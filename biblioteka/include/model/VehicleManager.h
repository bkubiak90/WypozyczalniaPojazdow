//  Created by students on 28.05.2020.
//  Bartłomiej Kubiak & Jan Wądołowski
//
#ifndef VEHICLEMANAGER_H
#define VEHICLEMANAGER_H

#include "VehicleRepository.h"
#include "Vehicle.h"
#include <list>
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

class VehicleManager {
    
    public:
        //constructors/destructors
        VehicleManager();
        ~VehicleManager();
    
        //methods
        void addVehicle(const VehiclePtr &vehicle);
        void removeVehicle(const VehiclePtr &vehicle);
    
        //getters
        VehiclePtr getVehicle(int vehicleIndex) const;
        VehiclePtr getVehicle(const VehiclePtr &vehicle) const;
        std::shared_ptr<VehicleRepository> getAllVehicles() const;
    
    private:
        std::shared_ptr<VehicleRepository> vehicleRepository;
};
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

#endif //VEHICLEMANAGER_H
