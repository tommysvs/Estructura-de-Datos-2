#include <iostream>
#include "empleados.h"

int main() {
    int opcion, codigo;

    do {
        std::cout << "1. Generar archivo" << std::endl;
        std::cout << "2. Busqueda secuencial" << std::endl;
        std::cout << "3. Binary search" << std::endl;
        std::cout << "4. Salir" << std::endl;

        std::cout << "> ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                Empleados::generar_archivo();
                break;
            case 2:
                std::cout << "\nIngresa el codigo: ";
                std::cin >> codigo;

                Empleados::busqueda_secuencial(codigo);
                break;
            case 3:
                std::cout << "\nIngresa el codigo: ";
                std::cin >> codigo;

                Empleados::busqueda_binaria(codigo);
                break;
            case 4:
                exit(0);
                break;
            default:
                std::cout << "Opcion no valida." << std::endl;
                break;
        }
    } while(opcion != 4);
}