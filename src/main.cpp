#include "main.h"

void initialize(){
	pros::lcd::initialize();
	pros::lcd::set_text(1, "LCD Initialized");

	// liftController->tarePosition();
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

    // while(true){
    //     pros::delay(10);
    // }

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
    // liftController->tarePosition();
    double liftPosition = 0.0;
    bool mogoState = false, prevBtnState = false, currentBtnState = false;

    // Gif gif("/usd/logo.gif", lv_scr_act());

    pros::lcd::clear();
    lift.setBrakeMode(AbstractMotor::brakeMode::brake);

    // claw.set_value(true);
    // pros::delay(2000);
    // claw.set_value(false);
    // pros::delay(2000);
    // claw.set_value(true);
    // pros::delay(2000);

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
        // liftPosition += master.getDigital(ControllerDigital::L1) * LIFT_INCREMENT;
        // liftPosition -= master.getDigital(ControllerDigital::L2) * LIFT_INCREMENT;
        // liftPosition = std::min(std::max(liftPosition, 0.0), MAXLIFTHEIGHT);
    	// liftController->setTarget(liftPosition);
        // pros::lcd::set_text(1, "lift pos: " + liftPosition);
        // pros::lcd::set_text(2, "rotation sensor: " + liftSensor.get());
        if(master.getDigital(ControllerDigital::L1)) lift.moveVoltage(12000);
        else if (master.getDigital(ControllerDigital::L2))lift.moveVoltage(-12000);
        else lift.moveVoltage(0);



        // claw control - direct
        // std::printf("Claw val: %d", claw.set_value(!master.getDigital(ControllerDigital::R1)));

        if(master.getDigital(ControllerDigital::R1)) claw.set_value(true);
        else claw.set_value(false);

        // std::printf("claw button: %d", master.getDigital(ControllerDigital::R1));
        // std::printf("limit: %d", limit.get_value());

        // mogo holder - toggle 
        currentBtnState = master.getDigital(ControllerDigital::R2);
        if(currentBtnState && !prevBtnState){
            std::cout << mogo.set_value((mogoState = !mogoState));
            // mogoRight.set_value(mogoState);
        }
        prevBtnState = currentBtnState;

        pros::delay(10);
    }
}
