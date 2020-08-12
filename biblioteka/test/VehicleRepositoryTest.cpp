//  Created by students on 27.05.2020.
//  Bartłomiej Kubiak & Jan Wądołowski
//

#include <boost/test/unit_test.hpp>
#include "VehicleRepository.h"
#include "Vehicle.h"
#include "Bicycle.h"
#include "Moped.h"
#include "Car.h"
#include <string>
#include "Repository.h"

using namespace std;
typedef shared_ptr<Vehicle> VehiclePtr;

BOOST_AUTO_TEST_SUITE(VehicleRepositorySuiteCorrect)

    Repository<Vehicle> *vehicleRepo = new VehicleRepository();

    VehiclePtr veh0 = make_shared<Bicycle> ("bic-001", 10);
    VehiclePtr veh1 = make_shared<Bicycle> ("bic-002", 10);
    VehiclePtr veh2 = make_shared<Moped> ("El123BG", 25, 100);
    VehiclePtr veh3 = make_shared<Moped> ("El169JW", 20, 55);
    VehiclePtr veh4 = make_shared<Car> ("EL323RD", 80, 1700, Car::Segment::A);
    VehiclePtr veh5 = make_shared<Car> ("EL26R6G", 120, 2000, Car::Segment::B);

    BOOST_AUTO_TEST_CASE(VehicleEmptyRepositoryExceptionCase) {

        BOOST_REQUIRE_THROW(vehicleRepo->report(), logic_error);
        BOOST_REQUIRE_THROW(vehicleRepo->find(1), logic_error);

    }

    BOOST_AUTO_TEST_CASE(VehicleAddToRepositoryCase) {

        vehicleRepo->create(veh0);
        vehicleRepo->create(veh1);
        vehicleRepo->create(veh2);
        vehicleRepo->create(veh3);
        vehicleRepo->create(veh4);
        vehicleRepo->create(veh5);

    }

    BOOST_AUTO_TEST_CASE(VehicleGetByIndexCase) {

        BOOST_REQUIRE_EQUAL(vehicleRepo->find(1), veh0);
        BOOST_REQUIRE_EQUAL(vehicleRepo->find(4), veh3);
        BOOST_REQUIRE_EQUAL(vehicleRepo->find(6), veh5);

    }

    BOOST_AUTO_TEST_CASE(VehicleReportCase) {

        string output = "\nVehicles in repository: \n" + veh0->vehicleInfo() + "\n" + veh1->vehicleInfo() + "\n" + veh2->vehicleInfo() + "\n" + veh3->vehicleInfo() + "\n"
                            + veh4->vehicleInfo() + "\n" + veh5->vehicleInfo() + "\n" + "==In total: 6 vehicles in the repository.==\n";
        BOOST_REQUIRE_EQUAL(output, vehicleRepo->report());
        BOOST_TEST_MESSAGE(vehicleRepo->report());

    }

    BOOST_AUTO_TEST_CASE(VehicleAlreadyInRepositoryExceptionCase) {

        VehiclePtr veh3version2 = make_shared<Moped> ("El169JW", 20, 55);
        BOOST_REQUIRE_THROW(vehicleRepo->create(veh3version2), logic_error);
        VehiclePtr veh0version2 = make_shared<Bicycle> ("bic-001", 10);
        BOOST_REQUIRE_THROW(vehicleRepo->create(veh0version2), logic_error);

    }

    BOOST_AUTO_TEST_CASE(VehicleFindByObject) {

        BOOST_REQUIRE_EQUAL(vehicleRepo->find(veh1), true);
        BOOST_REQUIRE_EQUAL(vehicleRepo->find(veh2), true);
        BOOST_REQUIRE_EQUAL(vehicleRepo->find(veh5), true);
        vehicleRepo->remove(2);
        BOOST_REQUIRE_EQUAL(vehicleRepo->find(veh1), false);
        BOOST_REQUIRE_EQUAL(vehicleRepo->find(veh2), true);
        vehicleRepo->remove(veh2);
        vehicleRepo->remove(4);
        BOOST_REQUIRE_EQUAL(vehicleRepo->find(veh2), false);
        BOOST_REQUIRE_EQUAL(vehicleRepo->find(veh5), false);

    }




BOOST_AUTO_TEST_SUITE_END()
