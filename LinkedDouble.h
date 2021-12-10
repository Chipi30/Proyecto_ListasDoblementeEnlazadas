//
// Created by karen on 7/12/2021.
//

#ifndef PROYECTOLISTASENLAZADAS_LINKEDDOUBLE_H
#define PROYECTOLISTASENLAZADAS_LINKEDDOUBLE_H
#include <vector>
#include "NodeDouble.h"
#include <string>

template <class T>
class LinkedDouble {
public:
    LinkedDouble();

    bool isEmpty();

    void addNodeFirst( T );

    void addNodeLast( T );

    NodeDouble<T>* findNode( std::string );

    T* findInfo( std::string );

    void addNodeSorted( T );

    void addNodeBeforeTo( NodeDouble<T>*, T);

    void addNodeAfterTo( NodeDouble<T>*, T);

    std::vector<T> getList(bool);

    T deleteNode(NodeDouble<T>*);

    T getFirst();

    T getLast();

    int getSize();

    T* getObject(int);

    virtual ~LinkedDouble();

private:
    NodeDouble<T>* head;
    NodeDouble<T>* last;

};
#endif //PROYECTOLISTASENLAZADAS_LINKEDDOUBLE_H
