#pragma once
#include "main.h"

/**
 * @brief The following class contains all paths used in the left auton.
 *        In the auton, we first capture the left neutral mogo, score a ring
 *        and bring it back. As we head back to our home row, we move to our
 *        alliance mogo where we deposit a ring into the base of our mogo. 
 * 
 */
class LeftPaths {
    public:
    static std::vector<std::vector<double>> path1Left;
    static std::vector<std::vector<double>> path1Right;

    static std::vector<std::vector<double>> path2Left;
    static std::vector<std::vector<double>> path2Right;
};