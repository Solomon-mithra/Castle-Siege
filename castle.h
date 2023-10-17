#ifndef CASTLE_H
#define CASTLE_H

#include "location.h"

class Castle : public Location {
private:
    bool defeated;

public:
    // Constructor
    Castle(char s = ' ');

    // Accessor
    bool getDefeated() const;

    // Mutator
    void setDefeated(bool d);

    // Functionality Methods
    void draw();
    int visit(Player &p);
};

#endif // CASTLE_H