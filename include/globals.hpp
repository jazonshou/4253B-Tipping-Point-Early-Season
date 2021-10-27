#pragma once
#include "main.h"
using Pneumatic = pros::ADIDigitalOut;

// CONSTANTS
const double DEADBAND = 0.0500;
const double MAXLIFTHEIGHT = 2000; // TODO - Tune Max Lift Tick
const double LIFT_INCREMENT = 10; // TODO - Tune incrememt to match actual lift velocity

// CONTROLLER
extern Controller master;

// MOTORS
extern MotorGroup leftDrive;
extern MotorGroup rightDrive;
// extern Motor lift;
extern pros::Motor lift;
extern Motor roller;

// SENSORS
extern ADIEncoder trackLeft;
extern ADIEncoder trackRight;
extern ADIEncoder trackMiddle;
extern RotationSensor liftSensor;
extern IMU imu; 

// PNEUMATICS
extern Pneumatic mogo;
extern Pneumatic claw;

// SUBSYSTEM CONTROLLERS
extern std::shared_ptr<ChassisController> chassis;
extern std::shared_ptr<AsyncMotionProfileController> profiler;
extern std::shared_ptr<AsyncPositionController<double, double>> liftController;
extern std::shared_ptr<IterativePosPIDController> turnPID;


// AUTONOMOUS CONTROLLER
extern int selectedAuton;
extern std::map<int, std::function<void()>> auton;
extern std::map<int, std::function<void()>> path;

