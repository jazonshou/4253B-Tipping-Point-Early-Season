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
 * @brief Rescales an angle to [-180, 180]
 * 
 * @param angle angle to be converted
 * @return scaled angle to [-180, 180]
 */
double rescale180(double angle);

/**
 * @brief Rescales an angle to [0, 360]
 * 
 * @param angle angle to be converted
 * @return scaled angle to [0, 360]
 */
double rescale360(double angle);

};
