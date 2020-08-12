//  Created by students on 29.05.2020.
//  Bartłomiej Kubiak & Jan Wądołowski
//

#ifndef CLIENTMANAGEREXCEPTION_H
#define CLIENTMANAGEREXCEPTION_H

#include <string>
#include <stdexcept>
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

class ClientManagerException : public std::logic_error {

    public:
        explicit ClientManagerException(const std::string &arg);
        virtual ~ClientManagerException();
    
        static const std::string clientAlreadyExist;
        static const std::string clientNotFound;

};
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

#endif //CLIENTMANAGEREXCEPTION_H
