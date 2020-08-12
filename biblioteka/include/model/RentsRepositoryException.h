//  Created by students on 27.05.2020.
//  Bartłomiej Kubiak & Jan Wądołowski
//

#ifndef RENTSREPOSITORYEXCEPTION_H
#define RENTSREPOSITORYEXCEPTION_H

#include <string>
#include <stdexcept>
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

class RentsRepositoryException : public std::logic_error {

    public:
        //constructors/destructors
        explicit RentsRepositoryException(const std::string &arg);
        virtual ~RentsRepositoryException();
    
        //exceptions declarations
        static const std::string carLimit;
        static const std::string uuidExists;
        static const std::string rentNotFound;
        static const std::string vehicleIsRented;
        static const std::string vehicleIsNotRented;
        static const std::string repoIsEmpty;

};
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

#endif //RENTSREPOSITORYEXCEPTION_H
