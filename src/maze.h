#ifndef ASSIGNMENT_2_MAZE_H
#define ASSIGNMENT_2_MAZE_H

#include <vector>
#include <string>

// A cell in the maze.
struct Coordinates {
    int x_coord{};
    int y_coord{};
    Coordinates();
    Coordinates(int x_input, int y_input);
};

// The Maze class is used for storing the maze itself inside a two-dimensional vector. The constructor
// creates the vector from a text file.
class Maze {
    private:
        std::vector<std::vector<char>> _maze_vector;
    public:
        // Populate _maze_vector by parsing a text file.
        explicit Maze(const std::string& _input_filepath);
        // Find the entrance/exit of a maze.
        Coordinates find_entrance();
        // Test whether a coordinate is empty
        bool is_empty(Coordinates coordinates);
        // Test whether a coordinate is the middle of an intersection.
        bool is_intersection(Coordinates coordinates);
        // Draw a part of the solution line.
        void draw_solution_portion(Coordinates coord);
        // Delete a part of the solution line.
        void delete_solution_portion(Coordinates coord);
};

#endif //ASSIGNMENT_2_MAZE_H
