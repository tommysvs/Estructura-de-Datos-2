#ifndef TABLA_HASH_H
#define TABLA_HASH_H

#include <vector>
#include <list>

using namespace std;

class TablaHash {
    private:
        int tamanio;
        int longitudLista;
        vector<list<int>> tabla;
        int dispersion(int);
        bool existeLlave(int, int);
    public:
        TablaHash(int, int);
        
        void insertarLlave(int);
        int buscarLlave(int);
        bool eliminarLlave(int);

        void imprimirTabla();
};

#endif