#pragma once
#include "main.h"

struct ProfileConstraint{
    QSpeed maxVelocity{0.0};
    QAcceleration maxAcceleration{0.0};
    QJerk maxJerk{0.0};

    ProfileConstraint(QSpeed maxVel, QAcceleration maxAccel, QJerk maxJerk);
    ~ProfileConstraint() = default;

    protected:
    ProfileConstraint() = default;
    friend class LinearMotionProfile;
};

class LinearMotionProfile{
    protected:
    ProfileConstraint constraint;
    QLength distance{0.0};
    bool isReversed{false};

    std::vector<QTime> timePhase;
    std::vector<QLength> distPhase;
    std::vector<QSpeed> velPhase;
    std::vector<QAcceleration> accPhase;
    std::vector<QJerk> jerkPhase;

    public:
    LinearMotionProfile() = default;
    ~LinearMotionProfile() = default;

    virtual void setDistance(QLength iDistance) = 0;
    virtual void setConstraint(ProfileConstraint iConstraint) = 0;

    virtual QTime getTotalTime() const = 0;
    virtual QLength getPosition(QTime time) const = 0;
    virtual QSpeed getVelocity(QTime time) const = 0;
    virtual QAcceleration getAcceleration(QTime time) const = 0;
    virtual TrajectoryPoint get(QTime time) const = 0;
};

class TrapezoidalMotionProfile : LinearMotionProfile{
    private:
    QLength min3Stage = 0_m;

    public:
    TrapezoidalMotionProfile(ProfileConstraint iConstraint);
    TrapezoidalMotionProfile() = default;
    ~TrapezoidalMotionProfile() = default;

    void setDistance(QLength iDistance) override;
    void setConstraint(ProfileConstraint iConstraint) override;

    QTime getTotalTime() const override;
    QLength getPosition(QTime time) const override;
    QSpeed getVelocity(QTime time) const override;
    QAcceleration getAcceleration(QTime time) const override;
    TrajectoryPoint get(QTime time) const override;
};

class SCurveMotionProfile : LinearMotionProfile{
    QLength fullDist = 0_m;
    QLength minDist = 0_m;
    bool fullAccel{true};

    public:
    SCurveMotionProfile(ProfileConstraint iConstraint);
    SCurveMotionProfile() = default;
    ~SCurveMotionProfile() = default;

    void setDistance(QLength iDistance) override;
    void setConstraint(ProfileConstraint iConstraint) override;

    QTime getTotalTime() const override;
    QLength getPosition(QTime time) const override;
    QSpeed getVelocity(QTime time) const override;
    QAcceleration getAcceleration(QTime time) const override;
    TrajectoryPoint get(QTime time) const override;
};