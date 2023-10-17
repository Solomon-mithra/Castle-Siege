#ifndef LOCATION_H
#define LOCATION_H

#include "player.h"

class Location {
protected:
    bool visited;

public:
    // Constructor
    Location();

    // Accessors
    bool getVisited() const;
    char getSymbol() const;

    // Mutators
    void setVisited(bool v);
    void setSymbol(char s);

    // Functionality Methods
    virtual void draw();
    virtual int visit(Player &p);
};

#endif // LOCATION_H
