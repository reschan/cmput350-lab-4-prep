#ifndef TIMER_H
#define TIMER_H

#include <chrono>
#include <cstdint>

class Timer {
public:
    using Nanos = std::chrono::nanoseconds;
    using Micros = std::chrono::microseconds;
    using Millis = std::chrono::milliseconds;
    using Seconds = std::chrono::seconds;
    using Minutes = std::chrono::minutes;
    using Hours = std::chrono::hours;
    Timer() {}

    void restart() { 
        since = std::chrono::steady_clock::now(); 
    }

    template <typename T>
    uint64_t click() {
        uint64_t res = std::chrono::duration_cast<T>(std::chrono::steady_clock::now() - since).count();
        since = std::chrono::steady_clock::now();
        return res;
    }

    template <typename T>
    uint64_t glance() {
        return std::chrono::duration_cast<T>(std::chrono::steady_clock::now() - since).count();
    }


private:
    const std::chrono::steady_clock::time_point time = std::chrono::steady_clock::now();
     std::chrono::steady_clock::time_point since = time;
};

#endif  // TIMER_H