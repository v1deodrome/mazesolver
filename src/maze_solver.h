#ifndef ASSIGNMENT_2_MAZE_SOLVER_H
#define ASSIGNMENT_2_MAZE_SOLVER_H

#include "stack.h"
#include "maze.h"

// A stack that moves through a maze until it finds the exit.
class MazeSolver {
    Maze _maze;
    Stack _path;
    bool _dead_end_ahead = false;
    bool _is_solved = false;
public:
    // Finds the entrance of the maze and starts the stack.
    explicit MazeSolver(const std::string& _input_filepath);
    // While loop that executes this classes functions until the maze is solved
    std::string solve_maze();
    // Make a move forward. Marks _dead_end_ahead as true if it cannot move.
    void move_forward();
    // Move backwards. Blocks the path and marks _dead_end_ahead as false if it finds another valid path.
    void move_backward();
    // Push the top of the stack and draw on the maze vector simultaneously.
    void push_and_draw(Coordinates _coordinates);
    // Pops the top of the stack and removes its segment on the maze vector simultaneously.
    void pop_and_erase();
};


#endif //ASSIGNMENT_2_MAZE_SOLVER_H
