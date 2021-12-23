#pragma once
#include "main.h"

/**
 * @brief Structure for trajectory points 
 *        Used to make motion profile organization better
 * 
 */
struct  TrajectoryPoint{
    /**
     * @brief Construct a new Trajectory Point 
     * 
     */
    TrajectoryPoint() = default;

    /**
     * @brief Destroy the Trajectory Point 
     * 
     */
    ~TrajectoryPoint() = default;
    
    /**
     * @brief Construct a new Trajectory Point object
     * 
     * @param leftP left position
     * @param rightP right position
     * @param leftV left velocity
     * @param rightV right velocity
     * @param leftA left acceleration
     * @param rightA right acceleration
     */
    TrajectoryPoint(double leftP, double rightP, double leftV, double rightV, double leftA, double rightA);

    friend std::ostream& operator<<(std::ostream& os, TrajectoryPoint& pt);

    double leftPosition, rightPosition, leftVelocity, leftAcceleration, rightVelocity, rightAcceleration;
};

std::ostream& operator<<(std::ostream& os, TrajectoryPoint& pt);

class Trajectory{
    private:
    std::vector<TrajectoryPoint> path;

    public:
    Trajectory() = default;
    ~Trajectory() = default;
    Trajectory(const std::initializer_list<TrajectoryPoint>& iPath);
    
    TrajectoryPoint operator[](int index) const;
    int size() const;
};