#include "maze_solver.h"

MazeSolver::MazeSolver(const std::string &_input_filepath) : _maze(_input_filepath) {
    // create the stack/snake at the starting point of the maze, get the foot out the door
    _path.push(_maze.find_entrance());
    _maze.draw_solution_portion(_path.top_coordinates());
    move_forward();
}

std::string MazeSolver::solve_maze() {
    while (!_is_solved) {
        if (_maze.is_exit(_path.top_coordinates())) {
            _is_solved = true;
        }
        else {
            move_forward();
            while (_dead_end_ahead) {
                move_backward();
            }
        }
    }
    return _maze.output_maze();
}

void MazeSolver::move_forward() {
    Coordinates _current_pos = _path.top_coordinates();
    Coordinates _new_position;
    // right
    if (_maze.is_empty(_new_position = Coordinates(_current_pos.x_coord+1,_current_pos.y_coord))) {
        push_and_draw(_new_position);
    }
        // down
    else if (_maze.is_empty(_new_position = Coordinates(_current_pos.x_coord,_current_pos.y_coord+1))) {
        push_and_draw(_new_position);
    }
        // left
    else if (_maze.is_empty(_new_position = Coordinates(_current_pos.x_coord-1,_current_pos.y_coord))) {
        push_and_draw(_new_position);
    }
        // up
    else if (_maze.is_empty(_new_position = Coordinates(_current_pos.x_coord,_current_pos.y_coord-1))) {
        push_and_draw(_new_position);
    }
    else {
        _dead_end_ahead = true;
    }
}

void MazeSolver::move_backward() {
    Coordinates _deleted_coords = _path.top_coordinates();
    pop_and_erase();
    if (_dead_end_ahead && _maze.is_intersection(_path.top_coordinates())) {
        _dead_end_ahead = false;
        _maze.block_coordinate(_deleted_coords);
    }
}

void MazeSolver::push_and_draw(Coordinates _coordinates) {
    _path.push(_coordinates);
    _maze.draw_solution_portion(_coordinates);
}

void MazeSolver::pop_and_erase() {
    _maze.delete_solution_portion(_path.top_coordinates());
    _path.pop();
}
