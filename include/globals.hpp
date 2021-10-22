#pragma once
#include "main.h"

#define Pneumatic pros::ADIDigitalOut
const double DEADBAND = 0.0500;
const double MAXLIFTHEIGHT = 2000;
const double LIFTINCREMENT = 100;

// CONTROLLER
extern Controller master;

// MOTORS - check rotation
extern MotorGroup leftDrive;
extern MotorGroup rightDrive;

// LIFT
extern Motor lift;

//change port
extern Motor roller;

// SENSORS - check ports & rotation
extern ADIEncoder trackLeft;
extern ADIEncoder trackRight;
extern ADIEncoder trackMiddle;

extern RotationSensor liftSensor;

// PNEUMATICS
extern Pneumatic mogoLeft;
extern Pneumatic mogoRight;
extern Pneumatic claw; //check port

// CUSTOM CONTROLLERS
extern std::shared_ptr<OdomChassisController> chassis;
extern std::shared_ptr<AsyncMotionProfileController> profiler;
extern std::shared_ptr<AsyncPositionController<double, double>> liftController;
extern std::shared_ptr<IterativePosPIDController> turnPID;
