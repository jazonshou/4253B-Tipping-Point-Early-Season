#include "main.h"

/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */
void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		pros::lcd::set_text(2, "I was pressed!");
	} else {
		pros::lcd::clear_line(2);
	}
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	pros::lcd::initialize();
	pros::lcd::set_text(1, "Hello PROS User!");

	pros::lcd::register_btn1_cb(on_center_button);
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */

const double db = 0.0500;
const double rotationValLiftDown = 0.0;
const double rotationValLiftUp = 0.0;

PID liftWithMogo(0.0, 0.0, 0.0);
PID liftWithoutMogo(0.0, 0.0, 0.0);

bool quickTurn = false;
bool liftToggle = false; //false = up, true = down
bool released = true;

std::pair<double, double> curvatureDrive(double moveC, double turnC, bool quickTurn){
    // range: [-1, 1]
    // moveC /= 100; turnC /= 100;

    double leftSpeed = 0.0;
    double rightSpeed = 0.0;

    if (quickTurn) {
        leftSpeed = moveC + turnC;
        rightSpeed = moveC - turnC;
    } else {
        leftSpeed = moveC + fabs(moveC) * turnC;
        rightSpeed = moveC - fabs(moveC) * turnC;
    }

    // Normalize wheel speeds
    double maxMagnitude = std::max(fabs(leftSpeed), fabs(rightSpeed));
    if (maxMagnitude > 1.0) {
        leftSpeed /= maxMagnitude;
        rightSpeed /= maxMagnitude;
    }
    leftSpeed *= 100;
    rightSpeed *= 100;

    return std::make_pair(leftSpeed, rightSpeed);
}

Controller master = Controller();

/**
 * Joysticks = drive
 * Left top & bottom button = lift toggle (up/down)
 * right top button = claw toggle (up/down)
 * Right bottom button = mogo lift
 * 
 */

void opcontrol() {
    while(true) {
        // gets controller input
	    double leftC = std::fabs(master.getAnalog(ControllerAnalog::leftY)) <= db 
                       ? 0 : master.getAnalog(ControllerAnalog::leftY);
        double rightC = std::fabs(master.getAnalog(ControllerAnalog::rightX)) <= db 
                        ? 0 : master.getAnalog(ControllerAnalog::rightX);
        // check for quick turn
        quickTurn = leftC == 0 ? true : false;
        // gets motor vel
        double leftSpeed = curvatureDrive(leftC, rightC, quickTurn).first;
        double rightSpeed = curvatureDrive(leftC, rightC, quickTurn).second;
        //output
        Globals::leftFront.moveVoltage(leftSpeed * 120);
        Globals::leftTop.moveVoltage(leftSpeed * 120);
        Globals::leftBottom.moveVoltage(leftSpeed * 120);
        Globals::rightFront.moveVoltage(rightSpeed * 120);
        Globals::rightTop.moveVoltage(rightSpeed * 120);
        Globals::rightBottom.moveVoltage(rightSpeed * 120);

        if(master.getDigital(ControllerDigital::L1)) {
            Globals::lift.moveVoltage(120000);
        } else if (master.getDigital(ControllerDigital::L2)) {
            Globals::lift.moveVoltage(-120000);
        } else {
            Globals::lift.moveVoltage(0);
        }

        if(master.getDigital(ControllerDigital::R1)) {
            Globals::claw.set_value(true);
        } else {
            Globals::claw.set_value(false);
        }

        if(master.getDigital(ControllerDigital::R2)) {
            Globals::mogoLeft.set_value(true);
            Globals::mogoRight.set_value(true);
        } else {
            Globals::mogoLeft.set_value(false);
            Globals::mogoRight.set_value(false);
        }

        pros::delay(10);
    }
}
