//
// Created by karen on 7/12/2021.
//

#ifndef PROYECTOLISTASENLAZADAS_NODEDOUBLE_H
#define PROYECTOLISTASENLAZADAS_NODEDOUBLE_H

#include <cstdlib>

template <class T> class LinkedDouble;

template <class T>
class NodeDouble{
    friend class LinkedDouble<T>;
public:
    NodeDouble(){
        next = NULL;
        previous = NULL;
    }
    NodeDouble(T info) : info(info){
        next = previous = NULL;
    }
    virtual ~NodeDouble(){
    }

private:
    T info;
    NodeDouble<T>* next;
    NodeDouble<T>* previous;
};


#endif //PROYECTOLISTASENLAZADAS_NODEDOUBLE_H