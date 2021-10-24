#include "main.h"

// CONTROLLER
Controller master(ControllerId::master); 

// MOTORS
MotorGroup leftDrive({4, -5, 6});
MotorGroup rightDrive({-7, 8, -9});
Motor lift(10, true, AbstractMotor::gearset::green, AbstractMotor::encoderUnits::degrees);
// Motor roller(8, false, AbstractMotor::gearset::blue, AbstractMotor::encoderUnits::degrees); // TODO - Change Port

// SENSORS
ADIEncoder trackLeft({14, 'A', 'B'}, false); // TODO - Change Port, reverse?
ADIEncoder trackRight({14, 'C', 'D'}, false); // TODO - Change Port, reverse?
ADIEncoder trackMiddle({14, 'E', 'F'}, false); // TODO - Change Port, reverse?
RotationSensor liftSensor(20, false); // TODO - Change Port, reverse?

// PNEUMATICS
Pneumatic mogo('C');
Pneumatic claw('D'); // TODO - Change Port

// SUBSYSTEM CONTROLLERS
auto chassis = ChassisControllerBuilder()
	.withMotors(leftDrive, rightDrive)
	.withDimensions({AbstractMotor::gearset::blue, 5.0/3.0}, {{3.25_in, 12.25_in}, imev5BlueTPR}) // TODO - Change Track Width
	.withSensors(trackLeft, trackRight, trackMiddle)
	.withOdometry({{2.75_in, 6.25_in}, quadEncoderTPR}) // TODO - Change Track Width
	.buildOdometry();

auto profiler = AsyncMotionProfileControllerBuilder()
    .withLimits({ // TODO - Tune Max Robot Velocity / Acceleration
        1.0, // Maximum linear velocity of the Chassis in m/s
        2.0, // Maximum linear acceleration of the Chassis in m/s/s
        10.0 // Maximum linear jerk of the Chassis in m/s/s/s
    })
    .withOutput(chassis)
    .buildMotionProfileController();

auto liftController =  AsyncPosControllerBuilder()
    .withMotor(lift)
    .withGains({0.01, 0.001, 0.0000}) // TODO - Slightly tune constant
    .withSensor(std::make_shared<okapi::RotationSensor>(liftSensor))
    .build();

auto turnPID = std::make_shared<IterativePosPIDController>(0, 0, 0, 0, TimeUtilFactory::withSettledUtilParams(2, 2, 100_ms)); // #TODO - Tune Constant


// AUTONOMOUS CONTROLLER
int selectedAuton = 0;
std::map<int, std::function<void()>> auton;
std::map<int, std::function<void()>> path;

