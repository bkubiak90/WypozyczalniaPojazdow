//  Created by students on 27.05.2020.
//  Bartłomiej Kubiak & Jan Wądołowski
//

#include <boost/test/unit_test.hpp>
#include "Client.h"
#include "Address.h"
#include "AddressException.h"

using namespace std;
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

BOOST_AUTO_TEST_SUITE(AddressSuiteCorrect)

    AddressPtr adres1 = make_shared<Address>("Piotrkowska", "33");

    BOOST_AUTO_TEST_CASE(AddressInfoCase) {

        BOOST_REQUIRE_EQUAL(adres1->addressInfo(), "Piotrkowska 33");

    }

    BOOST_AUTO_TEST_CASE(SetAddressCase) {

        adres1->setStreetName("Ogrodowa");
        adres1->setStreetNum("13");
        BOOST_REQUIRE_EQUAL(adres1->addressInfo(), "Ogrodowa 13");

    }

    BOOST_AUTO_TEST_CASE(ClientAddressCase) {

        ClientPtr klient1 = make_shared<Client>("Marek", "Nowak", "2211221122", adres1, adres1);
        BOOST_REQUIRE_EQUAL(klient1->getAddress()->addressInfo(), "Ogrodowa 13");
        BOOST_REQUIRE_EQUAL(klient1->getAddress(), adres1);
        BOOST_REQUIRE_EQUAL(klient1->getRegisteredAddress()->addressInfo(), "Ogrodowa 13");
        BOOST_REQUIRE_EQUAL(klient1->getRegisteredAddress(), adres1);


    }

    BOOST_AUTO_TEST_CASE(AddressExceptionCase) {

        BOOST_REQUIRE_THROW(AddressPtr adres2 = make_shared<Address>("", "33"), logic_error);
        BOOST_REQUIRE_THROW(AddressPtr adres2 = make_shared<Address>("Piotrkowska", "0"), logic_error);
        BOOST_REQUIRE_THROW(AddressPtr adres2 = make_shared<Address>("Piotrkowska", "-8"), logic_error);

    }

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
BOOST_AUTO_TEST_SUITE_END()
