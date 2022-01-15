#include "main.h"

LazyPneumatics::LazyPneumatics(char iPort, bool initState):piston(iPort), state(initState){
    piston.set_value(state);
}

void LazyPneumatics::toggle(){
    state = !state;
    piston.set_value(state);
}

void LazyPneumatics::set(bool iState){
    state = iState;
    piston.set_value(iState);
}