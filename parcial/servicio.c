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
    printf("   ID     Descripcion     Precio\n");
    printf("--------------------------------\n");
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
    printf("   %d   %10s    $ %d\n", unServicio.id,
                                    unServicio.descripcion,
                                    unServicio.precio);
}

int hardcodearServicios(eServicio listado[], int tam, int cant)
{
    int id_servicios []= {20000,20001,20002,20003};
    char servicios[][20] = {"Limpieza","Parche","Centrado","Cadena"};
    int precios[] = {250,300,400,350};

    int retorno = -1;
    if(listado != NULL && tam >0 && cant <= tam)
    {
        for(int i=0; i<cant; i++)
        {
            listado[i].id = id_servicios[i];
            strcpy(listado[i].descripcion, servicios[i]);
            listado[i].precio = precios[i];

            retorno++;
        }
    }

    return retorno;
}
