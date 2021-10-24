#include "main.h"

void initialize(){
	//pros::lcd::initialize();
    master.setText(0, 0, "Current Autonomous: " + std::to_string(selectedAuton));

    // Initializes Controller
    liftController->tarePosition();

    // Adds autonomous
    auton.insert(std::make_pair(0, [](){})); // lambda ftw
    auton.insert(std::make_pair(1, redLeft));
    auton.insert(std::make_pair(2, redRight));
    auton.insert(std::make_pair(3, blueLeft));
    auton.insert(std::make_pair(4, blueRight));
    auton.insert(std::make_pair(5, awp));
    auton.insert(std::make_pair(6, skills));

    // Adds path generation functions
    path.insert(std::make_pair(0, [](){}));
    path.insert(std::make_pair(1, genRedLeft));
    path.insert(std::make_pair(2, genRedRight));
    path.insert(std::make_pair(3, genBlueLeft));
    path.insert(std::make_pair(4, genBlueRight));
    path.insert(std::make_pair(5, genAwp));
    path.insert(std::make_pair(6, genSkills));

    // Generates path based on pre-selected auton
    path[selectedAuton]();
}

void disabled(){}

void competition_initialize(){}

void autonomous(){
    auton[selectedAuton]();
}

void opcontrol(){
    // Initializes lift
    liftController->tarePosition();
    lift.setBrakeMode(AbstractMotor::brakeMode::brake);

    // Initializes driver control variable
    double liftPosition = 0.0;
    bool mogoState = false, prevBtnState = false, currentBtnState = false;
    
    // Initializes logo on the brain screen
    // Gif gif("/usd/logo.gif", lv_scr_act()); // #TODO - Make Gif Run in opcontrol

    while(true){
        /** 
         * @brief Chassis Control
         * Left Analog Y Stick -> Linear velocity the chassis drives in
         * Right Analog X Stick -> Curvature the chassis drives in
         */
	    double power = master.getAnalog(ControllerAnalog::leftY) * (abs(master.getAnalog(ControllerAnalog::leftY)) >= DEADBAND);
        double curvature = master.getAnalog(ControllerAnalog::rightX) * (abs(master.getAnalog(ControllerAnalog::rightX)) >= DEADBAND);
        auto speed = curvatureDrive(power, curvature, power == 0);
		(chassis->getModel())->tank(speed.first, speed.second);

        /**
         * @brief Lift Control
         * L1 (Left Top) Pressed -> Lift goes up
         * L2 (Left Bottom) Pressed -> Lift goes down
         * Both are pressed / both aren't pressed -> lift stays in the current position
         */
        lift.moveVoltage((master.getDigital(ControllerDigital::L1) - master.getDigital(ControllerDigital::L2)) * 12000);

        /**
         * @brief Claw Control
         * R1 (Right Top) Pressed -> claw closes
         * R1 (Right Top) not pressed -> claw opens
         */
        claw.set_value(master.getDigital(ControllerDigital::R1));

        /**
         * @brief Mogo Holder Control
         * The solenoid toggles between the two states every time R2 (Right Bottom) is pressed
         */
        currentBtnState = master.getDigital(ControllerDigital::R2);
        if(currentBtnState && !prevBtnState){
            mogo.set_value((mogoState = !mogoState));
        }
        prevBtnState = currentBtnState;

        pros::delay(10);
    }
}