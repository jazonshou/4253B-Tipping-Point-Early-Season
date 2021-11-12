#pragma once
#include "main.h"

/**
 * @brief The following class contains all paths used in the old right auton. 
 *        The right auton begins by curving to the tall neutral mogo, tipping
 *        it over, and going back to score 2 rings on our right alliance mogo.
 * 
 */
class RightPaths {
    public:
    static std::vector<std::vector<double>> curveLeft;
    static std::vector<std::vector<double>> curveRight;

    static std::vector<std::vector<double>> curveRLeft;
    static std::vector<std::vector<double>> curveRRight;

    static std::vector<std::vector<double>> fwdLeft;
    static std::vector<std::vector<double>> fwdRight;
};