#include "main.h"

// input range: [-1, 1]
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
	turnPID->setTarget(targetAngle.convert(degree));

	do{
		chassis->getOdometry()->step();
		double power = turnPID->step(chassis->getState().theta.convert(degree));
		(chassis->getModel())->tank(power, -power);
		pros::delay(10);
	}while(!turnPID->isSettled());

	(chassis->getModel())->stop();
}