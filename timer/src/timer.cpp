#include "../include/timer.h"

timer::timer(){
    running = false;
}

void timer::start(){
    start_time = std::chrono::steady_clock::now(); 
    last_lap_time = start_time;
    running = true;
}

double timer::stop(){
    if(running){
        std::chrono::time_point<std::chrono::steady_clock> end = steady_clock::now();
        std::chrono::duration<double> dur = end - start_time;
        running = false;
        return dur.count();
    }
    return 0.0;
}

void timer::reset(){
    running = false;
    start_time = {};
    last_lap_time = {};
}

double timer::lap(){
    if(running){
        std::chrono::time_point<std::chrono::steady_clock> end = std::chrono::steady_clock::now();
        std::chrono::duration<double> dur = end - last_lap_time; 
        last_lap_time = end;
        return dur.count();
    }
    return 0.0;
}

bool timer::isRunning(){
    return running;
}