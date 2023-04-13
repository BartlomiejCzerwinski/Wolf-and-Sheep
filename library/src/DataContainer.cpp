#include "DataContainer.h"
#include "json.hpp"

using json = nlohmann::json;

void DataContainer::saveGame() {

    std::vector<int> o;
    for(int i=0;i<64;i++)
    {
        if(ptrForGame->getBoardSmPtr()->getFieldsTable()[i]->isBlack1())
            if(ptrForGame->getBoardSmPtr()->getFieldsTable()[i]->isTaken1())
                if(ptrForGame->getBoardSmPtr()->getFieldsTable()[i]->getUnitSmPtr()->getUnitType()=="SHEEP")
                {
                    o.push_back(ptrForGame->getBoardSmPtr()->getFieldsTable()[i]->getUnitSmPtr()->getUnitsField()->getCoordinateX());
                    o.push_back(ptrForGame->getBoardSmPtr()->getFieldsTable()[i]->getUnitSmPtr()->getUnitsField()->getCoordinateY());
                }
    }

    for(int i=0;i<64;i++)
    {
        if(ptrForGame->getBoardSmPtr()->getFieldsTable()[i]->isBlack1())
            if(ptrForGame->getBoardSmPtr()->getFieldsTable()[i]->isTaken1())
                if(ptrForGame->getBoardSmPtr()->getFieldsTable()[i]->getUnitSmPtr()->getUnitType()=="WOLF")
                {
                    o.push_back(ptrForGame->getBoardSmPtr()->getFieldsTable()[i]->getUnitSmPtr()->getUnitsField()->getCoordinateX());
                    o.push_back(ptrForGame->getBoardSmPtr()->getFieldsTable()[i]->getUnitSmPtr()->getUnitsField()->getCoordinateY());
                    break;
                }
    }

    json j={
            {"isHumanPlayer1", ptrForGame->getPlayer1SmPtr()->isHuman1()},
            {"isWolfPlayer1", ptrForGame->getPlayer1SmPtr()->isWolf1()},
            {"namePlayer1", ptrForGame->getPlayer1SmPtr()->getPlayerName()},
            {"isHumanPlayer2", ptrForGame->getPlayer2SmPtr()->isHuman1()},
            {"isWolfPlayer2", ptrForGame->getPlayer2SmPtr()->isWolf1()},
            {"namePlayer2", ptrForGame->getPlayer2SmPtr()->getPlayerName()},
            {"sheep1X", o[0]},
            {"sheep1Y", o[1]},
            {"sheep2X", o[2]},
            {"sheep2Y", o[3]},
            {"sheep3X", o[4]},
            {"sheep3Y", o[5]},
            {"sheep4X", o[6]},
            {"sheep4Y", o[7]},
            {"wolfX", o[8]},
            {"wolfY", o[9]},
            {"whoseTurn", ptrForGame->isWhoseTurn()},
            };

    json jj;
    jj["a"]=j;

    std::string saveName;
    std::cout<<"Enter save name"<<std::endl;
    cin>>saveName;
    ofstream save(saveName);
    save<<jj.dump(4);
    save.close();
    std::cout<<"Successfully saved game!";
    exit(0);
}

DataContainer::~DataContainer() {

}

void DataContainer::setPtrForGame(const gamePtr &ptrForGame) {
    DataContainer::ptrForGame = ptrForGame;
}

DataContainer::DataContainer(const gamePtr &ptrForGame) : ptrForGame(ptrForGame) {}


