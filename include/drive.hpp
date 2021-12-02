#pragma once
#include "main.h"

/**
 * @brief Sets voltage of drive
 * 
 * @param l left voltage [-12000, 12000]
 * @param r right voltage [-12000, 12000]
 */
void setVoltage(double l, double r);

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
std::pair<double, double> curvatureDrive(double moveC, double turnC, bool quickTurn);

/**
 * @brief Turns the robot to the desired global angle (using closed-loop control)
 * 
 * @param targetAngle - the target odometry global angle to turn to, normalized to [-pi, pi]
 */
void turnToAngle(okapi::QAngle targetAngle);

/**
 * @brief Follows a path using the internal motor velocity controller
 * 
 * @param path 
 */
void followPath(const Trajectory& path);

/**
 * @brief Follows a path using our custon feedforward velocity controller
 * 
 * @param path 
 */
void followPathCustom(const Trajectory& path);

/**
 * @brief Uses the vision sensor & PID to align the back mogo holder to a red goal
 * 
 */
void alignMogo();