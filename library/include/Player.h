#ifndef GRA_NA_PROJEKT_PLAYER_H
#define GRA_NA_PROJEKT_PLAYER_H

#include <iostream>
#include "typedefs.h"
#include <vector>


class Player {
private:
    bool isHuman;
    bool isWolf;
    std::shared_ptr<Board> boardSmPtr;
    std::vector<unitPtr> playerUnits;
public:
    virtual void move();

    Player(bool isHuman, bool isWolf, const std::shared_ptr<Board> &boardSmPtr);



    virtual ~Player();


  virtual  void setPlayerName(const std::string &playerName);
    bool isHuman1() const;

    bool isWolf1() const;

    void setBoardSmPtr(const std::shared_ptr<Board> &boardSmPtr);


    const std::shared_ptr<Board> &getBoardSmPtr() const;

    void setIsHuman(int isHuman);

    void setIsWolf(bool isWolf);

    virtual const std::string &getPlayerName() const;

    const std::vector<unitPtr> &getPlayerUnits() const;

    void addUnit(unitPtr unit);


};


#endif //GRA_NA_PROJEKT_PLAYER_H
