#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <iomanip>

#include "local.h"
#include "listaLocal.h"

using namespace std;

void insertarLista(Nodo *&lista, Local *local){
    Nodo * nuevo = new Nodo(local);
    Nodo * aux1 = lista;
    Nodo * aux2;
    //while para rerorrer cada nodo hasta ubicar la provincia
    while((aux1 !=NULL) && (aux1->dato->provincia != local->provincia) ){
        aux2 = aux1;
        aux1= aux1->siguiente;
    }
    //while para para agrupar las caza matriz
    while( (aux1 !=NULL) && (aux1->dato->provincia == local->provincia) && (aux1->dato->casaMatriz != local->casaMatriz) ){
        aux2 = aux1;
        aux1= aux1->siguiente;
    }
    if(lista == aux1){//si la lista está vacia, se le agrega el nuevo nodo
        lista = nuevo;
    }else{
        aux2->siguiente = nuevo; // si no está vacia se agrega el nodo en la ubicacion correspondiente
    }
    nuevo->siguiente = aux1;
};
void insertXCasaMatriz(Nodo *&lista, Local *local){
    Nodo * nuevo = new Nodo(local);
    Nodo * aux1 = lista;
    Nodo * aux2;
    //while para para agrupar las caza matriz
    while( (aux1 !=NULL) && (aux1->dato->casaMatriz != local->casaMatriz) ){
        aux2 = aux1;
        aux1= aux1->siguiente;
    }
    if(lista == aux1){//si la lista está vacia, se le agrega el nuevo nodo
        lista = nuevo;
    }else{
        aux2->siguiente = nuevo; // si no está vacia se agrega el nodo en la ubicacion correspondiente
    }
    nuevo->siguiente = aux1;
};
void insertXFact(Nodo *&lista, Local *local){
    Nodo * nuevo = new Nodo(local);
    Nodo * aux1 = lista;
    Nodo * aux2;

    while( (aux1 !=NULL) && (aux1->dato->monto > local->monto) ){
        aux2 = aux1;
        aux1= aux1->siguiente;
    }
    if(lista == aux1){//si la lista está vacia, se le agrega el nuevo nodo
        lista = nuevo;
    }else{
        aux2->siguiente = nuevo; // si no está vacia se agrega el nodo en la ubicacion correspondiente
    }
    nuevo->siguiente = aux1;
};
void insertXArt(Nodo *&lista, Local *local){
    Nodo * nuevo = new Nodo(local);
    Nodo * aux1 = lista;
    Nodo * aux2;

    while( (aux1 !=NULL) && (aux1->dato->cantidadArticulos > local->cantidadArticulos) ){
        aux2 = aux1;
        aux1= aux1->siguiente;
    }
    if(lista == aux1){//si la lista está vacia, se le agrega el nuevo nodo
        lista = nuevo;
    }else{
        aux2->siguiente = nuevo; // si no está vacia se agrega el nodo en la ubicacion correspondiente
    }
    nuevo->siguiente = aux1;
};

void mostrarTotal(Nodo *&lista, int opc){
    Nodo * actual = new Nodo();
    actual = lista;

    float total = 0;
    while(actual != NULL){
        if(opc==1)total = total + actual->dato->monto;
        if(opc==2)total = total + actual->dato->cantidadArticulos;
        actual = actual->siguiente;
    }

    if(opc==1){cout<< "\nTotal de facturacion: " << total << endl;}
    if(opc==2){cout<< "\nTotal de articulos vendidos: " << total << endl;}
};


void mostrarLocal(Local* local){
    cout << "Codigo sucursal: "     << local->codigoSucursal    << endl;
    cout << "Provincia: "           << local->provincia         << endl;
    cout << "Cantidad Articulos: "  << local->cantidadArticulos << endl;
    cout << "Monto: "               << local->monto             << endl;
    cout << "Metros: "              << local->metros            << endl;
    cout << "Casa Matriz: "         << local->casaMatriz        << endl;
}


void mostrarLista(Nodo *&lista, int opc){
    int i =1;
    Nodo * actual = new Nodo();
    actual = lista;
    while(actual != NULL){
        cout << "\n" << endl;
        cout << ">>>>>>>>>>  "<< i <<"  <<<<<<<<<<"<<endl;
        mostrarLocal(actual->dato);  //mostrarLocal
        //cout << "^^^^^^^^^^^^^^^^^^^^^^"<<endl;
       actual = actual->siguiente;
       i++;
    }

    mostrarTotal(lista, opc);

    cout << "\n" << endl;
    cout<< "LOCALES MOSTRADOS: "<<i-1 <<endl;
    cout << "\n\n" << endl;
};
