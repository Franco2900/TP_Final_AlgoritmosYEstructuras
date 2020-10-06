#include <iostream>
#include <cstdio>
#include <dirent.h>
#include <fstream>
#include <string>
#include <vector>


#include "carga.h"
#include "listaLocal.h"
#include "local.h"

using namespace std;


vector<string> cargaArchivo(){
    DIR * carpeta;
    struct dirent * elemento;                               //es una estructura de elementos que se va a usar para listar los archivos
    string carp = "datos/";                                 //ruta para la carga de archivos
    string arch;                                            // variable para almacenar el nombre de cada archivo
    vector <string> archivos;                               // todos los archivos vana  ser almacenados  en este vector
    if (carpeta = opendir(carp.c_str())){                   // se comprieba si se puede abrir la carpeta
            while(elemento = readdir(carpeta)){             //mientras haya un archivo para leer
                arch = elemento->d_name;                    // guardamos el nombre del archivo en la variable
                if(arch !="." && arch !=".."){
                    archivos.push_back(arch);               //se guarda el nombre del archivo en el vector
                }
            }
    } else{
        cout << "No se puedo abrir la carpeta "+carp << endl;
        exit(1);                                               //  <= Ver si está bien esta salida
    }
    closedir(carpeta);
   return archivos;
}
Nodo* buildListLocales(vector<string> arch){
    Nodo *nodo = NULL;

    for(int i=0;i<arch.size();i++){

            string datos = ("datos/"+arch[i]);
            ifstream archivo;
            archivo.open(datos, ios::in);
            if(archivo.fail()){
                cout<< "No se pudo abrir el archivo: "+datos << endl ;
                exit(1);
            }
            string texto;
            vector<string> resultados;
            while(!archivo.eof()){
                getline(archivo, texto);
                if (validarLinea(texto)){
                    cout << "Existe algun dato erroneo en el archivo: "+ datos << endl;
                    cout << "No se cargara la siguiente linea: "+ texto << endl;
                    cout << "\n" <<endl;
                }
                else{
                    resultados = cortar(texto);
                    reemplazo(resultados[3], ',', '.');
                    reemplazo(resultados[4], ',', '.');
                    Local *nuevo = new Local(stoi(resultados[0]),resultados[1] ,stoi(resultados[2]), stof(resultados[3]), stof(resultados[4]), stoi(resultados[5]));
                    insertarLista(nodo, nuevo);
                }
            }
            archivo.close();
    }
    return nodo;
}
vector<string> cortar(string str ) {
    char pattern = '-';                                     //delimitador
    int posInit = 0;                                        //posicion iniicial del recorrido
    int posFound = 0;                                       //posicion final del recorrido
    string splitted;                                        // variable para almacenar el tramo de string
    vector<string> resultados;                              // vector para almacenar todos los recortes
    while(posFound >= 0){
        posFound = str.find(pattern, posInit);
        splitted = str.substr(posInit, posFound - posInit); //concatena desde la posicion inicial hasta la posicion final
        posInit = posFound + 1;
        resultados.push_back(splitted);                     //inserta el string al final del vector
    }
    return resultados;
}
void reemplazo(string &tex, char a, char b){
    for(int i=0;i<tex.size();i++){                          // reemplazo un caracter del string a por b
        if (tex[i]== a) tex[i]=b;
    }
}
bool validarLinea(string tex){
    bool flag = false;
    int j=0;
    for(int i=0;i<tex.size();i++){                          // este for cuenta los '-' y valida si hay 2 seguidos
        if (tex[i]== '-') j++;
        if (tex[i]== '-' && tex[i+1] == '-') flag=true;
    }
    if (j!=6) flag = true;
    return flag;
}
