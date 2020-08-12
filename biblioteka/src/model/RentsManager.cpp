//
// Created by student on 23.04.2020.
//

#include <string>
#include "RentsManager.h"
#include "RentsRepository.h"
#include "Rent.h"
#include "Client.h"
#include "ClientTypeRegular.h"
#include "ClientTypePremium.h"
#include "ClientTypeVip.h"
#include "Vehicle.h"
#include "RentsRepositoryException.h"

typedef std::shared_ptr<ClientType> ClientTypePtr;

ClientTypePtr premium = std::make_shared<ClientTypePremium>();
ClientTypePtr vip = std::make_shared<ClientTypeVip>();
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//constructors/destructors
RentsManager::RentsManager() : currentRentRepository(new RentsRepository), archiveRentRepository(new RentsRepository) {}

RentsManager::~RentsManager() {

};
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//methods modifying rents and clients in RentRepository
void RentsManager::returnVehicle(const RentPtr &rent) {
    if (currentRentRepository->getAll().empty()) throw RentsRepositoryException(RentsRepositoryException::repoIsEmpty);
    if (!currentRentRepository->find(rent)) throw RentsRepositoryException(RentsRepositoryException::rentNotFound);
    rent->returnVehicle();
    rent->getClient()->removeRent(rent);
    currentRentRepository->remove(rent);
    archiveRentRepository->create(rent);
    changeClientType(rent->getClient());
}

void RentsManager::changeClientType(const ClientPtr &client) {
    if (client->getClientBalance() >= 1500 && client->getClientBalance() < 3000) {
        client->changeClientType(premium);
    } else if (client->getClientBalance() >= 3000) {
        client->changeClientType(vip);
    }
}

void RentsManager::rentVehicle(const RentPtr &rent) {
    
    for (const RentPtr& rentInRepo : currentRentRepository->getAll()) {
        if (rentInRepo->getVehicle() == rent->getVehicle()) {
            throw RentsRepositoryException(RentsRepositoryException::vehicleIsRented);
        }
        if (rentInRepo == rent) {
            throw RentsRepositoryException(RentsRepositoryException::uuidExists);
        }
    }
    for (const RentPtr& rentInRepo : archiveRentRepository->getAll()) {
        if (rentInRepo == rent) {
            throw RentsRepositoryException(RentsRepositoryException::uuidExists);
        }
    }
    if ((rent->getClient()->getRents()).size() >= rent->getClient()->getClientCarLimit()) {
        throw RentsRepositoryException(RentsRepositoryException::carLimit);
    } else {
        currentRentRepository->create(rent);
        rent->getClient()->addRent(rent);
    }
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//getters
double RentsManager::checkClientRentBalance(const ClientPtr &client) const {
    return client->getClientBalance();
}

std::string RentsManager::getAllClientRents(const ClientPtr &client) const {
    std::string output = "";
    for (const RentPtr& rent : archiveRentRepository->getAll()) {
        if (rent->getClient() == client) {
            output += rent->shortRentInfo() + "\n";
        }
    }
    return output;
}


int RentsManager::getNumberOfClientRents(const ClientPtr &client) const{
    int numberOfRents = 0;
    for (const RentPtr& rent : currentRentRepository->getAll()) {
        if (rent->getClient() == client) {
            numberOfRents += 1;
        }
    }
    return numberOfRents;
}

const ClientPtr &RentsManager::getClientForRentedVehicle(const VehiclePtr& findByVehicle) const{
    for (const RentPtr& rentInRepo : currentRentRepository->getAll()) {
        if (rentInRepo->getVehicle() == findByVehicle)
            return rentInRepo->getClient();
    }
    throw RentsRepositoryException(RentsRepositoryException::vehicleIsNotRented);
}

const std::string RentsManager::currentRentsReport() {
    return "Current rents in repository:" + currentRentRepository->report();
}

const std::string RentsManager::archiveRentsReport() {
    return "Archive rents in repository:" + archiveRentRepository->report();
}



//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
