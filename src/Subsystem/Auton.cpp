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
    moveDistance(-3.5_ft);

    wings.set(false);
    pros::delay(250);
    moveDistance(4.25_ft);

    wings.set(true); pros::delay(250); wings.set(false); pros::delay(250);
}

void Auton::left(){
    
}

void Auton::right(){
    wingGrab();
    
    moveDistance(-2_ft);
    turnToAngle(90_deg);

    moveDistance(-4_ft);
    moveTime({-0.5, -0.5}, 250_ms);
    pros::delay(250);
    mogoClamp.set(true); pros::delay(250); mogo.set(true);

    //followPathCustom(AWP::p0Left);
    claw.set(true);
}

void Auton::awp(){
    
}


void Auton::skills(){
    
    liftController->setTarget(100);

    // // moveTime({-0.1, -0.1}, 250_ms);

    mogoClamp.set(true); pros::delay(250); mogo.set(true);
    roller.moveVoltage(12000);

    profiler->setTarget(Skills::path0);
    pros::delay(1000);
    liftController->setTarget(0);
    profiler->waitUntilSettled();
    moveTime({0.1, 0.1}, 250_ms);
    claw.set(true);

    profiler->setTarget(Skills::path1);
    liftController->setTarget(710);
    profiler->waitUntilSettled();
    // jerk around
    moveTime({-0.5, 0.5}, 400_ms);
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
    moveTime({-0.8, -0.8}, 390_ms);
    liftController->waitUntilSettled();
    turnToAngle(90_deg);
    moveDistance(1.5_ft, 1_s);
    claw.set(false);
    moveDistance(-5_ft, 4_s);

    moveDistance(1.25_ft);
    turnToAngle(225_deg);
    moveDistance(4_ft);
    turnToAngle(270_deg);

    moveTime({0.5, 0.5}, 1_s);
    moveDistance(-1_ft);
    turnToAngle(180_deg);
    moveTime({0.5, 0.5}, 1_s);
    moveDistance(-4_in);
    turnToAngle(270_deg);

    moveTime({-0.5, -0.5}, 600_ms); pros::delay(250);
    mogoClamp.set(true); pros::delay(250); mogo.set(true);
    profiler->setTarget(Skills::path2);
    profiler->waitUntilSettled();

    turnToAngle(90_deg);
    moveDistance(1_ft);
    liftController->setTarget(0);
    moveDistance(-1_ft);
    moveDistance(1_ft); pros::delay(500);
    moveTime({0.2, 0.2}, 400_ms); 
    claw.set(true); pros::delay(250);

    liftController->setTarget(710);
    turnToAngle(45_deg); 
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
    turnToAngle(90_deg);
    // turnToAngle(0_deg);
    moveDistance(3_ft, 1500_ms);
    claw.set(false); pros::delay(250);

    moveDistance(-1_ft);
    turnToAngle(0_deg);
    // turnToAngle(-90_deg);
    liftController->setTarget(0);
    moveDistance(-4.5_ft);
    turnToAngle(50_deg);
    // turnToAngle(-45_deg);
    moveDistance(2.5_ft);
    claw.set(true);

    liftController->setTarget(710);
    moveDistance(-1_ft);
    turnToAngle(-90_deg);
    // turnToAngle(180_deg); 
    pros::delay(250);
    moveTime({-0.5, -0.5}, 1.5_s); pros::delay(500);
    moveDistance(2.5_ft); pros::delay(250);
    turnToAngle(0_deg);
    // turnToAngle(-90_deg);

    moveDistance(7_ft); pros::delay(500);
    moveTimeHeadingCorrect(-0.5, 750_ms);
    turnToAngle(180_deg);
    // turnToAngle(90_deg); 
    pros::delay(250);
    moveTime({-0.5, -0.5}, 1.5_s);
    mogoClamp.set(true); pros::delay(250); mogo.set(true);

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


