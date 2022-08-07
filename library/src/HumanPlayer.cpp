//
// Created by student on 03.06.2022.
//

#include "HumanPlayer.h"
#include "Board.h"
#include "Sheep.h"
#include "Wolf.h"

HumanPlayer::~HumanPlayer() {

}

const std::string &HumanPlayer::getPlayerName() const {
    return playerName;
}

void HumanPlayer::move() {

    PolaWilka:

    if (isWolf1() == true) {
        std::cout << "Dostepne ruchy wilka:" << std::endl;
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
                        getPlayerUnits()[0]->getPolaNaKtoreMozeWejscJednostka().size(); i++) {
            std::cout << (i + 1) << ". "
                      << getPlayerUnits()[0]->getPolaNaKtoreMozeWejscJednostka()[i]->getCoordinates()
                      << std::endl;
        }
        unsigned int decyzjaOruchu;
        cin >> decyzjaOruchu;
        if((decyzjaOruchu < 1 && decyzjaOruchu > getPlayerUnits()[0]->getPolaNaKtoreMozeWejscJednostka().size()) || cin.fail())
        {
            getPlayerUnits()[0]->polaNaKtoreMozeWejscJednostka_Clear();
            throw std::runtime_error("Podano zly argument.");
        }

        getBoardSmPtr()->getFieldsTable()[temp]->getUnitSmPtr()->setUnitsField(getBoardSmPtr()->getFieldsTable()[temp]->getUnitSmPtr()->getPolaNaKtoreMozeWejscJednostka()[decyzjaOruchu - 1]);
        getBoardSmPtr()->getFieldsTable()[temp]->getUnitSmPtr()->getPolaNaKtoreMozeWejscJednostka()[decyzjaOruchu - 1]->setUnitSmPtr(getPlayerUnits()[0]);
        getBoardSmPtr()->getFieldsTable()[temp]->setUnitSmPtr(nullptr);

        getPlayerUnits()[0]->polaNaKtoreMozeWejscJednostka_Clear();

        if(getPlayerUnits()[0]->getUnitsField()->drawBonusMove())
        {
            std::cout << "Wolosowano dodatkowy ruch" << std::endl;
            goto PolaWilka;
        }

    }
    else
    {
        wyborOwieczki:
        std::cout << "Wybierz owce ktora chcesz sie ruszyc: ";
        int temppp = 0;
        for (int i = 0; i < 4; i++) {
            temppp++;
            std::cout << temppp << ". Owca " << getPlayerUnits()[i]->getPositionInfo() << std::endl;
        }


        unsigned int wyborOwcy;
        std::cin >> wyborOwcy;
        if((wyborOwcy < 1 && wyborOwcy > getPlayerUnits().size()) || cin.fail())
        {
            throw std::runtime_error("Podano zly argument.");
        }

        int iOwcy;
        for (int i = 0; i < 64; i++) {
            if (getBoardSmPtr()->getFieldsTable()[i]->getUnitSmPtr() == getPlayerUnits()[wyborOwcy - 1]) {
                iOwcy = i;
            }
        }


        std::cout << "Pola na ktore moze wejsc owca:" << std::endl;
        getPlayerUnits()[wyborOwcy - 1]->availableMoves();
        for (int i = 0; i < getPlayerUnits()[wyborOwcy - 1]->getPolaNaKtoreMozeWejscJednostka().size(); i++) {
            std::cout << (i + 1) << ". "
                      << getPlayerUnits()[wyborOwcy - 1]->getPolaNaKtoreMozeWejscJednostka()[i]->getCoordinates()
                      << std::endl;
        }

        unsigned int decyzjaORuchu;
        cin >> decyzjaORuchu;
        if((decyzjaORuchu < 1 && decyzjaORuchu > getPlayerUnits()[wyborOwcy - 1]->getPolaNaKtoreMozeWejscJednostka().size()) || cin.fail())
        {
            getPlayerUnits()[wyborOwcy - 1]->polaNaKtoreMozeWejscJednostka_Clear();
            throw std::runtime_error("Podano zly argument.");
        }


        getBoardSmPtr()->getFieldsTable()[iOwcy]->getUnitSmPtr()->setUnitsField(getPlayerUnits()[wyborOwcy - 1]->getPolaNaKtoreMozeWejscJednostka()[decyzjaORuchu - 1]);
        getPlayerUnits()[wyborOwcy - 1]->getPolaNaKtoreMozeWejscJednostka()[decyzjaORuchu - 1]->setUnitSmPtr(getPlayerUnits()[wyborOwcy - 1]);
        getBoardSmPtr()->getFieldsTable()[iOwcy]->setUnitSmPtr(nullptr);


        getPlayerUnits()[wyborOwcy - 1]->polaNaKtoreMozeWejscJednostka_Clear();

        if(getPlayerUnits()[wyborOwcy - 1]->getUnitsField()->drawBonusMove())
        {
            std::cout << "Wolosowano dodatkowy ruch" << std::endl;
            goto wyborOwieczki;
        }
    }
}









HumanPlayer::HumanPlayer(bool isHuman, bool isWolf, const std::shared_ptr<Board> &boardSmPtr,
                         const std::string &playerName) : Player(isHuman, isWolf, boardSmPtr), playerName(playerName) {}

void HumanPlayer::setPlayerName(const string &playerName) {
    HumanPlayer::playerName = playerName;
}




