//  Created by students on 20.04.2020.
//  Bartłomiej Kubiak & Jan Wądołowski
//

#ifndef CURRENTRENTSREPOSITORY_H
#define CURRENTRENTSREPOSITORY_H

#include <list>
#include <string>
#include <memory>
#include "Repository.h"

class Rent;
class Vehicle;
class Client;

typedef std::shared_ptr<Rent> RentPtr;
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

class RentsRepository : public Repository<Rent> {
    
    public:
        //constructors/destructor
        RentsRepository();
        ~RentsRepository() override;
    
        void create(const RentPtr&) override;
        void remove(const RentPtr&) override;
        void remove(int rentRepoIndex) override;
        const std::list<RentPtr> getAll() const override;
        const bool find(const RentPtr &) const override;
        const RentPtr find(int rentRepoIndex) const override;
        const std::string report() const override;
    
    private:
        std::list<RentPtr> rentsRepository;

};
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

#endif //CURRENTRENTSREPOSITORY_H
