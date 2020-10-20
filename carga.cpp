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


vector<string> cargaArchivo(){ //Con este método cargamos los nombres de los archivos de la carpeta datos en un vector
    DIR * carpeta;                                   //Puntero para manejar directorios /Trae todos los directorios que hay en donde se encuentra el proyecto
    struct dirent * archivo;                         //Es una estructura de elementos que se va a usar para listar los archivos /Se utiliza para acceder a la información de los elementos
    string carp = "datos/";                          //Ruta para la carga de archivos
    string arch;                                     //Variable para almacenar el nombre de cada archivo
    vector <string> archivos;                        //Todos los archivos van a  ser almacenados  en este vector

    if (carpeta = opendir(carp.c_str()) ){       //Se comprieba si se puede abrir la carpeta datos
        while(archivo = readdir(carpeta)){       //Mientras haya un archivo para leer, los recorremos uno a uno
            arch = archivo->d_name;              //Guardamos el nombre del archivo en la variable
            if(arch !="." && arch !=".."){
                archivos.push_back(arch);        //Se guarda el nombre del archivo en el vector
            }
        }
    } else{
        cout << "No se puedo abrir la carpeta "+carp << endl;
        exit(1);                                               //  <= Ver si está bien esta salida
    }

    closedir(carpeta);
    return archivos;
}
// Guias del vector <string>
// https://stackoverflow.com/questions/17938166/displaying-a-vector-of-strings-in-c
// https://stackoverflow.com/questions/1088622/how-do-i-create-an-array-of-strings-in-c

// Guia de directorios
// https://www.youtube.com/watch?v=XBqtPWvjlQI

Nodo* buildListLocales(vector<string> arch){ //Con este leemos los datos de los archivos del vector que definimos antes y creamos los locales
    Nodo *nodo = NULL;

    for(int i=0;i<arch.size();i++){            //Recorremos todos los archivos

            string datos = ("datos/"+arch[i]); //Guardamos la direccion de cada archivo en un string
            ifstream archivo;                  //Para el manejo de archivos
            archivo.open(datos, ios::in);      //Abro archivo para lectura
            if(archivo.fail()){                //En caso de que no se pueda
                cout<< "No se pudo abrir el archivo: "+datos << endl ;
                exit(1);
            }
            string texto;
            vector<string> resultados;
            while(!archivo.eof()){             //Mientras no llegue al fin del archivo
                getline(archivo, texto);       //Para leer el archivo una linea a la vez y guardar esa linea en una variable
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
vector<string> cortar(string str ) {    //Se usa para separar las variables de cada linea
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
void reemplazo(string &tex, char a, char b){    //Para convertir los “,” de un string en “.” y así poder guardar los float
    for(int i=0;i<tex.size();i++){                          // reemplazo un caracter del string a por b
        if (tex[i]== a) tex[i]=b;
    }
}
bool validarLinea(string tex){  //Sirve para saber si un linea esta mal escrita
    bool flag = false;
    int j=0;
    for(int i=0;i<tex.size();i++){                          // este for cuenta los '-' y valida si hay 2 seguidos
        if (tex[i]== '-') j++;
        if (tex[i]== '-' && tex[i+1] == '-') flag=true;
    }
    if (j!=6) flag = true;
    return flag;
}
