//  Created by students on 28.05.2020.
//  Bartłomiej Kubiak & Jan Wądołowski
//

#include "ClientManager.h"
#include "ClientRepository.h"
#include "ClientManagerException.h"
#include "Address.h"
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//constructors/destructors
ClientManager::ClientManager() : clientRepository(new ClientRepository) {}
ClientManager::~ClientManager() = default;
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void ClientManager::addClient(const ClientPtr &client) {

    for (const ClientPtr &clientInRepo : clientRepository->getAll()) {
        if (clientInRepo == client) {
            throw ClientManagerException(ClientManagerException::clientAlreadyExist);
        }
    }
    clientRepository->create(client);
}

void ClientManager::removeClient(const ClientPtr &client) {
    bool exists = false;
    for (const ClientPtr &clientInRepo : clientRepository->getAll()) {
        if (clientInRepo == client) {
            clientRepository->remove(client);
            exists = true;
        }
    }
    if (!exists) throw ClientManagerException(ClientManagerException::clientNotFound);
}

void ClientManager::changeAddress(const ClientPtr &client, AddressPtr &address) {
    client->setAddress(address);
}

void ClientManager::changeRegisteredAddress(const ClientPtr &client, AddressPtr &address) {
    client->setRegisteredAddress(address);
}

void ClientManager::changeClientType(const ClientPtr &client, ClientTypePtr &clientType) {
    client->changeClientType(clientType);
}

bool ClientManager::findClient(const ClientPtr &client) {
    return clientRepository->find(client);
}

const std::string ClientManager::getAllClientsInfo() {
    return clientRepository->report();
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------