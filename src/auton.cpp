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
    wings.set_value(true);
    translate(-3.5_ft);
    while(translatePID->getError() > 50) {
        pros::delay(20);
    }
    wings.set_value(false);
    translate(2.5_ft);
}

void Auton::left(){
    mogoClamp.set_value(true);
    pros::delay(250);
    mogo.set_value(true);
    liftController->setTarget(700);
    roller.moveVoltage(12000);
    followPathCustom(AWP::path0Left);
    // pros::delay(1000);
    roller.moveVoltage(-12000);
    followPathCustom(Skills::path13Left);
    turnToAngle(90_deg);

    mogo.set_value(false);
    pros::delay(250);
    mogoClamp.set_value(false);
    roller.moveVoltage(12000);
    liftController->setTarget(0);
    liftController->waitUntilSettled();
}

void Auton::right(){
    wings.set_value(true);
    followPathCustom(AWP::pathLeft);
    wings.set_value(false);
    pros::delay(325);
    followPathCustom(AWP::pathBackLeft);
    turnToAngle(280_deg);
    liftController->setTarget(700);
    followPathCustom(AWP::pathBackLeft);
    turnToAngle(0_deg);
    (chassis->getModel())->tank(300, 300); pros::delay(1000);(chassis->getModel())->tank(0, 0);
    wings.set_value(true); pros::delay(250); wings.set_value(false);
    followPathCustom(Skills::path13Left);
    liftController->setTarget(0);
    turnToAngle(90_deg);
}

void Auton::awp(){
    pros::delay(7500);
    liftController->setTarget(700);
    liftController->waitUntilSettled();
    liftController->setTarget(0);
    followPathCustom(AWP::pathNew0Left);
    claw.set_value(true);
    liftController->setTarget(400);
    followPathCustom(Skills::path13Left);
}


void Auton::skills(){
    mogoClamp.set_value(true);
    pros::delay(250);
    mogo.set_value(true);
    roller.moveVoltage(12000);
    followPathCustom(Skills::path1Left);
    // setVelocity(300, 300); pros::delay(100); setVelocity(0, 0);
    roller.moveVoltage(0);
    claw.set_value(true);
    pros::delay(250);
    liftController->setTarget(700);
    roller.moveVoltage(12000);
    followPathCustom(Skills::path2Left);
    
    roller.moveVoltage(0);
    
    claw.set_value(false);
    
    followPathCustom(Skills::path3Left);
    turnToAngle(0_deg);

    liftController->setTarget(0);
    mogo.set_value(false); pros::delay(250); mogoClamp.set_value(false);
    followPathCustom(Skills::path4Left);
    claw.set_value(true);
    liftController->setTarget(400);
    followPathCustom(Skills::path5Left);
    liftController->setTarget(700);
    roller.moveVoltage(12000);
    followPathCustom(Skills::path6Left);
    roller.moveVoltage(0);
    claw.set_value(false);
    turnToAngle(270_deg);

    followPathCustom(Skills::path7Left);
    turnToAngle(0_deg);
    alignMogo();
    liftController->setTarget(0);
    (chassis->getModel())->tank(-0.5, -0.5); pros::delay(1500); (chassis->getModel())->tank(0, 0);
    pros::delay(500);
    (chassis->getModel())->tank(0.1, 0.1); pros::delay(100); (chassis->getModel())->tank(0, 0);
    // followPathCustom(Skills::path8Left);
    mogoClamp.set_value(true); pros::delay(500); mogo.set_value(true);
    (chassis->getModel())->tank(0.4, 0.4); pros::delay(250); (chassis->getModel())->tank(0, 0);

    turnToAngle(0_deg);
    followPathCustom(Skills::path9Left);
    claw.set_value(true);
    liftController->setTarget(700);
    roller.moveVoltage(12000);
    followPathCustom(Skills::path10Left);
    claw.set_value(false);
    
    followPathCustom(Skills::path11Left);
    followPathCustom(Skills::path12Left);
    mogo.set_value(false); pros::delay(250); mogoClamp.set_value(false);
    followPathCustom(Skills::path12Left);
    liftController->setTarget(0);
    roller.moveVoltage(0);
    turnToAngle(0_deg);
    followPathCustom(Skills::path12Left);
    followPathCustom(Skills::path12Left);
    claw.set_value(true);
    liftController->setTarget(700);
    
    followPathCustom(Skills::path13Left);
    turnToAngle(90_deg);
    followPathCustom(Skills::path12Left);
    claw.set_value(false);
}


