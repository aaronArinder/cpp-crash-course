/*
 * Create a struct TimerClass. In its constructor, record the current time
 * in a field called timestamp (compare with the POSIX function gettimeofday).
 * */

#include <cstdio>
#include <chrono>
#include <ctime>
#include <iostream>

struct TimerClass {
    TimerClass(){
        timestamp = std::chrono::system_clock::now();
        std::time_t timestamp_t = std::chrono::system_clock::to_time_t(timestamp);
        printf("timestamp: %s", std::ctime(&timestamp_t));
    }

    private:
        std::chrono::time_point<std::chrono::system_clock> timestamp;
};

int main () {
    TimerClass timer;
    return 0;
}
