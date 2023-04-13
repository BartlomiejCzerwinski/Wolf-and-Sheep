#include "Field.h"

class Board;

Field::~Field() {

}


Field::Field(bool isBlack, int coordinateX, int coordinateY, const unitPtr &unitSmPtr) : isBlack(isBlack),
                                                                                         coordinateX(coordinateX),
                                                                                         coordinateY(coordinateY),
                                                                                         unitSmPtr(unitSmPtr) {}

bool Field::isBlack1() const {
    return isBlack;
}

int Field::getCoordinateX() const {
    return coordinateX;
}

int Field::getCoordinateY() const {
    return coordinateY;
}

const unitPtr &Field::getUnitSmPtr() const {
    return unitSmPtr;
}

void Field::setUnitSmPtr(const unitPtr &unitSmPtr) {
    Field::unitSmPtr = unitSmPtr;
}

bool Field::isTaken1(){
    if(unitSmPtr== nullptr)
    return 0;
    else
        return 1;
}



std::string Field::getCoordinates() {
    return "( "+ std::to_string(getCoordinateX())+" , "+std::to_string(getCoordinateY())+" )";
}