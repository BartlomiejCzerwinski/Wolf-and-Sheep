#ifndef GRA_NA_PROJEKT_USERINTERFACE_H
#define GRA_NA_PROJEKT_USERINTERFACE_H

#include <iostream>
#include "Board.h"
#include "typedefs.h"

class UserInterface {
private:
    boardPtr boardPtrTable;
public:
    void drawBoard();

    UserInterface(boardPtr &boardPtrTable);

    virtual ~UserInterface();
};


#endif
