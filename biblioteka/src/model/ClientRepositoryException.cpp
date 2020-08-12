//  Created by students on 29.05.2020.
//  Bartłomiej Kubiak & Jan Wądołowski
//

#include "ClientRepositoryException.h"
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//constructors/destructors
ClientRepositoryException::ClientRepositoryException(const std::string &arg) : logic_error(arg) {}
ClientRepositoryException::~ClientRepositoryException() = default;
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//exceptions definitions
const std::string ClientRepositoryException::clientAlreadyExist = "ERROR: clientAlreadyExistInRepository!";
const std::string ClientRepositoryException::clientNotFound = "ERROR: clientNotFoundInRepository!";
const std::string ClientRepositoryException::repoIsEmpty = "ERROR: repositoryIsEmpty!";
const std::string ClientRepositoryException::clientHasRents = "ERROR: client has open rents!";
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------