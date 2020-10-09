/**//* 33.906.317-RODRIGUEZ,Ramiro-(06-2961) *//**/
/**//*          ACÁ DEBE INDICAR SU NÚMERO DE DNI, APELLIDO(S) Y          *//**/
/**//*          NOMBRE(S) COMPLETOS Y COMISIÓN TAL COMO SE INDICA         *//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//* CUALQUIER INCLUDE DE BIBLIOTECA QUE NECESITE, HÁGALO DESDE ACÁ *//**/


/**//**//* CUALQUIER INCLUDE DE BIBLIOTECA QUE NECESITE, HÁGALO HASTA ACÁ *//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
#include "funciones.h"
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//* ACÁ DEBE DESARROLLAR LAS FUNCIONES Y PRIMITIVAS PEDIDAS    *//**//**/
/**//**//* ADEMÁS DE CUALQUIER OTRA FUNCIÓN QUE SE REQUIERA           *//**//**/

#define TAM_LINEA 199

int esCaracterEspecial(char c)
{
    char caracteresEspeciales[] = {'á', 'Á', 'é', 'É', 'í', 'Í', 'ó', 'Ó', 'ú',
        'Ú', 'ü', 'Ü', 'ñ', 'Ñ'};
    int esEspecial = 0;
    char * i = caracteresEspeciales;
    char * finArray = &caracteresEspeciales[sizeof(caracteresEspeciales)
                                            / sizeof(char)];

    while (i < finArray && !esEspecial) {
        if (*i == c) {
            esEspecial = 1;
        }
        i++;
    }

    return esEspecial;
}

int esLetraODigito_MIO(char c)
{
    return (c >= '0' && c <= '9')
        || (c >= 'A' && c <= 'Z')
        || (c >= 'a' && c <= 'z')
        || esCaracterEspecial(c);
}

char * proxPal_MIO(const char *s)
{
    while(!esLetraODigito_MIO(*s) && *s != '\n') {
        s++;
    }

    return *s != '\n' ? (char *)s : NULL;
}

char * finPal_MIO(const char *s)
{
    while(esLetraODigito_MIO(*s)) {
        s++;
    }

    return (char*)s;
}

size_t tamPal_MIO(const char *ini, const char *fin)
{
    return fin - ini;
}

char * copiarPal_MIO(char * dest, const char * orig, size_t tam, int tope)
{
    const char * principioPalabra = orig;
    while(tam > 0 && (orig - principioPalabra) < tope) {
        *dest = *orig;
        dest++;
        orig++;
        tam--;
    }
    return dest;
}

char * finDeLinea(const char * s)
{
    while(*s != '\n') {
        s++;
    }

    return (char *)s;
}

void limpiarMayores(char m[CANT_PAL_MAX][TAM_PAL_MAX])
{
    for (int i = 0; i < CANT_PAL_MAX; i++)
    {
        for (int j = 0; j < TAM_PAL_MAX; j++)
        {
            m[i][j] = 0;
        }
    }
}

int esLineaVacia(const char * s)
{
    int i = 0;
    while(!esLetraODigito_MIO(*s) && *s != '\n' && i < TAM_LINEA) {
        i++;
        s++;
    }

    return !esLetraODigito_MIO(*s);
}

void procesarArchivo_MIO(FILE *fpEnt, FILE *fpPantalla)
{
    char linea[TAM_LINEA] = "",
         palabrasMayores[CANT_PAL_MAX][TAM_PAL_MAX];
    char * pAMayores;
    int cantPalabrasMayores = 0,
        cantLineas = 0,
        cantLineasVacias = 0,
        cantPalabras = 0,
        mayorLongitud = 0;

    if (!fpEnt || !fpPantalla) {
        printf("ERROR - El archivo no existe");
        return;
    }

    while(fgets(linea, sizeof(linea), fpEnt)) {
        char * origenLinea = linea;
        cantLineas++;

        if (esLineaVacia(linea)) {
            cantLineasVacias++;
        }
        else {
            while(*origenLinea != '\n')
            {
                char * inicioPal = proxPal_MIO(origenLinea);
                char * finPalActual;
                int tam;

                if (inicioPal)
                {
                    finPalActual = finPal_MIO(inicioPal);
                    tam = tamPal_MIO(inicioPal, finPalActual);

                    cantPalabras++;

                    if (tam > mayorLongitud)
                    {
                        if (cantPalabrasMayores > 0)
                            limpiarMayores(palabrasMayores);

                        mayorLongitud = tam;
                        cantPalabrasMayores = 1;
                        pAMayores = copiarPal_MIO(palabrasMayores[0],
                                                  inicioPal,
                                                  tam, TAM_PAL_MAX);
                    }
                    else if (tam == mayorLongitud &&
                             cantPalabrasMayores < CANT_PAL_MAX)
                    {
                        pAMayores = copiarPal_MIO(
                                        palabrasMayores[cantPalabrasMayores],
                                        inicioPal,
                                        tam, TAM_PAL_MAX);
                        cantPalabrasMayores++;
                    }

                    origenLinea = finPalActual;
                }
                else
                {
                    origenLinea = finDeLinea(linea);
                }
            }
        }
        fflush(stdin);
    }

    if (cantLineas)
    {
        printf("\nEl archivo tiene un total de %d l%cnea(s) de texto.",
           cantLineas, 161);
        printf("\nHay %d l%cnea(s) sin palabras.",
               cantLineasVacias, 161);
        printf("\nHay un total de %d palabra(s).",
               cantPalabras);
        printf("\nLa palabra m%cs larga tiene %d caracteres.",
               160, mayorLongitud);
        printf("\nHay %d palabra(s) con esa cantidad de caracteres",
               cantPalabrasMayores);
        printf("\nSe muestra(n) la(s) %d palabra(s) m%cs larga(s)",
               cantPalabrasMayores, 160);

        for(int j = 0; j < cantPalabrasMayores - 1; j++)
        {
            printf("\n%d - ", j + 1);
            for(int k = 0; k < TAM_PAL_MAX; k++)
            {
                printf("%c", palabrasMayores[j][k]);
            }

        }
    }
    else
    {
        printf("\nEl archivo est%c vac%co", 160, 161);
    }

}


/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//* FUNCIONES A DESARROLLAR                                            *//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**
int esLetraODigito_MIO(char c)
{

}

char *proxPal_MIO(const char *s)
{

}

char *finPal_MIO(const char *s)
{

}

size_t tamPal_MIO(const char *ini, const char *fin)
{

}

char *copiarPal_MIO(char *dest, const char *orig, size_t tam, int tope)
{

}

void procesarArchivo_MIO(FILE *fpEnt, FILE *fpPantalla)
{

}


int traspRespAlCentro_MIO(int mat[][M_COLUM], int filas, int colum)
{

}

int mostrarTriangSup_MIO(int mat[][M_COLUM], int filas, int colum,
                         FILE *fpPantalla)
{

}

 */
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/

