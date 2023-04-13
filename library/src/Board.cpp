#include "Board.h"

Board::~Board() {

}

Board::Board(int size) : size(size) {
    int tempx=1,tempy=1;
    srand(time(NULL));
    bool fieldColorIsWhite=0;
    for(int i=1;i<=size;i++)
    {
        if(fieldColorIsWhite)
        {
            fieldsTable.push_back(make_shared<BlackField>(1,tempx,tempy,nullptr,0));
            fieldColorIsWhite=false;
       tempx++;
        }
        else
        {
            fieldsTable.push_back(make_shared<WhiteField>(0, tempx, tempy,nullptr));
            fieldColorIsWhite=true;
            tempx++;
        }
        if(i%8==0)
        {
            tempx=1;
            tempy+=1;
            if(fieldColorIsWhite)
                fieldColorIsWhite= false;
            else
                fieldColorIsWhite=true;
        }
    }

}

const std::vector<fieldPtr> &Board::getFieldsTable() const {
    return fieldsTable;
}
