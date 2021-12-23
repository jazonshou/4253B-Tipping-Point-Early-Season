#include "main.h"

void setVelocity(double l, double r) {
    leftDrive.moveVelocity(l);
    rightDrive.moveVelocity(r);
}

void moveTime(std::pair<double, double> speed, QTime time) {
    (chassis->getModel())->tank(speed.first, speed.second);
    pros::delay(time.convert(millisecond));
    (chassis->getModel())->tank(0, 0);
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

void turnToAngle(QAngle targetAngle){
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
        pros::delay(10);
    }
    chassis->stop();
}



void alignMogo() {
    do {
        pros::vision_object_s_t rtn = vision_sensor.get_by_size(0);
        std::cout << "sig: " << rtn.x_middle_coord << std::endl;

        (chassis->getModel())->arcade(0, mogoAlignerController->step(-rtn.x_middle_coord));

		pros::delay(10);
	} while(!mogoAlignerController->isSettled());
	(chassis->getModel())->stop();
}


void translate(QLength target){
    double headingCorrection_kP = 0.118;

	translatePID->reset();
    translatePID->setTarget(0);
    (chassis->getModel())->resetSensors();
    imu.reset();

	do {
        double dist = Math::tickToFt(((chassis->getModel())->getSensorVals()[0] + (chassis->getModel())->getSensorVals()[1]) / 2) * 12;
        double error = target.convert(inch) - dist;
        (chassis->getModel())->arcade(translatePID->step(-error), -imu.get()*headingCorrection_kP);
		pros::delay(10);
	} while(!translatePID->isSettled());

	(chassis->getModel())->stop();
}



