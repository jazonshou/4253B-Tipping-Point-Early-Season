#include "StateMachine.hpp"

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