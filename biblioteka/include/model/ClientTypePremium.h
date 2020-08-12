//  Created by students on 22.04.2020.
//  Bartłomiej Kubiak & Jan Wądołowski
//

#ifndef CLIENTTYPEBONUS_H
#define CLIENTTYPEBONUS_H

#include "ClientType.h"
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

class ClientTypePremium : public ClientType {

    public:
        //constructors/destructors
        ClientTypePremium();
        ~ClientTypePremium() override;
    
        //setters
        int vehicleLimit() override;
        double rentDiscount(double balance) override;
        
        //getters
        std::string getClientType() override;
};
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

#endif //CLIENTTYPEBONUS_H
