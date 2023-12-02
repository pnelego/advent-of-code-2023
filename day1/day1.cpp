//
// Created by pnelego on 11/30/23.
//
#include "../tools/file_loader.hpp"
#include "../tools/timer.hpp"

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <ranges>
#include <algorithm>


uint32_t part_one(std::vector<std::string> &lines)
{
    uint32_t sum = 0;
    for (std::string &line : lines)
    {
        //go forward until we find a digit
        for (char i : line)
        {
            if (i >= 0x30 && i <= 0x39)
            {
                sum += (((int)i) - 0x30) * 0xA;
                break;
            }
        }

        //go backwards until we find a digit
        for (uint8_t i = line.length()-1; i >= 0; i--)
        {
            if (line[i] >= 0x30 && line[i] <= 0x39)
            {
                sum += (((int)line[i]) - 0x30);
                break;
            }
        }

    }

    return sum;
}


uint32_t part_two(std::vector<std::string> &lines)
{


    //Fun fact, i accidentally solved part two first. because i misinterpreted the question.
    std::unordered_map<std::string, std::string> numbers =
    {
        std::pair<std::string, std::string>("one", "1"),
        std::pair<std::string, std::string>("two", "2"),
        std::pair<std::string, std::string>("three", "3"),
        std::pair<std::string, std::string>("four", "4"),
        std::pair<std::string, std::string>("five", "5"),
        std::pair<std::string, std::string>("six", "6"),
        std::pair<std::string, std::string>("seven", "7"),
        std::pair<std::string, std::string>("eight", "8"),
        std::pair<std::string, std::string>("nine", "9"),
    };


    uint32_t  sum = 0;

    for (std::string &line : lines)
    {
        std::string digits = "";
        for (auto &[number, digit] : numbers)
        {
            //find all occurrences of the number and replace them with the digit
            while (line.find(number) != std::string::npos)
            {
                line.replace(line.find(number)+1, number.length()-2, digit);
            }
        }

        for (const char &c : line)
        {
            if (c >= 0x30 && c <= 0x39)
            {
                digits += c;
            }
        }

        std::string numberPair;
        numberPair += digits[0];
        numberPair += digits[digits.length() - 1];
        sum += std::stoi(numberPair);
    }

    return sum;
}



int main()
{
    //read input file
    std::vector<std::string> lines = FileLoader::load_file("input.txt");
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
