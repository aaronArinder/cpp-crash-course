/*
 * Implement a move constructor and a move assignment operator for TimerClass. A
 * moved-from TimerClass shouldn't print any output to the console when it gets
 * destructed.
 * */

#include <cstdio>
#include <chrono>
#include <ctime>
#include <iostream>

struct TimerClass {
    TimerClass(){
        timestamp = std::chrono::system_clock::now();
        beginning_time = std::chrono::high_resolution_clock::now();
    }

    // copy assignment
    TimerClass& operator=(const TimerClass& copied_timer) {
        return *this;
    }

    // move assignment
    TimerClass operator=(TimerClass&& moved_timer) {
        return *this;
    }

    ~TimerClass() {
        auto ending_time = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli>
            duration = ending_time - beginning_time;

        std::cout << "duration in milliseconds:  "<< duration.count() << std::endl;
    }

    void print_timestamp() {
        std::time_t timestamp_t = std::chrono::system_clock::to_time_t(timestamp);
        printf("timestamp: %s", std::ctime(&timestamp_t));
    }

    private:
        std::chrono::time_point<std::chrono::system_clock> timestamp;
        std::chrono::time_point<std::chrono::high_resolution_clock> beginning_time;

};

int main () {
    TimerClass timer_a;
    TimerClass timer_b;
    timer_b = timer_a;

    // Prints same timestamps
    timer_a.print_timestamp();
    timer_b.print_timestamp();

    return 0;
}
