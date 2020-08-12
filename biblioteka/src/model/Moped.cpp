//  Created by students on 18.04.2020.
//  Bartłomiej Kubiak & Jan Wądołowski
//

#include "Moped.h"

using namespace std;
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//constructors/destructors
Moped::Moped(const string &id, const int baseRentPrice, const int engineDisplacement) :
                MotorVehicle(id, baseRentPrice, engineDisplacement) {}

Moped::~Moped() = default;
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------