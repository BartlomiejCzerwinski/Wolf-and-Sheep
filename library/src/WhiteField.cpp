//
// Created by student on 03.06.2022.
//

#include "WhiteField.h"

bool WhiteField::drawBonusMove() {
return 0;
}

WhiteField::~WhiteField() {

}

WhiteField::WhiteField(bool isBlack, int coordinateX, int coordinateY, const unitPtr &unitSmPtr) : Field(isBlack,
                                                                                                         coordinateX,
                                                                                                         coordinateY,
                                                                                                         unitSmPtr) {}





