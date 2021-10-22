#pragma once
#include "main.h"

class Globals {
    public:
    // CONTROLLER
    // static Controller master;

    // MOTORS - check rotation
    static Motor leftFront;
    static Motor leftTop;
    static Motor leftBottom;
    static Motor rightFront;
    static Motor rightTop;
    static Motor rightBottom;

    static Motor lift;

    //change port
    static Motor roller;

    // SENSORS - check ports & rotation
    static ADIEncoder trackLeft;
    static ADIEncoder trackRight;
    static ADIEncoder trackMiddle;

    static RotationSensor liftSensor;

    // PNEUMATICS
    static pros::ADIDigitalOut mogoLeft;
    static pros::ADIDigitalOut mogoRight;

    static pros::ADIDigitalOut claw; //check port
};