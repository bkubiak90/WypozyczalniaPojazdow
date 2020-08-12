//  Created by students on 03.04.2020.
//  Bartłomiej Kubiak & Jan Wądołowski
//

#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
#include <memory>
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

class Vehicle {

    public:
        //constructors/destructors
        Vehicle(const std::string &id, int baseRentPrice);
        virtual ~Vehicle();

        //metoda wyświetla dane o pojeździe w formacie id:baseRentPrice
        virtual std::string vehicleInfo();

        //getters
        const std::string &getId() const;
        virtual double getActualRentalPrice();
    
        //overloaded comparison operators
        friend bool operator== (const std::shared_ptr<Vehicle> &vehicle1, const std::shared_ptr<Vehicle> &vehicle2);
        friend bool operator!= (const std::shared_ptr<Vehicle> &vehicle1, const std::shared_ptr<Vehicle> &vehicle2);

    private:
        const std::string id;
        const int baseRentPrice;
};
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

typedef std::shared_ptr<Vehicle> VehiclePtr ;

#endif //VEHICLE_H