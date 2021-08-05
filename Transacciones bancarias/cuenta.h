#ifndef CUENTA_H
#define CUENTA_H

struct cuenta {
    char id[5];
    float saldo;
};

class Cuenta {
    public:
        static void agregarCuenta();
        static void listarCuentas();
        static void realizarOperacion();
        static void actualizarSaldo(const char*, float);
        static float cuentaExiste(const char*);
};

#endif