#include "Odometry.hpp"

OdomDimension::OdomDimension(QLength wheelDiam, QLength leftOffset, QLength midOffset, QLength rightOffset){
    wheelDiameter = wheelDiam;
    lDist = leftOffset;
    mDist = midOffset;
    rDist = rightOffset;
}

OdomDimension::OdomDimension(QLength wheelDiam, QLength offset1, QLength offset2){
    wheelDiameter = wheelDiam;
    lDist = offset1;
    mDist = offset2;
}

OdomState (::Odometry::getPos() const){
    return globalPos;
}   

QLength (::Odometry::getX() const){
    return globalPos.x;
}

QLength (::Odometry::getY() const){
    return globalPos.y;
}

QAngle (::Odometry::getAngle() const){
    return globalPos.theta;
}

double ::Odometry::getEncoderLeft() const{
    return 0;
}

double ::Odometry::getEncoderMid() const{
    return 0;
}

double ::Odometry::getEncoderRight() const{
    return 0;
}

double ::Odometry::getEncoderSide() const{
    return 0;
}

void ::Odometry::setPos(OdomState iPos){
    globalPos = iPos;
}

void ::Odometry::setX(QLength iX){
    globalPos.x = iX;
}

void ::Odometry::setY(QLength iY){
    globalPos.y = iY;
}

void ::Odometry::setAngle(QAngle iTheta){
    globalPos.theta = iTheta;
}

void ::Odometry::resetState(){
    globalPos.x = 0_m;
    globalPos.y = 0_m;
    globalPos.theta = 0_rad;
}

void ::Odometry::reset(){
    resetState();
    resetSensors();
}

ThreeWheelOdometry::ThreeWheelOdometry(std::shared_ptr<ContinuousRotarySensor> l, std::shared_ptr<ContinuousRotarySensor> m, std::shared_ptr<ContinuousRotarySensor> r, OdomDimension dim){
    left = l;
    mid = m;
    right = r;
    dimension = dim;
    if(dimension.rDist == (-1 * inch)){
        throw std::invalid_argument("MISSING RIGHT WHEEL OFFSET ARGUMENT");
    }
    dimension.tpr = 360;
    setPos({0 * inch, 0 * inch, 0 * radian});
}

void ThreeWheelOdometry::resetSensors(){
    left->reset(); mid->reset(); right->reset();
}

double ThreeWheelOdometry::getEncoderLeft() const{
    return lVal;
}

double ThreeWheelOdometry::getEncoderMid() const{
    return mVal;
}

double ThreeWheelOdometry::getEncoderRight() const{
    return rVal;
}

void ThreeWheelOdometry::loop(){
    auto t = pros::millis();
    while(true){
        lVal = left->get(), mVal = mid->get(), rVal = right->get();

        QLength left = Math::angleToArcLength((lVal - lPrev) / dimension.tpr * 360_deg, dimension.wheelDiameter/2);
        QLength right = Math::angleToArcLength((rVal - rPrev) / dimension.tpr * 360_deg, dimension.wheelDiameter/2);
        QLength mid = Math::angleToArcLength((mVal - mPrev) / dimension.tpr * 360_deg, dimension.wheelDiameter/2);

        lPrev = lVal;
        rPrev = rVal;
        mPrev = mVal;

        QLength h, h2, rRad, mRad;
        QAngle theta = (left - right) / (dimension.lDist + dimension.rDist) * radian;
        if(theta != 0 * radian){
            rRad = right / theta.convert(radian);
            mRad = mid / theta.convert(radian);

            h = (rRad + dimension.rDist) * sin(theta / 2) * 2;
            h2 = (mRad + dimension.mDist) * sin(theta / 2) * 2;
        }
        else{
            h = right;
            h2 = mid;
        }

        QAngle endAngle = theta / 2 + globalPos.theta;

        globalPos.x += (h * sin(endAngle) + h2 * cos(endAngle));
        globalPos.y += (h * cos(endAngle) + h2 * -sin(endAngle));
        globalPos.theta = Math::rescale180(((globalPos.theta) + theta));

        pros::Task::delay_until(&t, 10);
    }
}

TwoWheelIMUOdometry::TwoWheelIMUOdometry(std::shared_ptr<ContinuousRotarySensor> s, std::shared_ptr<ContinuousRotarySensor> m, std::shared_ptr<IMU> imu, OdomDimension dim){
    side = s;
    mid = m;
    inertial = imu;
    dimension = dim;
    dimension.tpr = 360;
    setPos({0_m, 0_m, 0_rad});
}

void TwoWheelIMUOdometry::resetSensors(){
    mid->reset();
    side->reset();
    inertial->reset();
}

double TwoWheelIMUOdometry::getEncoderSide() const{
    return sVal;
}

double TwoWheelIMUOdometry::getEncoderMid() const{
    return mVal;
}

void TwoWheelIMUOdometry::loop(){
    auto t = pros::millis();
    while(true){
        // ldist is sdist
        sVal = side->get(), mVal = mid->get(), aVal = inertial->get();
        
        QLength side = Math::angleToArcLength((sVal - sPrev) / dimension.tpr * 360_deg, dimension.wheelDiameter/2);
        QLength mid = Math::angleToArcLength((mVal - mPrev) / dimension.tpr * 360_deg, dimension.wheelDiameter/2);
        QAngle theta = (inertial->get() - aPrev) * degree;
        
        sPrev = sVal;
        mPrev = mVal;
        aPrev = aVal;
        
        QLength h, h2, sRad, mRad;
        if(theta != 0 * radian){
            sRad = side / theta.convert(radian);
            mRad = mid / theta.convert(radian);

            h = (sRad + dimension.lDist) * sin(theta / 2) * 2;
            h2 = (mRad + dimension.mDist) * sin(theta / 2) * 2;
        }
        else{
            h = side;
            h2 = mid;
        }
        
        QAngle endAngle = theta / 2 + globalPos.theta;
        
        globalPos.x += (h * sin(endAngle) + h2 * cos(endAngle));
        globalPos.y += (h * cos(endAngle) + h2 * -sin(endAngle));
        globalPos.theta = Math::rescale180((globalPos.theta) + theta);
        
        pros::Task::delay_until(&t, 10);
    }   
}

TwoWheelOdometry::TwoWheelOdometry(std::shared_ptr<ContinuousRotarySensor> l, std::shared_ptr<ContinuousRotarySensor> r, OdomDimension dim){
    left = l;
    right = r;
    dimension = dim;
    dimension.tpr = 360;
    setPos({0 * inch, 0 * inch, 0 * radian});
}

void TwoWheelOdometry::resetSensors(){
    left->reset();
    right->reset();
}

double TwoWheelOdometry::getEncoderLeft() const{
    return lVal;
}

double TwoWheelOdometry::getEncoderRight() const{
    return rVal;
}

void TwoWheelOdometry::loop(){
    auto t = pros::millis();
    while(true){
        //mdist is rdist
        lVal = left->get(), rVal = right->get();

        QLength left = Math::angleToArcLength((lVal - lPrev) / dimension.tpr * 360_deg, dimension.wheelDiameter/2);
        QLength right = Math::angleToArcLength((rVal - rPrev) / dimension.tpr * 360_deg, dimension.wheelDiameter/2);

        lPrev = lVal;
        rPrev = rVal;

        QLength h, rRad;
        QAngle theta = (left - right) / (dimension.lDist + dimension.mDist) * radian;
        if(theta != 0 * radian){
            rRad = right / theta.convert(radian);
            h = (rRad + dimension.mDist) * sin(theta / 2) * 2;
        }
        else{
            h = right;
        }

        QAngle endAngle = theta / 2 + globalPos.theta;

        globalPos.x += (h * sin(endAngle));
        globalPos.y += (h * cos(endAngle));
        globalPos.theta = Math::rescale180((globalPos.theta) + theta);

        pros::Task::delay_until(&t, 3);
    }
}
