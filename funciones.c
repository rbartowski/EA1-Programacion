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

/******************************************
****************  PUNTO 1 *****************
******************************************/

#define TAM_LINEA 199
#define TAM_PAL_MIO(X, Y) ((Y)-(X))

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
    int esLetraODig = esLetraODigito_MIO(*s);

    while(!esLetraODig && *s != '\n' && *s != '\0') {
        s++;
        esLetraODig = esLetraODigito_MIO(*s);
    }

    return esLetraODig ? (char *)s : NULL;
}

char * finPal_MIO(const char *s)
{
    while(esLetraODigito_MIO(*s)) {
        s++;
    }

    return (char*)s;
}

char * copiarPal_MIO(char * dest, const char * orig, size_t tam, int tope)
{
    const char * palabra = orig;
    int offset = 0;

    while(tam > 0 && offset < tope) {
        *dest = *palabra;
        dest++;
        palabra++;
        tam--;
        offset = palabra - orig;
    }

    return dest;
}

char * finDeLinea(const char * s)
{
    while(*s != '\n' && *s != '\0') {
        s++;
    }

    return (char *)s;
}

void imprimirResultados(FILE * fp,
                        const char palabras[CANT_PAL_MAX][TAM_PAL_MAX],
                        int cantLineasVacias,
                        int cantLineas,
                        int cantPalabras,
                        int cantPalabrasMayores,
                        int mayorLongitud)
{
    int topeRow = cantPalabrasMayores > CANT_PAL_MAX ? CANT_PAL_MAX :
        cantPalabrasMayores;
    char *aux = (char *)palabras[0];
    char * fin = (char *)&palabras[topeRow - 1];
    int i = 0;

    fprintf(fp, "El archivo tiene un total de %d línea(s) de texto.",
            cantLineas);
    fprintf(fp, "\nHay %d línea(s) sin palabras.", cantLineasVacias);
    fprintf(fp, "\nHay un total de %d palabra(s).", cantPalabras);
    fprintf(fp, "\nLa palabra más larga tiene %d caracteres.", mayorLongitud);
    fprintf(fp, "\nHay %d palabra(s) con esa cantidad de caracteres",
            cantPalabrasMayores);
    fprintf(fp, "\nSe muestra(n) la(s) %d palabra(s) más larga(s)\n",
                cantPalabrasMayores);

    while(aux < fin)
    {
        fprintf(fp,"%2d - %.*s\n",i + 1, mayorLongitud, aux);
        aux += TAM_PAL_MAX;
        i++;
    }
}

void procesarArchivo_MIO(FILE *fpEnt, FILE *fpPantalla)
{
    char palabrasMayores[CANT_PAL_MAX][TAM_PAL_MAX],
         linea[TAM_LINEA] = "";
    char * pAMayores,
         * origenLinea,
         * inicioPal;
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
        origenLinea = linea;
        cantLineas++;

        inicioPal = proxPal_MIO(origenLinea);

        if (!inicioPal)
        {
            cantLineasVacias++;
        }

        while(inicioPal)
        {
            char * finPalActual;
            int tam;

            finPalActual = finPal_MIO(inicioPal);
            tam = TAM_PAL_MIO(inicioPal, finPalActual);

            cantPalabras++;

            if (tam > mayorLongitud)
            {
                mayorLongitud = tam;
                cantPalabrasMayores = 1;
                copiarPal_MIO(palabrasMayores[0],
                                          inicioPal,
                                          tam,
                                          TAM_PAL_MAX);
            }
            else if (tam == mayorLongitud)
            {
                if (cantPalabrasMayores < CANT_PAL_MAX)
                    copiarPal_MIO(palabrasMayores[cantPalabrasMayores - 1],
                                inicioPal,
                                tam, TAM_PAL_MAX);
                cantPalabrasMayores++;
            }

            origenLinea = finPalActual;
            inicioPal = proxPal_MIO(origenLinea);
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
        fprintf(fpPantalla, "El archivo está vacío\n");
    }

}

/******************************************
****************  PUNTO 2 *****************
******************************************/

int traspRespAlCentro_MIO(int mat[][M_COLUM], int filas, int colum)
{
    int aux,
        modificaciones = 0;
    int * origen = mat[0],
        * fin = &mat[filas - 1][colum - 1];

    while(origen < fin) {
        modificaciones++;
        aux = *fin;
        *fin = *origen;
        *origen = aux;
        origen++;
        fin--;
    }

    return modificaciones;
}

int mostrarTriangSup_MIO(int mat[][M_COLUM], int filas, int colum,
                         FILE *fpPantalla)
{
    int cantDigitos = 4,
        cantElementos = 0;

    for(int i = 0; i < filas; i++)
    {
        fprintf(fpPantalla,"\n%*s",(i)*4,"");
        for (int j = i; j < colum;j++, cantElementos++)
        {
            fprintf(fpPantalla,"%4d",mat[i][j]);
        }
    }
    fprintf(fpPantalla,"\n");
    return cantElementos;
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

