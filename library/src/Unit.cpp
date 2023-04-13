#include "Unit.h"


Unit::~Unit() {

}

const std::string &Unit::getUnitType() const {
    return unitType;
}

void Unit::clearFieldsThatUnitCanStandOn() {
    fieldsThatUnitCanStandOn.clear();
}

string Unit::getPositionInfo() {
return getUnitsField()->getCoordinates();
}

const fieldPtr &Unit::getUnitsField() const {
    return unitsField;
}

const playerPtr &Unit::getUnitsPlayer() const {
    return unitsPlayer;
}

Unit::Unit(const string &unitType, const fieldPtr &unitsField, const playerPtr &unitsPlayer) : unitType(unitType),
                                                                                               unitsField(unitsField),
                                                                                               unitsPlayer(
                                                                                                       unitsPlayer) {}

void Unit::setUnitsField(const fieldPtr &unitsField) {
    Unit::unitsField = unitsField;
}

const vector<fieldPtr> &Unit::getFieldsThatUnitCanStandOn() const {
    return fieldsThatUnitCanStandOn;
}

void Unit::availableMoves() {

}

void Unit::setFieldsThatUnitCanStandOn(fieldPtr field) {
    fieldsThatUnitCanStandOn.push_back(field);
}




