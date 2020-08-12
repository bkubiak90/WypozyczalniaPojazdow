//  Created by students on 1.04.2020.
//  Bartłomiej Kubiak & Jan Wądołowski
//

#include <boost/uuid/uuid.hpp>            // uuid class
#include <boost/uuid/uuid_generators.hpp> // generators
#include <boost/uuid/uuid_io.hpp>         // streaming operators etc.
#include <boost/date_time/local_time/local_time.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include "Rent.h"
#include "Client.h"
#include "Vehicle.h"
#include "RentException.h"

using namespace std;
namespace blt = boost::local_time;
namespace bpt = boost::posix_time;
namespace bu = boost::uuids;

const blt::time_zone_ptr timeZone;
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//constructors/destructors
Rent::Rent(ClientPtr &client, VehiclePtr &vehicle, BoostTimePtr &date_time) : client(client), vehicle(vehicle), rentUUID(bu::random_generator()()),
                                               rentStartDate(date_time),
                                               rentEndDate(nullptr){
    if (client == nullptr) throw RentException(RentException::nullptrClient);
    if (vehicle == nullptr) throw RentException(RentException::nullptrVehicle);
    if (date_time->date() > blt::local_date_time(boost::posix_time::second_clock::local_time(), timeZone).date())
        throw RentException(RentException::wrongStartDate);
}

Rent::~Rent() = default;
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//metody wyświetlające info
string Rent::rentInfo() const{
    string output = shortRentInfo() + client->clientInfo() +
            "\n--------------------------------------";
    return output;
}

string Rent::shortRentInfo() const{
    string output = "\n---------------Rent Info----------------\nuuID: " +
                    to_string(rentUUID) + "\nstart: " +
                    (*rentStartDate).to_string();
    if (rentEndDate != nullptr) {
        output += "\nend: " + (*rentEndDate).to_string();
    }
    output = output + "\ndays: " + to_string(rentDuration()) + "\nrent price: " + to_string(totalRentPrice) +
             "\n" + vehicle->vehicleInfo() + "\n";
    return output;
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//methods modifying rents
int Rent::rentDuration() const {
    if (rentEndDate != nullptr) {
        boost::gregorian::date_period rentPeriod(rentStartDate->date(), rentEndDate->date());
        int daysNumber = rentPeriod.length().days();
        return daysNumber + 1;
    } else
        return 0;
}

void Rent::returnVehicle() {
    bpt::ptime endrent(bpt::second_clock::local_time());
    rentEndDate = make_shared<boost::local_time::local_date_time>(blt::local_date_time(endrent, timeZone));
    double priceWithoutDiscount = rentDuration() * (vehicle->getActualRentalPrice());
    totalRentPrice = priceWithoutDiscount - (priceWithoutDiscount * (client->getClientDiscount()));
    client->increaseBalance(totalRentPrice);
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//getters
const bu::uuid &Rent::getRentUuid() const {
    return rentUUID;
}

const ClientPtr &Rent::getClient() const {
    return client;
}

VehiclePtr Rent::getVehicle() const {
    return vehicle;
}

double Rent::getRentCost() const {
    if (rentEndDate == nullptr)
        return 0;
    else
        return totalRentPrice;
}

string Rent::getClientInfo() const {
    return this->client->clientInfo();
}

string Rent::getVehicleId() const {
    return this->vehicle->getId();
}

//overloaded comparison operators
bool operator== (const RentPtr &rent1, const RentPtr &rent2) {
    return (rent1->rentUUID == rent2->rentUUID);
}

bool operator!= (const RentPtr &rent1, const RentPtr &rent2) {
    return (rent1->rentUUID != rent2->rentUUID);
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------