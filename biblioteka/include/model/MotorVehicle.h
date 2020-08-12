//  Created by students on 18.04.2020.
//  Bartłomiej Kubiak & Jan Wądołowski
//

#ifndef MOTORVEHICLE_H
#define MOTORVEHICLE_H

#include "Vehicle.h"
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

class MotorVehicle: public Vehicle {
    
    public:
        //constructors/destructors
        MotorVehicle(const std::string &id, int baseRentPrice, const int engineDisplacement);
        virtual ~MotorVehicle();
    
        //getters
        std::string vehicleInfo() override;
        double getActualRentalPrice() override;
    
    private:
        const int engineDisplacement;
};
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

#endif //MOTORVEHICLE_H
