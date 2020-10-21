#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];
}eTipo;

#endif // TIPO_H_INCLUDED

/** \brief muestra todas las estructuras del array
 *
 * \param listado[] eTipo
 * \param tam int
 * \return int 1 error 0 OK
 *
 */
int mostrarTipos(eTipo listado[], int tam);
/** \brief muestra una sola estructura
 *
 * \param unTipo eTipo
 * \return void
 *
 */
void mostrarTipo(eTipo unTipo);
/** \brief harcodea la estructura
 *
 * \param listado[] eTipo
 * \param tam int
 * \param cant int
 * \return int retorna el siguiente id a cargarse en la proxima alta
 *
 */
int hardcodearTipos(eTipo listado[], int tam, int cant);
/** \brief verifica que exista el Id en la estructura
 *
 * \param id int
 * \param unTipo[] eTipo
 * \param tam int
 * \return int 0 invalido 1 valido
 *
 */
int validarIdTipo(int id,eTipo unTipo[], int tam);
