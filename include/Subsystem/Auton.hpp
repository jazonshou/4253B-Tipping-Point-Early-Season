#pragma once
#include "main.h"

class Auton {
    // extern pros::Mutex lock;
    // extern std::vector<std::function<void()>> auton;
    // extern std::vector<std::string> name;
    // extern int index;
    private:
    std::shared_ptr<AsyncPositionController<double, double>> liftController;
    
    public:
    void add(std::function<void()> iAutonomous, std::string iName);

    void switchAuton();

    void select();

    void execute();

    std::string getName();

    void addPath(int ind);

    void init();

    void wingGrab();

    void skills();

    void left();

    void right();

    void awp();

};