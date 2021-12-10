#include <iostream>
#include <conio.h>
#include "Automovil.h"
#include "LinkedDouble.cpp"
#include "NodeDouble.h"
#include "Gestion.h"

using namespace std;

int main() {
    int tecla = 0;
    do {
        cout << "\t----MENU----" << endl;
        cout << "\t------------" << endl << endl;
        cout << "\t1.) Agregar" << endl;
        cout << "\t2.) Buscar" << endl;
        cout << "\t3.) Eliminar" << endl;
        cout << "\t4.) Cantidad" << endl;
        cout << "\t5.) Mostrar lista" << endl;
        cout << "\t6. Salir) "<< endl << endl;
        cout << "\tElige una opcion: ";
        cin >>tecla;

            LinkedDouble<Automovil>* linked = new LinkedDouble<Automovil>();
            linked->addNodeFirst(Automovil("1","QFK 839","Renault Nissan"));
            linked->addNodeFirst(Automovil("2","NAJ 144","Volkswagen"));
            linked->addNodeLast(Automovil("3","BTS 613","Hyundai"));
            linked->addNodeLast(Automovil("4","TLP 864","BMW Group"));

            Gestion *gestion = new Gestion();

        switch (tecla) {
            case 1: {
                int agregar;
                string id,placa,marca;
                cout << "1.) Agregar al inicio de la lista " << endl;
                cout << "2.) Agregar al fianl de la lista " << endl;
                cout << "3.) Agregar automovil antes de otro" << endl;
                cout << "4.) Agregar automovil despues de otro" << endl;
                cout << "5.) Agragar varios automoviles ordenados por su id" << endl;
                cout << "\n Digite una opcion: " << endl;
                cin >> agregar;
                if (agregar == 1) {
                    cout << "Digitar datos del automovil" << endl;
                    cout << "id del automovil: " << endl;
                    cin >> id;
                    cout << "Ingrese la placa: " << endl;
                    cin >> placa;
                    cout << "Ingrese la marca: " << endl;
                    cin >> marca;

                    gestion->addNodeFirst(Automovil(id, placa, marca));
                    cout << endl;
                    cout << "Lista con el automovil agregado al inicio" << endl;
                    cout << endl;
                    cout << gestion->viewList();
                    getch();

                } else if (agregar == 2) {
                    cout << "Digitar datos del automovil" << endl;
                    cout << "id del automovil: " << endl;
                    cin >> id;
                    cout << "Ingrese la placa: " << endl;
                    cin >> placa;
                    cout << "Ingrese la marca: " << endl;
                    cin >> marca;

                    gestion->addNodeLast(Automovil(id, placa, marca));
                    cout << endl;
                    cout << "Lista con el automovil agegado al final" << endl;
                    cout << endl;
                    cout << gestion->viewList();

                } else if (agregar == 3) {
                    string idAfter;
                    cout << "Digite el id del automovil despues: " << endl;
                    cin >> idAfter;
                    cout << "Digitar datos del automovil" << endl;
                    cout << "id del automovil: " << endl;
                    cin >> id;
                    cout << "Ingrese la placa: " << endl;
                    cin >> placa;
                    cout << "Ingrese la marca: " << endl;
                    cin >> marca;

                    cout << gestion->addNodeAfterTo(id, Automovil(id, placa, marca));
                    cout << gestion->viewList();

                } else if (agregar == 4) {
                    string idAfter;

                } else if (agregar == 5) {
                    cout << "Digitar datos del automovil" << endl;
                    cout << "id del automovil: " << endl;
                    cin >> id;
                    cout << "Ingrese la placa: " << endl;
                    cin >> placa;
                    cout << "Ingrese la marca: " << endl;
                    cin >> marca;

                    gestion->addNodeSorted(Automovil(id, placa, marca));
                    cout << gestion->viewList();
                } else {
                    cout << "La opcion no es valida" << endl;
                }
            }
                break;
            case 2: {
                int find;
                string idFind;
                cout << "1.) Buscar si existe un automovil" << endl;
                cout << "2.) Buscar un automovil y su informacion" << endl;
                cout << "3.) Buscar el primer automovil de la lista" << endl;
                cout << "4.) Buscar el ultimo automovil de la lista" << endl;
                cout << "5.) Buscar el automovil de placa n en la lista" << endl;
                cin >> find;

                if (find == 1) {
                    cout << "Digite el id del automovil que desea buscar: " << endl;
                    cin >> idFind;
                    NodeDouble<Automovil> *found = linked->findNode(idFind);
                    if (found == NULL) {
                        cout << "No se encontro el automovil con id: " << idFind << endl;
                    } else {
                        cout << "El automovil si fue encontrado con el id: " << idFind << endl;
                    }
                } else if (find == 2) {
                    cout << "Digite el id del automovil que desea buscar: " << endl;
                    cin >> idFind;
                    Automovil *findAutomovil = linked->findInfo(idFind);
                    if (findAutomovil == NULL) {
                        cout << "No se encontro el automovil con id: " << idFind;
                    } else {
                        cout << "Si se encontro el automovil, la informacion es: \n" << *findAutomovil;
                    }
                } else if (find == 3) {
                    cout << "Primer automovil en la lista: \n" << linked->getFirst() << endl;
                } else if (find == 4) {
                    cout << "Ultimo automovil en la lista: \n" << linked->getLast() << endl;
                } else if (find == 5) {
                    Automovil *found = linked->getObject(6);
                    if (found != NULL) {
                        cout << *found << endl;
                    } else {
                        cout << "No se encontro" << endl;
                    }
                } else {
                    cout << "La opcion no es valida" << endl;
                }
            }
                break;
            case 3: {
                string idEliminar;
                cout << "Digite el id del nodo que desea eliminar: " << endl;
                cin >> idEliminar;
                NodeDouble<Automovil> *found = linked->findNode(idEliminar);
                linked->deleteNode(found);
                for (Automovil automovil: linked->getList(true)) {
                    cout << automovil << endl;
                }
            }
                break;
            case 4:
                cout << "La cantidad de automiviles existentes es de: " << linked->getSize() << endl;
                break;
            case 5:
                cout << "Lista de automoviles: " << endl;
                for (Automovil automovil: linked->getList(true)) {
                    cout << automovil << endl;
                }
                break;
            case 6:
                cout<<"Saliendo del programa...";
                exit(0);
            default:

                break;
        }
    }while(tecla != 6);
    return 0;
}

