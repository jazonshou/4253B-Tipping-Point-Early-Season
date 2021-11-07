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
    static std::vector<std::vector<double>> pathLeft;
    static std::vector<std::vector<double>> pathRight;

    static std::vector<std::vector<double>> pathRLeft;
    static std::vector<std::vector<double>> pathRRight;

    static std::vector<std::vector<double>> pathLeftR;
    static std::vector<std::vector<double>> pathRightR;

    static std::vector<std::vector<double>> fwdLeft;
    static std::vector<std::vector<double>> fwdRight;
};