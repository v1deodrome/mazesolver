#include <fstream>
#include <iostream>
#include "maze_solver.h"
#include <filesystem>

using namespace std;

int main(int argc, char* argv[]) {
    string output_filepath;
    if (argc < 3) {
        cout << "error: program requires input and output filepath";
        return 1;
    }
    else {
        MazeSolver solver(argv[1]);
        string solution = solver.solve_maze();
        ofstream output;
        output.open(argv[2]);
        output << solution;
        output.close();
        return 0;
    }
}