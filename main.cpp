#include "game.h"
#include <iostream>
using namespace std;

int main() {
  Game game; // Create a Game object

  // Set up the game world with the desired dimensions and player's starting
  // position
  game.setUpGame("dataFile.txt");

  // Play the game
  game.playGame();

  cout << "The End" << endl;
  return 0;
}
