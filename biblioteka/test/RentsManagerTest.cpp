//  Created by students on 26.05.2020.
//  Bartłomiej Kubiak & Jan Wądołowski
//

#include <boost/test/unit_test.hpp>
#include "Client.h"
#include "Car.h"
#include "Bicycle.h"
#include "Moped.h"
#include "Rent.h"
#include "RentsManager.h"
#include "RentsRepository.h"

using namespace std;
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

BOOST_AUTO_TEST_SUITE(RentsManagerTestSuiteCorrect)
    const boost::local_time::time_zone_ptr timeZone;
    const bTime aktualnyCzas = bTime(boost::posix_time::second_clock::local_time(), timeZone);

    BoostTimePtr czas1 = make_shared<bTime>(aktualnyCzas-daysNum(2));
    BoostTimePtr czas2 = make_shared<bTime>(aktualnyCzas-daysNum(10));

    ClientPtr klient1 = make_shared<Client>("Jan", "Bezdomny", "123123123");
    ClientPtr klient2 = make_shared<Client>("Marek", "Nowak", "2211221122");

    VehiclePtr rower2 = make_shared<Bicycle>("bic-002", 10);
    VehiclePtr skuter1 = make_shared<Moped>("El123BG", 50, 999);
    VehiclePtr skuter2 = make_shared<Moped>("El169JW", 50, 55);
    VehiclePtr samochod1 = make_shared<Car>("EL323RD", 120, 1700, Car::Segment::A);

    shared_ptr<RentsManager> rentManager = make_shared<RentsManager>();

    RentPtr rent1 = make_shared<Rent>(klient1, samochod1, czas1);
    RentPtr rent2 = make_shared<Rent>(klient1, skuter2, czas1);
    RentPtr rent3 = make_shared<Rent>(klient1, skuter1, czas1);
    RentPtr rent4 = make_shared<Rent>(klient1, rower2, czas1);
    RentPtr rent5 = make_shared<Rent>(klient2, samochod1, czas1);
    RentPtr rent6 = make_shared<Rent>(klient2, samochod1, czas2);

    BOOST_AUTO_TEST_CASE(RentVehicleCase) {

        rentManager->rentVehicle(rent1);
        BOOST_REQUIRE_EQUAL(rentManager->getNumberOfClientRents(klient1), 1);
        rentManager->rentVehicle(rent2);
        BOOST_REQUIRE_EQUAL(rentManager->getNumberOfClientRents(klient1), 2);
    }

    BOOST_AUTO_TEST_CASE(RentLimitCase) {

        rentManager->rentVehicle(rent3);
        BOOST_REQUIRE_EQUAL(klient1->getClientCarLimit(), 3);
        BOOST_REQUIRE_EQUAL(rentManager->getNumberOfClientRents(klient1), 3);
        BOOST_REQUIRE_THROW(rentManager->rentVehicle(rent4), logic_error);
        rentManager->returnVehicle(rent3);
        rentManager->rentVehicle(rent4);
    }

    BOOST_AUTO_TEST_CASE(ReturnVehicleCase) {

        rentManager->returnVehicle(rent1);
        BOOST_REQUIRE_EQUAL(rentManager->getNumberOfClientRents(klient1), 2);
        rentManager->returnVehicle(rent2);
        BOOST_REQUIRE_EQUAL(rentManager->getNumberOfClientRents(klient1), 1);
    }

    BOOST_AUTO_TEST_CASE(VehicleAlreadyRentedCase) {

        rentManager->rentVehicle(rent5);
        BOOST_REQUIRE_THROW(rentManager->rentVehicle(rent6), logic_error);
    }

    BOOST_AUTO_TEST_CASE(UuidAlreadyExistCase) {

        BOOST_REQUIRE_THROW(rentManager->rentVehicle(rent1), logic_error);
        BOOST_REQUIRE_THROW(rentManager->rentVehicle(rent2), logic_error);
        BOOST_REQUIRE_THROW(rentManager->rentVehicle(rent3), logic_error);
    }

    BOOST_AUTO_TEST_CASE(GetAllClientRentsCase) {

        rentManager->returnVehicle(rent5);
        BOOST_REQUIRE_EQUAL(rentManager->getAllClientRents(klient2), rent5->shortRentInfo() + "\n");
    }

    BOOST_AUTO_TEST_CASE(ClientTypeChangeCase) {

        BOOST_REQUIRE_EQUAL(klient2->printClientType(), "Regular");
        rentManager->rentVehicle(rent6);
        rentManager->returnVehicle(rent6);
        BOOST_REQUIRE_EQUAL(klient2->printClientType(), "Premium");
    }

    BOOST_AUTO_TEST_CASE(CheckClientBalanceCase) {

        BOOST_CHECK(rentManager->checkClientRentBalance(klient2) >= 1500);
        BOOST_CHECK(rentManager->checkClientRentBalance(klient2) < 3000);
    }

    BOOST_AUTO_TEST_CASE(FindClientByRentedVevicle) {

        shared_ptr<RentsManager> rentManager2 = make_shared<RentsManager>();
        RentPtr rent = make_shared<Rent>(klient1, samochod1, czas1);
        rentManager2->rentVehicle(rent);
        BOOST_REQUIRE_EQUAL(rentManager2->getClientForRentedVehicle(samochod1), klient1);

    }

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
BOOST_AUTO_TEST_SUITE_END()

