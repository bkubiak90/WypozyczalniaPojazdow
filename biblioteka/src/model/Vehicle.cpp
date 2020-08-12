//  Created by students on 03.04.2020.
//  Bartłomiej Kubiak & Jan Wądołowski
//

#include "Vehicle.h"
#include "VehicleException.h"
#include <utility>

using namespace std;
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//constructors/destructors
Vehicle::Vehicle(const string &id, int baseRentPrice) : id(id), baseRentPrice(baseRentPrice) {
    if (id.empty()) throw VehicleException(VehicleException::emptyRegistration);
    if (baseRentPrice < 0) throw VehicleException(VehicleException::negativePrice);
};

Vehicle::~Vehicle()= default;
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//metoda wyświetla dane o pojeździe w formacie id <id> price <actualRentalPrice>
string Vehicle::vehicleInfo() {
    string output = "id " + id + " price " + to_string(this->getActualRentalPrice());
    return output;
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//getters
const string &Vehicle::getId() const {
    return id;
}

double Vehicle::getActualRentalPrice() {
    return baseRentPrice;
}

//overloaded comparison operators
bool operator== (const VehiclePtr &vehicle1, const VehiclePtr &vehicle2) {
    return (vehicle1->getId() == vehicle2->getId());
}

bool operator!= (const VehiclePtr &vehicle1, const VehiclePtr &vehicle2) {
    return (vehicle1->getId() != vehicle2->getId());
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------