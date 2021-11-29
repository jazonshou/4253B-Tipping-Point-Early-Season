#pragma once
#include "main.h"

struct  TrajectoryPoint{
    TrajectoryPoint() = default;

    ~TrajectoryPoint() = default;
    
    TrajectoryPoint(double, double, double, double, double, double);

    double leftPosition, rightPosition, leftVelocity, leftAcceleration, rightVelocity, rightAcceleration;
};

using Trajectory = std::vector<TrajectoryPoint>;