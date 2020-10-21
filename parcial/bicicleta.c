#include "bicicleta.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char menu_modificar()
{
    char opcion;
    printf("a Tipo\n");
    printf("b Rodado\n");
    printf("e Salir\n\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    opcion = tolower(getchar());
    return opcion;
}


int altaBicicleta(eBicicleta listado[], int tam, int id, eColor lColores[], int tamC, eTipo lTipos[],int tamT, eCliente clientes[], int tamCLI)
{
    int error = 1;
    int indice;
    eBicicleta nuevaBicicleta;

    if(listado != NULL && tam > 0 && id>0)
    {
        system("cls");
        printf("  *** ALta de bicicletas ***  \n\n");
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

            printf("Rodados disponibles: 20, 26, 27.5, 29\n");
            printf("Ingrese el rodado: ");
            scanf("%f", &nuevaBicicleta.rodado);
            while(nuevaBicicleta.rodado != 20 && nuevaBicicleta.rodado != 26 && nuevaBicicleta.rodado != 27.5 && nuevaBicicleta.rodado != 29)
            {
            printf("Rodado invalido, Ingrese un nuevo rodado: ");
            scanf("%f", &nuevaBicicleta.rodado);
            }
            printf("\n");

            mostrarTipos(lTipos,tamT);
            printf("Ingrese el tipo: ");
            scanf("%d", &nuevaBicicleta.idTipo);

            while(validarIdTipo(nuevaBicicleta.idTipo,lTipos,tamT)==0){
            printf("Tipo invalido. Ingrese un nuevo tipo ");
            scanf("%d", &nuevaBicicleta.idTipo);
            }
            printf("\n");
            mostrarColores(lColores,tamC);
            printf("Ingrese el Color: ");
            scanf("%d", &nuevaBicicleta.idColor);
            while(validarIdColor(nuevaBicicleta.idColor,lColores,tamC)==0){
            printf("Color invalido. Ingrese un nuevo color ");
            scanf("%d", &nuevaBicicleta.idColor);
            }
            mostrarClientes(clientes,tamCLI);
            printf("Ingrese el Cliente: ");
            scanf("%d", &nuevaBicicleta.idCliente);

            listado[indice] = nuevaBicicleta;
            error =0;
        }
    }

    return error;
}

int bajaBicicleta(eBicicleta listado[], int tam, eColor colores[], int tamC, eTipo lTipos[], int tamT, eCliente clientes[], int tamCLI)//devuelve 0 baja exitosa // devuelve 1 hubo problemas // devuelve 2 si el usuario cancelo
{

    int error = 1;
    int legajo;
    int indice;
    char confirma;

    if(listado != NULL && tam > 0)
    {
        system("cls");
        printf("   *** Baja Bicicleta *** \n\n");
        mostrarBicicletasTodo(listado, tam,colores,tamC,lTipos,tamT,clientes,tamCLI);
        printf("Ingrese legajo: ");
        scanf("%d", &legajo);
        indice = buscarBicicleta(listado, tam, legajo);
        if(indice == -1)
        {
            printf("No hay ninguna Bicicleta con este legajo.\n\n");
        }else{
            mostrarBicicletaTodo(listado[indice],colores,tamC,lTipos,tamT,clientes,tamCLI);
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




int modificarBicicleta(eBicicleta listado[], int tam, eColor unColor[], int tamC, eTipo unTiipo[], int tamT, eCliente clientes[], int tamCLI)
{

    int error = 1;
    int legajo;
    int indice;
    char salir = 'n';

    if(listado != NULL && tam > 0)
    {
        system("cls");
        printf("   *** Modificar Bicicleta ***  \n\n");
        mostrarBicicletasTodo(listado, tam, unColor, tamC,unTiipo,tamT,clientes,tamCLI);
        printf("Ingrese legajo: ");
        scanf("%d", &legajo);
        indice = buscarBicicleta(listado, tam, legajo);
        if(indice == -1)
        {
            printf("No hay ninguna Bicicleta con este legajo.\n\n");
        }else{
            do{
            system("cls");
            printf("   *** Modificar Bicicleta ***  \n\n");
            printf("    ID        Color        Tipo          Marca     Rodado\n");
            printf("---------------------------------------------------------\n");
            mostrarBicicletaTodo(listado[indice],unColor,tamC,unTiipo,tamT,clientes,tamCLI);
            printf("\n");
            switch(menu_modificar())
            {
            case 'a':
            mostrarTipos(unTiipo,tamT);
            printf("Ingrese el nuevo Tipo: ");
            fflush(stdin);
            scanf("%d", &listado[indice].idTipo);
            break;
            case 'b':
            printf("Rodados disponibles: 20, 26, 27.5, 29\n");
            printf("Ingrese el nuevo Rodado: ");
            fflush(stdin);
            scanf("%f", &listado[indice].rodado);
            break;
            case 'e':
            printf("Saliendo del menu modificar... \n");
            salir = 's';
            break;
            default:
            printf("Opcion invalida!!!\n");
            }
            system("pause");
            system("cls");
            error = 0;
            }while(salir == 'n');

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

int hardcodearBicicletas(eBicicleta listado[], int tam, int cant)
{
    int id []= {100,101,102,103};
    char Marcas[][20] = {"Scott","Lapierre","Apple","Xiaomi"};
    int idTipos[] = {1000,1001,1002,1003};
    int idColores[] = {5000,5002,5000,5001};
    float rodados[] = {20,26,27.5,29};
    int idClientes[] ={10000,10003,10002,10000};

    int retorno = -1;
    if(listado != NULL && tam >0 && cant <= tam)
    {
        retorno = 0;
        for(int i=0; i<cant; i++)
        {
            listado[i].id = id[i];
            strcpy(listado[i].marca, Marcas[i]);
            listado[i].idColor = idColores[i];
            listado[i].idTipo = idTipos[i];
            listado[i].rodado = rodados[i];
            listado[i].idCliente = idClientes[i];
            listado[i].isEmpty = 0;
            retorno++;
        }
    }

    return retorno;
}

int cargarDescripcionColor(eColor unColor[], int tam, char descripcion[],int idColor)
{
    int error = 1;
    for(int i = 0; i < tam; i++)
    {
        if(unColor[i].id == idColor)
        {
            strcpy(descripcion, unColor[i].nombreColor);
            error =0;
            break;
        }

    }
    return error;
}

int cargarDescripcionTipo(eTipo unTipo[], int tam, char descripcion[],int idTipo)
{
    int error = 1;
    for(int i = 0; i < tam; i++)
    {
        if(unTipo[i].id == idTipo)
        {
            strcpy(descripcion, unTipo[i].descripcion);
            error =0;
            break;
        }

    }
    return error;
}

void mostrarBicicletaTodo(eBicicleta unBicicleta, eColor unColor[],int tamC ,eTipo unTipo[],int tamT, eCliente clientes[], int tamCli)
{
    char descripcionColor[20];
    char descripcionTipo[20];
    char descripcionNombre[20];

    if(cargarDescripcionColor(unColor,tamC,descripcionColor,unBicicleta.idColor)==0 &&
       cargarDescripcionTipo(unTipo,tamT,descripcionTipo,unBicicleta.idTipo)==0 &&
       cargarDescripcionCliente(clientes,tamCli,descripcionNombre,unBicicleta.idCliente)==0)
    {
            printf("   %d  %10s     %10s   %10s     %2.2f  %10s\n", unBicicleta.id,
                                                               descripcionColor,
                                                               descripcionTipo,
                                                               unBicicleta.marca,
                                                               unBicicleta.rodado,
                                                               descripcionNombre);
    }else
    {
        printf("Problema para recuperar descripcion\n\n");
    }
}

int mostrarBicicletasTodo(eBicicleta listado[], int tam, eColor listaC[], int tamC, eTipo listaT[], int tamT, eCliente clientes[], int tamCLI)
{
    int error = 1;
    int flag = 0;
    if(listado != NULL && tam > 0 && listaC != NULL && tamC > 0 && listaT !=NULL && tamT>0)
    {
        printf("    ***  Listado de Bicis  *** \n");
    printf("    ID        Color        Tipo          Marca     Rodado     Cliente\n");
    printf("---------------------------------------------------------------------\n");
    for(int i = 0; i<tam; i++)
    {
        if(listado[i].isEmpty==0)
        {
            mostrarBicicletaTodo(listado[i],listaC,tamC,listaT,tamT,clientes,tamCLI);
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


int ordenarBici_tipo_rodado(eBicicleta listado[], int tam, eTipo listaT[], int tamT, int criterio)
{
    eBicicleta aux;
    int error = 1;
    char tipoI[20];
    char tipoJ[20];

if(listado != NULL && tam > 0 &&  listaT !=NULL && tamT > 0)
{
  for (int i = 0; i < tam - 1; i++)
  {
    for (int j = i + 1; j < tam; j++)
    {
        cargarDescripcionTipo(listaT,tamT,tipoI,listado[i].idTipo);

        cargarDescripcionTipo(listaT,tamT,tipoJ,listado[j].idTipo);

      if(strcmpi(tipoI, tipoJ)>0 && criterio == 0)
      {
        aux = listado[i];
        listado[i] = listado[j];
        listado[j] = aux;
      }
	  else if(strcmpi(tipoI, tipoJ)<0 && criterio == 1)
      {
        aux = listado[i];
        listado[i] = listado[j];
        listado[j] = aux;
      }else if(strcmpi(tipoI, tipoJ)==0 && listado[i].rodado < listado[j].rodado)
      {
        aux = listado[i];
        listado[i] = listado[j];
        listado[j] = aux;
      }
    }
  }
  error = 0;
  }
  return error;
}


int cargarDescripcionMarca(eBicicleta unaBici[], int tam, char descripcion[],int idBici)
{
    int error = 1;
    for(int i = 0; i < tam; i++)
    {
        if(unaBici[i].id == idBici)
        {
            strcpy(descripcion, unaBici[i].marca);
            error =0;
            break;
        }

    }
    return error;
}

int obtenerIdTipo(eBicicleta unaBici[], int tam, int idBici)
{
    int idTipo;
    for(int i=0;i<tam;i++)
    {
        if(unaBici[i].id == idBici)
        {
            idTipo = unaBici[i].idTipo;
        }
    }
    return idTipo;
}


int validarIdBicicleta(int id,eBicicleta bici[], int tam)
{
    int esValido = 0;
    for(int i = 0; i < tam; i++)
    {
        if(bici[i].id == id)
        {
            esValido =1;
            break;
        }

    }
    return esValido;
}





void mostrarBiciPorColorSelec(eBicicleta listado[], int tam, eColor listaC[], int tamC, eTipo listaT[], int tamT, eCliente clientes[], int tamCLI)
{
    system("cls");
    int colorSelec;
    mostrarColores(listaC,tamC);
    printf("Ingrese el color de bici que desea mostrar: ");
    scanf("%d", &colorSelec);

    while(validarIdColor(colorSelec,listaC,tamC)==0){
    printf("Color invalido. Ingrese un nuevo color: ");
    scanf("%d", &colorSelec);
    }

    if(listado != NULL && tam > 0 && listaC != NULL && tamC > 0)
    {
        printf("Bicicletas de color: \n\n");
    for(int i=0;i<tam;i++)
    {
        if(colorSelec == listado[i].idColor && listado[i].isEmpty == 0)
        {
            mostrarBicicletaTodo(listado[i],listaC,tamC,listaT,tamT,clientes,tamCLI);
        }
    }
    }else{
            printf("No hay bicicletas del color seleccionado\n");
        }
}

void mostrarBiciPorTipoSelec(eBicicleta listado[], int tam, eColor listaC[], int tamC, eTipo listaT[], int tamT, eCliente clientes[], int tamCLI)
{
    system("cls");
    int tipoSelec;
    mostrarTipos(listaT,tamT);
    printf("Ingrese el Tipo que desea mostrar: ");
    scanf("%d", &tipoSelec);

    while(validarIdTipo(tipoSelec,listaT,tamT)==0){
    printf("Tipo invalido. Ingrese un nuevo tipo: ");
    scanf("%d", &tipoSelec);
    }

    if(listado != NULL && tam > 0 && listaT != NULL && tamC > 0)
    {
        printf("Bicicletas de Tipo: \n\n");
    for(int i=0;i<tam;i++)
    {
        if(tipoSelec == listado[i].idTipo && listado[i].isEmpty == 0)
        {
            mostrarBicicletaTodo(listado[i],listaC,tamC,listaT,tamT,clientes,tamCLI);
        }
    }
    }else{
            printf("No hay bicicletas del color seleccionado\n");
        }
}
void InformarBicicletasMenorRodado(eBicicleta listado[], int tam, eColor listaC[], int tamC, eTipo listaT[], int tamT, eCliente clientes[], int tamCLI)
{
    float min;
    int flag = 0;

    for(int i=0;i<tam-1;i++)
    {
        if(flag == 0 || min > listado[i].rodado)
        {
            flag = 1;
            min = listado[i].rodado;

        }
    }

    for(int i=0;i<tam;i++)
    {
        if(listado[i].rodado == min && listado[i].isEmpty == 0)
        {
            mostrarBicicletaTodo(listado[i],listaC,tamC,listaT,tamT,clientes,tamCLI);
            printf("Minimo: %f", min);
        }
    }

}

void ElegirColor_Tipo_contar(eBicicleta listado[], int tam, eColor listaC[], int tamC, eTipo listaT[], int tamT, eCliente clientes[], int tamCLI)
{
    int contadorC_T =0;
    char descripcionTipo[20];
    char descripcionColor[20];

    system("cls");
    int colorSelec;
    mostrarColores(listaC,tamC);
    printf("Ingrese el color de bici que desea mostrar: ");
    scanf("%d", &colorSelec);
    while(validarIdColor(colorSelec,listaC,tamC)==0){
    printf("Color invalido. Ingrese un nuevo color: ");
    scanf("%d", &colorSelec);
    }
    printf("\n");

    int tipoSelec;
    mostrarTipos(listaT,tamT);
    printf("Ingrese el Tipo que desea mostrar: ");
    scanf("%d", &tipoSelec);
    while(validarIdTipo(tipoSelec,listaT,tamT)==0){
    printf("Tipo invalido. Ingrese un nuevo tipo: ");
    scanf("%d", &tipoSelec);
    }
    printf("\n");

    cargarDescripcionColor(listaC,tamC,descripcionColor,colorSelec);
    cargarDescripcionTipo(listaT,tamT,descripcionTipo,tipoSelec);

    if(listado != NULL && tam > 0 && listaC != NULL && tamC > 0 && listaT != NULL && tamT)
    {
    printf("Bicicletas de color: %s y tipo: %s\n\n", descripcionColor, descripcionTipo);
    printf("    ID        Color        Tipo          Marca     Rodado     Cliente\n");
    printf("---------------------------------------------------------------------\n");
    for(int i=0;i<tam;i++)
    {
        if(colorSelec == listado[i].idColor && listado[i].isEmpty == 0 && tipoSelec == listado[i].idTipo)
        {
            contadorC_T++;
            mostrarBicicletaTodo(listado[i],listaC,tamC,listaT,tamT,clientes,tamCLI);
        }
    }
    }else{
            printf("No hay bicicletas del color y tipo seleccionado\n");
        }
        printf("\n hay  %d Bicicletas de color: %s y tipo: %s \n\n", contadorC_T, descripcionColor, descripcionTipo);

}

int MostrarColoresFavoritosClientes(eBicicleta listado[], int tam, eColor listaC[], int tamC, eTipo listaT[], int tamT, eCliente clientes[], int tamCLI)
{
    int error = 1;
    int flag=0;
    int mayor;
    int contadores[tam];

    if(listado != NULL && tam > 0)
    {
        for(int d = 0; d<tam; d++)
        {
            contadores[d] = 0;
        }


        for(int d = 0; d<tamC; d++)
        {
            for(int p=0;p<tam;p++)
            {
                if(listado[p].idColor == listaC[d].id && listado[p].isEmpty == 0)
                {
                    contadores[d]++;
                }
            }

        }
        for(int i = 0; i<tamC; i++)
        {
            if(contadores[i] > mayor || flag == 0)
            {
                flag = 1;
                mayor = contadores[i];
            }
        }
        printf("\nEl o los colores favoritos de los clientes son: \n\n");
        for(int i = 0; i<tamC; i++)
        {
            if(contadores[i]== mayor)
            {
                printf("%s\n", listaC[i].nombreColor);
            }
        }
        printf("\n\n");


    error = 0;
    }

    return error;
}

int informes()
{
    int opcion;
    system("cls");

    printf("*** Informes ***\n\n");
    printf("1- Mostrar bicicletas del color seleccionado por el usuario.\n");
    printf("2- Mostrar bicicletas de un tipo seleccionado.\n");
    printf("3- Informar la o las bicicletas de menor rodado.\n");
    printf("4- Mostrar un listado de las bicicletas separadas por tipo.\n");
    printf("5- Elegir un color y un tipo y contar cuantas bicicletas hay de ese color y ese tipo.\n");
    printf("6- Mostrar el o los colores más elegidos por los clientes.\n");
    /*printf("g Listar Servicios\n");
    printf("h Alta Trabajo\n");
    printf("i Listar Trabajos\n");*/
    printf("10 Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

int mostrarBicicletasXTipo(eBicicleta listado[], int tam, eColor listaC[], int tamC, eTipo listaT[], int tamT, eCliente clientes[], int tamCLI)
{
    char tipo[20];
    int error = 1;
    int flag;

    if(listado != NULL && listaT != NULL && tam > 0 && tamT >0)
    {
        system("cls");
        printf("\n          *** Informe Bicicletas de todos los tipos ***  \n\n");
        for(int i = 0;i<tamT;i++)//recorre tipos
        {
            flag = 0;
            cargarDescripcionTipo(listaT,tamT,tipo,listaT[i].id);
            printf("Tipo: %s\n\n", tipo);
            printf("    ID        Color        Tipo          Marca     Rodado     Cliente\n");
            printf("---------------------------------------------------------------------\n");

            for(int j=0;j<tam;j++)//recorre bicicletas
            {
                if(listado[j].idTipo == listaT[i].id && listado[j].isEmpty == 0)
                {
                    mostrarBicicletaTodo(listado[j],listaC,tamC,listaT,tamT,clientes,tamCLI);
                    flag = 1;

                }
            }
            if(flag ==0)
            {
                printf("\n No hay bicis de este tipo\n");
            }
            printf("\n\n");
        }
    error = 0;
    }
    return error;
}


int elegirInforme(eBicicleta listado[], int tam, eColor unColor[], int tamC, eTipo unTiipo[], int tamT, eCliente clientes[], int tamCLI)
{

    int error = 1;

    char seguir = 's';
    char confirma;
    do
    {
        switch(informes())
        {

        case 1:
            mostrarBiciPorColorSelec(listado,tam,unColor,tamC,unTiipo,tamT,clientes,tamCLI);
            break;
        case 2:
            mostrarBiciPorTipoSelec(listado,tam,unColor,tamC,unTiipo,tamT,clientes,tamCLI);
            break;
        case 3:
            InformarBicicletasMenorRodado(listado,tam,unColor,tamC,unTiipo,tamT,clientes,tamCLI);
            break;
        case 4:
            mostrarBicicletasXTipo(listado,tam,unColor,tamC,unTiipo,tamT,clientes,tamCLI);
            break;
        case 5:
            ElegirColor_Tipo_contar(listado,tam,unColor,tamC,unTiipo,tamT,clientes,tamCLI);
            break;
        case 6:
            MostrarColoresFavoritosClientes(listado,tam,unColor,tamC,unTiipo,tamT,clientes,tamCLI);
            break;
            /*case 7:
            break;
            case 8:
            break;
            case 9:
            break;*/
        case 10:
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


    return error;
}



