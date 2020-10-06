#include <iostream>
#include <cstdio>
//#include <dirent.h>
//#include <fstream>
#include <string>
#include <vector>
#include <iomanip>


#include "local.h"
#include "listaLocal.h"

using namespace std;

//CONSTRUCTOR
void Constructor(Nodo &lista, Local &dato);

//DESTRUCTOR
void Destructor(Nodo &lista);

//Getters y Setters
Local getDato(Nodo &lista);
void setDato(Nodo &lista, Local &dato);

Nodo getSiguiente(Nodo &lista);
void setDato(Nodo &lista, Nodo *siguiente);

//METODOS
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
void mostrarLista(Nodo *&lista){
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
    cout << "\n" << endl;
    cout<< "LOCALES MOSTRADOS: "<<i-1 <<endl;
};
