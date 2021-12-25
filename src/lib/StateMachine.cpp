#include "main.h"

template<typename State, State initState>
StateMachine<State, initState>::StateMachine(){
    state = initState;
}

template<typename State, State initState>
State StateMachine<State, initState>::getState(){
    stateLock.take();
    State currentState = state;
    stateLock.give();
    return currentState;
}

template<typename State, State initState>
void StateMachine<State, initState>::setState(State iState){
    stateLock.take();
    state = iState;
    stateLock.give();
}