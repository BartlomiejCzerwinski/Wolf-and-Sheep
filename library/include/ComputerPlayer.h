#ifndef GRA_NA_PROJEKT_COMPUTERPLAYER_H
#define GRA_NA_PROJEKT_COMPUTERPLAYER_H
#include "Player.h"
#include <string>

using namespace std;

class ComputerPlayer : public Player {
private:
    const std::string playerName = "Computer";
public:
    void move();

    ComputerPlayer(bool isHuman, bool isWolf, const boardPtr &boardSmPtr);

    ~ComputerPlayer();

    const std::string &getPlayerName() const;

    void setPlayerName(const std::string &playerName);

};


#endif //GRA_NA_PROJEKT_COMPUTERPLAYER_H
