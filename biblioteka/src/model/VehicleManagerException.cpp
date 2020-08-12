//  Created by students on 29.05.2020.
//  Bartłomiej Kubiak & Jan Wądołowski
//

#include "VehicleManagerException.h"
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//constructors/destructors
VehicleManagerException::VehicleManagerException(const std::string &arg) : logic_error(arg) {}
VehicleManagerException::~VehicleManagerException() = default;

//exceptions definitions
const std::string VehicleManagerException::vehicleAlreadyExist = "ERROR: vehicleAlreadyExistInRepository!";
const std::string VehicleManagerException::vehicleNotFound = "ERROR: vehicleNotFoundInRepository!";
const std::string VehicleManagerException::repoIsEmpty = "ERROR: repositoryIsEmpty!";
const std::string VehicleManagerException::indexDontExist = "ERROR: thisIndexDontExistInRepository!";


//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------