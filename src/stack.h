#ifndef ASSIGNMENT_2_STACK_H
#define ASSIGNMENT_2_STACK_H

#include <memory>
#include <optional>
#include "maze.h"

// A piece of the stack. Constructor for automatically inputting the coordinates is provided.
struct Node {
    std::unique_ptr<Node> _next{nullptr};
    Coordinates _coords{};
    explicit Node(Coordinates _input_coords);
};

// The stack is a line that draws itself to the end of the maze. By the time this program
// is finished running, think of it as the giant snake that goes from point A to point B.
class Stack {
    // The last node in the stack, which points to the one before that, and so on so forth.
    std::unique_ptr<Node> _top{nullptr};
public:
    // Add something on top of the stack.
    void push(Coordinates coords);
    // Return the top of the stack's contents.
    std::optional<Coordinates> peek();
    // Remove the top node of the stack.
    void pop();
};

#endif //ASSIGNMENT_2_STACK_H