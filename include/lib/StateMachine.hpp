#pragma once
#include "main.h"

template<typename State, State initState = State::IDLE>
class StateMachine{
    private:
    State state = initState;
    pros::Mutex stateLock;

    public:
    State getState();
    void setState(State iState);
};