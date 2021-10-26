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
    std::vector<std::vector<double>> testLeft = {
        {0,0},
        {0.0823,8.1513},
        {0.2374,15.3707},
        {0.4059,17.1488},
        {0.5721,16.5438},
        {0.7428,17.126},
        {0.9113,16.8671},
        {1.081,16.9828},
        {1.2508,16.9197},
        {1.4228,17.2543},
        {1.5921,16.9426},
        {1.7632,17.0526},
        {1.9368,17.381},
        {2.1085,17.1902},
        {2.2806,17.2294},
        {2.4537,17.2728},
        {2.6293,17.5876},
        {2.8023,17.3066},
        {2.9767,17.4155},
        {3.1535,17.7067},
        {3.3268,17.32},
        {3.5034,17.6482},
        {3.679,17.5713},
        {3.8536,17.4645},
        {4.0284,17.4961},
        {4.2013,17.2601},
        {4.3767,17.5589},
        {4.5376,16.0832},
        {4.59,5.2424},
        {4.591,0.1001},
        {4.5846,-0.6448},
        {4.5772,-0.7328},
        {4.5697,-0.7537},
        {4.5585,-1.1183},
        {4.5466,-1.1977},
        {4.5338,-1.2764},
        {4.519,-1.4825},
        {4.5028,-1.6128},
        {4.4855,-1.7351},
        {4.4682,-1.7288},
        {4.4474,-2.0799},
        {4.4275,-1.9935},
        {4.406,-2.1423},
        {4.3844,-2.1664},
        {4.3609,-2.3474},
        {4.3379,-2.3},
        {4.3138,-2.4083},
        {4.2888,-2.5008},
        {4.2649,-2.3925},
        {4.2396,-2.5247},
        {4.2133,-2.6344},
        {4.1886,-2.4726},
        {4.1624,-2.617},
        {4.137,-2.5406},
        {4.1111,-2.586},
        {4.0849,-2.6193},
        {4.0595,-2.5406},
        {4.0338,-2.5706},
        {4.0079,-2.5901},
        {3.9831,-2.4845},
        {3.9572,-2.5913},
        {3.932,-2.5114},
        {3.9076,-2.4464},
        {3.8823,-2.5311},
        {3.8579,-2.4379},
        {3.8334,-2.4454},
        {3.809,-2.4452},
        {3.7851,-2.3888},
        {3.7612,-2.3926},
        {3.7374,-2.3762},
        {3.7136,-2.3842},
        {3.6905,-2.3062},
        {3.667,-2.3549},
        {3.6438,-2.3161},
        {3.6208,-2.2994},
        {3.5978,-2.3046},
        {3.5749,-2.2877},
        {3.5521,-2.2798},
        {3.5293,-2.2804},
        {3.5066,-2.2712},
        {3.4838,-2.272},
        {3.4611,-2.2701},
        {3.4384,-2.2712},
        {3.4158,-2.2663},
        {3.3929,-2.2911},
        {3.3701,-2.2771},
        {3.3473,-2.278},
        {3.3242,-2.3068},
        {3.3013,-2.2923},
        {3.2779,-2.3457},
        {3.2549,-2.2974},
        {3.2315,-2.3362},
        {3.2078,-2.3699},
        {3.1842,-2.3668},
        {3.1606,-2.3565},
        {3.1367,-2.3897},
        {3.1124,-2.4303},
        {3.0885,-2.3927},
        {3.0639,-2.4595},
        {3.0397,-2.4141},
        {3.0149,-2.4849},
        {2.9906,-2.4306},
        {2.9655,-2.5042},
        {2.9411,-2.4393},
        {2.916,-2.5141},
        {2.8912,-2.4782},
        {2.8669,-2.4308},
        {2.8419,-2.5043},
        {2.8174,-2.4516},
        {2.7935,-2.3862},
        {2.7685,-2.5029},
        {2.7451,-2.3346},
        {2.7217,-2.3446},
        {2.6986,-2.3022},
        {2.6756,-2.3074},
        {2.6541,-2.144},
        {2.6317,-2.2464},
        {2.6122,-1.9494},
        {2.5918,-2.0386},
        {2.5722,-1.9556},
        {2.5548,-1.7389},
        {2.5373,-1.7575},
        {2.5214,-1.5857},
        {2.5067,-1.4669},
        {2.4927,-1.4086},
        {2.4812,-1.1452},
        {2.4698,-1.1423},
        {2.4604,-0.9349},
        {2.4525,-0.7899},
        {2.4454,-0.7133},
        {2.4405,-0.495},
        {2.4377,-0.2728},
        {2.3885,-4.9222},
        {2.2853,-10.3235},
        {2.1952,-9.0071},
        {2.1046,-9.0684},
        {2.0177,-8.6777},
        {1.9267,-9.1077},
        {1.8405,-8.6136},
        {1.7514,-8.9169},
        {1.6637,-8.7711},
        {1.575,-8.871},
        {1.4867,-8.8193},
        {1.3965,-9.0266},
        {1.3082,-8.8236},
        {1.2172,-9.115},
        {1.1278,-8.9123},
        {1.0349,-9.303},
        {0.9446,-9.0234},
        {0.8515,-9.3237},
        {0.7603,-9.1005},
        {0.6656,-9.5052},
        {0.5736,-9.1912},
        {0.4796,-9.3668},
        {0.3843,-9.5255},
        {0.2905,-9.3536},
        {0.1952,-9.4185},
        {0.0991,-9.6715}
    }
    ;
    std::vector<std::vector<double>> testRight = {
        {0,0},
        {0.0604,5.9816},
        {0.16,9.8697},
        {0.2528,9.4519},
        {0.3474,9.416},
        {0.4394,9.2201},
        {0.5328,9.3539},
        {0.6253,9.2598},
        {0.7184,9.2719},
        {0.8089,9.0799},
        {0.9015,9.2744},
        {0.9932,9.1382},
        {1.0823,8.9189},
        {1.1729,9.0694},
        {1.2629,9.0025},
        {1.3524,8.9399},
        {1.4393,8.704},
        {1.5286,8.9288},
        {1.6168,8.8046},
        {1.7024,8.5785},
        {1.7914,8.8954},
        {1.8775,8.6034},
        {1.9643,8.6875},
        {2.0521,8.7792},
        {2.1396,8.7547},
        {2.2293,8.9586},
        {2.3164,8.7226},
        {2.4035,8.7033},
        {2.4099,0.6412},
        {2.4089,-0.1},
        {2.4154,0.6448},
        {2.4227,0.7329},
        {2.4302,0.7538},
        {2.4414,1.1184},
        {2.4534,1.1977},
        {2.4662,1.2765},
        {2.481,1.4826},
        {2.4971,1.6129},
        {2.5145,1.7353},
        {2.5318,1.7289},
        {2.5526,2.08},
        {2.5725,1.9936},
        {2.5939,2.1424},
        {2.6156,2.1666},
        {2.6391,2.3476},
        {2.6621,2.3002},
        {2.6861,2.4085},
        {2.7112,2.501},
        {2.7351,2.3927},
        {2.7603,2.5249},
        {2.7867,2.6346},
        {2.8114,2.4728},
        {2.8376,2.6172},
        {2.863,2.5408},
        {2.8889,2.5861},
        {2.9151,2.6194},
        {2.9405,2.5407},
        {2.9662,2.5708},
        {2.9921,2.5902},
        {3.0169,2.4847},
        {3.0428,2.5914},
        {3.068,2.5116},
        {3.0924,2.4466},
        {3.1177,2.5313},
        {3.1421,2.4381},
        {3.1666,2.4455},
        {3.191,2.4453},
        {3.2149,2.3889},
        {3.2388,2.3927},
        {3.2626,2.3763},
        {3.2864,2.3842},
        {3.3095,2.3063},
        {3.333,2.3549},
        {3.3562,2.3161},
        {3.3792,2.2995},
        {3.4022,2.3046},
        {3.4251,2.2878},
        {3.4479,2.2798},
        {3.4707,2.2804},
        {3.4934,2.2712},
        {3.5162,2.272},
        {3.5389,2.2701},
        {3.5616,2.2711},
        {3.5842,2.2663},
        {3.6071,2.2911},
        {3.6299,2.2771},
        {3.6527,2.2779},
        {3.6758,2.3067},
        {3.6987,2.2922},
        {3.7221,2.3456},
        {3.7451,2.2973},
        {3.7685,2.3362},
        {3.7922,2.3698},
        {3.8158,2.3667},
        {3.8394,2.3564},
        {3.8633,2.3896},
        {3.8876,2.4302},
        {3.9115,2.3926},
        {3.9361,2.4593},
        {3.9603,2.4139},
        {3.9851,2.4848},
        {4.0094,2.4304},
        {4.0345,2.504},
        {4.0589,2.4391},
        {4.084,2.5139},
        {4.1088,2.478},
        {4.1331,2.4307},
        {4.1581,2.5041},
        {4.1826,2.4514},
        {4.2065,2.386},
        {4.2315,2.5027},
        {4.2548,2.3344},
        {4.2783,2.3444},
        {4.3013,2.302},
        {4.3244,2.3072},
        {4.3458,2.1438},
        {4.3683,2.2463},
        {4.3878,1.9492},
        {4.4082,2.0385},
        {4.4277,1.9555},
        {4.4451,1.7388},
        {4.4627,1.7574},
        {4.4785,1.5856},
        {4.4932,1.4668},
        {4.5073,1.4085},
        {4.5187,1.1451},
        {4.5302,1.1422},
        {4.5395,0.9349},
        {4.5474,0.7899},
        {4.5545,0.7132},
        {4.5595,0.495},
        {4.5622,0.2727},
        {4.5025,-5.9713},
        {4.3443,-15.8265},
        {4.1719,-17.2317},
        {4.0001,-17.1975},
        {3.8245,-17.5322},
        {3.653,-17.1755},
        {3.4768,-17.6106},
        {3.3034,-17.3396},
        {3.1287,-17.4699},
        {2.9549,-17.3802},
        {2.7806,-17.4128},
        {2.6083,-17.2488},
        {2.4342,-17.3977},
        {2.2629,-17.1531},
        {2.0895,-17.2883},
        {1.9198,-16.9936},
        {1.7476,-17.1981},
        {1.5784,-16.9629},
        {1.4071,-17.0838},
        {1.2394,-16.8203},
        {1.0693,-17.0115},
        {0.9003,-16.8253},
        {0.7326,-16.7798},
        {0.5635,-16.8469},
        {0.3944,-16.7275},
        {0.2274,-16.8071}
    }
    ;
    // auton[selectedAuton]();
    leftDrive.setBrakeMode(AbstractMotor::brakeMode::hold);
    rightDrive.setBrakeMode(AbstractMotor::brakeMode::hold);

    pros::lcd::set_text(0, "auton");
    // chassis->setState({0_in, 0_in, 0_deg});
    // profiler->generatePath({{0_in, 0_in, 0_deg}, {4_ft, 4_ft, 90_deg}, {0_ft, 4_ft, 180_deg}}, "Test");
    // pros::lcd::set_text(1, "pathgen");
    // profiler->setTarget("Test");
    // profiler->waitUntilSettled();
    std::vector<double> left = pathToRPM(testLeft); std::vector<double> right = pathToRPM(testRight);
    std::uint32_t now = pros::millis();
    for(int i = 0; i < left.size(); i++) {
        leftDrive.moveVelocity(left[i]);
        rightDrive.moveVelocity(right[i]);
        pros::delay(10);
        // pros::Task::delay_until(&now, 10);
    }


    // \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\//
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