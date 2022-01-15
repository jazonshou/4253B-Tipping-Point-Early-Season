#include "main.h"

AsyncMotionProfiler::AsyncMotionProfiler(std::shared_ptr<ChassisController> iChassis, 
                                         std::unique_ptr<LinearMotionProfile> iMove, 
                                         std::unique_ptr<FFVelocityController> iLeftLinear, 
                                         std::unique_ptr<FFVelocityController> iRightLinear,
                                         std::unique_ptr<FFVelocityController> iLeftTrajectory,
                                         std::unique_ptr<FFVelocityController> iRightTrajectory,
                                         const TimeUtil& iTimeUtil): timeUtil(iTimeUtil)
{
    chassis = std::move(iChassis);
    profiler = std::move(iMove);
    leftLinear =  std::move(iLeftLinear);
    rightLinear = std::move(iRightLinear);
    leftTrajectory = std::move(iLeftTrajectory);
    rightTrajectory = std::move(iRightTrajectory);
    rate = std::move(timeUtil.getRate());
    timer = std::move(timeUtil.getTimer());

    leftMotor = std::move(std::static_pointer_cast<SkidSteerModel>(chassis->getModel())->getLeftSideMotor());
    rightMotor = std::move(std::static_pointer_cast<SkidSteerModel>(chassis->getModel())->getRightSideMotor());

}

void AsyncMotionProfiler::setTarget(QLength distance){
    lock.take(5);
    setState(MotionProfileState::MOVE);
    profiler->setDistance(distance);
    leftMotor->tarePosition();
    rightMotor->tarePosition();
    chassis->getModel()->tank(0, 0);
    maxTime = profiler->getTotalTime() + 0.02_s;
    timer->placeMark();
    lock.give();
}

void AsyncMotionProfiler::setTarget(const Trajectory& iPath){
    lock.take(5);
    setState(MotionProfileState::FOLLOW);
    leftMotor->tarePosition();
    rightMotor->tarePosition();
    chassis->getModel()->tank(0, 0);
    path = iPath;
    maxTime = path.size() * 10 * millisecond + 0.02_s;
    timer->placeMark();
    lock.give();
}

void AsyncMotionProfiler::stop(){
    lock.take(5);
    setState(MotionProfileState::IDLE);
    (chassis->getModel())->tank(0, 0);
    lock.give();
}

void AsyncMotionProfiler::loop(){
    TrajectoryPoint pt;
    double leftPower, rightPower;

    while(true){
        lock.take(5);
        QTime time = timer->getDtFromMark();

        if(getState() == MotionProfileState::IDLE){

        }
        else if(time > maxTime){
            setState(MotionProfileState::IDLE);
            chassis->getModel()->tank(0, 0);
        }
        else if(getState() == MotionProfileState::MOVE){
            pt = profiler->get(time);
            leftPower = leftLinear->step(pt.leftPosition, pt.leftVelocity, pt.leftAcceleration, leftMotor->getPosition(), leftMotor->getActualVelocity());
            rightPower = rightLinear->step(pt.rightPosition, pt.rightVelocity, pt.rightAcceleration, rightMotor->getPosition(), rightMotor->getActualVelocity());
            chassis->getModel()->tank(leftPower, rightPower);
        }
        else if(getState() == MotionProfileState::FOLLOW){
            pt = path[(int)(time.convert(millisecond) / 10)];
            leftPower = leftTrajectory->step(pt.leftPosition, pt.leftVelocity, pt.leftAcceleration, leftMotor->getPosition(), leftMotor->getActualVelocity());
            rightPower = rightTrajectory->step(pt.rightPosition, pt.rightVelocity, pt.rightAcceleration, rightMotor->getPosition(), rightMotor->getActualVelocity());
            chassis->getModel()->tank(leftPower, rightPower);
            std::cout << Math::tickToFt(rightDrive.getPosition()) << std::endl;
        }

        lock.give();
        rate->delayUntil(10);
    }
}

void AsyncMotionProfiler::waitUntilSettled(){
    while(getState() != MotionProfileState::IDLE){
        pros::delay(10);
    }
}

AsyncMotionProfilerBuilder::AsyncMotionProfilerBuilder(){
    linearInit = false;
    trajInit = false;
    driveInit = false;
    profileInit = false;
}

AsyncMotionProfilerBuilder& AsyncMotionProfilerBuilder::withOutput(std::shared_ptr<ChassisController> iChassis){
    chassis = std::move(iChassis);
    driveInit = true;
    return *this;
}

AsyncMotionProfilerBuilder& AsyncMotionProfilerBuilder::withProfiler(std::unique_ptr<LinearMotionProfile> iProfiler){
    profile = std::move(iProfiler);
    profileInit = true;
    return *this;
}

AsyncMotionProfilerBuilder& AsyncMotionProfilerBuilder::withLinearController(FFVelocityController iLeft, FFVelocityController iRight){
    leftL = iLeft, rightL = iRight;
    linearInit = true;
    return *this;

}

AsyncMotionProfilerBuilder& AsyncMotionProfilerBuilder::withTrajectoryController(FFVelocityController iLeft, FFVelocityController iRight){
    leftT = iLeft, rightT = iRight;
    trajInit = true;
    return *this;
}

std::shared_ptr<AsyncMotionProfiler> AsyncMotionProfilerBuilder::build(){
    if(driveInit && profileInit && linearInit && trajInit){
        std::shared_ptr<AsyncMotionProfiler> ret(new AsyncMotionProfiler(std::move(chassis), 
                                            std::move(profile), 
                                            std::make_unique<FFVelocityController>(leftL), 
                                            std::make_unique<FFVelocityController>(rightL),
                                            std::make_unique<FFVelocityController>(leftT), 
                                            std::make_unique<FFVelocityController>(rightT),
                                            TimeUtilFactory::createDefault()));

        ret->startTask();
        return std::move(ret);
    }
    else{
        throw std::runtime_error("AsyncMotionProfilerBuilder: Not all parameters supplied, failed to build");
    }
}







