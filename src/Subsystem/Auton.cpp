#include "main.h"

pros::Mutex Auton::lock;
std::vector<std::function<void()>> Auton::auton;
std::vector<std::string> Auton::name;
int Auton::index = 0;


void Auton::add(std::function<void()> iAutonomous, std::string iName){
    auton.push_back(iAutonomous);
    name.push_back(iName);
}

void Auton::switchAuton(){
    lock.take(5);
    index++;
    index %= auton.size();
    lock.give();
}

void Auton::select(){
    pros::lcd::register_btn1_cb([](){});
    pros::lcd::register_btn2_cb([](){});
    //addPath(index);
}

std::string Auton::getName(){
    lock.take(5);
    std::string ret = name[index];
    lock.give();
    return ret;
}

void Auton::execute(){
    auton[index];
}




/**
 * @brief Initializes the auton
 * 
 */
void Auton::init() {
    // INITIALIZATION
    leftDrive.setBrakeMode(AbstractMotor::brakeMode::hold);
    rightDrive.setBrakeMode(AbstractMotor::brakeMode::hold);
    lift.setBrakeMode(AbstractMotor::brakeMode::hold);
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
    roller.moveVoltage(12000);

    mogoClamp.set(true); pros::delay(250); mogo.set(true);
    profiler->setTarget(Skills::path0);
    profiler->waitUntilSettled();
    moveTime({0.1, 0.1}, 250_ms);
    claw.set(true);

    profiler->setTarget(Skills::path1);
    liftController->setTarget(715);
    profiler->waitUntilSettled();
    claw.set(false); pros::delay(500);

    moveDistance(-8_in);
    liftController->setTarget(0);
    turnToAngle(0_deg);
    mogo.set(false); mogoClamp.set(false);

    moveDistance(3_ft);
    moveTime({0.5, 0.5}, 500_ms);
    claw.set(true); pros::delay(250);
    liftController->setTarget(350);
    
    profiler->setTarget(Skills::path2);
    profiler->waitUntilSettled();
}

