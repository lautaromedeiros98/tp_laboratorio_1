#include <stdio.h>
#include <stdlib.h>

/** \brief Solicita un numero entero al usuario
 *
 * \param mensaje char* Mensaje a ser mostrado que define la caracteristica del dato a ingresar(edad,longitud,etc)
 * \param mensajeError char* Mensaje a ser mostrado en caso de error
 * \param reIntentos int Cantidad de intentos permitidos
 * \param minimo int limite minimo de numeros enteros
 * \param maximo int limite maximo de numeros enteros
 * \param resultado int* numero ingresado por el usuario
 * \return int devuelve -1 en caso de error y 0 si el numero ingresado es entero
 *
 */
int getInt(char* mensaje,char* mensajeError,int reIntentos,int minimo,int maximo,int* resultado)
{
    int retorno = -1;
    char buffer[4096];
    long auxiliarLong;
    do
    {
        printf("%s",mensaje);
        scanf("%4095s",buffer);
        if(esEntero(buffer) == 1)
        {
            auxiliarLong = atol(buffer);
            if(auxiliarLong >= minimo && auxiliarLong <= maximo)
            {
                *resultado = (int)auxiliarLong;
                retorno = 0;
                break;
            }
        }
        printf("%s",mensajeError);
        reIntentos--;
    }while(reIntentos >= 0);
    return retorno;
}


/** \brief  verifica si el numero ingresado por el usuario es entero
 *
 * \param str char* se ingresa el numero como un array
 * \return int devuelve 1 en caso de que el numero no sea entero
 *
 */
int esEntero(char *str)
{
    int i;
    for(i=0;str[i] != '\0';i++)
    {
        if(str[i] > '9' || str[i] < '0')
            return 0;
    }
    return 1;
}

/** \brief  opciones con las que puede trabajar el usuario
 *
 * \return void
 *
 */
void menu()
{
        printf("*****INGRESE...***** \n");
        printf("1- Ingresar 1er operando \n");
        printf("2- Ingresar 2do operando \n");
        printf("3- Calcular la suma \n");
        printf("4- Calcular la resta \n");
        printf("5- Calcular la division \n");
        printf("6- Calcular la multiplicacion \n");
        printf("7- Calcular el factorial \n");
        printf("8- Calcular todas las operacione\n");
        printf("9- Salir\n");

}

/** \brief suma dos numeros enteros
 *
 * \param primerNumero int primer numero ingresado por el usuario
 * \param segundoNumero int segundo numero ingresado por el usuario
 * \param resultado int* resultado de la suma
 * \return int devuelve-1 en caso de error OverFlow
 *
 */
int sumaEnteros(int primerNumero, int segundoNumero, int* resultado)
{
    long resultadoAuxiliar;
    int retorno= -1;
    resultadoAuxiliar=primerNumero+segundoNumero;
    if(resultadoAuxiliar<32676 && resultadoAuxiliar>-32676 )
    {
        *resultado=resultadoAuxiliar;
        retorno=0;

    }
    else
    {
        retorno=-1;
        printf("ERROR fuera de rango \n");
    }
    return retorno;
}

/** \brief resta dos numeros enteros
 *
 * \param primerNumero int primer numero ingresado por el usuario
 * \param segundoNumero int segundo numero ingresado por el usuario
 * \param resultado int* resultado de la resta
 * \return int devuelve-1 en caso de error OverFlow
 *
 */
int restaEnteros(int primerNumero, int segundoNumero, int* resultado)
{
    long resultadoAuxiliar;
    int retorno= -1;
    resultadoAuxiliar=primerNumero-segundoNumero;
    if(resultadoAuxiliar<32676 && resultadoAuxiliar>-32676 )
    {
        *resultado=resultadoAuxiliar;
        retorno=0;
    }
    else
    {
        retorno=-1;
        printf("ERROR fuera de rango \n");
    }
    return retorno;
}

/** \brief multiplica dos numeros enteros
 *
 * \param primerNumero int primer numero ingresado por el usuario
 * \param segundoNumero int segundo numero ingresado por el usuario
 * \param resultado int* producto de la multiplicacion entre los numeros ingresados
 * \return int devuelve-1 en caso de error OverFlow
 *
 */
int multiplicacionEnteros(int primerNumero, int segundoNumero, int* resultado)
{
    long resultadoAuxiliar;
    int retorno= -1;
    resultadoAuxiliar=primerNumero*segundoNumero;
    if(resultadoAuxiliar<32676 && resultadoAuxiliar>-32676 )
    {
        *resultado=resultadoAuxiliar;
        retorno=0;
    }
    else
    {
        retorno=-1;
        printf("ERROR fuera de rango \n");
    }
    return retorno;
}

/** \brief divide dos numeros enteros
 *
 * \param primerNumero int primer numero ingresado por el usuario
 * \param segundoNumero int segundo numero ingresado por el usuario
 * \param resultadoDivision float* resultado flotante de la division entre los numeros enteros
 * \return int devuelve int devuelve-1 en caso de error OverFlow
 *
 */
int divisionEnteros(int primerNumero, int segundoNumero, float* resultadoDivision)
{
    float resultadoAuxiliar;
    int retorno= -1;
    resultadoAuxiliar=(float)primerNumero/(float)segundoNumero;
    if(resultadoAuxiliar>0 )
    {
        *resultadoDivision=resultadoAuxiliar;
        retorno=0;
    }
    else
    {
        retorno=-1;
        printf("ERROR fuera de rango \n");
    }
    return retorno;
}

/** \brief calcula el factorial de los numeros ingresados
 *
 * \param primerNumero int numeros ingresados por el usuario
 * \param resultado int* el factorial de los numeros ingresados por el usuario
 * \return int devuelve-1 en caso de error OverFlow
 *
 */
int factorial(int primerNumero,int* resultado)
{

    int retorno= -1;
    int i;
    long acumulador=1;
    if(primerNumero<15)
        {
            for(i=1;i<=primerNumero;i++)
            {
                acumulador=acumulador*i;
            }
            if(acumulador<2147483647 && acumulador>-2147483648)
            {
                *resultado=acumulador;
                retorno=0;
            }
        }
    else
        {
            retorno=-1;
        }
    return retorno;
}

/** \brief pregunta al usuario si quiere terminar con el programa o reiniciarlo
 *
 * \return void
 *
 */
void pregunta()
 {
     printf("\n ***INGRESE 9 PARA TERMINAR EL PROGRAMA*** \n ***INGRESE 10 PARA REINICIAR*** \n");
 }

 /** \brief pregunta al usuario si quiere realizar otra operacion con los mismos numeros ya ingresados
  *
  * \return void
  *
  */
 void preguntaDos()
 {
     printf("***** O INGRESE 3,4,5,6,7,8 PARA REALIZAR LAS DEMAS OPERACIONES***** \n");
 }

