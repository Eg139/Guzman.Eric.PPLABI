#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

typedef struct
{
    int id;
    char nombreColor[20];
}eColor;

#endif // COLOR_H_INCLUDED

/** \brief muestra todo el array de estructuras
 *
 * \param listado[] eColor
 * \param tam int
 * \return int 1 error 0 OK
 *
 */
int mostrarColores(eColor listado[], int tam);
/** \brief muestra una estructura
 *
 * \param unColor eColor
 * \return void
 *
 */
void mostrarColor(eColor unColor);
/** \brief hardcodea la estructura
 *
 * \param listado[] eColor
 * \param tam int
 * \param cant int
 * \return int 1 error 0 OK
 *
 */
int hardcodearColores(eColor listado[], int tam, int cant);
/** \brief verifica la existencia del Color mediante ID
 *
 * \param id int
 * \param colores[] eColor
 * \param tam int
 * \return int 0 error 1 OK
 *
 */
int validarIdColor(int id,eColor colores[], int tam);
