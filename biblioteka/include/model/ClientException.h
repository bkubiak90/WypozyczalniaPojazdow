//  Created by students on 24.04.2020.
//  Bartłomiej Kubiak & Jan Wądołowski
//

#ifndef CLIENTEXCEPTION_H
#define CLIENTEXCEPTION_H

#include <string>
#include <stdexcept>
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

class ClientException : public std::logic_error {

public:
    //constructors/destructors
    explicit ClientException(const std::string &arg);
    virtual ~ClientException();

    static const std::string emptyPersonalID;
    static const std::string emptyFirstName;
    static const std::string emptyLastName;
};
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

#endif //CLIENTEXCEPTION_H
