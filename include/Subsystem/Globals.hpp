#pragma once
#include "main.h"

#define LVGL_SCREEN_WIDTH 480
#define LVGL_SCREEN_HEIGHT 240

// CONSTANTS
const double DEADBAND = 0.0500;
const int MAX_LIFT_HEIGHT = 750; 
const int LIFT_STEP = 11; 

extern const double TURNKI;

// CONTROLLER
extern Controller master;

// MOTORS
extern MotorGroup leftDrive;
extern MotorGroup rightDrive;
extern Motor lift;
extern pros::Motor lift_pros;
extern Motor roller;

// SENSORS
extern IMU imu; 
extern pros::Vision vision_sensor;

// PNEUMATICS
extern Pneumatics mogo;
extern Pneumatics mogoClamp;
extern Pneumatics claw;
extern Pneumatics wings;

// SUBSYSTEM CONTROLLERS
extern std::shared_ptr<ChassisController> chassis;
// extern std::shared_ptr<AsyncPositionController<double, double>> liftController;
extern std::shared_ptr<AsyncMotionProfiler> profiler;

// PID CONTROLLERS
extern std::shared_ptr<IterativePosPIDController> turnPID;
extern std::shared_ptr<IterativePosPIDController> visionPID;
extern std::shared_ptr<IterativePosPIDController> movePID;
extern std::shared_ptr<IterativePosPIDController> headingPID;

// MOTION PROFILE CONSTANTS
extern ProfileConstraint constraint;
extern FFVelocityController leftMotorController;
extern FFVelocityController rightMotorController;



