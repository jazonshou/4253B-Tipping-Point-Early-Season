#pragma once
#include "main.h"

/**
 * @brief The following class contains the route & all the paths
 *        for our skills auton. 
 * 
 */

class Skills {
    public:
    // back mogo down
    // path0 - 1.5 ft back
    // static std::vector<std::vector<double>> path0Left;
    // static std::vector<std::vector<double>> path0Right;
    static Trajectory path1Left;
    // back mogo up async (short delay???)
    // path1 - left neutral mogo, front facing north
    // static std::vector<std::vector<double>> path1Left;
    // static std::vector<std::vector<double>> path1Right;
    // claw down
    // lift up async 
    // path2 - to platform
    static Trajectory path2Left;
    // static std::vector<std::vector<double>> path2Left;
    // static std::vector<std::vector<double>> path2Right;
    // claw up
    // back mogo down async 
    // path3 - back, front facing west
    static Trajectory path3Left;
    // static std::vector<std::vector<double>> path3Left;
    // static std::vector<std::vector<double>> path3Right;

    // static std::vector<std::vector<double>> backLeft;
    // static std::vector<std::vector<double>> backRight;
    // lift down async
    // path4 - collects left blue mogo
    static Trajectory path4Left;
    // static std::vector<std::vector<double>> path4Left;
    // static std::vector<std::vector<double>> path4Right;
    // claw down
    // lift up mid async
    // path5 - collects mid neutral mogo, front facing 45 deg (NW)
    static Trajectory path5Left;
    // static std::vector<std::vector<double>> path5Left;
    // static std::vector<std::vector<double>> path5Right;
    // back mogo up async
    // path6 - deport mogo to right bottom corner
    static Trajectory path6Left;
    // static std::vector<std::vector<double>> path6Left;
    // static std::vector<std::vector<double>> path6Right;
    // back mogo down - wait till settled 

    static Trajectory path7Left;

    static Trajectory path8Left;

    static Trajectory path9Left;

    static Trajectory path10Left;

};