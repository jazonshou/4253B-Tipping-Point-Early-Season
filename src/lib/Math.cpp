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

QLength Math::tickToDistance(){
    return 0_m;
}

QAngle Math::rescale180(QAngle angle){
    return rescale180(angle.convert(degree)) * degree;
}

double Math::rescale180(double angle){
    return angle - 360.0 * std::floor((angle + 180.0) * (1.0 / 360.0));
}

QAngle Math::rescale360(QAngle angle){
    return rescale360(angle.convert(degree)) * degree;
}

double Math::rescale360(double angle){
    return angle - 360.0 * (std::floor(angle * (1.0 / 360.0)));
}

std::pair<double, double> Math::quadraticFormula(double a, double b, double c){
    double discriminant = b * b - 4 * a * c;

    if(discriminant < 0){
        throw std::runtime_error("Quadratic Formula: No Real Solution!");
    }
    else if(abs(discriminant) <= 0.001){
        return {-b / 2 * a, -b / 2 * a};
    }
    else{
        double x1 = (-b + sqrt(discriminant)) / (2 * a);
        double x2 = (-b - sqrt(discriminant)) / (2 * a);

        return {x1, x2};
    }
}

