#ifndef GRA_NA_PROJEKT_SHEEP_H
#define GRA_NA_PROJEKT_SHEEP_H

#include "Unit.h"

class Sheep : public Unit {
private:
    int sheepId;
public:
   Sheep(const string &unitType, const fieldPtr &unitsField, const playerPtr &unitsPlayer, int sheepId);

    ~Sheep();

    int getSheepId() const;

    void availableMoves();


};


#endif //GRA_NA_PROJEKT_SHEEP_H
