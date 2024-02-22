#include "stack.h"

Node::Node(Coordinates _input_coords) {
    _coords = _input_coords;
}

void Stack::push(Coordinates coords) {
    auto node = std::make_unique<Node>(coords);
    node->_next = std::move(_top);
    _top = std::move(node);
}

std::optional<Coordinates> Stack::peek() {
    if(_top == nullptr) return std::nullopt;
    return std::make_optional<Coordinates>(_top->_coords);
}

void Stack::pop() {
    if (_top != nullptr) {
        _top = std::move(_top->_next);
    }
}

Coordinates Stack::top_coordinates() {
    return _top->_coords;
}
