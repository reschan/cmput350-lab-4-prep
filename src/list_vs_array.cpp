#include <cstddef>  // size_t
#include <iostream>
#include <vector>
#include <random>
#include <list>
#include <cstdint>
#include <numeric>

#include "timer.h"

constexpr size_t SIZE = 16000000;

int main() {
    std::mt19937_64 rng(727); 
    std::vector<uint64_t> vector_array;
    std::vector<uint64_t> vector_reserve_array;
    vector_reserve_array.reserve(SIZE);
    std::list<uint64_t> list_array = {};
    Timer timer;

    // time to insert 16 million uint64_t into vector array (reserve)
    std::cout << "Time taken to insert 16 million uint64_t with vector (reserve) (ns): ";
    timer.restart();
    for (uint64_t i = 0; i < SIZE; i++) {
        vector_reserve_array.push_back(rng());
    }
    std::cout << timer.click<Timer::Nanos>() << std::endl;

    // time to insert 16 million uint64_t into vector array
    std::cout << "Time taken to insert 16 million uint64_t with vector (ns): ";
    timer.restart();
    for (uint64_t i = 0; i < SIZE; i++) {
        vector_array.push_back(rng());
    }
    std::cout << timer.click<Timer::Nanos>() << std::endl;

    // time to insert 16 million uint64_t into list array
    std::cout << "Time taken to insert 16 million uint64_t with list (ns): ";
    timer.restart();
    for (uint64_t i = 0; i < SIZE; i++) {
        list_array.push_back(rng());
    }
    std::cout << timer.click<Timer::Nanos>() << std::endl;

    // i am division line -----
    uint64_t sum = 0;

    // time to add up 16 million uint64_t into vector array (reserve)
    std::cout << "Time taken to add up 16 million uint64_t with vector (reserve) (ns): ";
    timer.restart();
    for (uint64_t i = 0; i < SIZE; i++) {
        sum += vector_reserve_array.at(i);
    }
    std::cout << timer.click<Timer::Nanos>() << std::endl;

    // time to add up 16 million uint64_t into vector array
    std::cout << "Time taken to add up 16 million uint64_t with vector (ns): ";
    timer.restart();
    for (uint64_t i = 0; i < SIZE; i++) {
        sum += vector_array.at(i);
    }
    std::cout << timer.click<Timer::Nanos>() << std::endl;

    // time to add up 16 million uint64_t into list array
    std::cout << "Time taken to add up 16 million uint64_t with list (ns): ";
    timer.restart();
    sum = std::accumulate(std::begin(list_array), std::end(list_array), 0.0);
    std::cout << timer.click<Timer::Nanos>() << std::endl;

    return 0;
}
