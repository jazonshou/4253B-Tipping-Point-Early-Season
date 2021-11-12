#pragma once
#include "main.h"

/**
 * @brief set 'Pneumatic' as pros::ADIDigitalOut
 * 
 */
using Pneumatic = pros::ADIDigitalOut;

// CONSTANTS
/**
 * @brief Here is our constants (though we only ended up really using
 *        DEADBAND since we had no time to tune lift)
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

// MOTORS
/**
 * @brief These are all the motors we used 
 *        (each of our drive motor groups have 3 individual motors)
 * 
 */
extern MotorGroup leftDrive;
extern MotorGroup rightDrive;
// extern pros::Motor lift;

extern Motor lift;
extern Motor roller;

// SENSORS
/**
 * @brief These were all sensors we were planning on using. But due to 
 *        time constraints, mechanical issues, and our insanely accurate 
 *        pathing algorithm, we found no need to use these sensors. 
 * 
 */
extern ADIEncoder trackLeft;
extern ADIEncoder trackRight;
extern ADIEncoder trackMiddle;

extern RotationSensor liftSensor;
extern RotationSensor mogoSensor;

extern IMU imu; 

// PNEUMATICS
/**
 * @brief Globally declares our solenoids (one for claw, one for back mogo lift)
 * 
 */
// extern Pneumatic mogo;
extern Motor mogo;
// extern pros::Motor mogo;
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
extern std::shared_ptr<AsyncPositionController<double, double>> liftController;
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

