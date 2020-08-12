//  Created by students on 22.04.2020.
//  Bartłomiej Kubiak & Jan Wądołowski
//

#ifndef CLIENTTYPEPREMIUM_H
#define CLIENTTYPEPREMIUM_H

#include "ClientType.h"
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

class ClientTypeVip : public ClientType {

    public:
        //constructors/destructors
        ClientTypeVip();
        ~ClientTypeVip() override;
    
        //setters
        int vehicleLimit() override;
        double rentDiscount(double balance) override;
        
        //getters
        std::string getClientType() override;
};
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

#endif //CLIENTTYPEPREMIUM_H