//  Created by students on 31.05.2020.
//  Bartłomiej Kubiak & Jan Wądołowski
//

#ifndef FIND_H
#define FIND_H

#include <memory>
#include <list>
#include <algorithm>


//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
template <class T>
class PredicateTemplate {

public:
    PredicateTemplate(T szukany) : szukany(szukany) {}


    bool operator () (const T &sprawdzany)  {
        return szukany == sprawdzany;
    }

private:
    T szukany;
    
};




//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

#endif //FIND_H


/*
template <class T>

class PredicateTemplate {

    public:
        //constructors/destructors
        PredicateTemplate <T>::PredicateTemplate(std::list <T> list) : repo(list<T>) {}
        PredicateTemplate <T>::~PredicateTemplate() = default;
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

        //overloading operator
        shared_ptr <T> PredicateTemplate<T>::operator()(T &object) const {
            return *(std::find(repo.begin(), repo.end(), &object));
        }

        shared_ptr <T> PredicateTemplate <T>::operator()(int index) const {
            return *(std::find(repo.begin(), repo.end(), *next(repo.begin(), index)));
        }

private:
    std::list repo;
};*/