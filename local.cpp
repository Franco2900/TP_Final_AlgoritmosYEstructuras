#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include "local.h"
using namespace std;
/********************************************************************************************************************************/
/*
    ATRIBUTOS:
    codigoSucursal
    provincia
    cantidadArticulos
    monto
    metros
    casaMatriz

    AXIOMAS:
    codigoSucursal > 0
    provincia
    cantidadArticulos => 0
    monto >= 0
    metros > 0
    casaMatriz (codigoSucursal del local desde que se maneja todo)
*/
/********************************************************************************************************************************/

//Destructor
void destruirLocal(Local* local){
    delete local;
}


//Getters y Setters
int getCodigoSucursal(Local* local){
    return local->codigoSucursal;
}
void setCodigoSucursal(Local* local,int codigoSucursal){
    if(codigoSucursal > 0) local->codigoSucursal = codigoSucursal;
}


string getProvincia(Local *local){
    return local->provincia;
}
void setProvincia(Local *local, string provincia){
   local->provincia = provincia;
}


int getCantidadArticulos(Local* local){
    return local->cantidadArticulos;
}
void setCantidadArticulos(Local* local, int cantidadArticulos){
    if(cantidadArticulos >= 0) local->cantidadArticulos = cantidadArticulos;
}


float getMonto(Local* local){
    return local->monto;
}
void setMonto(Local* local, float monto){
    if(monto >= 0) local->monto = monto;
}


float getMetros(Local* local){
    return local->metros;
}
void setMetros(Local* local, float metros){
    if(metros > 0) local->metros = metros;
}


int getCasaMatriz(Local* local){
    return local->casaMatriz;
}
void setCasaMatriz(Local* local, int casaMatriz){
    if(casaMatriz > 0) local->casaMatriz = casaMatriz;
}

/********************************************************************************************************************************/

//Métodos

void mostrarLocal(Local* local){
    cout << "Codigo sucursal: "     << local->codigoSucursal    << endl;
    cout << "Provincia: "           << local->provincia         << endl;
    cout << "Cantidad Articulos: "  << local->cantidadArticulos << endl;
    cout << "Monto: "               << local->monto             << endl;
    cout << "Metros: "              << local->metros            << endl;
    cout << "Casa Matriz: "         << local->casaMatriz        << endl;
}
