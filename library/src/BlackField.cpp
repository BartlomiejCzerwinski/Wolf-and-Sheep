#include "BlackField.h"
#include "Unit.h"

BlackField::~BlackField() {

}

bool BlackField::drawBonusMove() {
    int x = rand() % 16 + 1;
    if(x == 1){
        bonusMove = 1;
        return 1;
    }
    else {
        return 0;
    }
}

BlackField::BlackField(bool isBlack, int coordinateX, int coordinateY, const unitPtr &unitSmPtr,
                       bool isTaken) : Field(isBlack, coordinateX, coordinateY, unitSmPtr),
                                       isTaken(isTaken) {
}



