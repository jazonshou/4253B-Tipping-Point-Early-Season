#pragma once
#include "main.h"

class RightNew {
    public:
    static std::vector<std::vector<double>> pathBackLeft;
    static std::vector<std::vector<double>> pathBackRight;

    static std::vector<std::vector<double>> pathRLeft;
    static std::vector<std::vector<double>> pathRRight;

    static std::vector<std::vector<double>> shortTurnLeft;
    static std::vector<std::vector<double>> shortTurnRight;

    static std::vector<std::vector<double>> backLeft;
    static std::vector<std::vector<double>> backRight;

    static std::vector<std::vector<double>> forwardLeft;
    static std::vector<std::vector<double>> forwardRight;
};