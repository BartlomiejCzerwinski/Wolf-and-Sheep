#include <iostream>
#include "Game.h"
#include "Field.h"
#include "Board.h"
#include "Menu.h"
#include "typedefs.h"
#include "UserInterface.h"
#include <time.h>



using namespace std;

int main() {
    srand(time(NULL));

Menu *menuwsk=new Menu;
Game *wskaznikgame = new Game();
wskaznikgame->settingDataCOntainer();

menuReturn:
int menuSwitch=menuwsk->options();

    switch(menuSwitch)
    {
        case 1:
            wskaznikgame->newGame();
            wskaznikgame->theGame();
            break;

        case 2:
            wskaznikgame->creatingGameFromFile();
            wskaznikgame->theGame();
            break;

        case 3:
            goto menuReturn;
            break;

        case 4:
            goto menuReturn;
            break;

        case 5:
            exit(0);
            break;
    }





    return 0;
}