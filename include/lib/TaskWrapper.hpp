#pragma once
#include "main.h"

class TaskWrapper {
    protected:
    TaskWrapper() = default;
    TaskWrapper(const TaskWrapper& iTask) = delete;
    TaskWrapper(TaskWrapper&& iTask) = default;
    virtual ~TaskWrapper();

    /**
     * Override this function to implement a custom task loop.
     */
    virtual void loop() = 0;
    public:
    /**   
     * Start the task.
     *
     * @param iname The task name, optional.
     */
    virtual void startTask(const char* iname = "task");

    /**
     * resumes the task.
     */
    virtual void resumeTask();

    /**
     * pauses the task.
     */
    virtual void pauseTask();

    /**
     * kills the task.
     */
    virtual void stopTask();
    
    /**
     * Get the task name.
     *
     * @return The name.
     */
    virtual const char* getName();

    private:
        static void trampoline(void* iparam);
        std::unique_ptr<pros::Task> task {nullptr};
};