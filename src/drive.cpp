#include "main.h"

void setBrakeMode(AbstractMotor::brakeMode brakeMode) {
    leftDrive.setBrakeMode(brakeMode);
    rightDrive.setBrakeMode(brakeMode);
}

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

double velControl(double velocity, double accel, double currSpeed, Side side) {
    // double kV = 0.0, kA = 0.0, kP = 0.0;
    return side == Side::LEFT ? LEFT_kV * velocity + LEFT_kA * accel + LEFT_kP * (velocity - currSpeed) : 
                                RIGHT_kV * velocity + RIGHT_kA * accel + RIGHT_kP * (velocity - currSpeed);
}

// TODO - make rpm to velocity conversion - also make ftps to mps convertor 
void followPathAccel(std::vector<std::vector<double>> leftPath, std::vector<std::vector<double>> rightPath) {
    for(int i = 0; i < path.size(); i++) {
        double l = rpmToLinVel(leftDrive.getActualVelocity());
        double r = rpmToLinVel(rightDrive.getActualVelocity());
        leftDrive.moveVoltage(velControl(leftPath[i][0], leftPath[i][1], l, Side::LEFT));
        rightDrive.moveVoltage(velControl(rightPath[i][0], rightPath[i][1], r, Side::RIGHT));

        // for plotting
        std::cout << l << std::endl << r << std::endl;
        pros::delay(10);
    }
}

double rpmToLinVel(double rpm) {
    return rpm * 3.25 * 3.14159265359 / 720; // don't judge, constants are overrated anyways
}

// velocity only, doesn't use custon velControl
std::vector<double> pathToRPM(std::vector<std::vector<double>> path) {
    std::vector<double> newPath;
    double val = 0.0;
    for(int i = 0; i < path.size(); i++) {
        // max vel = 4.92126 ft/s, max rpm = 600 --> convert values to rpm
        val = (path[i][0] * 600) / 4.92126;
        newPath.push_back(val);
    }
    return newPath;
}

// also not for custon vel control
void followPath(std::vector<std::vector<double>> leftVel, std::vector<std::vector<double>> rightVel) {
    std::vector<double> left = pathToRPM(leftVel); std::vector<double> right = pathToRPM(rightVel);
    for(int i = 0; i < left.size() || i < right.size(); i++) {
        setVelocity(left[i], right[i]);
        pros::delay(10);
        // pros::Task::delay_until(&now, 10);
    }
    setVelocity(0, 0);
}

void turnToAngle(okapi::QAngle targetAngle){
	turnPID->reset();
	turnPID->setTarget(targetAngle.convert(degree));

	do {
		chassis->getOdometry()->step();
		double power = turnPID->step(chassis->getState().theta.convert(degree));
		(chassis->getModel())->tank(power, -power);
		pros::delay(10);
	} while(!turnPID->isSettled());

	(chassis->getModel())->stop();
}

