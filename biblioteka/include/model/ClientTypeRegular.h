//  Created by students on 22.04.2020.
//  Bartłomiej Kubiak & Jan Wądołowski
//

#ifndef CLIENTTYPEREGULAR_H
#define CLIENTTYPEREGULAR_H

#include "ClientType.h"
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

class ClientTypeRegular : public ClientType {

    public:
        //constructors/destructors
        ClientTypeRegular();
        ~ClientTypeRegular() override;
    
        //setters
        int vehicleLimit() override;
        double rentDiscount(double balance) override;
        
        //getters
        std::string getClientType() override;
};
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

#endif //CLIENTTYPEREGULAR_H