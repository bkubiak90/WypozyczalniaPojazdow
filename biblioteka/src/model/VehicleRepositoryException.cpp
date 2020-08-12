//  Created by students on 27.05.2020.
//  Bartłomiej Kubiak & Jan Wądołowski
//

#include "VehicleRepositoryException.h"
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//constructors/destructors
VehicleRepositoryException::VehicleRepositoryException(const std::string &arg) : logic_error(arg) {}
VehicleRepositoryException::~VehicleRepositoryException() = default;
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//exceptions definitions
const std::string VehicleRepositoryException::vehicleInRepo = "ERROR: vehicleAlreadyInRepository!";
const std::string VehicleRepositoryException::emptyRepo = "ERROR: repositoryIsEmpty!";
const std::string VehicleRepositoryException::vehicleNotFound = "ERROR: vehicleNotFoundInRepository!";
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------