#include <boost/test/unit_test.hpp>


#include "Board.h"
#include "Field.h"
#include "Unit.h"
#include "Wolf.h"

BOOST_AUTO_TEST_SUITE(FieldGettersAndSettersTest)

    BOOST_AUTO_TEST_CASE(FieldGettersTest) {
        fieldPtr f1 = make_shared<BlackField>(1,1,1,nullptr,0);
        BOOST_CHECK_EQUAL(f1->getUnitSmPtr(), nullptr);
        BOOST_CHECK_EQUAL(f1->getCoordinateX(), 1);
        BOOST_CHECK_EQUAL(f1->getCoordinateY(), 1);
        BOOST_CHECK_EQUAL(f1->getCoordinates(), "( 1 , 1 )");
    }

    BOOST_AUTO_TEST_CASE(FieldSettersTest) {
        fieldPtr f1 = make_shared<BlackField>(1,1,1,nullptr,0);
        unitPtr w = make_shared<Wolf>("WOLF",nullptr,nullptr);
        BOOST_CHECK_EQUAL(f1->getUnitSmPtr(), nullptr);
        f1->setUnitSmPtr(w);
        BOOST_CHECK_EQUAL(f1->getUnitSmPtr(), w);
    }

BOOST_AUTO_TEST_SUITE_END()
