#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"


int main()

{
    int primerOperando;
    int segundoOperando;
    int opcion;
    int resultado;
    float resultadoDivision;
    int flagUno;
    int flagDos;
    menu();
    char seguir='s';
    while(seguir=='s')
    {
        scanf("%d",&opcion);
        switch(opcion)
        {
    case 1:
        if(getInt("*****INGRESE PRIMER OPERANDO***** \n","ERROR no es un entero \n" ,10,-32676,32676,&primerOperando)==0)
        {
            printf("\n El primer operando es %d \n *****PRECIONE 2 PARA INGRESAR UN SEGUNDO OPERADOR***** \n ",primerOperando);
            flagUno=1;
        }
        break;
    case 2:
        if(getInt("*****INGRESE SEGUNDO OPERANDO***** \n","ERROR no es un entero \n" ,10,-32676,32676,&segundoOperando)==0)
        {
            printf("\n El segundo operando es %d \n *****INGRESE NUMERO CORRESPONDIENTE A LA OPERACION A REALIZAR***** \n",segundoOperando);
            flagDos=2;
        }
        break;
    case 3:
        if(flagUno==1 && flagDos==2)
        {
            sumaEnteros(primerOperando,segundoOperando,&resultado);
            printf("\n el resultado de la suma es %d \n",resultado);
        }
        else
        {
            printf("\n ¡ERROR! Falta algun operador \n");
        }
        pregunta();
        preguntaDos();
        break;
    case 4:
        if(flagUno==1 && flagDos==2)
        {
            restaEnteros(primerOperando,segundoOperando,&resultado);
            printf("\n el resultado de la resta es %d \n",resultado);
        }
        else
        {
            printf("\n ¡ERROR! Falta algun operador \n");
        }
        pregunta();
        preguntaDos();
        break;
    case 5:
        if(segundoOperando!=0)
        {
            if(flagUno==1 && flagDos==2)
            {
                divisionEnteros(primerOperando,segundoOperando,&resultadoDivision);
                printf("\n el resultado de la division es %.2f \n",resultadoDivision);
            }
            else
            {
                printf("\n ¡ERROR! Falta algun operador \n");
            }
         }
         else
         {
             printf("\n ERROR no se puede dividir si el segundo operando es 0");
         }
        pregunta();
        preguntaDos();
        break;

    case 6:
        if(flagUno==1 && flagDos==2)
        {
            multiplicacionEnteros(primerOperando,segundoOperando,&resultado);
            printf("\n el producto de la multiplicacion es %d \n",resultado);
        }
        else
        {
            printf("\n ¡ERROR! Falta algun operador \n");
        }
        pregunta();
        preguntaDos();
        break;
    case 7:
        if(flagUno==1 && primerOperando<15)
        {
            factorial(primerOperando,&resultado);
            printf("\n el factorial del primer operando es %d \n",resultado);
        }
        else
        {
            printf("\n ¡ERROR! solo se puede trabajar con el factorial de numeros menores a 15 \n");
        }
        if (flagDos==2 && segundoOperando<15)
        {
            factorial(segundoOperando,&resultado);
            printf("\n el factorial del segundo operando es %d \n",resultado);
        }
        else
        {
            printf("\n ¡ERROR! solo se puede trabajar con el factorial de numeros menores a 15 \n");
        }
        pregunta();
        preguntaDos();
        break;
    case 8:
        if (flagUno==1 && flagDos==2)
        {
            sumaEnteros(primerOperando,segundoOperando,&resultado);
            printf("\n el resultado de la suma es %d \n",resultado);
            restaEnteros(primerOperando,segundoOperando,&resultado);
            printf("\n el resultado de la resta es %d \n",resultado);
            if(segundoOperando!=0)
               {
                divisionEnteros(primerOperando,segundoOperando,&resultadoDivision);
                printf("\n el resultado de la division es %.2f \n",resultadoDivision);
                }
                else
                    {
                        printf("\n ERROR no se puede dividir si el segundo operando es 0");
                    }
            multiplicacionEnteros(primerOperando,segundoOperando,&resultado);
            printf("\n el producto de la multiplicacion es %d \n",resultado);
            if(primerOperando<15)
                {
                    factorial(primerOperando,&resultado);
                    printf("\n el factorial del primer operando es %d \n",resultado);
                }
                else
                {
                    printf("\n ¡ERROR! solo se puede  trabajar con el factorial de numeros menores a 15 ");
                }
            if(segundoOperando<15)
                {
                    factorial(segundoOperando,&resultado);
                    printf("\n el factorial del segundo operando es %d \n",resultado);
                }
                else
                {
                    printf("\n ¡ERROR! solo se puede  trabajar con el factorial de numeros menores a 15 ");
                }

                }
        else
        {
            printf("\n ¡ERROR! Falta algun operador \n");
        }
        pregunta();
        preguntaDos();
        break;
    case 9:
            seguir='n';
            break;
    case 10:
        system("cls");
        menu();
        break;
    default:
        printf("*****INGRESE UNA OPCION CORRECTA***** \n");
        break;
        }


    }

    return 0;
}
