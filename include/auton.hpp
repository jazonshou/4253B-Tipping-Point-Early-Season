#pragma once
#include "main.h"

class Auton {
    private:
    std::shared_ptr<AsyncPositionController<double, double>> liftController;

    public:
    Auton();

    void init();

    void wingGrab();

    void skills();

    void left();

    void right();

    void awp();

};