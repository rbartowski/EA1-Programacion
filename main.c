/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//* ACÁ NO DEBE HACER NINGUNA MODIFICACIÓN                         *//**/
/**//**//*      SÓLO PARA SUS PRUEBAS CON LOS DISTINTOS                   *//**/
/**//**//*      LOTES E INVOCAR ASUS FUNCIONES                            *//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/

#include "main.h"

int main()
{
    FILE   *fpPantalla = fopen("pantalla.txt", "wt");

    if(fpPantalla == NULL)
        fpPantalla = stdout;

    punto_1(fpPantalla);

    //punto_2(fpPantalla);

    fclose(fpPantalla);
    system("start Notepad " ARCH_PUNTO_1);
    system("start Notepad pantalla.txt");
    return 0;
}


/** pruebe su solución de   procesarDatosPunto1
 **     invocando a   crearDatosPunto1
 **     con los valores de 0 a 10 en su segundo argumento, y con cualquier
 **     otro valor (con lo que no habrá archivo de datos a procesar)
 **/
void punto_1(FILE *fpPantalla)
{
    FILE   *fpEnt;
    int     nroLote = 1;   /// pruebe con 0/1/2/3/4/5/6/7/8/9/10 y además con
                            ///     cualquier otro valor para tener distintos
                            ///     lotes de prueba

    fprintf(fpPantalla,
            "********************************************\n"
            "* PUNTO-1: Probando con lote de prueba %2d. *\n"
            "********************************************\n",
            nroLote);
    crearDatosPunto1(ARCH_PUNTO_1, nroLote);
    fpEnt = fopen(ARCH_PUNTO_1, "rt");

/** acá debe invocar a su versión de la función  >> procesarArchivo_MIO <<   **/
    procesarArchivo_MIO(fpEnt, fpPantalla);


    fclose(fpEnt);
    fprintf(fpPantalla,
            "********************************************\n"
            "*           Fin ejecución PUNTO-1          *\n"
            "********************************************\n\n");
}

/** pruebe su solución de   procesarDatosPunto1
 **     invocando a   crearDatosPunto1
 **     con los valores de 0 a 10 en su segundo argumento, y con cualquier
 **     otro valor (con lo que no habrá archivo de datos a procesar)
 **/
void punto_2(FILE *fpPantalla)
{
    int     matriz[N_FILAS][M_COLUM],
            cant;

    fprintf(fpPantalla,
            "********************************************\n"
            "* PUNTO-2: Probando con matriz de %2d x %2d. *\n"
            "********************************************\n",
            N_FILAS, M_COLUM);
    cant = crearMat(matriz, N_FILAS, M_COLUM);
    fprintf(fpPantalla, "Matriz creada con %d elementos.\n", cant);
    cant = mostrarMat(matriz, N_FILAS, M_COLUM, fpPantalla);
    fprintf(fpPantalla,
            "Se mostraron los %d elementos de la matriz.\n\n"
            "Se procede a trasponerla con respecto al centro.\n",
            cant);

/** acá debe invocar a su versión de la función  >> trasponerCentro_MIO <<   **/
    cant = traspRespAlCentro(matriz, N_FILAS, M_COLUM);

    fprintf(fpPantalla,
            "Se hicieron %d intercambios de los elementos de la matriz.\n"
            "Se procede a mostrarla.\n",
            cant);
    cant = mostrarMat(matriz, N_FILAS, M_COLUM, fpPantalla);
    fprintf(fpPantalla,
            "Se mostraron los %d elementos de la matriz.\n\n"
            "Se procede a mostrar la triangular superior.\n",
            cant);

/** acá debe invocar a su versión de la función  >> mostrarTriangSup_MIO <<  **/
    cant = mostrarTriangSup(matriz, N_FILAS, M_COLUM, fpPantalla);

    fprintf(fpPantalla,
            "Se mostraron los %d elementos de la triangular superior.\n",
            cant);
    fprintf(fpPantalla,
            "********************************************\n"
            "*           Fin ejecución PUNTO-2          *\n"
            "********************************************\n\n");
}

