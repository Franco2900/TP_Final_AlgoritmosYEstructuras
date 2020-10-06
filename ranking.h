#ifndef RANKING_H_INCLUDED
#define RANKING_H_INCLUDED

#include <vector>
#include <string>

#include "listaLocal.h"

using namespace std;


void rankingAllProvFA(Nodo *&lista, vector<string> prov, int opc);
Nodo* rankingProvFA(Nodo *&lista, string provincia, int opc);
Nodo* rankingNacFA(Nodo *&lista, int opc);
void rankingRendimento(Nodo *&lista);
Nodo* localesXMatriz(Nodo *&lista);
void ordenMatrizRendimiento(Nodo*& lista, vector<int>& matriz);
float rendimiento(Nodo*& lista, int matriz);
vector<int> listaMatriz(Nodo *&lista);
vector<string> listaProv(Nodo *&lista);
void mostrarRankingRendimiento(Nodo* lista, vector<int>& matriz);

#endif // RANKING_H_INCLUDED
