#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "persona.h"
#include "funciones.h"
#define QTY 10
#define OCUPADO 0
#define LIBRE 1
#define cantidad 20


int persona_init(Persona* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            array[i].isEmpty = 1;
        }
    }
    return retorno;
}

int persona_buscarPorId(Persona* array,int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(array[i].isEmpty == OCUPADO && array[i].idPersona == id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int persona_baja(Persona* array,int limite, int id)
{

    int retorno = -1;
    int indice;
    indice = persona_buscarPorId(array,limite,id);
    if(indice >= 0)
    {
        retorno = 0;
        array[indice].isEmpty = LIBRE;
    }
    return retorno;
}


int persona_mostrar(Persona* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty)
            {
               printf("\nNombre: %s - Edad: %d - Dni: %d - Id: %d \n",array[i].nombre,array[i].edad,array[i].dni,array[i].idPersona);
            }
        }
    }
    return retorno;
}

int persona_mostrarDebug(Persona* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            printf("\n[DEBUG] %s - %d - %d",array[i].nombre,array[i].idPersona,array[i].isEmpty);
        }
    }
    return retorno;
}


int persona_alta(Persona* array,int limite)
{
    int retorno = -1;
    char nombre[50];
    int dni;
    int edad;
    int id;
    int indice;
        if(limite > 0 && array != NULL)
        {
            retorno = -2;
            indice = buscarLugarLibre(array,limite);
            if(indice >= 0)
            {
                retorno = -3;
                id = proximoId();
                if(!getValidString("**INGRESE EL NOMBRE DE LA PERSONA**\n","Ingrese un nombre valido SOLO LETRAS \n","Overflow", nombre,50,100))
                {
                    if(!getValidInt("**INGRESE LA EDAD DE LA PERSONA**\n","Ingrese una edad valida de 0 a 100\n",&edad,0,100,200))
                    {
                        if(!getValidInt("**INGRESE EL DNI DE LA PERSONA**\n","Ingrese un dni correcto \n",&dni,0,99999999,100))
                        {
                            retorno = 0;
                            strcpy(array[indice].nombre,nombre);
                            array[indice].edad = edad;
                            array[indice].dni = dni;
                            array[indice].idPersona = id;
                            array[indice].isEmpty = OCUPADO;
                            printf("\n El id de esa persona es %d \n", id);
                        }
                    }
                }
            }
        }

    return retorno;
}



int persona_modificacion(Persona* array,int limite, int id)
{
    int retorno = -1;
    int indice;
    char nombre[50];
    indice = persona_buscarPorId(array,limite,id);
    if(indice >= 0)
    {
        retorno = -2;
        if(!getValidString("Nombre?","Error","Overflow", nombre,50,2))
        {
            retorno = 0;
            strcpy(array[indice].nombre,nombre);
        }


    }
    return retorno;
}


int buscarLugarLibre(Persona* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(array[i].isEmpty == LIBRE)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}


int proximoId()
{
    static int ultimoId = -1;
    ultimoId++;
    return ultimoId;
}



int persona_ordenar(Persona* array,int limite, int orden)
{
    int retorno = -1;
    int flagSwap;
    int i;
    Persona auxiliar;

    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        do
        {
            flagSwap = 0;
            for(i=0;i<limite-1;i++)
            {
                    if(array[i].isEmpty == OCUPADO && array[i+1].isEmpty == OCUPADO )
                    {
                        if((strcmp(array[i].nombre,array[i+1].nombre) > 0 && !orden) || (strcmp(array[i].nombre,array[i+1].nombre) < 0 && orden)) //<------------
                        {
                            auxiliar = array[i];
                            array[i] = array[i+1];
                            array[i+1] = auxiliar;
                            flagSwap = 1;
                        }
                    }
            }
        }while(flagSwap);
    }

    return retorno;
}




void graficoDatos(Persona * array, int menor,int joven, int mayor,int total,int limite) //Arma un grafico por edades.
{
    int i,flag;
    for(i=0; i<limite; i++)
    {
        flag=0;

        if(array[i].isEmpty == OCUPADO)
        {
            if(array[i].edad<=18)
            {
                menor++;
            }
            else
            {
                if(array[i].edad>35)
                {
                    mayor++;
                }
                else
                {
                    joven++;
                }
            }

        }
    }
    if(menor >= joven && menor >= mayor)
    {
        total = menor;
    }
    else
    {
        if(joven >= menor && joven >= mayor)
        {
            total = joven;
        }
        else
        {
            total = mayor;
        }
    }
    for(i=total; i>0; i--)
    {
        if(i<10)
        {
            printf("%02d|",i);
        }
        else
        {
            printf("%02d",i);
        }
        if(i<=menor)
        {
            printf(" *");
        }
        if(i<=joven)
        {
            flag = 1;
            printf("\t   *");
        }
        if(i<= mayor)
        {
            if(flag == 0)
            {
                printf("\t\t *");
            }
            if(flag == 1)
            {
                printf("\t  *");
            }
        }
        printf("\n");
    }
    printf("--------------------");
    printf("\n  |<18|\t|19-35|\t|>35| \n ");
}





































