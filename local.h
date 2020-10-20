#ifndef LOCAL_H_INCLUDED
#define LOCAL_H_INCLUDED

#include <string>
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
    provincia (Buenos_Aires por default)
    cantidadArticulos => 0
    monto >= 0
    metros > 0
    casaMatriz (codigoSucursal del local desde que se maneja todo)
*/
/********************************************************************************************************************************/

using namespace std;
struct Local{
    int codigoSucursal;
	string provincia;
	int cantidadArticulos;
	float monto;
	float metros;
	int casaMatriz;

    Local();
	Local(int codigoS, string provincia, int cantidadArticulos, float monto, float metros, int casaMatriz){
        Local::codigoSucursal    = codigoS;
        Local::provincia         = provincia;
        Local::cantidadArticulos = cantidadArticulos;
        Local::monto             = monto;
        Local::metros            = metros;
        Local::casaMatriz        = casaMatriz;
	}
	Local(Local *l){
        Local::codigoSucursal    = l->codigoSucursal;
        Local::provincia         = l->provincia;
        Local::cantidadArticulos = l->cantidadArticulos;
        Local::monto             = l->monto;
        Local::metros            = l->metros;
        Local::casaMatriz        = l->casaMatriz;
	}
};


//CONSTRUCTORES
/*Local crearLocal();*/


//DESTRUCTOR
void destruirLocal(Local *local);



//GETTERS Y SETTERS
int getCodigoSucursal(Local *local);
void setCodigoSucursal(Local *local,int codigoSucursal);

string getProvincia(Local *local);
void setProvincia(Local *local, string provincia);

int getCantidadArticulos(Local *local);
void setCantidadArticulos(Local *local, int cantidadArticulos);

float getMonto(Local *local);
void setMonto(Local *local, float monto);

float getMetros(Local *local);
void setMetros(Local *local, float metros);

int getCasaMatriz(Local *local);
void setCasaMatriz(Local *local, int casaMatriz);

/********************************************************************************************************************************/

//MÉTODOS
void mostrarLocal(Local *local);


#endif // LOCAL_H_INCLUDED
