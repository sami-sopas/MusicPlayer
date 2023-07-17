#ifndef ANIMACIONES_H_INCLUDED
#define ANIMACIONES_H_INCLUDED
#include"ListaCircular.h"
#include"Cancion.h"
#include"windows.h"


void titulo(); //Titulo de playlist con colores que va en el displayMenu
void interfazPrincipal(); //Se manda a llamar en el metodo de insertar en la funcion de lista
void interfazPrincipalVacia();
void interfazPrincipal_AgregandoCancion(); //Interfaz para cuando se esta agregando una nueva cancion
void interfazPrincipal_ModificandoCancion(); //Interfaz para cuando se esta editando una cancion existente
void agregandoCancion(); //Animacion cuando se termina de agregar una cancion
void editandoCancion(); //Animacion cuando se termina de editar una cancion
void piano(); //Dibujo que va dentro de la interfaz vacia
void violin(); //Dibujo que va dentro de la interfaz cuando se agrega una cancion (interfazPrincipalCancion)
void notas(); //Dibujo que va dentro de la interfaz cuando se modifica una cancion
void reproductor(); //Intento de reproductor de musica
void cuadroNotas(); //Dibujo que sale donde esta el reproductor para representar la cancion
int generarColor1(); //Funcion que retorna un numero para poder tener colores aleatorios para las notas musicales
int generarColor2();
int generarColor3(); //Tuve que crear 3 porque me aparecia el mismo color xd
void fechaHora(); //Funcion para mostrar la fecha y hora actual (Se manda a llamar en reproductor() )


void gotoxy(int x, int y);


#endif // ANIMACIONES_H_INCLUDED
