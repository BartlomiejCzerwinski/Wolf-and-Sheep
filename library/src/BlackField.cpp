//
// Created by student on 03.06.2022.
//

#include "BlackField.h"
#include <ctime>
#include "Unit.h"

BlackField::~BlackField() {
    srand( time( NULL ) );
}

bool BlackField::drawBonusMove() {
    int x = rand() % 16 + 1;
    if(x == 1)
    {
        bonusMove = 1;
        return 1;
    }
    else
        return 0;
}

BlackField::BlackField(bool isBlack, int coordinateX, int coordinateY, const unitPtr &unitSmPtr,
                       bool isTaken) : Field(isBlack, coordinateX, coordinateY, unitSmPtr),
                                       isTaken(isTaken) {
    this->drawBonusMove();
}

bool BlackField::isTaken1() const {
    return isTaken;
}


