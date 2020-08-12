//  Created by students on 28.05.2020.
//  Bartłomiej Kubiak & Jan Wądołowski
//

#ifndef REPOSITORY_H
#define REPOSITORY_H

#include <list>
#include <memory>
#include "PredicateTemplate.h"
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

template <class T>

class Repository {
    
    public:
        //constructors/destructors
        virtual ~Repository() = default;
        
        //methods
        virtual void create(const std::shared_ptr<T> &) = 0;
        virtual void remove(const std::shared_ptr<T> &) = 0;
        virtual void remove(int) = 0;
        virtual const std::list <std::shared_ptr<T>> getAll() const = 0;
        virtual const std::shared_ptr<T> find(int) const = 0;
        virtual const bool find(const std::shared_ptr<T> &) const = 0;
        virtual const std::string report() const = 0;
};
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

#endif //REPOSITORY_H


//virtual const std::shared_ptr<T> find(const std::shared_ptr<T> &) const = 0;
//virtual const std::shared_ptr<T> find(findInRepo<std::shared_ptr<T>> &) const = 0;
//virtual const std::shared_ptr<T> find(const std::shared_ptr<T> &) const = 0;