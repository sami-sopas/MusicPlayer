#ifndef LISTACIRCULAR_H_INCLUDED
#define LISTACIRCULAR_H_INCLUDED
#include<iostream>
#include"Cancion.h"

#define GRISBAJITO "\x1b[1;37m"
#define REGRESA "\x1b[0m"

using namespace std;
class ListaCircular{
    private:
        class Nodo{
            public:
                Cancion mySong;
                Nodo *siguiente;
                Nodo *anterior;
        };
    Nodo *encabezado;

    public:
        ListaCircular();
        ~ListaCircular();
        void insertarPrimero(Cancion);
        void insertarUltimo(Cancion);
        bool estaVacia();
        void imprimirLista(int,Cancion); //Imprime todas las canciones que hay en la interfaz principal
        void imprimirCancionActual(int); //Imprime la cancion actual en la que esta la flechita en la interfaz principal
        void imprimirCancionActualReproductor(int); //Para imprimir la cancion actual en una posicion diferente para el reproductor
        void reproducirCancion(int);
        void temporizadorCancion(int,int);
        int travel(); //Elementos actuales
        void eliminar(const int&);
        Cancion buscarPos(const int&);
        void modificar(const int&,Cancion);
};



#endif // LISTACIRCULAR_H_INCLUDED
