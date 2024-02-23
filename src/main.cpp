#include <fstream>
#include <iostream>
#include "maze_solver.h"

using namespace std;

int main(int argc, char* argv[]) {
    string output_filepath;
    if (argc < 3) {
        cout << "error: program requires input and output filepath";
        return 1;
    }
    else {
        cout << "Running Maze Solver..." << endl;
        MazeSolver solver(argv[1]);
        cout << "Solving..." << endl;
        string solution = solver.solve_maze();
        cout << "Done!" << endl;
        ofstream output;
        output.open(argv[2]);
        output << solution;
        output.close();
        cout << "Saved to " << argv[2] << "." << endl;
        return 0;
    }
}