#include <iostream>
#include "tabla_hash.h"

using std::cout;

int main() {
    TablaHash th(8, 6);

	th.insertarLlave(22);
	th.insertarLlave(38);
	th.insertarLlave(12);
	th.insertarLlave(7);
	th.insertarLlave(59);
	th.insertarLlave(31);

	th.imprimirTabla();
}