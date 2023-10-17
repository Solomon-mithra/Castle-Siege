#include "game.h"
#include "castle.h"
#include "crystal.h"
#include "goblin.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

// Constructor
Game::Game() : world(nullptr), rows(0), cols(0), playerRow(0), playerCol(0) {}

// Destructor
Game::~Game() {
  if (world != nullptr) {
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        delete world[i][j];
      }
      delete[] world[i];
    }
    delete[] world;
  }
}

// Method to set up the game world
void Game::setUpGame(const string &filename) {
  char goblinEmoji[] = u8"\U0001F47A";
  char diamondEmoji[] = u8"\U0001F48E";
  char castleEmoji[] = u8"\U0001F3EF";
  // setup game objective
  std::cout << R"(
      ▄▄▄▄▄▄▄ ▄▄▄▄▄▄▄ ▄▄   ▄▄ ▄▄▄▄▄▄▄ 
     █       █       █  █▄█  █       █
     █   ▄▄▄▄█   ▄   █       █    ▄▄▄█
     █  █  ▄▄█  █▄█  █       █   █▄▄▄ 
     █  █ █  █       █       █    ▄▄▄█
     █  █▄▄█ █   ▄   █ ██▄██ █   █▄▄▄ 
     █▄▄▄▄▄▄▄█▄▄█ █▄▄█▄█   █▄█▄▄▄▄▄▄▄█

)";
  std::cout << "Welcome to the game! Your objective is to find the "
            << diamondEmoji << "treasure and defeat the " << goblinEmoji
            << "goblin's to enter the Castle! " << castleEmoji << std::endl;
  cout << "\n\033[33mTask:\033[0m\n";
  cout << "\033[33mCollect 3 Crystals & Defeat 1 Goblin\033[0m\n";
#include <cstdlib>
#include <iostream>

  ifstream inputFile(filename);
  if (!inputFile.is_open()) {
    cerr << "Failed to open the input file." << endl;
    return;
  }
  
  std::cout << "Press enter to continue...";
  std::cin.get();

  

  inputFile >> rows >> cols;

  // Allocate memory for the world array
  world = new Location **[rows];
  for (int i = 0; i < rows; i++) {
    world[i] = new Location *[cols];
    for (int j = 0; j < cols; j++) {
      world[i][j] = nullptr;
    }
  }

  char locationType;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      inputFile >> locationType;
      switch (locationType) {
      case 'o':
        world[i][j] = new Location();
        break;
      case 'c':
        world[i][j] = new Castle('C');
        break;
      case 'g':
        world[i][j] = new Goblin('G');
        break;
      case 'r':
        world[i][j] = new Crystal('R');
        break;
      }
    }
  }

  inputFile.close();
}

// Method to draw the game world
void Game::drawGame() {

#ifdef _WIN32 // Check if running on Windows
  system("cls");
#else // Assume Unix-like system
  system("clear");
#endif

  char goblinEmoji[] = u8"\U0001F47A";
  char diamondEmoji[] = u8"\U0001F48E";
  cout << "\n" << diamondEmoji << ": " << p.getCrystalsCollected() << "  ";
  cout << goblinEmoji << ": " << p.getGoblinsDefeated() << "\n\n";

  // Loop through the world array and print the game world
  char smileyEmoji[] = u8"\U0001F916";
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (i == playerRow && j == playerCol) {
        cout << smileyEmoji; // Print the player symbol
      } else if (world[i][j] != nullptr) {
        world[i][j]->draw(); // Call the draw method for other locations
      } else {
        // cout <<(world[i][j] == nullptr);
        cout << ". "; // Empty space
      }
    }
    cout << endl;
  }
}

// Method to play the game
void Game::playGame() {
  bool continueExploring = true;

  while (continueExploring) {
    drawGame(); // Display the game world

    // Ask the user for a direction
    char move;
    cout << "Enter a direction (W/A/S/D) or Q to quit: ";
    cin >> move;

    // Check for valid move and update player position
    int newPlayerRow = playerRow;
    int newPlayerCol = playerCol;

    switch (move) {
    case 'W':
    case 'w':
      newPlayerRow--;
      break;
    case 'A':
    case 'a':
      newPlayerCol--;
      break;
    case 'S':
    case 's':
      newPlayerRow++;
      break;
    case 'D':
    case 'd':
      newPlayerCol++;
      break;
    case 'Q':
    case 'q':
      continueExploring = false;
      break;
    default:
      cout << "Invalid move. Try again." << endl;
      continue;
    }

    // Check if the new position is within bounds
    if (newPlayerRow >= 0 && newPlayerRow < rows && newPlayerCol >= 0 &&
        newPlayerCol < cols) {
      // Update player position
      playerRow = newPlayerRow;
      playerCol = newPlayerCol;

      // Call the visit method for the location
      if (world[playerRow][playerCol] != nullptr) {
        world[playerRow][playerCol]->visit(p);
      }
    } else {
      cout << "Invalid move. Try again." << endl;
    }
  }
}
