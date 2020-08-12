//  Created by students on 09.05.2020.
//  Bartłomiej Kubiak & Jan Wądołowski
//

#include <boost/test/unit_test.hpp>
#include "Client.h"
#include "ClientException.h"
#include "Rent.h"
#include "Address.h"
#include "ClientTypePremium.h"
#include "ClientTypeRegular.h"
#include "ClientTypeVip.h"


using namespace std;

BOOST_AUTO_TEST_SUITE(ClientSuiteCorrect)

    shared_ptr<Address> address1 = make_shared<Address>("Pabianicka", "120a");
    shared_ptr<Address> address2 = make_shared<Address>("Traktorowa", "1");

    shared_ptr<Client> klient1 = make_shared<Client>("Jan", "Bezdomny", "123123123");
    shared_ptr<Client> klient2 = make_shared<Client>("Marek", "Nowak", "2211221122", address1, address1);

    shared_ptr<ClientType> regular = make_shared<ClientTypeRegular>();
    shared_ptr<ClientType> premium = make_shared<ClientTypePremium>();
    shared_ptr<ClientType> vip = make_shared<ClientTypeVip>();

    BOOST_AUTO_TEST_CASE(FirstNameCase) {
        BOOST_REQUIRE_EQUAL(klient1->getFirstName(), "Jan");
        BOOST_REQUIRE_EQUAL(klient2->getFirstName(), "Marek");
    }

    BOOST_AUTO_TEST_CASE(LastNameCase) {
        BOOST_REQUIRE_EQUAL(klient1->getLastName(), "Bezdomny");
        BOOST_REQUIRE_EQUAL(klient2->getLastName(), "Nowak");
    }

    BOOST_AUTO_TEST_CASE(PersonalIdCase) {
        BOOST_REQUIRE_EQUAL(klient1->getPersonalID(), "123123123");
        BOOST_REQUIRE_EQUAL(klient2->getPersonalID(), "2211221122");
    }

    BOOST_AUTO_TEST_CASE(ClientAddressCase) {
        BOOST_REQUIRE_EQUAL(klient1->getAddress(), nullptr);
        BOOST_REQUIRE_EQUAL(klient2->getAddress()->addressInfo(), "Pabianicka 120a");
        klient1->setAddress(address1);
        BOOST_REQUIRE_EQUAL(klient1->getAddress()->addressInfo(), "Pabianicka 120a");
        klient1->setAddress(address2);
        BOOST_REQUIRE_EQUAL(klient1->getAddress()->addressInfo(), "Traktorowa 1");
        BOOST_REQUIRE_EQUAL(klient2->getAddress()->addressInfo(), "Pabianicka 120a");
    }

    BOOST_AUTO_TEST_CASE(ClientRegisteredAddressCase) {
        BOOST_REQUIRE_EQUAL(klient1->getRegisteredAddress(), nullptr);
        BOOST_REQUIRE_EQUAL(klient2->getRegisteredAddress()->addressInfo(), "Pabianicka 120a");
        klient1->setRegisteredAddress(address1);
        BOOST_REQUIRE_EQUAL(klient1->getRegisteredAddress()->addressInfo(), "Pabianicka 120a");
        klient1->setRegisteredAddress(address2);
        BOOST_REQUIRE_EQUAL(klient1->getRegisteredAddress()->addressInfo(), "Traktorowa 1");
        BOOST_REQUIRE_EQUAL(klient2->getRegisteredAddress()->addressInfo(), "Pabianicka 120a");
    }

    BOOST_AUTO_TEST_CASE(ClientTypeChange) {
        klient1->changeClientType(regular);
        klient2->changeClientType(regular);
        BOOST_REQUIRE_EQUAL(klient1->printClientType(), "Regular");
        BOOST_REQUIRE_EQUAL(klient2->printClientType(), "Regular");
        klient1->changeClientType(premium);
        klient2->changeClientType(vip);
        BOOST_REQUIRE_EQUAL(klient1->printClientType(), "Premium");
        BOOST_REQUIRE_EQUAL(klient2->printClientType(), "Vip");
    }

    BOOST_AUTO_TEST_CASE(VehicleLimit) {
        BOOST_REQUIRE_EQUAL(klient1->getClientCarLimit(), 5);
        BOOST_REQUIRE_EQUAL(klient2->getClientCarLimit(), 8);
    }


    //WYJATKI DLA KLIENTA
    BOOST_AUTO_TEST_CASE(CatchExceptionCase) {

        BOOST_REQUIRE_THROW(shared_ptr<Client> klient3 = make_shared<Client>("", "Bezdomny", "123123123"), logic_error);
        BOOST_REQUIRE_THROW(shared_ptr<Client> klient3 = make_shared<Client>("Jan", "", "123123123"), logic_error);
        BOOST_REQUIRE_THROW(shared_ptr<Client> klient3 = make_shared<Client>("Jan", "Bezdomny", ""), logic_error);

    }

BOOST_AUTO_TEST_SUITE_END();

/*========================snippet testClient z ćwiczeń=======================
BOOST_AUTO_TEST_SUITE(TestSuiteClient)

struct TestSuiteClientFixture { const std::string testFirstName = "Jon"; const std::string testLastName = "Arbuckle";
                                const std::string testPersonalID = "0123456789"; Address *testaddress1; Address *testaddress2;
TestSuiteClientFixture() { testaddress1 = new Address("Accacia Avenue", "22"); testaddress2 = new Address("Rue Morgue", "13"); }
~TestSuiteClientFixture() { delete testaddress1; delete testaddress2; } };

    BOOST_FIXTURE_TEST_SUITE(TestSuiteClient, TestSuiteClientFixture)
    BOOST_AUTO_TEST_CASE(ParameterConstrutorTest) {
        Client c(testFirstName, testLastName, testPersonalID, testaddress1);
    BOOST_TEST(testFirstName == c.getFirstName());
    BOOST_TEST(testLastName == c.getLastName());
    BOOST_TEST(testPersonalID == c.getPersonalID());
    BOOST_TEST(testaddress1 == c.getAddress()); }

BOOST_AUTO_TEST_SUITE_END() };
 =============================================================================*/