#include "main.h"

/**
 * @brief Create a Blank Background on the brain screen
 * 
 */
void createBlankBackground(){
    lv_obj_t *background;
    lv_style_t backgroundStyle;
    lv_style_copy(&backgroundStyle, &lv_style_plain);
    backgroundStyle.body.main_color = LV_COLOR_BLACK;
    backgroundStyle.body.grad_color = LV_COLOR_BLACK;
    backgroundStyle.body.radius = 0;
    backgroundStyle.text.color = LV_COLOR_WHITE;
    background = lv_obj_create(lv_scr_act(), NULL);
    lv_obj_set_free_num(background, 0);
    lv_obj_set_style(background, &backgroundStyle);
    lv_obj_set_size(background, LVGL_SCREEN_WIDTH, LVGL_SCREEN_HEIGHT);
    lv_obj_align(background, NULL, LV_ALIGN_CENTER, 0, 0);
}

void initialize(){
    // Screen initialization
	pros::lcd::initialize();

    // Vision initialization
    pros::vision_signature_s_t RED_SIG = pros::Vision::signature_from_utility(1, 5685, 8135, 6910, -1963, -1705, -1834, 4.000, 0);
    vision_sensor.set_signature(1, &RED_SIG);

    // IMU initialization
    pros::lcd::set_text(2, "imu calibrating..............");
    imu.calibrate();
    pros::delay(3000);
    pros::lcd::set_text(2, "imu calibrated");

    // Adds autonomous functions
    Auton::add([](){}, "Do Nothing");
    Auton::add(Auton::skills, "Skills");
    Auton::add(Auton::right, "Right Wing");
    Auton::add(Auton::awp, "AWP Wing");
}

void disabled(){}

void competition_initialize(){
    // Simple autonomous selector implemented using lambda functions
    pros::lcd::register_btn0_cb([](){lift.tarePosition();});
    pros::lcd::register_btn1_cb([](){Auton::switchAuton();});
    pros::lcd::register_btn2_cb([](){Auton::select();});
    
    while(true){
        std::string message = "Selected Autonomous: " + Auton::getName();
        pros::lcd::print(0, message.c_str());
        pros::delay(10);
    }
}

void autonomous(){
    Auton::execute();
}

void opcontrol(){
    // Starts logo gif
    createBlankBackground();
    Gif gif("/usd/gif/logo.gif", lv_scr_act());

    // Initializes variable
    int liftPos = 0;
    bool clampState = false, prevClampState = false;
    bool mogoState = false, prevMogoState = false;

    // Sets motor brake mode
    leftDrive.setBrakeMode(AbstractMotor::brakeMode::coast);
    rightDrive.setBrakeMode(AbstractMotor::brakeMode::coast);
    lift.setBrakeMode(AbstractMotor::brakeMode::hold);
    
    while(true){
        /**
         * @brief chassis control using our custom curvature mode
         *        Left analog stick: throttle
         *        right analog stick: throttle
         */
        double power = Math::deadband(master.getAnalog(ControllerAnalog::leftY), DEADBAND);
        double curvature = Math::deadband(master.getAnalog(ControllerAnalog::rightX), DEADBAND);
        curvatureDrive(power, curvature, power == 0);

        /**
         * @brief lift control using an async PID controller
         *        L1 pressed: increments target angle by LIFT_STEP
         *        L2 pressed: decrements target angle by LIFT_STEP
         *        note: target angle is capped to [0, MAX_LIFT_HEIGHT] to protect the lift
         * 
         */
        liftPos += LIFT_STEP * master.getDigital(ControllerDigital::L1); 
        liftPos -= LIFT_STEP * master.getDigital(ControllerDigital::L2);
        liftController->setTarget(liftPos = Math::clamp(liftPos, MAX_LIFT_HEIGHT, 0));

        /**
         * @brief controlls our roller
         *        When both L1 and L2 pressed: runs the roller inward (intakes)
         *        When A is pressed: runs the roller outward (outtakes)
         *        When Both are pressed / unpressed: no movement
         * 
         */
        roller.moveVoltage(12000*((master.getDigital(ControllerDigital::L1) && master.getDigital(ControllerDigital::L2))-master.getDigital(ControllerDigital::A)));

        /**
         * @brief controls the claw depending on the button value 
         *        When R1 is pressed: claw solenoid is set to true
         *        When R2 is unpressed: claw solenoid is set to false
         */
        claw.set(master.getDigital(ControllerDigital::R1));


        /**
         * @brief controls the wing depending on the button value 
         *        When Y is pressed: wing solenoid is set to true
         *        When Y is unpressed: wing solenoid is set to false
         */
        wings.set(master.getDigital(ControllerDigital::Y));

        /**
         * @brief controls the mogo holder pistons using rising edge detection (上升緣觸發)
         *        When X is pressed: toggles the state of the mogo solenoid
         */
        mogoState = master.getDigital(ControllerDigital::X);
        if(!prevMogoState && mogoState){
            mogo.toggle();
        }
        prevMogoState = mogoState;

        /**
         * @brief controls the mogo clamp pistons using rising edge detection (上升緣觸發)
         *        When X is pressed: toggles the state of the mogo clamp
         */
        clampState = master.getDigital(ControllerDigital::R2);
        if(!prevClampState && clampState){
            mogoClamp.toggle();
        }
        prevClampState = clampState;

        pros::delay(10);
    }
}
