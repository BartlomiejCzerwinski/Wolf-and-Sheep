#ifndef GRA_NA_PROJEKT_FIELD_H
#define GRA_NA_PROJEKT_FIELD_H

#include <iostream>
#include "typedefs.h"
#include "Unit.h"
#include <string>

using namespace std;

class Field {
private:
    bool isBlack;
    int coordinateX;
    int coordinateY;
    unitPtr unitSmPtr;
public:
    Field(bool isBlack, int coordinateX, int coordinateY, const unitPtr &unitSmPtr);

    virtual ~Field();

    virtual bool drawBonusMove()=0;

    bool isBlack1() const;

    int getCoordinateX() const;

    int getCoordinateY() const;

    const unitPtr &getUnitSmPtr() const;

    void setUnitSmPtr(const unitPtr &unitSmPtr);

    virtual bool isTaken1();

    std::string getCoordinates();
};

#endif
