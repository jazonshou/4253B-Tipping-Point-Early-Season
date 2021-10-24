#include "main.h"

// CONTROLLER
Controller master(ControllerId::master); 

// MOTORS - check rotation
MotorGroup leftDrive({4, -5, 6});
MotorGroup rightDrive({-7, 8, -9});

Motor lift(10, true, AbstractMotor::gearset::green, AbstractMotor::encoderUnits::degrees);

//change port
// Motor roller(8, false, AbstractMotor::gearset::blue, AbstractMotor::encoderUnits::degrees); 

// SENSORS - check ports & rotation
ADIEncoder trackLeft({14, 'A', 'B'}, false);
ADIEncoder trackRight({14, 'C', 'D'}, false);
ADIEncoder trackMiddle({14, 'E', 'F'}, false);

RotationSensor liftSensor(20, false); //check port

// PNEUMATICS
// Pneumatic mogoLeft({{14, 'G'}});
// Pneumatic mogoRight({{14, 'H'}});
Pneumatic mogo('C');

Pneumatic claw('D'); //check port

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


int selectedAuton = 0;

std::map<int, std::function<void()>> auton;
std::map<int, std::function<void()>> path;