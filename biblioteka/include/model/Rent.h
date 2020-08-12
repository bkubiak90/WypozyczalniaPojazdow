//  Created by students on 16.03.2020.
//  Bartłomiej Kubiak & Jan Wądołowski
//

#ifndef RENT_H
#define RENT_H

#include <boost/uuid/uuid.hpp>
#include <boost/date_time/local_time/local_time.hpp>
#include <string>

class Vehicle;
class Client;

typedef std::shared_ptr<Client> ClientPtr;
typedef std::shared_ptr<Vehicle> VehiclePtr;
typedef std::shared_ptr<boost::local_time::local_date_time> BoostTimePtr;
typedef boost::local_time::local_date_time bTime;
typedef boost::gregorian::days daysNum;
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

class Rent {
    
    public:
        //destruktor
        ~Rent();

        //konstruktor -- dodanie klienta i spięcie relacji dwukierunkowej
        Rent(ClientPtr &client, VehiclePtr &vehicle, BoostTimePtr &date_time);

        //metody wyświetlające info
        std::string rentInfo() const;
        std::string shortRentInfo() const;

        //setters
        int rentDuration() const;
        void returnVehicle();

        //getters
        const boost::uuids::uuid &getRentUuid() const;
        const ClientPtr &getClient() const;
        VehiclePtr getVehicle() const;
        double getRentCost() const;
        std::string getClientInfo() const;
        std::string getVehicleId() const;
    
        //overloaded comparison operators
        friend bool operator== (const std::shared_ptr<Rent> &rent1, const std::shared_ptr<Rent> &rent2);
        friend bool operator!= (const std::shared_ptr<Rent> &rent1, const std::shared_ptr<Rent> &rent2);

    private:
        ClientPtr client;
        VehiclePtr vehicle;
        BoostTimePtr rentStartDate;
        BoostTimePtr rentEndDate;
        boost::uuids::uuid rentUUID;
        double totalRentPrice = 0;
};
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

typedef std::shared_ptr<Rent> RentPtr;

#endif //RENT_H