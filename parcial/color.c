#include "color.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int mostrarColores(eColor listado[], int tam)
{
    int error = 1;
    int flag = 0;
    if(listado != NULL && tam > 0)
    {
    printf("   ID     Descripcion\n");
    printf("---------------------\n");
    for(int i = 0; i<tam; i++)
    {
            mostrarColor(listado[i]);
            flag = 1;
    }
        if(flag ==0)
        {
            printf("\nNo hay Color en la lista \n\n");
        }
        error = 0;
    }


    return error;
}
void mostrarColor(eColor unColor)
{
    printf("   %d   %10s\n", unColor.id,
                            unColor.nombreColor);
}

int hardcodearColores(eColor listado[], int tam, int cant)
{
    int id_colores[] = {5000,5001,5002,5003,5004};
    char colores [][20] ={"Gris","Negro","Blanco","Azul","Rojo"};

    int retorno = -1;
    if(listado != NULL && tam >0 && cant <= tam)
    {
        for(int i=0; i<cant; i++)
        {
            listado[i].id = id_colores[i];
            strcpy(listado[i].nombreColor, colores[i]);
            retorno++;
        }
    }

    return retorno;
}

int validarIdColor(int id,eColor colores[], int tam)
{
    int esValido = 0;
    for(int i = 0; i < tam; i++)
    {
        if(colores[i].id == id)
        {
            esValido =1;
            break;
        }

    }
    return esValido;
}
