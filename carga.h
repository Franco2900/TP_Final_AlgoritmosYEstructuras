#ifndef CARGA_H_INCLUDED
#define CARGA_H_INCLUDED

#include <vector>
#include <string>

#include "listaLocal.h"
using namespace std;

vector<string> cargaArchivo();
Nodo* buildListLocales(vector<string> lista);
bool validarLinea(string tex);
vector<string> cortar(string str);
void reemplazo(string &tex, char a, char b);


#endif // CARGA_H_INCLUDED
