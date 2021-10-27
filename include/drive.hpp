#pragma once
#include"main.h"

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
 * @param targetAngle - the target odometry global angle to turn to, normalized to [-2pi, 2pi]
 */
void turnToAngle(okapi::QAngle targetAngle);

double velControl(QSpeed velocity, QAcceleration accel, QSpeed currSpeed);

std::vector<double> pathToRPM(std::vector<std::vector<double>> path);

void followPath(std::vector<std::vector<double>> leftVel, std::vector<std::vector<double>> rightVel);