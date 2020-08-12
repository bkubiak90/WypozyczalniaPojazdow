//  Created by students on 11.06.2020.
//  Bartłomiej Kubiak & Jan Wądołowski
//



#include <boost/test/unit_test.hpp>
#include "Vehicle.h"
#include "Bicycle.h"
#include "Moped.h"
#include "Car.h"
#include "VehicleManager.h"

using namespace std;
typedef shared_ptr<Vehicle> VehiclePtr;

BOOST_AUTO_TEST_SUITE(VehicleManagerSuiteCorrect)

    VehiclePtr veh1 = make_shared<Bicycle> ("bic-001", 10);
    VehiclePtr veh2 = make_shared<Bicycle> ("bic-002", 10);
    VehiclePtr veh3 = make_shared<Moped> ("El123BG", 25, 100);
    VehiclePtr veh4 = make_shared<Moped> ("El169JW", 20, 55);
    VehiclePtr veh5 = make_shared<Car> ("EL323RD", 80, 1700, Car::Segment::A);
    VehiclePtr veh6 = make_shared<Car> ("EL26R6G", 120, 2000, Car::Segment::B);

    shared_ptr<VehicleManager> manager = make_shared<VehicleManager>();



    BOOST_AUTO_TEST_CASE(AddAndGetVehicleCase) {

        manager->addVehicle(veh1);
        manager->addVehicle(veh2);
        manager->addVehicle(veh3);
        manager->addVehicle(veh4);
        BOOST_REQUIRE_EQUAL(manager->getVehicle(veh1), veh1);
        BOOST_REQUIRE_EQUAL(manager->getVehicle(veh2), veh2);
        BOOST_REQUIRE_EQUAL(manager->getVehicle(veh3), veh3);
        BOOST_REQUIRE_EQUAL(manager->getVehicle(veh4), veh4);
        BOOST_REQUIRE_EQUAL(manager->getVehicle(1), veh1);
        BOOST_REQUIRE_EQUAL(manager->getVehicle(2), veh2);
        BOOST_REQUIRE_EQUAL(manager->getVehicle(3), veh3);
        BOOST_REQUIRE_EQUAL(manager->getVehicle(4), veh4);

    }

    BOOST_AUTO_TEST_CASE(RemoveVehicleCase) {

        manager->removeVehicle(veh1);
        BOOST_REQUIRE_THROW(manager->getVehicle(veh1), logic_error);
        BOOST_REQUIRE_THROW(manager->removeVehicle(veh1), logic_error);

        BOOST_REQUIRE_EQUAL(manager->getVehicle(1), veh2);

        BOOST_REQUIRE_THROW(manager->getVehicle(5), logic_error);

    }

    BOOST_AUTO_TEST_CASE(AddAlreadyExistingVehicleCase) {

        BOOST_REQUIRE_THROW(manager->addVehicle(veh2), logic_error);
        manager->removeVehicle(veh2);
        BOOST_REQUIRE_THROW(manager->getVehicle(veh2), logic_error);
        manager->addVehicle(veh2);
        BOOST_REQUIRE_EQUAL(manager->getVehicle(veh2), veh2);

    }


BOOST_AUTO_TEST_SUITE_END()