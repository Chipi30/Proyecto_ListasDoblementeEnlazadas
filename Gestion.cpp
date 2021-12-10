//
// Created by karen on 7/12/2021.
//

#include "Gestion.h"

void Gestion::addNodeFirst(Automovil info){
    linked->addNodeFirst(info);
}

void Gestion::addNodeLast(Automovil info){
    linked->addNodeLast(info);
}

bool Gestion::contNode(std::string idFind){
    NodeDouble<Automovil>* found = linked->findNode(idFind);
    if (found == NULL){
        return false;
    }else{
        return true;
    }
}

string Gestion::findNode(std::string idFind){
    contNode(idFind);
    if(contNode(idFind)){
        return "No fue encontrado el automovil con el id " + idFind + "\n";
    }else{
        return "Fue encontrado el automovil con el id " + idFind + "\n";
    }
}

bool Gestion::addNodeAfterTo(string id, Automovil info){
    NodeDouble<Automovil>* encontrar = linked->findNode(id);
    if(encontrar == NULL){
        return false;
    }else{
        linked -> addNodeAfterTo(encontrar, info);
        return true;
    }
}

string Gestion::viewList() {
    string view = "";
    for(Automovil automovil: linked->getList(true)){
        view+= automovil.toString()+"\n";
    }
    return view;
}

bool Gestion::addNodeBeforeTo(string id, Automovil info) {
    NodeDouble<Automovil>* encontrar = linked-> findNode("4");
    if (encontrar == NULL){
        return false;
    }else{
        return true;
    }
}
    Gestion::~Gestion() {

}

