//
// Created by student on 03.06.2022.
//

#include "WhiteField.h"

bool WhiteField::drawBonusMove() {
//std::cout<<"Biale pole nie losuje bonusowego ruchu - jednostka nie moze zostac na nim umieszczona"<<std::endl;
return 0;
}

WhiteField::~WhiteField() {

}

WhiteField::WhiteField(bool isBlack, int coordinateX, int coordinateY, const unitPtr &unitSmPtr) : Field(isBlack,
                                                                                                         coordinateX,
                                                                                                         coordinateY,
                                                                                                         unitSmPtr) {}





