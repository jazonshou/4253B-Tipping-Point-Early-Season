#include "Math.hpp"
#include <cmath>

// vel (ft/s) -> vel(in/s) -> rps(wheel) -> rps -> rpm
double Math::ftpsToRPM(double ftps){
    return ftps * 12 / (3.25 * M_PI) / (3.0/5) * 60;
}

// rpm -> rps -> rps (wheel) -> vel (in/s) -> vel (ft/s)
double Math::rpmToFtps(double rpm){
    return rpm / 60 * (3.0/5) * (3.25 * M_PI) / 12;
}

double Math::ftToTick(double ft){
    return ft*12/(3.25*M_PI)/(3.0/5)*300;
}

double Math::tickToFt(double tick){
    return (tick/300)*(3.0/5)*(3.25*M_PI)/12;
}


double Math::rescale180(double angle){
    return angle - 360.0 * std::floor((angle + 180.0) * (1.0 / 360.0));
}

double Math::rescale360(double angle){
    return angle - 360.0 * (std::floor(angle * (1.0 / 360.0)));
}

