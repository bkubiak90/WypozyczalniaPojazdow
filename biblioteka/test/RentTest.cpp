//  Created by students on 12.04.2020.
//  Bartłomiej Kubiak & Jan Wądołowski
//

#include <boost/test/unit_test.hpp>
#include <boost/uuid/uuid_io.hpp>         // streaming operators etc.
#include "ClientTypeVip.h"
#include "Client.h"
#include "Vehicle.h"
#include "Rent.h"
#include "Address.h"
#include "Car.h"
#include "Bicycle.h"
#include "RentsManager.h"

using namespace std;
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

BOOST_AUTO_TEST_SUITE(RentSuiteCorrect)
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    const boost::local_time::time_zone_ptr timeZone;
    const bTime aktualnyCzas = bTime(boost::posix_time::second_clock::local_time(), timeZone);

    BoostTimePtr czas1 = make_shared<bTime>(aktualnyCzas-daysNum(2));
    BoostTimePtr czas2 = make_shared<bTime>(aktualnyCzas-daysNum(10));

    AddressPtr address1 = make_shared<Address>("Pabianicka", "120a");

    ClientPtr klient1 = make_shared<Client>("Jan", "Bezdomny", "123123123");
    ClientPtr klient2 = make_shared<Client>("Marek", "Nowak", "2211221122", address1, address1);

    VehiclePtr rower1 = make_shared<Bicycle>("bic-001", 10);
    VehiclePtr samochod3 = make_shared<Car>("EL1337Y", 120, 1700, Car::Segment::E);



    BOOST_AUTO_TEST_CASE(RentDurationCase) {

        RentPtr rent1 = make_shared<Rent>(klient1, rower1, czas1);
        rent1->returnVehicle();
        BOOST_REQUIRE_EQUAL(rent1->rentDuration(), 3);
        RentPtr rent2 = make_shared<Rent>(klient2, samochod3, czas2);
        rent2->returnVehicle();
        BOOST_REQUIRE_EQUAL(rent2->rentDuration(), 11);

    }

    BOOST_AUTO_TEST_CASE(RentCostCase) {

        RentPtr rent1 = make_shared<Rent>(klient1, rower1, czas1);
        double rentCostCalc = 3 * rent1->getVehicle()->getActualRentalPrice() - (3 * rent1->getVehicle()->getActualRentalPrice() * rent1->getClient()->getClientDiscount());
        rent1->returnVehicle();
        BOOST_REQUIRE_EQUAL(rent1->getRentCost(), rentCostCalc);

        RentPtr rent2 = make_shared<Rent>(klient2, samochod3, czas2);
        ClientTypePtr vip = make_shared<ClientTypeVip>();
        rent2->getClient()->changeClientType(vip);
        double rentCostCalc2 = 11 * rent2->getVehicle()->getActualRentalPrice() - (11 * rent2->getVehicle()->getActualRentalPrice() * rent2->getClient()->getClientDiscount());
        rent2->returnVehicle();
        BOOST_REQUIRE_EQUAL(rent2->getRentCost(), rentCostCalc2);

    }

    BOOST_AUTO_TEST_CASE(ClientInfoCase) {

        RentPtr rent1 = make_shared<Rent>(klient1, rower1, czas1);
        BOOST_REQUIRE_EQUAL(rent1->getClientInfo(), klient1->clientInfo());

    }
    
    BOOST_AUTO_TEST_CASE(VehicleIdCase) {

        RentPtr rent1 = make_shared<Rent>(klient1, rower1, czas1);
        BOOST_REQUIRE_EQUAL(rent1->getVehicleId(), rower1->getId());

    }

    BOOST_AUTO_TEST_CASE(EndRentClientCase) {

        RentPtr rent1 = make_shared<Rent>(klient1, rower1, czas1);
        BOOST_REQUIRE_EQUAL(rent1->getClient(), klient1);
        rent1->returnVehicle();
        BOOST_REQUIRE_EQUAL(rent1->getClient(), klient1);

    }

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
BOOST_AUTO_TEST_SUITE_END()
