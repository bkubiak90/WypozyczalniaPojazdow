//  Created by students on 22.04.2020.
//  Bartłomiej Kubiak & Jan Wądołowski
//

#include <algorithm>
#include "ClientRepository.h"
#include "ClientRepositoryException.h"
#include "PredicateTemplate.h"

using namespace std;
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//constructors/destructors
ClientRepository::ClientRepository() = default;
ClientRepository::~ClientRepository() = default;
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//methods modifying repository
void ClientRepository::create(const ClientPtr& addClient) {
    ClientRepository::clients.push_back(addClient);
}

void ClientRepository::remove(const ClientPtr& deleteClient) {
    if (!deleteClient->getRents().empty()) throw ClientRepositoryException(ClientRepositoryException::clientHasRents);
    ClientRepository::clients.remove(deleteClient);
}

void ClientRepository::remove(int index) {
    if(clients.empty()) throw ClientRepositoryException(ClientRepositoryException::repoIsEmpty);
    auto it = std::next(clients.begin(), index - 1);
    if (!((*it)->getRents().empty())) throw ClientRepositoryException(ClientRepositoryException::clientHasRents);
    clients.erase(std::next(clients.begin(), index-1));
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//methods modifying clients

const ClientPtr ClientRepository::find(int rentRepoIndex) const {
    if(clients.empty()) throw ClientRepositoryException(ClientRepositoryException::repoIsEmpty);
    auto it = std::next(clients.begin(), rentRepoIndex - 1);
    return *it;
}

const string ClientRepository::report() const{
    if(clients.empty()) throw ClientRepositoryException(ClientRepositoryException::repoIsEmpty);
    string output = "Clients in repository: \n";
    for (const auto& rent : clients) {
        output += rent->clientInfo() + "\n";
    }
    return output;
}

const bool ClientRepository::find(const ClientPtr &client) const {
    PredicateTemplate<ClientPtr> find(client);
    auto result = std::find_if(clients.begin(),clients.end(),find);
    return result != clients.end();
}

const std::list<ClientPtr> ClientRepository::getAll() const {
    return clients;
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------