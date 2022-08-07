//
// Created by student on 03.06.2022.
//

#include "ComputerPlayer.h"
#include <vector>
#include "Board.h"
#include "Sheep.h"

ComputerPlayer::~ComputerPlayer() {

}

const std::string &ComputerPlayer::getPlayerName() const {
    return playerName;
}

void ComputerPlayer::move(){
    std::cout<<"* KOMPUTER SIE RUSZA *"<<std::endl;
    PolaWilka:
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

        unsigned int decyzjaOruchu = rand() % getPlayerUnits()[0]->getPolaNaKtoreMozeWejscJednostka().size() + 1;

        getBoardSmPtr()->getFieldsTable()[temp]->getUnitSmPtr()->setUnitsField(getBoardSmPtr()->getFieldsTable()[temp]->getUnitSmPtr()->getPolaNaKtoreMozeWejscJednostka()[decyzjaOruchu - 1]);
        getBoardSmPtr()->getFieldsTable()[temp]->getUnitSmPtr()->getPolaNaKtoreMozeWejscJednostka()[decyzjaOruchu - 1]->setUnitSmPtr(getPlayerUnits()[0]);
        getBoardSmPtr()->getFieldsTable()[temp]->setUnitSmPtr(nullptr);

        getPlayerUnits()[0]->polaNaKtoreMozeWejscJednostka_Clear();

        if(getPlayerUnits()[0]->getUnitsField()->drawBonusMove())
        {
            goto PolaWilka;
        }

    }
    else
    {
        wyborOwieczki:
        unsigned int wyborOwcy = rand() % getPlayerUnits().size() + 1;

        int iOwcy;
        for (int i = 0; i < 64; i++) {
            if (getBoardSmPtr()->getFieldsTable()[i]->getUnitSmPtr() == getPlayerUnits()[wyborOwcy - 1]) {
                iOwcy = i;
            }
        }

        getPlayerUnits()[wyborOwcy - 1]->availableMoves();
        unsigned int decyzjaORuchu = rand() % getPlayerUnits()[wyborOwcy -1]->getPolaNaKtoreMozeWejscJednostka().size() + 1;

        getBoardSmPtr()->getFieldsTable()[iOwcy]->getUnitSmPtr()->setUnitsField(getPlayerUnits()[wyborOwcy - 1]->getPolaNaKtoreMozeWejscJednostka()[decyzjaORuchu - 1]);
        getPlayerUnits()[wyborOwcy - 1]->getPolaNaKtoreMozeWejscJednostka()[decyzjaORuchu - 1]->setUnitSmPtr(getPlayerUnits()[wyborOwcy - 1]);
        getBoardSmPtr()->getFieldsTable()[iOwcy]->setUnitSmPtr(nullptr);


        getPlayerUnits()[wyborOwcy - 1]->polaNaKtoreMozeWejscJednostka_Clear();

        if(getPlayerUnits()[wyborOwcy - 1]->getUnitsField()->drawBonusMove())
        {
            goto wyborOwieczki;
        }
    }
}

ComputerPlayer::ComputerPlayer(bool isHuman, bool isWolf, const std::shared_ptr<Board> &boardSmPtr) : Player(isHuman, isWolf, boardSmPtr){

}

void ComputerPlayer::setPlayerName(const std::string &playerName) {

}
