#pragma once
#include "main.h"

#define Pneumatic pros::ADIDigitalOut
const double DEADBAND = 0.0500;
const double MAXLIFTHEIGHT = 2000;
const double LIFTINCREMENT = 100;

// CONTROLLER
Controller master;

    // MOTORS - check rotation
MotorGroup leftDrive;
MotorGroup rightDrive;

Motor lift;

//change port
Motor roller;

// SENSORS - check ports & rotation
ADIEncoder trackLeft;
ADIEncoder trackRight;
ADIEncoder trackMiddle;

RotationSensor liftSensor;

// PNEUMATICS
Pneumatic mogoLeft;
Pneumatic mogoRight;

Pneumatic claw; //check port


