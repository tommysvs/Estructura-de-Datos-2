#include "empleados.h"

using namespace std;

void Empleados::generar_archivo() {
    fstream emp_file("empleados.bin", ios::out | ios::binary | ios::app);

    if(!emp_file) {
        cout << "Error: Cannot open file.\n\n";
        return;
    }

    registro nuevo_empleado;

    for(int i = 1; i <= CANTIDAD; i++) {
        nuevo_empleado.codigo = i;

        string nombre = "empleado_" + to_string(nuevo_empleado.codigo);
        strncpy(nuevo_empleado.nombre, nombre.c_str(), sizeof(registro::nombre));

        nuevo_empleado.salario = rand() % (SALARIO_MAX - SALARIO_MIN + 1) + SALARIO_MIN;

        nuevo_empleado.estado = true;

        emp_file.write(reinterpret_cast<const char*>(&nuevo_empleado), sizeof(registro));
    }

    cout << "Archivo creado exitosamente!\n\n";

    emp_file.close();
}

void Empleados::busqueda_secuencial(int codigo) {
    fstream file_emp("empleados.bin", ios::in | ios::binary);

    if(!file_emp) {
        cout << "Error: No se puede abrir el archivo.\n\n";
        return;
    }

    registro actual;
    bool revisar;

    auto inicio = chrono::high_resolution_clock::now();

    file_emp.seekg(0, ios::beg);
    file_emp.read(reinterpret_cast<char*>(&actual), sizeof(registro));

    while(!file_emp.eof()) {
        revisar = false;

        if(actual.codigo == codigo) {
            cout << "Employee { codigo: " << actual.codigo << ", nombre: " << actual.nombre << ", salario: " << actual.salario << ", estado: " << actual.estado << " }" << endl;
            revisar = true;
            file_emp.close();
        }

        file_emp.read(reinterpret_cast<char*>(&actual), sizeof(registro));
    }

    if(revisar == false) {
        cout << "El empleado no existe.\n";
        file_emp.close();
    }
        
    auto final = chrono::high_resolution_clock::now();
    chrono::duration<float> duracion = final - inicio;

    cout << "Tiempo transcurrido: " << duracion.count() << " ms\n\n";
}

void Empleados::busqueda_binaria(int codigo) {
    fstream file_emp("empleados.bin", ios::in | ios::binary);

    if(!file_emp) {
        cout << "Error: No se puede abrir el archivo.\n\n";
        return;
    }

    registro actual;
    int bajo, medio, alto;
    bool revisar;

    bajo = 0;
    alto = CANTIDAD - 1;

    file_emp.seekg(0, ios::beg);
    file_emp.read(reinterpret_cast<char*>(&actual), sizeof(registro));

    auto inicio = chrono::high_resolution_clock::now();

    while(!file_emp.eof()) {
        revisar = false;
        medio = (bajo + alto) / 2;

        file_emp.seekg(medio * sizeof(registro), ios::beg);
        file_emp.read(reinterpret_cast<char*>(&actual), sizeof(registro));

        if(actual.codigo == codigo) {
            cout << "Empleado { codigo: " << actual.codigo << ", nombre: " << actual.nombre << ", salario: " << actual.salario << ", estado: " << actual.estado << " }" << endl;
            revisar = true;
            break;
            file_emp.close();
        } else if(codigo > actual.codigo) {
            bajo = medio + 1;
        } else if(codigo < actual.codigo) {
            alto = medio - 1;
        }
    }

    if(revisar == false) {
        cout << "El empleado no existe.\n";
        file_emp.close();
    }

    auto final = chrono::high_resolution_clock::now();
    chrono::duration<float> duracion = final - inicio;

    cout << "Tiempo transcurrido: " << duracion.count() << " ms\n\n";
}