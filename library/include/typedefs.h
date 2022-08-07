//
// Created by student on 03.06.2022.
//

#ifndef GRA_NA_PROJEKT_TYPEDEFS_H
#define GRA_NA_PROJEKT_TYPEDEFS_H

#include <iostream>
#include <memory>

class Field;
class Board;
class DataContainer;
class Game;
class Menu;
class Player;
class Unit;
class UserInterface;
class WhiteField;
class BlackField;

typedef std::shared_ptr<Field> fieldPtr;
typedef std::shared_ptr<Board> boardPtr;
typedef std::shared_ptr<DataContainer> dataContainerPtr;
typedef std::shared_ptr<Game> gamePtr;
typedef std::shared_ptr<Menu> menuPtr;
typedef std::shared_ptr<Player> playerPtr;
typedef std::shared_ptr<Unit> unitPtr;
typedef std::shared_ptr<UserInterface> userInterfacePtr;
typedef std::shared_ptr<WhiteField> whiteFieldPtr;
typedef std::shared_ptr<BlackField> blackFieldPtr;

#endif //GRA_NA_PROJEKT_TYPEDEFS_H
