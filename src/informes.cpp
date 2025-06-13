#include <iostream>
#include <fstream>
#include <cctype>

using namespace std;

void selection();
void creation(bool advanced);

int main() {
    int input_main;

    system("cls");
    system("title Informes v0.2.0 - test build");

    cout << "Informes v0.2.0 - test build" << endl << "--------------------" << endl;
    cout << "1. Hacer informe" << endl << "2. Salir" << endl << "--------------------" << endl << endl;
    cout << "> ";
    cin >> input_main;

    if (input_main == 1) {
        selection();
    } else if (input_main == 2) {
        return 0;
    } else {
        cout << "Opcion invalida" << endl;
        system("pause");
        main();
    }
}

void selection() {
    int input_selection;

    system("cls");

    cout << "Selecciona el tipo de informe" << endl << "--------------------" << endl;
    cout << "1. Informe Basico" << endl << "2. Informe Avanzado" << endl << "3. Volver" << endl << "--------------------" << endl << endl;
    cout << "> ";
    cin >> input_selection;

    if (input_selection == 1) {
        creation(false);
    } else if (input_selection == 2) {
        creation(true);
    } else if (input_selection == 3) {
        main();
    }
}

void creation(bool advanced) {
    int cantidad;
    string tipo, estado, rendimiento, observacion, id, serial;

    system("cls");

    if (advanced) {
        cout << "Informe Avanzado" << endl << "--------------------" << endl << endl;
    } else {
        cout << "Informe Basico" << endl << "--------------------" << endl << endl;
    }

    cout << "Cantidad de dispositivos: ";
    cin >> cantidad;
    cin.ignore();

    if (cantidad < 1) {
        cout << "El informe tiene que ser para al menos 1 dispositivo." << endl;
        system("pause");
        main();
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

        if (advanced) {
            cout << "ID del dispositivo " << i << ": ";
            getline(cin, id);

            cout << "Numero de serie del dispositivo " << i << ": ";
            getline(cin, serial);

            cout << endl;
        }

        cout << "Estado fisico del dispositivo " << i << ": ";
        getline(cin, estado);

        cout << "Rendimiento del dispositivo " << i << ": ";
        getline(cin, rendimiento);

        cout << "Observacion del dispositivo " << i << ": ";
        getline(cin, observacion);

        cout << endl;

        if (advanced) {
            if (!id.empty()) {
                file << "ID: " << id << endl;
            }

            if (!serial.empty()) {
                file << "Numero de serie: " << serial << endl;
            }

            file << "------------" << endl;
        }

        if (!estado.empty()) {
            file << "Estado fisico: " << estado << endl;
        }
        
        if (!rendimiento.empty()) {
            file << "Rendimiento: " << rendimiento << endl;
        }
        
        if (!observacion.empty()) {
            file << observacion << endl;
        }
    }

    file.close();

    system("cls");
    cout << "Informe completado correctamente!" << endl;

    system("pause");
    main();
}