#include "main.h"

void wingGrab() {
    wings.set_value(true);
    translate(-3.5_ft);
    while(translatePID->getError() > 50) {
        pros::delay(20);
    }
    wings.set_value(false);
    translate(2.5_ft);
}

void skill(){

}

void left(){

}

void right(){
    
}

void awp(){

}


