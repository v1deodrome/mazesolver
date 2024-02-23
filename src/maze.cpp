#include "maze.h"
#include <fstream>

Coordinates::Coordinates(int x_input, int y_input) {
    x_coord = x_input;
    y_coord = y_input;
}

Coordinates::Coordinates() = default;

Maze::Maze(const std::string& _input_filepath) {
    std::ifstream _file(_input_filepath);
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

std::string Maze::output_maze() {
    std::string _output;
    for (auto & i : _maze_vector) {
        for (char j : i) {
            // clean output of Xs
            if (j == 'X') {
                _output.append(1,' ');
            }
            else {
                _output.append(1,j);
            }
        }
        _output.append(1,'\n');
    }
    return _output;
}

Coordinates Maze::find_entrance() {
    // declaring this array as static prevents undefined behavior from returning an array
    Coordinates entrance;
    for (int i = 1; i < _maze_vector.size()-1; i++) {
        if (_maze_vector[i][0] == ' ') {
            entrance = Coordinates(0,i);
            break;
        }
        else if (_maze_vector[i][_maze_vector.size()-1] == ' ') {
            entrance = Coordinates((int)_maze_vector.size()-1,i);
            break;
        }
    }
    return entrance;
}

bool Maze::is_empty(Coordinates coord) {
    return (_maze_vector[coord.y_coord][coord.x_coord] == ' ');
}

bool Maze::is_intersection(Coordinates coord) {
    int _path_counter = 0;
    if (_maze_vector[coord.y_coord + 1][coord.x_coord] == ' ') {
        _path_counter++;
    }
    if (_maze_vector[coord.y_coord - 1][coord.x_coord] == ' ') {
        _path_counter++;
    }
    if (_maze_vector[coord.y_coord][coord.x_coord + 1] == ' ') {
        _path_counter++;
    }
    if (_maze_vector[coord.y_coord][coord.x_coord - 2] == ' ') {
        _path_counter++;
    }
    return (_path_counter >= 2);
}

bool Maze::is_exit(Coordinates coord) {
    return (coord.x_coord == 0 ||
            coord.x_coord == _maze_vector[1].size()-1 ||
            coord.y_coord == 0 ||
            coord.y_coord == _maze_vector.size()-1
            );
}

void Maze::draw_solution_portion(Coordinates coord) {
    _maze_vector[coord.y_coord][coord.x_coord] = '#';
}

void Maze::delete_solution_portion(Coordinates coord) {
    _maze_vector[coord.y_coord][coord.x_coord] = ' ';
}

void Maze::block_coordinate(Coordinates coord) {
    _maze_vector[coord.y_coord][coord.x_coord] = 'X';
}
