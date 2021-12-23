#include "main.h"

void TaskWrapper::startTask(const char* iname){
    task = std::move(std::make_unique<pros::Task>(trampoline, this, iname));
}

void TaskWrapper::pauseTask(){
    task->suspend();
}

void TaskWrapper::resumeTask(){
    task->resume();
}

void TaskWrapper::stopTask(){
    task->remove();
    task = {nullptr};
}

const char* TaskWrapper::getName(){
    return task->get_name();
}

