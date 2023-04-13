#include "UserInterface.h"

void::UserInterface::drawBoard(){
    int tempx=0;
    int tempi=1;
    std::cout<<"   1 2 3 4 5 6 7 8"<<std::endl;
    for(int i=0;i<64;i++){
        if(tempx%8==0) {
            std::cout << tempi << "  ";
            tempi++;
        }
            if(boardPtrTable->getFieldsTable()[i]->isBlack1()==1)
        {
           if(boardPtrTable->getFieldsTable()[i]->getUnitSmPtr()!=nullptr)
           {
               if(boardPtrTable->getFieldsTable()[i]->getUnitSmPtr()->getUnitType()=="WOLF")
                   std::cout<<"W"<<" ";
               else
                  std::cout<<"S"<<" ";
           }
           else
               cout<<"-"<<" ";
        }
        else
            std::cout<<" "<<" ";
        tempx++;
        if(tempx%8==0)
            std::cout<<std::endl;
    }

    }


UserInterface::~UserInterface() {

}

UserInterface::UserInterface(boardPtr &boardPtrTable) : boardPtrTable(boardPtrTable) {}
