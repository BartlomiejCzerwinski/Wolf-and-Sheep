//
// Created by student on 03.06.2022.
//

#ifndef GRA_NA_PROJEKT_WHITEFIELD_H
#define GRA_NA_PROJEKT_WHITEFIELD_H

#include <iostream>

#include "Field.h"



class WhiteField : public Field {
public:
    WhiteField(bool isBlack, int coordinateX, int coordinateY, const unitPtr &unitSmPtr);

    ~WhiteField();

    bool drawBonusMove();



};


#endif //GRA_NA_PROJEKT_WHITEFIELD_H
