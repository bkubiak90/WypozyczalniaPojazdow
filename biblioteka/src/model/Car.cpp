//  Created by students on 18.04.2020.
//  Bartłomiej Kubiak & Jan Wądołowski
//

#include "Car.h"

using namespace std;
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//constructors/destructors
Car::Car(const string &id, int baseRentPrice, const int engineDisplacement, const enum Segment segment) :
            MotorVehicle(id, baseRentPrice, engineDisplacement), segment(segment) {}

Car::~Car() = default;
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//getters
double Car::getActualRentalPrice() {
    return MotorVehicle::getActualRentalPrice() * (static_cast<double>(segment) / 10.0);
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

string Car::vehicleInfo() {
    char seg = 'E';
    for (int i{static_cast<int>(segment)}; i < 14; ++i) {
        seg--;
    }
    string output = MotorVehicle::vehicleInfo() + " segm: " + seg;
    return output;
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------