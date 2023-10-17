#ifndef CRYSTAL_H
#define CRYSTAL_H
using namespace std;
#include "location.h"

class Crystal : public Location {
private:
    bool taken;

public:
    // Constructor
    Crystal(char s = ' ');

    // Accessor
    bool getTaken() const;

    // Mutator
    void setTaken(bool t);

    // Functionality Methods
    void draw() ;
    int visit(Player &p) ;
};

#endif // CRYSTAL_H
