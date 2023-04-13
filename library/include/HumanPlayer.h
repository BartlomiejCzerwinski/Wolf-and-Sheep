#ifndef GRA_NA_PROJEKT_HUMANPLAYER_H
#define GRA_NA_PROJEKT_HUMANPLAYER_H

#include "Player.h"
#include <string>

class HumanPlayer : public Player {
private:
    std::string playerName;
public:
    void move();

    HumanPlayer(bool isHuman, bool isWolf, const std::shared_ptr<Board> &boardSmPtr, const std::string &playerName);

    ~HumanPlayer();

    const std::string &getPlayerName() const;

    void setPlayerName(const std::string &playerName);
};

#endif
