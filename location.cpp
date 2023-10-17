
#include "location.h"
#include <iostream>

// Constructor
Location::Location() {
  visited = false;
}

// Accessors
bool Location::getVisited() const { return visited; }

// Mutators
void Location::setVisited(bool v) { visited = v; }

// Methods
void Location::draw() {
  if (visited) {
    std::cout <<  "  ";
  } else {
    std::cout << ". ";
  }
}

int Location::visit(Player &p) {
  visited = true;
  // std::cout << "visited";
  return 1;
}
