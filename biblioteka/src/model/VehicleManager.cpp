//  Created by students on 28.05.2020.
//  Bartłomiej Kubiak & Jan Wądołowski
//

#include <VehicleManagerException.h>
#include "VehicleManager.h"
#include "VehicleRepository.h"
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//constructors/destructors
VehicleManager::VehicleManager() : vehicleRepository(new VehicleRepository){}
VehicleManager::~VehicleManager() = default;
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//methods modifying VehicleRepository
void VehicleManager::addVehicle(const VehiclePtr &vehicle) {
    for (const VehiclePtr &vehicleInRepo : vehicleRepository->getAll()) {
        if (vehicleInRepo == vehicle) {
            throw VehicleManagerException(VehicleManagerException::vehicleAlreadyExist);
        }
    }
    vehicleRepository->create(vehicle);
}

void VehicleManager::removeVehicle(const VehiclePtr &vehicle) {
    //problem: jest możliwe usunięcie pojazdu, który jest aktualnie wypożyczony!
    bool exists = false;
    for (const VehiclePtr &vehicleInRepo : vehicleRepository->getAll()) {
        if (vehicleInRepo == vehicle) {
            vehicleRepository->remove(vehicle);
            exists = true;
        }
    }
    if(!exists) throw VehicleManagerException(VehicleManagerException::vehicleNotFound);
}

VehiclePtr VehicleManager::getVehicle(int vehicleIndex) const {
    if(vehicleRepository->getAll().empty()) throw VehicleManagerException(VehicleManagerException::repoIsEmpty);
    if(vehicleRepository->getAll().size() < vehicleIndex) throw VehicleManagerException(VehicleManagerException::indexDontExist);
    return vehicleRepository->find(vehicleIndex);
}

VehiclePtr VehicleManager::getVehicle(const VehiclePtr &vehicle) const {
    for (auto veh : vehicleRepository->getAll()) {
        if (veh == vehicle)
            return veh;
        }
    throw VehicleManagerException(VehicleManagerException::vehicleNotFound);
}

std::shared_ptr<VehicleRepository> VehicleManager::getAllVehicles() const {
    return vehicleRepository;
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------