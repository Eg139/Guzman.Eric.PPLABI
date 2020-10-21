#include "tipo.h"
#include "color.h"
#ifndef BICICLETA_H_INCLUDED
#define BICICLETA_H_INCLUDED

typedef struct
{
    int id;
    char marca[20];
    int idTipo;
    int idColor;
    float rodado;
    int isEmpty;
}eBicicleta;

#endif // BICICLETA_H_INCLUDED

/** \brief menu de modificar bicicleta
 *
 * \return char
 *
 */
char menu_modificar();
/** \brief Inicializa el campo isEmpty del array de estructuras en 0
 *
 * \param listado[] eBicicleta
 * \param tam int
 * \return int 1 error 0 OK
 *
 */
int inicializarBicicletas(eBicicleta listado[], int tam);
/** \brief Carga una estructura bicicleta en el array de estructuras
 *
 * \param listado[] eBicicleta
 * \param tam int
 * \param id int
 * \param lColores[] eColor
 * \param tamC int
 * \param lTipos[] eTipo
 * \param tamT int
 * \return int 1 error 0 OK
 *
 */
int altaBicicleta(eBicicleta listado[], int tam, int id, eColor lColores[], int tamC, eTipo lTipos[],int tamT);
/** \brief busca lugar libre en el array de estructuras
 *
 * \param listado[] eBicicleta
 * \param tam int
 * \return int el indice libre
 *
 */
int buscarLIbre(eBicicleta listado[], int tam);
/** \brief comprueba la existencia de una bicicleta
 *
 * \param listado[] eBicicleta
 * \param tam int
 * \param id int
 * \return int -1 error o devuelve el indice
 *
 */
int buscarBicicleta(eBicicleta listado[], int tam, int id);
/** \brief baja logica en el array de estructuras
 *
 * \param listado[] eBicicleta
 * \param tam int
 * \param colores[] eColor
 * \param tamC int
 * \param lTipos[] eTipo
 * \param tamT int
 * \return int 1 error 0 OK
 *
 */
int bajaBicicleta(eBicicleta listado[], int tam, eColor colores[], int tamC, eTipo lTipos[], int tamT);
/** \brief Modifica una estructura de bicicleta
 *
 * \param listado[] eBicicleta
 * \param tam int
 * \param unColor[] eColor
 * \param tamC int
 * \param unTiipo[] eTipo
 * \param tamT int
 * \return int 1 error 0 OK
 *
 */
int modificarBicicleta(eBicicleta listado[], int tam, eColor unColor[], int tamC, eTipo unTiipo[], int tamT);
/** \brief hardcodea el array de estructuras
 *
 * \param listado[] eBicicleta
 * \param tam int
 * \param cant int
 * \return int 1 error 0 OK
 *
 */
int hardcodearBicicletas(eBicicleta listado[], int tam, int cant);
/** \brief muestra el array de estructuras
 *
 * \param listado[] eBicicleta
 * \param tam int
 * \param listaC[] eColor
 * \param tamC int
 * \param listaT[] eTipo
 * \param tamT int
 * \return int 1 error 0 OK
 *
 */
int mostrarBicicletasTodo(eBicicleta listado[], int tam, eColor listaC[], int tamC, eTipo listaT[], int tamT);
/** \brief muestra una estructura
 *
 * \param unBicicleta eBicicleta
 * \param unColor[] eColor
 * \param tamC int
 * \param unTipo[] eTipo
 * \param tamT int
 * \return void
 *
 */
void mostrarBicicletaTodo(eBicicleta unBicicleta, eColor unColor[],int tamC ,eTipo unTipo[],int tamT);
/** \brief obtiene la descripcion de color mediante ID
 *
 * \param unColor[] eColor
 * \param tam int
 * \param descripcion[] char
 * \param idColor int
 * \return int 1 error 0 OK
 *
 */
int cargarDescripcionColor(eColor unColor[], int tam, char descripcion[],int idColor);
/** \brief obtiene la descripcion de tipo mediante ID
 *
 * \param unTipo[] eTipo
 * \param tam int
 * \param descripcion[] char
 * \param idTipo int
 * \return int 1 error 0 OK
 *
 */
int cargarDescripcionTipo(eTipo unTipo[], int tam, char descripcion[],int idTipo);
/** \brief obtiene la descri`cion de marca mediante ID
 *
 * \param unaBici[] eBicicleta
 * \param tam int
 * \param descripcion[] char
 * \param idTipo int
 * \return int 1 error 0 OK
 *
 */
int cargarDescripcionMarca(eBicicleta unaBici[], int tam, char descripcion[],int idTipo);

/** \brief ordena el array de estructuras por tipo y al ser iguales los ordena por rodado
 *
 * \param listado[] eBicicleta
 * \param tam int
 * \param listaT[] eTipo
 * \param tamT int
 * \param criterio int
 * \return int 1 error 0 OK
 *
 */
int ordenarBici_tipo_rodado(eBicicleta listado[], int tam, eTipo listaT[], int tamT, int criterio);
/** \brief Obtiene el idTipo mediante la busqueda en el array de bicis
 *
 * \param unaBici[] eBicicleta
 * \param tam int
 * \param idBici int
 * \return int retorna el idTipo
 *
 */
int obtenerIdTipo(eBicicleta unaBici[], int tam, int idBici);
/** \brief verifica la existencia de la bicicleta mediante id
 *
 * \param id int
 * \param bici[] eBicicleta
 * \param tam int
 * \return int 0 error 1 OK
 *
 */
int validarIdBicicleta(int id,eBicicleta bici[], int tam);
