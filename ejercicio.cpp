#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void registrarVenta() {
    ofstream archivo("ventas.txt", ios::app);

    string producto;
    double monto;

    cout << "Ingrese el nombre del producto: ";
    cin.ignore();
    getline(cin, producto);

    cout << "Ingrese el monto de la venta: $";
    cin >> monto;

    if (archivo.is_open()) {
        archivo << "Producto: " << producto
                << " | Monto: $" << monto << endl;

        cout << "Venta registrada correctamente." << endl;
        archivo.close();
    } else {
        cout << "Error al abrir el archivo." << endl;
    }
}

void mostrarVentas() {
    ifstream archivo("ventas.txt");
    string linea;

    if (archivo.is_open()) {
        cout << "===== VENTAS REGISTRADAS =====" << endl;

        while (getline(archivo, linea)) {
            cout << linea << endl;
        }

        archivo.close();
    } else {
        cout << "No hay ventas registradas." << endl;
    }
}

int main() {
    int opcion;

    do {
        cout << "===== MENU DE VENTAS =====" << endl;
        cout << "1. Registrar venta" << endl;
        cout << "2. Mostrar ventas" << endl;
        cout << "3. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                registrarVenta();
                break;

            case 2:
                mostrarVentas();
                break;

            case 3:
                cout << "Saliendo del programa..." << endl;
                break;

            default:
                cout << "Opcion no valida." << endl;
        }

    } while (opcion != 3);

    return 0;
}