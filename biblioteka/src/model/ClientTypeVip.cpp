//  Created by students on 22.04.2020.
//  Bartłomiej Kubiak & Jan Wądołowski
//

#include "ClientTypeVip.h"
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//constructors/destructors
ClientTypeVip::ClientTypeVip() = default;
ClientTypeVip::~ClientTypeVip() = default;
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//setters
int ClientTypeVip::vehicleLimit() {
    return 8;
}

double ClientTypeVip::rentDiscount(double balance) {
    double disc {0.10};
    for (int i = 3000; balance > i && disc != 0.20; i += 500) {
        disc += 0.01;
    }
    return disc;
}

//getters
std::string ClientTypeVip::getClientType() {
    return "Vip";
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------