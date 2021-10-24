#include "main.h"

void genSkills(){}

void skills(){
    chassis->setState({0_in, 0_in, 0_deg});
}

void genRedLeft(){
    profiler->generatePath({{0_in, 0_in, 0_deg}, {3_in, 0_in, 0_deg}}, "COCK");
}

void redLeft(){
    chassis->setState({0_in, 0_in, 0_deg});
    profiler->setTarget("COCK");
    profiler->waitUntilSettled();

    turnToAngle(90_deg);
}

void genRedRight(){}

void redRight(){
    chassis->setState({0_in, 0_in, 0_deg});
}

void genBlueLeft(){}

void blueLeft(){
    chassis->setState({0_in, 0_in, 0_deg});
}

void genBlueRight(){}

void blueRight(){
    chassis->setState({0_in, 0_in, 0_deg});
}

void genAwp(){}

void awp(){
    chassis->setState({0_in, 0_in, 0_deg});
}