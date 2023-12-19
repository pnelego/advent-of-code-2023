#ifndef __FSTOI_HPP__
#define __FSTOI_HPP__

#include <string>

// Convert a string to an integer using nothing but math.
// Way faster than std::stoi, but isnt type safe.
// Only works with positive numbers.
class Fstoi
{
    static uint32_t f_stoi(const std::string &str);
    static int32_t f_istoi(const std::string &str);
};

inline uint32_t Fstoi::f_stoi(const std::string &str)
{
    uint32_t result = 0;
    for (char i : str)
    {
        result *= 10;
        result += (((int)i) - 0x30);
    }
    return result;
}

inline int32_t Fstoi::f_istoi(const std::string &str)
{
    if (str[0] == '-')
    {
        int32_t result = 0;
        for (uint8_t i = 1; i < str.length(); i++)
        {
            result *= 10;
            result += (((int)str[i]) - 0x30);
        }
        return -result;
    }
    return f_stoi(str);
}

#endif // __FSTOI_HPP__