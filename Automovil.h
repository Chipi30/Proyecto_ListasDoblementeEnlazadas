//
// Created by karen on 7/12/2021.
//

#ifndef PROYECTOLISTASENLAZADAS_AUTOMOVIL_H
#define PROYECTOLISTASENLAZADAS_AUTOMOVIL_H
#include <string>
#include <ostream>

using namespace std;

class Automovil{

public:
    Automovil();

    Automovil(const string &id, const string &placa, const string &marca);

    const string &getId() const;

    void setId(const string &id);

    const string &getPlaca() const;

    void setPlaca(const string &placa);

    const string &getMarca() const;

    void setMarca(const string &marca);

    string toString();

    friend ostream &operator<<(ostream &os, const Automovil &automovil);

    virtual ~Automovil();

private:
    string id;
    string placa;
    string marca;
};
#endif //PROYECTOLISTASENLAZADAS_AUTOMOVIL_H
