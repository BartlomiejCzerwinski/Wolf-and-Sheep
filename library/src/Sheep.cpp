#include "Sheep.h"
#include "Board.h"

Sheep::~Sheep() {

}

Sheep::Sheep(const string &unitType, const fieldPtr &unitsField, const playerPtr &unitsPlayer, int sheepId) : Unit(
        unitType, unitsField, unitsPlayer), sheepId(sheepId) {}

void Sheep::availableMoves() {

 for(int i=0;i<64;i++){
     if(getUnitsPlayer()->getBoardSmPtr()->getFieldsTable()[i]==getUnitsField())
     {
         if(i+7 < 64)
         if(getUnitsPlayer()->getBoardSmPtr()->getFieldsTable()[i+7]->isBlack1()==1)
             if(getUnitsPlayer()->getBoardSmPtr()->getFieldsTable()[i+7]->isTaken1()==0)
         setFieldsThatUnitCanStandOn(getUnitsPlayer()->getBoardSmPtr()->getFieldsTable()[i+7]);

         if(i+9 < 64)
         if(getUnitsPlayer()->getBoardSmPtr()->getFieldsTable()[i+9]->isBlack1()==1)
             if(getUnitsPlayer()->getBoardSmPtr()->getFieldsTable()[i+9]->isTaken1()==0)
                 setFieldsThatUnitCanStandOn(getUnitsPlayer()->getBoardSmPtr()->getFieldsTable()[i+9]);
     }
 }

}

