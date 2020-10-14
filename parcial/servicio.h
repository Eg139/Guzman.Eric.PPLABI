#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED

typedef struct
{
    int id;
    int idBicicleta;
    int idServicio;
    eFecha fecha;
}eServicio;

#endif // SERVICIO_H_INCLUDED

int mostrarServicos(eServico listado[], int tam);
void mostrarServico(eServico unServico);
int hardcodearServicos(eServico listado[], int tam, int cant);
