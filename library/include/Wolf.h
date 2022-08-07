//
// Created by student on 03.06.2022.
//

#ifndef GRA_NA_PROJEKT_WOLF_H
#define GRA_NA_PROJEKT_WOLF_H
#include "Unit.h"

class Wolf : public Unit {
private:

public:
    

    ~Wolf();
    Wolf(const string &unitType, const fieldPtr &unitsField, const playerPtr &unitsPlayer);

    void availableMoves();


};


#endif //GRA_NA_PROJEKT_WOLF_H
