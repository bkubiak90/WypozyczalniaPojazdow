//  Created by students on 29.05.2020.
//  Bartłomiej Kubiak & Jan Wądołowski
//

#ifndef VEHICLEMANAGEREXCEPTION_H
#define VEHICLEMANAGEREXCEPTION_H

#include <string>
#include <stdexcept>
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

class VehicleManagerException : public std::logic_error {

    public:
        VehicleManagerException(const std::string &arg);
        virtual ~VehicleManagerException();
    
        static const std::string vehicleAlreadyExist;
        static const std::string vehicleNotFound;
        static const std::string repoIsEmpty;
        static const std::string indexDontExist;


};
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

#endif //VEHICLEMANAGEREXCEPTION_H