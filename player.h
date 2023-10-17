// player.h
#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player {
public:
    // Constructors
    Player(); // Default constructor
    Player(const std::string& name, int& crystalsCollected, int& goblinsDefeated );

    // Accessors
    std::string getName() const;
    int getAge() const;
    int getGoblinsDefeated() const;
    int getCrystalsCollected() const;

    // Mutators
    void setName(const std::string& name);
    void setGoblinsDefeated();
    void setCrystalsCollected();

    // Functionality Methods
    void print() const;

private:
    std::string name;
    int crystalsCollected;
    int goblinsDefeated;

};

#endif // PLAYER_H
