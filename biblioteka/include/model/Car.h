//  Created by students on 18.04.2020.
//  Bartłomiej Kubiak & Jan Wądołowski
//

#ifndef CAR_H
#define CAR_H

#include "MotorVehicle.h"
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

class Car: public MotorVehicle {

    public:
        enum class Segment : int {
            A = 10,
            B = 11,
            C = 12,
            D = 13,
            E = 15
        };
        //constructors/destructors
        Car(const std::string &id, int baseRentPrice, int engineDisplacement, enum Segment);
        ~Car() override;
    
        //getters
        double getActualRentalPrice() override;
        std::string vehicleInfo() override;

    private:
        const enum Segment segment;
};
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

#endif //CAR_H
