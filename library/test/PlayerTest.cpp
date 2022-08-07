#include <boost/test/unit_test.hpp>

#include "ComputerPlayer.h"
#include "HumanPlayer.h"
#include "Board.h"

BOOST_AUTO_TEST_SUITE(PlayerGettersAndSettersTest)

    BOOST_AUTO_TEST_CASE(PlayerGettersTest) {
        playerPtr cp = make_shared<ComputerPlayer>(0,1,nullptr);
        playerPtr hp = make_shared<HumanPlayer>(0,1,nullptr,"Gracz");
        BOOST_CHECK_EQUAL(cp->isWolf1(), 1);
        BOOST_CHECK_EQUAL(cp->isHuman1(), 0);
        BOOST_CHECK_EQUAL(cp->getBoardSmPtr(), nullptr);
        BOOST_CHECK_EQUAL(cp->getPlayerName(), "Computer");
        BOOST_CHECK_EQUAL(hp->getPlayerName(), "Gracz");
    }

    BOOST_AUTO_TEST_CASE(PlayerSettersTest) {
        playerPtr cp = make_shared<ComputerPlayer>(0,1,nullptr);
        boardPtr b = make_shared<Board>(64);
        cp->setBoardSmPtr(b);
        BOOST_CHECK_EQUAL(cp->getBoardSmPtr(), b);

    }

BOOST_AUTO_TEST_SUITE_END()
