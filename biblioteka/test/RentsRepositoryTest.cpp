//  Created by students on 26.05.2020.
//  Bartłomiej Kubiak & Jan Wądołowski
//


#include <boost/test/unit_test.hpp>
#include "RentsRepository.h"
#include "Client.h"
#include "Rent.h"
#include "Address.h"
#include "Car.h"
#include "Bicycle.h"
#include "ClientTypePremium.h"
#include <string>

using namespace std;

typedef boost::local_time::local_date_time bTime;
typedef boost::gregorian::days daysNum;
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

BOOST_AUTO_TEST_SUITE(RentsRepositorySuiteCorrect)
    const boost::local_time::time_zone_ptr timeZone;
    const bTime aktualnyCzas = bTime(boost::posix_time::second_clock::local_time(), timeZone);

    BoostTimePtr czas1 = make_shared<bTime>(aktualnyCzas-daysNum(2));

    Repository<Rent> *currRepo = new RentsRepository();
    Repository<Rent> *archRepo = new RentsRepository();

    shared_ptr<Client> klient1 = make_shared<Client>("Jan", "Bezdomny", "123123123");
    shared_ptr<Client> klient2 = make_shared<Client>("Marek", "Nowak", "2211221122");

    VehiclePtr rower1 = make_shared<Bicycle>("bic-001", 10);
    VehiclePtr samochod2 = make_shared<Car>("EL26R6G", 120, 2000, Car::Segment::A);

    shared_ptr<Rent> rent1 = make_shared<Rent>(klient1, samochod2, czas1);
    shared_ptr<Rent> rent2 = make_shared<Rent>(klient2, rower1, czas1);

    BOOST_AUTO_TEST_CASE(AddToCurrentRepoCase) {
        currRepo->create(rent1);
        currRepo->create(rent2);
        string output = rent1->rentInfo() + "\n" + rent2->rentInfo() + "\n";
        BOOST_REQUIRE_EQUAL(output, currRepo->report());

    }

    BOOST_AUTO_TEST_CASE(MoveToArchiveCase) {
        currRepo->remove(rent1);
        archRepo->create(rent1);
        currRepo->remove(rent2);
        archRepo->create(rent2);
        string output1 = "";
        BOOST_REQUIRE_EQUAL(output1, currRepo->report());
        string output2 = rent1->rentInfo() + "\n" + rent2->rentInfo() + "\n";
        BOOST_REQUIRE_EQUAL(output2, archRepo->report());
    }

    BOOST_AUTO_TEST_CASE(FindByIndex) {

        BOOST_REQUIRE_EQUAL(archRepo->find(1), rent1);
        BOOST_REQUIRE_EQUAL(archRepo->find(2), rent2);

    }

    BOOST_AUTO_TEST_CASE(FindByObject) {

        BOOST_REQUIRE_EQUAL(archRepo->find(rent1), true);
        BOOST_REQUIRE_EQUAL(archRepo->find(rent2), true);
        archRepo->remove(rent1);                                    //<<<<<JESLI TU PODAMY INTA TO WYWALA ERROR
        BOOST_REQUIRE_EQUAL(archRepo->find(rent1), false);
        BOOST_REQUIRE_EQUAL(archRepo->find(rent2), true);
        archRepo->remove(rent2);
        BOOST_REQUIRE_EQUAL(archRepo->find(rent2), false);


    }


//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

BOOST_AUTO_TEST_SUITE_END();


