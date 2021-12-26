#include "main.h"

void initialize(){
	pros::lcd::initialize();
    
    pros::vision_signature_s_t RED_SIG = pros::Vision::signature_from_utility(1, 5685, 8135, 6910, -1963, -1705, -1834, 4.000, 0);
    // pros::vision_signature_s_t BLUE_SIG = pros::Vision::signature_from_utility()

    vision_sensor.set_signature(1, &RED_SIG);

    pros::lcd::set_text(2, "imu calibrating..............");
    imu.calibrate();
    pros::delay(2000);
    pros::lcd::set_text(2, "imu calibrated");
}

void disabled(){}

void competition_initialize(){}

void autonomous(){
    //Auton auton = Auton();
    //auton.init();
    //auton.wingGrab();

    std::unique_ptr<Auton> auton = std::move(std::make_unique<Auton>());
    auton->init();
    auton->right();
    auton.reset();
}

void opcontrol(){
    // Creates a black background
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

    // Starts crab rave gif
    // Gif gif("/usd/crab-rave.gif", lv_scr_act());

    int liftPos = 0;
    bool clampState = false, prevClampState = false;
    bool mogoState = false, prevMogoState = false;

    leftDrive.setBrakeMode(AbstractMotor::brakeMode::coast);
    rightDrive.setBrakeMode(AbstractMotor::brakeMode::coast);

    while(true){
        double power = master.getAnalog(ControllerAnalog::leftY) * (abs(master.getAnalog(ControllerAnalog::leftY)) >= DEADBAND);
        double curvature = master.getAnalog(ControllerAnalog::rightX) * (abs(master.getAnalog(ControllerAnalog::rightX)) >= DEADBAND);
        curvatureDrive(power, curvature, power == 0);

        liftPos += LIFT_STEP * master.getDigital(ControllerDigital::L1); 
        liftPos -= LIFT_STEP * master.getDigital(ControllerDigital::L2);
        liftController->setTarget(liftPos = std::max(std::min(liftPos, MAX_LIFT_HEIGHT), 0));

        roller.moveVoltage(12000*((master.getDigital(ControllerDigital::L1) && master.getDigital(ControllerDigital::L2))-master.getDigital(ControllerDigital::A)));

        claw.set(master.getDigital(ControllerDigital::R1));
        wings.set(master.getDigital(ControllerDigital::Y));

        clampState = master.getDigital(ControllerDigital::R2);
        if(clampState && !prevClampState) {mogoClamp.toggle();}
        prevClampState = clampState;

        mogoState = master.getDigital(ControllerDigital::X);
        if(mogoState && !prevMogoState) {mogo.toggle();}
        prevMogoState = mogoState;

        pros::delay(10);
    }
}
