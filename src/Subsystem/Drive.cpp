#include "main.h"

void curvatureDrive(double moveC, double turnC, bool quickTurn){
    // Compute velocity, right stick = curvature if no quickturn, else power
    double leftSpeed = moveC + (quickTurn ? turnC : abs(moveC) * turnC);
    double rightSpeed = moveC - (quickTurn ? turnC : abs(moveC) * turnC);

    // Normalize velocity
    double maxMagnitude = std::max(abs(leftSpeed), abs(rightSpeed));
    if (maxMagnitude > 1.0) {
        leftSpeed /= maxMagnitude;
        rightSpeed /= maxMagnitude;
    }

    chassis->getModel()->tank(leftSpeed, rightSpeed);
}

void moveTime(std::pair<double, double> speed, QTime time) {
    (chassis->getModel())->tank(speed.first, speed.second);
    pros::delay(time.convert(millisecond));
    (chassis->getModel())->tank(0, 0);
}

void moveTimeHeadingCorrect(double speed, QTime time) {
    headingPID->reset();
    headingPID->setTarget(imu.get());

    int timeCnt = 0;
    do {
        (chassis->getModel())->arcade(speed, headingPID->step(imu.get()));
        pros::delay(10);
    } while(++timeCnt <= std::round(time.convert(millisecond) / 10));
}

void moveDistance(QLength target){
	movePID->reset(); headingPID->reset();
    movePID->setTarget(0); headingPID->setTarget(imu.get());
    (chassis->getModel())->resetSensors();

	do {
        double dist = Math::tickToFt(((chassis->getModel())->getSensorVals()[0] + (chassis->getModel())->getSensorVals()[1]) / 2) * 12;
        double error = target.convert(inch) - dist;
        (chassis->getModel())->arcade(movePID->step(-error), headingPID->step(imu.get()));
		pros::delay(10);
	} while(!movePID->isSettled());

	(chassis->getModel())->stop();
}

void moveDistance(QLength target, QTime time) {
    movePID->reset(); headingPID->reset();
    movePID->setTarget(0); headingPID->setTarget(imu.get());
    (chassis->getModel())->resetSensors();
    // imu.reset();
    double imuBeginningVal = imu.get();

    int timeCnt = 0;
    
	do {
        double dist = Math::tickToFt(((chassis->getModel())->getSensorVals()[0] + (chassis->getModel())->getSensorVals()[1]) / 2) * 12;
        double error = target.convert(inch) - dist;
        (chassis->getModel())->arcade(movePID->step(-error), headingPID->step(imu.get()));

        if(++timeCnt >= std::round(time.convert(millisecond) / 10)) break;
		pros::delay(10);
	} while(!movePID->isSettled());

	(chassis->getModel())->stop();
}

void turnToAngle(QAngle targetAngle){
	turnPID->reset();
    turnPID->setTarget(0);
    turnPID->setIntegratorReset(true);
    turnPID->setIntegralLimits(0.4 / TURNKI, -0.405/TURNKI);
    turnPID->setErrorSumLimits(15, 0);

	do{
        double error = Math::rescale180(targetAngle.convert(degree)-imu.get());
        (chassis->getModel())->arcade(0, turnPID->step(-Math::rescale180(targetAngle.convert(degree)-imu.get())));
        pros::delay(10);
    }while (!turnPID->isSettled());

    (chassis->getModel())->stop();
}

void turnToMogo() {
    do {
        pros::vision_object_s_t rtn = vision_sensor.get_by_size(0);
        //std::cout << "sig: " << rtn.x_middle_coord << std::endl;

        (chassis->getModel())->arcade(0, visionPID->step(-rtn.x_middle_coord));

		pros::delay(10);
	} while(!visionPID->isSettled());
	(chassis->getModel())->stop();
}





