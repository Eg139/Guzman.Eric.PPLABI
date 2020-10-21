#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;

#endif // FECHA_H_INCLUDED

/** \brief muestra una estructura fecha
 *
 * \param fecha eFecha
 * \return void
 *
 */
void mostrarFecha(eFecha fecha);
/** \brief verifica que los dias, meses y anios esten en rango
 *
 * \param dia int
 * \param mes int
 * \param anio int
 * \return int 0 error 1 OK
 *
 */
int validarIdFecha(int dia, int mes, int anio);
