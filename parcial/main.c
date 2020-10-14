#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "bicicleta.h"
#include "tipo.h"
#include "color.h"
#include "servicio.h"
#define TAM 10
#define TAM_T 4
#define TAM_C 5
#define TAM_S 4

char menu();


int main()
{
    int rta;
    int proximoID = 100;
    eBicicleta lista[TAM];
    eTipo lista_tipos[TAM_T];
    eColor lista_colores[TAM_C];
    eServicio lista_servicios[TAM_S];
    int proximoID_tipo = 1000;

    if(inicializarBicicletas(lista, TAM)==0)
    {
        printf("Inicializacion exitosa!!!!\n");
    }else
    {
        printf("Fallo al inicializar....\n");
    }

    //proximoID +=hardcodearBicicletas(lista,TAM,10);*/
    proximoID_tipo +=hardcodearTipos(lista_tipos,TAM_T,4);
    hardcodearColores(lista_colores,TAM_C,5);
    hardcodearServicios(lista_servicios,TAM_S, 4);

    char seguir = 's';
    char confirma;
    do
    {
        switch(menu())
        {

        case 'a':
        if(altaBicicleta(lista,TAM, proximoID)==0)
        {
        proximoID++;
        printf("Alta exitosa!!! \n\n");
        }else{
        printf("No se pudo realizar el alta...\n");
        }

            break;
        case 'b':
        rta =bajaBicicleta(lista,TAM);
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
            modificarBicicleta(lista,TAM);
            break;
        case 'd':
            system("cls");
            mostrarBicicletas(lista, TAM);

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

            break;/*
        case 'e':
            if(ordenarBicicletas_Sexo_altura(lista,TAM, ASC, ASC)==0)
            {
                printf("Se ordeno el vector \n\n");
            }else{
            printf("Problema al ordenar el vetor\n\n");
            }

            break;
        case 'f':

            break;
        case 'g':
            printf("Ingrese el sexo que se va a mostrar: ");
            fflush(stdin);
            scanf("%c", &sexo);
            mostrarXSexo(lista,TAM,sexo);
            break;
        case 'h':
            printf("Ingrese el anio que se va a mostrar: ");
            scanf("%d", &anio);
            mostrarXAnio(lista,TAM,anio);
            break;
        case 'i':
            mostrarDeportes(deporte,TAM_D);
            break;

*/
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
    printf("z Salir\n\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    opcion = tolower(getchar());

    return opcion;
}
