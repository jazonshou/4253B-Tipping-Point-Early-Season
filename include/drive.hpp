#pragma once
#include"main.h"

std::pair<double, double> curvatureDrive(double moveC, double turnC, bool quickTurn);

void turnToAngle(okapi::QAngle targetAngle);