#pragma once
#include "main.h"
/*
class OdomDimension{
    public:
    QLength wheelDiameter{0 * inch};
    QLength lDist{0 * inch}, mDist{0 * inch}, rDist{0 * inch};
    double tpr;

    OdomDimension(const QLength& wheelDiam, const QLength& leftOffset, const QLength& midOffset, const QLength& rightOffset);
    OdomDimension(const QLength& wheelDiam, const QLength& offset1, const QLength& offset2);
    ~OdomDimension() = default;
};




class Odometry: public TaskWrapper{
    protected:
    OdomState globalPos{0_m, 0_m, 0_rad}; // the global position of the robot
    OdomDimension dimension{-1_in, -1_in, -1_in, -1_in};
    pros::Mutex lock;

    public:
    Odometry() = default;
    virtual ~Odometry() = default;
    
    OdomState getPos() const; // return current position as a struct
    QLength getX() const; // return x position as type QLength
    QLength getY() const; // return y position in type QLength
    QAngle getAngle() const; // return angle in radians

    virtual double getEncoderLeft() const; // gets the left encoder reading
    virtual double getEncoderRight() const; // gets the right encoder reading
    virtual double getEncoderMid() const; // gets the mid encoder reading
    virtual double getEncoderSide() const; // gets the side encoder reading

    void setPos(const OdomState& newPos); // sets the current position
    void setX(const QLength& inch); // sets the x position of the robot
    void setY(const QLength& inch); // sets the y position of the robot
    void setAngle(const QAngle& theta); // sets the angle of the robot

    void displayPosition() const; // outputs the x, y, angle of the robot on the robot screen and the console

    void resetState();
    virtual void resetSensors() = 0;
    void reset();
};

// Odometry using 3 encoders - 2 parallel to drive and one perpendicular
class ThreeWheelOdometry : public ::Odometry{
    private:
    void loop() override; // updates position based on encoder values
    double lVal{0}, mVal{0}, rVal{0}; // readings from the left, middle and right encoders
    double lPrev{0}, mPrev{0}, rPrev{0}; // previous reading from the left, middle and right encoders
    std::shared_ptr<ContinuousRotarySensor> left{nullptr}, mid{nullptr}, right{nullptr}; // the 3 encoders

    public:
    ThreeWheelOdometry(const std::shared_ptr<ContinuousRotarySensor>& l, const std::shared_ptr<ContinuousRotarySensor>& m, const std::shared_ptr<ContinuousRotarySensor>& r, const OdomDimension& dim); // constructor    
    ~ThreeWheelOdometry() = default;
    void resetSensors() override; // reset sensors
    double getEncoderLeft() const override; // gets reading from the left encoder
    double getEncoderRight() const override; // gets reading from the right encoder
    double getEncoderMid() const override; // gets reading fom the middle encoder
};

// Odometry using 2 encoder that are perpendicular to each other, as well as an imu to gather angle information
class TwoWheelIMUOdometry:public ::Odometry{
    private:
    void loop() override;  // updates position based on encoder values
    double mVal{0}, sVal{0}, aVal{0}; // readings from the side, middle encoder + imu sensor
    double mPrev{0}, sPrev{0}, aPrev{0}; // previous readings from the side, middle encoder + imu sensor
    std::shared_ptr<ContinuousRotarySensor> side{nullptr}, mid{nullptr};
    std::shared_ptr<IMU> inertial{nullptr};

    public:
    TwoWheelIMUOdometry(const std::shared_ptr<ContinuousRotarySensor>& s, const std::shared_ptr<ContinuousRotarySensor>& m, const std::shared_ptr<IMU>& imu, const OdomDimension& dim); // constructor
    TwoWheelIMUOdometry() = default;

    void resetSensors() override; // reset sensors
    double getEncoderSide() const override; // gets reading from the side encoder
    double getEncoderMid() const override; // gets reading from the middle encoder
};

class TwoWheelOdometry : public ::Odometry{
    private:
    void loop() override;  // updates position based on encoder values
    double lVal{0}, rVal{0}; // readings from the side, middle encoder + imu sensor
    double lPrev{0}, rPrev{0}; // previous readings from the side, middle encoder + imu sensor
    std::shared_ptr<ContinuousRotarySensor> left{nullptr}, right{nullptr};

    public:
    TwoWheelOdometry(const std::shared_ptr<ContinuousRotarySensor>& l, const std::shared_ptr<ContinuousRotarySensor>& r, const OdomDimension& dim); // constructor
    ~TwoWheelOdometry() = default;

    void resetSensors() override; // reset sensors
    double getEncoderLeft() const override; // gets reading from the side encoder
    double getEncoderRight() const override; // gets reading from the middle encoder
};
*/
