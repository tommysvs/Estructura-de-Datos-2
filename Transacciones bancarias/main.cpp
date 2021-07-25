#include <iostream>
#include "cuenta.h"
#include "transaccion.h"

using namespace std;

int main() {
    int op;

    do {
        cout << "1. Crear cuenta" << endl;
        cout << "2. Consultar cuentas" << endl;
        cout << "3. Realizar operacion" << endl;
        cout << "4. Consultar transacciones" << endl;
        cout << "5. Salir" << endl;
        cout << "Opcion > ";
        cin >> op;

        switch(op) {
            case 1:
                Cuenta::agregarCuenta();
                break;
            case 2:
                Cuenta::listarCuentas();
                break;
            case 3:
                Cuenta::realizarOperacion();
                break;
            case 4:
                Transaccion::listarTransacciones();
                break;
            case 5:
                system("exit");
                break;
        }
    }while(op != 5);
}