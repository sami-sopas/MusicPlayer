#include"ListaCircular.h"
#include"Cancion.h"
#include"Animaciones.h"
#include"windows.h"
#include<iostream>
#include"conio.h"

using namespace std;
void interfazReproductor();
void gotoxy(int x, int y)
{
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}

ListaCircular::ListaCircular()
{
    encabezado = nullptr;
}

ListaCircular::~ListaCircular()
{
    if (encabezado != nullptr) {
        Nodo *temp = encabezado->siguiente;
        Nodo *temp_encabezado;

        while(temp != encabezado){
            temp_encabezado = temp;
            temp = temp->siguiente;

            delete temp_encabezado;
        }
        delete encabezado;
    }
}

void ListaCircular::insertarPrimero(Cancion cancion)
{
    ///Insercion
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->mySong = cancion;

    if(encabezado == nullptr){
        nuevo_nodo->siguiente = nuevo_nodo;

        nuevo_nodo->anterior = nuevo_nodo;

        encabezado = nuevo_nodo;
    }else{
        Nodo *ultimo_nodo = encabezado->anterior;

        nuevo_nodo->siguiente = encabezado;

        nuevo_nodo->anterior = ultimo_nodo;

        encabezado->anterior = nuevo_nodo;

        ultimo_nodo->siguiente = nuevo_nodo;

        encabezado = nuevo_nodo;
    }
}

void ListaCircular::insertarUltimo(Cancion cancion)
{

    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->mySong = cancion;

    if(encabezado == nullptr){
        nuevo_nodo->siguiente = nuevo_nodo;

        nuevo_nodo->anterior = nuevo_nodo;

        encabezado = nuevo_nodo;
    }else{
        Nodo *ultimo_nodo = encabezado->anterior;

        nuevo_nodo->siguiente = encabezado;

        nuevo_nodo->anterior = ultimo_nodo;

        encabezado->anterior = nuevo_nodo;

        ultimo_nodo->siguiente = nuevo_nodo;


    }
}

bool ListaCircular::estaVacia()
{
    if(encabezado == nullptr){
        return true;
    }else{
        return false;
    }

}
void ListaCircular::imprimirLista(int puntero,Cancion cancion) //Imprime toda la lista
{
    if(!estaVacia()) {
        int n(8);
        int id(1);
        Nodo *temp = encabezado;
        printf(GRISBAJITO);
        gotoxy(116,6+puntero+puntero); cout << "<-" << "\n                              ------------------- ------------------- ------------------- -------------------------";
        printf(REGRESA);
        do{
            interfazPrincipal(); //Imprime la interfaz si no esta vacia
            cancion = temp->mySong;

            //Impresion de todos los datos de la lista en orden
            //ID
            gotoxy(111,6); cout << "ID" ;
            gotoxy(111,n); cout << id;

            //Nombre
            gotoxy(96,6); cout << "NOMBRE";
            ///SI LA CADENA ES MUY LARGA NO SE IMPRIMIRA COMPLETA. ESTA ES LA VALIDACION
            if(cancion.getNombre().size() < 15){
                //Cadena completa
                gotoxy(92,n); cout << cancion.getNombre();
            }else{
                //Cadena con puntitos
                gotoxy(92,n); cout << cancion.getNombre().substr(0,11) + "...";
            }

            //Artista
            gotoxy(76,6); cout << "ARTISTA";
            if(cancion.getArtista().size() < 15){
                gotoxy(72,n); cout << cancion.getArtista();
            }else{
                gotoxy(72,n); cout << cancion.getArtista().substr(0,11) + "...";
            }

            //Album
            gotoxy(57,6); cout << "ALBUM";
            if(cancion.getAlbum().size() < 15){
                gotoxy(52,n); cout << cancion.getAlbum();
            }else{
                gotoxy(52,n); cout << cancion.getArtista().substr(0,11) + "...";
            }

            //Genero
            gotoxy(37,6); cout << "GENERO";
            if(cancion.getGenero().size() < 15){
                gotoxy(32,n); cout << cancion.getGenero();
            }else{
                gotoxy(32,n); cout << cancion.getGenero().substr(0,11) + "...";
            }

            temp = temp->siguiente; //Se aumenta en uno temp para seguir imprimiendo hasta que acabe el ciclo do while donde temp sea diferente que encabezado
            cout << endl;
            n+=2; //Se aumento en 2 para darle un espacio entre cancion y cancion
            id++;
        }while(temp != encabezado);
    }else{ //SI la lista esta vacia imprime la interfaz para este caso
        interfazPrincipalVacia();
        gotoxy(54,7); cout << " ACTUALMENTE LA LISTA ESTA VACIA :( " << endl;
        gotoxy(43,9); cout << "AGREGA UNAS CANCIONES PARA EMPEZAR A REPRODUCIR MUSICA :D" << endl;

    }
}

void ListaCircular::imprimirCancionActual(int puntero)
{
    Cancion cancion;
    if(estaVacia()){
       // cout << "esta vacia " << endl;
    }else{
        cancion = buscarPos(puntero);

        ///Cambiamos los string de minutos y segundos a int
        int minutos;
        int segundos;

        minutos = stoi(cancion.getMinutos());
        segundos = stoi(cancion.getSegundos());

        gotoxy(31,2); cout << "CANCION: " << cancion.getNombre();
        gotoxy(70,2); cout << "ARTISTA: " << cancion.getArtista();
        gotoxy(31,4); cout << "ALBUM: " << cancion.getAlbum();
        gotoxy(70,4); cout << "GENERO: " << cancion.getGenero();

        gotoxy(95,3); cout << "DURACION: "; printf("%.2d:%.2d",minutos,segundos);

        //gotoxy(0,0); cout << "DIRECCION: " << cancion.getDireccion();
        //gotoxy(70,0); cout << "MINUTOS: " << cancion.getMinutos();
       // gotoxy(80,0); cout << "SEGUNDOS: " << cancion.getSegundos();

    }
}

void ListaCircular::imprimirCancionActualReproductor(int puntero) //Imprime la cancion actual en otra posicion
{


    Cancion cancion;
    if(!estaVacia()){

        cancion = buscarPos(puntero);

        ///Cambiamos los string de minutos y segundos a int
        int minutos;
        int segundos;

        minutos = stoi(cancion.getMinutos());
        segundos = stoi(cancion.getSegundos());

        gotoxy(60,9); printf("%c",254); cout << " ESTAS ESCUCHANDO: " << cancion.getNombre();
        gotoxy(60,12); printf("%c",254); cout << " DE: " << cancion.getArtista();
        gotoxy(60,15); printf("%c",254); cout << " DEL ALBUM: " << cancion.getAlbum();
        gotoxy(105,22); printf("%.2d:%.2d",minutos,segundos); //Para imprimir la duracion total de la cancion actual

        //Lineas blancas que estan debajo del nombre de las canciones
        gotoxy(60,10); for (int i = 0; i < 40; i++){
                               printf("-");
                               }

        gotoxy(60,13); for (int i = 0; i < 40; i++){
                               printf("-");
                               }

        gotoxy(60,16); for (int i = 0; i < 40; i++){
                               printf("-");
                               }

        temporizadorCancion(minutos,segundos); //LLamamos al temprozaodr
    }

}

void ListaCircular::reproducirCancion(int puntero) //Reproduce la cancion dependiendo de donde este el puntero
{
    Cancion cancion; //auxiliar
    if(!estaVacia()){
        cancion = buscarPos(puntero); /*Con la funcion de buscar que nos regresa un objeto cancion lo igualamos al auxiliar de aqui
                                          y a partir de ahi imprime dependiendo de donde este el puntero*/

        //Aqui convierto la cadena con la que recibi la direccion a char
        string cadena = cancion.getDireccion();
        char auxiliar[150];
        strcpy(auxiliar,cadena.c_str()); //Esta madre me regresa un char*

        //Y ya convertida ahora si se hace el proceso para que se reproduzca la cancion
        char* song[] = {auxiliar};
        PlaySound(TEXT(*song), NULL, SND_FILENAME | SND_ASYNC);
    }
}

void ListaCircular::temporizadorCancion(int m,int s)
{
        int minutos = 0;
        int segundos = 0;
        int i = 47;

        do{
          gotoxy(70,25);cout << "<|    ||    |>";
          gotoxy(70,26); cout << "1      2    3"; //Solo para mostrarlo y de ahi al dar a un numero. se rompa el ciclo y eso se guarde en el main en la funcion de interfaz reproductor

            segundos++;

            if(segundos == 60){
                segundos = 0;
                minutos++;
                if(minutos == 60){
                    minutos = 0;
                }
            }
            if(i == 109){ //Si la barra llega a su limite (109) se empieza a reducir. de manera contraria ya se ejecuta el switch depeniendo de los minutos
                i--;
            }else{

            switch(m){ //m son los minutos que dura la cancion (dato que recibo desde la funcion de imprimir cancion actual
                //Dependiendo de cuantos minutos dure. aumento cada x segundos i para imprimir la barra

                case 0:{
                    i++; //No se termina de completar si es muy menor que 1
                    break;
                }
                case 1:{
                        i++; //Apenitas. se aumenta cada segundo
                    break;
                }
                case 2:{
                    if(segundos % 2 == 0){
                        i++;
                    }
                    break;
                }
                case 3:{
                    if(segundos % 3 == 0){
                        i++;
                    }
                    break;
                }
                case 4:{
                    if(segundos == 4 or segundos == 8){ // Aqui aumento un rectangulo cada que segundo sea 4 u 8
                        i++;
                    }
                }
                case 5:{ //Para aumentar cada 5 segundos
                    if(segundos % 5 == 0){
                        i++;
                    }
                }

            }
            }

            gotoxy(46,22); printf("%.2d:%.2d",minutos,segundos); //Para el temporizador
            Sleep(1000);
            gotoxy(i,20); printf("%c",254); //Para la barra
            Sleep(30);

            if(kbhit()) break; //Si se presiona una tecla durante el ciclo. esto lo que hace es terminarlo

        }while(minutos != m || segundos != s);

}

int ListaCircular::travel()
{
    int contador = 0;

    if(!estaVacia()){
        Nodo *temp = encabezado;
        do{
            contador++;
            temp = temp->siguiente;
        }while(temp != encabezado);
    }

    return contador;
}

void ListaCircular::eliminar(const int& posicion) {

    if (posicion<= travel())
    {
        if (posicion == 1)
        {
            if (travel() == 1)
            {
                delete encabezado;
                encabezado = nullptr;
            }
            else
            {
                Nodo *temp_encabezado = encabezado;
                Nodo *ultimo_nodo = encabezado->anterior;
                encabezado = encabezado->siguiente;
                ultimo_nodo->siguiente = encabezado;
                encabezado->anterior = ultimo_nodo;
                delete temp_encabezado;
            }
        }
        else
            {
                Nodo *temp = encabezado;
                for (int f = 1; f <= posicion-1; f++)
                temp = temp->siguiente;
                Nodo *temp_encabezado = temp;
                Nodo *anterior = temp->anterior;
                temp = temp->siguiente;
                anterior->siguiente = temp;
                temp->anterior = anterior;
                delete temp_encabezado;
            }
    }
}

Cancion ListaCircular::buscarPos(const int& posicion)
{
    Nodo *temp = encabezado;
    for (int i = 1; i <= posicion-1; i++){
        temp = temp->siguiente;
    }
    return temp->mySong;
}

void ListaCircular::modificar(const int& posicion, Cancion cancion)
{
    Nodo* temp = encabezado;
    for (int i = 1; i <= posicion-1; i++){
        temp = temp->siguiente;
    }
    temp->mySong = cancion;
}

