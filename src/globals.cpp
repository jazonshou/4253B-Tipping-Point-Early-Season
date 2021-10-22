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

// CONTROLLERS
std::shared_ptr<OdomChassisController> chassis = ChassisControllerBuilder()
	.withMotors(leftDrive, rightDrive)
	.withDimensions({AbstractMotor::gearset::blue, 5.0/30}, {{3.25_in, 12.25_in}, imev5BlueTPR}) // Drop Center Wheels
	.withSensors(trackLeft, trackRight, trackMiddle)
	.withOdometry({{2.75_in, 6.25_in}, quadEncoderTPR})
	.buildOdometry();

std::shared_ptr<AsyncMotionProfileController> profiler = AsyncMotionProfileControllerBuilder()
    .withLimits({
        1.0, // Maximum linear velocity of the Chassis in m/s
        2.0, // Maximum linear acceleration of the Chassis in m/s/s
        10.0 // Maximum linear jerk of the Chassis in m/s/s/s
    })
    .withOutput(chassis)
    .buildMotionProfileController();

std::shared_ptr<AsyncPositionController<double, double>> liftController =  AsyncPosControllerBuilder()
    .withMotor(lift) // Lift Motor: Port 7
    .withGains({0.001, 0.001, 0.0000}) // kP, kI, kD
    .withSensor(std::make_shared<okapi::RotationSensor>(liftSensor))
    .build();

std::shared_ptr<IterativePosPIDController> turnPID = std::make_shared<IterativePosPIDController>(0, 0, 0, 0, TimeUtilFactory::withSettledUtilParams(2, 2, 100_ms));


