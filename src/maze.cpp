#include "maze.h"
#include <fstream>

Maze::Maze(const std::string& _input_filepath) {
    std::ifstream _file(_input_filepath);
    std::string _line;
    int _row_number = 0;
    // ideally we'd like to populate with booleans, but since we're printing this it doesn't make
    // sense to waste memory on a completely new vector that works *slightly* better for parsing
    for (std::string _row_content; std::getline(_file, _row_content); _row_number++) {
        _maze_vector.emplace_back();
        for (int i = 0; i < _row_content.length(); i++) {
            _maze_vector[_row_number].push_back(_row_content[i]);
        }
    }
}
