#ifndef EMPLEADOS_H
#define EMPLEADOS_H

#define CANTIDAD 10000
#define SALARIO_MIN 100
#define SALARIO_MAX 2200

#include <iostream>
#include <fstream>
#include <string.h>
#include <chrono>

struct registro {
    int codigo;
    char nombre[20];
    double salario;
    bool estado;
}; 

class Empleados {
    public:
        static void generar_archivo();
        static void busqueda_secuencial(int);
        static void busqueda_binaria(int);
};

#endif