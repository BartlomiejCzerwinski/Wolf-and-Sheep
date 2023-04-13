#ifndef CARRENTAL_GAME_H
#define CARRENTAL_GAME_H

#include <iostream>
#include <memory>
#include <vector>
#include "Player.h"
#include "HumanPlayer.h"
#include "Menu.h"
#include "Board.h"
#include "DataContainer.h"
#include "typedefs.h"
#include "Sheep.h"
#include "Wolf.h"
#include "UserInterface.h"
#include "ComputerPlayer.h"
#include <fstream>
#include <string>
#include <sstream>

class Game {
private:
    playerPtr player1SmPtr;
    playerPtr player2SmPtr;
    boardPtr boardSmPtr;
    dataContainerPtr dataContainerSmPtr;
    bool whoseTurn;

public:
Game* getwsk();
    void newGame();
    void theGame();
    void winConditions();
    void settingDataCOntainer();

    const dataContainerPtr &getDataContainerSmPtr() const;

    const playerPtr &getPlayer1SmPtr() const;

    const playerPtr &getPlayer2SmPtr() const;

    const boardPtr &getBoardSmPtr() const;

    bool isWhoseTurn() const;

    void setWhoseTurn(bool whoseTurn);

    Game();
void creatingGameFromFile();

};


#endif
