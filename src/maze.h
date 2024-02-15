#ifndef ASSIGNMENT_2_MAZE_H
#define ASSIGNMENT_2_MAZE_H

#include <vector>
#include <string>

// The Maze class is used for storing the maze itself inside a two-dimensional vector. The constructor
// creates the vector from a text file.
class Maze {
    private:
        std::vector<std::vector<char>> _maze_vector;
    public:
        // Populate _maze_vector by parsing a text file.
        explicit Maze(const std::string& _input_filepath);
};

#endif //ASSIGNMENT_2_MAZE_H
