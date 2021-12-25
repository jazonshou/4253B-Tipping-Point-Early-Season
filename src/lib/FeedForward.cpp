#include "main.h"

FFVelocityController::FFVelocityController(double ikV, double ikAU, double ikAD, double ikP_Pos, double ikP_Vel){
    kV = ikV, kA_Up = ikAU, kA_Down = ikAD, kP_Pos = ikP_Pos, kP_Vel = ikP_Vel;
}

double FFVelocityController::step(double position, double velocity, double acceleration, double currentPos, double currentRPM){
    currPos = Math::tickToFt(currentPos);
    currVel = Math::rpmToFtps(currentRPM);

    if(acceleration > 0){
        return power = (kV * velocity + kA_Up * acceleration + kP_Pos * (position - currPos) + kP_Vel * (velocity - currVel));
    }
    else{
        return power = (kV * velocity + kA_Down * acceleration + kP_Pos * (position - currPos) + kP_Vel * (velocity - currVel));
    }
}

double FFVelocityController::getTargetPower() const{
    return power;
}

