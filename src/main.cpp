#include "main.h"

Trajectory path = {
        {0,0,0,0,0,0},
        {0.0003,0.0004,0.0247,0.0374,2.3212,3.5121},
        {0.0008,0.0013,0.0577,0.0975,3.3838,6.1699},
        {0.0017,0.0029,0.0899,0.1626,3.3118,6.6936},
        {0.0029,0.0052,0.1223,0.2287,3.2546,6.6262},
        {0.0045,0.0082,0.1547,0.2965,3.2167,6.7332},
        {0.0063,0.0118,0.1866,0.3647,3.2014,6.8498},
        {0.0085,0.0161,0.2193,0.4315,3.2948,6.7323},
        {0.011,0.0211,0.253,0.4974,3.3671,6.5879},
        {0.0139,0.0268,0.2864,0.5643,3.3182,6.6492},
        {0.0171,0.033,0.3185,0.6321,3.237,6.833},
        {0.0206,0.04,0.354,0.6963,3.5495,6.4119},
        {0.0245,0.0476,0.3877,0.7627,3.3652,6.6428},
        {0.0287,0.0559,0.4225,0.8277,3.4873,6.5162},
        {0.0333,0.0649,0.4586,0.8918,3.5923,6.3736},
        {0.0383,0.0744,0.4929,0.9577,3.4356,6.5984},
        {0.0435,0.0846,0.5299,1.0205,3.7054,6.2894},
        {0.0492,0.0955,0.5667,1.0838,3.6759,6.3171},
        {0.0552,0.1069,0.6033,1.1471,3.6651,6.3535},
        {0.0617,0.119,0.6418,1.2084,3.8597,6.1277},
        {0.0685,0.1317,0.6803,1.27,3.8371,6.1494},
        {0.0756,0.145,0.7178,1.3324,3.7681,6.2648},
        {0.0832,0.1589,0.7596,1.3906,4.1622,5.7965},
        {0.0912,0.1735,0.7977,1.4527,3.8105,6.2154},
        {0.0996,0.1885,0.8392,1.5111,4.1524,5.8472},
        {0.1084,0.2042,0.8805,1.5697,4.1354,5.8618},
        {0.1176,0.2205,0.9224,1.6277,4.1926,5.8025},
        {0.1273,0.2374,0.9643,1.6859,4.1899,5.8221},
        {0.1373,0.2548,1.008,1.742,4.3758,5.6146},
        {0.1479,0.2728,1.0517,1.7984,4.3607,5.6284},
        {0.1588,0.2913,1.0946,1.8555,4.3005,5.7216},
        {0.1702,0.3104,1.1407,1.9094,4.6032,5.3815},
        {0.1821,0.3301,1.1854,1.9648,4.4644,5.5357},
        {0.1944,0.3502,1.2306,2.0195,4.5261,5.4879},
        {0.2072,0.371,1.2781,2.072,4.7479,5.232},
        {0.2204,0.3923,1.3238,2.1265,4.5601,5.4496},
        {0.2341,0.414,1.371,2.1792,4.7321,5.275},
        {0.2483,0.4364,1.4193,2.2308,4.8268,5.1636},
        {0.263,0.4592,1.4669,2.2833,4.7561,5.2474},
        {0.2781,0.4825,1.5154,2.3347,4.8562,5.1453},
        {0.2938,0.5064,1.5643,2.3858,4.8937,5.1061},
        {0.3099,0.5307,1.6136,2.4365,4.9293,5.0689},
        {0.3265,0.5556,1.6633,2.4868,4.963,5.0338},
        {0.3436,0.581,1.7127,2.5374,4.9481,5.0603},
        {0.3613,0.6068,1.7635,2.5865,5.0792,4.9147},
        {0.3794,0.6332,1.8141,2.636,5.0522,4.9406},
        {0.3981,0.6601,1.8639,2.6862,4.9901,5.0265},
        {0.4172,0.6874,1.916,2.734,5.2062,4.7841},
        {0.4369,0.7152,1.9668,2.7832,5.0822,4.9193},
        {0.4571,0.7435,2.0183,2.8317,5.1536,4.8466},
        {0.4778,0.7723,2.0701,2.88,5.1723,4.8268},
        {0.499,0.8016,2.122,2.9281,5.1894,4.8088},
        {0.5208,0.8314,2.1741,2.976,5.2049,4.7923},
        {0.543,0.8617,2.2259,3.0243,5.1803,4.8273},
        {0.5658,0.8924,2.2786,3.0715,5.2769,4.7184},
        {0.5891,0.9236,2.3307,3.1195,5.2053,4.8004},
        {0.6129,0.9552,2.3836,3.1665,5.296,4.6978},
        {0.6373,0.9874,2.4359,3.2142,5.2249,4.7791},
        {0.6622,1.02,2.4886,3.2615,5.2752,4.7279},
        {0.6876,1.0531,2.5418,3.3083,5.3153,4.6766},
        {0.7135,1.0866,2.5942,3.3559,5.2451,4.7567},
        {0.74,1.1207,2.6472,3.403,5.2899,4.7114},
        {0.767,1.1552,2.7001,3.4501,5.2927,4.708},
        {0.7945,1.1901,2.753,3.4971,5.2946,4.7055},
        {0.8226,1.2256,2.806,3.5442,5.2956,4.704},
        {0.8512,1.2615,2.8589,3.5912,5.2959,4.7034},
        {0.8803,1.2978,2.9115,3.6386,5.2653,4.7433},
        {0.9099,1.3347,2.9652,3.6849,5.3594,4.6293},
        {0.9402,1.3721,3.0178,3.7323,5.2567,4.7415},
        {0.9708,1.4098,3.0704,3.7798,5.2612,4.7463},
        {1.0021,1.4481,3.1236,3.8266,5.3205,4.6772},
        {1.0338,1.4868,3.1761,3.874,5.2551,4.7517},
        {1.0661,1.5261,3.2295,3.9206,5.338,4.65},
        {1.0989,1.5657,3.2816,3.9685,5.2147,4.7917},
        {1.1323,1.6059,3.3347,4.0155,5.3001,4.6969},
        {1.1661,1.6465,3.387,4.0631,5.237,4.769},
        {1.2005,1.6876,3.4398,4.1102,5.2873,4.7096},
        {1.2355,1.7292,3.4924,4.1577,5.2498,4.7471},
        {1.2709,1.7712,3.5445,4.2055,5.2187,4.787},
        {1.3069,1.8137,3.5972,4.2528,5.2651,4.7318},
        {1.3434,1.8568,3.6495,4.3006,5.2281,4.769},
        {1.3804,1.9003,3.7017,4.3484,5.2202,4.777},
        {1.418,1.9443,3.7536,4.3965,5.1893,4.8166},
        {1.456,1.9886,3.8056,4.4444,5.2087,4.7971},
        {1.4946,2.0336,3.8581,4.4919,5.2437,4.7454},
        {1.5337,2.079,3.9095,4.5406,5.1367,4.8694},
        {1.5733,2.1249,3.9615,4.5886,5.2025,4.7955},
        {1.6134,2.1713,4.0132,4.6369,5.1661,4.8321},
        {1.654,2.2181,4.0645,4.6856,5.1353,4.8714},
        {1.6952,2.2655,4.1164,4.7336,5.1918,4.7989},
        {1.7369,2.3133,4.1673,4.7828,5.0897,4.9175},
        {1.7791,2.3616,4.2188,4.8313,5.1491,4.8503},
        {1.8218,2.4104,4.2702,4.8799,5.1327,4.8593},
        {1.865,2.4597,4.3207,4.9294,5.0575,4.9506},
        {1.9087,2.5094,4.3718,4.9782,5.1135,4.8871},
        {1.953,2.5598,4.4228,5.0272,5.0963,4.8971},
        {1.9976,2.6105,4.473,5.0771,5.022,4.9873},
        {2.0429,2.6617,4.5239,5.1261,5.0935,4.9009},
        {2.0887,2.7135,4.5743,5.1757,5.0336,4.9615},
        {2.1349,2.7657,4.6241,5.226,4.9827,5.028},
        {2.1817,2.8185,4.6748,5.2752,5.0688,4.9201},
        {2.2289,2.8718,4.7243,5.3258,4.9499,5.0545},
        {2.2766,2.9255,4.7741,5.376,4.9791,5.0258},
        {2.3248,2.9798,4.8239,5.4261,4.981,5.0173},
        {2.3736,3.0346,4.8735,5.4765,4.9601,5.0319},
        {2.4228,3.0899,4.9224,5.5277,4.8854,5.1217},
        {2.4725,3.1456,4.9717,5.5784,4.9284,5.0723},
        {2.5227,3.2019,5.0205,5.6295,4.8878,5.1137},
        {2.5734,3.2587,5.0694,5.6806,4.8855,5.1099},
        {2.6246,3.3161,5.1178,5.7322,4.8435,5.153},
        {2.6763,3.3739,5.1659,5.7842,4.8041,5.2002},
        {2.7284,3.4322,5.2139,5.8362,4.8022,5.203},
        {2.781,3.4911,5.262,5.888,4.813,5.1798},
        {2.8338,3.5502,5.276,5.9058,1.4043,1.7737},
        {2.8861,3.6088,5.2288,5.8559,-4.7155,-4.9759},
        {2.9379,3.6668,5.181,5.8038,-4.7869,-5.2193},
        {2.9892,3.7243,5.1335,5.7512,-4.7474,-5.2531},
        {3.0401,3.7813,5.0856,5.6992,-4.7937,-5.2077},
        {3.0904,3.8378,5.0377,5.6472,-4.7935,-5.2018},
        {3.1403,3.8937,4.9891,5.5958,-4.8624,-5.1407},
        {3.1897,3.9492,4.9406,5.5442,-4.8392,-5.1577},
        {3.2387,4.0041,4.8918,5.493,-4.8819,-5.1157},
        {3.2871,4.0585,4.8425,5.4422,-4.9278,-5.0776},
        {3.335,4.1124,4.7935,5.3913,-4.9019,-5.0971},
        {3.3825,4.1658,4.7441,5.3407,-4.9428,-5.0569},
        {3.4294,4.2187,4.6945,5.2903,-4.9619,-5.0384},
        {3.4758,4.2711,4.6447,5.2401,-4.9805,-5.0204},
        {3.5218,4.3231,4.5949,5.1899,-4.9729,-5.0212},
        {3.5673,4.3745,4.5445,5.1402,-5.0382,-4.9638},
        {3.6122,4.4254,4.4942,5.0905,-5.0339,-4.9687},
        {3.6566,4.4758,4.4437,5.0411,-5.051,-4.9522},
        {3.7006,4.5257,4.3933,4.9915,-5.041,-4.9551},
        {3.744,4.5751,4.3425,4.9423,-5.0797,-4.9167},
        {3.7869,4.624,4.2913,4.8935,-5.1232,-4.8814},
        {3.8293,4.6725,4.2404,4.8444,-5.089,-4.9083},
        {3.8712,4.7204,4.1888,4.7959,-5.1556,-4.8499},
        {3.9126,4.7679,4.1379,4.7469,-5.0919,-4.8983},
        {3.9535,4.8149,4.0858,4.699,-5.211,-4.7952},
        {3.9938,4.8614,4.0343,4.6505,-5.1503,-4.8484},
        {4.0336,4.9074,3.9821,4.6027,-5.2187,-4.7882},
        {4.0729,4.953,3.9306,4.5542,-5.1506,-4.8407},
        {4.1117,4.9981,3.8781,4.5066,-5.2445,-4.7549},
        {4.1499,5.0426,3.8255,4.4593,-5.2651,-4.7427},
        {4.1877,5.0867,3.7736,4.4113,-5.1934,-4.7983},
        {4.2249,5.1304,3.7206,4.3641,-5.2905,-4.7095},
        {4.2616,5.1735,3.6676,4.3172,-5.3112,-4.6973},
        {4.2977,5.2163,3.6152,4.2696,-5.2355,-4.7565},
        {4.3333,5.2585,3.5618,4.223,-5.3362,-4.6642},
        {4.3684,5.3003,3.5086,4.1762,-5.3239,-4.6767},
        {4.403,5.3416,3.4552,4.1296,-5.3386,-4.662},
        {4.437,5.3824,3.4016,4.0831,-5.3533,-4.6473},
        {4.4705,5.4228,3.348,4.0368,-5.3679,-4.6327},
        {4.5034,5.4626,3.2942,3.9906,-5.3825,-4.6181},
        {4.5358,5.5021,3.2402,3.9446,-5.397,-4.6036},
        {4.5677,5.5411,3.1864,3.8984,-5.3748,-4.6169},
        {4.599,5.5796,3.1315,3.8533,-5.4941,-4.5152},
        {4.6298,5.6177,3.0778,3.807,-5.3702,-4.6211},
        {4.66,5.6553,3.0226,3.7622,-5.5248,-4.4843},
        {4.6897,5.6925,2.9686,3.7162,-5.3953,-4.5955},
        {4.7188,5.7292,2.9131,3.6717,-5.5549,-4.4538},
        {4.7474,5.7655,2.8588,3.6259,-5.4193,-4.5708},
        {4.7754,5.8013,2.803,3.5817,-5.5841,-4.4242},
        {4.8029,5.8366,2.7482,3.5366,-5.4843,-4.5144},
        {4.8299,5.8715,2.6929,3.4919,-5.5321,-4.4662},
        {4.8562,5.906,2.6374,3.4474,-5.5437,-4.4541},
        {4.882,5.94,2.5815,3.4034,-5.6001,-4.4068},
        {4.9073,5.9737,2.5266,3.3582,-5.4802,-4.5069},
        {4.932,6.0068,2.4696,3.3152,-5.7091,-4.3064},
        {4.9562,6.0395,2.415,3.2699,-5.4542,-4.5314},
        {4.9798,6.0718,2.3581,3.2266,-5.6819,-4.3226},
        {5.0028,6.1036,2.3021,3.1827,-5.606,-4.3979},
        {5.0252,6.135,2.2465,3.1383,-5.5601,-4.4329},
        {5.0471,6.1659,2.1894,3.0954,-5.7133,-4.2992},
        {5.0684,6.1964,2.1342,3.0507,-5.5194,-4.4719},
        {5.0892,6.2265,2.0776,3.0073,-5.6664,-4.334},
        {5.1094,6.2561,2.0214,2.9635,-5.6192,-4.3802},
        {5.1291,6.2853,1.9652,2.9197,-5.6164,-4.3818},
        {5.1482,6.3141,1.909,2.8758,-5.6115,-4.3855},
        {5.1667,6.3424,1.8524,2.8324,-5.6646,-4.3419},
        {5.1847,6.3703,1.797,2.7879,-5.5418,-4.4525},
        {5.2021,6.3977,1.7405,2.7443,-5.6445,-4.3593},
        {5.2189,6.4247,1.6848,2.7,-5.5751,-4.4273},
        {5.2352,6.4513,1.6298,2.655,-5.4897,-4.4996},
        {5.251,6.4774,1.5733,2.6115,-5.6588,-4.3517},
        {5.2662,6.5031,1.5188,2.566,-5.4474,-4.5498},
        {5.2808,6.5283,1.464,2.5208,-5.4758,-4.5193},
        {5.2949,6.553,1.4089,2.4759,-5.5135,-4.4915},
        {5.3084,6.5773,1.3549,2.43,-5.412,-4.5911},
        {5.3215,6.6012,1.3019,2.383,-5.2914,-4.6969},
        {5.3339,6.6245,1.2473,2.3376,-5.463,-4.5481},
        {5.3459,6.6475,1.1961,2.2888,-5.1154,-4.8675},
        {5.3573,6.6698,1.1418,2.243,-5.4366,-4.5829},
        {5.3682,6.6918,1.0918,2.193,-4.9935,-4.9969},
        {5.3786,6.7132,1.0403,2.1445,-5.1506,-4.8503},
        {5.3885,6.7342,0.9903,2.0945,-4.9996,-4.9983},
        {5.398,6.7546,0.9411,2.0437,-4.9159,-5.0786},
        {5.4069,6.7746,0.8919,1.9928,-4.9176,-5.0883},
        {5.4153,6.794,0.8445,1.9402,-4.744,-5.259},
        {5.4233,6.8128,0.7981,1.8867,-4.6429,-5.3566},
        {5.4308,6.8311,0.7527,1.8321,-4.5361,-5.4596},
        {5.4379,6.8489,0.7075,1.7773,-4.5236,-5.4849},
        {5.4445,6.8661,0.6653,1.7196,-4.2193,-5.7683},
        {5.4508,6.8827,0.6224,1.6624,-4.2875,-5.7128},
        {5.4566,6.8988,0.5807,1.6042,-4.1785,-5.8365},
        {5.462,6.9142,0.5432,1.5417,-3.7432,-6.2296},
        {5.467,6.929,0.502,1.4828,-4.1235,-5.9031},
        {5.4717,6.9432,0.4672,1.4177,-3.482,-6.5002},
        {5.476,6.9568,0.4306,1.3541,-3.6497,-6.3476},
        {5.48,6.9696,0.3953,1.2893,-3.5307,-6.4852},
        {5.4836,6.9819,0.3635,1.2212,-3.1761,-6.8119},
        {5.4869,6.9934,0.331,1.1537,-3.26,-6.7475},
        {5.4899,7.0042,0.3008,1.084,-3.0234,-6.9802},
        {5.4927,7.0144,0.273,1.0117,-2.7674,-7.2002},
        {5.4951,7.0238,0.243,0.9414,-2.994,-7.0273},
        {5.4972,7.0325,0.2165,0.868,-2.6609,-7.3604},
        {5.4992,7.0404,0.1924,0.7923,-2.4128,-7.5681},
        {5.5008,7.0475,0.167,0.7179,-2.5453,-7.4682},
        {5.5023,7.054,0.1449,0.6398,-2.1943,-7.7668},
        {5.5035,7.0596,0.1213,0.5628,-2.3443,-7.6513},
        {5.5045,7.0645,0.0985,0.4857,-2.2983,-7.7587},
        {5.5053,7.0685,0.0789,0.4058,-1.966,-8.0354},
        {5.5059,7.0718,0.0601,0.324,-1.8494,-8.0352},
        {5.5063,7.0743,0.0378,0.245,-2.2165,-7.8271},
        {5.5064,7.0759,0.0181,0.1651,-2.0001,-8.134},
        {5.5065,7.0768,0.0022,0.0648,-1.1849,-7.4766}
    };

void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		pros::lcd::set_text(2, "I was pressed!");
	} else {
		pros::lcd::clear_line(2);
	}
}

void initialize(){
	pros::lcd::initialize();
    
    pros::vision_signature_s_t RED_SIG = pros::Vision::signature_from_utility(1, 5685, 8135, 6910, -1963, -1705, -1834, 4.000, 0);
    // pros::vision_signature_s_t BLUE_SIG = pros::Vision::signature_from_utility()

    vision_sensor.set_signature(1, &RED_SIG);

    pros::lcd::set_text(2, "imu calibrating..............");
    imu.calibrate();
    pros::delay(2000);
    pros::lcd::set_text(2, "imu calibrated");

    // Auton::add([](){}, "Do Nothing");
    // Auton::add(Auton::skills, "Skills");
    // Auton::add(Auton::right, "Match");

    // pros::lcd::register_btn0_cb([](){lift.tarePosition();});
    // pros::lcd::register_btn1_cb([](){Auton::switchAuton();});
    // pros::lcd::register_btn2_cb([](){Auton::select();});
    /*
    for(int i = 0; i < 300; i++){
        std::string message = "Selected Autonomous: " + Auton::getName();
        pros::lcd::print(0, message.c_str());
        pros::delay(10);
    }
    */
    
}

void disabled(){}

void competition_initialize(){

}

void autonomous(){
    //Auton auton = Auton();
    //auton.init();
    //auton.wingGrab();

    //std::unique_ptr<Auton> auton = std::move(std::make_unique<Auton>());
    //auton->init();
    //auton->right();
    //auton.reset();
    // Auton::execute();
    
}

void opcontrol(){
    Auton a = Auton();
    a.init();
    a.skills();

    while(true) {
        pros::delay(10);
    }

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
	//Gif gif("/usd/gif/crab-rave.gif", lv_scr_act());

    int liftPos = 0;
    bool clampState = false, prevClampState = false;
    bool mogoState = false, prevMogoState = false;

    leftDrive.setBrakeMode(AbstractMotor::brakeMode::coast);
    rightDrive.setBrakeMode(AbstractMotor::brakeMode::coast);
    lift.setBrakeMode(AbstractMotor::brakeMode::hold);
    
    while(true){
        double power = master.getAnalog(ControllerAnalog::leftY) * (abs(master.getAnalog(ControllerAnalog::leftY)) >= DEADBAND);
        double curvature = master.getAnalog(ControllerAnalog::rightX) * (abs(master.getAnalog(ControllerAnalog::rightX)) >= DEADBAND);
        curvatureDrive(power, curvature, power == 0);

        //liftPos += LIFT_STEP * master.getDigital(ControllerDigital::L1); 
        //liftPos -= LIFT_STEP * master.getDigital(ControllerDigital::L2);
        //liftController->setTarget(liftPos = std::max(std::min(liftPos, MAX_LIFT_HEIGHT), 0));

        roller.moveVoltage(12000*((master.getDigital(ControllerDigital::L1) && master.getDigital(ControllerDigital::L2))-master.getDigital(ControllerDigital::A)));
        /*
        if(master.getDigital(ControllerDigital::L1) && master.getDigital(ControllerDigital::L2)) {
            lift.moveVelocity(0);
        } else if(master.getDigital(ControllerDigital::L1)) {
            lift.moveVoltage(12000);
        } else if (master.getDigital(ControllerDigital::L2)) {
            lift.moveVelocity(-12000);
        } else {
            lift.moveVelocity(0);
        }
        */

        claw.set(master.getDigital(ControllerDigital::R1));
        wings.set(master.getDigital(ControllerDigital::Y));

        mogoState = master.getDigital(ControllerDigital::X);
        if(!prevMogoState && mogoState){
            mogo.toggle();
        }
        prevMogoState = mogoState;

        clampState = master.getDigital(ControllerDigital::R2);
        if(!prevClampState && clampState){
            mogoClamp.toggle();
        }
        prevClampState = clampState;

        pros::delay(10);
    }
}
