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
}

void disabled(){}

void competition_initialize(){}

void autonomous(){
    Auton a = Auton();
    a.init();
    a.skills();
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

        if(master.getDigital(ControllerDigital::L1) && master.getDigital(ControllerDigital::L2)) {
            lift.moveVelocity(0);
        } else if(master.getDigital(ControllerDigital::L1)) {
            lift.moveVoltage(12000);
        } else if(master.getDigital(ControllerDigital::L2)) {
            lift.moveVoltage(-12000);
        } else {
            lift.moveVelocity(0);
        }

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

        if((leftDrive.getTemperature() + rightDrive.getTemperature()) / 2 >= 55 && lift.getTemperature() >= 55) {
            master.rumble(". - ");
        } else if(lift.getTemperature() >= 55) {
            master.rumble(". ");
        } else if((leftDrive.getTemperature() + rightDrive.getTemperature()) / 2 >= 55) {
            master.rumble("- ");
        }

        pros::delay(10);
    }
}
