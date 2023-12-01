//
// Created by pnelego on 11/30/23.
//
#include "../tools/file_loader.hpp"
#include "../tools/timer.hpp"

#include <iostream>
#include <vector>
#include <string>



void process(const std::vector<std::string>& lines)
{

}



int main()
{
    //read input file
    std::vector<std::string> lines = FileLoader::load_file("input.txt");

    Timer timer;

    timer.start();

    //process input
    process(lines);

    //stop timer
    const uint64_t timeTaken = timer.stop();
    std::cout << "Time taken: " << timeTaken << "ms" << std::endl;
    return 0;
}