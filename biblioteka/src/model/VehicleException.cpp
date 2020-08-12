//  Created by students on 27.05.2020.
//  Bartłomiej Kubiak & Jan Wądołowski
//

#include "VehicleException.h"
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//constructors/destructors
VehicleException::VehicleException(const std::string &arg) : logic_error(arg) {}
VehicleException::~VehicleException() = default;
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//exceptions definitions
const std::string VehicleException::negativePrice = "ERROR: negativePrice!";
const std::string VehicleException::emptyRegistration = "ERROR: emptyRegistration!";
const std::string VehicleException::wrongEngineDisplacement = "ERROR: engineDisplacementZeroOrNegative!";
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------