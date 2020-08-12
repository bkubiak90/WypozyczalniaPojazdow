//  Created by students on 18.04.2020.
//  Bartłomiej Kubiak & Jan Wądołowski
//

#include "MotorVehicle.h"
#include "VehicleException.h"

using namespace std;
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//constructors/destructors
MotorVehicle::MotorVehicle(const string &id, int baseRentPrice, const int engineDisplacement) :
                            Vehicle(id, baseRentPrice), engineDisplacement(engineDisplacement) {
    if (engineDisplacement <= 0) throw VehicleException(VehicleException::wrongEngineDisplacement);
}

MotorVehicle::~MotorVehicle() = default;
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//getters
string MotorVehicle::vehicleInfo() {
    string output = Vehicle::vehicleInfo() + " engine: " + to_string(engineDisplacement) + "cm3";
    return output;
}

double MotorVehicle::getActualRentalPrice() {
    if (this->engineDisplacement < 1000) return Vehicle::getActualRentalPrice();
    else if (this->engineDisplacement >= 1000 && this->engineDisplacement <= 2000) return Vehicle::getActualRentalPrice() * (1 + 0.0005 * (this->engineDisplacement - 1000));
    else return Vehicle::getActualRentalPrice() * 1.5;
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


