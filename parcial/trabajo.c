#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "trabajo.h"
#include "bicicleta.h"

int mostrarTrabajos(eTrabajo trabajos[], int tam,eBicicleta bici[], int tamB, eServicio servicio[], int tamS, eTipo unTipo[],int tamT)
{
    int error = 1;
    int flag = 0;
    if(trabajos != NULL && tam > 0 && bici != NULL && tamB > 0 && servicio !=NULL && tamS>0)
    {
    printf("    ***   Lista de trabajos   ***  \n\n");
    printf("   ID   Servicio        Precio    Bicicleta        Tipo     dd/mm/aa\n");
    printf("--------------------------------------------------------------------\n");
    for(int i = 0; i<tam; i++)
    {
        if(trabajos[i].isEmpty==0)
        {
        mostrarTrabajo(trabajos[i],tam,bici,tamB,servicio,tamS,unTipo,tamT);
            flag = 1;
        }
    }


    if(flag ==0)
    {
        printf("\nNo hay Trabajos en la lista \n\n");
    }

    error = 0;
    }



    return error;
}

void mostrarTrabajo(eTrabajo trabajos, int tam,eBicicleta bici[], int tamB, eServicio servicio[], int tamS, eTipo unTipo[],int tamT)
{
    char descripcionMarca[20];
    char descripcionTipo[20];
    char descripcionServicio[20];
    int idTipo;
    float precio;
    idTipo = obtenerIdTipo(bici,tamB,trabajos.idBicicleta);
    precio = obtenerPrecio(servicio,tamS,trabajos.idServicio);

    if(cargarDescripcionServicio(servicio,tamS,descripcionServicio,trabajos.idServicio,precio)==0
       &&cargarDescripcionMarca(bici,tamB,descripcionMarca,trabajos.idBicicleta) ==0
       && cargarDescripcionTipo(unTipo,tamT,descripcionTipo,idTipo)==0)
    {
            printf("   %d %12s    $ %.2f %10s     %10s   %02d/%02d/%d\n", trabajos.id,
                                                                        descripcionServicio,
                                                                        precio,
                                                                        descripcionMarca,
                                                                        descripcionTipo,
                                                                        trabajos.fecha.dia,
                                                                        trabajos.fecha.mes,
                                                                        trabajos.fecha.anio);
    }else
    {
        printf("Problema para recuperar descripcion\n\n");
    }
}

int altaTrabajo(eTrabajo trabajos[], int tam,int id,eBicicleta bici[], int tamB, eServicio servicio[], int tamS)
{
    int error = 1;
    int indice;
    eTrabajo nuevoTrabajo;

    if(trabajos != NULL && tam > 0 && id>0)
    {
        printf("   ***  Alta Trabajo  *** \n");

        indice = buscarLIbreT(trabajos, tam);
        if(indice == -1)
        {
            printf("Sistema completo.\n\n");
        }else
        {
            nuevoTrabajo.id = id;
            nuevoTrabajo.isEmpty = 0;

            printf("Ingrese la bicicleta: ");
            scanf("%d", &nuevoTrabajo.idBicicleta);
            while(validarIdBicicleta(nuevoTrabajo.idBicicleta,bici,tamB)==0){
            printf("Bicicleta invalida. Ingrese un nueva bicicleta ");
            scanf("%d", &nuevoTrabajo.idBicicleta);
            }
            printf("\n");


            mostrarServicios(servicio,tamS);
            printf("Ingrese el Servicio: ");
            scanf("%d", &nuevoTrabajo.idServicio);
            while(validarIdServicio(nuevoTrabajo.idServicio,servicio,tamS)==0){
            printf("Servicio invalido. Ingrese un nuevo servicio ");
            scanf("%d", &nuevoTrabajo.idServicio);
            }


            printf("Ingrese fecha del trabajo dd/mm/aaaa: ");
            scanf("%d/%d/%d", &nuevoTrabajo.fecha.dia, &nuevoTrabajo.fecha.mes, &nuevoTrabajo.fecha.anio);

            while(validarIdFecha(nuevoTrabajo.fecha.dia,nuevoTrabajo.fecha.mes,nuevoTrabajo.fecha.anio)==0){
            printf("Fecha invalida. Ingrese una nueva fecha del trabajo dd/mm/aaaa: ");
            scanf("%d/%d/%d", &nuevoTrabajo.fecha.dia, &nuevoTrabajo.fecha.mes, &nuevoTrabajo.fecha.anio);
            }

            trabajos[indice] = nuevoTrabajo;
            error =0;
        }
    }




    return error;
}


int buscarLIbreT(eTrabajo listado[], int tam)
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

int inicializarTrabajos(eTrabajo listado[], int tam)
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

int hardcodearTrabajos(eTrabajo trabajos[], int tam, int cant)
{
    int id_trabajos []= {1,2,3,4,5};
    int servicios[] = {20000,20001,20002,20003,20000};
    int bicicletas[] = {100,102,101,102,103};
    int dias[] = {11,22,1,9,18};
    int meses[] = {12,1,11,5,4};
    int anios[] = {2000,2020,2018,2015,2013};

    int retorno = -1;
    if(trabajos != NULL && tam >0 && cant <= tam)
    {
        retorno = 0;
        for(int i=0; i<cant; i++)
        {
            trabajos[i].isEmpty =0;
            trabajos[i].id = id_trabajos[i];
            trabajos[i].idServicio = servicios[i];
            trabajos[i].idBicicleta = bicicletas[i];
            trabajos[i].fecha.dia = dias[i];
            trabajos[i].fecha.mes = meses[i];
            trabajos[i].fecha.anio = anios[i];

            retorno++;
        }
    }

    return retorno;
}
/*
int mostrarTotalTrabajosDeBicis(eBicicleta unaBici[], int tam, eTrabajo unTrabajo[], int tamT, eServicio servicios[], int tamS, eTipo lTipo[], int tamTipo, eColor colores[],int tamC, eCliente clientes[], int tamCLI)
{
    int error = 1;
    int idBici;
    float total = 0;

    if(unaBici != NULL && tam > 0 && unTrabajo!=NULL && tamT > 0 && servicios!=NULL && tamS>0)
    {
    system("cls");
    printf("Informe total de una bici\n\n");
    mostrarBicicletasTodo(unaBici,tam,colores,tamC,lTipo,tamTipo,clientes,tamCLI);
    printf("Ingrese id de la bici: ");
    scanf("%d", &idBici);
    for(int i=0;i<tamT;i++)
    {
        if(unTrabajo[i].isEmpty == 0 && unTrabajo[i].idBicicleta == idBici)
        {
            for(int j=0;j<tamS;j++)
            {
                if(servicios[j].id == unTrabajo[i].idServicio)
                {
                total += servicios[j].precio;
                }
            }

        }
    }
    printf("Total a pagar: %.2f\n\n", total);

    error = 0;
    }
    return error;
}
*/
