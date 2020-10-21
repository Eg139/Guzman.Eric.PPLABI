#include "clientes.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int hardcodearClientes(eCliente listado[], int tam, int cant)
{
    int idClientes[] = {10000,10001,10002,10003,10004,10005};
    char nombres[][20] = {"Pepe","Paola","Coki", "Moni", "Dardo"};
    char sexos[] = {'m','f','m','f','m'};
    int retorno = -1;
    if(listado != NULL && tam >0 && cant <= tam)
    {
        for(int i=0; i<cant; i++)
        {
            listado[i].id = idClientes[i];
            strcpy(listado[i].nombre, nombres[i]);
            listado[i].sexo = sexos[i];
            retorno++;
        }
    }

    return retorno;
}


int mostrarClientes(eCliente listado[], int tam)
{
    int error = 1;
    int flag = 0;
    if(listado != NULL && tam > 0)
    {
    printf("   ***  Listado de Clientes  ***  \n");
    printf("   ID         Nombre   Sexo\n");
    printf("---------------------------\n");
    for(int i = 0; i<tam; i++)
    {
            mostrarCliente(listado[i]);
            flag = 1;
    }
        if(flag ==0)
        {
            printf("\nNo hay Clientes en la lista \n\n");
        }
        error = 0;
    }


    return error;
}
void mostrarCliente(eCliente unCliente)
{
    printf("   %d   %10s  %c\n", unCliente.id,
                            unCliente.nombre,
                            unCliente.sexo);
}

int cargarDescripcionCliente(eCliente clientes[], int tam, char descripcion[],int idCliente)
{
    int error = 1;
    for(int i = 0; i < tam; i++)
    {
        if(clientes[i].id == idCliente)
        {
            strcpy(descripcion, clientes[i].nombre);
            error =0;
            break;
        }

    }
    return error;
}
