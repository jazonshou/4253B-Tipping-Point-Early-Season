#pragma once
#include "main.h"

/**
 * @brief Namespace for all math related functions
 * 
 */
namespace Math{

/**
 * @brief limits the value to zero if the value is smaller than deadband
 * 
 * @param value the value to limit
 * @param db deadband limit
 * @return double the value controlled with deadband
 */
double deadband(double value, double db);

/**
 * @brief clamps the value within [mn, mx]. Analogous to std::clamp()
 *        The function works for any data type with an overloaded < and > operator
 * 
 * @tparam T the type to use
 * @param val the value to clamp
 * @param mn minimum value
 * @param mx maximum value
 * @return T the clamped value
 */
template<typename T>
T clamp(T val, T mn, T mx){return std::max(std::min(mx, val), mn);}

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
 * @brief converts radius and angle to arc length using the formula s = rw
 * 
 * @param angle angle
 * @param rad radius
 * @return QLength computed arc length
 */
QLength angleToArcLength(QAngle angle, QLength rad);

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

/**
 * @brief The quadratic formula [https://youtu.be/VOXYMRcWbF8]
 *        Computes the two roots of a quadratic equation
 *        x = -b +- sqrt(b^2 - 4ac) / 2a
 * 
 * @param a ^
 * @param b ^
 * @param c ^
 * @return pair containing the two roots, first value is the larger solution
 */
std::pair<double, double> quadraticFormula(double a, double b, double c);

};
