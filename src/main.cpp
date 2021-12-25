#include "main.h"
Trajectory path = {
        {0,0,0,0,0,0},
        {0.0005,0.0003,0.0488,0.033,4.6976,3.1775},
        {0.0018,0.0011,0.1328,0.0806,8.6453,4.8954},
        {0.004,0.0024,0.2241,0.1269,9.1873,4.6602},
        {0.0072,0.0041,0.3181,0.1723,9.4122,4.5498},
        {0.0113,0.0063,0.4125,0.218,9.4227,4.5632},
        {0.0164,0.0089,0.5069,0.2638,9.4248,4.5693},
        {0.0224,0.012,0.6014,0.3097,9.4239,4.5739},
        {0.0294,0.0156,0.6961,0.3546,9.5333,4.5256},
        {0.0373,0.0196,0.7886,0.4019,9.2222,4.7138},
        {0.0461,0.024,0.8842,0.4462,9.6001,4.4503},
        {0.0559,0.029,0.9767,0.4937,9.2184,4.734},
        {0.0666,0.0344,1.0722,0.5382,9.5811,4.4627},
        {0.0782,0.0402,1.1644,0.5858,9.2058,4.7567},
        {0.0908,0.0465,1.2591,0.6314,9.4582,4.5469},
        {0.1044,0.0533,1.3528,0.6778,9.3637,4.6414},
        {0.1188,0.0606,1.4462,0.7244,9.3478,4.6573},
        {0.1342,0.0683,1.5394,0.7711,9.3294,4.6756},
        {0.1505,0.0764,1.6323,0.8179,9.3083,4.6967},
        {0.1677,0.0851,1.7243,0.8659,9.1928,4.7876},
        {0.1859,0.0942,1.8177,0.9126,9.3378,4.6696},
        {0.205,0.1038,1.9099,0.9603,9.227,4.7799},
        {0.225,0.1139,2.001,1.0092,9.1036,4.8818},
        {0.246,0.1245,2.0933,1.0569,9.233,4.7749},
        {0.2678,0.1355,2.1843,1.1058,9.111,4.8963},
        {0.2905,0.1471,2.2742,1.156,8.9773,5.0108},
        {0.3142,0.1591,2.365,1.2051,9.0892,4.9183},
        {0.3387,0.1717,2.4538,1.2564,8.8701,5.1194},
        {0.3642,0.1848,2.5435,1.3068,8.9689,5.0382},
        {0.3905,0.1984,2.6317,1.3585,8.8247,5.1815},
        {0.4177,0.2125,2.7184,1.4117,8.6706,5.3193},
        {0.4457,0.2271,2.8059,1.4643,8.7492,5.2563},
        {0.4746,0.2423,2.8917,1.5184,8.591,5.4135},
        {0.5044,0.258,2.976,1.5741,8.4241,5.5655},
        {0.535,0.2743,3.0608,1.6293,8.4819,5.5215},
        {0.5664,0.2912,3.1439,1.6862,8.3105,5.6919},
        {0.5987,0.3087,3.2253,1.7448,8.1323,5.8564},
        {0.6318,0.3267,3.3077,1.8025,8.2442,5.7695},
        {0.6656,0.3453,3.3868,1.8632,7.9181,6.0813},
        {0.7003,0.3646,3.4649,1.9252,7.8008,6.1858},
        {0.7357,0.3844,3.5438,1.9863,7.8914,6.1182},
        {0.7719,0.4049,3.6195,2.0507,7.5652,6.4313},
        {0.8089,0.4261,3.6952,2.1149,7.5756,6.431},
        {0.8466,0.4479,3.7684,2.1817,7.3176,6.6766},
        {0.885,0.4704,3.8416,2.2485,7.3202,6.6837},
        {0.9241,0.4936,3.9123,2.3178,7.0653,6.9267},
        {0.9639,0.5174,3.9834,2.3866,7.1245,6.8871},
        {1.0044,0.542,4.051,2.4591,6.7529,7.2368},
        {1.0456,0.5673,4.1196,2.5304,6.865,7.1435},
        {1.0875,0.5934,4.1847,2.6053,6.507,7.4807},
        {1.13,0.6201,4.2513,2.6787,6.668,7.3473},
        {1.1731,0.6477,4.3135,2.7565,6.2145,7.7712},
        {1.2169,0.676,4.3777,2.8323,6.4208,7.5916},
        {1.2613,0.7051,4.4381,2.9119,6.0425,7.9503},
        {1.3062,0.7351,4.499,2.991,6.0853,7.9156},
        {1.3518,0.7658,4.5583,3.0717,5.9274,8.0725},
        {1.398,0.7973,4.6165,3.1535,5.8237,8.1753},
        {1.4448,0.8297,4.6738,3.2363,5.7239,8.2743},
        {1.492,0.8629,4.7305,3.3196,5.6724,8.3334},
        {1.5399,0.8969,4.7854,3.4046,5.4933,8.5036},
        {1.5883,0.9318,4.8399,3.4901,5.4484,8.548},
        {1.6373,0.9676,4.8939,3.5761,5.4038,8.6003},
        {1.6867,1.0042,4.9467,3.6633,5.283,8.7206},
        {1.7367,1.0417,4.9984,3.7516,5.169,8.8265},
        {1.7872,1.0801,5.0501,3.8399,5.1667,8.8365},
        {1.838,1.1193,5.0815,3.9128,3.1369,7.2879},
        {1.8886,1.1587,5.0592,3.9408,-2.2279,2.7987},
        {1.9389,1.1984,5.0313,3.9687,-2.7862,2.7864},
        {1.989,1.2383,5.0037,3.9962,-2.7562,2.7564},
        {2.0387,1.2786,4.9768,4.0232,-2.6979,2.6982},
        {2.0882,1.3191,4.9501,4.0499,-2.6653,2.6655},
        {2.1374,1.3598,4.9245,4.0755,-2.5654,2.5656},
        {2.1865,1.4008,4.8986,4.1013,-2.5819,2.5821},
        {2.2352,1.4421,4.8741,4.1259,-2.4518,2.452},
        {2.2837,1.4836,4.8494,4.1506,-2.4729,2.473},
        {2.3319,1.5253,4.8251,4.1749,-2.4299,2.43},
        {2.3799,1.5673,4.8015,4.1985,-2.3613,2.3614},
        {2.4277,1.6095,4.7779,4.2221,-2.3633,2.3634},
        {2.4753,1.652,4.7547,4.2453,-2.3199,2.32},
        {2.5226,1.6947,4.7318,4.2682,-2.2868,2.2869},
        {2.5697,1.7376,4.7088,4.2912,-2.3031,2.3032},
        {2.6165,1.7807,4.6863,4.3137,-2.2451,2.2452},
        {2.6632,1.8241,4.6635,4.3365,-2.282,2.282},
        {2.7096,1.8677,4.6412,4.3588,-2.2316,2.2316},
        {2.7558,1.9115,4.6186,4.3814,-2.2551,2.2552},
        {2.8018,1.9556,4.5961,4.4039,-2.2504,2.2504},
        {2.8475,1.9998,4.5735,4.4265,-2.2588,2.2588},
        {2.893,2.0443,4.5508,4.4492,-2.2721,2.2721},
        {2.9383,2.089,4.5279,4.4721,-2.29,2.29},
        {2.9833,2.134,4.5048,4.4952,-2.3091,2.3091},
        {3.0281,2.1792,4.4814,4.5186,-2.3399,2.3399},
        {3.0727,2.2245,4.4577,4.5423,-2.3732,2.3732},
        {3.117,2.2702,4.4336,4.5664,-2.4081,2.4081},
        {3.1611,2.3161,4.4091,4.5909,-2.4559,2.4559},
        {3.205,2.3623,4.384,4.616,-2.5087,2.5087},
        {3.2486,2.4087,4.3583,4.6417,-2.5683,2.5683},
        {3.2919,2.4554,4.3319,4.6681,-2.6351,2.635},
        {3.3349,2.5023,4.305,4.695,-2.6972,2.6971},
        {3.3777,2.5496,4.2771,4.7229,-2.7874,2.7873},
        {3.4202,2.5971,4.2483,4.7517,-2.8781,2.878},
        {3.4624,2.6449,4.2187,4.7813,-2.9612,2.961},
        {3.5042,2.693,4.1877,4.8123,-3.1009,3.1007},
        {3.5456,2.7412,4.1364,4.8229,-5.1293,1.0629},
        {3.586,2.7891,4.0392,4.7841,-9.7156,-3.8849},
        {3.6254,2.8365,3.9416,4.7416,-9.7607,-4.2473},
        {3.6639,2.8835,3.8452,4.6981,-9.6448,-4.3484},
        {3.7014,2.9301,3.7482,4.655,-9.6929,-4.3077},
        {3.7379,2.9762,3.6517,4.6115,-9.6481,-4.3522},
        {3.7734,3.0218,3.5552,4.568,-9.6575,-4.3502},
        {3.808,3.0671,3.4598,4.5234,-9.5338,-4.4579},
        {3.8417,3.1119,3.3638,4.4794,-9.5946,-4.4041},
        {3.8743,3.1562,3.2681,4.435,-9.5721,-4.4338},
        {3.9061,3.2001,3.1735,4.3897,-9.4623,-4.5347},
        {3.9368,3.2436,3.0786,4.3446,-9.4945,-4.5096},
        {3.9667,3.2866,2.9849,4.2983,-9.366,-4.6285},
        {3.9956,3.3291,2.891,4.2522,-9.3932,-4.6082},
        {4.0236,3.3711,2.798,4.2051,-9.2927,-4.7072},
        {4.0506,3.4127,2.7054,4.1579,-9.2734,-4.7334},
        {4.0768,3.4538,2.6148,4.1084,-9.0455,-4.9421},
        {4.102,3.4944,2.5228,4.0604,-9.2102,-4.8017},
        {4.1264,3.5345,2.4342,4.0091,-8.8608,-5.1312},
        {4.1498,3.5741,2.3451,3.9581,-8.9066,-5.0919},
        {4.1724,3.6131,2.2571,3.9061,-8.8008,-5.2045},
        {4.1941,3.6516,2.1709,3.8523,-8.6208,-5.3821},
        {4.215,3.6896,2.0867,3.7965,-8.4152,-5.5754},
        {4.235,3.727,2.0022,3.741,-8.4569,-5.5502},
        {4.2542,3.7639,1.921,3.6822,-8.112,-5.8823},
        {4.2726,3.8001,1.8403,3.6229,-8.0737,-5.9275},
        {4.2902,3.8357,1.7613,3.562,-7.9083,-6.1004},
        {4.3071,3.8707,1.6861,3.4971,-7.5048,-6.4796},
        {4.3232,3.905,1.6094,3.4338,-7.6756,-6.3375},
        {4.3386,3.9387,1.5383,3.3649,-7.1118,-6.8763},
        {4.3532,3.9716,1.4662,3.297,-7.2078,-6.7992},
        {4.3672,4.0039,1.3977,3.2255,-6.8553,-7.1489},
        {4.3805,4.0354,1.3321,3.1512,-6.5559,-7.433},
        {4.3932,4.0662,1.2662,3.077,-6.5917,-7.4182},
        {4.4052,4.0961,1.2049,2.9984,-6.1346,-7.8599},
        {4.4167,4.1254,1.1448,2.9184,-5.9997,-7.9911},
        {4.4275,4.1537,1.0851,2.8381,-5.9758,-8.0387},
        {4.4378,4.1812,1.03,2.7533,-5.5127,-8.486},
        {4.4476,4.2079,0.976,2.6673,-5.3959,-8.5997},
        {4.4568,4.2337,0.924,2.5793,-5.2022,-8.7901},
        {4.4656,4.2586,0.8728,2.4904,-5.1152,-8.8897},
        {4.4738,4.2826,0.8243,2.3989,-4.8508,-9.1521},
        {4.4816,4.3057,0.7775,2.3057,-4.6829,-9.3181},
        {4.4889,4.3278,0.7322,2.211,-4.5247,-9.4743},
        {4.4958,4.3489,0.6885,2.1148,-4.3764,-9.6205},
        {4.5022,4.3691,0.646,2.0171,-4.2382,-9.7564},
        {4.5083,4.3883,0.6039,1.9192,-4.218,-9.7956},
        {4.5139,4.4065,0.5649,1.8183,-3.8986,-10.0931},
        {4.5192,4.4237,0.526,1.7171,-3.886,-10.103},
        {4.5241,4.4398,0.487,1.6159,-3.8992,-10.1122},
        {4.5286,4.455,0.4499,1.5131,-3.7163,-10.2968},
        {4.5327,4.469,0.4146,1.4085,-3.5242,-10.4612},
        {4.5365,4.4821,0.378,1.3052,-3.6672,-10.3464},
        {4.5399,4.4941,0.3441,1.1991,-3.3898,-10.5916},
        {4.543,4.505,0.3086,1.0946,-3.5524,-10.4624},
        {4.5458,4.5149,0.2756,0.9874,-3.2845,-10.6911},
        {4.5482,4.5237,0.241,0.8819,-3.4647,-10.5512},
        {4.5503,4.5315,0.2078,0.7753,-3.3329,-10.6904},
        {4.552,4.5381,0.176,0.6672,-3.1732,-10.7948},
        {4.5535,4.5438,0.1433,0.5591,-3.2395,-10.7079},
        {4.5545,4.5483,0.1084,0.4538,-3.5101,-10.6073},
        {4.5553,4.5517,0.0785,0.3444,-3.0014,-10.9551},
        {4.5558,4.5541,0.0464,0.2354,-3.1543,-10.7191},
        {4.5559,4.5554,0.0128,0.125,-3.2281,-10.6175}
    };
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
}

enum class SussyAmogus{
    IDLE, AMOGUS
};

void opcontrol(){
    
    ProfileConstraint constraint({4.5_ftps, 9_ftps2, 20_ftps3});\
    pros::ADIDigitalOut E('D');
 
    auto test = std::move(AsyncMotionProfilerBuilder()
                          .withOutput(chassis)
                          .withProfiler(std::make_unique<SCurveMotionProfile>(constraint))
                          .withVelocityController(leftMotorController, rightMotorController)
                          .build());
    //pros::delay(1000);
    //test->moveDistance(4_ft);
    //pros::delay(1000);
    //test->stop();
    //test->waitUntilSettled();
    /*
    test->waitUntilSettled();
    test->moveDistance(-4_ft);
    claw.toggle();
    pros::delay(250);
    lift.moveVelocity(200);
    pros::delay(500);
    roller.moveVelocity(600);
    lift.moveVelocity(0);
    test->waitUntilSettled();
    claw.setState(true);
    */
    //test->turnAngle(90_deg);
    //test->waitUntilSettled();
    int liftPos = 0;
    
    auto liftController = AsyncPosControllerBuilder()
        .withMotor(lift)
        .withGains({0.007, 0.0, 0.000075}) 
        .build();

    while(true){
        double power = master.getAnalog(ControllerAnalog::leftY) * (abs(master.getAnalog(ControllerAnalog::leftY)) >= DEADBAND);
        double curvature = master.getAnalog(ControllerAnalog::rightX) * (abs(master.getAnalog(ControllerAnalog::rightX)) >= DEADBAND);
        auto speed = curvatureDrive(power, curvature, power == 0);
		(chassis->getModel())->tank(speed.first, speed.second);

        if(master.getDigital(okapi::ControllerDigital::L1)){
            liftPos += 11;
            //lift.moveVoltage(12000);
            
        }
        else if(master.getDigital(okapi::ControllerDigital::L2)){
            liftPos -= 11;
            //lift.moveVoltage(-12000);
        }

        liftPos = std::max(std::min(liftPos, 750), 0);

        liftController->setTarget(liftPos);

        E.set_value(master.getDigital(ControllerDigital::R1));
        pros::delay(10);
    }
}

void op(){
        std::unique_ptr<Auton> auton = std::move(std::make_unique<Auton>());
    auton->init();
    auton->right();
    auton.reset();

    std::unique_ptr<Conveyor> conveyor = std::move(std::make_unique<Conveyor>(std::make_shared<Motor>(roller)));
    conveyor->startTask("conveyorTask");

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
        claw.setState(master.getDigital(ControllerDigital::R1));
        wings.setState(master.getDigital(ControllerDigital::Y));

        /**
         * @brief Mogo Holder Control
         * The solenoid toggles between the two states every time R2 (Right Bottom) is pressed
         */
        currentBtnState = master.getDigital(ControllerDigital::R2);
        if(currentBtnState && !prevBtnState){
            mogoState = !mogoState;
            mogoClamp.toggle();
        }
        prevBtnState = currentBtnState;

        _currentBtnState = master.getDigital(ControllerDigital::X);
        if(_currentBtnState && !_prevBtnState){
            _mogoState = !_mogoState;
            mogo.toggle();
        }
        _prevBtnState = _currentBtnState;

        pros::delay(10);
    }
}
