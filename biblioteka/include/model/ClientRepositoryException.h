//  Created by students on 29.05.2020.
//  Bartłomiej Kubiak & Jan Wądołowski
//

#ifndef CLIENTREPOSITORYEXCEPTION_H
#define CLIENTREPOSITORYEXCEPTION_H

#include <string>
#include <stdexcept>
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

class ClientRepositoryException : public std::logic_error {

    public:
        explicit ClientRepositoryException(const std::string &arg);
        virtual ~ClientRepositoryException();
    
        static const std::string clientAlreadyExist;
        static const std::string clientNotFound;
        static const std::string repoIsEmpty;
        static const std::string clientHasRents;
};

#endif //CLIENTREPOSITORYEXCEPTION_H
