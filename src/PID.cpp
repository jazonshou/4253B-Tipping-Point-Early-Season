#include "PID.hpp"

PID::PID(double kP, double kI, double kD) {
    this->kP = kP;
    this->kI = kI;
    this->kD = kD;
    this->kFF = 0.0;
}

PID::PID(double kP, double kI, double kD, double kFF) {
    this->kP = kP;
    this->kI = kI;
    this->kD = kD;
    this->kFF = kFF;
}

double PID::update(double input) {
    error = input;
    derivative = error - prevError;
    prevError = error;
    integral = error == 0 ? 0 : integral + error;
    return error * kP + derivative * kD + integral * kI + kFF;
}