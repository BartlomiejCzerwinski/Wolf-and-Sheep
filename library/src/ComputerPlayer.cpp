#include "ComputerPlayer.h"
#include "Board.h"

ComputerPlayer::~ComputerPlayer() {

}

const std::string &ComputerPlayer::getPlayerName() const {
    return playerName;
}

void ComputerPlayer::move(){
    std::cout<<"* COMPUTER IS MOVING *"<<std::endl;
    WolfFields:
    if (isWolf1() == true) {
        int temp;

        for (int i = 0; i < 64; i++) {

            if (getBoardSmPtr()->getFieldsTable()[i]->isBlack1()) {
                if (getBoardSmPtr()->getFieldsTable()[i]->getUnitSmPtr() != nullptr)
                    if (getBoardSmPtr()->getFieldsTable()[i]->getUnitSmPtr()->getUnitType() == "WOLF") {
                        temp = i;
                        break;
                    }
            }
        }
        getPlayerUnits()[0]->availableMoves();

        unsigned int moveDecision = rand() % getPlayerUnits()[0]->getFieldsThatUnitCanStandOn().size() + 1;

        getBoardSmPtr()->getFieldsTable()[temp]->getUnitSmPtr()->setUnitsField(getBoardSmPtr()->getFieldsTable()[temp]->getUnitSmPtr()->getFieldsThatUnitCanStandOn()[moveDecision - 1]);
        getBoardSmPtr()->getFieldsTable()[temp]->getUnitSmPtr()->getFieldsThatUnitCanStandOn()[moveDecision - 1]->setUnitSmPtr(getPlayerUnits()[0]);
        getBoardSmPtr()->getFieldsTable()[temp]->setUnitSmPtr(nullptr);

        getPlayerUnits()[0]->clearFieldsThatUnitCanStandOn();

        if(getPlayerUnits()[0]->getUnitsField()->drawBonusMove())
        {
            goto WolfFields;
        }

    }
    else
    {
        SheepMove:
        unsigned int selectedSheep = rand() % getPlayerUnits().size() + 1;

        int iSheep;
        for (int i = 0; i < 64; i++) {
            if (getBoardSmPtr()->getFieldsTable()[i]->getUnitSmPtr() == getPlayerUnits()[selectedSheep - 1]) {
                iSheep = i;
            }
        }

        getPlayerUnits()[selectedSheep - 1]->availableMoves();
        unsigned int moveDecision = rand() % getPlayerUnits()[selectedSheep -1]->getFieldsThatUnitCanStandOn().size() + 1;

        getBoardSmPtr()->getFieldsTable()[iSheep]->getUnitSmPtr()->setUnitsField(getPlayerUnits()[selectedSheep - 1]->getFieldsThatUnitCanStandOn()[moveDecision - 1]);
        getPlayerUnits()[selectedSheep - 1]->getFieldsThatUnitCanStandOn()[moveDecision - 1]->setUnitSmPtr(getPlayerUnits()[selectedSheep - 1]);
        getBoardSmPtr()->getFieldsTable()[iSheep]->setUnitSmPtr(nullptr);


        getPlayerUnits()[selectedSheep - 1]->clearFieldsThatUnitCanStandOn();

        if(getPlayerUnits()[selectedSheep - 1]->getUnitsField()->drawBonusMove())
        {
            goto SheepMove;
        }
    }
}

ComputerPlayer::ComputerPlayer(bool isHuman, bool isWolf, const std::shared_ptr<Board> &boardSmPtr) : Player(isHuman, isWolf, boardSmPtr){

}

void ComputerPlayer::setPlayerName(const std::string &playerName) {

}
