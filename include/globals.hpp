#pragma once
#include "main.h"

#define LVGL_SCREEN_WIDTH 480
#define LVGL_SCREEN_HEIGHT 240

using Pneumatic = pros::ADIDigitalOut;

// CONSTANTS
const double DEADBAND = 0.0500;
const double MAX_LIFT_HEIGHT = 2000; 
const double LIFT_INCREMENT = 10; 

// CONTROLLER
extern Controller master;

// MOTORS
extern MotorGroup leftDrive;
extern MotorGroup rightDrive;
extern Motor lift;
extern Motor roller;

// SENSORS
// extern RotationSensor liftSensor;
extern IMU imu; 
extern pros::Vision vision_sensor;

// PNEUMATICS
extern Pneumatic mogo;
extern Pneumatic mogoClamp;
extern Pneumatic claw;
extern Pneumatic wings;

// SUBSYSTEM CONTROLLERS
extern std::shared_ptr<ChassisController> chassis;
extern std::shared_ptr<AsyncPositionController<double, double>> liftController;
extern std::shared_ptr<IterativePosPIDController> turnPID;
extern std::shared_ptr<IterativePosPIDController> mogoAlignerController;
extern std::shared_ptr<IterativePosPIDController> translatePID;


// VELOCITY CONTROLLERS
class FFVelocityController;
extern FFVelocityController leftMotorController;
extern FFVelocityController rightMotorController;


