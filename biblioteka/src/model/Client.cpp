//  Created by students on 16.03.2020.
//  Bartłomiej Kubiak & Jan Wądołowski
//

#include <iostream>
#include <utility>
#include "Address.h"
#include "Client.h"
#include "ClientException.h"
#include "ClientTypeRegular.h"
#include "Rent.h"

using namespace std;
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//Konstruktor parametrowy z adresem zamieszkania i adresem zameldowania
Client::Client(const string& firstName, const string& lastName, const string& personalID, AddressPtr address, AddressPtr regAddress)
        : firstName(firstName), lastName(lastName), personalID(personalID), address(std::move(address)), registeredAddress(std::move(regAddress)), clientType(make_shared<ClientTypeRegular>()) {

    if (personalID.empty()) throw ClientException(ClientException::emptyPersonalID);
    if (firstName.empty()) throw ClientException(ClientException::emptyFirstName);
    if (lastName.empty()) throw ClientException(ClientException::emptyLastName);
}

//Destruktor
Client::~Client() = default;
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//metoda wyświetla dane klienta w formacie imię:nazwisko:pesel:adres:adres zamieszkania
string Client::clientInfo() const {
    string output = "name: " + firstName + " " + lastName + " personalID: " + personalID;
    if (address  != nullptr) {
        output += " adr: " + address->addressInfo();
    }
    if (registeredAddress != nullptr) {
        output += " rAdr: " + registeredAddress->addressInfo();
    }
    for (auto const &i : this->getRents()) {
        output += i->shortRentInfo();
        }
        return output;
    }
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//getters
    const string &Client::getFirstName() const {
        return firstName;
    }
    
    const string &Client::getLastName() const {
        return lastName;
    }
    
    const string &Client::getPersonalID() const {
        return personalID;
    }

    const AddressPtr &Client::getAddress() const {
        return address;
    }
    
    const AddressPtr &Client::getRegisteredAddress() const {
        return registeredAddress;
    }
    
    const list <RentPtr> &Client::getRents() const {
        return rents;
    }

    const string Client::printClientType() const{
        return clientType->getClientType();
    }

    int Client::getClientCarLimit() const{
        return clientType->vehicleLimit();
    }

    double Client::getClientDiscount() const {
        return clientType->rentDiscount(balance);
    }

    const double & Client::getClientBalance() const {
    return balance;
    }
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    //overloaded comparison operators
    bool operator== (const ClientPtr &klient1, const ClientPtr &klient2) {
        return (klient1->getPersonalID() == klient2->getPersonalID());
    }

    bool operator!= (const ClientPtr &klient1, const ClientPtr &klient2) {
        return (klient1->getPersonalID() != klient2->getPersonalID());
    }
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//setters
    void Client::setAddress(AddressPtr &newAddress) {
        this->address = newAddress;
    }
    
    void Client::setRegisteredAddress(AddressPtr &newRegisteredAddress) {
        this->registeredAddress = newRegisteredAddress;
    }
    
    void Client::addRent(const RentPtr& rent) {
        Client::rents.push_back(rent);
    }
    
    void Client::removeRent(const RentPtr& rent) {
        Client::rents.remove(rent);
    }

    void Client::changeClientType(ClientTypePtr &type) {
        clientType = type;
    }

    void Client::increaseBalance(double addToBalance) {
        balance += addToBalance;
    }

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------