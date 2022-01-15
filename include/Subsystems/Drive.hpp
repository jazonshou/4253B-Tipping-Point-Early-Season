#pragma once
#include "main.h"

/**
 * @brief Computes the desired drive speed to control the chassis using curvature control
 *        The turn power is scaled with the linear power in order to allow finer control
 *        of the chassis. The easiest way to imagine this control is by consider driving
 *        a car: the left stick is the gas pedal (throttle), the right stick is the steering
 *        wheel, which controls the curvature the car drives in by manipulating the wheel location
 * 
 * @param moveC - the desired linear speed for the robot to move in, normalized to [-1, 1]
 * @param turnC - the desired curvature for the robot to move in, normalized to [-1, 1]
 * @param quickTurn - when this parameter is set to true, arcade control is used instead to allow point turn
 */
void curvatureDrive(double moveC, double turnC, bool quickTurn);

/**
 * @brief Moves for set amount of time at set speed
 * 
 * @param speed speed [-1, 1]
 * @param time time
 */
void moveTime(std::pair<double, double> speed, QTime time);

/**
 * @brief Moves for set amount of time at set speed. Heading is maintained using PID
 * 
 * @param speed speed [-1, 1]
 * @param time time
 */
void moveTimeHeadingCorrect(double speed, QTime time);

/**
 * @brief Moves the robot for the desired distance (using closed-loop control)
 * 
 * @param target desired location
 * @param time maximum time to run before ending the loop, defaulted to infinite
 */
void moveDistance(QLength target, QTime time = 2_min);

/**
 * @brief Turns the robot to the desired global angle (using closed-loop control)
 * 
 * @param targetAngle - the target odometry global angle to turn to, normalized to [-pi, pi]
 */
void turnToAngle(QAngle targetAngle);

/**
 * @brief Uses the vision sensor & PID to align the back mogo holder to a red goal
 * 
 */
void turnToMogo();

