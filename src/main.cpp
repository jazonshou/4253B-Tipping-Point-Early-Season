#include "main.h"

void initialize(){
	pros::lcd::initialize();
    master.setText(0, 0, "Current Autonomous: " + std::to_string(selectedAuton));
    pros::lcd::set_text(4, "init");


    // Initializes Controller
    // liftController->tarePosition();

    // Adds autonomous
    // auton.insert(std::make_pair(0, [](){})); // lambda ftw
    // auton.insert(std::make_pair(1, redLeft));
    // auton.insert(std::make_pair(2, redRight));
    // auton.insert(std::make_pair(3, blueLeft));
    // auton.insert(std::make_pair(4, blueRight));
    // auton.insert(std::make_pair(5, awp));
    // auton.insert(std::make_pair(6, skills));

    // // Adds path generation functions
    // path.insert(std::make_pair(0, [](){}));
    // path.insert(std::make_pair(1, genRedLeft));
    // path.insert(std::make_pair(2, genRedRight));
    // path.insert(std::make_pair(3, genBlueLeft));
    // path.insert(std::make_pair(4, genBlueRight));
    // path.insert(std::make_pair(5, genAwp));
    // path.insert(std::make_pair(6, genSkills));

    // // Generates path based on pre-selected auton
    // path[selectedAuton]();
}

void disabled(){}

void competition_initialize(){}

void autonomous(){
    // INITIALIZATION
    lift.set_brake_mode(pros::motor_brake_mode_e::E_MOTOR_BRAKE_HOLD);
    leftDrive.setBrakeMode(AbstractMotor::brakeMode::hold);
    rightDrive.setBrakeMode(AbstractMotor::brakeMode::hold);
    
    //----------------------------------------------------------------------//
    // LEFT AUTON
    followPath(LeftPaths::pathLeft, LeftPaths::pathRight);
    claw.set_value(true);
    mogo.set_value(true);
    pros::delay(250);
    lift.move_relative(360, 200);
    followPath(LeftPaths::pathLeftR, LeftPaths::pathRightR);
    mogo.set_value(false);
    followPath(LeftPaths::fwdLeft, LeftPaths::fwdRight);

    //---------------------------------------------------------------------------------//
    // AWP AUTON
    mogo.set_value(true);
    followPath(AWP::fwdRLeft, AWP::fwdRRight);
    mogo.set_value(false);
    followPath(AWP::loopbackLeft, AWP::loopbackRight);
    claw.set_value(true);
    leftDrive.moveRelative(-360, 600);
    rightDrive.moveRelative(1500, 600);

    //-----------------------------------------------------------------------------------------//
    // RIGHT AUTON
    followPath(RightPaths::curveLeft, RightPaths::curveRight);
    lift.move_relative(500, 200);
    mogo.set_value(true);
    followPath(RightPaths::curveRLeft, RightPaths::curveRRight);
    mogo.set_value(false);
    followPath(RightPaths::fwdLeft, RightPaths::fwdRight);
}

void opcontrol(){
    // Configures brake type for drive & lift
    leftDrive.setBrakeMode(AbstractMotor::brakeMode::coast);
    rightDrive.setBrakeMode(AbstractMotor::brakeMode::coast);
    lift.set_brake_mode(pros::motor_brake_mode_e::E_MOTOR_BRAKE_BRAKE);

    // Initializes driver control variable
    double liftPosition = 0.0;
    bool mogoState = false, prevBtnState = false, currentBtnState = false;
    
    // Initializes logo on the brain screen
    // Gif gif("/usd/logo.gif", lv_scr_act()); // TODO - Make Gif Run in opcontrol

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
        // lift.moveVoltage((master.getDigital(ControllerDigital::L1) - master.getDigital(ControllerDigital::L2)) * 12000);
        if(master.getDigital(ControllerDigital::L1)) lift.move_voltage(12000);
        else if(master.getDigital(ControllerDigital::L2)) lift.move_voltage(-12000);
        else lift.move_voltage(0);

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