#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[25];
    int precio;
}eServicio;

#endif // SERVICIO_H_INCLUDED

/** \brief mustra todo el array de estructuras
 *
 * \param listado[] eServicio
 * \param tam int
 * \return int 1 error  0 OK
 *
 */
int mostrarServicios(eServicio listado[], int tam);
/** \brief muestra una sola estructura
 *
 * \param unServico eServicio
 * \return void
 *
 */
void mostrarServicio(eServicio unServico);
/** \brief hardcodea la estructura
 *
 * \param listado[] eServicio
 * \param tam int
 * \param cant int
 * \return int retorna el siguiente id a cargarse en la proxima alta
 *
 */
int hardcodearServicios(eServicio listado[], int tam, int cant);
/** \brief obtiene la descripcion de servicio mediante un ID
 *
 * \param unServicio[] eServicio
 * \param tam int
 * \param descripcion[] char
 * \param idTipo int
 * \param precio float
 * \return int 1 error 0 OK
 *
 */
int cargarDescripcionServicio(eServicio unServicio[], int tam, char descripcion[],int idTipo, float precio);
/** \brief obtiene el precio de un servicio mediante ID
 *
 * \param unServicio[] eServicio
 * \param tam int
 * \param idTipo int
 * \return int  el valor del precio buscado por id
 *
 */
int obtenerPrecio(eServicio unServicio[], int tam, int idTipo);
/** \brief verifica que el Id del servicio exista
 *
 * \param id int
 * \param servicios[] eServicio
 * \param tam int
 * \return int 0 error 1 OK
 *
 */
int validarIdServicio(int id,eServicio servicios[], int tam);
