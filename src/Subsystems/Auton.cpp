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


