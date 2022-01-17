#pragma once
#include "main.h"

/**
 * @brief This namespaces contains our auton selector implemented
 *        using pros' LLEMU buttons, as well as all our auton routes
 * 
 */
class Auton {
    private: 
    std::shared_ptr<AsyncPositionController<double, double>> liftController;

    public:
    /**
     * @brief initializes robot for autonomous
     * 
     */
    void init();

    /**
     * @brief utility function which pulls two mogo from the center using our wings
     * 
     */
    void wingGrab();

    /**
     * @brief our skills autnomous routine
     * 
     */
    void skills();  

    /**
     * @brief Our autonomous routing for starting on the left side
     * 
     */
    void left();

    /**
     * @brief Our autonomous routing for starting on the right side
     * 
     */
    void right();

    /**
     * @brief Our autonomous routine that gets the autonomous win point by ourselves
     * 
     */
    void awp();
};