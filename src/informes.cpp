#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;

int main() {
    int cantidad;
    string tipo, estado, rendimiento, observacion;

    system("title Informes v0.1.1");

    cout << "Cantidad de dispositivos: ";
    cin >> cantidad;
    cin.ignore();

    if (cantidad < 1) {
        cout << "El informe tiene que ser para al menos 1 dispositivo." << endl;
        system("pause");
        return 1;
    } else if (cantidad > 1) {
        cout << "Tipo de los dispositivos: ";
        cin >> tipo;
        cin.ignore(100, '\n');

        tipo[0] = toupper(tipo[0]);
    } else {
        cout << "Tipo del dispositivo: ";
        cin >> tipo;
        cin.ignore(100, '\n');

        tipo[0] = toupper(tipo[0]);
    }

    cout << endl;
    
    ofstream file("Informe" + tipo + ".txt");
    file << "Informe para " << cantidad << " " << tipo << endl << "-----------------------" << endl;

    for (int i = 1; i <= cantidad; i++) {
        file << endl << tipo << " " << i << endl << "------------" << endl;

        cout << "Estado fisico del dispositivo " << i << ": ";
        getline(cin, estado);

        cout << "Rendimiento del dispositivo " << i << ": ";
        getline(cin, rendimiento);

        cout << "Observacion del dispositivo " << i << ": ";
        getline(cin, observacion);

        cout << endl;

        if (!estado.empty()) {
            file << "Estado fisico del dispositivo: " << estado << endl;
        }
        
        if (!rendimiento.empty()) {
            file << "Rendimiento dispositivo: " << rendimiento << endl;
        }
        
        if (!observacion.empty()) {
            file << "Observacion: " << observacion << endl;
        }
    }

    file.close();
    cout << "Informe completado correctamente!" << endl;
    system("pause");
    return 0;
}