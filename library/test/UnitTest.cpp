#include <boost/test/unit_test.hpp>

#include "ComputerPlayer.h"
#include "HumanPlayer.h"
#include "Board.h"
#include "Unit.h"
#include "Wolf.h"
#include "Sheep.h"

BOOST_AUTO_TEST_SUITE(UnitGettersAndSettersTest)

    BOOST_AUTO_TEST_CASE(UnitGettersTest) {
        playerPtr cp = make_shared<ComputerPlayer>(0,1,nullptr);
        playerPtr hp = make_shared<HumanPlayer>(1,1,nullptr,"Gracz");
        fieldPtr f1 = make_shared<BlackField>(1,2,3,nullptr,0);
        fieldPtr f2 = make_shared<BlackField>(1,3,4,nullptr,0);
        unitPtr w = make_shared<Wolf>("WOLF",f1,cp);
        BOOST_CHECK_EQUAL(w->getUnitType(), "WOLF");
        BOOST_CHECK_EQUAL(w->getUnitsField(), f1);
        BOOST_CHECK_EQUAL(w->getUnitsPlayer(), cp);
    }

    BOOST_AUTO_TEST_CASE(UnitSettersTest) {
        playerPtr cp = make_shared<ComputerPlayer>(0,1,nullptr);
        playerPtr hp = make_shared<HumanPlayer>(1,1,nullptr,"Gracz");
        fieldPtr f1 = make_shared<BlackField>(1,2,3,nullptr,0);
        fieldPtr f2 = make_shared<BlackField>(1,3,4,nullptr,0);
        unitPtr w = make_shared<Wolf>("WOLF",f1,cp);
        w->setUnitsField(f2);
        BOOST_CHECK_EQUAL(w->getUnitsField(), f2);
    }

    BOOST_AUTO_TEST_CASE(SheepAvailableMovesTest){
        boardPtr b = make_shared<Board>(64);
        playerPtr hp = make_shared<HumanPlayer>(1,0,b,"Gracz");
        unitPtr o1 = make_shared<Sheep>("SHEEP",b->getFieldsTable()[1],hp,1);
        unitPtr o2 = make_shared<Sheep>("SHEEP",b->getFieldsTable()[7],hp,2);
        o1->availableMoves();
        o2->availableMoves();
        BOOST_CHECK_EQUAL(o1->getPolaNaKtoreMozeWejscJednostka().size(), 2);
        BOOST_CHECK_EQUAL(o2->getPolaNaKtoreMozeWejscJednostka().size(), 1);
}

    BOOST_AUTO_TEST_CASE(WolfAvailableMovesTest){
        boardPtr b = make_shared<Board>(64);
        playerPtr cp = make_shared<ComputerPlayer>(0,1,b);
        playerPtr hp = make_shared<HumanPlayer>(1,1,b,"Gracz");
        unitPtr w1 = make_shared<Wolf>("WOLF",b->getFieldsTable()[1],cp);
        unitPtr w2 = make_shared<Wolf>("WOLF",b->getFieldsTable()[17],hp);
        w1->availableMoves();
        w2->availableMoves();
        BOOST_CHECK_EQUAL(w1->getPolaNaKtoreMozeWejscJednostka().size(), 2);
        BOOST_CHECK_EQUAL(w2->getPolaNaKtoreMozeWejscJednostka().size(), 4);
    }
BOOST_AUTO_TEST_SUITE_END()
