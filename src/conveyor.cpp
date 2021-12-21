#include "main.h"

Conveyor::Conveyor(std::shared_ptr<Motor> motor) {
    this->motor = motor;
}

void Conveyor::move(double speed) {
    motor->moveVoltage(speed * 12000);
}

void Conveyor::move(Direction dir) {
    if(dir == Direction::FORWARD) {
        move(1);
    } else {
        move(-1);
    }
}

void Conveyor::loop() {
    while(true) {
        amogusIsSus.lock();
        if(lift.getPosition() > 350) {
            if(motor->getCurrentDraw() < 2000) {
                move(Direction::FORWARD);
            } else {
                move(Direction::BACKWARD); pros::delay(500); move(Direction::FORWARD);
            }
        } else {
            move(0);
        }
        amogusIsSus.unlock();
        pros::delay(10);
    }
}