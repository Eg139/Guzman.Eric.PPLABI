#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED

typedef struct
{
    int id;
    char nombre[25];
    char sexo;
}eCliente;

#endif // CLIENTES_H_INCLUDED

/** \brief hardcodea la estructura clientes
 *
 * \param listado[] eCliente
 * \param tam int
 * \param cant int
 * \return int 1 error 0 OK
 *
 */
int hardcodearClientes(eCliente listado[], int tam, int cant);
/** \brief Muestra una estructura de cliente
 *
 * \param unCliente eCliente
 * \return void
 *
 */
void mostrarCliente(eCliente unCliente);
/** \brief muestra el array de estructuras
 *
 * \param listado[] eCliente
 * \param tam int
 * \return int
 *
 */
int mostrarClientes(eCliente listado[], int tam);
/** \brief carga el nombre del cliente mediante ID
 *
 * \param clientes[] eCliente
 * \param tam int
 * \param descripcion[] char
 * \param idCliente int
 * \return int 1 error 0 OK
 *
 */
int cargarDescripcionCliente(eCliente clientes[], int tam, char descripcion[],int idCliente);
