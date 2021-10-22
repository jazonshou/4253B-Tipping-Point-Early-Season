#pragma once
#include "main.h"

class PID {
    private: 
    double kP, kI, kD, kFF;
    double error{0}, prevError{0}, derivative{0}, integral{0};

    public: 
    PID(double kP, double kI, double kD);
    PID(double kP, double kI, double kD, double kFF);
    double update(double input);
};