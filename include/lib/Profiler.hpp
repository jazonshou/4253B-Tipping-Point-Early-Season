#pragma once
#include "main.h"

enum class MotionProfileState{
    MOVE, FOLLOW, IDLE
};

template class StateMachine<MotionProfileState>;

class AsyncMotionProfiler : public StateMachine<MotionProfileState, MotionProfileState::IDLE>, public TaskWrapper{
    protected:
    AsyncMotionProfiler(std::shared_ptr<ChassisController> iChassis, 
                        std::unique_ptr<LinearMotionProfile> iMove, 
                        std::unique_ptr<FFVelocityController> iLeftLinear, 
                        std::unique_ptr<FFVelocityController> iRightLinear,
                        std::unique_ptr<FFVelocityController> iLeftTrajectory,
                        std::unique_ptr<FFVelocityController> iRightTrajectory,
                        const TimeUtil& iTimeUtil);

    void operator=(const AsyncMotionProfiler& rhs) = delete;

    friend class AsyncMotionProfilerBuilder;
    std::shared_ptr<ChassisController> chassis;
    std::shared_ptr<AbstractMotor> leftMotor;
    std::shared_ptr<AbstractMotor> rightMotor;

    std::unique_ptr<LinearMotionProfile> profiler;
    std::unique_ptr<FFVelocityController> leftLinear;
    std::unique_ptr<FFVelocityController> rightLinear;
    std::unique_ptr<FFVelocityController> leftTrajectory;
    std::unique_ptr<FFVelocityController> rightTrajectory;

    TimeUtil timeUtil;
    std::unique_ptr<AbstractRate> rate;
    std::unique_ptr<AbstractTimer> timer;
    QTime maxTime{0.0};

    Trajectory path;
    pros::Mutex lock;

    public:

    void setTarget(QLength iDistance);

    void setTarget(const Trajectory& iPath);

    void stop();

    void loop() override;

    void waitUntilSettled();
};

class AsyncMotionProfilerBuilder{
    public:
    AsyncMotionProfilerBuilder();
    ~AsyncMotionProfilerBuilder() = default;

    AsyncMotionProfilerBuilder& withOutput(std::shared_ptr<ChassisController> iChassis);

    AsyncMotionProfilerBuilder& withProfiler(std::unique_ptr<LinearMotionProfile> iProfiler);

    AsyncMotionProfilerBuilder& withLinearController(FFVelocityController iLeft, FFVelocityController iRight);

    AsyncMotionProfilerBuilder& withTrajectoryController(FFVelocityController iLeft, FFVelocityController iRight);

    std::shared_ptr<AsyncMotionProfiler> build();

    private:
    std::unique_ptr<LinearMotionProfile> profile;
    std::shared_ptr<ChassisController> chassis;
    FFVelocityController leftL;
    FFVelocityController rightL;
    FFVelocityController leftT;
    FFVelocityController rightT;

    bool linearInit = false;
    bool trajInit = false;
    bool driveInit = false;
    bool profileInit = false;
};