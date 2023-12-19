//
// Created by pnelego on 11/30/23.
//
#include "../tools/file_loader.hpp"
#include "../tools/timer.hpp"
#include "../tools/fstoi.hpp"

#include <iostream>
#include <vector>
#include <string>




bool IsLinePossible(const char *line, const uint32_t length)
{
    uint8_t unknownColor = 0;
    for (uint8_t i = 9; i < length; i++)
    {
        if (line[i] >= 0x30 && line[i] <= 0x39)
        {
            unknownColor *= 10;
            unknownColor += (int)line[i] - 0x30;
        }

        switch (line[i])
        {
            case 0x72: //r
                if (unknownColor > 12)
                {
                    return false;
                }
                unknownColor ^= unknownColor;
                //skip 4 characters
                i += 4;
                break;

            case 0x67: //g
                if (unknownColor > 13)
                {
                    return false;
                }
                unknownColor ^= unknownColor;
                //skip 6 characters
                i += 6;
                break;

            case 0x62: //b
                if (unknownColor > 14)
                {
                    return false;
                }
                unknownColor ^= unknownColor;
                //skip 5 characters
                i += 5;
                break;
            default:
                break;
        }
    }
    return true;
}

uint32_t part_one(const std::vector<std::string> &lines)
{
    uint32_t sum = 0;
    for (uint8_t lineNum = 0; lineNum < lines.size(); lineNum++)
    {
        if (IsLinePossible(lines[lineNum].c_str(), lines[lineNum].length()))
        {
            sum += lineNum+1;
        }
    }

    return sum;
}


/**
 * BEGIN PART TWO
 */

uint32_t GetLinePower(const std::string &line)
{

    //very similar to the IsLinePossible function, but we're trying to get
    //the largest of each color

    uint32_t largestRed = 0;
    uint32_t largestGreen = 0;
    uint32_t largestBlue = 0;

    uint32_t unknownColor = 0;
    for (uint32_t i = 8; i < line.length(); i++)
    {
        if (line[i] >= 0x30 && line[i] <= 0x39)
        {
            unknownColor *= 10;
            unknownColor += (((int)line[i]) - 0x30);
        }

        if (line[i] == 'r' && line[i-1] != 'g')
        {

            //we have a new red chunk
            if (unknownColor > largestRed)
            {
                largestRed = unknownColor;
            }
            unknownColor = 0;

            //skip 3 characters
            i += 3;
        }
        if (line[i] == 'g')
        {
            //we have a new green chunk
            if (unknownColor > largestGreen)
            {
                largestGreen = unknownColor;
            }
            unknownColor = 0;

            //skip 5 characters
            i += 5;
        }
        if (line[i] == 'b')
        {
            //we have a new blue chunk
            if (unknownColor > largestBlue)
            {
                largestBlue = unknownColor;
            }
            unknownColor = 0;
            //skip 4 characters
            i += 4;
        }
    }

    return largestRed * largestGreen * largestBlue;
}

uint32_t part_two(const std::vector<std::string> &lines)
{
    uint32_t sum = 0;
    for (const std::string &line : lines)
    {
        sum+= GetLinePower(line);
    }
    return sum;
}



int main()
{
    //read input file
    std::vector<std::string> lines = FileLoader::load_file("../day2/input.txt");
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
    std::cout << "Expected result: 1867" << std::endl;


    //part two
    std::cout << "Part two ------------------------- \n";
    timer.start();
    uint32_t result2 = part_two(lines2);
    const uint64_t timeTaken2 = timer.stop();
    std::cout << "Time to execute: " << timeTaken2 << "µs" << std::endl;
    std::cout << "Result: " << result2 << std::endl;
    std::cout << "Expected result: 84538" << std::endl;

    return 0;
}