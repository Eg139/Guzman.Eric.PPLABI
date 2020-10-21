#include "fecha.h"
#include <stdio.h>
#include <stdlib.h>

void mostrarFecha(eFecha fecha)
{
    printf("%02d/%02d/%d", fecha.dia, fecha.mes, fecha.anio);
}

int validarIdFecha(int dia, int mes, int anio)
{
    int esValido = 0;

    if((dia >= 1 &&  dia <= 31) && (mes >= 1 &&  mes <=12) && (anio >= 1990 &&  anio <=2020))
    {
        esValido =1;
    }

    return esValido;
}
