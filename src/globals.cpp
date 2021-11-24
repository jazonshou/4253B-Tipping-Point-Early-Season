#include "main.h"

// CONTROLLER
Controller master(ControllerId::master); 

// MOTORS
Motor leftTop(1, false, AbstractMotor::gearset::blue, AbstractMotor::encoderUnits::degrees);
Motor leftMiddle(2, true, AbstractMotor::gearset::blue, AbstractMotor::encoderUnits::degrees);
Motor leftBottom(3, false, AbstractMotor::gearset::blue, AbstractMotor::encoderUnits::degrees);
Motor rightTop(10, true, AbstractMotor::gearset::blue, AbstractMotor::encoderUnits::degrees);
Motor rightMiddle(9, false, AbstractMotor::gearset::blue, AbstractMotor::encoderUnits::degrees);
Motor rightBottom(8, true, AbstractMotor::gearset::blue, AbstractMotor::encoderUnits::degrees);
MotorGroup leftDrive({leftTop, leftMiddle, leftBottom});
MotorGroup rightDrive({rightTop, rightMiddle, rightBottom});
Motor lift(5, true, AbstractMotor::gearset::green, AbstractMotor::encoderUnits::degrees);
// pros::Motor lift(5, true);
// Motor roller(8, false, AbstractMotor::gearset::blue, AbstractMotor::encoderUnits::degrees); // TODO - Change Port

// SENSORS
ADIEncoder trackLeft({14, 'A', 'B'}, false); // TODO - Change Port, reverse?
ADIEncoder trackRight({14, 'C', 'D'}, false); // TODO - Change Port, reverse?
ADIEncoder trackMiddle({14, 'E', 'F'}, false); // TODO - Change Port, reverse?
RotationSensor liftSensor(4, false); // TODO - Change Port, reverse?
RotationSensor mogoSensor(15, false);
IMU imu(6);

// PNEUMATICS
// Pneumatic mogo('C');
Motor mogo(16, false, AbstractMotor::gearset::red, AbstractMotor::encoderUnits::degrees); //TODO - port?
// pros::Motor mogo(20, true);
Pneumatic claw('C'); // TODO - Change Port
Pneumatic wings('B');

// SUBSYSTEM CONTROLLERS
std::shared_ptr<OdomChassisController> chassis = ChassisControllerBuilder()
	.withMotors(leftDrive, rightDrive)
	.withDimensions({AbstractMotor::gearset::blue, 5.0/3.0}, {{3.25_in, 38.5_cm}, imev5BlueTPR}) // TODO - Change Track Width
	// .withSensors(trackLeft, trackRight, trackMiddle)
	// .withOdometry({{2.75_in, 6.25_in}, quadEncoderTPR}) // TODO - Change Track Width
    .withOdometry()
	.buildOdometry();
    // .build();

std::shared_ptr<AsyncMotionProfileController> profiler = AsyncMotionProfileControllerBuilder()
    .withLimits({ // TODO - Tune Max Robot Velocity / Acceleration
        1.5, // Maximum linear velocity of the Chassis in m/s
        4.0, // Maximum linear acceleration of the Chassis in m/s/s
        6.0 // Maximum linear jerk of the Chassis in m/s/s/s
    })
    .withOutput(chassis)
    .buildMotionProfileController();

// std::shared_ptr<AsyncPositionController<double, double>> liftController = AsyncPosControllerBuilder()
//     .withMotor(lift)
//     .withGains({0.035, 0.0, 0.0005}) // TODO - Slightly tune constant
//     .withSensor(std::make_shared<okapi::RotationSensor>(liftSensor))
//     .build();

// std::shared_ptr<AsyncPositionController<double, double>> rollerController = AsyncPosControllerBuilder()
//     .withMotor(roller)
//     .withGains({0.01, 0.001, 0.0000})
//     .withSensor(std::make_shared<okapi::RotationSensor>(liftSensor))
//     .build();

std::shared_ptr<AsyncPositionController<double, double>> mogoController = AsyncPosControllerBuilder()
    .withMotor(mogo)
    .withGains({0.015, 0.0001, 0.0005}) // 0.0225, 0.0, 0.0005
    .withSensor(std::make_shared<okapi::RotationSensor>(mogoSensor))
    .build();


std::shared_ptr<IterativePosPIDController> turnPID = std::make_shared<IterativePosPIDController>(0.025, 0, 0, 0, TimeUtilFactory::withSettledUtilParams(2, 2, 100_ms)); // #TODO - Tune Constant


// AUTONOMOUS CONTROLLER
int selectedAuton = 1;
std::map<int, std::function<void()>> auton;
std::map<int, std::function<void()>> path;

