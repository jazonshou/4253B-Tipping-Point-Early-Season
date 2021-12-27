#include "main.h"

/**
 * @brief Construct a new Auton object, creates liftController
 * 
 */
Auton::Auton() {
    liftController = AsyncPosControllerBuilder()
        .withMotor(lift)
        .withGains({0.00875, 0.0, 0.000075}) 
        .build();

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
    liftController->tarePosition();
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
    /*
    mogoClamp.set(true);
    pros::delay(250);
    mogo.set(true);
    roller.moveVoltage(12000);
    followPathCustom(Skills::path1Left);
    // setVelocity(300, 300); pros::delay(100); setVelocity(0, 0);
    roller.moveVoltage(0);
    claw.set(true);
    pros::delay(250);
    liftController->setTarget(700);
    roller.moveVoltage(12000);
    followPathCustom(Skills::path2Left);
    
    roller.moveVoltage(0);
    
    claw.set(false);
    
    followPathCustom(Skills::path3Left);
    turnToAngle(0_deg);

    liftController->setTarget(0);
    mogo.set(false); pros::delay(250); mogoClamp.set(false);
    followPathCustom(Skills::path4Left);
    claw.set(true);
    liftController->setTarget(400);
    followPathCustom(Skills::path5Left);
    liftController->setTarget(700);
    roller.moveVoltage(12000);
    followPathCustom(Skills::path6Left);
    roller.moveVoltage(0);
    claw.set(false);
    turnToAngle(270_deg);

    followPathCustom(Skills::path7Left);
    turnToAngle(0_deg);
    alignMogo();
    liftController->setTarget(0);
    (chassis->getModel())->tank(-0.5, -0.5); pros::delay(1500); (chassis->getModel())->tank(0, 0);
    pros::delay(500);
    (chassis->getModel())->tank(0.1, 0.1); pros::delay(100); (chassis->getModel())->tank(0, 0);
    // followPathCustom(Skills::path8Left);
    mogoClamp.set(true); pros::delay(500); mogo.set(true);
    (chassis->getModel())->tank(0.4, 0.4); pros::delay(250); (chassis->getModel())->tank(0, 0);

    turnToAngle(0_deg);
    followPathCustom(Skills::path9Left);
    claw.set(true);
    liftController->setTarget(700);
    roller.moveVoltage(12000);
    followPathCustom(Skills::path10Left);
    claw.set(false);
    
    followPathCustom(Skills::path11Left);
    followPathCustom(Skills::path12Left);
    mogo.set(false); pros::delay(250); mogoClamp.set(false);
    followPathCustom(Skills::path12Left);
    liftController->setTarget(0);
    roller.moveVoltage(0);
    turnToAngle(0_deg);
    followPathCustom(Skills::path12Left);
    followPathCustom(Skills::path12Left);
    claw.set(true);
    liftController->setTarget(700);
    
    followPathCustom(Skills::path13Left);
    turnToAngle(90_deg);
    followPathCustom(Skills::path12Left);
    claw.set(false);
    */
}


