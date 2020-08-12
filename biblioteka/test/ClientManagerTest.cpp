//  Created by students on 10.06.2020.
//  Bartłomiej Kubiak & Jan Wądołowski
//


#include <boost/test/unit_test.hpp>
#include "ClientRepository.h"
#include "Client.h"
#include "ClientManager.h"
#include "Address.h"
#include "ClientTypePremium.h"
#include "ClientTypeVip.h"


using namespace std;
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

BOOST_AUTO_TEST_SUITE(ClientManagerSuiteCorrect)

    AddressPtr adres1 = make_shared<Address>("Aleksandrowska", "88");
    AddressPtr adres2 = make_shared<Address>("Piotrkowska", "111");

    ClientPtr klient1 = make_shared<Client>("Jan", "Bezdomny", "123123123");
    ClientPtr klient2 = make_shared<Client>("Marek", "Nowak", "2211221122", adres1, adres1);

    ClientTypePtr premium = make_shared<ClientTypePremium>();
    ClientTypePtr vip = make_shared<ClientTypeVip>();

    shared_ptr<ClientManager> clientManager = make_shared<ClientManager>();

    BOOST_AUTO_TEST_CASE(ClientAddAndRemoveCase) {

        clientManager->addClient(klient1);
        clientManager->addClient(klient2);
        BOOST_REQUIRE_EQUAL(clientManager->findClient(klient1), true);
        BOOST_REQUIRE_EQUAL(clientManager->findClient(klient2), true);

        clientManager->removeClient(klient1);
        BOOST_REQUIRE_EQUAL(clientManager->findClient(klient1), false);

        BOOST_REQUIRE_THROW(clientManager->removeClient(klient1), logic_error);

        BOOST_REQUIRE_THROW(clientManager->addClient(klient2), logic_error);

        clientManager->addClient(klient1);
        BOOST_REQUIRE_EQUAL(clientManager->findClient(klient1), true);
        BOOST_REQUIRE_EQUAL(clientManager->findClient(klient2), true);

    }

    BOOST_AUTO_TEST_CASE(AddressAndRegisteredChangeCase) {

        BOOST_REQUIRE_EQUAL(klient1->getAddress(), nullptr);
        BOOST_REQUIRE_EQUAL(klient1->getRegisteredAddress(), nullptr);

        clientManager->changeAddress(klient1, adres2);
        clientManager->changeRegisteredAddress(klient1, adres1);

        BOOST_REQUIRE_EQUAL(klient1->getAddress(), adres2);
        BOOST_REQUIRE_EQUAL(klient1->getAddress()->addressInfo(), adres2->addressInfo());

        BOOST_REQUIRE_EQUAL(klient1->getRegisteredAddress(), adres1);
        BOOST_REQUIRE_EQUAL(klient1->getRegisteredAddress()->addressInfo(), adres1->addressInfo());

        clientManager->changeAddress(klient1, adres1);
        BOOST_REQUIRE_EQUAL(klient1->getAddress(), adres1);
        BOOST_REQUIRE_EQUAL(klient1->getAddress()->addressInfo(), adres1->addressInfo());

    }

    BOOST_AUTO_TEST_CASE(ClientTypeChange) {

        BOOST_REQUIRE_EQUAL(klient1->printClientType(), "Regular");
        BOOST_REQUIRE_EQUAL(klient2->printClientType(), "Regular");
        clientManager->changeClientType(klient1, premium);
        clientManager->changeClientType(klient2, vip);
        BOOST_REQUIRE_EQUAL(klient1->printClientType(), "Premium");
        BOOST_REQUIRE_EQUAL(klient2->printClientType(), "Vip");

    }



//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

BOOST_AUTO_TEST_SUITE_END()