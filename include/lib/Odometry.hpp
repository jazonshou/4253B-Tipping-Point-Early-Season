#pragma once
#include "main.h"

/**
 * @brief Tracking wheel dimensions used for odometry
 * 
 */
class OdomDimension{
    public:
    QLength wheelDiameter{0 * inch};
    QLength lDist{0 * inch}, mDist{0 * inch}, rDist{0 * inch};
    double tpr;

    OdomDimension(QLength wheelDiam, QLength leftOffset, QLength midOffset, QLength rightOffset);
    OdomDimension(QLength wheelDiam, QLength offset1, QLength offset2);
    ~OdomDimension() = default;
};

/**
 * @brief Odometry is essentially an algorithm that acts as a sensor. By using small free spinning wheel called "tracking wheels", 
 *        We are able to calculate the robot's global position by approximating the robot's movement into infinitely many small arcs, 
 *        and then integraing the dx and dy of each arc. This is an abstract class which allows us to reduce boilerplate and easily
 *        implement different kinds of odometry
 * 
 */
class Odometry: public TaskWrapper{
    protected:
    OdomState globalPos{0_m, 0_m, 0_rad}; // the global position of the robot
    OdomDimension dimension{-1_in, -1_in, -1_in, -1_in};
    pros::Mutex lock;

    /**
     * @brief Task loop that updates global position based on encoder reading
     *        What the loop does is dependent on each derived class
     * 
     */
    virtual void loop() = 0;

    public:
    /**
     * @brief Construct a new Odometry object
     * 
     */
    Odometry() = default;
    
    /**
     * @brief Destroy the Odometry object
     * 
     */
    virtual ~Odometry() = default;
    
    /**
     * @brief gets the global position
     * 
     * @return OdomState the global position in form (x, y, theta)
     */
    OdomState getPos() const;

    /**
     * @brief gets the global x position
     * 
     * @return QLength global x position
     */
    QLength getX() const;

    /**
     * @brief gets the global y position
     * 
     * @return QLength global y position
     */
    QLength getY() const;

    /**
     * @brief gets the global angle position
     * 
     * @return QLength global angle position
     */
    QAngle getAngle() const;

    /**
     * @brief Get the left encoder reading
     * 
     * @return double left encoder reading
     */
    virtual double getEncoderLeft() const;

    /**
     * @brief Get the right encoder reading
     * 
     * @return double right encoder reading
     */
    virtual double getEncoderRight() const;

    /**
     * @brief Get the mid encoder reading
     * 
     * @return double mid encoder reading
     */
    virtual double getEncoderMid() const;

    /**
     * @brief Get the side encoder reading
     * 
     * @return double s9de encoder reading
     */
    virtual double getEncoderSide() const;

    /**
     * @brief Set the global position
     * 
     * @param iPos new global position in form (x, y, theta)
     */
    void setPos(OdomState iPos);

    /**
     * @brief Set the global x position
     * 
     * @param iX new global x position
     */
    void setX(QLength iX);

    /**
     * @brief Set the global y position
     * 
     * @param iY new global y position
     */
    void setY(QLength iY);

    /**
     * @brief Set the global angle
     * 
     * @param iTheta new global angle
     */
    void setAngle(QAngle iTheta);

    /**
     * @brief prints the current x, y, and angle of the robot
     * 
     */
    void displayPosition() const;

    /**
     * @brief resets the current global position to (0, 0, 0)
     * 
     */
    void resetState();

    /**
     * @brief Resets all sensors
     * 
     */
    virtual void resetSensors() = 0;

    /**
     * @brief Resets both global position and sensors
     * 
     */
    void reset();
};

/**
 * @brief Odometry using 3 encoders - 2 parallel to drive and one perpendicular
 *        Since most of the functions are inherited from the Odometry class, description
 *        of overridden functions will be omitted
 * 
 */
class ThreeWheelOdometry : public ::Odometry{
    private:
    void loop() override;
    double lVal{0}, mVal{0}, rVal{0};
    double lPrev{0}, mPrev{0}, rPrev{0};
    std::shared_ptr<ContinuousRotarySensor> left{nullptr}, mid{nullptr}, right{nullptr};

    public:
    /**
     * @brief Construct a new Three Wheel Odometry object
     * 
     * @param l left Sensor
     * @param m middle Sensor
     * @param r right Sensor
     * @param dim Odometry dimensions
     */
    ThreeWheelOdometry(std::shared_ptr<ContinuousRotarySensor> l, std::shared_ptr<ContinuousRotarySensor> m, std::shared_ptr<ContinuousRotarySensor> r, OdomDimension dim);

    /**
     * @brief Destroy the Three Wheel Odometry object
     * 
     */
    ~ThreeWheelOdometry() = default;
    void resetSensors() override;
    double getEncoderLeft() const override;
    double getEncoderRight() const override;
    double getEncoderMid() const override;
};

/**
 * @brief Odometry using 2 encoder that are perpendicular to each other, as well as an imu to gather angle information
 *        Since most of the functions are inherited from the Odometry class, description of overridden functions will be omitted
 * 
 */
class TwoWheelIMUOdometry:public ::Odometry{
    private:
    void loop() override;
    double mVal{0}, sVal{0}, aVal{0};
    double mPrev{0}, sPrev{0}, aPrev{0};
    std::shared_ptr<ContinuousRotarySensor> side{nullptr}, mid{nullptr};
    std::shared_ptr<IMU> inertial{nullptr};

    public:
    /**
     * @brief Construct a new Two Wheel I M U Odometry object
     * 
     * @param s side encoder
     * @param m middle encoder
     * @param imu inertial sensor
     * @param dim odometry dimensions
     */
    TwoWheelIMUOdometry(std::shared_ptr<ContinuousRotarySensor> s, std::shared_ptr<ContinuousRotarySensor> m, std::shared_ptr<IMU> imu, OdomDimension dim);

    /**
     * @brief Destroys a new Two Wheel IMU Odometry object
     * 
     */
    ~TwoWheelIMUOdometry() = default;

    void resetSensors() override;
    double getEncoderSide() const override; 
    double getEncoderMid() const override; 
};

/**
 * @brief Odometry using two wheels that are parallel to each other. Note that sideways movement is not accounted for
 *        Since most of the functions are inherited from the Odometry class, description of overridden functions will be omitted
 */
class TwoWheelOdometry : public ::Odometry{
    private:
    void loop() override; 
    double lVal{0}, rVal{0};
    double lPrev{0}, rPrev{0}; 
    std::shared_ptr<ContinuousRotarySensor> left{nullptr}, right{nullptr};

    public:
    /**
     * @brief Construct a new Two Wheel Odometry object
     * 
     * @param l left encoder
     * @param r right encoder
     * @param dim odometry dimensions
     */
    TwoWheelOdometry(std::shared_ptr<ContinuousRotarySensor> l, std::shared_ptr<ContinuousRotarySensor> r, OdomDimension dim);

    /**
     * @brief Destroy the Two Wheel Odometry object
     * 
     */
    ~TwoWheelOdometry() = default;

    void resetSensors() override;
    double getEncoderLeft() const override; 
    double getEncoderRight() const override; 
};

