#ifndef LISTALOCALES_H_INCLUDED
#define LISTALOCALES_H_INCLUDED

//#include <vector>
//#include <string>

#include "local.h"

using namespace std;

 struct Nodo{
	Local *dato;
	Nodo *siguiente;

	Nodo(){};
	Nodo(Local *loc){
	    dato = loc;
	    siguiente = NULL;
	}
};

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
void insertarLista(Nodo *&lista, Local *dato);
void insertXCasaMatriz(Nodo *&lista, Local *local);
void insertXFact(Nodo *&lista, Local *local);
void insertXArt(Nodo *&lista, Local *local);
void mostrarLista(Nodo *&lista);






#endif // LISTALOCALES_H_INCLUDED
