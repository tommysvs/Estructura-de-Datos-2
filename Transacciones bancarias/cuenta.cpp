#include <iostream>
#include <fstream>
#include "cuenta.h"
#include "transaccion.h"

using namespace std;

void Cuenta::agregarCuenta() {
    fstream file_cuentas("cuentas.bin", ios::out | ios::binary | ios::app);

    if(!file_cuentas) {
        cout << "Error: No se puede abrir el archivo.\n\n";
        return;
    }

    cout << "*** C R E A R  C U E N T A ***\n\n";

    cuenta nueva_cuenta;

    cout << "Codigo de cuenta: ";
    cin >> nueva_cuenta.id;

    nueva_cuenta.saldo = 0;

    file_cuentas.write(reinterpret_cast<const char*>(&nueva_cuenta), sizeof(cuenta));
    cout << "\n-- Cuenta creada exitosamente\n\n";

    file_cuentas.close();
}

void Cuenta::listarCuentas() {
     fstream file_cuentas("cuentas.bin", ios::in | ios::binary);

    if(!file_cuentas) {
        cout << "Error: No se puede abrir el archivo.\n\n";
        return;
    }

    file_cuentas.seekg(0, ios::beg);

    cout << "*** C U E N T A S ***\n\n";

    cuenta actual;

    file_cuentas.read(reinterpret_cast<char*>(&actual), sizeof(cuenta));

    while(!file_cuentas.eof()) {
        cout << "Cuenta { Codigo: " << actual.id << ", saldo: " << actual.saldo << " }\n";
        file_cuentas.read(reinterpret_cast<char*>(&actual), sizeof(cuenta));
    }

    cout << "\n";
    file_cuentas.close();
}

float Cuenta::cuentaExiste(const char* _id) {
      fstream file_cuentas("cuentas.bin", ios::in | ios::binary);

    if(!file_cuentas)
        cout << "Error: No se puede abrir el archivo.\n\n";

    file_cuentas.seekg(0, ios::beg);

    cuenta actual;

    file_cuentas.read(reinterpret_cast<char*>(&actual), sizeof(cuenta));

    while(!file_cuentas.eof()) {
        if(actual.id == _id) {
            file_cuentas.close();
            return actual.saldo;
        }

        file_cuentas.read(reinterpret_cast<char*>(&actual), sizeof(cuenta));
    }

    file_cuentas.close();
    return -1;
}

void Cuenta::realizarOperacion() {
    int op;

    cout << "*** OPERACIONES ***\n\n";
    cout << "Ingrese el tipo de operacion que desea realizar" << endl;
    cout << "1. Deposito" << endl;
    cout << "2. Retiro" << endl;
    cout << "Operacion > ";
    cin >> op;

    if(op == 1)
        Transaccion::agregarTransaccion(1);
    else
        Transaccion::agregarTransaccion(2);
}

void Cuenta::actualizarSaldo(const char* _id, float _saldo) {
    fstream file_cuentas("cuentas.bin", ios::out | ios::in | ios::binary);

    if(!file_cuentas) {
        cout << "Error: No se puede abrir el archivo.\n\n";
        return;
    }

    file_cuentas.seekg(0, ios::beg);

    cuenta actual;
    long act_pos = 0;

    file_cuentas.read(reinterpret_cast<char*>(&actual), sizeof(cuenta));

    while(!file_cuentas.eof()) {
        if(actual.id == _id) {
            actual.saldo = _saldo;

            file_cuentas.seekp(act_pos, ios::beg);
            file_cuentas.write(reinterpret_cast<const char*>(&actual), sizeof(cuenta));

            file_cuentas.close();
            cout << "-- Cuenta actualizada exitosamente\n";

            return;
        }

        act_pos = file_cuentas.tellg();
        file_cuentas.read(reinterpret_cast<char*>(&actual), sizeof(cuenta));
    }

    file_cuentas.close();
}