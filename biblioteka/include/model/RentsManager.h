//  Created by students on 20.04.2020.
//  Bartłomiej Kubiak & Jan Wądołowski
//

#ifndef RENTSMENAGER_H
#define RENTSMENAGER_H

#include <memory>

class Client;
class ClientRepository;
class RentsRepository;
class Rent;
class Vehicle;

typedef std::shared_ptr<Rent> RentPtr;
typedef std::shared_ptr<Vehicle> VehiclePtr;
typedef std::shared_ptr<Client> ClientPtr;
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

class RentsManager {

    public:
        //constructors/destructors
        RentsManager();
        ~RentsManager();
        
        //methods modifying rents and clients in RentRepository
        void rentVehicle(const RentPtr &rent);
        void returnVehicle(const RentPtr &rent);
        void changeClientType(const ClientPtr &client);
        
        //getters
        double checkClientRentBalance(const ClientPtr &client) const;
        std::string getAllClientRents(const ClientPtr &client) const;
        int getNumberOfClientRents(const ClientPtr &client) const;
        const ClientPtr &getClientForRentedVehicle(const VehiclePtr &findByVehicle) const;
        const std::string currentRentsReport();
        const std::string archiveRentsReport();
    

    private:
        std::shared_ptr<RentsRepository> currentRentRepository;
        std::shared_ptr<RentsRepository> archiveRentRepository;

};
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

#endif //RENTSMENAGER_H
