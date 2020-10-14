#include "bicicleta.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char menu_modificar()
{
    char opcion;
    system("cls");

    printf("a Tipo\n");
    printf("b Rodado\n");
    printf("e Salir\n\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    opcion = tolower(getchar());
    return opcion;
}


int altaBicicleta(eBicicleta listado[], int tam, int id)
{
    int error = 1;
    int indice;
    eBicicleta nuevaBicicleta;

    if(listado != NULL && tam > 0 && id>0)
    {
        indice = buscarLIbre(listado, tam);
        if(indice == -1)
        {
            printf("Sistema completo.\n\n");
        }else
        {
            nuevaBicicleta.id = id;
            nuevaBicicleta.isEmpty = 0;
            printf("Ingrese la Marca: ");
            fflush(stdin);
            gets(nuevaBicicleta.marca);
            printf("Ingrese el rodado: ");
            scanf("%f", &nuevaBicicleta.rodado);
            printf("Ingrese el tipo: ");
            scanf("%d", &nuevaBicicleta.idTipo);
            printf("Ingrese el Color: ");
            scanf("%d", &nuevaBicicleta.idColor);

            listado[indice] = nuevaBicicleta;
            error =0;
        }
    }

    return error;
}

int bajaBicicleta(eBicicleta listado[], int tam)//devuelve 0 baja exitosa // devuelve 1 hubo problemas // devuelve 2 si el usuario cancelo
{

    int error = 1;
    int legajo;
    int indice;
    char confirma;

    if(listado != NULL && tam > 0)
    {
        system("cls");
        printf("   *** Baja Bicicleta *** \n\n");
        mostrarBicicletas(listado, tam);
        printf("Ingrese legajo: ");
        scanf("%d", &legajo);
        indice = buscarBicicleta(listado, tam, legajo);
        if(indice == -1)
        {
            printf("No hay ninguna Bicicleta con este legajo.\n\n");
        }else{
            mostrarBicicleta(listado[indice]);
            printf("Confirma baja?");
            fflush(stdin);
            scanf("%c", &confirma);
            if( confirma == 's')
            {
                listado[indice].isEmpty = 1;
                error = 0;
            }
            else
            {
                error = 2;
            }
            }

    }



    return error;
}




int modificarBicicleta(eBicicleta listado[], int tam)
{

    int error = 1;
    int legajo;
    int indice;
    char confirma;
    char seguir = 's';

    if(listado != NULL && tam > 0)
    {
        system("cls");
        printf("   *** Modificar Bicicleta ***  \n\n");
        mostrarBicicletas(listado, tam);
        printf("Ingrese legajo: ");
        scanf("%d", &legajo);
        indice = buscarBicicleta(listado, tam, legajo);
        if(indice == -1)
        {
            printf("No hay ninguna Bicicleta con este legajo.\n\n");
        }else{
            mostrarBicicleta(listado[indice]);
            do
            {
            switch(menu_modificar())
            {
            case 'a':
            printf("Ingrese el nuevo Tipo: ");
            fflush(stdin);
            scanf("%d", &listado[indice].idTipo);
            break;
            case 'b':
            printf("Ingrese el nuevo Rodado: ");
            fflush(stdin);
            scanf("%f", &listado[indice].rodado);
            break;
            case 'e':
            printf("Confirma salida?: ");
            fflush(stdin);
            scanf("%c", &confirma);
            confirma = tolower(confirma);
            if(confirma == 's')
            {
                seguir = 'n';
            }
            break;
            default:
            printf("Opcion invalida!!!\n");
            }
            error = 0;
            system("pause");
            }
            while( seguir == 's');
            }

    }
    return error;
}

int buscarLIbre(eBicicleta listado[], int tam)
{
    int indice =-1;
    for(int i = 0; i<tam; i++)
    {
        if(listado[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

int buscarBicicleta(eBicicleta listado[], int tam, int id)
{
    int indice =-1;

    for(int i = 0; i<tam; i++)
    {
        if(listado[i].id == id && listado[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }

    return indice;
}
int inicializarBicicletas(eBicicleta listado[], int tam)
{
    int error =1;
    if(listado != NULL && tam > 0)
    {
        for(int i=0;i<tam;i++)
        {
            listado[i].isEmpty = 1;
        }

        error = 0;
    }

        return error;
}
int mostrarBicicletas(eBicicleta listado[], int tam)
{
    int error = 1;
    int flag = 0;
    if(listado != NULL && tam > 0)
    {
    printf("   ID    Color    Tipo     Marca    Altura\n");
    printf("------------------------------------------\n");
    for(int i = 0; i<tam; i++)
    {
        if(listado[i].isEmpty==0)
        {
            mostrarBicicleta(listado[i]);
            flag = 1;
        }

    }
        if(flag ==0)
        {
            printf("\nNo hay Bicicletas en la lista \n\n");
        }
        error = 0;
    }


    return error;
}
void mostrarBicicleta(eBicicleta unBicicleta)
{
    printf("   %d  %d     %d   %10s     %2.2f \n", unBicicleta.id,
                                       unBicicleta.idColor,
                                       unBicicleta.idTipo,
                                       unBicicleta.marca,
                                       unBicicleta.rodado);
}
