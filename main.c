#include <stdio.h>
#include <stdlib.h>
#include "matrices.h"
#include "funciones.h"

int main()
{
    // VARIABLES
    int c = 0;
    int i = 0;
    int d = 1;
    int apuesta;
    int rondas;
    int acumuladoCasino = 0;
    //int acumuladoUsuario = 0;

    int apuestas_jugadas = 0;

    // SE IMPRIME BIENVENIDA Y SE PREGUNTA CUANTAS RONDAS SE DESEA JUGAR
    printf("bienvenido a la ruleta europea ! \n");
    printf("cuantas rondas desea jugar ? (maximo 20) \n");

    // SE GUARDA LA CANTIDAD DE RONDAS A JUGAR
    scanf("%d", &rondas);

    //SE INICIA EL BUCLE,DE ACUERDO A LA CANTIDAD DE RONDAS A JUGAR
    while(c < rondas){

    // SE IMPRIME QUE RONDA SE ESTA JUGANDO
        printf("ronda numero : %d \n", c);

    // BUCLE QUE ITERA HASTA LLEGAR A LA APUESTA NUMERO 10
    while(d <= 10 ){

    // SE AVISA QUE SE ESTAN TERMINANDO LA CANTIDAD DE APUESTAS A JUGAR
    if(d >= 7){
        printf("solo quedan %d apuestas a jugar... \n", 10-d );
    }
        //SE IMPRIME EN QUE NUMERO DE APUESTA SE ESTA JUGANDO
        printf("apuesta numero : %d \n",d);

    // SE MUESTRAN LOS TIPOS DE TABLEROS A ELEGIR
    printf("elegi la apuesta : \n 1 pleno \n 2 color \n 3 docena1 \n 4 docena2 \n 5 docena3 \n 6 falta \n 7 pasa \n 8 pares \n 9 impares \n 10 columna1 \n 11 columna2 \n 12 columna3 \n 13 pasar de ronda \n");
    scanf("%d", &apuesta);

    // SE INVOCA LA FUNCION CORRESPONDIENTE A CADA TABLERO Y SE LE PASA DE ARGUMENTO EL TABLERO ELEGIDO
    switch(apuesta){

    case 1 :
       apuestas_jugadas++;
       printf("\n usted eligio apostar al pleno \n");
       acumuladoCasino += rueda1(pleno,tableroBinario1,colorBinario);
       printf("resultado acumulado del casino : %d \n", acumuladoCasino);
       break;

    case 2 :
        apuestas_jugadas++;
        printf("\n usted eligio apostar al color \n");
        acumuladoCasino += rueda2(pleno,color,colorBinario);
        printf("resultado acumulado del casino : %d \n", acumuladoCasino);
        break;

    case 3 :
        apuestas_jugadas++;
        printf("\n usted eligio la apuesta a la primera docena \n");
        acumuladoCasino += rueda3(docena1,colorBinario,pleno);
        break;

    case 4 :
        apuestas_jugadas++;
        printf("\n usted eligio la apuesta a la segunda docena \n");
        acumuladoCasino += rueda4(docena2,colorBinario,pleno);
        break;

    case 5 :
        apuestas_jugadas++;
        printf("\n usted eligio la apuesta a los terceros doce \n");
        acumuladoCasino += rueda5(docena3,colorBinario,pleno);
        break;

    case 6 :
        apuestas_jugadas++;
        printf("\n usted eligio apostar a la falta \n");
        acumuladoCasino += rueda6 (falta,colorBinario,pleno);
        break;

    case 7 :
        apuestas_jugadas++;
        printf("\n usted eligio apostar a la pasa \n");
        acumuladoCasino += rueda7 (pasa,colorBinario,pleno);
        break;

    case 8 :
        apuestas_jugadas++;
        printf("\n usted eligio apostar a los pares \n");
        acumuladoCasino += rueda8 (pares,colorBinario,pleno);
        break;

    case 9 :
        apuestas_jugadas++;
        printf("\n usted eligio apostar a los impares \n");
        acumuladoCasino += rueda9 (impares,colorBinario,pleno );
        break;

    case 10 :
        apuestas_jugadas++;
        printf("\n usted eligio apostar a la columna 1 \n");
        acumuladoCasino += rueda10 (columna1,colorBinario,pleno );
        break;

    case 11 :
        apuestas_jugadas++;
        printf("\n usted eligio apostar a la columna 2 \n");
        acumuladoCasino += rueda11 (columna2,colorBinario,pleno );
        break;

    case 12 :
        apuestas_jugadas++;
        printf("\n usted eligio apostar a la columna 3 \n");
        acumuladoCasino += rueda12 ( columna3, colorBinario,pleno );
        break;

    case 13 :
        printf("pasa de ronda \n");
        break;


   // printf("acumulado : %d \n", acumulado);

    }
    d++;
    }
    c++;
    }





    if(acumuladoCasino > sumaUsuario){
        printf("mesa ganadora !! \n");
    }else if(acumuladoCasino == sumaUsuario ){
        printf("mesa no conforme \n");
    }else{
        printf("mesa perdedora \n");
    }

    // ESTADISTICAS --------------------------------------------------------------------

    printf("estadisticas : \n");

    int apuestas_jugadas_por_ronda = apuestas_jugadas / rondas;
    printf("promedio de apuestas jugadas por ronda : %d \n", apuestas_jugadas_por_ronda);

    if (color_consecutivo_rojo > 5 ){
        printf("la bola callo mas de 5 veces consecutivas en colores rojos \n");
    }

    if (color_consecutivo_negro < -5 ){
        printf("la bola callo mas de 5 veces consecutivas en colores negros \n");
    }

    printf("veces que la bola cayo en un numero primo : %d \n", veces_que_sale_en_numero_primo);




  // printf("%d", pleno[0][10]);
    return 0;
}
