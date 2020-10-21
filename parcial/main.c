#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "bicicleta.h"
#include "tipo.h"
#include "color.h"
#include "servicio.h"
#include "trabajo.h"
#define TAM 10
#define TAM_T 4
#define TAM_C 5
#define TAM_S 4
#define ASC 0
#define DESC 1
#define TRABAJO 20

char menu();
int mostrarTotalTrabajosDeBicis(eBicicleta unaBici[], int tam, eTrabajo unTrabajo[], int tamT, eServicio servicios[], int tamS, eTipo lTipo[], int tamTipo, eColor colores[],int tamC);

int main()
{
    int rta;
    int proximoID = 100;
    int proximoIdTrabajo = 1;
    eTrabajo lista_trabajos[TRABAJO];
    eBicicleta lista[TAM];
    eTipo lista_tipos[TAM_T];
    eColor lista_colores[TAM_C];
    eServicio lista_servicios[TAM_S];

    if(inicializarBicicletas(lista, TAM)==0 && inicializarTrabajos(lista_trabajos,TRABAJO))
    {
        printf("Inicializacion exitosa!!!!\n");
    }else
    {
        printf("Fallo al inicializar....\n");
    }

    proximoID +=hardcodearBicicletas(lista,TAM,4);
    hardcodearTipos(lista_tipos,TAM_T,4);
    hardcodearColores(lista_colores,TAM_C,5);
    hardcodearServicios(lista_servicios,TAM_S, 4);
    proximoIdTrabajo+=hardcodearTrabajos(lista_trabajos,TRABAJO,5);

    char seguir = 's';
    char confirma;
    do
    {
        switch(menu())
        {

        case 'a':
        if(altaBicicleta(lista,TAM, proximoID,lista_colores,TAM_C,lista_tipos,TAM_T)==0)
        {
        proximoID++;
        printf("Alta exitosa!!! \n\n");
        }else{
        printf("No se pudo realizar el alta...\n");
        }

            break;
        case 'b':
        rta =bajaBicicleta(lista,TAM,lista_colores,TAM_C,lista_tipos,TAM_T);
        if(rta==0)
        {
        printf("Baja exitosa\n");
        }else if(rta==1){

        printf("problema al intentar baja exitosa\n");
        }
        else{
        printf("Baja cancelada por el usuario\n");
        }

            break;
        case 'c':
            if(modificarBicicleta(lista,TAM,lista_colores,TAM_C,lista_tipos,TAM_T)==0)
            {
                printf("\n\nModificacion exitosa\n");
            }else
            {
             printf("\n\nFallo al modificar\n");
            }
            break;
        case 'd':
            system("cls");
            ordenarBici_tipo_rodado(lista,TAM,lista_tipos,TAM_T,ASC);
            mostrarBicicletasTodo(lista,TAM,lista_colores,TAM_C,lista_tipos,TAM_T);

            break;
        case 'e':
            system("cls");
            mostrarTipos(lista_tipos, TAM_T);

            break;
        case 'f':
            system("cls");
            mostrarColores(lista_colores, TAM_C);

            break;
            case 'g':
            system("cls");
            mostrarServicios(lista_servicios, TAM_S);
            break;
            case 'h':
            system("cls");
            printf("  *** ALta de Trabajos ***  \n\n");
            mostrarBicicletasTodo(lista,TAM,lista_colores,TAM_C,lista_tipos,TAM_T);
            altaTrabajo(lista_trabajos,TRABAJO,proximoIdTrabajo,lista,TAM,lista_servicios,TAM_S);
            break;
            case 'i':
            system("cls");
            mostrarTrabajos(lista_trabajos,TRABAJO,lista,TAM,lista_servicios,TAM_S,lista_tipos,TAM_T);
            break;
            case 'j':
            system("cls");
            mostrarTotalTrabajosDeBicis(lista,TAM,lista_trabajos,TRABAJO,lista_servicios,TAM_S,lista_tipos,TAM_T,lista_colores,TAM_C);
            break;
        case 'z':
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

        system("pause");

    }
    while( seguir == 's');


    return 0;
}

char menu()
{
    char opcion;
    system("cls");

    printf("*** ABM Bicicletas ***\n\n");
    printf("a Alta\n");
    printf("b Baja\n");
    printf("c Modificion\n");
    printf("d Listar Bicicletas\n");
    printf("e Listar Tipos\n");
    printf("f Listar Colores\n");
    printf("g Listar Servicios\n");
    printf("h Alta Trabajo\n");
    printf("i Listar Trabajos\n");
    printf("j Listar gasto total de servicios de una bici\n");
    printf("z Salir\n\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    opcion = tolower(getchar());

    return opcion;
}

int mostrarTotalTrabajosDeBicis(eBicicleta unaBici[], int tam, eTrabajo unTrabajo[], int tamT, eServicio servicios[], int tamS, eTipo lTipo[], int tamTipo, eColor colores[],int tamC)
{
    int error = 1;
    int idBici;
    float total = 0;

    if(unaBici != NULL && tam > 0 && unTrabajo!=NULL && tamT > 0 && servicios!=NULL && tamS>0)
    {
    system("cls");
    printf("Informe total de una bici\n\n");
    mostrarBicicletasTodo(unaBici,tam,colores,tamC,lTipo,tamTipo);
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
