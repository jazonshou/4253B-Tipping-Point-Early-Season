#pragma once
#include "main.h"

/**
 * @brief Computes the desired drive speed to control the chassis using curvature control
 *        The turn power is scaled with the linear power in order to allow finer control
 *        of the chassis.
 * 
 * @param moveC - the desired linear speed for the robot to move in, normalized to [-1, 1]
 * @param turnC - the desired curvature for the robot to move in, normalized to [-1, 1]
 * @param quickTurn - when this parameter is set to true, arcade control is used instead to allow point turn
 * 
 * @return the desired left and right velocity for the chassis motors to move in, normalized to [-1, 1]
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
 * @brief Moves for set amount of time at set speed and corrects heading
 * 
 * @param speed speed [-1, 1]
 * @param time time
 */
void moveTimeHeadingCorrect(double speed, QTime time);

/**
 * @brief PID moves to desired target
 * 
 * @param target desired location
 */
void moveDistance(QLength target);

/**
 * @brief PID moves to desired target
 * 
 * @param target desired location
 * @param time max time
 */
void moveDistance(QLength target, QTime time);

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

