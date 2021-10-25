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
    // auton[selectedAuton]();
    leftDrive.setBrakeMode(AbstractMotor::brakeMode::hold);
    rightDrive.setBrakeMode(AbstractMotor::brakeMode::hold);

    pros::lcd::set_text(0, "auton");
    // chassis->setState({0_in, 0_in, 0_deg});
    profiler->generatePath({{0_in, 0_in, 0_deg}, {4_ft, 4_ft, 90_deg}, {0_ft, 4_ft, 180_deg}}, "Test");
    pros::lcd::set_text(1, "pathgen");
    profiler->setTarget("Test");
    profiler->waitUntilSettled();
    // std::shared_ptr<OdomChassisController> chassis_ = ChassisControllerBuilder()
    //     .withMotors(leftDrive, rightDrive) // left motor is 1, right motor is 2 (reversed)
    //     // green gearset, 4 inch wheel diameter, 11.5 inch wheel track
    //     .withDimensions(AbstractMotor::gearset::blue, {{4_in, 11.5_in}, imev5BlueTPR})
    //     // left encoder in ADI ports A & B, right encoder in ADI ports C & D (reversed)
    //     // .withSensors(ADIEncoder{'A', 'B'}, ADIEncoder{'C', 'D', true})
    //     // specify the tracking wheels diameter (2.75 in), track (7 in), and TPR (360)
    //     .withOdometry()
    //     .buildOdometry();

    // std::shared_ptr<AsyncMotionProfileController> profileController = AsyncMotionProfileControllerBuilder()
    //     .withLimits({
    //         1.0, // Maximum linear velocity of the Chassis in m/s
    //         2.0, // Maximum linear acceleration of the Chassis in m/s/s
    //         10.0 // Maximum linear jerk of the Chassis in m/s/s/s
    //     })
    //     .withOutput(chassis_)
    //     .buildMotionProfileController();

    // profileController->generatePath({
    //     {0_ft, 0_ft, 0_deg},  // Profile starting position, this will normally be (0, 0, 0)
    //     {0_ft, 3_ft, 0_deg}}, // The next point in the profile, 3 feet forward
    //     "A" // Profile name
    // );
    // profileController->setTarget("A");
    // profileController->waitUntilSettled();

    // chassis_->setState({0_in, 0_in, 0_deg});
    // chassis_->turnToAngle(90_deg);
    pros::lcd::set_text(2, "done");
}

void opcontrol(){
    leftDrive.setBrakeMode(AbstractMotor::brakeMode::coast);
    rightDrive.setBrakeMode(AbstractMotor::brakeMode::coast);
    // Initializes lift
    // liftController->tarePosition();
    // lift.setBrakeMode(AbstractMotor::brakeMode::brake);
    lift.set_brake_mode(pros::motor_brake_mode_e::E_MOTOR_BRAKE_BRAKE);

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