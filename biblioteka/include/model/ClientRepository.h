//  Created by students on 22.04.2020.
//  Bartłomiej Kubiak & Jan Wądołowski
//

#ifndef CLIENTREPOSITORY_H
#define CLIENTREPOSITORY_H

#include <list>
#include <memory>
#include "Client.h"
#include "Repository.h"

class ClientType;
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

class ClientRepository : public Repository<Client> {
    
    public:
        //constructors/destructor
        ClientRepository();
        ~ClientRepository() override ;
        
        //methods
        void create(const ClientPtr&) override;
        void remove(const ClientPtr&) override;
        void remove(int clientRepoIndex) override;
        const std::list<ClientPtr> getAll() const override ;
        const ClientPtr find(int clientRepoIndex) const override;
        const bool find(const ClientPtr &) const override;
        const std::string report() const override;

    private:
        std::list<ClientPtr> clients;
};
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

#endif //CLIENTREPOSITORY_H