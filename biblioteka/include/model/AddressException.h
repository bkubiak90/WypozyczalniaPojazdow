//  Created by students on 27.05.2020.
//  Bartłomiej Kubiak & Jan Wądołowski
//

#ifndef ADDRESSEXCEPTION_H
#define ADDRESSEXCEPTION_H

#include <string>
#include <stdexcept>
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

class AddressException : public std::logic_error {

public:
    AddressException(const std::string &arg);
    virtual ~AddressException();

    static const std::string emptyStreetName;
    static const std::string wrongStreetNumber;
};
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

#endif //ADDRESSEXCEPTION_H
