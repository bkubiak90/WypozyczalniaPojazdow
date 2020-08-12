//  Created by students on 27.05.2020.
//  Bartłomiej Kubiak & Jan Wądołowski
//

#ifndef VEHICLEEXCEPTION_H
#define VEHICLEEXCEPTION_H

#include <string>
#include <stdexcept>
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

class VehicleException : public std::logic_error {

    public:
        //constructors/destructors
        explicit VehicleException(const std::string &arg);
        virtual ~VehicleException();
    
        //exceptions declarations
        static const std::string negativePrice;
        static const std::string emptyRegistration;
        static const std::string wrongEngineDisplacement;
};
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

#endif //VEHICLEEXCEPTION_H
