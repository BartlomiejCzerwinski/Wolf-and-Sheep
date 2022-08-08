#ifndef GRA_NA_PROJEKT_DATACONTAINER_H
#define GRA_NA_PROJEKT_DATACONTAINER_H

#include <iostream>
#include "Game.h"
#include "typedefs.h"
#include <fstream>


class DataContainer {
private:
gamePtr ptrForGame;

public:
    void saveGame();

    void setPtrForGame(const gamePtr &ptrForGame);

    DataContainer(const gamePtr &ptrForGame);

    virtual ~DataContainer();

};


#endif
