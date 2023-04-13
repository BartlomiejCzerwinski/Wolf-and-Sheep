#include <iostream>
#include "Game.h"
#include "Menu.h"
#include <time.h>



using namespace std;

int main() {
    srand(time(NULL));

Menu *menuPtr=new Menu;
Game *gamePtr = new Game();
gamePtr->settingDataCOntainer();

menuReturn:
int menuSwitch=menuPtr->options();

    switch(menuSwitch)
    {
        case 1:
            gamePtr->newGame();
            gamePtr->theGame();
            break;

        case 2:
            gamePtr->creatingGameFromFile();
            gamePtr->theGame();
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