// player.cpp
#include "player.h"
#include <iostream>
using namespace std;

// Default constructor
Player::Player() {
  name = "";
  crystalsCollected = 0;
  goblinsDefeated = 0;
}

// Accessors
std::string Player::getName() const { return name; }

int Player::getCrystalsCollected() const { return crystalsCollected; }
int Player::getGoblinsDefeated() const { return goblinsDefeated; }

// Mutators
void Player::setName(const std::string &name) { this->name = name; }

void Player::setCrystalsCollected() { this->crystalsCollected += 1; }

void Player::setGoblinsDefeated() { this->goblinsDefeated += 1; }

// Functionality Method
void Player::print() const {
  cout << "Name: " << name << "\n";
  cout << endl;
}
