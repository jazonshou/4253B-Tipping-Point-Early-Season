#include "main.h"

// pros::Mutex Auton::lock;
// std::vector<std::function<void()>> Auton::auton;
// std::vector<std::string> Auton::name;
// int Auton::index = 0;


// void Auton::add(std::function<void()> iAutonomous, std::string iName){
//     auton.push_back(iAutonomous);
//     name.push_back(iName);
// }

// void Auton::switchAuton(){
//     lock.take(5);
//     index++;
//     index %= auton.size();
//     lock.give();
// }

// void Auton::select(){
//     pros::lcd::register_btn1_cb([](){});
//     pros::lcd::register_btn2_cb([](){});
//     //addPath(index);
// }

// std::string Auton::getName(){
//     lock.take(5);
//     std::string ret = name[index];
//     lock.give();
//     return ret;
// }

// void Auton::execute(){
//     auton[index];
// }




/**
 * @brief Initializes the auton
 * 
 */
void Auton::init() {
    // INITIALIZATION
    leftDrive.setBrakeMode(AbstractMotor::brakeMode::hold);
    rightDrive.setBrakeMode(AbstractMotor::brakeMode::hold);
    lift.setBrakeMode(AbstractMotor::brakeMode::hold);
    this->liftController = AsyncPosControllerBuilder()
	    .withMotor(lift)
	    .withGains({0.007, 0.0, 0.000075}) 
	    .build();
    liftController->reset();
    
}

/**
 * @brief Only the wing grab portion
 * 
 */
void Auton::wingGrab() {
    std::cout << "hello world\n";
    wings.set(true);
    std::cout << "moving \n\n";
    // moveDistance(-3.5_ft);
    profiler->setTarget(-2.75_ft);
    pros::delay(775);

    wings.set(false);
    profiler->waitUntilSettled();

    // moveDistance(3_ft, 2_s);
    profiler->setTarget(3.5_ft);
    profiler->waitUntilSettled();

    wings.set(true); pros::delay(500); wings.set(false); pros::delay(500);
}

void Auton::left(){
    
}

void Auton::right(){
    wingGrab();
    
    profiler->setTarget(-1.75_ft);
    profiler->waitUntilSettled();
    turnToAngle(90_deg);

    profiler->setTarget(-3_ft);
    profiler->waitUntilSettled();
    // moveTime({-0.5, -0.5}, 250_ms);
    // pros::delay(250);
    mogoClamp.set(true); pros::delay(250); mogo.set(true);

    profiler->setTarget(6_in);
    liftController->setTarget(710);
    profiler->waitUntilSettled();
    turnToAngle(180_deg);

    roller.moveVoltage(12000);
    profiler->setTarget(3_ft);
    profiler->waitUntilSettled();
    profiler->setTarget(-3_ft);
    profiler->waitUntilSettled();
    turnToAngle(0_deg);
    
    // oscillate match load
    for(int i = 0; i < 3; i++) {
        profiler->setTarget(2_ft);
        profiler->waitUntilSettled();
        profiler->setTarget(-2_ft);
        profiler->waitUntilSettled();
    }
}

void Auton::awp(){
    wingGrab();
    turnToAngle(0_deg);
    
    profiler->setTarget(-1.6_ft);
    profiler->waitUntilSettled();
    turnToAngle(90_deg);

    profiler->setTarget(-3_ft);
    profiler->waitUntilSettled();
    // moveTime({-0.5, -0.5}, 250_ms);
    // pros::delay(250);
    mogoClamp.set(true); pros::delay(250); mogo.set(true);

    // profiler->setTarget(6_in);
    // liftController->setTarget(710);
    // profiler->waitUntilSettled();
    // turnToAngle(180_deg);

    // roller.moveVoltage(12000);
    // profiler->setTarget(3_ft);
    // profiler->waitUntilSettled();
    // profiler->setTarget(-2.91_ft);
    // profiler->waitUntilSettled();
    // turnToAngle(90_deg);

    profiler->setTarget(9_ft);
    roller.moveVoltage(12000); pros::delay(125); roller.moveVoltage(0);
    pros::delay(750);
    mogoClamp.set(false); mogo.set(false);
    roller.moveVoltage(0);
    profiler->waitUntilSettled();

    
    profiler->setTarget(-2_ft);
    profiler->waitUntilSettled();
    turnToAngle(90_deg);
    profiler->setTarget(2_ft);
    profiler->waitUntilSettled();
    profiler->setTarget(-1_ft);
    profiler->waitUntilSettled();
    
    turnToAngle(140_deg);
    profiler->setTarget(-2_ft);
    profiler->waitUntilSettled();

    mogoClamp.set(true); pros::delay(250); mogo.set(true);

    turnToAngle(90_deg);
    profiler->setTarget(1.5_ft);
    profiler->waitUntilSettled();
}

Trajectory path1 = {
        {0,0,0,0,0,0},
        {0.0003,0.0004,0.0276,0.0358,2.72,3.53},
        {0.0009,0.0012,0.0643,0.0876,3.6324,5.1178},
        {0.002,0.0028,0.1047,0.1485,3.9871,6.0135},
        {0.0034,0.0048,0.1433,0.2097,3.9285,6.2344},
        {0.0052,0.0075,0.1826,0.2691,3.9569,5.9806},
        {0.0074,0.0108,0.2215,0.3297,3.9006,6.0689},
        {0.01,0.0147,0.2607,0.3907,3.9059,6.0776},
        {0.013,0.0192,0.299,0.4519,3.877,6.1943},
        {0.0164,0.0243,0.3393,0.5114,4.0007,5.9059},
        {0.0202,0.03,0.3771,0.5737,3.7994,6.2637},
        {0.0243,0.0363,0.4167,0.6337,3.9682,6.0204},
        {0.0289,0.0433,0.4556,0.6946,3.897,6.0954},
        {0.0338,0.0508,0.4946,0.7556,3.8949,6.1003},
        {0.0392,0.059,0.5335,0.8167,3.8921,6.1051},
        {0.0449,0.0678,0.5724,0.8778,3.8889,6.1098},
        {0.051,0.0772,0.6113,0.939,3.8853,6.1147},
        {0.0575,0.0872,0.6501,1.0002,3.8814,6.1196},
        {0.0644,0.0978,0.6889,1.0614,3.8772,6.1246},
        {0.0717,0.109,0.7276,1.1227,3.8728,6.1296},
        {0.0793,0.1208,0.7662,1.184,3.8683,6.1348},
        {0.0874,0.1333,0.8056,1.2448,3.9177,6.0559},
        {0.0958,0.1464,0.8428,1.3076,3.7349,6.3007},
        {0.1046,0.1601,0.8827,1.3677,3.9794,5.9976},
        {0.1139,0.1744,0.9205,1.4299,3.7807,6.2263},
        {0.1234,0.1893,0.9589,1.4915,3.8452,6.1619},
        {0.1334,0.2048,0.9972,1.553,3.8403,6.1669},
        {0.1437,0.2209,1.0361,1.6139,3.8937,6.0904},
        {0.1545,0.2377,1.0745,1.6758,3.8206,6.1662},
        {0.1656,0.2551,1.1113,1.7389,3.6989,6.3332},
        {0.1771,0.273,1.1508,1.7992,3.9526,6.0354},
        {0.189,0.2917,1.189,1.8611,3.8099,6.1803},
        {0.2013,0.3109,1.2264,1.9237,3.7472,6.264},
        {0.2139,0.3307,1.2652,1.9849,3.8742,6.1181},
        {0.227,0.3513,1.3033,2.0469,3.8026,6.1912},
        {0.2404,0.3723,1.3406,2.1096,3.7404,6.2723},
        {0.2542,0.394,1.3793,2.1708,3.8697,6.1255},
        {0.2683,0.4164,1.4174,2.2329,3.7999,6.1965},
        {0.2829,0.4393,1.4547,2.2955,3.7389,6.2746},
        {0.2978,0.4629,1.4941,2.3561,3.9323,6.0495},
        {0.3131,0.4871,1.5308,2.4194,3.6728,6.3415},
        {0.3288,0.5118,1.5695,2.4806,3.8765,6.1225},
        {0.3449,0.5373,1.6083,2.5418,3.8728,6.1125},
        {0.3613,0.5633,1.6451,2.6051,3.6855,6.3296},
        {0.3782,0.59,1.684,2.6661,3.8924,6.1084},
        {0.3954,0.6173,1.723,2.7271,3.8929,6.0951},
        {0.413,0.6452,1.7607,2.7895,3.7716,6.2307},
        {0.431,0.6737,1.7992,2.851,3.8511,6.1515},
        {0.4494,0.7028,1.8378,2.9124,3.8632,6.1396},
        {0.4681,0.7325,1.8766,2.9736,3.8769,6.1261},
        {0.4873,0.7629,1.9161,3.034,3.9542,6.0371},
        {0.5069,0.7938,1.9546,3.0956,3.8415,6.1623},
        {0.5268,0.8254,1.9938,3.1563,3.9287,6.0752},
        {0.5471,0.8575,2.0339,3.2161,4.0109,5.9818},
        {0.5679,0.8903,2.073,3.2771,3.9048,6.0996},
        {0.589,0.9237,2.1136,3.3365,4.0581,5.9355},
        {0.6105,0.9577,2.1532,3.397,3.9568,6.0478},
        {0.6325,0.9922,2.1936,3.4565,4.0524,5.9521},
        {0.6548,1.0274,2.2351,3.515,4.1435,5.8507},
        {0.6776,1.0631,2.2756,3.5745,4.0497,5.9548},
        {0.7007,1.0994,2.3177,3.6323,4.2104,5.7842},
        {0.7243,1.1363,2.3589,3.6911,4.122,5.8824},
        {0.7483,1.1738,2.4017,3.7483,4.2851,5.7097},
        {0.7728,1.2119,2.4437,3.8063,4.2022,5.802},
        {0.7977,1.2505,2.4874,3.8626,4.3675,5.6274},
        {0.823,1.2897,2.5303,3.9197,4.29,5.7139},
        {0.8487,1.3295,2.5749,3.9751,4.4569,5.5379},
        {0.8749,1.3698,2.6188,4.0313,4.3848,5.6187},
        {0.9016,1.4106,2.6637,4.0864,4.4966,5.5065},
        {0.9286,1.452,2.7092,4.1409,4.5471,5.4557},
        {0.9562,1.494,2.7557,4.1943,4.6541,5.3401},
        {0.9842,1.5365,2.8022,4.2478,4.6461,5.3481},
        {1.0127,1.5795,2.8481,4.3019,4.5922,5.4179},
        {1.0417,1.623,2.8969,4.3532,4.8733,5.1204},
        {1.0711,1.6671,2.9445,4.4056,4.7579,5.2435},
        {1.101,1.7116,2.9932,4.4569,4.8725,5.1286},
        {1.1315,1.7567,3.0425,4.5076,4.9289,5.0718},
        {1.1624,1.8023,3.0923,4.5577,4.9854,5.0149},
        {1.1938,1.8483,3.1427,4.6073,5.0421,4.958},
        {1.2258,1.8949,3.1942,4.6558,5.1474,4.845},
        {1.2582,1.942,3.2447,4.7053,5.0526,4.9542},
        {1.2912,1.9895,3.2974,4.7527,5.2639,4.7352},
        {1.3247,2.0375,3.3501,4.8,5.2657,4.7331},
        {1.3587,2.086,3.4028,4.8473,5.2743,4.7312},
        {1.3933,2.1349,3.4575,4.8926,5.4693,4.5221},
        {1.4284,2.1843,3.5108,4.9393,5.3322,4.6727},
        {1.4641,2.2342,3.5661,4.984,5.5269,4.471},
        {1.5003,2.2844,3.6209,5.0292,5.4857,4.5186},
        {1.537,2.3351,3.6771,5.0729,5.6244,4.373},
        {1.5744,2.3863,3.7334,5.1166,5.6247,4.3726},
        {1.6123,2.4379,3.7897,5.1603,5.6315,4.3722},
        {1.6507,2.49,3.8473,5.2027,5.7606,4.2366},
        {1.6898,2.5424,3.9045,5.2455,5.7216,4.2818},
        {1.7294,2.5953,3.963,5.287,5.8442,4.1529},
        {1.7696,2.6485,4.021,5.329,5.8061,4.1972},
        {1.8104,2.7022,4.0802,5.3698,5.922,4.0751},
        {1.8518,2.7564,4.1395,5.4106,5.919,4.0783},
        {1.8938,2.8109,4.1987,5.4514,5.9224,4.081},
        {1.9364,2.8658,4.2586,5.4914,5.9964,4.007},
        {1.9796,2.9211,4.3192,5.5308,6.0617,3.9361},
        {2.0234,2.9768,4.3798,5.5702,6.0576,3.9405},
        {2.0678,3.0329,4.4407,5.6093,6.0896,3.9088},
        {2.1128,3.0894,4.5016,5.6484,6.0922,3.9122},
        {2.1584,3.1462,4.5635,5.6866,6.1842,3.8149},
        {2.2047,3.2035,4.6253,5.7247,6.1808,3.8187},
        {2.2515,3.2611,4.6797,5.7539,5.4417,2.9136},
        {2.2981,3.3181,4.6639,5.7051,-1.5825,-4.8814},
        {2.3445,3.3744,4.6353,5.6338,-2.8661,-7.1321},
        {2.3906,3.4301,4.6065,5.5625,-2.8758,-7.1229},
        {2.4363,3.4849,4.5768,5.4922,-2.9691,-7.0358},
        {2.4818,3.5392,4.5473,5.4218,-2.9519,-7.0421},
        {2.5269,3.5927,4.5164,5.3527,-3.0915,-6.9087},
        {2.5718,3.6456,4.4851,5.2839,-3.1245,-6.8762},
        {2.6163,3.6977,4.4533,5.2157,-3.1806,-6.8205},
        {2.6605,3.7492,4.421,5.1481,-3.2345,-6.7672},
        {2.7044,3.8,4.3884,5.0807,-3.2635,-6.7328},
        {2.748,3.8502,4.355,5.0141,-3.3348,-6.6618},
        {2.7912,3.8996,4.3208,4.9483,-3.424,-6.5852},
        {2.8341,3.9484,4.2871,4.882,-3.3676,-6.6238},
        {2.8766,3.9966,4.252,4.817,-3.5083,-6.4957},
        {2.9188,4.0441,4.2171,4.752,-3.4932,-6.5051},
        {2.9605,4.091,4.1814,4.6877,-3.5686,-6.4364},
        {3.002,4.1372,4.1458,4.6232,-3.5541,-6.4385},
        {3.0431,4.1828,4.1093,4.5598,-3.6561,-6.3497},
        {3.0839,4.2278,4.073,4.4961,-3.627,-6.3662},
        {3.1242,4.2721,4.0358,4.4332,-3.72,-6.2865},
        {3.1642,4.3159,3.9988,4.3702,-3.6936,-6.3001},
        {3.2038,4.3589,3.9611,4.3079,-3.7781,-6.2292},
        {3.243,4.4014,3.9235,4.2455,-3.7546,-6.2396},
        {3.2819,4.4432,3.8853,4.1837,-3.8183,-6.1828},
        {3.3204,4.4844,3.847,4.122,-3.833,-6.1684},
        {3.3584,4.525,3.8085,4.0606,-3.8578,-6.1438},
        {3.3962,4.565,3.7697,3.9993,-3.8711,-6.1237},
        {3.4335,4.6044,3.7306,3.9384,-3.9129,-6.089},
        {3.4704,4.6432,3.6913,3.8777,-3.9263,-6.0758},
        {3.5069,4.6813,3.6519,3.8172,-3.9474,-6.0549},
        {3.543,4.7189,3.6123,3.7568,-3.9597,-6.0354},
        {3.5787,4.7559,3.5724,3.6967,-3.9928,-6.0096},
        {3.6141,4.7923,3.5323,3.6367,-3.9993,-5.9957},
        {3.649,4.828,3.492,3.577,-4.0285,-5.9739},
        {3.6835,4.8632,3.4516,3.5174,-4.0419,-5.9605},
        {3.7176,4.8978,3.4111,3.458,-4.0591,-5.9433},
        {3.7513,4.9318,3.3703,3.3987,-4.0719,-5.9228},
        {3.7846,4.9652,3.3294,3.3397,-4.0939,-5.9084},
        {3.8175,4.998,3.2883,3.2807,-4.1057,-5.8885},
        {3.8499,5.0302,3.2471,3.2219,-4.1265,-5.8833},
        {3.882,5.0618,3.2057,3.1634,-4.1392,-5.8545},
        {3.9136,5.0929,3.1641,3.1049,-4.1544,-5.8471},
        {3.9449,5.1233,3.1225,3.0466,-4.1712,-5.8301},
        {3.9757,5.1532,3.0805,2.9885,-4.1873,-5.8053},
        {4.0061,5.1825,3.0386,2.9304,-4.1976,-5.8113},
        {4.036,5.2112,2.9964,2.8727,-4.2221,-5.7781},
        {4.0656,5.2394,2.954,2.8151,-4.2366,-5.7545},
        {4.0947,5.267,2.9116,2.7575,-4.2413,-5.7666},
        {4.1234,5.294,2.8689,2.7002,-4.2729,-5.7259},
        {4.1516,5.3204,2.826,2.6431,-4.2835,-5.7146},
        {4.1795,5.3463,2.783,2.5861,-4.3008,-5.6966},
        {4.2069,5.3716,2.7398,2.5292,-4.3186,-5.6781},
        {4.2339,5.3963,2.6965,2.4725,-4.3303,-5.675},
        {4.2604,5.4205,2.6529,2.4161,-4.3586,-5.6462},
        {4.2865,5.4441,2.6091,2.36,-4.3865,-5.608},
        {4.3121,5.4671,2.5652,2.3039,-4.3874,-5.6158},
        {4.3373,5.4896,2.5209,2.2482,-4.4297,-5.5628},
        {4.3621,5.5115,2.4767,2.1923,-4.4191,-5.5923},
        {4.3864,5.5329,2.4318,2.1373,-4.4901,-5.5003},
        {4.4103,5.5537,2.387,2.082,-4.475,-5.5243},
        {4.4337,5.574,2.342,2.027,-4.5023,-5.5066},
        {4.4566,5.5937,2.2965,1.9726,-4.5569,-5.4404},
        {4.4791,5.6129,2.2508,1.9183,-4.568,-5.4279},
        {4.5012,5.6315,2.2048,1.8643,-4.5963,-5.3981},
        {4.5228,5.6496,2.1586,1.8103,-4.6108,-5.3934},
        {4.5439,5.6672,2.1121,1.7569,-4.66,-5.343},
        {4.5646,5.6842,2.0652,1.7038,-4.6921,-5.3097},
        {4.5847,5.7007,2.0179,1.6511,-4.7253,-5.2751},
        {4.6044,5.7167,1.9704,1.5987,-4.7597,-5.2391},
        {4.6237,5.7322,1.9224,1.5467,-4.7953,-5.2018},
        {4.6424,5.7472,1.874,1.495,-4.832,-5.1631},
        {4.6607,5.7616,1.8255,1.4435,-4.8504,-5.1561},
        {4.6784,5.7755,1.7765,1.3926,-4.9136,-5.0916},
        {4.6957,5.7889,1.7267,1.3424,-4.9746,-5.0148},
        {4.7125,5.8019,1.677,1.2921,-4.9688,-5.0323},
        {4.7288,5.8143,1.6265,1.2424,-5.0372,-4.962},
        {4.7445,5.8262,1.5761,1.193,-5.0579,-4.9548},
        {4.7598,5.8377,1.5242,1.1448,-5.1753,-4.8042},
        {4.7745,5.8486,1.473,1.0959,-5.1158,-4.8926},
        {4.7887,5.8591,1.4209,1.048,-5.2195,-4.7875},
        {4.8024,5.8691,1.3683,1.0007,-5.2653,-4.7402},
        {4.8155,5.8786,1.3149,0.9542,-5.3353,-4.6497},
        {4.8281,5.8877,1.2616,0.9074,-5.3244,-4.6757},
        {4.8402,5.8964,1.2075,0.8614,-5.4021,-4.5954},
        {4.8517,5.9045,1.1534,0.8155,-5.4225,-4.5934},
        {4.8627,5.9122,1.0982,0.7709,-5.5269,-4.4662},
        {4.8732,5.9195,1.0427,0.7263,-5.5365,-4.4527},
        {4.883,5.9263,0.9872,0.6818,-5.5546,-4.4549},
        {4.8924,5.9327,0.9304,0.6384,-5.6574,-4.3245},
        {4.9011,5.9386,0.8745,0.5943,-5.6133,-4.4189},
        {4.9093,5.9441,0.8166,0.5523,-5.776,-4.199},
        {4.9169,5.9493,0.7594,0.5094,-5.7151,-4.2837},
        {4.9239,5.9539,0.7019,0.4669,-5.7669,-4.2644},
        {4.9303,5.9582,0.6429,0.426,-5.8837,-4.0748},
        {4.9362,5.962,0.585,0.3837,-5.7961,-4.2326},
        {4.9414,5.9654,0.5257,0.3431,-5.9244,-4.0625},
        {4.9461,5.9685,0.4663,0.3022,-5.9095,-4.0685},
        {4.9502,5.9711,0.4072,0.2611,-5.9199,-4.108},
        {4.9536,5.9733,0.3478,0.2209,-5.9889,-4.0515},
        {4.9565,5.9751,0.2867,0.1816,-6.0077,-3.8695},
        {4.9588,5.9765,0.2278,0.1402,-5.9473,-4.1809},
        {4.9605,5.9775,0.1668,0.1014,-6.0691,-3.8644},
        {4.9616,5.9782,0.1045,0.0608,-5.9106,-3.853},
        {4.962,5.9784,0.0391,0.0171,-5.8084,-3.8748}
    };

void Auton::skills(){
    
    liftController->setTarget(100);

    // moveTime({-0.1, -0.1}, 250_ms);
    
    mogoClamp.set(true); pros::delay(250); mogo.set(true);
    roller.moveVoltage(12000);

    profiler->setTarget(Skills::path0);
    pros::delay(1000);
    liftController->setTarget(0);
    profiler->waitUntilSettled();
    // ! moveTime({0.1, 0.1}, 250_ms); 
    claw.set(true);
    
    profiler->setTarget(Skills::path1);
    liftController->setTarget(710);
    profiler->waitUntilSettled();
    // jerk around
    moveTime({-0.5, 0.5}, 500_ms);
    turnToAngle(90_deg);
    claw.set(false); pros::delay(500);
    
    moveDistance(-7_in);
    liftController->setTarget(0);
    turnToAngle(0_deg);
    mogo.set(false); mogoClamp.set(false);

    moveDistance(1_ft);
    turnToAngle(180_deg);
    moveTime({0.6, 0.6}, 800_ms);
    claw.set(true); pros::delay(250);
    liftController->setTarget(710); 
    moveTime({-0.6, -0.6}, 600_ms);
    liftController->waitUntilSettled();
    turnToAngle(90_deg);
    moveDistance(1.5_ft, 1_s);
    claw.set(false);
    moveDistance(-6.5_ft, 3_s);

    moveDistance(2.5_ft);
    turnToAngle(225_deg);
    moveDistance(4.5_ft);
    turnToAngle(270_deg);

    moveTime({0.5, 0.5}, 1_s);
    // moveDistance(-1_ft);
    profiler->setTarget(-10_in);
    profiler->waitUntilSettled();
    turnToAngle(180_deg);
    moveTime({0.5, 0.5}, 1_s);
    // moveDistance(-4_in);
    profiler->setTarget(-4_in);
    profiler->waitUntilSettled();
    turnToAngle(270_deg);

    moveTime({-0.5, -0.5}, 650_ms); pros::delay(250);
    mogoClamp.set(true); pros::delay(250); mogo.set(true);
    profiler->setTarget(Skills::path2);
    profiler->waitUntilSettled();

    liftController->setTarget(0);
    turnToAngle(90_deg);
    moveDistance(1_ft);
    // liftController->setTarget(0);
    // moveDistance(-1_ft);
    // moveDistance(1_ft); pros::delay(500);
    moveTime({0.25, 0.25}, 600_ms); 
    claw.set(true); pros::delay(250);

    liftController->setTarget(710);
    turnToAngle(47.5_deg); 
    // turnToAngle(-35_deg);
    moveDistance(5_ft, 2_s);
    turnToAngle(90_deg);
    // turnToAngle(0_deg);
    moveDistance(1_ft, 1000_ms);
    claw.set(false); pros::delay(250);

    moveDistance(-2_ft);
    mogo.set(false); mogoClamp.set(false);
    liftController->setTarget(0);
    moveDistance(10_in);
    turnToAngle(270_deg);
    // turnToAngle(180_deg);
    liftController->waitUntilSettled();
    // moveDistance(1_ft);
    moveTime({0.5, 0.5}, 850_ms);
    claw.set(true); pros::delay(250);
    liftController->setTarget(710);
    turnToAngle(100_deg);
    // turnToAngle(0_deg);
    moveDistance(4_ft, 2000_ms);
    claw.set(false); pros::delay(250);

    moveDistance(-1_ft);
    turnToAngle(0_deg);
    // turnToAngle(-90_deg);
    // liftController->setTarget(0);
    moveDistance(4_ft, 2_s);
    // turnToAngle(55_deg);
    // turnToAngle(-45_deg);
    // moveDistance(2_ft, 1.5_s);
    turnToAngle(90_deg);

    moveTime({0.5, 0.5}, 1.5_s);
    profiler->setTarget(-4_in);
    profiler->waitUntilSettled();
    turnToAngle(0_deg);
    moveTime({0.5, 0.5}, 1.5_s);
    profiler->setTarget(-4_in);
    profiler->waitUntilSettled();
    turnToAngle(-90_deg);

    liftController->setTarget(0);
    liftController->waitUntilSettled();
    pros::delay(1200);

    profiler->setTarget(8_ft);
    pros::delay(800);
    claw.set(true);
    pros::delay(250);
    liftController->setTarget(710);
    profiler->waitUntilSettled();

    // moveTimeHeadingCorrect(-0.5, 0.5_s);
    // mogoClamp.set(true); pros::delay(250); mogo.set(true);

    // profiler->setTarget(Skills::path3);
    // turnToAngle(-90_deg);
    // moveDistance(7_ft, 2.5_s);
    
    // profiler->setTarget(-4_in);
    // profiler->waitUntilSettled();
    // turnToAngle(0_deg);
    // moveTime({0.5, 0.5}, 1_s);
    // profiler->setTarget(-12_in);
    // profiler->waitUntilSettled();

    // liftController->setTarget(710);
    // // moveDistance(-1_ft);
    // turnToAngle(-90_deg);
    // // turnToAngle(180_deg); 
    // // pros::delay(250);
    // moveTime({-0.5, -0.5}, 1.5_s); pros::delay(500);
    // // moveDistance(2.5_ft); 
    // profiler->setTarget(2.25_ft);
    // profiler->waitUntilSettled();
    // pros::delay(250);
    // turnToAngle(0_deg);
    // // turnToAngle(-90_deg);

    // // moveDistance(7_ft); 
    // profiler->setTarget(7_ft);
    // profiler->waitUntilSettled();
    // turnToAngle(-90_deg);
    // // pros::delay(500);
    // // moveTimeHeadingCorrect(-0.5, 750_ms);
    // // turnToAngle(180_deg);
    // // turnToAngle(90_deg); 
    // pros::delay(250);
    // moveTime({-0.5, -0.5}, 1.5_s);
    // mogoClamp.set(true); pros::delay(250); mogo.set(true);

    /*
    turnToAngle(270_deg);
    moveDistance(1.5_ft);
    liftController->setTarget(0);
    moveDistance(-1_ft);
    moveDistance(30_in);
    claw.set(true);
    liftController->setTarget(100);
    turnToAngle(225_deg);

    moveDistance(8_ft, 3.5_s);
    claw.set(false);
    moveDistance(-2_ft);
    liftController->setTarget(710);
    turnToAngle(270_deg);

    moveDistance(3_ft, 1_s);
    moveDistance(-10_in);
    turnToAngle(180_deg);
    moveTime({300, 300}, 800_ms);
    moveDistance(-7_in);
    */

    // moveDistance(3_ft);
    // moveTime({0.5, 0.5}, 1000_ms);
    // claw.set(true); pros::delay(250);
    // liftController->setTarget(710);
    // mogo.set(false); mogoClamp.set(false);

    // Hard reset
    // moveDistance(-6_in);
    // liftController->waitUntilSettled();
    // moveTime({200, 200}, 1000_ms); pros::delay(250);
    // moveDistance(-6_in);
    // turnToAngle(90_deg);
    // moveTime({200, 200}, 1200_ms); pros::delay(250);
    // moveDistance(-6_in);
    // turnToAngle(45_deg);

    // mogo.set(false); mogoClamp.set(false);
    // moveDistance(-12_ft);

    // profiler->setTarget(Skills::path2);
    // profiler->waitUntilSettled();
    // turnToAngle(45_deg);
    // moveDistance(-8_ft);
    // turnToAngle(45_deg);
    // // moveTime({-400, -400}, 500_ms);

    // liftController->setTarget(50);
    // moveDistance(22_in);
    // turnToAngle(0_deg);

    // claw.set(false); 
    // moveTime({-0.5, -0.5}, 600_ms); pros::delay(300);
    // mogoClamp.set(true); pros::delay(250); mogo.set(true);

    // profiler->setTarget(Skills::path3);
    // liftController->setTarget(0);
    // profiler->waitUntilSettled();
    // turnToAngle(90_deg);
}


