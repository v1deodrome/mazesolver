#include "maze_solver.h"

MazeSolver::MazeSolver(const std::string &_input_filepath) : _maze(_input_filepath) {
    // create the starting point of the maze
    _path.push(_maze.find_entrance());
    _maze.draw_solution_portion(_path.top_coordinates());
}

void MazeSolver::move_forward() {

}
