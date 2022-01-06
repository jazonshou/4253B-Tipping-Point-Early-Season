#pragma once
#include "main.h"

/**
 * @brief Namespace for all math related functions
 * 
 */
namespace Math{

/**
 * @brief Converts feets per second to rounds per minute
 * 
 * @param ftps feets per second
 * @return rounds per minute
 */
double ftpsToRPM(double ftps);

/**
 * @brief Converts rounds per minute to feet per second
 * 
 * @param rpm rounds per minute
 * @return feet per second
 */
double rpmToFtps(double rpm);

/**
 * @brief Converts feets to encoder ticks (aka. degrees)
 * 
 * @param ft feet
 * @return encoder ticks 
 */
double ftToTick(double ft);

/**
 * @brief Converts encoder ticks to feet
 * 
 * @param tick encoder ticks
 * @return feet
 */
double tickToFt(double tick);

/**
 * @brief Converts encoder ticks to actual distance
 * 
 * @return actual distance
 */
QLength tickToDistance();

/**
 * @brief Rescales an angle to [-180, 180]
 * 
 * @param angle Angle to be rescaled
 * @return rescaled angle
 */
QAngle rescale180(QAngle angle);

/**
 * @brief Rescales an angle to [-180, 180]
 * 
 * @param angle angle to be converted
 * @return scaled angle to [-180, 180]
 */
double rescale180(double angle);

/**
 * @brief Rescales an angle to [0, 360]
 * 
 * @param angle angle to be rescaled
 * @return rescaled angle
 */
QAngle rescale360(QAngle angle);

/**
 * @brief Rescales an angle to [0, 360]
 * 
 * @param angle angle to be converted
 * @return scaled angle to [0, 360]
 */
double rescale360(double angle);


/*
    x1 is larger solution, x1 is smaller
    jason write a description for this
*/

/**
 * @brief The quadratic formula [https://youtu.be/VOXYMRcWbF8]
 *        x = -b +- sqrt(pow(b) - 4ac) / 2a
 * 
 * @param a ^
 * @param b ^
 * @param c ^
 * @return pair containing the solutions
 */
std::pair<double, double> quadraticFormula(double a, double b, double c);

};
