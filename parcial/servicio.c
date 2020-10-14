#include "Servicio.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int mostrarServicios(eServicio listado[], int tam)
{
    int error = 1;
    int flag = 0;
    if(listado != NULL && tam > 0)
    {
    printf("   ID     Descripcion\n");
    printf("---------------------\n");
    for(int i = 0; i<tam; i++)
    {
            mostrarServicio(listado[i]);
            flag = 1;
    }
        if(flag ==0)
        {
            printf("\nNo hay Servicio en la lista \n\n");
        }
        error = 0;
    }


    return error;
}
void mostrarServicio(eServicio unServicio)
{
    printf("   %d   %10s\n", unServicio.id,
                            unServicio.nombreServicio);
}

int hardcodearServicios(eServicio listado[], int tam, int cant)
{
    int id_Servicioes[] = {5000,5001,5002,5003,5004};
    char Servicioes [][20] ={"Gris","Negro","Blanco","Azul","Rojo"};

    int retorno = -1;
    if(listado != NULL && tam >0 && cant <= tam)
    {
        for(int i=0; i<cant; i++)
        {
            listado[i].id = id_Servicioes[i];
            strcpy(listado[i].nombreServicio, Servicioes[i]);
            retorno++;
        }
    }

    return retorno;
}
