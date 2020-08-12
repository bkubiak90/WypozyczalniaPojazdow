//  Created by students on 27.05.2020.
//  Bartłomiej Kubiak & Jan Wądołowski
//

#include "RentsRepositoryException.h"
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//constructors/destructors
RentsRepositoryException::RentsRepositoryException(const std::string &arg) : logic_error(arg) {}
RentsRepositoryException::~RentsRepositoryException() = default;
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//exceptions definitions
const std::string RentsRepositoryException::carLimit = "ERROR: carLimitReached!";
const std::string RentsRepositoryException::uuidExists = "ERROR: uuidAlreadyExistsInRepository!";
const std::string RentsRepositoryException::rentNotFound = "ERROR: rentNotFoundInRepository!";
const std::string RentsRepositoryException::vehicleIsRented = "ERROR: vehicleIsAlreadyRented!";
const std::string RentsRepositoryException::vehicleIsNotRented = "ERROR: vehicleIsNotRented!";
const std::string RentsRepositoryException::repoIsEmpty = "ERROR: repositoryIsEmpty!";

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------