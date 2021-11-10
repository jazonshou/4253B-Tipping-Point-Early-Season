#pragma once
#include"main.h"

enum class Side {
    LEFT, RIGHT
};

    void setBrakeMode(AbstractMotor::brakeMode brakeMode);

    void setVelocity(double l, double r);

    /**
     * @brief Computes the desired drive speed to control the chassis using curvature control
     *        The turn power is scaled with the linear power in order to allow finer control
     *        of the chassis.
     * 
     * @param moveC - the desired linear speed for the robot to move in, normalized to [-1, 1]
     * @param turnC - the desired curvature for the robot to move in, normalized to [-1, 1]
     * @param quickTurn - when this parameter is set to true, arcade control is used instead to allow point turn
     * 
     * @return the desired left and right velocity for the chassis motors to move in, normalized to [-1, 1]
     */
    std::pair<double, double> curvatureDrive(double moveC, double turnC, bool quickTurn);

    /**
     * @brief Turns the robot to the desired global angle (using closed-loop control)
     * 
     * @param targetAngle - the target odometry global angle to turn to, normalized to [-2pi, 2pi]
     */
    void turnToAngle(okapi::QAngle targetAngle);

    /**
     * @brief This is our custom velocity controller. Although the motor has decent internal
     *        PID velocity control, through our testing, we realized that it still is not 
     *        as precise as this custom velocity controller. Yet due to time constraints, 
     *        we did not have enough to time to individually tune our motors, and thus, we 
     *        stuck with using the motor's internal velocity controller. 
     * 
     *        The reason why we even have this is because our drive's movement in auton heavily 
     *        relies on 2D motion profiles. There is lots of complicated math behind it, but in
     *        a sense, we create a smooth trajectory for our robot to follow and convert it to 
     *        actual drive velocity that our robot follows for every 10 ms. As a result, the 
     *        how precise our auton is heavily relies on how well the velocity control of our 
     *        motors are. 
     * 
     * @param velocity desired velocity
     * @param accel desired acceleration
     * @param currSpeed current speed of the motor(s)
     * @return output for the motor(s)
     */
    double velControl(double velocity, double accel, double currSpeed);

    /**
     * @brief The trajectory generator we use outputs linear velocity (ft/s). In order for us to 
     *        make use of that, we must convert the linear velocity to RPM, which the motors follow. 
     *        Although there are much more mathematical ways of making this conversion (such as 
     *        recording the wheel size, gear ratio, and motor speed, and using those values to 
     *        convert) we decided to use a much simpler method of calculating ratios. Since the 
     *        maximum motor RPM (for our drive) is 600 RPM and the maximum linear velocity is 
     *        4.92126 ft/s, we can use simple ratios to convert the desired linear velocity to RPM. 
     * 
     * @param path 2D vector of linear velocity
     * @return vector of RPM
     */
    std::vector<double> pathToRPM(std::vector<std::vector<double>> path);

    /**
     * @brief This is the function which actually makes the robot drive. followPath receives inputs 
     *        of the desired left and right velocites and feeds it to the drive motor to follow
     *        the desired path. 
     * 
     * @param leftVel 2D vector of left velocity
     * @param rightVel 2D vector of right velocity
     */
    void followPath(std::vector<std::vector<double>> leftVel, std::vector<std::vector<double>> rightVel);

