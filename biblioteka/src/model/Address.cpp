//  Created by students on 19.03.2020.
//  Bartłomiej Kubiak & Jan Wądołowski
//

#include <iostream>
#include <stdlib.h>
#include "AddressException.h"
#include "Address.h"

using namespace std;
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//konstruktor parametrowy
Address::Address(const string& street, const string& number) : street(street), number(number) {

    if (street.empty()) throw AddressException(AddressException::emptyStreetName);
    if (int num = stoi(number) <= 0) throw AddressException(AddressException::wrongStreetNumber);
}

//destruktor
Address::~Address() = default;
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//getters
const string &Address::getStreetName() const {
    return street;
}

const string &Address::getStreetNum() const {
    return number;
}

//setters
void Address::setStreetName(const string &pstreet) {
    Address::street = pstreet;
}

void Address::setStreetNum(const string &pnumber) {
    Address::number = pnumber;
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//toString method
string Address::addressInfo() const {
    return street + " " + number;
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------