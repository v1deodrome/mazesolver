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

class Stack {
    // The last node in the stack.
    std::unique_ptr<Node> _top{nullptr};
public:
    // Add something on top of the stack.
    void push(Coordinates coords);
    // Return the top of the stack's contents.
    std::optional<Coordinates> peek();
    // Remove the top node of the stack.
    void pop();
    // Get the data from the head
    Coordinates top_coordinates();
};

#endif //ASSIGNMENT_2_STACK_H