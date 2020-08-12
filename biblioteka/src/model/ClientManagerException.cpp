//  Created by students on 29.05.2020.
//  Bartłomiej Kubiak & Jan Wądołowski
//

#include "ClientManagerException.h"
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//constructors/destructors
ClientManagerException::ClientManagerException(const std::string &arg) : logic_error(arg) {}
ClientManagerException::~ClientManagerException() = default;

//exceptions definitions
const std::string ClientManagerException::clientAlreadyExist = "ERROR: clientAlreadyExistInRepository!";
const std::string ClientManagerException::clientNotFound = "ERROR: clientNotFoundInRepository!";
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------