#pragma once
#include "main.h"

class FFVelocityController{
    private:
        double kV, kA_Up, kA_Down, kP_Pos, kP_Vel;
        double currPos, currVel, power;

    public:
        FFVelocityController() = default;
        ~FFVelocityController() = default;

        FFVelocityController(double, double, double, double, double);

        double step(double position, double velocity, double acceleration, double currentPos, double currentRPM);

        double getTargetPower() const;

        double getkV() const {return kV;}
};

