#ifndef ASSIGNMENT_2_MAZE_SOLVER_H
#define ASSIGNMENT_2_MAZE_SOLVER_H

#include "stack.h"
#include "maze.h"

// A stack that moves through a maze until it finds the exit.
class MazeSolver {
    Maze _maze;
    Stack _path;
    bool _is_solved = false;
public:
    // Finds the entrance of the maze and starts the stack.
    explicit MazeSolver(const std::string& _input_filepath);
    void move_forward();
};


#endif //ASSIGNMENT_2_MAZE_SOLVER_H
