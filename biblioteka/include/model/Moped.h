//  Created by students on 18.04.2020.
//  Bartłomiej Kubiak & Jan Wądołowski
//

#ifndef MOPED_H
#define MOPED_H

#include "MotorVehicle.h"
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

class Moped: public MotorVehicle {
    
    public:
        //constructors/destructors
        Moped(const std::string &id, int baseRentPrice, int engineDisplacement);
        ~Moped() override;
};
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

#endif //MOPED_H
