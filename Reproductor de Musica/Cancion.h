#ifndef CANCION_H_INCLUDED
#define CANCION_H_INCLUDED

#include<string>
using namespace std;

class Cancion{
    private: //Atributos
        int id;
        string nombre;
        string album;
        string artista;
        string genero;
        //char *direccion;
        string direccion;
        string segundos; //Al leer del txt daba promeblas asi que todo se convirtio en string y mejor se convirtia despues a int
        string minutos;

    public: //Metodos
        void setId(const int&);
        void setNombre(const string&);
        void setAlbum(const string&);
        void setArtista(const string&);
        void setGenero(const string&);
        //void setDireccion(char*);
        void setDireccion(const string&);
        void setSegundos(const string&);
        void setMinutos(const string&);

        int getId();
        string getNombre();
        string getAlbum();
        string getArtista();
        string getGenero();
        //char* getDireccion();
        string getDireccion();
        string getSegundos();
        string getMinutos();

        string toString();
};

#endif // CANCION_H_INCLUDED
