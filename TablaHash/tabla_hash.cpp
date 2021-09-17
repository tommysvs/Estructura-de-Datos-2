  
#include <iostream>
#include "tabla_hash.h"

using std::cout;

int TablaHash::dispersion(int _llave) {
	return _llave % tamanio;
}

bool TablaHash::existeLlave(int _direccion, int _llave) {
	for (list<int>::iterator it = tabla[_direccion].begin(); it != tabla[_direccion].end(); ++it) {
		if (*it == _llave) // llave ya existe
			return true;
	}

	return false;
}

TablaHash::TablaHash(int _tamanio, int _longitud) : tamanio(_tamanio), longitudLista(_longitud) {
	for (int i = 0; i < tamanio; i++)
		tabla.push_back(list<int>());
}

void TablaHash::insertarLlave(int _llave) {
	int direccion = dispersion(_llave);

	if (tabla[direccion].size() >= longitudLista) {
		cout << "Error: Lista de colisiones se ha agotado!\n";
		return;
	}

	if (!existeLlave(direccion, _llave)) {
		tabla[direccion].push_back(_llave);
		cout << "Llave insertada!\n";
	} else
		cout << "Llave ya existe!";
}

void TablaHash::imprimirTabla() {
	cout << "Tabla Hash: \n";

	for (int i = 0; i < tabla.size(); i++) {
		cout << "[ " << i << " ] -> ";

		for (list<int>::iterator it = tabla[i].begin(); it != tabla[i].end(); ++it)
			cout << *it << " ->";

		cout << "\n";
	}
}