#include "main.h"

Conveyor::Conveyor(const std::shared_ptr<Motor>& motor) {
    this->motor = std::move(motor);
}

void Conveyor::loop() {
    while(true) {
        if(lift.getPosition() > 350) {
            if(motor->getActualVelocity() > 50) {
                motor->moveVoltage(12000);
            } else {
                motor->moveVoltage(-12000);
                pros::delay(1000);
                motor->moveVoltage(12000);
                pros::delay(1000);
            }
        } else {
            motor->moveVoltage(0);;
        }
        pros::delay(10);
    }
}

