//
// Created by student on 03.06.2022.
//

#include "Board.h"




Board::~Board() {

}

Board::Board(int size) : size(size) {
    int tempx=1,tempy=1;
    srand(time(NULL));
    bool whatColor=0;
    for(int i=1;i<=size;i++)
    {
        if(whatColor)
        {
//            fieldPtr bf = make_shared<BlackField>(1,tempx,tempy,nullptr,0);
            fieldsTable.push_back(make_shared<BlackField>(1,tempx,tempy,nullptr,0));
            whatColor=false;
       tempx++;
        }
        else
        {
            fieldsTable.push_back(make_shared<WhiteField>(0, tempx, tempy,nullptr));
            whatColor=true;
            tempx++;
        }
        if(i%8==0)
        {
            tempx=1;
            tempy+=1;
            if(whatColor)
                whatColor=0;
            else
                whatColor=1;
        }
    }

}

int Board::getSize() const {
    return size;
}

const std::vector<fieldPtr> &Board::getFieldsTable() const {
    return fieldsTable;
}
