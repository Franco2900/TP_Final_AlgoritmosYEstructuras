#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <string>

#include "listaLocal.h"

using namespace std;


void menu();
void menuPrincipal(Nodo*& listaLocales, string franquicia);
void menuRankingFacYArtVend(Nodo*& listaLocales, int opcion);

#endif // MENU_H_INCLUDED
