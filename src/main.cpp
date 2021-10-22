#include "main.h"

void initialize(){
	pros::lcd::initialize();
	pros::lcd::set_text(1, "Hello PROS User!");
}

void disabled(){}

void competition_initialize(){}

void autonomous(){
    auto chassis = ChassisControllerBuilder()
	    .withMotors(leftDrive, rightDrive)
	    .withDimensions({AbstractMotor::gearset::blue, 5.0/30}, {{3.25_in, 12.25_in}, imev5BlueTPR}) // Drop Center Wheels
	    .withSensors(trackLeft, trackRight, trackMiddle)
	    .withOdometry({{2.75_in, 6.25_in}, quadEncoderTPR})
	    .buildOdometry();

	auto profileController = AsyncMotionProfileControllerBuilder()
	    .withLimits({
	    	1.0, // Maximum linear velocity of the Chassis in m/s
	    	2.0, // Maximum linear acceleration of the Chassis in m/s/s
	    	10.0 // Maximum linear jerk of the Chassis in m/s/s/s
	    })
	    .withOutput(chassis)
	    .buildMotionProfileController();

    auto liftController =  AsyncPosControllerBuilder()
    	.withMotor(lift) // Lift Motor: Port 7
    	.withGains({0.001, 0.001, 0.0000}) // kP, kI, kD
		.withSensor(std::make_shared<okapi::RotationSensor>(liftSensor))
    	.build();
    
    liftController->tarePosition();
    chassis->setState({0_in, 0_in, 0_deg});
}

// input range: [-1, 1]
// output range: [-1, 1]
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

/**
 * Joysticks = drive
 * Left top & bottom button = lift toggle (up/down)
 * right top button = claw toggle (up/down)
 * Right bottom button = mogo lift
 */

void opcontrol(){
    auto liftController =  AsyncPosControllerBuilder()
    	.withMotor(lift) // Lift Motor: Port 7
    	.withGains({0.001, 0.001, 0.0000}) // kP, kI, kD
		.withSensor(std::make_shared<okapi::RotationSensor>(liftSensor)) // Potentiometer: ADI Port 'G'
    	.build();

    liftController->tarePosition();
    double liftPosition = 0.0;
    bool mogoState = false;
    bool prevBtnState = false, currentBtnState = false;

    while(true){
        // gets controller input
	    auto power = master.getAnalog(ControllerAnalog::leftY) * 
            (abs(master.getAnalog(ControllerAnalog::leftY)) >= DEADBAND);
        auto curvature = master.getAnalog(ControllerAnalog::rightX) * 
            (abs(master.getAnalog(ControllerAnalog::rightX)) >= DEADBAND);

        // gets drive vel
        auto speed = curvatureDrive(power, curvature, power == 0);

        //output
        leftDrive.moveVoltage(speed.first * 12000);
        rightDrive.moveVoltage(speed.second * 12000);

        // lift control
        liftPosition += master.getDigital(ControllerDigital::L1) * LIFT_INCREMENT;
        liftPosition -= master.getDigital(ControllerDigital::L2) * LIFT_INCREMENT;
        liftPosition = std::min(std::max(liftPosition, 0.0), MAXLIFTHEIGHT);
        liftController->setTarget(liftPosition);

        // claw control - direct
        claw.set_value(master.getDigital(ControllerDigital::R1));

        // mogo holder - toggle 
        currentBtnState = master.getDigital(ControllerDigital::R2);
        if(currentBtnState && !prevBtnState){
            mogoLeft.set_value((mogoState = !mogoState));
            mogoRight.set_value(mogoState);
        }
        prevBtnState = currentBtnState;

        pros::delay(10);
    }
}
