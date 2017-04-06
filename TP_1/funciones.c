#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

/** \brief Suma dos numeros recibidos como parametro
 * \param  nro1 numero a ser sumado
 * \param  nro2 numero a sumar
 * \return resultado de la suma
 *
 */

float suma2nros(float nro1,float nro2)
{
    float resultado;
    resultado=nro1+nro2;
    return resultado;
}





/** \brief Resta dos numeros recibidos como parametro
 * \param  nro1 numero a ser restado
 * \param  nro2 numero a restar
 * \return resultado de la resta
 *
 */

float resta2nros(float nro1,float nro2)
{
    int resultado;
    resultado=nro1-nro2;
    return resultado;
}




/** \brief Divide dos numeros recibidos como parametro
 * \param  nro1 dividendo de la division
 * \param  nro2 divisor de la division
 * \return resultado de la division
 *
 */

float div2nros(float nro1,float nro2)
{
    float resultado;
    resultado=nro1/nro2;
    return resultado;
}





/** \brief Multiplica dos numeros recibidos como parametro
 * \param  nro1 numero a ser multiplicado
 * \param  nro2 numero a multiplicar
 * \return resultado de la multiplicacion
 *
 */
float mult2nros(float nro1,float nro2)
{
    float resultado;
    resultado=nro1*nro2;
    return resultado;
}




/** \brief Calcula el factorial de un numero recibido como parametro
 * \param numero a calcular el factorial
 * \return resultado del factorial
 *
 */

float getsFact(float numero)
{
    float i,r=1;

  for (i=numero;i>1;i--)
    {
    r=r*i;
    }
    return r;

}







