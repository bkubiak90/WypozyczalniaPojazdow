//  Created by students on 18.04.2020.
//  Bartłomiej Kubiak & Jan Wądołowski
//

#include "VehicleRepository.h"
#include "VehicleRepositoryException.h"
#include "Vehicle.h"
#include "Repository.h"

using namespace std;
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//constructors/destructors
VehicleRepository::VehicleRepository() = default;
VehicleRepository::~VehicleRepository() = default;
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void VehicleRepository::create(const VehiclePtr &newVehicle) {
    bool alreadyInRepo = false;
    for (auto const &i : vehicles) {
        if(i == newVehicle)
            alreadyInRepo = true;
    }
    if (alreadyInRepo)
        throw VehicleRepositoryException(VehicleRepositoryException::vehicleInRepo);
    else
        vehicles.push_back(newVehicle);
}

void VehicleRepository::remove(const VehiclePtr &veh) {
    if (vehicles.empty()) throw VehicleRepositoryException(VehicleRepositoryException::emptyRepo);
    else if (!(this->find(veh)))throw VehicleRepositoryException(VehicleRepositoryException::vehicleNotFound);
    vehicles.remove(veh);
}

void VehicleRepository::remove(int vehicleRepoIndex) {
    if (vehicles.empty()) throw VehicleRepositoryException(VehicleRepositoryException::emptyRepo);
    vehicles.erase(std::next(vehicles.begin(), vehicleRepoIndex-1));
}

const list<VehiclePtr> VehicleRepository::getAll() const {
    return vehicles;
}

const VehiclePtr VehicleRepository::find(int vehicleRepoIndex) const {
    if (vehicles.empty()) throw VehicleRepositoryException(VehicleRepositoryException::emptyRepo);
    auto it = std::next(vehicles.begin(), vehicleRepoIndex-1);
    return *it;
}

const string VehicleRepository::report() const {
    if (vehicles.empty()) throw VehicleRepositoryException(VehicleRepositoryException::emptyRepo);
    string output = "\nVehicles in repository: \n";
    for (auto const &i : vehicles) {
        output += i->vehicleInfo() + "\n";
    }
    output += "==In total: " + to_string(vehicles.size()) + " vehicles in the repository.==\n";
    return output;
}

const bool VehicleRepository::find(const VehiclePtr &vehicle) const {
    PredicateTemplate<VehiclePtr> find(vehicle);
    auto result = std::find_if(vehicles.begin(),vehicles.end(),find);
    return result != vehicles.end();
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------