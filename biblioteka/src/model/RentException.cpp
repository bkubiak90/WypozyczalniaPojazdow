//  Created by students on 24.04.2020.
//  Bartłomiej Kubiak & Jan Wądołowski
//

#include "RentException.h"
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//constructors/destructors
RentException::RentException(const std::string &arg) : logic_error(arg) {}
RentException::~RentException() = default;
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//exceptions definitions
const std::string RentException::nullptrClient = "ERROR: nullptr Client!";
const std::string RentException::nullptrVehicle = "ERROR: nullptr Vehicle!";
const std::string RentException::wrongStartDate = "ERROR: wrong StartDate!";
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------