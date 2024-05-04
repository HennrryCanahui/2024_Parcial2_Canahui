#include <iostream>
#include <fstream>
#include <string>
#include <direct.h>

using namespace std;

void crearArchivos(int cantidad);
void Crear_capeta(int cantidad);
void agregarTexto();
void escribirArchivo(int cantidad, string nombreArchivo, string ruta);

int main() {
    int opc;
    cout << "Bienvenido al Programa de Manejo de Archivos" << endl;
    do {
        cout << "[1] Crear Archivos" << endl;
        cout << "[0] Salir" << endl;
        cin >> opc;
        switch (opc) {
            case 1:
                cout << "Opcion seleccionada -> Crear Archivos" << endl;
                cout <<":";
                int cantidad;
                cout << "Ingrese la cantidad de archivos que desea crear" << endl;
                cin >> cantidad;
                Crear_capeta(cantidad);
                crearArchivos(cantidad);
                break;
            default:
                cout << "Opcion incorrecta, vuelva a intentarlo" << endl;
                break;
        }
    } while (opc != 0);
    return 0;
}

void Crear_capeta(int cantidad){
    if ((cantidad % 2) == 0 ){
        mkdir("C:\\Users\\hennr\\OneDrive\\Escritorio\\par\\");
    }
    else{
        mkdir("C:\\Users\\hennr\\OneDrive\\Escritorio\\impar\\");
    }
}

void crearArchivos(int cantidad){
    string nombreArchivo = "file";
    if (cantidad % 2 == 0){
        cout << "Cantidad de Archivos par" << endl;
        escribirArchivo(cantidad, nombreArchivo, "C:\\Users\\hennr\\OneDrive\\Escritorio\\par\\ ");
    }else {
        cout << "Cantidad de Archivos impar" << endl;
        escribirArchivo(cantidad, nombreArchivo, "C:\\Users\\hennr\\OneDrive\\Escritorio\\impar\\ ");
    }
}

void escribirArchivo(int cantidad, string nombreArchivo, string ruta){
    for (int i = 0; i < cantidad; ++i) {
        ofstream file;
        file.open(ruta + nombreArchivo + to_string(i + 1) + ".txt");

        for (int j = 0; j < i+1; ++j) {
            file << "linea de texto" << endl;
        }
        file.close();
    }
    cout << cantidad << " Archivos creados con Exito" << endl;
}
