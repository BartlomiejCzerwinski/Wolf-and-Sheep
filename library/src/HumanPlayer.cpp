#include "HumanPlayer.h"
#include "Board.h"

HumanPlayer::~HumanPlayer() {

}

const std::string &HumanPlayer::getPlayerName() const {
    return playerName;
}

void HumanPlayer::move() {

    wolfFields:

    if (isWolf1() == true) {
        std::cout << "Wolf's available moves:" << std::endl;
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

        for (int i = 0; i <
                        getPlayerUnits()[0]->getFieldsThatUnitCanStandOn().size(); i++) {
            std::cout << (i + 1) << ". "
                      << getPlayerUnits()[0]->getFieldsThatUnitCanStandOn()[i]->getCoordinates()
                      << std::endl;
        }
        unsigned int selectedMove;
        cin >> selectedMove;
        if((selectedMove < 1 && selectedMove > getPlayerUnits()[0]->getFieldsThatUnitCanStandOn().size()) || cin.fail())
        {
            getPlayerUnits()[0]->clearFieldsThatUnitCanStandOn();
            throw std::runtime_error("Wrong option.");
        }

        getBoardSmPtr()->getFieldsTable()[temp]->getUnitSmPtr()->setUnitsField(getBoardSmPtr()->getFieldsTable()[temp]->getUnitSmPtr()->getFieldsThatUnitCanStandOn()[selectedMove - 1]);
        getBoardSmPtr()->getFieldsTable()[temp]->getUnitSmPtr()->getFieldsThatUnitCanStandOn()[selectedMove - 1]->setUnitSmPtr(getPlayerUnits()[0]);
        getBoardSmPtr()->getFieldsTable()[temp]->setUnitSmPtr(nullptr);

        getPlayerUnits()[0]->clearFieldsThatUnitCanStandOn();

        if(getPlayerUnits()[0]->getUnitsField()->drawBonusMove())
        {
            std::cout << "Bonus move!" << std::endl;
            goto wolfFields;
        }

    }
    else
    {
        sheepChoose:
        std::cout << "Select sheep that you want to move : ";
        int temppp = 0;
        for (int i = 0; i < 4; i++) {
            temppp++;
            std::cout << temppp << ". Sheep " << getPlayerUnits()[i]->getPositionInfo() << std::endl;
        }


        unsigned int selectedSheep;
        std::cin >> selectedSheep;
        if((selectedSheep < 1 && selectedSheep > getPlayerUnits().size()) || cin.fail())
        {
            throw std::runtime_error("Wrong option.");
        }

        int iSheep;
        for (int i = 0; i < 64; i++) {
            if (getBoardSmPtr()->getFieldsTable()[i]->getUnitSmPtr() == getPlayerUnits()[selectedSheep - 1]) {
                iSheep = i;
            }
        }


        std::cout << "Sheep's available moves:" << std::endl;
        getPlayerUnits()[selectedSheep - 1]->availableMoves();
        for (int i = 0; i < getPlayerUnits()[selectedSheep - 1]->getFieldsThatUnitCanStandOn().size(); i++) {
            std::cout << (i + 1) << ". "
                      << getPlayerUnits()[selectedSheep - 1]->getFieldsThatUnitCanStandOn()[i]->getCoordinates()
                      << std::endl;
        }

        unsigned int selectedMove;
        cin >> selectedMove;
        if((selectedMove < 1 && selectedMove > getPlayerUnits()[selectedSheep - 1]->getFieldsThatUnitCanStandOn().size()) || cin.fail())
        {
            getPlayerUnits()[selectedSheep - 1]->clearFieldsThatUnitCanStandOn();
            throw std::runtime_error("Wrong option.");
        }

        getBoardSmPtr()->getFieldsTable()[iSheep]->getUnitSmPtr()->setUnitsField(getPlayerUnits()[selectedSheep - 1]->getFieldsThatUnitCanStandOn()[selectedMove - 1]);
        getPlayerUnits()[selectedSheep - 1]->getFieldsThatUnitCanStandOn()[selectedMove - 1]->setUnitSmPtr(getPlayerUnits()[selectedSheep - 1]);
        getBoardSmPtr()->getFieldsTable()[iSheep]->setUnitSmPtr(nullptr);
        getPlayerUnits()[selectedSheep - 1]->clearFieldsThatUnitCanStandOn();

        if(getPlayerUnits()[selectedSheep - 1]->getUnitsField()->drawBonusMove())
        {
            std::cout << "Bonus move!" << std::endl;
            goto sheepChoose;
        }
    }
}

HumanPlayer::HumanPlayer(bool isHuman, bool isWolf, const std::shared_ptr<Board> &boardSmPtr,
                         const std::string &playerName) : Player(isHuman, isWolf, boardSmPtr), playerName(playerName) {}

void HumanPlayer::setPlayerName(const string &playerName) {
    HumanPlayer::playerName = playerName;
}




