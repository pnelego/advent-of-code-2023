//
// Created by pnelego on 11/30/23.
//
#include "../tools/file_loader.hpp"
#include "../tools/timer.hpp"
#include "../tools/fstoi.hpp"

#include <iostream>
#include <vector>
#include <string>




uint32_t f_GameId(const std::string &line)
{
    //start at the 6th character, because the first 5 are "Game "
    uint32_t result = 0;
    for (uint8_t i = 5; i < line.length(); i++)
    {
        if (line[i] >= 0x30 && line[i] <= 0x39)
        {
            result *= 10;
            result += (((int)line[i]) - 0x30);
        }
        else
        {
            break;
        }
    }
    return result;
}

bool IsLinePossible(const std::string &line)
{
    uint8_t chunkRed = 0;
    uint8_t chunkGreen = 0;
    uint8_t chunkBlue = 0;

    uint8_t unknownColor = 0;
    //start at the 9th character, because the first 8 are guarenteed to be "Game #: "
    for (uint32_t i = 8; i < line.length(); i++)
    {
        if (line[i] >= 0x30 && line[i] <= 0x39)
        {
            unknownColor *= 10;
            unknownColor += (((int)line[i]) - 0x30);
        }
        if (line[i] == 'r' && line[i-1] != 'g')
        {
            chunkRed = unknownColor;
            unknownColor = 0;
            //skip 3 characters
            i += 3;
        }
        if (line[i] == 'g')
        {
            chunkGreen = unknownColor;
            unknownColor = 0;
            //skip 5 characters
            i += 5;
        }
        if (line[i] == 'b')
        {
            chunkBlue = unknownColor;
            unknownColor = 0;
            //skip 4 characters
            i += 4;
        }
        if (line[i] == ';')
        {
            //end the chunk
            if (chunkRed > 12 || chunkGreen > 13 || chunkBlue > 14)
            {
                return false;
            }

            chunkRed = 0;
            chunkGreen = 0;
            chunkBlue = 0;
        }
    }


    //check the last chunk
    if (chunkRed > 12 || chunkGreen > 13 || chunkBlue > 14)
    {
        return false;
    }

    //std::cout << std::endl;
    return true;
}

uint32_t part_one(const std::vector<std::string> &lines)
{
    uint32_t sum = 0;
    for (const std::string &line : lines)
    {
        const uint8_t gameNumber = f_GameId(line);

        if (IsLinePossible(line))
        {
            sum += gameNumber;
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


    //part two
    std::cout << "Part two ------------------------- \n";
    timer.start();
    uint32_t result2 = part_two(lines2);
    const uint64_t timeTaken2 = timer.stop();
    std::cout << "Time to execute: " << timeTaken2 << "µs" << std::endl;
    std::cout << "Result: " << result2 << std::endl;

    return 0;
}