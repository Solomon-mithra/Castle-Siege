#ifndef GAME_H
#define GAME_H
using namespace std;
#include "location.h"
#include "player.h"

class Game {
private:
  Location ***world;
  Player p;
  int rows;
  int cols;
  int playerRow;
  int playerCol;

public:
  // Constructor
  Game();

  // Destructor
  ~Game();

  // Method to set up the game world
void setUpGame(const string& filename);


  // Method to draw the game world
  void drawGame();

  //method draw()
  void draw(Player& P);

  // Method to play the game
  void playGame();
};

#endif // GAME_H
