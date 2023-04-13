#include <boost/test/unit_test.hpp>
#include "Board.h"
#include "Field.h"
#include "Wolf.h"

BOOST_AUTO_TEST_SUITE(BoardGettersAndSettersTest)

    BOOST_AUTO_TEST_CASE(BoardGettersTest) {
        boardPtr b = make_shared<Board>(64);
        BOOST_CHECK_EQUAL(b->getFieldsTable()[0]->getUnitSmPtr(), nullptr);
        BOOST_CHECK_EQUAL(b->getFieldsTable()[0]->isTaken1(), 0);
        BOOST_CHECK_EQUAL(b->getFieldsTable()[0]->getCoordinateX(), 1);
        BOOST_CHECK_EQUAL(b->getFieldsTable()[0]->getCoordinateY(), 1);
        BOOST_CHECK_EQUAL(b->getFieldsTable()[0]->isBlack1(), 0);
    }

    BOOST_AUTO_TEST_CASE(BoardSettersTest) {
        boardPtr b = make_shared<Board>(64);
        unitPtr w = make_shared<Wolf>("WOLF",nullptr,nullptr);
        BOOST_CHECK_EQUAL(b->getFieldsTable()[0]->getUnitSmPtr(), nullptr);
        b->getFieldsTable()[0]->setUnitSmPtr(w);
        BOOST_CHECK_EQUAL(b->getFieldsTable()[0]->getUnitSmPtr(), w);
    }

BOOST_AUTO_TEST_SUITE_END()
