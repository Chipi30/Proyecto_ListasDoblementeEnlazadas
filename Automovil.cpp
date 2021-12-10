//
// Created by karen on 7/12/2021.
//

#include "Automovil.h"

Automovil :: Automovil(){

}
Automovil :: Automovil (const string &id,const string &placa,const string &marca): id(id),placa(placa),marca(marca){}

const string &Automovil::getId() const{
    return id;
}

void Automovil::setId(const string &id){
    Automovil::id = id;
}

const string &Automovil::getPlaca() const{
    return placa;
}

void Automovil::setPlaca(const string &placa){
    Automovil::placa = placa;
}

const string &Automovil::getMarca() const{
    return marca;
}

void Automovil::setMarca(const string &marca){
    Automovil::marca = marca;
}

ostream &operator<<(ostream &os, const Automovil &automovil){
    os << "id: " << automovil.id << "placa: " << automovil.placa << "marca: " << automovil.marca;
    return os;
}

Automovil::~Automovil(){

}

string Automovil::toString() {
    return "Id: " + id + "Placa: " + placa + "Marca: " + marca;
}