#include <stdio.h>
#include <stdlib.h>

/** \brief Pide al numero que ingreso el usuario.
 * \param  mensaje - imprime el mensaje.
 * \return x - el numero que ingreso el usuario.
 */

float getNumero1(char mensaje[])
{
    float x;
    printf("%s", mensaje);
    scanf("%f", &x);

    return x;
}

float getNumero2(char mensaje[])
{
    float y;
    printf("%s", mensaje);
    scanf("%f", &y);

    return y;
}

/** \brief Calcula la suma de dos numeros
 * \param mensaje - imprime el mensaje
 * \param x - primer numero que ingreso el usuario
 * \param y - segundo numero que ingreso el usuario
 * \return suma - devuelve la suma
 */

float sumar(char mensaje[], float x, float y)
{
    float suma = 0;
    if(x == 0 && y == 0){
        printf("No se ingreso un numero");}
    else
    {
        suma = x + y;
        printf("%s %f", mensaje, suma);}

	return suma;
}

/** \brief Calcula la resta de dos numeros
 * \param mensaje - imprime el mensaje
 * \param x - primer numero que ingreso el usuario
 * \param y - segundo numero que ingreso el usuario
 * \return resta - devuelve la resta
 */

float restar(char mensaje[], float x, float y)
{
	float resta = 0;
	resta = x - y;

    printf("%s %f", mensaje, resta);

	return resta;
}

/** \brief Calcula la division de dos numeros
 * \param mensaje - imprime el mensaje
 * \param x - primer numero que ingreso el usuario
 * \param y - segundo numero que ingreso el usuario
 * \return division - devuelve la division
 */

float dividir(char mensaje[], float x, float y)
{
	float division = 0;
	division = x / y;

	if(y == 0)
    {
        printf("No se puede dividir por cero");
    }
    else{
        printf("%s %f", mensaje, division);
    }

	return division;
}

/** \brief Calcula la multplicación de dos numeros
 * \param mensaje - imprime el mensaje
 * \param x - primer numero que ingreso el usuario
 * \param y - segundo numero que ingreso el usuario
 * \return multipl - devuelve la multiplicacion
 */

float producto(char mensaje[], float x, float y)
{
	float multipl = 0;
	multipl = x * y;

	printf("%s %f", mensaje, multipl);

	return multipl;
}

/** \brief Calcula el factorial de un numero
 * \param mensaje - imprime el mensaje
 * \param x - numero que ingreso el usuario
 * \return factor - devuelve el factorial
 */

 long long factorial(char mensaje[], long long int x)
{
	long long int factor=1;
	int i;
	for(i=x ; i>=1; i--)
	{
		factor = factor *i;
	}

	printf("%s  %lli", mensaje, factor);

	return factor;
}
 /*int validar (int x, int y)
 {


     return 0;
 } */
