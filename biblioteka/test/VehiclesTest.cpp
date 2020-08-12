//  Created by students on 09.05.2020.
//  Bartłomiej Kubiak & Jan Wądołowski
//

#include <boost/test/unit_test.hpp>
#include "Vehicle.h"
#include "Car.h"
#include "Moped.h"
#include "Bicycle.h"

using namespace std;
typedef shared_ptr<Vehicle> VehiclePtr;

BOOST_AUTO_TEST_SUITE(VehiclesSuiteCorrect)

    VehiclePtr rower1 = make_shared<Bicycle>("bic-001", 10);
    VehiclePtr rower2 = make_shared<Bicycle>("bic-002", 10);
    VehiclePtr skuter1 = make_shared<Moped>("El123BG", 50, 999);
    VehiclePtr skuter2 = make_shared<Moped>("El169JW", 50, 55);
    VehiclePtr samochod1 = make_shared<Car>("EL323RD", 120, 1700, Car::Segment::A);
    VehiclePtr samochod2 = make_shared<Car>("EL26R6G", 120, 2000, Car::Segment::A);
    VehiclePtr samochod3 = make_shared<Car>("EL1337Y", 120, 1700, Car::Segment::E);

    BOOST_AUTO_TEST_CASE(VehiclesIdTest) {
        BOOST_REQUIRE_EQUAL(rower1->getId(), "bic-001");
        BOOST_REQUIRE_EQUAL(skuter1->getId(), "El123BG");
        BOOST_REQUIRE_EQUAL(samochod1->getId(), "EL323RD");
    }

    BOOST_AUTO_TEST_CASE(VehiclesRentalPriceTest) {
        BOOST_CHECK(rower2->getActualRentalPrice() == 10);
        BOOST_CHECK(skuter2->getActualRentalPrice() == 50.0);
        BOOST_TEST(samochod2->getActualRentalPrice() == 180.0);
        BOOST_TEST(samochod3->getActualRentalPrice() == 243.0);
        BOOST_CHECK(skuter1->getActualRentalPrice() == skuter2->getActualRentalPrice());
        BOOST_TEST(samochod2->getActualRentalPrice() != samochod1->getActualRentalPrice());
        BOOST_TEST(samochod3->getActualRentalPrice() != samochod1->getActualRentalPrice());
    }

    BOOST_AUTO_TEST_CASE(VehicleExceptionCase) {

        BOOST_REQUIRE_THROW(VehiclePtr rower3 = make_shared<Bicycle>("", 10), logic_error);
        BOOST_REQUIRE_THROW(VehiclePtr samochod4 = make_shared<Car>("EL26R6G", 55, 0, Car::Segment::A),  logic_error);
        BOOST_REQUIRE_THROW(VehiclePtr skuter1 = make_shared<Moped>("El123BG", -77, 999), logic_error);

    }



BOOST_AUTO_TEST_SUITE_END()