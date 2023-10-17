#include "goblin.h"
#include <iostream>
using namespace std;

// Constructor
Goblin::Goblin(char s) : Location() { defeated = false; }

// Accessor
bool Goblin::getDefeated() const { return defeated; }

// Mutator
void Goblin::setDefeated(bool d) { defeated = d; }

// Methods
void Goblin::draw() {
  char goblinEmoji[] = u8"\U0001F47A";
  char skullEmoji[] = u8"\U0001F480";
  if (visited && !defeated) {
    std::cout << goblinEmoji;
  } else if (defeated) {
    std::cout << skullEmoji;
  } else {
    std::cout << goblinEmoji;
  }
}

int Goblin::visit(Player &p) {
  char goblinEmoji[] = u8"\U0001F47A";
  char skullEmoji[] = u8"\U0001F480";
  char smileyEmoji[] = u8"\U0001F916";
  if (!visited) {
    visited = true;
    std::cout << "\033[32mYou encountered a goblin!\033[0m"<< goblinEmoji <<"\n";
  }
  if (!defeated) {
    cout << "\nDo you want to fight the goblin?(Y/N)\n";
    string option;
    cin >> option;
    cin.ignore();
    if (option == "Y" || option == "y") {
      cout << "\nSelect an attack level from (1-10):\n";
      int attack;
      cin >> attack;
      cout<< "\n"<< smileyEmoji<<" Your attack level: " << attack <<"\n";
      cout<< goblinEmoji <<" Goblin attack level: " << 5 <<"\n";
       if(attack > 5){ 
      defeated = true;
         p.setGoblinsDefeated();
      cout << "\033[32mYou defeated the goblin!!\033[0m " << skullEmoji <<"\n";}else{
         cout << "\033[32mThe goblin is not defeated!\033[0m "<< goblinEmoji <<"\n";
         cout << endl;
      }
      std::cout << "Press enter to continue...";
      cin.ignore();
      std::cin.get();
    }
  }
  
  return 1;
}