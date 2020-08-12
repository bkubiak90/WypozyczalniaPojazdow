//  Created by students on 28.05.2020.
//  Bartłomiej Kubiak & Jan Wądołowski
//

#ifndef CLIENTMANAGER_H
#define CLIENTMANAGER_H

#include <memory>

class Address;
class Client;
class ClientType;
class ClientRepository;

typedef std::shared_ptr<ClientType> ClientTypePtr;
typedef std::shared_ptr<Address> AddressPtr;
typedef std::shared_ptr<Client> ClientPtr;
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

class ClientManager {
    
    public:
        //constructors/destructors
        ClientManager();
        ~ClientManager();
    
        //methods modifying clients in ClientRepository
        void addClient(const ClientPtr &client);
        void removeClient(const ClientPtr &client);
        void changeAddress(const ClientPtr &client, AddressPtr &address);
        void changeRegisteredAddress(const ClientPtr &client, AddressPtr &address);
        void changeClientType(const ClientPtr &client, ClientTypePtr &clientType);
        bool findClient(const ClientPtr &);
        const std::string getAllClientsInfo();
    
    private:
        std::shared_ptr<ClientRepository> clientRepository;
};
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

#endif //CLIENTMANAGER_H
