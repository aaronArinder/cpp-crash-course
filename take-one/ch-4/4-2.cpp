/*
 * In the destructor of TimerClass, record the current time and subtract the
 * time at construction. This time is roughly the age of the timer. Print this
 * value.
 * */

#include <cstdio>
#include <chrono>
#include <iostream>

struct TimerClass {
    TimerClass(){
        timestamp = std::chrono::high_resolution_clock::now();
    }

    ~TimerClass() {
        auto current_time = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> duration = current_time - timestamp;
        std::cout << "duration in milliseconds:  "<< duration.count() << std::endl;
    }

    private:
        std::chrono::time_point<std::chrono::high_resolution_clock> timestamp;
};

int main () {
    TimerClass timer;
    return 0;
}
