#ifndef TRANSACCIONES_H
#define TRANSACCIONES_H

struct transaccion {
    char id[5];
    char tipo[10];
    float monto;
};

class Transaccion {
    public:
        static void agregarTransaccion(int);
        static void listarTransacciones();
};

#endif