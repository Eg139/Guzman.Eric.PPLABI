#include "bicicleta.h"
#include "servicio.h"
#include "fecha.h"

#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED

typedef struct
{
    int id;
    int idBicicleta;
    int idServicio;
    int isEmpty;
    eFecha fecha;
}eTrabajo;

#endif // TRABAJO_H_INCLUDED

/** \brief Muestra el array de estructuras de trabajos
 *
 * \param trabajos[] eTrabajo
 * \param tam int
 * \param bici[] eBicicleta
 * \param tamB int
 * \param servicio[] eServicio
 * \param tamS int
 * \param unTipo[] eTipo
 * \param tamT int
 * \return int retorna 1 para error 0 para OK
 *
 */
int mostrarTrabajos(eTrabajo trabajos[], int tam,eBicicleta bici[], int tamB, eServicio servicio[], int tamS, eTipo unTipo[],int tamT);
/** \brief Muestra una estructura de trabajo
 *
 * \param trabajos eTrabajo
 * \param tam int
 * \param bici[] eBicicleta
 * \param tamB int
 * \param servicio[] eServicio
 * \param tamS int
 * \param unTipo[] eTipo
 * \param tamT int
 * \return void
 *
 */
void mostrarTrabajo(eTrabajo trabajos, int tam,eBicicleta bici[], int tamB, eServicio servicio[], int tamS, eTipo unTipo[],int tamT);
/** \brief Da de altua un trabajo en el array de estructuras
 *
 * \param trabajos[] eTrabajo
 * \param tam int
 * \param id int
 * \param bici[] eBicicleta
 * \param tamB int
 * \param servicio[] eServicio
 * \param tamS int
 * \return int 1 error 0 OK
 *
 */
int altaTrabajo(eTrabajo trabajos[], int tam,int id,eBicicleta bici[], int tamB, eServicio servicio[], int tamS);
/** \brief inicializa la estructura
 *
 * \param listado[] eTrabajo
 * \param tam int
 * \return int 1 error 0 OK
 *
 */
int inicializarTrabajos(eTrabajo listado[], int tam);
/** \brief Busca un indice libre en el array de estructuras
 *
 * \param listado[] eTrabajo
 * \param tam int
 * \return int devuelve el indice que encontro
 *
 */
int buscarLIbreT(eTrabajo listado[], int tam);
/** \brief harcodea la estructura
 *
 * \param trabajos[] eTrabajo
 * \param tam int
 * \param cant int
 * \return int retorna el siguiente id a cargarse en la proxima alta
 *
 */
int hardcodearTrabajos(eTrabajo trabajos[], int tam, int cant);
