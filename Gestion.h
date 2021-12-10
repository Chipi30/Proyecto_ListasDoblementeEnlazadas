//
// Created by karen on 7/12/2021.
//

#ifndef PROYECTOLISTASENLAZADAS_GESTION_H
#define PROYECTOLISTASENLAZADAS_GESTION_H
#include "Automovil.h"
#include "LinkedDouble.h"
#include "Gestion.h"

class Gestion{

private:
    LinkedDouble<Automovil>* linked;

public:
    Gestion(){
        linked = new LinkedDouble<Automovil>();
        linked->addNodeFirst(Automovil("1","QFK 839","Renault Nissan"));
        linked->addNodeFirst(Automovil("2","NAJ 144","Volkswagen"));
        linked->addNodeLast(Automovil("3","BTS 613","Hyundai"));
        linked->addNodeLast(Automovil("4","TLP 864","BMW Group"));
    }

    void addNodeFirst(Automovil);

    void addNodeLast(Automovil);

    bool contNode(std::string);

    string findNode(std::string);

    bool addNodeAfterTo(string, Automovil);

    bool addNodeBeforeTo(string, Automovil);

    void addNodeSorted(Automovil info){
        linked->addNodeSorted(info);
    }

    string viewList();

    virtual ~Gestion();

};

#endif //PROYECTOLISTASENLAZADAS_GESTION_H
