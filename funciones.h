#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define FILAS 3
#define COLUMNAS 12
#define COLUMNAS2 18

int sumaUsuario = 0;
int sumaCasino = 0;
int color_consecutivo_rojo = 0;
int color_consecutivo_negro = 0;
int veces_que_sale_en_numero_primo = 0;

int rueda1( int tablero[][COLUMNAS],int tableroBinario[][COLUMNAS], int colorBinario[][COLUMNAS] ){

    srand(time(NULL));

    // VARIABLES
    int fila;  // fila a la que se apuesta,se guarda aca.
    int columna;  // columna a la que se apuesta,se guarda aca.
    int bolilla; // NUMERO ALEATORIO
    int seguirApostando = 1;
    int cantidadFichas;
    int numeroFicha;
    int sumatoria = 0; // acumula el resultado final de las apuestas a casilllas


    // SE IMPRIME EL TABLERO ORIGINAL
    printf("tablero pleno \n");
    printf("\n");
    printf(" 0    1    2    3     4     5     6     7     8     9     10    11\n");
    //printf("\n");
    for(int i = 0; i < 3;i++){
        printf("-------------------------------------------------------------------- \n");
        for(int j = 0; j < 12;j++){
            printf(" %d | ",tablero[i][j]);

        }
    printf("  %d ",i);
    printf("\n");
    }

    printf("\n");

    // SE IMPRIME EL TABLERO ALTERNATIVO,CON VALORES EN 0 , PARA GUARDAR LAS APUESTAS REALIZADAS EN CADA CASILLA
    printf("tablero de apuestas \n");
   // printf(" 0    1    2    3     4     5     6     7     8     9     10    11\n");
    printf("\n");
    for(int i = 0; i < 3;i++){
        printf("-------------------------------------------------------------------- \n");
        for(int j = 0; j < 12;j++){
            printf(" %d | ",tableroBinario[i][j]);

        }
   // printf("      %d ",i);
    printf("\n");
    }

    printf("\n");

    // SE INICIA LA APUESTA DE FICHAS ILIMITADAS
    while(seguirApostando == 1){



    // SE ELIGE LA FILA Y COLUMNA DE CASILLA A APOSTAR
    printf("elegi casilla : \n");
    printf("fila : ");
    scanf( "%d", &fila );
    printf("columna : ");
    scanf("%d", &columna );

    // SE VALIDA QUE LA FILA DEL TABLERO ELEGIDA CORRESPONDA AL RANGO DE MISMO
    while(fila > 2 || columna > 11){

        printf("casilla no valida \n");
        printf("elegi casilla : \n");
        printf("fila : ");
        scanf("%d", &fila );
        printf("columna : ");
        scanf("%d", &columna );
    }

    // SE VALIDA QUE LA COLUMNA DEL TABLERO ELEGIDA CORRESPONDA AL RANGO DE MISMO
    while(fila < 0 || columna < 0){

        printf("casilla no valida \n");
        printf("elegi casilla : \n");
        printf("fila : ");
        scanf("%d", &fila );
        printf("columna : ");
        scanf("%d", &columna );

    }

    // SE MUESTRA EL NUMERO ELEGIDO
    printf("numero elegido : %d \n", tablero[fila][columna]);

    // SE PIDE LA CANTIDAD DE FICHAS A APOSTAR EN LA CASILLA ELEGIDA
    printf("elegi cantidad de fichas a apostar en esa casilla : \n");
    scanf("%d", &cantidadFichas);

    // SE PIDE EL VALOR DE LA FICHA A APOSTAR
    printf("elegi ficha : \n");
    for(int k = 0; k < 5;k++){
        printf("%d ficha : %d \n",k, fichas[k]);
    }
    scanf("%d", &numeroFicha);

    // SE VALIDA QUE LA FICHA ELEGIDA ESTE DENTRO DEL RANGO DE LAS FICHAS DISPONIBLES
    while(numeroFicha > 4 || numeroFicha < 0){

        printf("ficha invalida : \n");
        printf("elegi ficha : \n");

        for(int k = 0; k < 5;k++){
            printf("%d ficha : %d \n",k, fichas[k]);
        }
            scanf("%d", &numeroFicha);
    }

    // SI LA CASILLA ELEGIDA YA CUENTA CON FICHAS APOSTADAS,SE LE SUMAN LAS NUEVAS FICHAS A APOSTAR
    if(tableroBinario[fila][columna] != 0 ){
        tableroBinario[fila][columna] = tableroBinario[fila][columna] +  (fichas[numeroFicha] * cantidadFichas);
        printf("acumulado en la misma casilla : %d \n", tableroBinario[fila][columna]);

    //SE DEPOSITAN LAS FICHAS EN LA CASILLA DEL TABLERO ALTERNATIVO SI ESTA VACIA
    }else{
        tableroBinario[fila][columna] = fichas[numeroFicha] * cantidadFichas;
    }


    // SE PREGUNTA SI DESEA SEGUIR APOSTANDO FICHAS EN OTRAS CASILLAS-----------------------------------------------------+
    printf("seguir apostando fichas ? 1 : si  0 : no \n");
    scanf("%d", &seguirApostando);


    // SE VALIDA LA OPCION ELEGIDA
    while(seguirApostando > 1 || seguirApostando < 0){
        printf("opcion invalida \n");
        printf("seguir apostando fichas ? 1 : si  0 : no \n");
        scanf("%d", &seguirApostando);
    }

    //SI LA RESPUESTA ES 1 (SI),SE SIGUE CON LAS APUESTAS DE FICHAS
    if(seguirApostando == 1){
        rueda1(tablero,tableroBinario,colorBinario);
    }
    // SI LA RESPUESTA ES 0 (NO), SE TERMINA LA RONDA Y SE PROCEDE A LANZAR LA BOLILLA-------------------------------------+
    if(seguirApostando == 0){
        break;
    }
    }


    // NUMERO ALEATORIO DE LA BOLILLA
    bolilla = 1 + rand() % 35;
    printf("numero de BOLILLA : %d \n", bolilla);

    // SE VALIDA SI LA CASILLA ELEGIDA COINCIDE CON EL NUMERO DE BOLILLA
    for(int i = 0;i < FILAS ;i++){
        for(int j = 0;j < COLUMNAS ;j++){

            // SI COINCIDEN LOS NUMEROS , SE AGREGA LA GANANCIA AL USUARIO,Y LA PERDIDA AL CASINO
            if(tableroBinario[i][j] != 0 ){
                if(tablero[i][j] == bolilla ){
                    sumatoria += tableroBinario[i][j] * 35;
                }
            }

            // SI NO COINCIDEN,SE AGREGA LA PERDIDA AL USUARIO,Y LA GANANCIA AL CASINO
            if(tableroBinario[i][j] != 0 ){
                if(tablero[i][j] != bolilla ){
                    sumatoria += tableroBinario[i][j] * -35;
                }
            }
        }
    }



     if ( bolilla == 2 || bolilla == 3 || bolilla == 5 || bolilla == 7 || bolilla == 11 || bolilla == 13 || bolilla == 17 || bolilla == 19 || bolilla == 23 || bolilla == 29 || bolilla == 31  )
    veces_que_sale_en_numero_primo += 1;


    for (int i = 0; i < FILAS ;i++){
    for (int j = 0; j < COLUMNAS ;j++){

     if (bolilla == tablero[i][j]){
        if ( colorBinario[i][j] == 1 ){
            color_consecutivo_rojo += 1;
            }else{
            color_consecutivo_negro -= 1;
        }
    }
    }
    }

    // SE RETORNA EL RESULTADO DE LA APUESTA,PARA DETERMINAR SI ES GANANCIA O PERDIDA
    printf("resultado de la apuesta  : %d \n ", sumatoria);
    sumaUsuario += sumatoria;
    sumaCasino += (-1 * sumatoria);
    printf("dinero acumulado del usuario : %d \n", sumaUsuario);
    printf("dinero acumulado del casino : %d \n", sumaCasino);

    return sumaCasino;

}


int rueda2(int tablero[][COLUMNAS],char tableroColor[][COLUMNAS], int colorBinario[][COLUMNAS] ){

    srand(time(NULL));

    // VARIABLES

    int resultado = 2; // VALOR QUE SE PAGA POR CADA UNIDAD APOSTADA
    int bolilla; // NUMERO ALEATORIO
    int seguirApostando = 1;
    int cantidadFichas;
    int numeroFicha;
    int sumatoria = 0; // acumula el resultado final de las apuestas a casilllas
    int colorElegido;
    int apuestasAcumuladas = 0;


    // SE IMPRIME EL TABLERO ORIGINAL
    printf("tablero \n");
    printf("\n");
    printf(" 0    1    2    3     4     5     6     7     8     9     10    11\n");
    //printf("\n");
    for(int i = 0; i < 3;i++){
        printf("-------------------------------------------------------------------- \n");
        for(int j = 0; j < 12;j++){
            printf(" %d | ",tablero[i][j]);

        }
    printf("  %d ",i);
    printf("\n");
    }

    printf("tablero de colores de cada casilla \n");
    printf("\n");
    printf(" 0    1    2    3    4    5    6    7    8    9    10   11\n");
    //printf("\n");
    for(int i = 0; i < 3;i++){
        printf("----------------------------------------------------------- \n");
        for(int j = 0; j < 12;j++){
            printf(" %c | ",tableroColor[i][j]);

        }
    printf("           %d ",i);
    printf("\n");
    }

    printf("\n");

    // SE INICIA LA APUESTA DE FICHAS ILIMITADAS
    while(seguirApostando == 1){

    printf("elegi a que color apostarle \n 1 : es el rojo - 0 : el negro \n");
    scanf("%d", &colorElegido);
   // printf("color elegido : %c \n", colorElegido);


    // VALIDACION
    while( (colorElegido != 1) & (colorElegido != 0) ){

        printf("color invalido,volve a elegir \n");
        printf("elegi a que color apostarle \n 1 : es el rojo - 0 : el negro \n");
        scanf("%d", &colorElegido);
    }

    // SE PIDE LA CANTIDAD DE FICHAS A APOSTAR EN EL COLOR ELEGIDO
    printf("elegi cantidad de fichas a apostar en ese color : \n");
    scanf("%d", &cantidadFichas);

    // SE PIDE EL VALOR DE LA FICHA A APOSTAR
    printf("elegi ficha : \n");
    for(int k = 0; k < 5;k++){
        printf("%d ficha : %d \n",k, fichas[k]);
    }
    scanf("%d", &numeroFicha);

    // SE VALIDA QUE LA FICHA ELEGIDA ESTE DENTRO DEL RANGO DE LAS FICHAS DISPONIBLES
    while(numeroFicha > 4 || numeroFicha < 0){

        printf("ficha invalida : \n");
        printf("elegi ficha : \n");

        for(int k = 0; k < 5;k++){
            printf("%d ficha : %d \n",k, fichas[k]);
        }
            scanf("%d", &numeroFicha);
    }

    int contador = 0;
    int fichasElegidas[4] = {0,0,0,0};
    fichasElegidas[contador] = fichas[numeroFicha];
    contador += 1;

    int seguir = 0;
    for(int i = 0; i < 4; i++){

        if(fichas[numeroFicha] == fichasElegidas[i]){

            seguir += 1;
        }
    }

    if(seguir == 2){
        printf("numero de ficha ya elegido,no es posible volver a apostar el mismo dinero otra vez \n");
        printf("intente de nuevo...\n");
        rueda2(tablero,tableroColor,colorBinario);
}
    if( seguir == 1 ){
    // SI EL COLOR ELEGIDO YA CUENTA CON FICHAS APOSTADAS,SE LE SUMAN LAS NUEVAS FICHAS A APOSTAR

    if(colorElegido == 0){
        apuestasAcumuladas = apuestasAcumuladas +  (fichas[numeroFicha] * cantidadFichas);
    }
    if(colorElegido == 1){
        apuestasAcumuladas = apuestasAcumuladas + (fichas[numeroFicha] * cantidadFichas);

    }
    }


    seguir = 0;

    // SE PREGUNTA SI DESEA SEGUIR APOSTANDO FICHAS EN OTRAS CASILLAS-----------------------------------------------------+
    printf("seguir apostando fichas ? 1 : si  0 : no \n");
    scanf("%d", &seguirApostando);


    // SE VALIDA LA OPCION ELEGIDA
    while(seguirApostando > 1 || seguirApostando < 0){
        printf("opcion invalida \n");
        printf("seguir apostando fichas ? 1 : si  0 : no \n");
        scanf("%d", &seguirApostando);
    }

    //SI LA RESPUESTA ES 1 (SI),SE SIGUE CON LAS APUESTAS DE FICHAS
    if(seguirApostando == 1){
        rueda2(tablero,tableroColor,colorBinario);
    }
    // SI LA RESPUESTA ES 0 (NO), SE TERMINA LA RONDA Y SE PROCEDE A LANZAR LA BOLILLA-------------------------------------+
    if(seguirApostando == 0){
        break;
    }
    }
    // NUMERO ALEATORIO DE LA BOLILLA
    bolilla = 1 + rand() % 36;
    printf("numero de BOLILLA : %d \n", bolilla);

    // SE VALIDA SI LA CASILLA ELEGIDA COINCIDE CON EL NUMERO DE BOLILLA

            // SI COINCIDEN LOS NUMEROS , SE AGREGA LA GANANCIA AL USUARIO,Y LA PERDIDA AL CASINO

            for(int i = 0; i < FILAS;i++){
                for(int j = 0; j < COLUMNAS;j++){

                if(tablero[i][j] == bolilla ){
                    if( colorElegido == colorBinario[i][j] ){
                        sumatoria += apuestasAcumuladas * 2;
                }
                else{
                        sumatoria += apuestasAcumuladas * (-2) ;
                }
            }
            }
            }

     if ( bolilla == 2 || bolilla == 3 || bolilla == 5 || bolilla == 7 || bolilla == 11 || bolilla == 13 || bolilla == 17 || bolilla == 19 || bolilla == 23 || bolilla == 29 || bolilla == 31  )
    veces_que_sale_en_numero_primo += 1;


    for (int i = 0; i < FILAS ;i++){
    for (int j = 0; j < COLUMNAS ;j++){

     if (bolilla == tablero[i][j]){
        if ( colorBinario [i][j] == 1 ){
            color_consecutivo_rojo += 1;
            }else{
            color_consecutivo_negro -= 1;
        }
    }
    }
    }

    // SE RETORNA EL RESULTADO DE LA APUESTA,PARA DETERMINAR SI ES GANANCIA O PERDIDA
    printf("resultado de la apuesta  : %d \n ", sumatoria);
    sumaUsuario += sumatoria;
    sumaCasino += (-1 * sumatoria);
    printf("dinero acumulado del usuario : %d \n", sumaUsuario);
    printf("dinero acumulado del casino : %d \n", sumaCasino);

    return sumaCasino;
}


int rueda3(int tablero[COLUMNAS], int colorBinario[][COLUMNAS] , int tableroCompleto [][COLUMNAS] ){

    srand(time(NULL));

    // VARIABLES

    int resultado = 3; // VALOR QUE SE PAGA POR CADA UNIDAD APOSTADA
    int bolilla; // NUMERO ALEATORIO
    int seguirApostando = 1;
    int cantidadFichas;
    int numeroFicha;
    int sumatoria = 0; // acumula el resultado final de las apuestas a casilllas
    int apuestasAcumuladas = 0;
    int rondasJugadas = 1;

    while ( seguirApostando == 1 ){

    // SE IMPRIME EL TABLERO ORIGINAL
    printf("tablero docena 1 \n");
    printf("\n");
   // printf("0    1    2    3     4     5     6     7     8     9     10    11\n");
    //printf("\n");
    for(int i = 0; i < 12;i++){
       // printf("-------------------------------------------------------------------- \n");
            printf("%d    ",tablero[i]);

        }

    printf("\n");
    printf("\n");

    // SE PIDE LA CANTIDAD DE FICHAS A APOSTAR EN LA CASILLA ELEGIDA
    printf("elegi cantidad de fichas a apostar en la docena 1 : \n");
    scanf("%d", &cantidadFichas);

    // SE PIDE EL VALOR DE LA FICHA A APOSTAR
    printf("elegi ficha : \n");
    for(int k = 0; k < 5;k++){
        printf("%d ficha : %d \n",k, fichas[k]);
    }
    scanf("%d", &numeroFicha);

    // SE VALIDA QUE LA FICHA ELEGIDA ESTE DENTRO DEL RANGO DE LAS FICHAS DISPONIBLES
    while(numeroFicha > 4 || numeroFicha < 0){
        printf("ficha invalida : \n");
        printf("elegi ficha : \n");
        for(int k = 0; k < 5;k++){
            printf("%d ficha : %d \n",k, fichas[k]);
        }
            scanf("%d", &numeroFicha);
    }

    apuestasAcumuladas += cantidadFichas * fichas[numeroFicha];

    printf("desea seguir apostando ? \n");
    printf("1 : continuar 0: no continuar \n");
    scanf("%d", &seguirApostando);

    while(seguirApostando > 1 || seguirApostando < 0){

        printf("desea seguir apostando ? \n");
        printf("1 : continuar 0: no continuar \n");
        scanf("%d", &seguirApostando);

    }

    if(seguirApostando == 1){

        rueda3(tablero,colorBinario, tableroCompleto);

    }else{

        break;
    }
    }

    bolilla = 1 + rand() % 36;
    printf("numero de BOLILLA : %d \n", bolilla);

    for(int i = 0; i < COLUMNAS;i++){

        if( bolilla == tablero[i] ){
            sumatoria += apuestasAcumuladas * 3;

        }else{
            sumatoria += apuestasAcumuladas * (-3);
    }
    }


     if ( bolilla == 2 || bolilla == 3 || bolilla == 5 || bolilla == 7 || bolilla == 11 || bolilla == 13 || bolilla == 17 || bolilla == 19 || bolilla == 23 || bolilla == 29 || bolilla == 31  )
    veces_que_sale_en_numero_primo += 1;


    for (int i = 0; i < FILAS ;i++){
    for (int j = 0; j < COLUMNAS ;j++){

     if (bolilla == tableroCompleto[i][j]){
        if ( colorBinario [i][j] == 1 ){
            color_consecutivo_rojo += 1;
            }else{
            color_consecutivo_negro -= 1;
        }
    }
    }
    }

    // SE RETORNA EL RESULTADO DE LA APUESTA,PARA DETERMINAR SI ES GANANCIA O PERDIDA
    printf("resultado de la apuesta  : %d \n ", sumatoria);
    sumaUsuario += sumatoria;
    sumaCasino += (-1 * sumatoria);
    printf("dinero acumulado del usuario : %d \n", sumaUsuario);
    printf("dinero acumulado del casino : %d \n", sumaCasino);

    return sumaCasino;

}


int rueda4 (int tablero[COLUMNAS], int colorBinario[][COLUMNAS],int tableroCompleto[][COLUMNAS] ){

    srand(time(NULL));

    // VARIABLES

    int resultado = 3; // VALOR QUE SE PAGA POR CADA UNIDAD APOSTADA
    int bolilla; // NUMERO ALEATORIO
    int seguirApostando = 1;
    int cantidadFichas;
    int numeroFicha;
    int sumatoria = 0; // acumula el resultado final de las apuestas a casilllas
    int apuestasAcumuladas = 0;
    int rondasJugadas = 1;

    while ( seguirApostando == 1 ){

    // SE IMPRIME EL TABLERO ORIGINAL
    printf("tablero docena 2 \n");
    printf("\n");
   // printf("0    1    2    3     4     5     6     7     8     9     10    11\n");
    //printf("\n");
    for(int i = 0; i < 12;i++){
       // printf("-------------------------------------------------------------------- \n");
            printf("%d    ",tablero[i]);

        }

    printf("\n");
    printf("\n");

    // SE PIDE LA CANTIDAD DE FICHAS A APOSTAR EN LA CASILLA ELEGIDA
    printf("elegi cantidad de fichas a apostar en la docena 2 : \n");
    scanf("%d", &cantidadFichas);

    // SE PIDE EL VALOR DE LA FICHA A APOSTAR
    printf("elegi ficha : \n");
    for(int k = 0; k < 5;k++){
        printf("%d ficha : %d \n",k, fichas[k]);
    }
    scanf("%d", &numeroFicha);

    // SE VALIDA QUE LA FICHA ELEGIDA ESTE DENTRO DEL RANGO DE LAS FICHAS DISPONIBLES
    while(numeroFicha > 4 || numeroFicha < 0){

        printf("ficha invalida : \n");
        printf("elegi ficha : \n");

        for(int k = 0; k < 5;k++){
            printf("%d ficha : %d \n",k, fichas[k]);
        }
            scanf("%d", &numeroFicha);
    }

    apuestasAcumuladas += cantidadFichas * fichas[numeroFicha];

    printf("desea seguir apostando ? \n");
    printf("1 : continuar 0: no continuar \n");
    scanf("%d", &seguirApostando);

    while(seguirApostando > 1 || seguirApostando < 0){

        printf("desea seguir apostando ? \n");
        printf("1 : continuar 0: no continuar \n");
        scanf("%d", &seguirApostando);

    }

    if(seguirApostando == 1){

        rueda4 (tablero,colorBinario,tableroCompleto );

    }else{

        break;
    }
    }

    bolilla = 1 + rand() % 36;
    printf("numero de BOLILLA : %d \n", bolilla);

                for(int i = 0; i < COLUMNAS;i++){

                if( bolilla == tablero[i] ){
                        sumatoria += apuestasAcumuladas * 3;
                }else{
                        sumatoria += apuestasAcumuladas * (-3);
                }
            }

     if ( bolilla == 2 || bolilla == 3 || bolilla == 5 || bolilla == 7 || bolilla == 11 || bolilla == 13 || bolilla == 17 || bolilla == 19 || bolilla == 23 || bolilla == 29 || bolilla == 31  )
    veces_que_sale_en_numero_primo += 1;

    for (int i = 0; i < FILAS ;i++){
    for (int j = 0; j < COLUMNAS ;j++){

     if (bolilla == tableroCompleto[i][j]){
        if ( colorBinario [i][j] == 1 ){
            color_consecutivo_rojo += 1;
            }else{
            color_consecutivo_negro -= 1;
        }
    }
    }
    }

    // SE RETORNA EL RESULTADO DE LA APUESTA,PARA DETERMINAR SI ES GANANCIA O PERDIDA
    printf("resultado de la apuesta  : %d \n ", sumatoria);
    sumaUsuario += sumatoria;
    sumaCasino += (-1 * sumatoria);
    printf("dinero acumulado del usuario : %d \n", sumaUsuario);
    printf("dinero acumulado del casino : %d \n", sumaCasino);

    return sumaCasino;

}


int rueda5 (int tablero[COLUMNAS], int colorBinario[][COLUMNAS],int tableroCompleto[][COLUMNAS] ){

    srand(time(NULL));

    // VARIABLES

    int resultado = 3; // VALOR QUE SE PAGA POR CADA UNIDAD APOSTADA
    int bolilla; // NUMERO ALEATORIO
    int seguirApostando = 1;
    int cantidadFichas;
    int numeroFicha;
    int sumatoria = 0; // acumula el resultado final de las apuestas a casilllas
    int apuestasAcumuladas = 0;
    int rondasJugadas = 1;

    while ( seguirApostando == 1 ){

    // SE IMPRIME EL TABLERO ORIGINAL
    printf("tablero docena 3 \n");
    printf("\n");
   // printf("0    1    2    3     4     5     6     7     8     9     10    11\n");
    //printf("\n");
    for(int i = 0; i < 12;i++){
       // printf("-------------------------------------------------------------------- \n");
            printf("%d    ",tablero[i]);

        }

    printf("\n");
    printf("\n");

    // SE PIDE LA CANTIDAD DE FICHAS A APOSTAR EN LA CASILLA ELEGIDA
    printf("elegi cantidad de fichas a apostar en la docena 3 : \n");
    scanf("%d", &cantidadFichas);

    // SE PIDE EL VALOR DE LA FICHA A APOSTAR
    printf("elegi ficha : \n");
    for(int k = 0; k < 5;k++){
        printf("%d ficha : %d \n",k, fichas[k]);
    }
    scanf("%d", &numeroFicha);

    // SE VALIDA QUE LA FICHA ELEGIDA ESTE DENTRO DEL RANGO DE LAS FICHAS DISPONIBLES
    while(numeroFicha > 4 || numeroFicha < 0){

        printf("ficha invalida : \n");
        printf("elegi ficha : \n");

        for(int k = 0; k < 5;k++){
            printf("%d ficha : %d \n",k, fichas[k]);
        }
            scanf("%d", &numeroFicha);
    }

    apuestasAcumuladas += cantidadFichas * fichas[numeroFicha];

    printf("desea seguir apostando ? \n");
    printf("1 : continuar 0: no continuar \n");
    scanf("%d", &seguirApostando);

    while(seguirApostando > 1 || seguirApostando < 0){

        printf("desea seguir apostando ? \n");
        printf("1 : continuar 0: no continuar \n");
        scanf("%d", &seguirApostando);

    }

    if(seguirApostando == 1){

        rueda5 (tablero,colorBinario,tableroCompleto);

    }else{

        break;
    }
    }

    bolilla = 1 + rand() % 36;
    printf("numero de BOLILLA : %d \n", bolilla);

                for(int i = 0; i < COLUMNAS;i++){
                if( bolilla == tablero[i] ){
                        sumatoria += apuestasAcumuladas * 3;
                }else{
                        sumatoria += apuestasAcumuladas * (-3);
                }
            }

     if ( bolilla == 2 || bolilla == 3 || bolilla == 5 || bolilla == 7 || bolilla == 11 || bolilla == 13 || bolilla == 17 || bolilla == 19 || bolilla == 23 || bolilla == 29 || bolilla == 31  )
    veces_que_sale_en_numero_primo += 1;

    for (int i = 0; i < FILAS ;i++){
    for (int j = 0; j < COLUMNAS ;j++){

     if (bolilla == tableroCompleto[i][j]){
        if ( colorBinario [i][j] == 1 ){
            color_consecutivo_rojo += 1;
            }else{
            color_consecutivo_negro -= 1;
        }
    }
    }
    }

    // SE RETORNA EL RESULTADO DE LA APUESTA,PARA DETERMINAR SI ES GANANCIA O PERDIDA
    printf("resultado de la apuesta  : %d \n ", sumatoria);
    sumaUsuario += sumatoria;
    sumaCasino += (-1 * sumatoria);
    printf("dinero acumulado del usuario : %d \n", sumaUsuario);
    printf("dinero acumulado del casino : %d \n", sumaCasino);

    return sumaCasino;
}


int rueda6 ( int tablero[COLUMNAS2], int colorBinario[][COLUMNAS] , int tableroCompleto[][COLUMNAS]  )
{
    srand(time(NULL));
    // VARIABLES
    int bolilla; // NUMERO ALEATORIO
    int seguirApostando = 1;
    int cantidadFichas;
    int numeroFicha;
    int sumatoria = 0; // acumula el resultado final de las apuestas a casillas
    int apuestasAcumuladas = 0;
    int rondasJugadas = 1;

    while ( seguirApostando == 1 )
    {
        printf("\n tablero de falta \n");
            for ( int j = 0; j < 18 ; j++)
                {
                printf(" %d ", tablero[j]);
                }

    // SE PIDE LA CANTIDAD DE FICHAS A APOSTAR EN LA FALTA
    printf("\n elegi cantidad de fichas a apostar en la falta : \n");
    scanf("%d", &cantidadFichas);

    // SE PIDE EL VALOR DE LA FICHA A APOSTAR
    printf("elegi ficha : \n");
    for(int k = 0; k < 5;k++){
        printf("%d ficha : %d \n",k, fichas[k]);
    }
    scanf("%d", &numeroFicha);

    // SE VALIDA QUE LA FICHA ELEGIDA ESTE DENTRO DEL RANGO DE LAS FICHAS DISPONIBLES
    while(numeroFicha > 4 || numeroFicha < 0){

        printf("ficha invalida : \n");
        printf("elegi ficha : \n");

        for(int k = 0; k < 5;k++){
            printf("%d ficha : %d \n",k, fichas[k]);
        }
            scanf("%d", &numeroFicha);
    }

    int contador = 0;
    int fichasElegidas[4] = {0,0,0,0};
    fichasElegidas[contador] = fichas[numeroFicha];
    contador += 1;

    int seguir = 0;
    for(int i = 0; i < 4; i++){

        if(fichas[numeroFicha] == fichasElegidas[i]){

            seguir += 1;
        }
    }

    if(seguir == 2)
        printf("numero de ficha ya elegido,no es posible volver a apostar el mismo dinero otra vez \n");

    if( seguir == 1 ){
    // SI LA APUESTA ELEGIDA YA CUENTA CON FICHAS APOSTADAS,SE LE SUMAN LAS NUEVAS FICHAS A APOSTAR

    apuestasAcumuladas = apuestasAcumuladas + (fichas[numeroFicha] * cantidadFichas);
    }

    seguir = 0;

    // SE PREGUNTA SI DESEA SEGUIR APOSTANDO FICHAS EN OTRAS CASILLAS-----------------------------------------------------+
    printf("seguir apostando fichas ? 1 : si  0 : no \n");
    scanf("%d", &seguirApostando);


    // SE VALIDA LA OPCION ELEGIDA
    while(seguirApostando > 1 || seguirApostando < 0){
        printf("opcion invalida \n");
        printf("seguir apostando fichas ? 1 : si  0 : no \n");
        scanf("%d", &seguirApostando);
    }

    //SI LA RESPUESTA ES 1 (SI),SE SIGUE CON LAS APUESTAS DE FICHAS
    if(seguirApostando == 1){
        rueda6 ( tablero[COLUMNAS2],colorBinario, tableroCompleto );
    }
    // SI LA RESPUESTA ES 0 (NO), SE TERMINA LA RONDA Y SE PROCEDE A LANZAR LA BOLILLA-------------------------------------+
    if(seguirApostando == 0){
        break;
    }
    }
    // NUMERO ALEATORIO DE LA BOLILLA
    bolilla = 1 + rand() % 36;
    printf("numero de BOLILLA : %d \n", bolilla);

    // SE VALIDA SI LA CASILLA ELEGIDA COINCIDE CON EL NUMERO DE BOLILLA

            // SI COINCIDEN LOS NUMEROS , SE AGREGA LA GANANCIA AL USUARIO,Y LA PERDIDA AL CASINO
    int contador = 0;

        for( int j = 0; j < COLUMNAS2;j++ ){

            if( tablero[j] == bolilla ){

                sumaUsuario += apuestasAcumuladas * 2;
                sumaCasino  -= apuestasAcumuladas * 2;
                contador += 1;
                }
                }

    if (contador == 0 ){
    sumaCasino += apuestasAcumuladas * 2;
    sumaUsuario -= sumaCasino ;
    }

    contador = 0;

     if ( bolilla == 2 || bolilla == 3 || bolilla == 5 || bolilla == 7 || bolilla == 11 || bolilla == 13 || bolilla == 17 || bolilla == 19 || bolilla == 23 || bolilla == 29 || bolilla == 31  )
    veces_que_sale_en_numero_primo += 1;


    for (int i = 0; i < FILAS ;i++){
    for (int j = 0; j < COLUMNAS ;j++){

     if (bolilla == tableroCompleto[i][j]){
        if ( colorBinario [i][j] == 1 ){
            color_consecutivo_rojo += 1;
            }else{
            color_consecutivo_negro -= 1;
        }
    }
    }
    }

    sumatoria = apuestasAcumuladas*2;
    // SE RETORNA EL RESULTADO DE LA APUESTA,PARA DETERMINAR SI ES GANANCIA O PERDIDA
    printf("resultado de la apuesta  : %d \n ", sumatoria);
    //sumaUsuario += (-1 * sumatoria);
    //sumaCasino += (-1 * sumatoria);
    printf("dinero acumulado del usuario : %d \n", sumaUsuario);
    printf("dinero acumulado del casino : %d \n", sumaCasino);

    return sumaCasino;
}


int rueda7 ( int tablero [COLUMNAS2], int colorBinario[][COLUMNAS], int tableroCompleto[][COLUMNAS] )
{
    srand(time(NULL));
    // VARIABLES
    int resultado = 2; // VALOR QUE SE PAGA POR CADA UNIDAD APOSTADA
    int bolilla; // NUMERO ALEATORIO
    int seguirApostando = 1;
    int cantidadFichas;
    int numeroFicha;
    int sumatoria = 0; // acumula el resultado final de las apuestas a casilllas
    int apuestasAcumuladas = 0;
    int rondasJugadas = 1;

    while ( seguirApostando == 1 )
    {
        printf("\n tablero de pasa \n");
            for ( int j = 0; j < 18 ; j++)
                {
                printf(" %d ", tablero[j]);
                }

    // SE PIDE LA CANTIDAD DE FICHAS A APOSTAR EN EL COLOR ELEGIDO
    printf("\n elegi cantidad de fichas a apostar en la pasa : \n");
    scanf("%d", &cantidadFichas);

    // SE PIDE EL VALOR DE LA FICHA A APOSTAR
    printf("elegi ficha : \n");
    for(int k = 0; k < 5;k++){
        printf("%d ficha : %d \n",k, fichas[k]);
    }
    scanf("%d", &numeroFicha);

    // SE VALIDA QUE LA FICHA ELEGIDA ESTE DENTRO DEL RANGO DE LAS FICHAS DISPONIBLES
    while(numeroFicha > 4 || numeroFicha < 0){

        printf("ficha invalida : \n");
        printf("elegi ficha : \n");

        for(int k = 0; k < 5;k++){
            printf("%d ficha : %d \n",k, fichas[k]);
        }
            scanf("%d", &numeroFicha);
    }

    int contador = 0;
    int fichasElegidas[4] = {0,0,0,0};
    fichasElegidas[contador] = fichas[numeroFicha];
    contador += 1;

    int seguir = 0;
    for(int i = 0; i < 4; i++){

        if(fichas[numeroFicha] == fichasElegidas[i]){

            seguir += 1;
        }
    }

    if(seguir == 2)
        printf("numero de ficha ya elegido,no es posible volver a apostar el mismo dinero otra vez \n");

    if( seguir == 1 ){
    // SI EL COLOR ELEGIDO YA CUENTA CON FICHAS APOSTADAS,SE LE SUMAN LAS NUEVAS FICHAS A APOSTAR

    apuestasAcumuladas = apuestasAcumuladas + (fichas[numeroFicha] * cantidadFichas);
    }

    seguir = 0;

    // SE PREGUNTA SI DESEA SEGUIR APOSTANDO FICHAS EN OTRAS CASILLAS-----------------------------------------------------+
    printf("seguir apostando fichas ? 1 : si  0 : no \n");
    scanf("%d", &seguirApostando);


    // SE VALIDA LA OPCION ELEGIDA
    while(seguirApostando > 1 || seguirApostando < 0){
        printf("opcion invalida \n");
        printf("seguir apostando fichas ? 1 : si  0 : no \n");
        scanf("%d", &seguirApostando);
    }

    //SI LA RESPUESTA ES 1 (SI),SE SIGUE CON LAS APUESTAS DE FICHAS
    if(seguirApostando == 1){
        rueda7 ( tablero[COLUMNAS2],colorBinario,tableroCompleto );
    }
    // SI LA RESPUESTA ES 0 (NO), SE TERMINA LA RONDA Y SE PROCEDE A LANZAR LA BOLILLA-------------------------------------+
    if(seguirApostando == 0){
        break;
    }
    }
    // NUMERO ALEATORIO DE LA BOLILLA
    bolilla = 1 + rand() % 36;
    printf("numero de BOLILLA : %d \n", bolilla);

    // SE VALIDA SI LA CASILLA ELEGIDA COINCIDE CON EL NUMERO DE BOLILLA

            // SI COINCIDEN LOS NUMEROS , SE AGREGA LA GANANCIA AL USUARIO,Y LA PERDIDA AL CASINO
    int contador = 0;

        for( int j = 0; j < COLUMNAS2;j++ ){
            if( tablero[j] == bolilla ){
                sumaUsuario += apuestasAcumuladas * 2;
                sumaCasino -= apuestasAcumuladas * 2 ;
                contador += 1;
                }
                }

    if (contador == 0 ){
    sumaCasino += apuestasAcumuladas * 2;
    sumaUsuario -= sumaCasino ;
    }

    contador = 0;

     if ( bolilla == 2 || bolilla == 3 || bolilla == 5 || bolilla == 7 || bolilla == 11 || bolilla == 13 || bolilla == 17 || bolilla == 19 || bolilla == 23 || bolilla == 29 || bolilla == 31  )
    veces_que_sale_en_numero_primo += 1;

    for (int i = 0; i < FILAS ;i++){
    for (int j = 0; j < COLUMNAS ;j++){

     if (bolilla == tableroCompleto[i][j]){
        if ( colorBinario [i][j] == 1 ){
            color_consecutivo_rojo += 1;
            }else{
            color_consecutivo_negro -= 1;
        }
    }
    }
    }

    sumatoria = apuestasAcumuladas*2;
    // SE RETORNA EL RESULTADO DE LA APUESTA,PARA DETERMINAR SI ES GANANCIA O PERDIDA
    printf("resultado de la apuesta  : %d \n ", sumatoria);
    //sumaUsuario += (-1 * sumatoria);
    //sumaCasino += (-1 * sumatoria);
    printf("dinero acumulado del usuario : %d \n", sumaUsuario);
    printf("dinero acumulado del casino : %d \n", sumaCasino);

    return sumaCasino;
}


int rueda8 ( int tablero [COLUMNAS2], int colorBinario[][COLUMNAS], int tableroCompleto[][COLUMNAS] )
{
    srand(time(NULL));
    // VARIABLES
    int resultado = 2; // VALOR QUE SE PAGA POR CADA UNIDAD APOSTADA
    int bolilla; // NUMERO ALEATORIO
    int seguirApostando = 1;
    int cantidadFichas;
    int numeroFicha;
    int sumatoria = 0; // acumula el resultado final de las apuestas a casilllas
    int apuestasAcumuladas = 0;
    int rondasJugadas = 1;

    while ( seguirApostando == 1 )
    {
        printf("\n tablero de pares \n");
            for ( int j = 0; j < 18 ; j++)
                {
                printf(" %d ", tablero[j]);
                }

    // SE PIDE LA CANTIDAD DE FICHAS A APOSTAR EN EL COLOR ELEGIDO
    printf("\n elegi cantidad de fichas a apostar en los numeros par : \n");
    scanf("%d", &cantidadFichas);

    // SE PIDE EL VALOR DE LA FICHA A APOSTAR
    printf("elegi ficha : \n");
    for(int k = 0; k < 5;k++){
        printf("%d ficha : %d \n",k, fichas[k]);
    }
    scanf("%d", &numeroFicha);

    // SE VALIDA QUE LA FICHA ELEGIDA ESTE DENTRO DEL RANGO DE LAS FICHAS DISPONIBLES
    while(numeroFicha > 4 || numeroFicha < 0){

        printf("ficha invalida : \n");
        printf("elegi ficha : \n");

        for(int k = 0; k < 5;k++){
            printf("%d ficha : %d \n",k, fichas[k]);
        }
            scanf("%d", &numeroFicha);
    }

    int contador = 0;
    int fichasElegidas[4] = {0,0,0,0};
    fichasElegidas[contador] = fichas[numeroFicha];
    contador += 1;

    int seguir = 0;
    for(int i = 0; i < 4; i++){

        if(fichas[numeroFicha] == fichasElegidas[i]){

            seguir += 1;
        }
    }

    if(seguir == 2)
        printf("numero de ficha ya elegido,no es posible volver a apostar el mismo dinero otra vez \n");

    if( seguir == 1 ){
    // SI EL COLOR ELEGIDO YA CUENTA CON FICHAS APOSTADAS,SE LE SUMAN LAS NUEVAS FICHAS A APOSTAR

    apuestasAcumuladas = apuestasAcumuladas + (fichas[numeroFicha] * cantidadFichas);
    }

    seguir = 0;

    // SE PREGUNTA SI DESEA SEGUIR APOSTANDO FICHAS EN OTRAS CASILLAS-----------------------------------------------------+
    printf("seguir apostando fichas ? 1 : si  0 : no \n");
    scanf("%d", &seguirApostando);


    // SE VALIDA LA OPCION ELEGIDA
    while(seguirApostando > 1 || seguirApostando < 0){
        printf("opcion invalida \n");
        printf("seguir apostando fichas ? 1 : si  0 : no \n");
        scanf("%d", &seguirApostando);
    }

    //SI LA RESPUESTA ES 1 (SI),SE SIGUE CON LAS APUESTAS DE FICHAS
    if(seguirApostando == 1){
        rueda8 ( tablero[COLUMNAS2],colorBinario,tableroCompleto );
    }
    // SI LA RESPUESTA ES 0 (NO), SE TERMINA LA RONDA Y SE PROCEDE A LANZAR LA BOLILLA-------------------------------------+
    if(seguirApostando == 0){
        break;
    }
    }
    // NUMERO ALEATORIO DE LA BOLILLA
    bolilla = 1 + rand() % 36;
    printf("numero de BOLILLA : %d \n", bolilla);

    // SE VALIDA SI LA CASILLA ELEGIDA COINCIDE CON EL NUMERO DE BOLILLA

            // SI COINCIDEN LOS NUMEROS , SE AGREGA LA GANANCIA AL USUARIO,Y LA PERDIDA AL CASINO
    int contador = 0;

        for( int j = 0; j < COLUMNAS2;j++ ){
            if( tablero[j] == bolilla ){

                sumaUsuario += apuestasAcumuladas * 2;
                sumaCasino -= apuestasAcumuladas * 2 ;
                contador += 1;
                }
                }

    if (contador == 0 ){
    sumaCasino += apuestasAcumuladas * 2;
    sumaUsuario -= sumaCasino ;
    }

    contador = 0;

     if ( bolilla == 2 || bolilla == 3 || bolilla == 5 || bolilla == 7 || bolilla == 11 || bolilla == 13 || bolilla == 17 || bolilla == 19 || bolilla == 23 || bolilla == 29 || bolilla == 31  )
    veces_que_sale_en_numero_primo += 1;

    for (int i = 0; i < FILAS ;i++){
    for (int j = 0; j < COLUMNAS ;j++){

     if (bolilla == tableroCompleto[i][j]){
        if ( colorBinario [i][j] == 1 ){
            color_consecutivo_rojo += 1;
            }else{
            color_consecutivo_negro -= 1;
        }
    }
    }
    }

    sumatoria = apuestasAcumuladas*2;
    // SE RETORNA EL RESULTADO DE LA APUESTA,PARA DETERMINAR SI ES GANANCIA O PERDIDA
    printf("resultado de la apuesta  : %d \n ", sumatoria);
    //sumaUsuario += (-1 * sumatoria);
    //sumaCasino += (-1 * sumatoria);
    printf("dinero acumulado del usuario : %d \n", sumaUsuario);
    printf("dinero acumulado del casino : %d \n", sumaCasino);

    return sumaCasino;
}


int rueda9 ( int tablero [COLUMNAS2] , int colorBinario[][COLUMNAS], int tableroCompleto[][COLUMNAS] )
{
    srand(time(NULL));
    // VARIABLES
    int resultado = 2; // VALOR QUE SE PAGA POR CADA UNIDAD APOSTADA
    int bolilla; // NUMERO ALEATORIO
    int seguirApostando = 1;
    int cantidadFichas;
    int numeroFicha;
    int sumatoria = 0; // acumula el resultado final de las apuestas a casilllas
    int apuestasAcumuladas = 0;
    int rondasJugadas = 1;

    while ( seguirApostando == 1 )
    {
        printf("\n tablero de impares \n");
            for ( int j = 0; j < 18 ; j++)
                {
                printf(" %d ", tablero[j]);
                }

    // SE PIDE LA CANTIDAD DE FICHAS A APOSTAR EN EL COLOR ELEGIDO
    printf("\n elegi cantidad de fichas a apostar en los impares : \n");
    scanf("%d", &cantidadFichas);

    // SE PIDE EL VALOR DE LA FICHA A APOSTAR
    printf("elegi ficha : \n");
    for(int k = 0; k < 5;k++){
        printf("%d ficha : %d \n",k, fichas[k]);
    }
    scanf("%d", &numeroFicha);

    // SE VALIDA QUE LA FICHA ELEGIDA ESTE DENTRO DEL RANGO DE LAS FICHAS DISPONIBLES
    while(numeroFicha > 4 || numeroFicha < 0){

        printf("ficha invalida : \n");
        printf("elegi ficha : \n");

        for(int k = 0; k < 5;k++){
            printf("%d ficha : %d \n",k, fichas[k]);
        }
            scanf("%d", &numeroFicha);
    }

    int contador = 0;
    int fichasElegidas[4] = {0,0,0,0};
    fichasElegidas[contador] = fichas[numeroFicha];
    contador += 1;

    int seguir = 0;
    for(int i = 0; i < 4; i++){

        if(fichas[numeroFicha] == fichasElegidas[i]){

            seguir += 1;
        }
    }

    if(seguir == 2)
        printf("numero de ficha ya elegido,no es posible volver a apostar el mismo dinero otra vez \n");

    if( seguir == 1 ){
    // SI EL COLOR ELEGIDO YA CUENTA CON FICHAS APOSTADAS,SE LE SUMAN LAS NUEVAS FICHAS A APOSTAR

    apuestasAcumuladas = apuestasAcumuladas + (fichas[numeroFicha] * cantidadFichas);
    }

    seguir = 0;

    // SE PREGUNTA SI DESEA SEGUIR APOSTANDO FICHAS EN OTRAS CASILLAS-----------------------------------------------------+
    printf("seguir apostando fichas ? 1 : si  0 : no \n");
    scanf("%d", &seguirApostando);


    // SE VALIDA LA OPCION ELEGIDA
    while(seguirApostando > 1 || seguirApostando < 0){
        printf("opcion invalida \n");
        printf("seguir apostando fichas ? 1 : si  0 : no \n");
        scanf("%d", &seguirApostando);
    }

    //SI LA RESPUESTA ES 1 (SI),SE SIGUE CON LAS APUESTAS DE FICHAS
    if(seguirApostando == 1){
        rueda9 ( tablero[COLUMNAS2],colorBinario,tableroCompleto );
    }
    // SI LA RESPUESTA ES 0 (NO), SE TERMINA LA RONDA Y SE PROCEDE A LANZAR LA BOLILLA-------------------------------------+
    if(seguirApostando == 0){
        break;
    }
    }
    // NUMERO ALEATORIO DE LA BOLILLA
    bolilla = 1 + rand() % 36;
    printf("numero de BOLILLA : %d \n", bolilla);

    // SE VALIDA SI LA CASILLA ELEGIDA COINCIDE CON EL NUMERO DE BOLILLA

            // SI COINCIDEN LOS NUMEROS , SE AGREGA LA GANANCIA AL USUARIO,Y LA PERDIDA AL CASINO
    int contador = 0;

        for( int j = 0; j < COLUMNAS2;j++ ){
            if( tablero[j] == bolilla ){

                sumaUsuario += apuestasAcumuladas * 2;
                sumaCasino -= apuestasAcumuladas * 2 ;
                contador += 1;
                }
                }

    if (contador == 0 ){
    sumaCasino += apuestasAcumuladas * 2;
    sumaUsuario -= sumaCasino ;
    }

    contador = 0;

     if ( bolilla == 2 || bolilla == 3 || bolilla == 5 || bolilla == 7 || bolilla == 11 || bolilla == 13 || bolilla == 17 || bolilla == 19 || bolilla == 23 || bolilla == 29 || bolilla == 31  )
    veces_que_sale_en_numero_primo += 1;

    for (int i = 0; i < FILAS ;i++){
    for (int j = 0; j < COLUMNAS ;j++){

     if (bolilla == tableroCompleto[i][j]){
        if ( colorBinario [i][j] == 1 ){
            color_consecutivo_rojo += 1;
            }else{
            color_consecutivo_negro -= 1;
        }
    }
    }
    }

    sumatoria = apuestasAcumuladas*2;
    // SE RETORNA EL RESULTADO DE LA APUESTA,PARA DETERMINAR SI ES GANANCIA O PERDIDA
    printf("resultado de la apuesta  : %d \n ", sumatoria);
    //sumaUsuario += (-1 * sumatoria);
    //sumaCasino += (-1 * sumatoria);
    printf("dinero acumulado del usuario : %d \n", sumaUsuario);
    printf("dinero acumulado del casino : %d \n", sumaCasino);

    return sumaCasino;
}


int rueda10 (int tablero[COLUMNAS], int colorBinario[][COLUMNAS] ,int tableroCompleto[][COLUMNAS] ){

    srand(time(NULL));

    // VARIABLES

    int resultado = 3; // VALOR QUE SE PAGA POR CADA UNIDAD APOSTADA
    int bolilla; // NUMERO ALEATORIO
    int seguirApostando = 1;
    int cantidadFichas;
    int numeroFicha;
    int sumatoria = 0; // acumula el resultado final de las apuestas a casilllas
    int apuestasAcumuladas = 0;
    int rondasJugadas = 1;

    while ( seguirApostando == 1 ){

    // SE IMPRIME EL TABLERO ORIGINAL
    printf("tablero columna 1 \n");
    printf("\n");
   // printf("0    1    2    3     4     5     6     7     8     9     10    11\n");
    //printf("\n");
    for(int i = 0; i < 12;i++){
       // printf("-------------------------------------------------------------------- \n");
            printf("%d    ",tablero[i]);

        }

    printf("\n");
    printf("\n");

    // SE PIDE LA CANTIDAD DE FICHAS A APOSTAR EN LA CASILLA ELEGIDA
    printf("elegi cantidad de fichas a apostar en la columna 1 : \n");
    scanf("%d", &cantidadFichas);

    // SE PIDE EL VALOR DE LA FICHA A APOSTAR
    printf("elegi ficha : \n");
    for(int k = 0; k < 5;k++){
        printf("%d ficha : %d \n",k, fichas[k]);
    }
    scanf("%d", &numeroFicha);

    // SE VALIDA QUE LA FICHA ELEGIDA ESTE DENTRO DEL RANGO DE LAS FICHAS DISPONIBLES
    while(numeroFicha > 4 || numeroFicha < 0){
        printf("ficha invalida : \n");
        printf("elegi ficha : \n");
        for(int k = 0; k < 5;k++){
            printf("%d ficha : %d \n",k, fichas[k]);
        }
            scanf("%d", &numeroFicha);
    }

    apuestasAcumuladas += cantidadFichas * fichas[numeroFicha];

    printf("desea seguir apostando ? \n");
    printf("1 : continuar 0: no continuar \n");
    scanf("%d", &seguirApostando);

    while(seguirApostando > 1 || seguirApostando < 0){

        printf("desea seguir apostando ? \n");
        printf("1 : continuar 0: no continuar \n");
        scanf("%d", &seguirApostando);

    }

    if(seguirApostando == 1){

        rueda10 (tablero,colorBinario,tableroCompleto);

    }else{

        break;
    }
    }

    bolilla = 1 + rand() % 36;
    printf("numero de BOLILLA : %d \n", bolilla);

    for(int i = 0; i < COLUMNAS;i++){

        if( bolilla == tablero[i] ){
            sumatoria += apuestasAcumuladas * 3;

        }else{
            sumatoria += apuestasAcumuladas * (-3);
    }
    }

     if ( bolilla == 2 || bolilla == 3 || bolilla == 5 || bolilla == 7 || bolilla == 11 || bolilla == 13 || bolilla == 17 || bolilla == 19 || bolilla == 23 || bolilla == 29 || bolilla == 31  )
    veces_que_sale_en_numero_primo += 1;


    for (int i = 0; i < FILAS ;i++){
    for (int j = 0; j < COLUMNAS ;j++){

     if (bolilla == tableroCompleto[i][j]){
        if ( colorBinario [i][j] == 1 ){
            color_consecutivo_rojo += 1;
            }else{
            color_consecutivo_negro -= 1;
        }
    }
    }
    }

    // SE RETORNA EL RESULTADO DE LA APUESTA,PARA DETERMINAR SI ES GANANCIA O PERDIDA
    printf("resultado de la apuesta  : %d \n ", sumatoria);
    sumaUsuario += sumatoria;
    sumaCasino += (-1 * sumatoria);
    printf("dinero acumulado del usuario : %d \n", sumaUsuario);
    printf("dinero acumulado del casino : %d \n", sumaCasino);

    return sumaCasino;

}


int rueda11 (int tablero[COLUMNAS], int colorBinario[][COLUMNAS], int tableroCompleto[][COLUMNAS] ){

    srand(time(NULL));

    // VARIABLES

    int resultado = 3; // VALOR QUE SE PAGA POR CADA UNIDAD APOSTADA
    int bolilla; // NUMERO ALEATORIO
    int seguirApostando = 1;
    int cantidadFichas;
    int numeroFicha;
    int sumatoria = 0; // acumula el resultado final de las apuestas a casilllas
    int apuestasAcumuladas = 0;
    int rondasJugadas = 1;

    while ( seguirApostando == 1 ){

    // SE IMPRIME EL TABLERO ORIGINAL
    printf("tablero columna 2 \n");
    printf("\n");
   // printf("0    1    2    3     4     5     6     7     8     9     10    11\n");
    //printf("\n");
    for(int i = 0; i < 12;i++){
       // printf("-------------------------------------------------------------------- \n");
            printf("%d    ",tablero[i]);

        }

    printf("\n");
    printf("\n");

    // SE PIDE LA CANTIDAD DE FICHAS A APOSTAR EN LA CASILLA ELEGIDA
    printf("elegi cantidad de fichas a apostar en la columna 2 : \n");
    scanf("%d", &cantidadFichas);

    // SE PIDE EL VALOR DE LA FICHA A APOSTAR
    printf("elegi ficha : \n");
    for(int k = 0; k < 5;k++){
        printf("%d ficha : %d \n",k, fichas[k]);
    }
    scanf("%d", &numeroFicha);

    // SE VALIDA QUE LA FICHA ELEGIDA ESTE DENTRO DEL RANGO DE LAS FICHAS DISPONIBLES
    while(numeroFicha > 4 || numeroFicha < 0){
        printf("ficha invalida : \n");
        printf("elegi ficha : \n");
        for(int k = 0; k < 5;k++){
            printf("%d ficha : %d \n",k, fichas[k]);
        }
            scanf("%d", &numeroFicha);
    }

    apuestasAcumuladas += cantidadFichas * fichas[numeroFicha];

    printf("desea seguir apostando ? \n");
    printf("1 : continuar 0: no continuar \n");
    scanf("%d", &seguirApostando);

    while(seguirApostando > 1 || seguirApostando < 0){

        printf("desea seguir apostando ? \n");
        printf("1 : continuar 0: no continuar \n");
        scanf("%d", &seguirApostando);

    }

    if(seguirApostando == 1){

        rueda11 (tablero,colorBinario,tableroCompleto);

    }else{

        break;
    }
    }

    bolilla = 1 + rand() % 36;
    printf("numero de BOLILLA : %d \n", bolilla);

    for(int i = 0; i < COLUMNAS;i++){

        if( bolilla == tablero[i] ){
            sumatoria += apuestasAcumuladas * 3;

        }else{
            sumatoria += apuestasAcumuladas * (-3);
    }
    }

     if ( bolilla == 2 || bolilla == 3 || bolilla == 5 || bolilla == 7 || bolilla == 11 || bolilla == 13 || bolilla == 17 || bolilla == 19 || bolilla == 23 || bolilla == 29 || bolilla == 31  )
     veces_que_sale_en_numero_primo += 1;

    for (int i = 0; i < FILAS ;i++){
    for (int j = 0; j < COLUMNAS ;j++){

     if (bolilla == tableroCompleto[i][j]){
        if ( colorBinario [i][j] == 1 ){
            color_consecutivo_rojo += 1;
            }else{
            color_consecutivo_negro -= 1;
        }
    }
    }
    }
    // SE RETORNA EL RESULTADO DE LA APUESTA,PARA DETERMINAR SI ES GANANCIA O PERDIDA
    printf("resultado de la apuesta  : %d \n ", sumatoria);
    sumaUsuario += sumatoria;
    sumaCasino += (-1 * sumatoria);
    printf("dinero acumulado del usuario : %d \n", sumaUsuario);
    printf("dinero acumulado del casino : %d \n", sumaCasino);

    return sumaCasino;

}


int rueda12 (int tablero[COLUMNAS] , int colorBinario[][COLUMNAS], int tableroCompleto[][COLUMNAS] ){

    srand(time(NULL));

    // VARIABLES

    int resultado = 3; // VALOR QUE SE PAGA POR CADA UNIDAD APOSTADA
    int bolilla; // NUMERO ALEATORIO
    int seguirApostando = 1;
    int cantidadFichas;
    int numeroFicha;
    int sumatoria = 0; // acumula el resultado final de las apuestas a casilllas
    int apuestasAcumuladas = 0;
    int rondasJugadas = 1;

    while ( seguirApostando == 1 ){

    // SE IMPRIME EL TABLERO ORIGINAL
    printf("tablero columna 3 \n");
    printf("\n");
   // printf("0    1    2    3     4     5     6     7     8     9     10    11\n");
    //printf("\n");
    for(int i = 0; i < 12;i++){
       // printf("-------------------------------------------------------------------- \n");
            printf("%d    ",tablero[i]);

        }

    printf("\n");
    printf("\n");

    // SE PIDE LA CANTIDAD DE FICHAS A APOSTAR EN LA CASILLA ELEGIDA
    printf("elegi cantidad de fichas a apostar en la columna 3 : \n");
    scanf("%d", &cantidadFichas);

    // SE PIDE EL VALOR DE LA FICHA A APOSTAR
    printf("elegi ficha : \n");
    for(int k = 0; k < 5;k++){
        printf("%d ficha : %d \n",k, fichas[k]);
    }
    scanf("%d", &numeroFicha);

    // SE VALIDA QUE LA FICHA ELEGIDA ESTE DENTRO DEL RANGO DE LAS FICHAS DISPONIBLES
    while(numeroFicha > 4 || numeroFicha < 0){
        printf("ficha invalida : \n");
        printf("elegi ficha : \n");
        for(int k = 0; k < 5;k++){
            printf("%d ficha : %d \n",k, fichas[k]);
        }
            scanf("%d", &numeroFicha);
    }

    apuestasAcumuladas += cantidadFichas * fichas[numeroFicha];

    printf("desea seguir apostando ? \n");
    printf("1 : continuar 0: no continuar \n");
    scanf("%d", &seguirApostando);

    while(seguirApostando > 1 || seguirApostando < 0){

        printf("desea seguir apostando ? \n");
        printf("1 : continuar 0: no continuar \n");
        scanf("%d", &seguirApostando);

    }

    if(seguirApostando == 1){

        rueda12(tablero,colorBinario, tableroCompleto);

    }else{

        break;
    }
    }

    bolilla = 1 + rand() % 36;
    printf("numero de BOLILLA : %d \n", bolilla);

    for(int i = 0; i < COLUMNAS;i++){

        if( bolilla == tablero[i] ){
            sumatoria += apuestasAcumuladas * 3;
        }else{
            sumatoria += apuestasAcumuladas * (-3);
    }
    }

    if ( bolilla == 2 || bolilla == 3 || bolilla == 5 || bolilla == 7 || bolilla == 11 || bolilla == 13 || bolilla == 17 || bolilla == 19 || bolilla == 23 || bolilla == 29 || bolilla == 31  )
    veces_que_sale_en_numero_primo += 1;

    for (int i = 0; i < FILAS ;i++){
    for (int j = 0; j < COLUMNAS ;j++){

     if (bolilla == tableroCompleto[i][j]){
        if ( colorBinario [i][j] == 1 ){
            color_consecutivo_rojo += 1;
            }else{
            color_consecutivo_negro -= 1;
        }
    }
    }
    }

    // SE RETORNA EL RESULTADO DE LA APUESTA,PARA DETERMINAR SI ES GANANCIA O PERDIDA
    printf("resultado de la apuesta  : %d \n ", sumatoria);
    sumaUsuario += sumatoria;
    sumaCasino += (-1 * sumatoria);
    printf("dinero acumulado del usuario : %d \n", sumaUsuario);
    printf("dinero acumulado del casino : %d \n", sumaCasino);

    return sumaCasino;

}

