//  Created by students on 16.03.2020.
//  Bartłomiej Kubiak & Jan Wądołowski
//

#include <iostream>
#include <string>
#include "Address.h"
#include "Bicycle.h"
#include "Car.h"
#include "Client.h"
#include "ClientTypePremium.h"
#include "Moped.h"
#include "Vehicle.h"
#include "Rent.h"
#include "Repository.h"
#include "VehicleManager.h"
#include "ClientManager.h"
#include "RentsManager.h"


using namespace std;

typedef boost::local_time::local_date_time bTime;
typedef boost::gregorian::days daysNum;
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
int main() {
    //Czas: generowanie czasu na kilka dni wstecz
    const boost::local_time::time_zone_ptr timeZone;
    const bTime ttt = bTime(boost::posix_time::second_clock::local_time() ,timeZone);
    shared_ptr<bTime> czas = make_shared<bTime>(ttt-daysNum(0));

    //Managery i repozytoria:
    shared_ptr<VehicleManager> vehicleManager = make_shared<VehicleManager>();
    shared_ptr<ClientManager> clientManager = make_shared<ClientManager>();
    shared_ptr<RentsManager> rentsManager = make_shared<RentsManager>();

    //Lista pojazdów:
    VehiclePtr rower1 = make_shared<Bicycle> ("bic-001", 10);
    VehiclePtr rower2 = make_shared<Bicycle> ("bic-002", 10);
    VehiclePtr skuter1 = make_shared<Moped> ("El123BG", 25, 100);
    VehiclePtr skuter2 = make_shared<Moped> ("El169JW", 20, 55);
    VehiclePtr skuter3 = make_shared<Moped> ("El223BK", 25, 100);
    VehiclePtr skuter4 = make_shared<Moped> ("El996AA", 23, 75);
    VehiclePtr samochod1 = make_shared<Car> ("EL323RD", 80, 1700, Car::Segment::A);
    VehiclePtr samochod2 = make_shared<Car> ("EL26R6G", 120, 2000, Car::Segment::B);
    VehiclePtr samochod3 = make_shared<Car> ("EL1337Y", 80, 2500, Car::Segment::E);
    VehiclePtr samochod4 = make_shared<Car> ("EL666YO", 90, 2500, Car::Segment::C);
    vehicleManager->addVehicle(rower1);
    vehicleManager->addVehicle(rower2);
    vehicleManager->addVehicle(skuter1);
    vehicleManager->addVehicle(skuter2);
    vehicleManager->addVehicle(skuter3);
    vehicleManager->addVehicle(skuter4);
    vehicleManager->addVehicle(samochod1);
    vehicleManager->addVehicle(samochod2);
    vehicleManager->addVehicle(samochod3);
    vehicleManager->addVehicle(samochod4);

    //Adres:
    AddressPtr adres1 = make_shared<Address>("Czikago", "55");
    AddressPtr adres2 = make_shared<Address>("Zgierska", "1");
    //Klienci:
    ClientPtr klient1 = make_shared<Client>("Endrju", "Golota", "68010578901");
    ClientPtr klient2 = make_shared<Client>("Jan", "Kowalski", "09876543219", adres2, adres2);

    //================================
    //=======SCENARIUSZ 1============
    //================================

    shared_ptr<bTime> czasMinus14 = make_shared<bTime>(ttt-daysNum(14));
    clientManager->addClient(klient1);
    clientManager->changeAddress(klient1, adres1);
    clientManager->changeRegisteredAddress(klient1, adres1);
    RentPtr wypozyczenie = make_shared<Rent>(klient1, samochod1, czasMinus14);
    rentsManager->rentVehicle(wypozyczenie);
    cout << "\n===SCENARIUSZ 1===\n1. Informacje o kliencie i jego aktualnych wypożyczeniach: \n" << endl;
    cout << klient1->clientInfo() << endl;
    cout << "2. Oddanie pojazdu i wyświetlenie informacji o zakończonym wypozyczeniu: " << endl;
    rentsManager->returnVehicle(wypozyczenie);
    cout << wypozyczenie->rentInfo();
    cout << "\n3. Ponowne wypożyczenie tego samego pojazdu na ta sama ilosc dni: " << endl;   //zmniejszenie sie ceny końcowej ze względu na zmianeę typu klienta
    RentPtr wypozyczenie2 = make_shared<Rent>(klient1, samochod1, czasMinus14);
    rentsManager->rentVehicle(wypozyczenie2);
    rentsManager->returnVehicle(wypozyczenie2);
    cout << wypozyczenie2->rentInfo() << endl;
    cout << "===SCENARIUSZ 1===" << endl;

    //================================
    //=======SCENARIUSZ 2============
    //================================

    cout << "===SCENARIUSZ 2===" << endl;
    cout << "1. Wypozyczalnia sprawdza archiwalne wypozyczenia: " << endl;
    cout << rentsManager->archiveRentsReport() << endl;
    cout << "2. Wypozyczalnia sprawdza liste pojazdow w repozutorium i usuwa jeden z nich: " << endl;
    cout << vehicleManager->getAllVehicles()->report() << endl;
    vehicleManager->removeVehicle(samochod3);
    cout << vehicleManager->getAllVehicles()->report() << endl;
    clientManager->addClient(klient2);
    cout << "3. Wypozyczalnia sprawdza informacje o klientach znajdujacych sie w repozytorium i usuwa jednego z nich: \n" << endl;
    cout << clientManager->getAllClientsInfo() << endl;
    clientManager->removeClient(klient1);
    cout << clientManager->getAllClientsInfo();
    cout << "===SCENARIUSZ 2===" << endl;


    return 0;
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


/*========================snippet rent time z ćwiczeń=======================
#include<iostream>
 #include <boost/date_time.hpp>
 
 using namespace std;
 namespace pt = boost::posix_time;
 namespace gr = boost::gregorian;
 
 int main() {
 pt::ptime empty = pt::not_a_date_time;
 cout << empty << endl;
 pt::ptime now = pt::second_clock::local_time();
 cout << now << endl;
 pt::ptime then = pt::ptime(gr::date(2015,5,13),pt::hours(9)+pt::minutes(25));
 cout << then << endl;
 pt::time_period period(then, now);
 cout << period << endl;
 cout << period.length() << endl;
 cout << period.length().hours() << endl;
 cout << period.length().minutes() << endl;
 cout << (then>now) << endl;
 cout << (then<=now) << endl;
 return 0; }
 =========================================================================*/