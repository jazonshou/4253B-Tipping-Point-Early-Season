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
    Auton auton = Auton();
    auton.init();
    auton.wingGrab();
}

void opcontrol(){
    std::unique_ptr<Auton> auton(new Auton());
    auton->init();
    auton->right();
    auton.reset();

    std::unique_ptr<Conveyor> c(new Conveyor(std::make_shared<Motor> (roller)));
    c->loop();

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

    // Configures brake type for drive & lift
    leftDrive.setBrakeMode(AbstractMotor::brakeMode::coast);
    rightDrive.setBrakeMode(AbstractMotor::brakeMode::coast);
    lift.setBrakeMode(AbstractMotor::brakeMode::brake);
    
    imu.reset();

    // Initializes driver control variable
    double liftPosition = 0.0;
    bool mogoState = false, prevBtnState = false, currentBtnState = false;
    bool _mogoState = false, _prevBtnState = false, _currentBtnState = false;
    
    // Initializes logo on the brain screen
    // Gif gif("/usd/logo.gif", lv_scr_act()); // TODO - Make Gif Run in opcontrol
    double value = 0;;
    leftDrive.tarePosition();
    rightDrive.tarePosition();

    while(true){
        
        wings.set_value(false);
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
         * Both are pressed -> Conveyor goes up
         * Both are unpressed -> No movement
         */
        if(master.getDigital(ControllerDigital::L1) && master.getDigital(ControllerDigital::L2)){
            roller.moveVoltage(12000); 
            lift.moveVoltage(0);
        }
        else if(master.getDigital(ControllerDigital::L1)){
            lift.moveVoltage(12000);
            roller.moveVoltage(0);
        }
        else if(master.getDigital(ControllerDigital::L2)){
            lift.moveVoltage(-12000);
            roller.moveVoltage(0);
        }
        else if(master.getDigital(ControllerDigital::A)){
            roller.moveVoltage(-12000);
            lift.moveVoltage(0);
        }
        else {
            lift.moveVoltage(0);
            roller.moveVoltage(0);
        }

        /**
         * @brief Solenod Control (Direct)
         * R1 (Right Top) Pressed -> claw closes
         * R1 (Right Top) not pressed -> claw opens
         * Y Pressed -> wing opens
         * Y not pressed -> claw closes
         */
        claw.set_value(master.getDigital(ControllerDigital::R1));
        wings.set_value(master.getDigital(ControllerDigital::Y));

        /**
         * @brief Mogo Holder Control
         * The solenoid toggles between the two states every time R2 (Right Bottom) is pressed
         */
        currentBtnState = master.getDigital(ControllerDigital::R2);
        if(currentBtnState && !prevBtnState){
            mogoState = !mogoState;
            mogoClamp.set_value(mogoState);
        }
        prevBtnState = currentBtnState;

        _currentBtnState = master.getDigital(ControllerDigital::X);
        if(_currentBtnState && !_prevBtnState){
            _mogoState = !_mogoState;
            mogo.set_value(_mogoState);
        }
        _prevBtnState = _currentBtnState;

        pros::delay(10);
    }
}