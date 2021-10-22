#include "main.h"

// CONTROLLER
Controller master(ControllerId::master); 

// MOTORS - check rotation
MotorGroup leftDrive({1, 20, 19});
MotorGroup rightDrive({16, 17, 18});

Motor lift(15, false, AbstractMotor::gearset::green, AbstractMotor::encoderUnits::degrees);

//change port
Motor roller(8, false, AbstractMotor::gearset::blue, AbstractMotor::encoderUnits::degrees); 

// SENSORS - check ports & rotation
ADIEncoder trackLeft({14, 'A', 'B'}, false);
ADIEncoder trackRight({14, 'C', 'D'}, false);
ADIEncoder trackMiddle({14, 'E', 'F'}, false);

RotationSensor liftSensor(5, false); //check port

// PNEUMATICS
Pneumatic mogoLeft({{14, 'G'}});
Pneumatic mogoRight({{14, 'H'}});

Pneumatic claw('A'); //check port

