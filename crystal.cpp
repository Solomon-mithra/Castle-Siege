#include "crystal.h"
#include <iostream>
using namespace std;
// Constructor
Crystal::Crystal(char s) : Location() { taken = false; }
// Accessor
bool Crystal::getTaken() const { return taken; }

// Mutator
void Crystal::setTaken(bool t) { taken = t; }

// Method
void Crystal::draw() {
  char diamondEmoji[] = u8"\U0001F48E";
  if (visited && !taken) {
    std::cout << diamondEmoji;
  } else if (taken) {
    std::cout << "  ";
  } else {
    std::cout << ". ";
  }
}

int Crystal::visit(Player &p) {
  if (!visited) {
    visited = true;
    std::cout << "\033[34mYou found a magic crystal! \033[0m \n";
  }
  if (!taken) {
    cout << "\nDo you want to pick the crystal?(Y/N)\n";
    string option;
    cin >> option;
    cin.ignore();
    if (option == "Y" || option == "y") {
      taken = true;
      p.setCrystalsCollected();
      cout << "\033[34mYou picked up the crystal! \033[0m \n";
      cout << endl;
    }
    std::cout << "Press enter to continue...\n";
    // cin.ignore();
    std::cin.get();
  }

  return 1;
}
