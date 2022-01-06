#pragma once
#include "main.h"

/**
 * @brief A very necessary wrapper class for pneumatics
 * 
 */
class Pneumatics{
    pros::ADIDigitalOut piston;
    bool state;

    public:
    /**
     * @brief Construct a new Pneumatics object
     * 
     * @param iPort solinoid port
     * @param initState initial state of the piston
     */
    Pneumatics(char iPort, bool initState = false);

    /**
     * @brief Destroys the Pneumatics object
     * 
     */
    ~Pneumatics() = default;

    /**
     * @brief Toggls the solinoid on/off
     * 
     */
    void toggle();

    /**
     * @brief Sets the state of the solinoid
     * 
     * @param iState state
     */
    void set(bool iState);
};