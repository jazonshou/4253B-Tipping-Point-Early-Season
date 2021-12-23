#pragma once
#include "main.h"
/*
class AsyncProfileFollower{
    public:
    AsyncProfileFollower(const std::shared_ptr<ChassisController>& iChassis, const std::shared_ptr<LinearMotionProfile>& iProfiler){
        chassis = std::move(iChassis);
        profiler = std::move(iProfiler);

    }

    void followPath(Trajectory& path){
        target = path;
        state = FOLLOW;
        timeElapsed = 0;
        isEnabled = true;
        chassis->getModel()->
    }

    void moveDistance(QLength distance){
        profiler->setDistance(distance);
        state = MOVE;
        timeElapsed = 0;
        isEnabled = true;
    }

    void turnAngle(QAngle angle){
        profiler->setDistance((chassis->getChassisScales().wheelTrack) * angle.convert(radian) / 2);
        state = TURN;
        timeElapsed = 0;
        isEnabled = true;
    }

    void waitUntilSettled(){
        while(isEnabled){
            pros::delay(10);
        }
    }

    protected:

    enum State{
        MOVE, TURN, FOLLOW
    };

    void loop(){
        if(isEnabled){
            TrajectoryPoint pt;
            if(state == MOVE){
                pt = profiler->get(timeElapsed * second);
            }
            else if(state == TURN){
                pt = profiler->get(timeElapsed * second);
            }
            else{
                pt = target[timeElapsed*100];
            }

            double leftEncoderPos = std::static_cast<SkidSteerModel>(chassis->getModel())->getPosition();
            chassis->tank();

            timeElapsed += 0.01;
        }
    }

    CrossplatformThread* task;
    double timeElapsed; 
    std::shared_ptr<ChassisController> chassis;
    std::shared_ptr<LinearMotionProfile> profiler;
    State state;
    bool isEnabled;
    Trajectory target;


};
*/