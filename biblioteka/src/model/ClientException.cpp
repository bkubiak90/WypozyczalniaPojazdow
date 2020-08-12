//  Created by students on 24.04.2020.
//  Bartłomiej Kubiak & Jan Wądołowski
//

#include "ClientException.h"
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//constructors/destructors
ClientException::ClientException(const std::string &arg) : logic_error(arg) {}
ClientException::~ClientException() = default;
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//exceptions definitions
const std::string ClientException::emptyPersonalID = "ERROR: empty personalID!";
const std::string ClientException::emptyFirstName = "ERROR: empty firstName!";
const std::string ClientException::emptyLastName = "ERROR: empty lastName!";
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------