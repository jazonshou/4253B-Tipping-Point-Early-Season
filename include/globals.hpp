#pragma once
#include "main.h"

/**
 * @brief set 'Pneumatic' as pros::ADIDigitalOut
 * 
 */
using Pneumatic = pros::ADIDigitalOut;

// CONSTANTS
/**
 * @brief Here is our constants for our lift & PID
 * 
 */
const double DEADBAND = 0.0500;
const double MAX_LIFT_HEIGHT = 2000; 
const double MAX_MOGO_DISTANCE = 35; 
const double LIFT_INCREMENT = 10; 

const double LEFT_kV = 1500.0;
const double LEFT_kA = 250.0;
const double LEFT_kP = 1500.0;

const double RIGHT_kV = 1500.0;
const double RIGHT_kA = 250.0;
const double RIGHT_kP = 1500.0;

// CONTROLLER
/**
 * @brief Our controller
 * 
 */
extern Controller master;

// MOTOR GROUPS
/**
 * @brief These are the 2 motor groups for the left & right side of the drive
 * 
 */
extern MotorGroup leftDrive;
extern MotorGroup rightDrive;

// MOTORS
/**
 * @brief These are the motors for our lift & back mogo
 * 
 */
extern Motor lift;
extern Motor roller;
// extern Motor mogo;

// SENSORS
/**
 * @brief Here are all the sensors we were planning on using. 
 *        Though in the end, we only ended up using the liftSensor & 
 *        mogoSensor because of time constraints. 
 * 
 */
extern ADIEncoder trackLeft;
extern ADIEncoder trackRight;
extern ADIEncoder trackMiddle;

extern RotationSensor liftSensor;
// extern RotationSensor mogoSensor;

extern IMU imu; 

// PNEUMATICS
/**
 * @brief Globally declares our solenoids (one for claw, one for wings)
 * 
 */
extern Pneumatic mogo;
extern Pneumatic mogoClamp;
extern Pneumatic claw;
extern Pneumatic wings;

// SUBSYSTEM CONTROLLERS
/**
 * @brief All of the following are controllers from Okpailib. But since we were 
 *        quite sucessful with our own custom path follower, we decided not to 
 *        use these. 
 * 
 */
extern std::shared_ptr<OdomChassisController> chassis;
extern std::shared_ptr<AsyncMotionProfileController> profiler;
// extern std::shared_ptr<AsyncPositionController<double, double>> liftController;
// extern std::shared_ptr<AsyncPositionController<double, double>> rollerController;
extern std::shared_ptr<AsyncPositionController<double, double>> mogoController;
extern std::shared_ptr<IterativePosPIDController> turnPID;


// AUTONOMOUS CONTROLLER
/**
 * @brief As stated previously, due to time constraints and bugs, we were not able 
 *        able to have our auton selector ready in time. 
 * 
 */
extern int selectedAuton;
extern std::map<int, std::function<void()>> auton;
extern std::map<int, std::function<void()>> path;