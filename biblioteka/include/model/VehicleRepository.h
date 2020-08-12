//  Created by students on 18.04.2020.
//  Bartłomiej Kubiak & Jan Wądołowski
//

#ifndef VEHICLEREPOSITORY_H
#define VEHICLEREPOSITORY_H

#include <vector>
#include <string>
#include <memory>
#include "Repository.h"
#include "PredicateTemplate.h"

class Vehicle;

typedef std::shared_ptr<Vehicle> VehiclePtr;
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

class VehicleRepository : public Repository<Vehicle> {
    
    public:
        //constructors/destructors
        ~VehicleRepository() override;
        VehicleRepository();
    
        void create(const VehiclePtr &) override;
        void remove(const VehiclePtr &) override;
        void remove(int vehicleRepoIndex) override;
        const std::list<std::shared_ptr<Vehicle>> getAll() const override;
        const bool find(const VehiclePtr &) const override;
        const VehiclePtr find(int vehicleRepoIndex) const override;
        const std::string report() const override;

    private:
        std::list<VehiclePtr> vehicles;
};
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

#endif //VEHICLEREPOSITORY_H