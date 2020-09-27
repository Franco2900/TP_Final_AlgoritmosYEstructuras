#include <iostream>
#include <string.h>
#include "local.h"

using namespace std;

int main(){
  
  // ************* PRUEBA 1 ***********************
  //CREANDO UN TDA DE TIPO LOCAL (usar constructor 1, mostrarlo, modificarlo y eliminarlo)
  
  Local* local1 = new Local(1, Salta, 1000, 20000, 200);
  
 	cout <<endl<<"****************PRUEBA 1 ********************"<<endl;
    cout << "Imprimiendo datos del local 1" << endl;
    cout << "Codigo Sucursal: " << getCodigoSucursal(local1) << endl;
    cout << "Provincia: " << getProvincia(local1) << endl;
    cout << "Articulos: " << getCantidadArticulos(local1) << endl;
    cout << "Monto: " << getMonto(local1) << endl;
    cout << "Metros: " << getMetros(local1) << endl;
    cout << "Casa Matriz: " << getCasaMatriz(local1) << endl;
  
 	setCantidadArticulos(local1, 3);
	setMonto(local1, 80000);
	
	cout <<endl<<"Imprimiendo datos del local 1 modificados" << endl;
	cout << "Articulos: " << getCantidadArticulos(local1) << endl;
	cout << "Monto: " << getMonto(local1) << endl;  
  
	//elimino el local
    destruirLocal(local1);
    cout<<endl<<"(El local fue eliminado)"<<endl;
    
    // ************* PRUEBA 2 ***********************
  //CREANDO UN TDA DE TIPO LOCAL (usar constructor 2, mostrarlo, modificarlo y eliminarlo)
	cout <<endl<<"****************PRUEBA 2 ********************"<<endl;
  	Local* local2 = new Local(2,Jujuy,1500,30000,400,1);
	
    cout <<endl<<"Imprimiendo datos del local 2" << endl;
    cout << "Codigo Sucursal: " << getCodigoSucursal(local2) << endl;
    cout << "Provincia: " << getProvincia(local2) << endl;
    cout << "Articulos: " << getCantidadArticulos(local2) << endl;
    cout << "Monto: " << getMonto(local2) << endl;
   	cout << "Metros: " << getMetros(local2) << endl;
    cout << "Casa Matriz: " << getCasaMatriz(local2) << endl;
	
    destruirLocal(local2);
    cout<<endl<<"(El local fue eliminado)"<<endl;

// ************* PRUEBA 3 ***********************
//CREANDO UN TDA DE TIPO LOCAL (usar constructor 3, mostrarlo, modificarlo y eliminarlo)

	Local* local3;
	local3 = crearLocal(local3, 3, Tucuman, 400, 16000, 800,3);
	cout <<endl<<"Imprimiendo datos del local 3" << endl;
    cout << "Codigo Sucursal: " << getCodigoSucursal(local3) << endl;
    cout << "Provincia: " << getProvincia(local3) << endl;
    cout << "Articulos: " << getCantidadArticulos(local3) << endl;
    cout << "Monto: " << getMonto(local3) << endl;
   	cout << "Metros: " << getMetros(local3) << endl;
    cout << "Casa Matriz: " << getCasaMatriz(local3) << endl;

	 destruirLocal(local3);
    cout<<endl<<"(El local fue eliminado)"<<endl;





	system("PAUSE");
    return 0;
}
