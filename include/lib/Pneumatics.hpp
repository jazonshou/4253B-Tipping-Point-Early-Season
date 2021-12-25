#pragma once
#include "main.h"

class Pneumatics{
    pros::ADIDigitalOut piston;
    bool state;

    public:
    Pneumatics(char iPort, bool initState = false);
    void toggle();
    void setState(bool iState);
};