//  Created by students on 20.04.2020.
//  Bartłomiej Kubiak & Jan Wądołowski
//
#include <string>
#include "RentsRepository.h"
#include "Rent.h"
#include "Vehicle.h"
#include "Client.h"
#include "RentsRepositoryException.h"

using namespace std;
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//constructors/destructors
RentsRepository::RentsRepository() = default;
RentsRepository::~RentsRepository() = default;
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void RentsRepository::create(const RentPtr &newRent)  {
        rentsRepository.push_back(newRent);
}

void RentsRepository::remove(const RentPtr& rent) {
    rentsRepository.remove(rent);
}

void RentsRepository::remove(int rentRepoIndex) {
    rentsRepository.erase(std::next(rentsRepository.begin(), rentRepoIndex-1));             //NIE DZIAŁA, NIE WIEM CZEMU BO W CLIENT i VEHICLE REPO JEST OK
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//getters
const list<RentPtr> RentsRepository::getAll() const {
    return rentsRepository;
}

const RentPtr RentsRepository::find(int rentRepoIndex) const {
    auto it = std::next(rentsRepository.begin(), rentRepoIndex-1);
    return *it;
}

//methods providing string output of information
const string RentsRepository::report() const{
    string output = "";
    for (const auto& rent : rentsRepository) {
        output += rent->rentInfo() + "\n";
    }
    return output;
}

const bool RentsRepository::find(const shared_ptr<Rent> &rent) const {
    PredicateTemplate<RentPtr> find(rent);
    auto result = std::find_if(rentsRepository.begin(),rentsRepository.end(),find);
    return result != rentsRepository.end();
}


//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------