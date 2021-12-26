#include "main.h"

AsyncMotionProfiler::AsyncMotionProfiler(std::shared_ptr<ChassisController> iChassis, 
                                         std::unique_ptr<LinearMotionProfile> iMove, 
                                         std::unique_ptr<FFVelocityController> iLeftController, 
                                         std::unique_ptr<FFVelocityController> iRightController,
                                         const TimeUtil& iTimeUtil): timeUtil(iTimeUtil)
{
    chassis = std::move(iChassis);
    profiler = std::move(iMove);
    leftVelController = std::move(iLeftController);
    rightVelController = std::move(iRightController);
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
        std::cout<<timer->getDt().convert(millisecond) << '\n';
        QTime time = timer->getDtFromMark();

        if(getState() == MotionProfileState::IDLE){

        }
        else if(time > maxTime){
            setState(MotionProfileState::IDLE);
            chassis->getModel()->tank(0, 0);
        }
        else if(getState() == MotionProfileState::MOVE){
            pt = profiler->get(time);
            leftPower = leftVelController->step(pt.leftPosition, pt.leftVelocity, pt.leftAcceleration, leftMotor->getPosition(), leftMotor->getActualVelocity());
            rightPower = rightVelController->step(pt.rightPosition, pt.rightVelocity, pt.rightAcceleration, rightMotor->getPosition(), rightMotor->getActualVelocity());
            chassis->getModel()->tank(leftPower, rightPower);
        }
        else if(getState() == MotionProfileState::FOLLOW){
            pt = path[(int)(time.convert(millisecond) / 10)];
            leftPower = leftVelController->step(pt.leftPosition, pt.leftVelocity, pt.leftAcceleration, leftMotor->getPosition(), leftMotor->getActualVelocity());
            rightPower = rightVelController->step(pt.rightPosition, pt.rightVelocity, pt.rightAcceleration, rightMotor->getPosition(), rightMotor->getActualVelocity());
            chassis->getModel()->tank(leftPower, rightPower);
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
    velInit = false;
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

AsyncMotionProfilerBuilder& AsyncMotionProfilerBuilder::withVelocityController(FFVelocityController iLeft, FFVelocityController iRight){
    left = iLeft, right = iRight;
    velInit = true;
    return *this;
}

std::shared_ptr<AsyncMotionProfiler> AsyncMotionProfilerBuilder::build(){
    std::shared_ptr<AsyncMotionProfiler> ret(new AsyncMotionProfiler(std::move(chassis), 
                                          std::move(profile), 
                                          std::make_unique<FFVelocityController>(left), 
                                          std::make_unique<FFVelocityController>(right), 
                                          TimeUtilFactory::createDefault()));

    ret->startTask();
    return std::move(ret);
}







