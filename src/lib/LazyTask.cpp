#include "main.h"

LazyTask::~LazyTask(){
    task->remove();
    task.reset(nullptr);
}

void LazyTask::startTask(const char* iname){
    task = std::move(std::make_unique<pros::Task>(trampoline, this, iname));
}

void LazyTask::pauseTask(){
    task->suspend();
}

void LazyTask::resumeTask(){
    task->resume();
}

void LazyTask::stopTask(){
    task->remove();
    task = nullptr;
}

const char* LazyTask::getName(){
    return task->get_name();
}

void LazyTask::trampoline(void* iparam){
    if(iparam){
        LazyTask* that = static_cast<LazyTask*>(iparam);
        that->loop();
    }
}