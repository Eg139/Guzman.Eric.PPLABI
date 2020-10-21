#include "tipo.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "dataStore.h"

int mostrarTipos(eTipo listado[], int tam)
{
    int error = 1;
    int flag = 0;
    if(listado != NULL && tam > 0)
    {
    printf("   ID     Descripcion\n");
    printf("---------------------\n");
    for(int i = 0; i<tam; i++)
    {
            mostrarTipo(listado[i]);
            flag = 1;
    }
        if(flag ==0)
        {
            printf("\nNo hay Tipos en la lista \n\n");
        }
        error = 0;
    }


    return error;
}
void mostrarTipo(eTipo unTipo)
{
    printf("   %d   %10s\n", unTipo.id,
                            unTipo.descripcion);
}

int hardcodearTipos(eTipo listado[], int tam, int cant)
{
    int retorno = -1;
    if(listado != NULL && tam >0 && cant <= tam)
    {
        for(int i=0; i<cant; i++)
        {
            listado[i].id = id_tipos[i];
            strcpy(listado[i].descripcion, tipos[i]);
            retorno++;
        }
    }

    return retorno;
}

int validarIdTipo(int id,eTipo unTipo[], int tam)
{
    int esValido = 0;
    for(int i = 0; i < tam; i++)
    {
        if(unTipo[i].id == id)
        {
            esValido =1;
            break;
        }

    }
    return esValido;
}
