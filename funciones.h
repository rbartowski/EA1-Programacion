/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//* CUALQUIER MODIFICACI�N QUE HAGA NO SER� TENIDA EN CUENTA.      *//**/
/**//**//* S�LO PARA QUE CAMBIE LAS CANTIDADES DE FILAS Y COLUMNAS        *//**/
/**//**//* DURANTE SUS PRUEBAS      *//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/


#ifndef FUNCIONES_H_
#define FUNCIONES_H_

#include <stdio.h>


/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/** para el PUNTO_1 **/
#define ARCH_PUNTO_1        "datos.txt"

#define TAM_PAL_MAX     20
#define CANT_PAL_MAX    20


void crearDatosPunto1(const char *nomArch, int nroDeLote);

void procesarArchivo(FILE *fpEnt, FILE *fpPantalla);

/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/** para el PUNTO_2 **/
#define N_FILAS         15
#define M_COLUM         15

int crearMat(int mat[][M_COLUM], int filas, int colum);

int mostrarMat(int mat[][M_COLUM], int filas, int colum, FILE *fpPantalla);

int traspRespAlCentro(int mat[][M_COLUM], int filas, int colum);

int mostrarTriangSup(int mat[][M_COLUM], int filas, int colum,
                     FILE *fpPantalla);


/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//* FUNCIONES A DESARROLLAR                                            *//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/** funci�n que determina si su argumento es un d�gito, una letra may�scula o
 **     min�scula acentuada o no, u con di�resis (� / �), o � / �
 **/
int esLetraODigito_MIO(char c);

/** funci�n que busca el comienzo de una palabra desde la direcci�n que recibe
 **/
char *proxPal_MIO(const char *s);

/** funci�n que busca el car�cter que est� a continuaci�n de una palabra
 **/
char *finPal_MIO(const char *s);

/** funci�n que determina el tama�o de una palabra (su cantidad de car�cteres)
 **/
size_t tamPal_MIO(const char *ini, const char *fin);


/** funci�n que copia una cadena de caracteres, recibe la cantidad de caracteres
 **     a copiar adem�s de el espacio posible a utilizar
 **     para de copiar cuando se cumpla una de las dos cosas
 **/
char *copiarPal_MIO(char *dest, const char *orig, size_t tam, int tope);

/** funci�n que lee el archivo que recibe (�ya abierto?) por argumento y hace
 **     las determinaciones pedidas
 **/
void procesarArchivo_MIO(FILE *fpEnt, FILE *fpPantalla);


/** funci�n que intercambia los elementos de la matriz respecto al centro
 **/
int traspRespAlCentro_MIO(int mat[][M_COLUM], int filas, int colum);

/** funci�n que muestra la triangular superior de la matriz
 **/
int mostrarTriangSup_MIO(int mat[][M_COLUM], int filas, int colum,
                         FILE *fpPantalla);

/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/



#endif // FUNCIONES_H_

