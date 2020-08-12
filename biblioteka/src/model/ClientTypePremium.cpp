//  Created by students on 22.04.2020.
//  Bartłomiej Kubiak & Jan Wądołowski
//

#include "ClientTypePremium.h"
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//constructors/destructors
ClientTypePremium::ClientTypePremium() = default;
ClientTypePremium::~ClientTypePremium() = default;
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//setters
int ClientTypePremium::vehicleLimit() {
    return 5;
}

double ClientTypePremium::rentDiscount(double balance) {
    double disc = 0;
    if (balance >= 1500 && balance < 3000) {
        disc = balance / 30000.0;
    };
    return disc;
}

//getters
std::string ClientTypePremium::getClientType() {
    return "Premium";
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------