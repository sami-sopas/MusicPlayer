#include"Cancion.h"
#include<string>
#include<iostream>

///SETTETS
void Cancion::setId(const int& i)
{
    id = i;
}

void Cancion::setNombre(const string& n)
{
    nombre = n;
}

void Cancion::setAlbum(const string& a)
{
    album = a;
}

void Cancion::setArtista(const string& a)
{
    artista = a;
}

void Cancion::setGenero(const string& g)
{
    genero = g;
}

/*void Cancion::setDireccion(char *d)
{
    direccion = d;
}*/

void Cancion::setDireccion(const string& d)
{
    direccion = d;
}
void Cancion::setSegundos(const string& s)
{
    segundos = s;
}

void Cancion::setMinutos(const string& m)
{
    minutos = m;
}


///GETTETS
int Cancion::getId()
{
    return id;
}

string Cancion::getNombre()
{
    return nombre;
}

string Cancion::getAlbum()
{
    return album;
}

string Cancion::getArtista()
{
    return artista;
}

string Cancion::getGenero()
{
    return genero;
}

/*char* Cancion::getDireccion()
{
    return direccion;
}*/

string Cancion::getDireccion()
{
    return direccion;
}

string Cancion::getMinutos()
{
    return minutos;
}

string Cancion::getSegundos()
{
    return segundos;
}

string Cancion::toString()
{

    string impresion;
   // char myId[10];
    //sprintf_s(myId,"%i",id);

    //impresion = "\nId: ";
    //impresion += id;
    impresion += "\nNombre: ";
    impresion += nombre;
    impresion += "\nAlbum: ";
    impresion += album;
    impresion += "\nArtista: ";
    impresion += artista;
    impresion += "\nGenero: ";
    impresion += genero;

    return impresion;
}
