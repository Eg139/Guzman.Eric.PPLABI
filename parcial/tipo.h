#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];
}eTipo;

#endif // TIPO_H_INCLUDED

int mostrarTipos(eTipo listado[], int tam);
void mostrarTipo(eTipo unTipo);
int hardcodearTipos(eTipo listado[], int tam, int cant);
