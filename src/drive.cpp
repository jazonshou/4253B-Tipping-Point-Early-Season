#include "main.h"

void setVelocity(double l, double r) {
    leftDrive.moveVelocity(l);
    rightDrive.moveVelocity(r);
}

std::pair<double, double> curvatureDrive(double moveC, double turnC, bool quickTurn){
    // Compute velocity, right stick = curvature if no quickturn, else power
    double leftSpeed = moveC + (quickTurn ? turnC : abs(moveC) * turnC);
    double rightSpeed = moveC - (quickTurn ? turnC : abs(moveC) * turnC);

    // Normalize velocity
    double maxMagnitude = std::max(abs(leftSpeed), abs(rightSpeed));
    if (maxMagnitude > 1.0) {
        leftSpeed /= maxMagnitude;
        rightSpeed /= maxMagnitude;
    }

    return std::make_pair(leftSpeed, rightSpeed);
}

void turnToAngle(okapi::QAngle targetAngle){
	turnPID->reset();
    turnPID->setTarget(0);

	do {
        (chassis->getModel())->arcade(0, turnPID->step(-Math::rescale180(targetAngle.convert(degree)-imu.get())));
		pros::delay(10);
	} while(!turnPID->isSettled());

	(chassis->getModel())->stop();
}

void followPath(const Trajectory& path){
    for(int i = 0; i < path.size(); i++){
        TrajectoryPoint pt = path[i];
        setVelocity(Math::ftpsToRPM(pt.leftVelocity), Math::ftpsToRPM(pt.rightVelocity));
        pros::delay(10);
    }
    chassis->stop();
}

void followPathCustom(const Trajectory& path){
    //okapi::EmaFilter filter(0.65); double leftPosition = 0, leftPrevPosition = 0;
    leftDrive.tarePosition();
    rightDrive.tarePosition();
    for(int i = 0; i < path.size(); i++){
        TrajectoryPoint pt = path[i];

        double leftPower = leftMotorController.step(pt.leftPosition, pt.leftVelocity, pt.leftAcceleration, leftDrive.getPosition(), leftDrive.getActualVelocity());
        double rightPower = rightMotorController.step(pt.rightPosition, pt.rightVelocity, pt.rightAcceleration, rightDrive.getPosition(), rightDrive.getActualVelocity());
        (chassis->getModel())->tank(leftPower, rightPower);


        // leftPosition = Math::tickToFt(leftDrive.getPosition());
        // std::cout << filter.filter((leftPosition - leftPrevPosition)/0.01) << std::endl;
        // leftPrevPosition = leftPosition;

        // std::cout << filter.filter(Math::rpmToFtps(leftDrive.getActualVelocity())) << std::endl; 

        // std::cout << Math::tickToFt(rightDrive.getPosition()) << std::endl;
        // std::cout << Math::tickToFt(leftDrive.getPosition()) << std::endl;
        pros::delay(10);
    }
    chassis->stop();
}



void alignMogo() {
    // const double kP = 0.005;
    
    do {
        pros::vision_object_s_t rtn = vision_sensor.get_by_size(0);
        std::cout << "sig: " << rtn.x_middle_coord << std::endl;

        (chassis->getModel())->arcade(0, mogoAlignerController->step(-rtn.x_middle_coord));

		pros::delay(10);
	} while(!mogoAlignerController->isSettled());

	(chassis->getModel())->stop();
}