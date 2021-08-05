#include <iostream>
#include <fstream>
#include <cstring>
#include "transaccion.h"
#include "cuenta.h"

using namespace std;

void Transaccion::agregarTransaccion(int _tipo) {
    fstream file_transacciones("transacciones.bin", ios::out | ios::binary | ios::app);

    if(!file_transacciones) {
        cout << "Error: No se puede abrir el archivo.\n\n";
        return;
    }

    cout << "*** R E A L I Z A R  T R A N S A C C I O N ***\n\n";

    transaccion nueva_transaccion;
    Cuenta _cuenta;
    float _saldo;

    do {
        cout << "Codigo de cuenta: ";
        cin >> nueva_transaccion.id;

        _saldo = _cuenta.cuentaExiste(nueva_transaccion.id);

        if(_saldo == -1) 
            cout << "La cuenta especificada no existe.\n";
    }while(_saldo != -1);

    cout << "Monto: ";
    cin  >> nueva_transaccion.monto;

    if(_tipo == 1) {
        strcpy(nueva_transaccion.tipo, "Deposito");
        _saldo += nueva_transaccion.monto;
    }
    else if (_tipo == 2) {
        strcpy(nueva_transaccion.tipo, "Retiro");
        _saldo -= nueva_transaccion.monto;
    }

    _cuenta.actualizarSaldo(nueva_transaccion.id, _saldo);

    file_transacciones.write(reinterpret_cast<const char*>(&nueva_transaccion), sizeof(transaccion));
    cout << "\n-- Transaccion realizada exitosamente\n\n";

    file_transacciones.close();
}

void Transaccion::listarTransacciones() {
    fstream file_transacciones("transacciones.bin", ios::in | ios::binary);

    if(!file_transacciones) {
        cout << "Error: No se puede abrir el archivo.\n\n";
        return;
    }

    file_transacciones.seekg(0, ios::beg);

    cout << "*** T R A N S A C C I O N E S ***\n\n";

    transaccion actual;

    file_transacciones.read(reinterpret_cast<char*>(&actual), sizeof(transaccion));

    while(!file_transacciones.eof()) {
        cout << "Transaccion { Cuenta: " << actual.id << ", tipo: " << actual.tipo << ", monto: " << actual.monto << " }\n";
        file_transacciones.read(reinterpret_cast<char*>(&actual), sizeof(transaccion));
    }

    cout << "\n";
    file_transacciones.close();
}