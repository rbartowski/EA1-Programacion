/**//* 33.906.317-RODRIGUEZ,Ramiro-(06-2961) *//**/
/**//*          AC� DEBE INDICAR SU N�MERO DE DNI, APELLIDO(S) Y          *//**/
/**//*          NOMBRE(S) COMPLETOS Y COMISI�N TAL COMO SE INDICA         *//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//* CUALQUIER INCLUDE DE BIBLIOTECA QUE NECESITE, H�GALO DESDE AC� *//**/


/**//**//* CUALQUIER INCLUDE DE BIBLIOTECA QUE NECESITE, H�GALO HASTA AC� *//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
#include "funciones.h"
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//* AC� DEBE DESARROLLAR LAS FUNCIONES Y PRIMITIVAS PEDIDAS    *//**//**/
/**//**//* ADEM�S DE CUALQUIER OTRA FUNCI�N QUE SE REQUIERA           *//**//**/

#define TAM_LINEA 199

int esCaracterEspecial(char c)
{
    char caracteresEspeciales[] = {'�', '�', '�', '�', '�', '�', '�', '�', '�',
        '�', '�', '�', '�', '�'};
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

void imprimirResultados(FILE * fp,
                        const char palabras[CANT_PAL_MAX][TAM_PAL_MAX],
                        int cantLineasVacias,
                        int cantLineas,
                        int cantPalabras,
                        int cantPalabrasMayores,
                        int mayorLongitud)
{
    int tope = mayorLongitud > TAM_PAL_MAX ? TAM_PAL_MAX : mayorLongitud;

    fprintf(fp, "El archivo tiene un total de %d l�nea(s) de texto.",
            cantLineas);
    fprintf(fp, "\nHay %d l�nea(s) sin palabras.", cantLineasVacias);
    fprintf(fp, "\nHay un total de %d palabra(s).", cantPalabras);
    fprintf(fp, "\nLa palabra m�s larga tiene %d caracteres.", mayorLongitud);
    fprintf(fp, "\nHay %d palabra(s) con esa cantidad de caracteres",
           cantPalabrasMayores);

    if (cantPalabrasMayores)
        fprintf(fp, "\nSe muestra(n) la(s) %d palabra(s) m�s larga(s)",
        cantPalabrasMayores);
    else
        fprintf(fp, "\nSe muestra(n) la(s) %d palabra(s) m�s larga(s)\n",
        cantPalabrasMayores);

    for(int j = 0; j < cantPalabrasMayores; j++)
    {
        if (j < 9)
            fprintf(fp, "\n %d - ", j + 1);
        else
            fprintf(fp, "\n%d - ", j + 1);

        for(int k = 0; k < tope; k++)
        {
            if (j == cantPalabrasMayores - 1 && k == tope - 1)
                fprintf(fp, "%c\n", palabras[j][k]);
            else
                fprintf(fp, "%c", palabras[j][k]);
        }
    }
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

    if (!fpEnt) {
        fprintf(fpPantalla, "ERROR - El archivo no existe\n");
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
                                                  tam,
                                                  TAM_PAL_MAX);
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
    }

    if (cantLineas)
    {
        imprimirResultados(fpPantalla,
                           palabrasMayores,
                           cantLineasVacias,
                           cantLineas,
                           cantPalabras,
                           cantPalabrasMayores,
                           mayorLongitud);
    }
    else
    {
        fprintf(fpPantalla, "El archivo est� vac�o\n");
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

