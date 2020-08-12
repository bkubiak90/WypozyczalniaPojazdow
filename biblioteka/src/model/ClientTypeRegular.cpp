//  Created by students on 22.04.2020.
//  Bartłomiej Kubiak & Jan Wądołowski
//

#include "ClientTypeRegular.h"
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//constructors/destructors
ClientTypeRegular::ClientTypeRegular() = default;
ClientTypeRegular::~ClientTypeRegular() = default;
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

int ClientTypeRegular::vehicleLimit() {
    return 3;
}

double ClientTypeRegular::rentDiscount(double balance) {
    return 0.00;
}

//getters
std::string ClientTypeRegular::getClientType() {
    return "Regular";
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------