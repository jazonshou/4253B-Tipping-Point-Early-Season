#include "globals.hpp"

// CONTROLLER
// Controller Globals::master(); //wtf

// MOTORS - check rotation
Motor Globals::leftFront(1, false, AbstractMotor::gearset::blue, AbstractMotor::encoderUnits::degrees);
Motor Globals::leftTop(20, false, AbstractMotor::gearset::blue, AbstractMotor::encoderUnits::degrees);
Motor Globals::leftBottom(19, false, AbstractMotor::gearset::blue, AbstractMotor::encoderUnits::degrees);
Motor Globals::rightFront(16, false, AbstractMotor::gearset::blue, AbstractMotor::encoderUnits::degrees);
Motor Globals::rightTop(17, false, AbstractMotor::gearset::blue, AbstractMotor::encoderUnits::degrees);
Motor Globals::rightBottom(18, false, AbstractMotor::gearset::blue, AbstractMotor::encoderUnits::degrees);

Motor Globals::lift(15, false, AbstractMotor::gearset::green, AbstractMotor::encoderUnits::degrees);

//change port
Motor Globals::roller(8, false, AbstractMotor::gearset::blue, AbstractMotor::encoderUnits::degrees); 

// SENSORS - check ports & rotation
ADIEncoder Globals::trackLeft({14, 'A', 'B'}, false);
ADIEncoder Globals::trackRight({14, 'C', 'D'}, false);
ADIEncoder Globals::trackMiddle({14, 'E', 'F'}, false);

RotationSensor Globals::liftSensor(5, false); //check port

// PNEUMATICS
pros::ADIDigitalOut Globals::mogoLeft({{14, 'G'}});
pros::ADIDigitalOut Globals::mogoRight({{14, 'H'}});

pros::ADIDigitalOut Globals::claw('A'); //check port