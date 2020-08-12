//  Created by students on 24.04.2020.
//  Bartłomiej Kubiak & Jan Wądołowski
//

#ifndef RENTEXCEPTION_H
#define RENTEXCEPTION_H

#include <string>
#include <stdexcept>
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

class RentException : public std::logic_error {

    public:
        //constructors/destructors
        explicit RentException(const std::string &arg);
        virtual ~RentException();
    
        //exceptions definitions
        static const std::string nullptrClient;
        static const std::string nullptrVehicle;
        static const std::string wrongStartDate;
};
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

#endif //RENTEXCEPTION_H
