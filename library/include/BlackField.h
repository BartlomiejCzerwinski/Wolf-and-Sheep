//
// Created by student on 03.06.2022.
//

#ifndef GRA_NA_PROJEKT_BLACKFIELD_H
#define GRA_NA_PROJEKT_BLACKFIELD_H


#include "Field.h"
#include <iostream>
class Field;
class BlackField : public Field{
private:
    bool bonusMove = 0;
    bool isTaken;
public:
    BlackField(bool isBlack, int coordinateX, int coordinateY, const unitPtr &unitSmPtr, bool isTaken);

    virtual ~BlackField();

    bool drawBonusMove();

    bool isTaken1() const;

};


#endif //GRA_NA_PROJEKT_BLACKFIELD_H
