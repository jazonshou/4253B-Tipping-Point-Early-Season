#pragma once
#include "main.h"

/**
 * @brief Wrapper class for vex pneumatics which allows more convenient control
 * 
 */
class LazyPneumatics {
    pros::ADIDigitalOut piston;
    bool state;

    public:
    /**
     * @brief Construct a new LazyPneumatics object
     * 
     * @param iPort solinoid port
     * @param initState initial state of the piston
     */
    LazyPneumatics(char iPort, bool initState = false);

    /**
     * @brief Destroys the LazyPneumatics object
     * 
     */
    ~LazyPneumatics() = default;

    /**
     * @brief Toggles the solinoid to the value opposite to the current state
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