#pragma once
#include "main.h"

/**
 * @brief A Conveyor class which we use to dynamically control our conveyor
 *        in autonomous
 * 
 */
class Conveyor : public TaskWrapper {
    private: 
    std::shared_ptr<Motor> motor;

    public: 
    /**
     * @brief Construct a new Conveyor object
     * 
     * @param motor the conveyor motor
     */
    Conveyor(const std::shared_ptr<Motor>& motor);
    
    /**
     * @brief Intakes dynamically in a seperate task
     *        The conveyor runs automatically when the lift is up. 
     *        If a jam is detected, the conveyor will automatically 
     *        reverse to stop the jam, then continue intaking
     * 
     */
    void loop() override;
};