#pragma once
#include "main.h"

/**
 * @brief Class for our custom feedforward velocity controller
 * 
 */
class FFVelocityController{
    private:
        double kV, kA_Up, kA_Down, kP_Pos, kP_Vel;
        double currPos, currVel, power;

    public:
        /**
         * @brief Construct a new FFVelocityController object
         * 
         */
        FFVelocityController() = default;

        /**
         * @brief Destroy the FFVelocityController object
         * 
         */
        ~FFVelocityController() = default;

        /**
         * @brief Construct a new FFVelocityController object
         * 
         * @param ikV velocity constant
         * @param ikAU acceleration constant
         * @param ikAD deceleration constant
         * @param ikP_Pos proportional constant for position
         * @param ikP_Vel proportional constant for velocity
         */
        FFVelocityController(double ikV, double ikAU, double ikAD, double ikP_Pos, double ikP_Vel);

        /**
         * @brief Calculates one step given the parameters
         * 
         * @param position desired position
         * @param velocity desired velocity
         * @param acceleration desired acceleration
         * @param currentPos current position, in motor ticks
         * @param currentRPM current RPM
         * @return calculated power to reach the target velocity
         */
        double step(double position, double velocity, double acceleration, double currentPos, double currentRPM);

        /**
         * @brief Returns the target power
         * 
         * @return target power
         */
        double getTargetPower() const;

        /**
         * @brief Returns kV constant
         * 
         * @return kV
         */
        double getkV() const;
};

