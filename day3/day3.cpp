//
// Created by pnelego on 11/30/23.
//
#include "../tools/file_loader.hpp"
#include "../tools/timer.hpp"

#include <iostream>
#include <vector>
#include <string>



uint32_t part_one(const std::vector<std::string> &lines)
{
}


uint32_t part_two(const std::vector<std::string> &lines)
{
}



int main()
{
    //read input file
    std::vector<std::string> lines = FileLoader::load_file("../day3/input.txt");
    //in order to get accurate time measurements we need to have two separate vectors
    //one for each part so one doesn't affect the other
    std::vector<std::string> lines2 = lines;

    Timer timer;

    //part one
    std::cout << "Part one ------------------------- \n";
    timer.start();
    uint32_t result = part_one(lines);
    const uint64_t timeTaken = timer.stop();
    std::cout << "Time to execute: " << timeTaken << "µs" << std::endl;
    std::cout << "Result: " << result << std::endl;


    //part two
    std::cout << "Part two ------------------------- \n";
    timer.start();
    uint32_t result2 = part_two(lines2);
    const uint64_t timeTaken2 = timer.stop();
    std::cout << "Time to execute: " << timeTaken2 << "µs" << std::endl;
    std::cout << "Result: " << result2 << std::endl;

    return 0;
}