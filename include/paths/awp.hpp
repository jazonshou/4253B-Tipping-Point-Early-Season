#pragma once
#include "main.h"

/**
 * @brief The follow class contains all paths used in the auton win point (AWP) auton
 * 
 */
class AWP {
    public:
    static std::vector<std::vector<double>> fwdRLeft;
    static std::vector<std::vector<double>> fwdRRight;

    static std::vector<std::vector<double>> loopbackLeft;
    static std::vector<std::vector<double>> loopbackRight;

    // ---------------------------------------------
    static std::vector<std::vector<double>> path1NewLeft;
    static std::vector<std::vector<double>> path1NewRight;

    static std::vector<std::vector<double>> testLeft;
    static std::vector<std::vector<double>> testRight;

    static Trajectory path0Left;
};