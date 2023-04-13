#include "Menu.h"

Menu::Menu() {}

Menu::~Menu() {

}

int Menu::options() {

    for(;;) {
        char decision;

        std::cout << "Welcome in wolf and sheep!" << std::endl;
        std::cout << "__________ M E N U __________" << std::endl;
        std::cout << "1.New game" << std::endl;
        std::cout << "2.Load game" << std::endl;
        std::cout << "3.Guide" << std::endl;
        std::cout << "4.Authors" << std::endl;
        std::cout << "5.Exit" << std::endl;
        std::cin >> decision;
        switch (decision) {
            case '1':
                return 1;
                break;

            case '2':
                return 2;
                break;

            case '3':
                std::cout << "The objective of the player-wolf is to get through the board into the first row of the chessboard. The sheep-player wins when he successfully blocks the wolf so this one can't move." << std::endl << std::endl;
                std::cout << "GThe game is started by wolf-player. In one round player can make only one move by one field at the diagonal." << std::endl << std::endl;
                std::cout << "Pheep-player can move only ahead. Wolf-player can move at all sides." << std::endl << std::endl;
                std::cout << "After the move, there is a drawing, the player can win a bonus move in the current round."<<std::endl<<std::endl;
                return 3;
                break;

            case '4':
                std::cout<<"AUTHORS"<<std::endl;
                std::cout<<"Oskar Baranowski"<<std::endl;
                std::cout<<"Bartlomiej Czerwinski"<<std::endl<<std::endl;
                return 4;
                break;

            case '5':
                return 5;
                break;

            default:
                std::cout << "No such option !!!" << std::endl;
                break;
        }
    }
}
