//  Created by students on 19.03.2020.
//  Bartłomiej Kubiak & Jan Wądołowski
//

#ifndef ADDRESS_H
#define ADDRESS_H

#include <string>
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

class Address {

    public:
        //constructors/destructors
        Address(const std::string& street, const std::string& number);
        ~Address();
        
        //Deklaracje metod dostępowych
        void setStreetName(const std::string &street);
        void setStreetNum(const std::string &number);
        const std::string &getStreetName() const;
        const std::string &getStreetNum() const;
        std::string addressInfo() const;

    private:
        std::string street;
        std::string number;
};
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

#endif //ADDRESS_H

