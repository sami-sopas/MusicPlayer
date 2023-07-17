//Liberias del sistema----
#include<iostream>
#include<conio.h> //Para el getch y el khbit (terminar un ciclo apretando una tecla)
#include"windows.h" //Para los gotoxys y cambiar color a la consola
#include<chrono> //Para el cronometro
#include<fstream> //Para leer y guardar archivos
#include<vector>
#include<ctime> //Para fecha/hora (tambien se uso <vector> para esto
#include"stdlib.h" //Para cambiarle el titulo al proyecto de consola
//Liberias locales--------
#include"Cancion.h"
#include"ListaCircular.h"
#include"Animaciones.h"

/*
Querido viajero:

Si estas leyendo esto, eres de los afortunados en tener mi codigo.

Cuando escribi este codigo, solo Dios y yo sabiamos como funcionaba.
Ahora, solo Dios lo sabe!!

Asi que si estas tratando de entender este codigo y fracasas (seguramente)
No te preocupes! Es normal, te deseo suerte en esta pequeña travesia :)
*/

using namespace std;

///CREACION DE OBJETO Y LISTA
Cancion cancion;
ListaCircular *lista = new ListaCircular();

///VARIABLES PARA SETEAR VALORES
string nombre;
string album;
string artista;
string genero;
//char direccionCancion[500];
string direccion;
string minutos;
string segundos;

///VARIABLES GENERALES
int opc = 0;
int puntero = 1; //Toma el rol como si fuera id
fstream file; //De donde se leera

///PROTOTIPOS DE FUNCIONES
void displayMenu(); //Menu principal
void insertarDatos(); //Case 1
void editarDatos(); //Case 5
void llenarLista(); //Case 6
void interfazReproductor(); //Case 9

int main()
{
    system("Title Spotify by sami");

    /*INSTRUCCIONES PARA REPRODUCIR MUSICA:
    1. En CodeBlocks ir a Settings
    2. Click en Compiler
    3. Abrir pestaña de linker settings
    4. En la parte the other linker options escribir "-lwinmm" y dar a ok
    5. Listo! No olvidar cambiar las direcciones en donde se encuentra la musica
    */

    displayMenu();
    return 0;
}

void displayMenu(){

    do{
        system("cls");
        titulo();
        gotoxy(7,6); cout << "1.INGRESAR CANCION" << endl;
        gotoxy(7,8); cout << "2.ANTERIOR" << endl;
        gotoxy(7,10); cout << "3.SIGUIENTE" << endl;
        gotoxy(7,12); cout << "4.ELIMINAR CANCION" << endl;
        gotoxy(7,14); cout << "5.EDITAR CANCION" << endl;
        gotoxy(7,16); cout << "6.LLENAR LISTA" << endl;
        gotoxy(7,18); cout << "7.REPRODUCIR CANCION" << endl;
        gotoxy(7,20); cout << "8.PAUSAR CANCION" << endl;
        gotoxy(7,22); cout << "9.SPOTIFY" << endl;
        gotoxy(7,24); cout << "10.SALIR" << endl;
        lista->imprimirLista(puntero,cancion); //para que siempre se este ejecutando la lista
        lista->imprimirCancionActual(puntero); //para que siempre se muestre la cancion actual

        gotoxy(7,26); cout << "TU OPCION: ", cin >> opc;

        switch(opc){
            case 1:{ ///INSERCION DE DATOS
                insertarDatos();
            break;
            }

            case 2:{ ///ANTERIOR

                /*Primero se reduce el puntero. si al reducir este es menor que 1. se iguala a travel
                (la posicion del ultimo elemento) si no pues se solo se reduce en uno*/

                puntero--;
                if(puntero < 1){
                    puntero = lista->travel();
                }

                /* otra manera de hacerlo
                if(puntero > 1){
                        puntero = puntero - 1;
                }else{
                    puntero = lista->travel();
                }*/

            break;
            }
            case 3:{ ///SIGUIENTE

                /*Primero se aumenta el muntero. si este es mayor a la cantidad de elementos actuales de la lista (travel)
                se iguala al primero. */
                puntero++;
                if(puntero > lista->travel()){
                    puntero = 1;
                }

                /* otra manera de hacerlo
                if(puntero < lista->travel()){
                    puntero = puntero + 1;

                }else{
                    puntero = 1;
                }*/

            break;
            }

            case 4:{ ///ELIMINAR CANCION

                if(!lista->estaVacia()){
                lista->eliminar(puntero);
                puntero = 1;
                }

            break;
            }

            case 5:{ ///EDITAR CANCION
                editarDatos();
                }
            break;

            case 6:{ ///LLenar lista
                llenarLista();
            break;
            }

            case 7:{ ///Reproducir music
                if(!lista->estaVacia()){
                    lista->reproducirCancion(puntero);
                }
            break;
            }

            case 8:{ ///Quitar cancion
                PlaySound(NULL,NULL,0);
            break;

            case 9:{///Interfaz de reproductor tipo spotifais
                interfazReproductor();
            break;
            }
        }
    }
    }while(opc!=10);

}

///FUNCIONES///////////////////////////////////////////////////////////////////////////////////////////////////

///CASE 1 INSERCION DE DATOS DESDE CONSOLA Y GUARDANDO EN TXT
void insertarDatos(){

        file.open("Canciones.txt",ios::app); //Abrimos el archivo

        interfazPrincipal_AgregandoCancion();

        cancion.setId(lista->travel()+1);
        gotoxy(80,7); cout << "ID: " << cancion.getId() << endl;

        gotoxy(34,7); cout << "INGRESE NOMBRE: "; cin.sync(); getline(cin,nombre);
                /*cout << nombre << endl;
                cin.sync();
                getline(cin,auxiliar); es lo mismo*/
        cancion.setNombre(nombre); //Seteando nombre

        file << nombre << "\n"; //Guardando el nombre en el archivo con un salto de linea

        gotoxy(34,10); cout << "INGRESE ARTISTA: "; getline(cin,artista);
        cancion.setArtista(artista); //Seteando artista

        file << artista << "\n";

        gotoxy(34,13); cout << "INGRESE ALBUM: "; getline(cin,album);
        cancion.setAlbum(album); //Seteando album

        file << album << "\n";

        gotoxy(34,16); cout << "INGRESE GENERO: "; getline(cin,genero);
        cancion.setGenero(genero); //Seteando genero

        file << genero << "\n";

        gotoxy(34,19); cout << "INGRESE LA DIRECCION: "; getline(cin,direccion);
        cancion.setDireccion(direccion);

        file << direccion << "\n";

        gotoxy(80,10); cout << "INGRESE DURACION: ";

        gotoxy(80,13); cout << "MINUTOS: "; getline(cin,minutos);
        cancion.setMinutos(minutos);

        file << minutos << "\n";

        /*//Validacion para que agreguen solo numeros entre 0 y 60
        if(minutos >= 0 and minutos < 61){
            cancion.setMinutos(minutos);
            file << minutos << "\n";
        }else{
            gotoxy(80,16); cout << "ERROR. INGRESE NUMERO VALIDO";
            getch();
            return menu();
        }*/

        gotoxy(80,16); cout << "SEGUNDOS: "; getline(cin,segundos);
        cancion.setSegundos(segundos);

        file << segundos << "\n";

        /*if(segundos > 0 and segundos < 61){
            cancion.setSegundos(segundos);
            file << segundos << "\n";
        }else{
            gotoxy(80,17); cout << "ERROR. INGRESE NUMERO VALIDO";
            getch();
            return menu();
        }*/

        lista->insertarUltimo(cancion); //Insertando todo lo anterior en la lista

        agregandoCancion(); //Animacion que sale cuando se termina de agregar una cancion
        getch();

        file.close(); //Cerramos el archivo*/
}

///CASE 5 EDICION DE DATOS
void editarDatos(){
        if(!lista->estaVacia()){

        interfazPrincipal_ModificandoCancion(); //Interfaz que aparecera ahora al estar modificando

        gotoxy(80,7); cout << "ID: " << cancion.getId() << endl;

        gotoxy(34,7); cout << "INGRESE NOMBRE: "; cin.sync(); getline(cin,nombre);
                /*cout << nombre << endl;
                cin.sync();
                getline(cin,auxiliar); es lo mismo*/
        cancion.setNombre(nombre); //Seteando nombre

        gotoxy(34,10); cout << "INGRESE ARTISTA: "; getline(cin,artista);
        cancion.setArtista(artista); //Seteando artista

        gotoxy(34,13); cout << "INGRESE ALBUM: "; getline(cin,album);
        cancion.setAlbum(album); //Seteando album

        gotoxy(34,16); cout << "INGRESE GENERO: "; getline(cin,genero);
        cancion.setGenero(genero); //Seteando genero

        gotoxy(34,19); cout << "INGRESE LA DIRECCION: "; getline(cin,direccion);
        cancion.setDireccion(direccion);

        gotoxy(80,10); cout << "INGRESE DURACION: ";

        gotoxy(80,13); cout << "MINUTOS: "; getline(cin,minutos);
        cancion.setMinutos(minutos);
        /*//Validacion para que agreguen solo numeros entre 0 y 60
        if(minutos >= 0 and minutos < 61){
            cancion.setMinutos(minutos);
            file << minutos << "\n";
        }else{
            gotoxy(80,16); cout << "ERROR. INGRESE NUMERO VALIDO";
            getch();
            return menu();
        }*/

        gotoxy(80,16); cout << "SEGUNDOS: "; getline(cin,segundos);
        cancion.setSegundos(segundos);
        /*if(segundos > 0 and segundos < 61){
            cancion.setSegundos(segundos);
            file << segundos << "\n";
        }else{
            gotoxy(80,17); cout << "ERROR. INGRESE NUMERO VALIDO";
            getch();
            return menu();
        }*/

        lista->modificar(puntero,cancion); //Modificando todo lo anterior en la lista dependiendo de donde se encuente el puntero

        editandoCancion(); //Animacion que sale cuando se termina de modificar una cancion
        getch();
        }


}

///CASE 6 LLENAR LISTA A PARTIR DEL TXT
void llenarLista(){

        file.open("Canciones.txt",ios::in); //Abre el archivo para lectura

        if(file.fail()){
            cout << "Error al abrir el archivo";
        }else{
            while(!file.eof()){ //Se recorre todo el txt hasta el final y se lee lo que tiene en cada renglon

                getline(file,nombre); //Para agarrar solo una linea del archivo (tambien sirve con getline(file,auxiliar);)
                cancion.setNombre(nombre);

                getline(file,artista); //Agarra ahora la siguiente linea (donde se encuentra el artista)
                cancion.setArtista(artista);

                getline(file,album);
                cancion.setAlbum(album);

                getline(file,genero);
                cancion.setGenero(genero);

                /*file >> direccionCancion;
                cancion.setDireccion(direccionCancion);*/

                getline(file,direccion);
                cancion.setDireccion(direccion);

                getline(file,minutos);
                cancion.setMinutos(minutos);

                getline(file,segundos);
                cancion.setSegundos(segundos);

                lista->insertarUltimo(cancion); //Se inserta todo lo anterior y se repite el ciclo
            }
            lista->eliminar(lista->travel()); //Por alguna razon se ponia otro elemento al final. asi que lo elimino aqui

        }

        file.close(); //Se cierra el archivo

}

///CASE 9 INTERFAZ TIPO SPOTIFY
void interfazReproductor(){

    int op;
    do{
    //system("cls");
    reproductor(); //Pura interfaz
    lista->reproducirCancion(puntero);
    lista->imprimirCancionActualReproductor(puntero);

    gotoxy(105,26); cin >> op;

    switch(op){
        case 1:{ //Atras
                if(puntero > 1){
                        puntero = puntero - 1;
                }else{
                    puntero = lista->travel();
                }
                lista->reproducirCancion(puntero);   // ponerlo asi en el reproductor

            break;
        }

        case 2:{ //Quitar cancion (pausar no es posible)

            PlaySound(NULL,NULL,0);
            break;
        }

        case 3:{ //Siguiente
                if(puntero < lista->travel()){
                    puntero = puntero + 1;
                }else{
                    puntero = 1;
                }
                lista->reproducirCancion(puntero);
            break;
        }
    }
    }while(op!=4); //Regresar al menu principal

}
/*
void temporizadorCancion(int m,int s){
        int minutos = 0;
        int segundos = 0;

        do{
            segundos++;

            if(segundos == 60){
                segundos = 0;
                minutos++;
                if(minutos == 60){
                    minutos = 0;
                }
            }
            //system("cls");
            gotoxy(1,1); printf("[ %.2d:%.2d ]",minutos,segundos);
            Sleep(1000);

        }while(minutos != m || segundos != s);
}
*/
///ANTIGUO METODO PARA REPRODUCIR MUSICA
/*
void reproducirMusica(int puntero){
    //Variables para el cronometro
    //int segundos = 0;
    //int minutos = 0;

    switch(puntero){
        case 1:{
            //Para reproducir
            char mencho[] = "C:/Users/ramir/OneDrive/Escritorio/Proyecto_Lista_Reproduccion/canciones/mencho.wav";
            PlaySound(TEXT(mencho), NULL, SND_FILENAME | SND_ASYNC);

            //Duracion 00:30
            temporizadorCancion(0,10);
            break;
        }
        case 2:{
            char sacrifice[] = "C:/Users/ramir/OneDrive/Escritorio/Proyecto_Lista_Reproduccion/canciones/sacrifice.wav";
            PlaySound(TEXT(sacrifice), NULL, SND_FILENAME | SND_ASYNC);
            break;
        }
        case 3:{
            char abcdefg[] = "C:/Users/ramir/OneDrive/Escritorio/Proyecto_Lista_Reproduccion/canciones/abcdefg.wav";
            PlaySound(TEXT(abcdefg), NULL, SND_FILENAME | SND_ASYNC);
            break;
            }
        case 4:{
        C:/Users/ramir/OneDrive/Escritorio/Proyecto_Lista_Reproduccion/canciones/champions.wav
            char champions[] = "C:/Users/ramir/OneDrive/Escritorio/Proyecto Lista Reproduccion/canciones/champions.wav";
            PlaySound(TEXT(champions), NULL, SND_FILENAME | SND_ASYNC);
            break;
            }
        }

}*/
