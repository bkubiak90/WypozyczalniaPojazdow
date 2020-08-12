//  Created by students on 27.05.2020.
//  Bartłomiej Kubiak & Jan Wądołowski
//

#include "AddressException.h"
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//constructors/destructors
AddressException::AddressException(const std::string &arg) : logic_error(arg) {}
AddressException::~AddressException() = default;
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//definicje wyjątków
const std::string AddressException::emptyStreetName = "ERROR: emptyStreetName!";
const std::string AddressException::wrongStreetNumber = "ERROR: wrongStreetNumber!";
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------