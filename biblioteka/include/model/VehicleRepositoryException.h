//  Created by students on 27.05.2020.
//  Bartłomiej Kubiak & Jan Wądołowski
//

#ifndef VEHICLEREPOSITORYEXCEPTION_H
#define VEHICLEREPOSITORYEXCEPTION_H

#include <string>
#include <stdexcept>
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

class VehicleRepositoryException : public std::logic_error {

public:
    //constructors/destructors
    VehicleRepositoryException(const std::string &arg);
    virtual ~VehicleRepositoryException();

    //exceptions declarations
    static const std::string vehicleInRepo;
    static const std::string emptyRepo;
    static const std::string vehicleNotFound;
};
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

#endif //VEHICLEREPOSITORYEXCEPTION_H
