#ifndef GOBLIN_H
#define GOBLIN_H
using namespace std;
#include "location.h"

class Goblin : public Location {
private:
    bool defeated;

public:
    // Constructor
    Goblin(char s = ' ');

    // Accessor
    bool getDefeated() const;

    // Mutator
    void setDefeated(bool t);

    // Functionality Methods
    void draw() ;
    int visit(Player &p) ;
};

#endif // CRYSTAL_H
