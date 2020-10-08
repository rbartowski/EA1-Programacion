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
    char * finPal = finPal_MIO(s);

    while(!esLetraODigito_MIO(*finPal)) {
        finPal++;
    }

    return (char *)finPal;
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
    char * principioPalabra = orig;
    while(tam - 1 > 0 && (orig - principioPalabra) < tope) {
        *dest = *orig;
        dest++;
        orig++;
        tam--;
    }
    return dest;
}

void procesarArchivo_MIO(FILE *fpEnt, FILE *fpPantalla)
{

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

