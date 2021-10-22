#include "main.h"

void initialize(){
	pros::lcd::initialize();
	pros::lcd::set_text(1, "Amogus");

	liftController->tarePosition();
}

void disabled(){}

void competition_initialize(){}

void autonomous(){    
    chassis->setState({0_in, 0_in, 0_deg});
}

/**
 * Joysticks = drive
 * Left top & bottom button = lift toggle (up/down)
 * right top button = claw toggle (up/down)
 * Right bottom button = mogo lift
 */
void opcontrol(){
    liftController->tarePosition();
    double liftPosition = 0.0;
    bool mogoState = false, prevBtnState = false, currentBtnState = false;

    while(true){
        // gets controller input
	    double power = master.getAnalog(ControllerAnalog::leftY) * 
            (abs(master.getAnalog(ControllerAnalog::leftY)) >= DEADBAND);
        double curvature = master.getAnalog(ControllerAnalog::rightX) * 
            (abs(master.getAnalog(ControllerAnalog::rightX)) >= DEADBAND);

        // gets drive vel
        auto speed = curvatureDrive(power, curvature, power == 0);

        //output
		(chassis->getModel())->tank(speed.first, speed.second);

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
