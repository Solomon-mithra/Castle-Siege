#include "castle.h"
#include <iostream>
#include <cstdlib>
using namespace std;

// Constructor
Castle::Castle(char s) : Location() { defeated = false; }

// Accessor
bool Castle::getDefeated() const { return defeated; }

// Mutator
void Castle::setDefeated(bool d) { defeated = d; }

// Method
void Castle::draw() {
  char castleEmoji[] = u8"\U0001F3EF";
  
    std::cout << castleEmoji;

}

// override the visit method from the base class
int Castle::visit(Player &p) {
  char castleEmoji[] = u8"\U0001F3EF";
  if (!visited) {
    visited = true;
    std::cout << "\033[33mYou encountered a castle!\033[0m" << castleEmoji <<"\n";
  }
  if (!defeated) {
    cout << "\nDo you want to conquer the castle?(Y/N)\n";
    string option;
    cin >> option;
    cin.ignore();
    if (option == "Y" || option == "y") {
      
      if(p.getGoblinsDefeated() >= 1 && p.getCrystalsCollected() >= 3){
      cout << "\n033[33mObjective Completed!\033[0m \n";
      defeated = true;
      cout << "\nYou conquered the castle!\n";
      
      std::exit(0);
      }else{
        cout<<"\n\033[31mYou need to collect 3 crystals and defeat 1 goblin to conquer the castle!\033[0m \n";
        std::cout << "Press enter to continue...\n";
        // cin.ignore();
        std::cin.get();
      }
      cout << endl;
    }
  }

  return 1;
}