//
// Created by student on 03.06.2022.
//

#include "Game.h"
#include "typedefs.h"
#include "Field.h"
#include "Player.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"
#include "json.hpp"
using json = nlohmann::json;
void Game::settingDataCOntainer(){
dataContainerSmPtr= static_cast<const shared_ptr<DataContainer>>(new DataContainer(static_cast<const gamePtr>(this)));
};

void Game::newGame() {

    whoseTurn=0;
    //Tworzenie graczy************************************************************************
    std::cout<<"__________ TWORZENIE NOWEJ GRY __________"<<std::endl;
    std::cout<<"GRACZ 1:"<<std::endl;
    std::string tempNamePlayer1;
    std::cout<<"Podaj imie gracza:"<<std::endl;
    std::cin>>tempNamePlayer1;
    unsigned int chooseSide1;
    while(chooseSide1!=1&&chooseSide1!=2) {
        std::cout << "Wybierz strone: 1.Owce ; 2.Wilk" << std::endl;
        std::cin>>chooseSide1;
        if(chooseSide1!=1&&chooseSide1!=2)
            std::cout<<"PROSZE WYBRAC WLASCIWA OPCJE!!!"<<std::endl;
    }
    chooseSide1--;
    std::cout<<"GRACZ 2:"<<std::endl;
    unsigned int whoIsPlayer2;
    std::cout<<"Gracz jest innym graczem czy komputerem? (1.gracz 2.komputer):"<<std::endl;
    std::cin>>whoIsPlayer2;
    std::string tempNamePlayer2;
    if(whoIsPlayer2==1)
    {
        std::cout<<"Podaj imie gracza:"<<std::endl;
        std::cin>>tempNamePlayer2;
    }

    unsigned int player2Unit;
    if(chooseSide1==1)
        player2Unit=0;
    else
        player2Unit=1;

    player1SmPtr= static_cast<const shared_ptr<Player>>(new HumanPlayer(1, chooseSide1, nullptr, tempNamePlayer1));
    if(whoIsPlayer2==1)
    {

        player2SmPtr= static_cast<const shared_ptr<Player>>(new HumanPlayer(1, player2Unit, nullptr, tempNamePlayer2));

    }
    if(whoIsPlayer2==2)
    {

        player2SmPtr= static_cast<const shared_ptr<Player>>(new ComputerPlayer(0,player2Unit,nullptr));
    }
    //Tworzenie graczy************************************************************************

    //Tworzenie jednostek********************************************************************

    std::vector<unitPtr> newSheeps;
    unitPtr newWolf;
    if(!(player1SmPtr->isWolf1())) {
        for (int i = 0; i < 4; i++) {
            newSheeps.push_back(static_cast<const shared_ptr<Unit>>(new Sheep("SHEEP", nullptr, player1SmPtr, i+1)));
            player1SmPtr->addUnit(newSheeps[i]);
        }

         newWolf = static_cast<const shared_ptr<Unit>>(new Wolf("WOLF", nullptr, player2SmPtr));
        player2SmPtr->addUnit(newWolf);
    }
    else
    {
        for (int i = 0; i < 4; i++) {
            newSheeps.push_back(static_cast<const shared_ptr<Unit>>(new Sheep("SHEEP", nullptr, player2SmPtr, i+1)));
            player2SmPtr->addUnit(newSheeps[i]);
        }

        newWolf = static_cast<const shared_ptr<Unit>>(new Wolf("WOLF", nullptr, player1SmPtr));
        player1SmPtr->addUnit(newWolf);
    }
    //Tworzenie jednostek********************************************************************

    //Tworzenie planszy************************************************************************
    boardSmPtr= std::make_shared<Board>(64);
    player1SmPtr->setBoardSmPtr(boardSmPtr);
    player2SmPtr->setBoardSmPtr(boardSmPtr);
    //Tworzenie planszy************************************************************************

    int temp=1;
    for (int i = 0; i < 4; i++) {

        newSheeps[i]->setUnitsField((const shared_ptr<Field> &) boardSmPtr->getFieldsTable()[temp]);
        boardSmPtr->getFieldsTable()[temp]->setUnitSmPtr(newSheeps[i]);

        temp+=2;
    }
    unsigned int wyborPozycjiWilka;
    if(whoIsPlayer2==2&&player1SmPtr->isWolf1()==0){
        srand(time(NULL));
        wyborPozycjiWilka=rand() % 4 + 1;
        goto pomininterakcjegracza;
    }//************************************
    std::cout<<"Wybierz pole startowe dla Wilka:"<<std::endl;
    std::cout<<"1. ( 1 ; 8 )"<<std::endl;
    std::cout<<"2. ( 3 ; 8 )"<<std::endl;
    std::cout<<"3. ( 5 ; 8 )"<<std::endl;
    std::cout<<"4. ( 7 ; 8 )"<<std::endl;
    std::cin>>wyborPozycjiWilka;
    while((wyborPozycjiWilka < 1 || wyborPozycjiWilka > 4) || cin.fail())
    {
        cout << "Podaj prawidlowa opcje!" << endl;
        std::cin.clear();
        std::cin.ignore(256, '\n');
        std::cin >> wyborPozycjiWilka;
    }
    pomininterakcjegracza:
    switch(wyborPozycjiWilka)
    {
        case 1:
            newWolf->setUnitsField((const shared_ptr<Field> &) boardSmPtr->getFieldsTable()[56]);
            boardSmPtr->getFieldsTable()[56]->setUnitSmPtr(newWolf);
            break;

        case 2:
            newWolf->setUnitsField((const shared_ptr<Field> &) boardSmPtr->getFieldsTable()[58]);
            boardSmPtr->getFieldsTable()[58]->setUnitSmPtr(newWolf);
            break;

        case 3:
            newWolf->setUnitsField((const shared_ptr<Field> &) boardSmPtr->getFieldsTable()[60]);
            boardSmPtr->getFieldsTable()[60]->setUnitSmPtr(newWolf);
            break;

        case 4:
            newWolf->setUnitsField((const shared_ptr<Field> &) boardSmPtr->getFieldsTable()[62]);
            boardSmPtr->getFieldsTable()[62]->setUnitSmPtr(newWolf);
            break;




    }

}
void Game::theGame() {
    int a;
    UserInterface interfejs(boardSmPtr);
    while (1) {
//*************************************************************
        if (whoseTurn == 0) {
            wykonajRuchGracza1:
            cout << "Ruch gracza: " + player1SmPtr->getPlayerName() << endl;
            interfejs.drawBoard();
            try
            {
                player1SmPtr->move();
            }
            catch(std::runtime_error & e)
            {
               cout << e.what() << " Wykonaj ruch jeszcze raz!" << endl;
                std::cin.clear();
                std::cin.ignore(256, '\n');
               goto wykonajRuchGracza1;
            }
                int bla = 0;
                czyZapisac1:
                try {
                    cout << "Jesli chcesz zapisac gre i wyjsc wpisz 1, jesli chcesz grac dalej wpisz 2: ";
                    std::cin >> bla;
                    while ((bla != 1 && bla != 2) || cin.fail()) {
                        throw std::runtime_error("Podano zly argument.");
                    }
                }
            catch(std::runtime_error & e)
            {
                    cout << e.what() << " Podaj prawidlowa opcje!" << endl;
                    std::cin.clear();
                    std::cin.ignore(256, '\n');
                    goto czyZapisac1;
            }
            if(bla == 1)
            {
                dataContainerSmPtr->saveGame();
            }
            winConditions();
            whoseTurn=1;
        }
        else
        {

//*************************************************************
            wykonajRuchGracza2:
            cout << "Ruch gracza: " + player2SmPtr->getPlayerName() << endl;
            interfejs.drawBoard();
            try
            {
                player2SmPtr->move();
            }
            catch(std::runtime_error & e)
            {
                cout << e.what() << " Wykonaj ruch jeszcze raz!" << endl;
                std::cin.clear();
                std::cin.ignore(256, '\n');
                goto wykonajRuchGracza2;
            }
            int bla = 0;
            czyZapisac2:
            try {
                cout << "Jesli chcesz zapisac gre i wyjsc wpisz 1, jesli chcesz grac dalej wpisz 2: ";
                std::cin >> bla;
                while ((bla != 1 && bla != 2) || cin.fail()) {
                    throw std::runtime_error("Podano zly argument.");
                }
            }
            catch(std::runtime_error & e)
            {
                cout << e.what() << " Podaj prawidlowa opcje!" << endl;
                std::cin.clear();
                std::cin.ignore(256, '\n');
                goto czyZapisac2;
            }
            if(bla == 1)
            {
                dataContainerSmPtr->saveGame();
            }
            winConditions();
            whoseTurn=0;
            //***************************
        }
    }
    }


void Game::winConditions() {
    if(boardSmPtr->getFieldsTable()[1]->getUnitSmPtr() != nullptr)
    {
        if(boardSmPtr->getFieldsTable()[1]->getUnitSmPtr()->getUnitType() == "WOLF")
        {
            std::cout << "KONIEC GRY. WILK WYGRYWA!";
            exit(0);
        }
    }
    if(boardSmPtr->getFieldsTable()[3]->getUnitSmPtr() != nullptr)
    {
        if(boardSmPtr->getFieldsTable()[3]->getUnitSmPtr()->getUnitType() == "WOLF")
        {
            std::cout << "KONIEC GRY. WILK WYGRYWA!";
            exit(0);
        }
    }
    if(boardSmPtr->getFieldsTable()[5]->getUnitSmPtr() != nullptr)
    {
        if(boardSmPtr->getFieldsTable()[5]->getUnitSmPtr()->getUnitType() == "WOLF")
        {
            std::cout << "KONIEC GRY. WILK WYGRYWA!";
            exit(0);
        }
    }
    if(boardSmPtr->getFieldsTable()[7]->getUnitSmPtr() != nullptr)
    {
        if(boardSmPtr->getFieldsTable()[7]->getUnitSmPtr()->getUnitType() == "WOLF")
        {
            std::cout << "KONIEC GRY. WILK WYGRYWA!";
            exit(0);
        }
    }
    int licznik1 = 0;
    int licznik2 = 0;
    for(int i=0;i<getPlayer1SmPtr()->getPlayerUnits().size();i++)
    {
        if(getPlayer1SmPtr()->isWolf1())
            getPlayer1SmPtr()->getPlayerUnits()[i]->availableMoves();
        if(getPlayer1SmPtr()->getPlayerUnits()[i]->getPolaNaKtoreMozeWejscJednostka().empty())
        {
            licznik1++;
        }
        if(!getPlayer1SmPtr()->isWolf1())
            getPlayer1SmPtr()->getPlayerUnits()[i]->availableMoves();
        if(getPlayer1SmPtr()->getPlayerUnits()[i]->getPolaNaKtoreMozeWejscJednostka().empty())
        {
            licznik2++;
        }
        getPlayer1SmPtr()->getPlayerUnits()[i]->polaNaKtoreMozeWejscJednostka_Clear();
    }
    if(licznik1 == 1)
    {
        std::cout << "KONIEC GRY, WILK NIE MA RUCHU. OWCE WYGRYWAJA!";
        exit(0);
    }
    if(licznik2 == 4)
    {
        std::cout << "KONIEC GRY, OWCE NIE MAJA RUCHU. WILK WYGRYWA!";
        exit(0);
    }
    licznik1 = 0;
    licznik2 = 0;
    for(int i=0;i<getPlayer2SmPtr()->getPlayerUnits().size();i++)
    {
        if(getPlayer2SmPtr()->isWolf1())
            getPlayer2SmPtr()->getPlayerUnits()[i]->availableMoves();
        if(getPlayer2SmPtr()->getPlayerUnits()[i]->getPolaNaKtoreMozeWejscJednostka().empty())
        {
            licznik1++;
        }
        if(!getPlayer2SmPtr()->isWolf1())
            getPlayer2SmPtr()->getPlayerUnits()[i]->availableMoves();
        if(getPlayer2SmPtr()->getPlayerUnits()[i]->getPolaNaKtoreMozeWejscJednostka().empty())
        {
            licznik2++;
        }
        getPlayer2SmPtr()->getPlayerUnits()[i]->polaNaKtoreMozeWejscJednostka_Clear();
    }
    if(licznik1 == 1)
    {
        std::cout << "KONIEC GRY, WILK NIE MA RUCHU. OWCE WYGRYWAJA!";
        exit(0);
    }
    if(licznik2 == 4)
    {
        std::cout << "KONIEC GRY, OWCE NIE MAJA RUCHU. WILK WYGRYWA!";
        exit(0);
    }
}

void Game::creatingGameFromFile() {
    player1SmPtr= static_cast<const shared_ptr<Player>>(new HumanPlayer(0, 0, nullptr, ""));
    ifstream wczytajGre;
    ponownePodanieNazwySavea:
    std::string saveName;
    std::cout<<"Podaj nazwe pliku z zapisanym stanem gry: "<<std::endl;
    cin>>saveName;
    wczytajGre.open(saveName);
    if(wczytajGre.good()==false)
    {
        std::cout<<"Podane niepoprawna nazwe pliku!"<<std::endl<<"Prosze podac poprawna nazwe pliku."<<std::endl;
        goto ponownePodanieNazwySavea;
    }
    json j;
    wczytajGre>>j;
    bool p1ih,p1iw,p2ih,p2iw,wt;
    std::string p1n,p2n;
    int s1x,s1y,s2x,s2y,s3x,s3y,s4x,s4y,wx,wy;
    for(const auto& create : j)
    {
        p1ih=create["isHumanPlayer1"];
        p2ih=create["isHumanPlayer2"];
        p1iw=create["isWolfPlayer1"];
        p2iw=create["isWolfPlayer2"];
        p1n=create["namePlayer1"];
        p2n=create["namePlayer2"];
        s1x=create["sheep1X"];
        s1y=create["sheep1Y"];
        s2x=create["sheep2X"];
        s2y=create["sheep2Y"];
        s3x=create["sheep3X"];
        s3y=create["sheep3Y"];
        s4x=create["sheep4X"];
        s4y=create["sheep4Y"];
        wt=create["whoseTurn"];
        wx=create["wolfX"];
        wy=create["wolfY"];
    }
    std::cout<<"player 1 name:"<<p1ih<<std::endl;
    std::cout<<"player 1 name:"<<p2ih<<std::endl;
    std::cout<<"player 1 is wolf:"<<p1iw<<std::endl;
    std::cout<<"player 2 is wolf:"<<p2iw<<std::endl;
    std::cout<<"player 1 name:"<<p1n<<std::endl;
    std::cout<<"player 2 name:"<<p2n<<std::endl;
    std::cout<<"sheep 1 x:"<<s1x<<std::endl;
    std::cout<<"sheep 1 y:"<<s1y<<std::endl;
    std::cout<<"sheep 2 x:"<<s2x<<std::endl;
    std::cout<<"sheep 2 y:"<<s2y<<std::endl;
    std::cout<<"sheep 3 x:"<<s3x<<std::endl;
    std::cout<<"sheep 3 y:"<<s3y<<std::endl;
    std::cout<<"sheep 4 x:"<<s4x<<std::endl;
    std::cout<<"sheep 4 y:"<<s4y<<std::endl;
    std::cout<<"whose turn: "<<wt<<std::endl;
    std::cout<<"wolf x:"<<wx<<std::endl;
    std::cout<<"wolf y:"<<wy<<std::endl;

    wczytajGre.close();
    player1SmPtr->setIsHuman(p1ih);
    player1SmPtr->setIsWolf(p1iw);
    player1SmPtr->setPlayerName(p1n);
    if(p2ih==0)
    {
        player2SmPtr= static_cast<const shared_ptr<Player>>(new ComputerPlayer(0, 0, nullptr));
    }
    else
    {
        player2SmPtr= static_cast<const shared_ptr<Player>>(new HumanPlayer(1, 0, nullptr, ""));
        player2SmPtr->setPlayerName(p2n);
    }
    player2SmPtr->setIsWolf(p2iw);
    std::vector<unitPtr> newSheeps;
    unitPtr newWolf;
    //**********************************************
    if(!(player1SmPtr->isWolf1())) {
        for (int i = 0; i < 4; i++) {
            newSheeps.push_back(static_cast<const shared_ptr<Unit>>(new Sheep("SHEEP", nullptr, player1SmPtr, i+1)));
            player1SmPtr->addUnit(newSheeps[i]);
        }

        newWolf = static_cast<const shared_ptr<Unit>>(new Wolf("WOLF", nullptr, player2SmPtr));
        player2SmPtr->addUnit(newWolf);
    }
    else
    {
        for (int i = 0; i < 4; i++) {
            newSheeps.push_back(static_cast<const shared_ptr<Unit>>(new Sheep("SHEEP", nullptr, player2SmPtr, i+1)));
            player2SmPtr->addUnit(newSheeps[i]);
        }

        newWolf = static_cast<const shared_ptr<Unit>>(new Wolf("WOLF", nullptr, player1SmPtr));
        player1SmPtr->addUnit(newWolf);
    }
//**********************************************
    boardSmPtr= std::make_shared<Board>(64);
    player1SmPtr->setBoardSmPtr(boardSmPtr);
    player2SmPtr->setBoardSmPtr(boardSmPtr);
    int Q=0;


    for(int a=0;a<64;a++)
    {
        if((boardSmPtr->getFieldsTable()[a]->getCoordinateX()==s1x)&&boardSmPtr->getFieldsTable()[a]->getCoordinateY()==s1y)
        {
            boardSmPtr->getFieldsTable()[a]->setUnitSmPtr(newSheeps[Q]);
            newSheeps[Q]->setUnitsField(boardSmPtr->getFieldsTable()[a]);
            if(!getPlayer1SmPtr()->isWolf1())
            {
                boardSmPtr->getFieldsTable()[a]->setUnitSmPtr(getPlayer1SmPtr()->getPlayerUnits()[Q]);
                getPlayer1SmPtr()->getPlayerUnits()[Q]->setUnitsField(boardSmPtr->getFieldsTable()[a]);
            }
            else
            {
                boardSmPtr->getFieldsTable()[a]->setUnitSmPtr(getPlayer2SmPtr()->getPlayerUnits()[Q]);
                getPlayer2SmPtr()->getPlayerUnits()[Q]->setUnitsField(boardSmPtr->getFieldsTable()[a]);
            }
            Q++;
            break;
        }
    }
    for(int a=0;a<64;a++)
    {
        if((boardSmPtr->getFieldsTable()[a]->getCoordinateX()==s2x)&&boardSmPtr->getFieldsTable()[a]->getCoordinateY()==s2y)
        {
            boardSmPtr->getFieldsTable()[a]->setUnitSmPtr(newSheeps[Q]);
            newSheeps[Q]->setUnitsField(boardSmPtr->getFieldsTable()[a]);
            if(!getPlayer1SmPtr()->isWolf1())
            {
                boardSmPtr->getFieldsTable()[a]->setUnitSmPtr(getPlayer1SmPtr()->getPlayerUnits()[Q]);
                getPlayer1SmPtr()->getPlayerUnits()[Q]->setUnitsField(boardSmPtr->getFieldsTable()[a]);
            }
            else
            {
                boardSmPtr->getFieldsTable()[a]->setUnitSmPtr(getPlayer2SmPtr()->getPlayerUnits()[Q]);
                getPlayer2SmPtr()->getPlayerUnits()[Q]->setUnitsField(boardSmPtr->getFieldsTable()[a]);
            }
            Q++;
            break;
        }
    }
    for(int a=0;a<64;a++)
    {
        if((boardSmPtr->getFieldsTable()[a]->getCoordinateX()==s3x)&&boardSmPtr->getFieldsTable()[a]->getCoordinateY()==s3y)
        {
            boardSmPtr->getFieldsTable()[a]->setUnitSmPtr(newSheeps[Q]);
            newSheeps[Q]->setUnitsField(boardSmPtr->getFieldsTable()[a]);
            if(!getPlayer1SmPtr()->isWolf1())
            {
                boardSmPtr->getFieldsTable()[a]->setUnitSmPtr(getPlayer1SmPtr()->getPlayerUnits()[Q]);
                getPlayer1SmPtr()->getPlayerUnits()[Q]->setUnitsField(boardSmPtr->getFieldsTable()[a]);
            }
            else
            {
                boardSmPtr->getFieldsTable()[a]->setUnitSmPtr(getPlayer2SmPtr()->getPlayerUnits()[Q]);
                getPlayer2SmPtr()->getPlayerUnits()[Q]->setUnitsField(boardSmPtr->getFieldsTable()[a]);
            }
            Q++;
            break;
        }
    }
    for(int a=0;a<64;a++)
    {
        if((boardSmPtr->getFieldsTable()[a]->getCoordinateX()==s4x)&&boardSmPtr->getFieldsTable()[a]->getCoordinateY()==s4y)
        {
            boardSmPtr->getFieldsTable()[a]->setUnitSmPtr(newSheeps[Q]);
            newSheeps[Q]->setUnitsField(boardSmPtr->getFieldsTable()[a]);
            if(!getPlayer1SmPtr()->isWolf1())
            {
                boardSmPtr->getFieldsTable()[a]->setUnitSmPtr(getPlayer1SmPtr()->getPlayerUnits()[Q]);
                getPlayer1SmPtr()->getPlayerUnits()[Q]->setUnitsField(boardSmPtr->getFieldsTable()[a]);
            }
            else
            {
                boardSmPtr->getFieldsTable()[a]->setUnitSmPtr(getPlayer2SmPtr()->getPlayerUnits()[Q]);
                getPlayer2SmPtr()->getPlayerUnits()[Q]->setUnitsField(boardSmPtr->getFieldsTable()[a]);
            }
            Q++;
            break;
        }
    }

    for(int a=0;a<64;a++)
    {
        if((boardSmPtr->getFieldsTable()[a]->getCoordinateX()==wx)&&boardSmPtr->getFieldsTable()[a]->getCoordinateY()==wy)
        {
            boardSmPtr->getFieldsTable()[a]->setUnitSmPtr(newWolf);
            newWolf->setUnitsField(boardSmPtr->getFieldsTable()[a]);
            if(getPlayer1SmPtr()->isWolf1())
            {
                boardSmPtr->getFieldsTable()[a]->setUnitSmPtr(getPlayer1SmPtr()->getPlayerUnits()[0]);
                getPlayer1SmPtr()->getPlayerUnits()[0]->setUnitsField(boardSmPtr->getFieldsTable()[a]);
            }
            else
            {
                boardSmPtr->getFieldsTable()[a]->setUnitSmPtr(getPlayer2SmPtr()->getPlayerUnits()[0]);
                getPlayer2SmPtr()->getPlayerUnits()[0]->setUnitsField(boardSmPtr->getFieldsTable()[a]);
            }
            break;
        }
    }
    setWhoseTurn(wt);
}

Game::Game() {}

const playerPtr &Game::getPlayer1SmPtr() const {
    return player1SmPtr;
}

const playerPtr &Game::getPlayer2SmPtr() const {
    return player2SmPtr;
}

const boardPtr &Game::getBoardSmPtr() const {
    return boardSmPtr;
}

const dataContainerPtr &Game::getDataContainerSmPtr() const {
    return dataContainerSmPtr;
}

bool Game::isWhoseTurn() const {
    return whoseTurn;
}

void Game::setWhoseTurn(bool whoseTurn) {
    Game::whoseTurn = whoseTurn;
}
