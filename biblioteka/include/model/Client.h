//  Created by students on 16.03.2020.
//  Bartłomiej Kubiak & Jan Wądołowski
//

#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include <list>
#include <memory>

class ClientType;
class Rent;
class Address;

typedef std::shared_ptr<Address> AddressPtr;
typedef std::shared_ptr<ClientType> ClientTypePtr;
typedef std::shared_ptr<Rent> RentPtr;
//typedef dla klasy Client po definicji klasy.
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

class Client {

    public:
        //constructors/destructors
        Client(const std::string& firstName, const std::string& lastName, const std::string& personalID, AddressPtr address = nullptr, AddressPtr regAddress = nullptr);
        ~Client();
        
        //metoda wyświetla dane klienta w formacie imię:nazwisko:pesel:adres:adres zamieszkania
        std::string clientInfo() const;
        
        //getters
        const std::string &getFirstName() const;
        const std::string &getLastName() const;
        const std::string &getPersonalID() const;
        int getClientCarLimit()const;
        double getClientDiscount() const;
        const AddressPtr &getAddress() const;
        const AddressPtr &getRegisteredAddress() const;
        const std::list<RentPtr> &getRents() const;
        const std::string printClientType() const;
        const double & getClientBalance() const;
        
        //overloaded comparison operators
        friend bool operator== (const std::shared_ptr<Client> &klient1, const std::shared_ptr<Client> &klient2);
        friend bool operator!= (const std::shared_ptr<Client> &klient1, const std::shared_ptr<Client> &klient2);
        
        //setters
        void addRent(const RentPtr &rent);
        void changeClientType(ClientTypePtr &type);
        void removeRent(const RentPtr &rent);
        void setAddress(AddressPtr &newAddress);
        void setRegisteredAddress(AddressPtr &newRegisteredAddress);
        void increaseBalance(double addToBalance);

    private:
        const std::string firstName;
        const std::string lastName;
        const std::string personalID;
        double balance = 0;
        ClientTypePtr clientType;
        AddressPtr address;               //adres zamieszkania
        AddressPtr registeredAddress;     //adres zameldowania

        //lista wszystkich aktualnych wypożyczeń klienta; Porównanie złożoności obliczeniowej O operacji na liście i wektorze: https://users.cs.northwestern.edu/~riesbeck/programming/c++/stl-summary.html
        std::list<RentPtr> rents;
};
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

typedef std::shared_ptr<Client> ClientPtr;  //musi być po definicji klasy Client

#endif //CLIENT_H