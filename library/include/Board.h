#ifndef GRA_NA_PROJEKT_BOARD_H
#define GRA_NA_PROJEKT_BOARD_H

#include <iostream>
#include <memory>
#include <vector>
#include "typedefs.h"
#include "Field.h"
#include "BlackField.h"
#include "WhiteField.h"

class Board {
private:
    int size;
    std::vector<fieldPtr> fieldsTable;

public:
    Board(int size);

    virtual ~Board();

    const std::vector<fieldPtr> &getFieldsTable() const;

};


#endif //GRA_NA_PROJEKT_BOARD_H
