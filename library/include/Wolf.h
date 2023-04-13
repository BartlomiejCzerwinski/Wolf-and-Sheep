#ifndef GRA_NA_PROJEKT_WOLF_H
#define GRA_NA_PROJEKT_WOLF_H

#include "Unit.h"

class Wolf : public Unit {
public:

    ~Wolf();
    Wolf(const string &unitType, const fieldPtr &unitsField, const playerPtr &unitsPlayer);

    void availableMoves();
};

#endif