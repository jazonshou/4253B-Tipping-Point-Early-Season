#include "main.h"

void initialize(){
	pros::lcd::initialize();
	pros::lcd::set_text(1, "LCD Initialized");

	liftController->tarePosition();
    pros::lcd::set_text(2, "Subsysytems initialized");

    auton.insert(std::make_pair(0, [](){})); // lambda ftw
    auton.insert(std::make_pair(1, redLeft));
    auton.insert(std::make_pair(2, redRight));
    auton.insert(std::make_pair(3, blueLeft));
    auton.insert(std::make_pair(4, blueRight));
    auton.insert(std::make_pair(5, awp));
    auton.insert(std::make_pair(6, skills));

    path.insert(std::make_pair(0, [](){}));
    path.insert(std::make_pair(1, genRedLeft));
    path.insert(std::make_pair(2, genRedRight));
    path.insert(std::make_pair(3, genBlueLeft));
    path.insert(std::make_pair(4, genBlueRight));
    path.insert(std::make_pair(5, genAwp));
    path.insert(std::make_pair(6, genSkills));

    pros::lcd::set_text(3, "Auton Initialized, Please Select Your Auton");

    while(true){
        pros::delay(10);
    }

    pros::lcd::set_text(4, "Generating Path...");

    path[selectedAuton]();

    pros::lcd::set_text(5, "Path Generated, Ready To Go");
}

void disabled(){}

void competition_initialize(){}

void autonomous(){
    auton[selectedAuton]();
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

    Gif gif("/usd/logo.gif", lv_scr_act());

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
        liftPosition += master.getDigital(ControllerDigital::L1) * LIFTINCREMENT;
        liftPosition -= master.getDigital(ControllerDigital::L2) * LIFTINCREMENT;
        liftPosition = std::min(std::max(liftPosition, 0.0), MAXLIFTHEIGHT);
    	liftController->setTarget(liftPosition);

        // claw control - direct
        claw.set_value(master.getDigital(ControllerDigital::R1));
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
