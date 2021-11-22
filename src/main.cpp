#include "main.h"

void initialize(){
	pros::lcd::initialize();
    master.setText(0, 0, "Current Autonomous: " + std::to_string(selectedAuton));
    pros::lcd::set_text(4, "init");

    //TODO bruh
    // Initializes Controller
    mogoController->tarePosition();
    // liftController->tarePosition();
    mogoController->reset();
    // liftController->reset();
    pros::lcd::set_text(2, "mogo & lift sensor reset");

    imu.calibrate();
    pros::delay(2000);
    pros::lcd::set_text(2, "imu calibrated");
}

void disabled(){}

void competition_initialize(){}

void autonomous(){
    std::shared_ptr<AsyncPositionController<double, double>> liftController = AsyncPosControllerBuilder()
        .withMotor(lift)
        .withGains({0.035, 0.0, 0.0005}) // TODO - Slightly tune constant
        .withSensor(std::make_shared<okapi::RotationSensor>(liftSensor))
        .build();
    // INITIALIZATION
    leftDrive.setBrakeMode(AbstractMotor::brakeMode::hold);
    rightDrive.setBrakeMode(AbstractMotor::brakeMode::hold);
    liftController->tarePosition();
    liftController->reset();
    // mogoController->tarePosition();
    // mogoController->reset();
    
    // -----------------------------------------------------------------------
    // RIGHT AUTON
    // wings.set_value(true);
    // mogoController->setTarget(45);
    // followPath(RightNew::pathRLeft, RightNew::pathRRight);
    // wings.set_value(false);
    // followPath(RightNew::pathBackLeft, RightNew::pathBackRight);
    // wings.set_value(true); pros::delay(500); wings.set_value(false);
    //--------------------
    // followPath(RightNew::shortTurnLeft, RightNew::shortTurnRight);
    // mogoController->setTarget(0);
    // mogoController->waitUntilSettled();
    // followPath(RightNew::backLeft, RightNew::backRight);
    // mogoController->setTarget(45);
    // followPath(RightNew::forwardLeft, RightNew::forwardRight);
    // -----------------------------------------------------------------------
    // LEFT AUTON
    // wings.set_value(true); pros::delay(100); wings.set_value(false);
    // mogoController->setTarget(0);
    // followPath(LeftPaths::path1Left, LeftPaths::path1Right);
    // mogoController->setTarget(45);
    // pros::delay(250);
    // followPath(LeftPaths::path2Left, LeftPaths::path2Right);
    // claw.set_value(true);
    // -----------------------------------------------------------------------
    // AWP AUTON
    liftController->setTarget(100);
    mogoController->setTarget(45);
    liftController->waitUntilSettled();
    followPath(AWP::path1NewLeft, AWP::path1NewRight, false);
    mogoController->setTarget(0);
    setVelocity(300, 300); pros::delay(500); setVelocity(0,0);
    followPath(AWP::testLeft, AWP::testRight, true);
    mogoController->setTarget(45);
    pros::delay(500);
    setVelocity(300, 300); pros::delay(1000); setVelocity(0, 0);
    mogoController->setTarget(0);
    setVelocity(300, 300); pros::delay(1000); setVelocity(0, 0);
    // --------------------------------
    // mogoController->setTarget(0);
    // wings.set_value(true); pros::delay(100); wings.set_value(false);
    // mogoController->waitUntilSettled();
    // followPath(AWP::fwdRLeft, AWP::fwdRRight);
    // mogoController->setTarget(45);
    // followPath(AWP::loopbackLeft, AWP::loopbackRight);
    // claw.set_value(true);
    // rightDrive.moveRelative(-300, 600);
    // leftDrive.moveRelative(600, 600);
    // -----------------------------------------------------------------------
    // SKILLS AUTON
    // // mogoController->setTarget(0);
    // // wings.set_value(true); pros::delay(100); wings.set_value(false);
    // // mogoController->waitUntilSettled();
    // followPath(Skills::path0Left, Skills::path0Right);
    // // mogoController->setTarget(45);
    // followPath(Skills::path1Left, Skills::path1Right);
    // // pros::delay(250);
    // // claw.set_value(true);
    // liftController->setTarget(110);
    // followPath(Skills::path2Left, Skills::path2Right);
    // // claw.set_value(false);
    // // liftController->setTarget(100);
    // // leftDrive.moveVelocity(600); rightDrive.moveVelocity(600); pros::delay(500); leftDrive.moveVelocity(0); rightDrive.moveVelocity(0);
    // // followPath(Skills::backLeft, Skills::backRight);
    // followPath(Skills::path3Left, Skills::path3Right);
    // liftController->setTarget(0);
    // followPath(Skills::path4Left, Skills::path4Right);
    // followPath(Skills::path5Left, Skills::path5Right);
    // followPath(Skills::path6Left, Skills::path6Right);
}

void opcontrol(){
    
    // mogoController->reset();
    // liftController->reset();
    // Configures brake type for drive & lift
    leftDrive.setBrakeMode(AbstractMotor::brakeMode::coast);
    rightDrive.setBrakeMode(AbstractMotor::brakeMode::coast);
    lift.setBrakeMode(AbstractMotor::brakeMode::brake);
    mogo.setBrakeMode(AbstractMotor::brakeMode::hold);
    
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
        // leftDrive.moveVelocity(speed.first*600);
        // rightDrive.moveVelocity(speed.second*600);

        /**
         * @brief Lift Control
         * L1 (Left Top) Pressed -> Lift goes up
         * L2 (Left Bottom) Pressed -> Lift goes down
         * Both are pressed / both aren't pressed -> lift stays in the current position
         */
        if(master.getDigital(ControllerDigital::L1)) lift.moveVoltage(12000);//lift.moveVelocity(200); //liftController->setTarget(100);
        else if(master.getDigital(ControllerDigital::L2)) lift.moveVoltage(-12000);//lift.moveVelocity(-200); //liftController->setTarget(0);
        else lift.moveVoltage(0);
        // pros::lcd::set_text(3, "lift error : " + std::to_string(liftController->getError()));

        /**
         * @brief Claw Control
         * R1 (Right Top) Pressed -> claw closes
         * R1 (Right Top) not pressed -> claw opens
         */
        claw.set_value(master.getDigital(ControllerDigital::R1));
        wings.set_value(master.getDigital(ControllerDigital::Y));

        /**
         * @brief Mogo Holder Control
         * The solenoid toggles between the two states every time R2 (Right Bottom) is pressed
         */
        // TODO - tune lift height & PID
        currentBtnState = master.getDigital(ControllerDigital::R2);
        if(currentBtnState && !prevBtnState){
            // mogo.set_value((mogoState = !mogoState));
            mogoState = !mogoState;
            mogoController->setTarget(mogoState ? MAX_MOGO_DISTANCE : 0);
        }
        prevBtnState = currentBtnState;

        
        double err = mogoController->getError();
        pros::lcd::set_text(1, "Error: " + std::to_string(err));

        pros::delay(10);
        
    }
}