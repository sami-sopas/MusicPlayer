#include"Animaciones.h"
#include"windows.h"
#include<ctime>
#include<vector>

#define color SetConsoleTextAttribute //para solo llamar a color cuando quiera cambiar el color y no usar toda esa funcion larga

HANDLE hConsole = GetStdHandle( STD_OUTPUT_HANDLE ); ///PARA PODER CAMBIAR COLOR

void titulo(){

    color(hConsole,3);
    gotoxy(8,3); cout << "P";
    color(hConsole,12);
    gotoxy(9,3); cout << "L";
    color(hConsole,6);
    gotoxy(10,3); cout << "A";
    color(hConsole,8);
    gotoxy(11,3); cout << "Y";
    color(hConsole,9);
    gotoxy(12,3); cout << "L";
    color(hConsole,10);
    gotoxy(13,3); cout << "I";
    color(hConsole,14);
    gotoxy(14,3); cout << "S";
    color(hConsole,11);
    gotoxy(15,3); cout << "T";
    color(hConsole,7);

    gotoxy(18,3); printf("%c %c %c %c %c",220,219,220,219,220); //Barras de volumen

    gotoxy(5,4); cout << "------------------------" ;


}
void interfazPrincipalVacia(){
    color(hConsole,15);
    piano();

    //Barra superior
    gotoxy(4,1); for(int i = 0; i < 112; i++){
         printf("%c",205);
    }

    //Barra inferior
    gotoxy(4,28); for (int i = 0; i <112; i++){
        printf("%c",205);
    }

    //Esquinas
    gotoxy(4,1); printf("%c",201); // Superior izquierda
    gotoxy(115,1); printf("%c",187); // Superior derecha
    gotoxy(4,28); printf("%c",200); //Inferior izquierda
    gotoxy(115,28); printf("%c",188); //Inferior derecha

    //Barra lateral izquierda
     for (int i = 2; i <28; i++){
        gotoxy(4,i); printf("%c",186);
    }

    //Barra lateral derecha
    for (int i = 2;i < 28; i++){
        gotoxy(115,i); printf("%c",186);
    }

    //Rectangulo de arriba
    gotoxy(29,5); for (int i = 0; i < 86; i++){
         printf("%c",205);
    }

    //Barra vertical de adentro
    for (int i = 2; i < 28; i++){
        gotoxy(29,i); printf("%c",186);
    }

    //Union del rectangulito de arriba
    gotoxy(115,5); printf("%c",185); //Derecho
    gotoxy(29,5); printf("%c",204); //Izquierdo
    gotoxy(29,1); printf("%c",203);//Arriba
    gotoxy(29,28); printf("%c",202); //Abajo

    color(hConsole,14);
    gotoxy(53,3); printf("BIENVENIDO A TU LISTA DE REPRODUCCION !!!");
    color(hConsole,7);
}

void interfazPrincipal_AgregandoCancion(){
    system("cls");
    color(hConsole,15);
    violin();

    //Barra superior
    gotoxy(4,1); for(int i = 0; i < 112; i++){
         printf("%c",205);
    }

    //Barra inferior
    gotoxy(4,28); for (int i = 0; i <112; i++){
        printf("%c",205);
    }

    //Esquinas
    gotoxy(4,1); printf("%c",201); // Superior izquierda
    gotoxy(115,1); printf("%c",187); // Superior derecha
    gotoxy(4,28); printf("%c",200); //Inferior izquierda
    gotoxy(115,28); printf("%c",188); //Inferior derecha

    //Barra lateral izquierda
     for (int i = 2; i <28; i++){
        gotoxy(4,i); printf("%c",186);
    }

    //Barra lateral derecha
    for (int i = 2;i < 28; i++){
        gotoxy(115,i); printf("%c",186);
    }

    //Rectangulo de arriba
    gotoxy(29,5); for (int i = 0; i < 86; i++){
         printf("%c",205);
    }

    //Barra vertical de adentro
    for (int i = 2; i < 28; i++){
        gotoxy(29,i); printf("%c",186);
    }

    //Union del rectangulito de arriba
    gotoxy(115,5); printf("%c",185); //Derecho
    gotoxy(29,5); printf("%c",204); //Izquierdo
    gotoxy(29,1); printf("%c",203);//Arriba
    gotoxy(29,28); printf("%c",202); //Abajo

    gotoxy(60,3); printf("AGREGAR NUEVA CANCION");
}

void interfazPrincipal_ModificandoCancion(){
    system("cls");
    notas();

    //Barra superior
    gotoxy(4,1); for(int i = 0; i < 112; i++){
         printf("%c",205);
    }

    //Barra inferior
    gotoxy(4,28); for (int i = 0; i <112; i++){
        printf("%c",205);
    }

    //Esquinas
    gotoxy(4,1); printf("%c",201); // Superior izquierda
    gotoxy(115,1); printf("%c",187); // Superior derecha
    gotoxy(4,28); printf("%c",200); //Inferior izquierda
    gotoxy(115,28); printf("%c",188); //Inferior derecha

    //Barra lateral izquierda
     for (int i = 2; i <28; i++){
        gotoxy(4,i); printf("%c",186);
    }

    //Barra lateral derecha
    for (int i = 2;i < 28; i++){
        gotoxy(115,i); printf("%c",186);
    }

    //Rectangulo de arriba
    gotoxy(29,5); for (int i = 0; i < 86; i++){
         printf("%c",205);
    }

    //Barra vertical de adentro
    for (int i = 2; i < 28; i++){
        gotoxy(29,i); printf("%c",186);
    }

    //Union del rectangulito de arriba
    gotoxy(115,5); printf("%c",185); //Derecho
    gotoxy(29,5); printf("%c",204); //Izquierdo
    gotoxy(29,1); printf("%c",203);//Arriba
    gotoxy(29,28); printf("%c",202); //Abajo

    color(hConsole,14);
    gotoxy(63,3); printf("EDITAR CANCION");
    color(hConsole,7);
}

void interfazPrincipal(){

     color(hConsole,15);
    //Barra superior
    gotoxy(4,1); for(int i = 0; i < 112; i++){
         printf("%c",205);
    }

    //Barra inferior
    gotoxy(4,28); for (int i = 0; i <112; i++){
        printf("%c",205);
    }

    //Esquinas
    gotoxy(4,1); printf("%c",201); // Superior izquierda
    gotoxy(115,1); printf("%c",187); // Superior derecha
    gotoxy(4,28); printf("%c",200); //Inferior izquierda
    gotoxy(115,28); printf("%c",188); //Inferior derecha

    //Barra lateral izquierda
     for (int i = 2; i <28; i++){
        gotoxy(4,i); printf("%c",186);
    }

    //Barra lateral derecha
    for (int i = 2;i < 28; i++){
        gotoxy(115,i); printf("%c",186);
    }

    //Rectangulo de arriba
    gotoxy(29,5); for (int i = 0; i < 86; i++){
         printf("%c",205);
    }

    //Barra vertical de adentro
    for (int i = 2; i < 28; i++){
        gotoxy(29,i); printf("%c",186);
    }

    //Union del rectangulito de arriba
    gotoxy(115,5); printf("%c",185); //Derecho
    gotoxy(29,5); printf("%c",204); //Izquierdo
    gotoxy(29,1); printf("%c",203);//Arriba
    gotoxy(29,28); printf("%c",202); //Abajo

    //Rectangulo de soporte (para id, nombre etc)
    gotoxy(30,7); for (int i = 0; i < 85; i++){
         printf("%c",205);
    }

    gotoxy(29,7); printf("%c",204); //Union izquierda
    gotoxy(115,7); printf("%c",185); //Union derecha

    //Columnas donde esta el id, nombre etc

    //ID
    for (int i = 6; i < 28; i++){
        gotoxy(108,i); printf("%c",186); //Columna
    }

    gotoxy(108,5); printf("%c",203); //Union arriba
    gotoxy(108,7); printf("%c",206); //Union en medio
    gotoxy(108,28); printf("%c",202); //Union abajo

    //NOMBRE
    for (int i = 6; i < 28; i++){
        gotoxy(89,i); printf("%c",186); //Columna
    }

    gotoxy(89,5); printf("%c",203); //Union arriba
    gotoxy(89,7); printf("%c",206); //Union en medio
    gotoxy(89,28); printf("%c",202); //Union abajo

    //ARTISTA
    for (int i = 6; i < 28; i++){
        gotoxy(69,i); printf("%c",186);
    }

    gotoxy(69,5); printf("%c",203); //Union arriba
    gotoxy(69,7); printf("%c",206); //Union en medio
    gotoxy(69,28); printf("%c",202); //Union abajo

    //ALBUM
    for (int i = 6; i < 28; i++){
        gotoxy(49,i); printf("%c",186);
    }

    gotoxy(49,5); printf("%c",203); //Union arriba
    gotoxy(49,7); printf("%c",206); //Union en medio
    gotoxy(49,28); printf("%c",202); //Union abajo
    color(hConsole,7);

}

void agregandoCancion(){

    gotoxy(50,22); cout << "AGREGANDO CANCION A LA LISTA DE REPRODUCCION" << endl;

    for (int i = 45; i < 100; i+=2){
            Sleep(30);
       gotoxy(i,24); printf("%c",254);
    }

}

void editandoCancion(){

    gotoxy(50,22); cout << "EDITANDO CANCION DE LA LISTA DE REPRODUCCION" << endl;

    for (int i = 45; i < 100; i+=2){
            Sleep(30);
       gotoxy(i,24); printf("%c",254);
    }

}

void piano(){

gotoxy(50,11); printf("       ________________________");
gotoxy(50,12);printf("     /           ___ ___       '.");
gotoxy(50,13);printf("     |\\ .-------|:::/:::|--------;");
gotoxy(50,14);printf("     | |        |:::|:::|        |");
gotoxy(50,15);printf("     |\\|_  ___ _|:::/:::| __ ____|");
gotoxy(50,16);printf("     | |_________       _________`\\ ");
gotoxy(50,17);printf("     | |\\##\\\\###\\\\##\\\\###\\\\##\\\\### \\ ");
gotoxy(50,18);printf("     \\ \\ \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ \\ ");
gotoxy(50,19);printf("     |\ \||||||||||||||||||||||||||||_| ");
gotoxy(50,20);printf("     | | ;""""""""""""""""""""""""; | ");
gotoxy(50,21);printf("     | | |"""""".----------.""""""| | ");
gotoxy(50,22);printf("     | | |     |\\           \\  |  | | ");
gotoxy(50,23);printf("     | | |-----|\\\\___________\\-|  | | ");
gotoxy(50,24);printf("     | | |     | |---------- |  \\ | | ");
gotoxy(50,25);printf("     `\\| |     | |         | |   `| | ");
gotoxy(50,26);printf("       \\_|       |           |    `\\| ");


gotoxy(67,16); printf("%c%c%c %c%c%c",34,34,34,34,34,34); //Comillas (") ya que esas no se pueden imprimir directamente

gotoxy(60,20); for(int i = 0; i < 26; i++) {
    printf("%c",34); //Comillas (") ya que esas no se pueden imprimir directamente
    }

    gotoxy(84,20); printf(";");

gotoxy(60,21); for(int i = 0; i < 6; i++) {
    printf("%c",34); //Comillas (") ya que esas no se pueden imprimir directamente
    }

gotoxy(78,21); for(int i = 0; i < 6; i++) {
    printf("%c",34); //Comillas (") ya que esas no se pueden imprimir directamente
    }


gotoxy(66,21); printf(".----------.");

gotoxy(84,21); printf("| |");

gotoxy(86,20); printf("|");
}

void violin(){

gotoxy(3,7); printf("            ,;, ");
gotoxy(3,8);printf("           #(|)# ");
gotoxy(3,9);printf("           #|||# ");
gotoxy(3,10);printf("            ||| ");
gotoxy(3,11);printf("            ||| ");
gotoxy(3,12);printf("            ||| ");
gotoxy(3,13);printf("           _|||_ ");
gotoxy(3,14);printf("         .' ||| '. ");
gotoxy(3,15);printf("        /   |||   \\ ");
gotoxy(3,16);printf("        |   |||   | ");
gotoxy(3,17);printf("        |_  |||  _| ");
gotoxy(3,18);printf("        ,_)=|||=(_, ");
gotoxy(3,19);printf("        )   |||   ( ");
gotoxy(3,20);printf("       /    |||    \\ ");
gotoxy(3,21);printf("      |     |||     | ");
gotoxy(3,22);printf("      |    \\~~~/    | ");
gotoxy(3,23);printf("       \\    \\ /    / ");
gotoxy(3,24);printf("        `-.__Y__.-' ");

}

void notas(){

gotoxy(3,10); cout <<"        , ";
gotoxy(3,11); cout <<"        |\\        __ ";
gotoxy(3,12); cout <<"        | |      |--|   ";
gotoxy(3,13); cout <<"        |/       |  |   ";
gotoxy(3,14); cout <<"       /|_      () ()   " ;
gotoxy(3,15); cout << "     //| \\            " ;
gotoxy(3,16); cout <<"     | \\|_ |           ";
gotoxy(3,17); cout <<"      \\_|_/            ";
gotoxy(3,18); cout <<"        |               " ;
gotoxy(3,19); cout <<"       @'               " ;

}

void reproductor(){
    system("cls");

    fechaHora(); //Mostrar fecha y hora en el reproductor spotifais
    cuadroNotas(); //Mostral el cuadrito de music

    color(hConsole,15);
        //Barra superior
    gotoxy(4,1); for(int i = 0; i < 112; i++){
         printf("%c",205);
    }

    //Barra inferior
    gotoxy(4,28); for (int i = 0; i <112; i++){
        printf("%c",205);
    }

    //Esquinas
    gotoxy(4,1); printf("%c",201); // Superior izquierda
    gotoxy(115,1); printf("%c",187); // Superior derecha
    gotoxy(4,28); printf("%c",200); //Inferior izquierda
    gotoxy(115,28); printf("%c",188); //Inferior derecha

    //Barra lateral izquierda
     for (int i = 2; i <28; i++){
        gotoxy(4,i); printf("%c",186);
    }

    //Barra lateral derecha
    for (int i = 2;i < 28; i++){
        gotoxy(115,i); printf("%c",186);
    }
    color(hConsole,7);

    color(hConsole,10);
    gotoxy(55,3); printf("SPOTIFY");
    color(hConsole,7);

    color(hConsole,15);
    for (int i = 5; i < 115; i++){
        gotoxy(i,5); printf("-");
    }
    color(hConsole,7);

}

void cuadroNotas(){

        //Barra superior
    gotoxy(8,7); for(int i = 0; i < 35; i++){
         printf("%c",205);
    }

    //Barra inferior
    gotoxy(8,22); for (int i = 0; i <35; i++){
        printf("%c",205);
    }

        //Barra lateral izquierda
     for (int i = 8; i <22; i++){
        gotoxy(8,i); printf("%c",186);
    }

    //Barra lateral derecha
    for (int i = 8;i < 22; i++){
        gotoxy(42,i); printf("%c",186);
    }

        //Esquinas
    gotoxy(8,7); printf("%c",201); // Superior izquierda
    gotoxy(42,7); printf("%c",187); // Superior derecha
    gotoxy(8,22); printf("%c",200); //Inferior izquierda
    gotoxy(42,22); printf("%c",188); //Inferior derecha

    ///NOTAS MUSICALES

   // gotoxy(9,8); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196);
    gotoxy(9,8); for (int i = 0; i < 33; i++){ ///PRIMERA LINEA
         printf("%c",196);
    }

    gotoxy(9,9); for (int i = 0; i < 33; i++){
         printf("%c",196);
    }

    gotoxy(9,10); for (int i = 0; i < 33; i++){
         printf("%c",196);
    }

    gotoxy(9,11); for (int i = 0; i < 33; i++){
         printf("%c",196);
    }

    gotoxy(9,12); for (int i = 0; i < 33; i++){
         printf("%c",196);
    }

    gotoxy(9,13); for (int i = 0; i < 33; i++){
         printf("%c",196);
    }

    gotoxy(9,14); for (int i = 0; i < 33; i++){
         printf("%c",196);
    }

    gotoxy(9,15); for (int i = 0; i < 33; i++){
         printf("%c",196);
    }

    gotoxy(9,16); for (int i = 0; i < 33; i++){
         printf("%c",196);
    }

    gotoxy(9,17); for (int i = 0; i < 33; i++){
         printf("%c",196);
    }

    gotoxy(9,18); for (int i = 0; i < 33; i++){
         printf("%c",196);
    }

    gotoxy(9,19); for (int i = 0; i < 33; i++){
         printf("%c",196);
    }

    gotoxy(9,20); for (int i = 0; i < 33; i++){
         printf("%c",196);
    }

    gotoxy(9,21); for (int i = 0; i < 33; i++){ ///ULTIMA LINEA
         printf("%c",196);
    }

    ///NOTA 1
    /*
────█▀█▄▄▄▄─────██▄
────█▀▄▄▄▄█─────█▀▀█
─▄▄▄█─────█──▄▄▄█
██▀▄█─▄██▀█─███▀█
─▀▀▀──▀█▄█▀─▀█▄█▀*/

    color(hConsole,generarColor1()); //Se cambia de color
    gotoxy(15,12); printf("%c%c%c",219,219,220);
    gotoxy(15,13); printf("%c%c%c%c",219,223,223,219);
    gotoxy(12,14); printf("%c%c%c%c",220,220,220,219);
    gotoxy(11,15); printf("%c%c%c%c%c",219,219,219,223,219);
    gotoxy(11,16); printf("%c%c%c%c%c",223,219,220,219,223);
    color(hConsole,7); //Regresa al original gris

    ///NOTA 2
    color(hConsole,generarColor2());
    gotoxy(22,17); printf("%c%c%c%c%c%c%c",219,223,219,220,220,220,220);
    gotoxy(22,18); printf("%c%c%c%c%c%c%c",219,223,220,220,220,220,219);
    gotoxy(19,19); printf("%c%c%c%c     %c",220,220,220,219,219);
    gotoxy(18,20); printf("%c%c%c%c%c %c%c%c%c%c",219,219,223,220,219,220,219,219,223,219);
    gotoxy(19,21); printf("%c%c%c  %c%c%c%c%c",223,223,223,223,219,220,219,223);
    color(hConsole,7);

    ///NOTA 3
/*
───▄▀▌─▄▄▄▄
──▄█▀──▌─▌─▌─▄▄▄▄
▄▀─█▄──▌─▌─▌─▌─▌─▌
█─▀█─▌█▌█▌█▌─▌ ▌─▌
▀█▄█▀───────█▌█▌█▌
*/
    color(hConsole,generarColor3());
    gotoxy(34,8); printf("%c",220);
    gotoxy(33,9); printf("%c %c",219,219);
    gotoxy(32,10); printf("%c%c%c",220,219,223);
    gotoxy(30,11); printf("%c%c%c%c%c",220,223,196,219,220);
    gotoxy(30,12); printf("%c%c%c%c%c%c",219,196,223,219,196,219);
    gotoxy(30,13); printf("%c%c%c%c%c",223,219,220,219,223);
    gotoxy(31,14); printf("%c %c",220,219);
    gotoxy(32,15); printf("%c",223);
    color(hConsole,7);
}

int generarColor1(){
    srand((unsigned)time(0));
    return rand() % 14 + 1; //Para que retorne un numero random entre 1 y 14
}

int generarColor2(){
    srand((unsigned)time(0));
    return rand() % 13 + 2; //Para que retorne un numero random entre 1 y 14
}

int generarColor3(){
    srand((unsigned)time(0));
    return rand() % 12 + 3; //Para que retorne un numero random entre 1 y 14
}
void fechaHora(){
    time_t now = time(0);
    tm*time = localtime(&now);

    vector<string> dia_semana;
    dia_semana.push_back("Domingo");
    dia_semana.push_back("Lunes");
    dia_semana.push_back("Martes");
    dia_semana.push_back("Miercoles");
    dia_semana.push_back("Jueves");
    dia_semana.push_back("Viernes");
    dia_semana.push_back("Sabado");

    vector<string> mes;
    mes.push_back("Enero");
    mes.push_back("Febrero");
    mes.push_back("Marzo");
    mes.push_back("Abril");
    mes.push_back("Mayo");
    mes.push_back("Junio");
    mes.push_back("Julio");
    mes.push_back("Agosto");
    mes.push_back("Septiembre");
    mes.push_back("Octubre");
    mes.push_back("Noviembre");
    mes.push_back("Diciembre");

    int anio = 1900 + time->tm_year;

    /*cout << "Dia: " << dia_semana[time->tm_wday] << endl;
    cout << "Mes: " << mes[time->tm_mon] << endl;*/

    cout << "     " << dia_semana[time->tm_wday] << ",";
    cout << time->tm_mday << " de " << mes[time->tm_mon] << " del " << anio << endl;

    gotoxy(110,0); printf("%.2d:%.2d",time->tm_hour,time->tm_min);
    //otra manera: cout << time->tm_hour << ":" << time->tm_min << endl;
}
