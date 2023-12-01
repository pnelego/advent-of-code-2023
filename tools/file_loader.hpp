//
// Created by pnelego on 11/30/23.
//

#ifndef FILE_LOADER_HPP
#define FILE_LOADER_HPP

#include <fstream>
#include <vector>
#include <string>


class FileLoader {
public:
    static std::vector<std::string> load_file(std::string file_name) {
        std::ifstream file(file_name);
        std::vector<std::string> lines;
        std::string line;
        while (std::getline(file, line)) {
            lines.push_back(line);
        }
        return lines;
    }
};

#endif //FILE_LOADER_HPP
