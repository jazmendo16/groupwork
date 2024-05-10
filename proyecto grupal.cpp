#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

// Estructura para almacenar una entrada de traducci�n
struct Traduccion {
    string palabra;
    string traduccion;
    string funcionalidad;
};

// Funci�n para cargar las traducciones desde el archivo
Traduccion* cargarTraducciones(int& cantidadTraducciones) {
    ifstream archivo("traducciones.txt");
    if (!archivo) {
        cerr << "No se pudo abrir el archivo de traducciones." << endl;
        cantidadTraducciones = 0;
        return NULL;
    }
    cantidadTraducciones = 0;
    string palabra, traduccion, funcionalidad;
    while (archivo >> palabra >> traduccion) {
        getline(archivo, funcionalidad);
        cantidadTraducciones++;
    }
    archivo.close();

    Traduccion* traducciones = new Traduccion[cantidadTraducciones];
    ifstream archivo2("traducciones.txt");
    for (int i = 0; i < cantidadTraducciones; ++i) {
        archivo2 >> traducciones[i].palabra >> traducciones[i].traduccion;
        getline(archivo2, traducciones[i].funcionalidad);
    }
    archivo2.close();

    return traducciones;
}

// Funci�n para guardar las traducciones en el archivo
void guardarTraducciones(const Traduccion* traducciones, int cantidadTraducciones) {
    ofstream archivo("traducciones.txt");
    if (!archivo) {
        cerr << "No se pudo abrir el archivo de traducciones." << endl;
        return;
    }
    for (int i = 0; i < cantidadTraducciones; ++i) {
        archivo << traducciones[i].palabra << " " << traducciones[i].traduccion << " " << traducciones[i].funcionalidad << endl;
    }
    archivo.close();
}

// Funci�n para a�adir una nueva traducci�n
void crearTraduccion(Traduccion*& traducciones, int& cantidadTraducciones) {
    Traduccion nueva;
    cout << "Ingrese la palabra en ingl�s: ";
    cin >> nueva.palabra;
    cout << "Ingrese la traducci�n al espa�ol: ";
    
