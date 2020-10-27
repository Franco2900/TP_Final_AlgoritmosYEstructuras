#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>

#include "ranking.h"
//#include "listaLocal.h"
using namespace std;

//############ RANKING => FACTURACION Y VENTAS


void rankingAllProvFA(Nodo *&lista, vector<string> prov, int opc){ //Crea un ranking provincial de cada provincia
    string tipoRanking;
    for(int i=0;i<prov.size();i++){
        Nodo* ranking = rankingProvFA(lista, prov[i], opc);
        cout << "##########################################"<<endl;
        cout << "Ranking de la provincia "<<prov[i]<<endl;
        mostrarLista(ranking, opc);

    }
    system("pause");
};

Nodo* rankingProvFA(Nodo*& lista, string provincia, int opc){ //Crea un ranking con los locales de una provincia (el ranking puede ser por facturación o articulos vendidos)
    Nodo* listaRanking = NULL;
    Nodo* actual = new Nodo();
    actual = lista;
    if (opc == 1)cout << "RANKING DE FACTURACION"<< endl;
    if (opc == 2)cout << "RANKING DE VENTA DE ARTICULOS"<< endl;
    while(actual !=NULL){
        if(actual->dato->provincia == provincia){
            Local* loc = new Local(actual->dato);
            if (opc == 1)insertXFact(listaRanking, loc);
            if (opc == 2)insertXArt(listaRanking, loc);
        }
        actual = actual->siguiente;
    }
    return listaRanking;
};
Nodo* rankingNacFA(Nodo *&lista, int opc){ //Crea un ranking con los locales a nivel nacional (el ranking puede ser por facturación o articulos vendidos)
    Nodo* listaRanking = NULL;
    Nodo* actual = new Nodo();
    actual = lista;
    if (opc == 1)cout << "RANKING DE FACTURACION"<< endl;
    if (opc == 2)cout << "RANKING DE VENTA DE ARTICULOS"<< endl;
    while(actual !=NULL){
        Local* loc = new Local(actual->dato);
        if (opc == 1)insertXFact(listaRanking, loc);
        if (opc == 2)insertXArt(listaRanking, loc);
        actual = actual->siguiente;
    }
    return listaRanking;
};
//############ RANKING => RENDIMIENTO
void rankingRendimento(Nodo *&lista){ //Ranking de las casas matrices basadas en su rendimiento
    Nodo* listaRanking = localesXMatriz(lista);
    vector<int> matriz = listaMatriz(listaRanking);
    mostrarRankingRendimiento(listaRanking,matriz);
};
Nodo* localesXMatriz(Nodo *&lista){ //Agrupa locales por matriz
    Nodo* listaRanking = NULL;
    Nodo* actual = new Nodo();
    actual = lista;
    while(actual !=NULL){
        Local* loc = new Local(actual->dato);
        insertXCasaMatriz(listaRanking, loc);
        actual = actual->siguiente;
    }
    return listaRanking;
}
void ordenMatrizRendimiento(Nodo *& lista, vector<int>& matriz){
    int aux=0;
    bool cambio = false;
    while(!cambio){
            cambio = true;
                for (int i=0;i<matriz.size()-1;i++){
                    if ( (rendimiento(lista, matriz[i])) < (rendimiento(lista, matriz[i+1])) ){
                        aux = matriz[i];
                        matriz[i] = matriz[i+1];
                        matriz[i+1] = aux;
                        cambio = false;
                    }
                }
    }
}
float rendimiento(Nodo*& lista, int matriz){
    float monto = 0;
    float metros = 0;
    Nodo* actual = new Nodo();
    actual = lista;
    while(actual !=NULL){
            if(actual->dato->casaMatriz == matriz){
                monto = monto + actual->dato->monto;
                metros = metros + actual->dato->metros ;
            }
        actual = actual->siguiente;
    }
    return  monto/metros;
};
vector<int> listaMatriz(Nodo *&lista){ //Separa las casas matrices de la lista
    vector<int> matriz;
    Nodo * actual = new Nodo();
    actual = lista;
    while(actual != NULL){
       if(actual->siguiente == NULL) matriz.push_back(actual->dato->casaMatriz );
       if((actual->siguiente != NULL) && (actual->dato->casaMatriz != actual->siguiente->dato->casaMatriz))matriz.push_back(actual->dato->casaMatriz );
        actual = actual->siguiente;
    }
    ordenMatrizRendimiento(lista, matriz);
    return matriz;
};
vector<string> listaProv(Nodo *&lista){ //El vector va a almacenar el nombre de las provincias que tengan locales
    vector<string> provincias;
    Nodo * actual = new Nodo();
    actual = lista;
    while(actual != NULL){
       if(actual->siguiente == NULL) provincias.push_back(actual->dato->provincia );
       if((actual->siguiente != NULL) && (actual->dato->provincia != actual->siguiente->dato->provincia))provincias.push_back(actual->dato->provincia );
        actual = actual->siguiente;
    }
    return provincias;
};
void mostrarRankingRendimiento(Nodo* lista, vector<int>& matriz){
    cout << "RANKING DE RENDIMIENTO"<< endl;
    for(int i =0; i< matriz.size();i++){
        cout << "\nEl puesto Nro. "<<(i+1)<<" del ranking con un rendimiento de "<< rendimiento(lista, matriz[i])<<"."<<endl;
        cout << "Es correspondiente a la casa matriz "<< matriz[i]<<"."<< endl;
        cout <<"Esta compuesto por el/los siguiente/s local/es:\n"<<endl;
        Nodo * actual = new Nodo();
        actual = lista;
            while(actual != NULL){
                if(actual->dato->casaMatriz == matriz[i]){
                    mostrarLocal(actual->dato);
                    cout << "\n" << endl;
                }
                actual = actual->siguiente;
        }
        cout << "/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/" << endl;
    }
};
