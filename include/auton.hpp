#pragma once
#include "main.h"

/**
 * @brief Originally, our plan was to use an auton selector, but due to 
 *        time constraints and bugs, we were unable to finish it on time. 
 * 
 */

//-----------------------------------------------------------//

/**
 * @brief Generates the trajectories used in skills autnonomous
 */
void genSkills();

/**
 * @brief Executes skills autonomous
 */
void skills();

/**
 * @brief Generates the trajectories used in red alliance's left side autnonomous
 */
void genRedLeft();

/**
 * @brief Executes red alliance's left side autonomous
 */
void redLeft();

/**
 * @brief Generates the trajectories used in red alliance's right side autnonomous
 */
void genRedRight();

/**
 * @brief Executes red alliance's right side autonomous
 */
void redRight();

/**
 * @brief Generates the trajectories used in blue alliance's left side autnonomous
 */
void genBlueLeft();

/**
 * @brief Executes blue alliance's left side autonomous
 */
void blueLeft();

/**
 * @brief Generates the trajectories used in blue alliance's right side autnonomous
 */
void genBlueRight();

/**
 * @brief Executes blue alliance's right side autonomous
 */
void blueRight();

/**
 * @brief Generates the trajectories used in AWP autnonomous
 */
void genAwp();

/**
 * @brief Executes awp autonomous
 */
void awp();