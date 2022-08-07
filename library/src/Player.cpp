//
// Created by student on 03.06.2022.
//

#include "Player.h"


Player::~Player() {

}

bool Player::isHuman1() const {
    return isHuman;
}

bool Player::isWolf1() const {
    return isWolf;
}

Player::Player(bool isHuman, bool isWolf, const std::shared_ptr<Board> &boardSmPtr) : isHuman(isHuman), isWolf(isWolf),
                                                                                      boardSmPtr(boardSmPtr) {}

void Player::setBoardSmPtr(const std::shared_ptr<Board> &boardSmPtr) {
    Player::boardSmPtr = boardSmPtr;
}

void Player::move() {

}
const std::string &Player::getPlayerName()const{
    return ".";
}
const std::shared_ptr<Board> &Player::getBoardSmPtr() const {
    return boardSmPtr;
}

void Player::setIsHuman(int isHuman) {
    Player::isHuman = isHuman;
}

void Player::setIsWolf(bool isWolf) {
    Player::isWolf = isWolf;
}

void Player::setPlayerName(const std::string &playerName) {

}

const std::vector<unitPtr> &Player::getPlayerUnits() const {
    return playerUnits;
}

void Player::addUnit(unitPtr unit) {
    playerUnits.push_back(unit);
}
