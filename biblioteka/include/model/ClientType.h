//  Created by students on 20.04.2020.
//  Bartłomiej Kubiak & Jan Wądołowski
//

#ifndef CLIENTTYPE_H
#define CLIENTTYPE_H

#include <string>
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

class ClientType {

    public:
        //constructors/destructors
        virtual ~ClientType();
       
        //getters
        virtual int vehicleLimit();
        virtual double rentDiscount(double balance);
        virtual std::string getClientType();
};
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

#endif //CLIENTTYPE_H
