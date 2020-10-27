#ifndef LISTALOCALES_H_INCLUDED
#define LISTALOCALES_H_INCLUDED

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

void insertarLista(Nodo *&lista, Local *dato);
void insertXCasaMatriz(Nodo *&lista, Local *local);
void insertXFact(Nodo *&lista, Local *local);
void insertXArt(Nodo *&lista, Local *local);

void mostrarLista(Nodo *&lista, int opc);
void mostrarLocal(Local *local);
void mostrarTotal(Nodo *&lista, int opc);

#endif // LISTALOCALES_H_INCLUDED
