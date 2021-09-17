#include <iostream>
#include "tabla_hash.h"

using std::cout;

int main() {
    TablaHash th(8, 6);

	th.insertarLlave(56);
	th.insertarLlave(16);
	th.insertarLlave(89);
	th.insertarLlave(3);
	th.insertarLlave(17);
	th.insertarLlave(59);
	th.insertarLlave(13);
    th.imprimirTabla();

    th.eliminarLlave(17);
    th.imprimirTabla();

    int pos = th.buscarLlave(13);
    if(pos != -1)
        cout << "Llave 13 esta en la posicion [" << pos << "]" << endl;
    else
        cout << "Llave no encontrada" << endl;
}