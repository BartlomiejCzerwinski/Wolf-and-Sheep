//
// Created by student on 03.06.2022.
//

#include "Menu.h"
#include <unistd.h>

Menu::Menu() {}

Menu::~Menu() {

}

int Menu::options() {


    for(;;) {
        char decision;

        std::cout << "Witaj w Wilk i Owce!" << std::endl;
        std::cout << "__________ M E N U __________" << std::endl;
        std::cout << "1.Nowa gra" << std::endl;
        std::cout << "2.Wczytaj gre" << std::endl;
        std::cout << "3.Instrukcja" << std::endl;
        std::cout << "4.Autorzy" << std::endl;
        std::cout << "5.Wyjscie" << std::endl;
        std::cin >> decision;
        switch (decision) {
            case '1':
                return 1;
                break;

            case '2':
                return 2;
                break;

            case '3':
                std::cout << "Celem gracza-wilka jest przedostanie się na pierwszy rząd pól szachownicy. Gracz dysponujący owcami wygrywa, gdy uda mu się zablokować wilka tak, żeby nie mógł on wykonać posunięcia." << std::endl << std::endl;
                std::cout << "Grę rozpoczyna gracz grający wilkiem. W jednym ruchu może przejść o jedno pole po przekątnej w dowolną stronę." << std::endl << std::endl;
                std::cout << "Piony gracza grającego owcami w kolejnych posunięciach przechodzą także o jedno pole po przekątnej, lecz tylko do przodu. Wilk może cofać się, owce nie mogą się cofać." << std::endl << std::endl;
                std::cout<<"Po wykonaniu ruchu przez gracza losowany jest bonusowy ruch, ktory gracz wykonuje w swojej aktualnej turze"<<std::endl<<std::endl;
                std::cout << "Aby zapisac gre i wyjsc wpisz 9999" << std::endl;
                std::cout << "Aby wyjsc z gry wpisz 1111" << std::endl<<std::endl;
                return 3;
                break;

            case '4':
                std::cout<<"AUTORZY"<<std::endl;
                std::cout<<"Oskar Baranowski"<<std::endl;
                std::cout<<"Bartlomiej Czerwinski"<<std::endl<<std::endl;
                return 4;
                break;

            case '5':
                return 5;
                break;

            default:
                std::cout << "Nie ma takiej Opcji!!! " << std::endl;
                break;
        }
    }
}
