#include "tipo.h"
#include "color.h"
#ifndef BICICLETA_H_INCLUDED
#define BICICLETA_H_INCLUDED

typedef struct
{
    int id;
    char marca[20];
    int idTipo;
    int idColor;
    float rodado;
    int isEmpty;
}eBicicleta;

#endif // BICICLETA_H_INCLUDED

char menu_modificar();
int inicializarBicicletas(eBicicleta listado[], int tam);
int mostrarBicicletas(eBicicleta listado[], int tam);
void mostrarBicicleta(eBicicleta unBicicleta);
int altaBicicleta(eBicicleta listado[], int tam, int id);
int buscarLIbre(eBicicleta listado[], int tam);
int buscarBicicleta(eBicicleta listado[], int tam, int id);
int bajaBicicleta(eBicicleta listado[], int tam);
int modificarBicicleta(eBicicleta listado[], int tam);
int hardcodearBicicletas(eBicicleta listado[], int tam, int cant);
/*int mostrarBicicletasTodo(eBicicleta listado[], int tam, eColor listaC[], int tamC, eTipo listaT[], int tamT);
void mostrarBicicletaTodo(eBicicleta unBicicleta, eColor unColor, eTipo unTipo);*/
