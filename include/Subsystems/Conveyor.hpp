#pragma once
#include "main.h"

class Conveyor : public TaskWrapper {
    private: 
    std::shared_ptr<Motor> motor;

    public: 
    Conveyor(const std::shared_ptr<Motor>& motor);
    
    /**
     * @brief Intakes dynamically in seperate task
     * 
     */
    void loop() override;
};