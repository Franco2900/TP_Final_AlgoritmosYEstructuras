#include <iostream>
#include <cstdio>
//#include <dirent.h>
//#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

#include "carga.h"
#include "local.h"
#include "listaLocal.h"
#include "ranking.h"
#include "menu.h"

using namespace std;

void menu(){
    vector<string> archivos = cargaArchivo();         //Este vector dinamico va a tener los nombres de los archivos de la carpeta datos
    Nodo* listaLocales = buildListLocales(archivos);  //Con el vector de antes, creo los locales y una lista con estos
    string franquicia;
    cout<< "\nPor favor, ingrese el nombre de la franquicia: ";
    cin >> franquicia;
    fflush(stdin);
    system("CLS");
    menuPrincipal(listaLocales, franquicia);
    system("CLS");
    cout << "\nMensaje de despedida"<<endl;
    system("pause");
    system("CLS");
}
void menuPrincipal(Nodo*& listaLocales, string franquicia){ //Muestra opciones a elegir con la lista de locales
    int opcion=99;
    while(opcion !=0){
        system("CLS");
        cout << "Bienvenido al sistema de rankings de sucursales de "<< franquicia << endl;
        cout << "1 - Ranking de Facturacion" << endl;
        cout << "2 - Ranking de Articulos Vendidos" << endl;
        cout << "3 - Ranking de Rendimiento" << endl;
        cout << "0 - SALIR" << endl;
        cout << "\nElija el ranking a realizar: ";
        cin >> opcion ;
        switch (opcion){
            case (1):
                system("CLS");
                menuRankingFacYArtVend(listaLocales, opcion);

                system("CLS");
                break;
            case (2):
                system("CLS");
                menuRankingFacYArtVend(listaLocales, opcion);

                system("CLS");
                break;
            case (3):
                system("CLS");
                rankingRendimento(listaLocales);
                system("pause");
                system("CLS");
                break;
            case (0):
                break;
        }
    }
}
void menuRankingFacYArtVend(Nodo*& listaLocales, int opc){
    int opcion=77;
    vector<string> provincias = listaProv(listaLocales); //Recorre la lista de locales y crea una vector con los nombres de las provincias en donde están estos
    string tipoRanking;
    if(opc ==1) tipoRanking = "Facturacion";
    if(opc ==2) tipoRanking = "Venta de articulos";
    cout << "El ranking de "<<tipoRanking<<" esta disponible para las siguientes provincias: \n"<<endl;
    for (int i=0;i<provincias.size();i++){      //Muestra las provincias
        cout << (i+1) <<" - "<< provincias[i]<<"."<<endl;
    }
    cout << "\n88 - VER TODAS." <<endl;
    cout << "99 - RANKING NACIONAL." << endl;
    cout << "\n0  - VOLVER." << endl;
    cout << "\nIngrese su opcion: ";
    cin>>opcion;
    if(opcion !=0){
        if(opcion == 88 ){
            system("CLS");
            rankingAllProvFA(listaLocales, provincias,  opc);
            system("pause");
            system("CLS");
        }
        if(opcion == 99){
            system("CLS");
            Nodo* rankingNac = rankingNacFA(listaLocales, opc);
            mostrarLista(rankingNac);
            system("pause");
            system("CLS");
        }
        if(opcion >=1 && opcion<=provincias.size()){
            system("CLS");
            Nodo* rankingProv = rankingProvFA(listaLocales, provincias[opcion-1], opc);
            mostrarLista(rankingProv);
            system("pause");
            system("CLS");
        }
    }
};
