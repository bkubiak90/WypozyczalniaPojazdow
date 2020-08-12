//  Created by students on 07.05.2020.
//  Bartłomiej Kubiak & Jan Wądołowski
//

#include <boost/test/unit_test.hpp>
#include "ClientRepository.h"
#include "Client.h"
#include "ClientManager.h"
#include "Address.h"
#include "ClientType.h"
#include "ClientTypePremium.h"
#include "ClientTypeVip.h"

using namespace std;
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

BOOST_AUTO_TEST_SUITE(ClientRepositorySuiteCorrect)

    shared_ptr<Address> domKlienta2 = make_shared<Address>("Aleksandrowska", "88");

    shared_ptr<Client> klient1 = make_shared<Client>("Jan", "Bezdomny", "123123123");
    shared_ptr<Client> klient2 = make_shared<Client>("Marek", "Nowak", "2211221122", domKlienta2, domKlienta2);

    Repository<Client> *clientRepo = new ClientRepository();

    shared_ptr<ClientType> premium = make_shared<ClientTypePremium>();
    shared_ptr<ClientType> vip = make_shared<ClientTypeVip>();


    BOOST_AUTO_TEST_CASE(ClientAddAndRemoveCase) {
        clientRepo->create(klient1);
        clientRepo->create(klient2);
        BOOST_REQUIRE_EQUAL(clientRepo->find(klient2), true);
        BOOST_REQUIRE_EQUAL(clientRepo->find(klient1), true);
        clientRepo->remove(klient2);
        clientRepo->remove(1);
        BOOST_REQUIRE_EQUAL(clientRepo->find(klient2), false);
        BOOST_REQUIRE_EQUAL(clientRepo->find(klient1), false);

    }

   BOOST_AUTO_TEST_CASE(ClientTypeChangeCase) {
        shared_ptr<ClientManager> manager = make_shared<ClientManager>();
        manager->addClient(klient1);
        manager->addClient(klient2);

        BOOST_REQUIRE_EQUAL(klient1->printClientType(), "Regular");
        manager->changeClientType(klient1, premium);
        BOOST_REQUIRE_EQUAL(klient1->printClientType(), "Premium");

        BOOST_REQUIRE_EQUAL(klient2->printClientType(), "Regular");
        manager->changeClientType(klient2, vip);
        BOOST_REQUIRE_EQUAL(klient2->printClientType(), "Vip");
    }

    BOOST_AUTO_TEST_CASE(FindClientByObject) {
        clientRepo->create(klient2);

        BOOST_REQUIRE_EQUAL(clientRepo->find(klient2), true);
        BOOST_REQUIRE_EQUAL(clientRepo->find(klient1), false);
        clientRepo->remove(klient2);
        clientRepo->create(klient1);
        BOOST_REQUIRE_EQUAL(clientRepo->find(klient1), true);
        BOOST_REQUIRE_EQUAL(clientRepo->find(klient2), false);

    }

    BOOST_AUTO_TEST_CASE(FindClientByIndex) {

        BOOST_REQUIRE_EQUAL(clientRepo->find(1), klient1);

    }

    BOOST_AUTO_TEST_CASE(RepositoryReport) {

        BOOST_TEST_MESSAGE(clientRepo->report());
        clientRepo->remove(1);
        BOOST_REQUIRE_THROW(clientRepo->report(), logic_error);

    }





//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

BOOST_AUTO_TEST_SUITE_END()
