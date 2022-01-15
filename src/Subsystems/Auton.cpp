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
    pros::lcd::register_btn0_cb([](){});
    pros::lcd::register_btn1_cb([](){});
    pros::lcd::register_btn2_cb([](){});
}

std::string Auton::getName(){
    lock.take(5);
    std::string ret = name[index];
    lock.give();
    return ret;
}

void Auton::execute(){
    lock.take(5);
    auton[index];
    lock.give();
}

void Auton::init() {
    // sets brake mode
    leftDrive.setBrakeMode(AbstractMotor::brakeMode::hold);
    rightDrive.setBrakeMode(AbstractMotor::brakeMode::hold);
    lift.setBrakeMode(AbstractMotor::brakeMode::hold);

    // resets lift controller
    liftController->reset();
    
}

void Auton::wingGrab() {
    wings.set(true);

    profiler->setTarget(-2.75_ft);
    pros::delay(775);

    wings.set(false);
    profiler->waitUntilSettled();

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

    mogoClamp.set(true); pros::delay(250); mogo.set(true);

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
    
    mogoClamp.set(true); pros::delay(250); mogo.set(true);
    roller.moveVoltage(12000);

    profiler->setTarget(Skills::path0);
    pros::delay(1000);
    liftController->setTarget(0);
    profiler->waitUntilSettled();
    claw.set(true);
    
    profiler->setTarget(Skills::path1);
    liftController->setTarget(710);
    profiler->waitUntilSettled();

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
    profiler->setTarget(-10_in);
    profiler->waitUntilSettled();
    turnToAngle(180_deg);
    moveTime({0.5, 0.5}, 1_s);
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
    moveTime({0.25, 0.25}, 600_ms); 
    claw.set(true); pros::delay(250);

    liftController->setTarget(710);
    turnToAngle(47.5_deg); 
    moveDistance(5_ft, 2_s);
    turnToAngle(90_deg);
    moveDistance(1_ft, 1000_ms);
    claw.set(false); pros::delay(250);

    moveDistance(-2_ft);
    mogo.set(false); mogoClamp.set(false);
    liftController->setTarget(0);
    moveDistance(10_in);
    turnToAngle(270_deg);
    liftController->waitUntilSettled();
    moveTime({0.5, 0.5}, 850_ms);
    claw.set(true); pros::delay(250);
    liftController->setTarget(710);
    turnToAngle(100_deg);
    moveDistance(4_ft, 2000_ms);
    claw.set(false); pros::delay(250);

    moveDistance(-1_ft);
    turnToAngle(0_deg);
    moveDistance(4_ft, 2_s);
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
}


