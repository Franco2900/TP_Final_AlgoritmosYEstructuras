#include <iostream>
#include "local.h"

using namespace std;

int main()
{
    cout << "Hola" << endl;

    //El usuario crear�a un local
    crearLocal(); //Este local va a tener valores por default hasta que el usuario meta los datos

    //El codigo de la sucursal deber�a ser auto-incrementable. El usuario a lo mucho debe elegir la casaMatriz
    cout << "Elija la provincia" << endl;
    cout << "Indique cantidad de articulos a la venta" << endl;
    //El monto obtenido por las ventas no deber�a ingresarlo el usuario
    cout << "Indique en metros cuadrados el tama�o del local" << endl;
    //La casaMatriz creo que no deber�a ingresarla el usuario porque se supone que es la misma para todos los locales de la cadena

    //Falta los "cin"

    return 0;
}
