#pragma once
#include "main.h"

class FFVelocityController;
template<typename State, State initState> class StateMachine;
class AsyncMotionProfilerBuilder;

enum class MotionProfileState{
    MOVE, TURN, FOLLOW, IDLE
};
template class StateMachine<MotionProfileState>;

class AsyncMotionProfiler : public StateMachine<MotionProfileState, MotionProfileState::IDLE>, public TaskWrapper{
    protected:
    AsyncMotionProfiler(std::shared_ptr<ChassisController> iChassis, 
                        std::unique_ptr<LinearMotionProfile> iMove, 
                        std::unique_ptr<FFVelocityController> iLeftController, 
                        std::unique_ptr<FFVelocityController> iRightController,
                        const TimeUtil& iTimeUtil);

    void operator=(const AsyncMotionProfiler& rhs) = delete;

    friend class AsyncMotionProfilerBuilder;
    std::shared_ptr<ChassisController> chassis;
    std::shared_ptr<AbstractMotor> leftMotor;
    std::shared_ptr<AbstractMotor> rightMotor;

    std::unique_ptr<LinearMotionProfile> profiler;
    std::unique_ptr<FFVelocityController> leftVelController;
    std::unique_ptr<FFVelocityController> rightVelController;

    TimeUtil timeUtil;
    std::unique_ptr<AbstractRate> rate;
    std::unique_ptr<AbstractTimer> timer;
    QTime maxTime{0.0};

    Trajectory path;
    pros::Mutex lock;

    public:

    void moveDistance(QLength iDistance);

    void turnAngle(QAngle iAngle);

    void followPath(const Trajectory& iPath);

    void stop();

    void loop() override;

    void waitUntilSettled();
};

class AsyncMotionProfilerBuilder{
    public:
    AsyncMotionProfilerBuilder();

    AsyncMotionProfilerBuilder& withOutput(std::shared_ptr<ChassisController> iChassis);

    AsyncMotionProfilerBuilder& withProfiler(std::unique_ptr<LinearMotionProfile> iProfiler);

    AsyncMotionProfilerBuilder& withVelocityController(FFVelocityController iLeft, FFVelocityController iRight);

    std::unique_ptr<AsyncMotionProfiler> build();

    private:
    std::unique_ptr<LinearMotionProfile> profile;
    std::shared_ptr<ChassisController> chassis;
    FFVelocityController left;
    FFVelocityController right;

    bool velInit = false;
    bool driveInit = false;
    bool profileInit = false;
};