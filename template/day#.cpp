//
// Created by pnelego on 11/30/23.
//
#include "../tools/file_loader.hpp"
#include "../tools/timer.hpp"

#include <iostream>
#include <vector>
#include <string>



void part_one(const std::vector<std::string> &lines)
{
}


void part_two(const std::vector<std::string> &lines)
{
}



int main()
{
    //read input file
    std::vector<std::string> lines = FileLoader::load_file("input.txt");
    //in order to get accurate time measurements we need to have two seperate vectors
    //one for each part
    std::vector<std::string> lines2 = FileLoader::load_file("input.txt");


    Timer timer;

    timer.start();

    //we're gonna make a copy with both parts so one doesn't affect the other
    part_one(lines);

    //stop timer
    const uint64_t timeTaken = timer.stop();
    std::cout << "Part one time: " << timeTaken << "ms" << std::endl;

    timer.start();

    part_two(lines2);

    //stop timer
    const uint64_t timeTaken2 = timer.stop();
    std::cout << "Part two time: " << timeTaken2 << "ms" << std::endl;


    return 0;
}
}