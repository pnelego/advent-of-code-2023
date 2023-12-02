//
// Created by pnelego on 11/30/23.
//

#ifndef TIMER_HPP
#define TIMER_HPP

#include <chrono>
#include <iostream>

class Timer
{
private:
    uint64_t start_time{0};
public:
    void start() {

        start_time = std::chrono::duration_cast<std::chrono::microseconds>(
                std::chrono::system_clock::now().time_since_epoch()
        ).count();
    }

    [[nodiscard]] uint64_t stop() const {
        const uint64_t end_time = std::chrono::duration_cast<std::chrono::microseconds>(
                std::chrono::system_clock::now().time_since_epoch()
        ).count();
        return end_time - start_time;
    }
};

#endif //TIMER_HPP
