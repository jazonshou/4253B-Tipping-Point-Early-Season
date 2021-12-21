#pragma once
#include "main.h"

enum class Direction {
    FORWARD, BACKWARD
};

class Conveyor : TaskWrapper {
    private: 
    std::shared_ptr<Motor> motor;

    public: 
    Conveyor(std::shared_ptr<Motor> motor);
    
    /**
     * @brief Sets speed of conveyor
     * 
     * @param speed target speed [-1, 1]
     */
    void move(double speed);

    /**
     * @brief Sets speed of conveyor
     * 
     * @param dir FORWARD = 1, BACKWARD = -1
     */
    void move(Direction dir);

    /**
     * @brief Intakes dynamically in seperate task
     * 
     */
    void loop() override;
};