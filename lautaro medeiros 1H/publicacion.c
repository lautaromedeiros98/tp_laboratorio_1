#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#include "publicacion.h"
#include "utn.h"
#define QTY 10
#define OCUPADO 0
#define LIBRE 1
#define ACTIVA 1
#define PAUSADA 0

static int buscarLugarLibre(Publicacion* array,int limite);
static int proximoId();

int publicacion_init(Publicacion* array,int limite)
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

int publicacion_buscarPorId(Publicacion* array,int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(array[i].isEmpty == OCUPADO && array[i].idPublicacion == id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int publicacion_baja(Publicacion* array,int limite, int id)
{

    int retorno = -1;
    int indice;
    indice = publicacion_buscarPorId(array,limite,id);
    if(indice >= 0)
    {
        retorno = 0;
        array[indice].isEmpty = LIBRE;
    }
    return retorno;
}


int publicacion_mostrar(Publicacion* array,int limite)
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
               printf("\n Texto de la publicacion:%s - ID de la publicacion%d - Estado:%d\n\n",array[i].texto,array[i].idPublicacion,array[i].estado);
            }
        }
    }
    return retorno;
}

int publicacion_mostrarDebug(Publicacion* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            printf("\n %s - %d - %d",array[i].texto,array[i].idPublicacion,array[i].estado);
        }
    }
    return retorno;
}


int publicacion_alta(Publicacion* array,int limite,Cliente* arrayClientes,int limiteClientes)
{
    int retorno = -1;
    char texto[65];
    int rubro;
    int idCliente;
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
            if(!getValidString("Texto de la publicacion:","Error","Overflow",texto,50,2))
            {
                if(!getValidInt("Ingrese un rubro del 1 al 5","error",&rubro,0,5,10))
                {
                    if(!obtenerIdExistente(arrayClientes,limiteClientes,&idCliente))
                    {
                        retorno = 0;
                        array[indice].rubro=rubro;
                        array[indice].idCliente=idCliente;
                        array[indice].idPublicacion=id;
                        array[indice].estado=ACTIVA;
                        array[indice].isEmpty=OCUPADO;
                        strcpy(array[indice].texto,texto);
                    }
                }
            }
        }
    }
    return retorno;
}


/*
int publicacion_modificacion(Publicacion* array,int limite, int id)
{
    int retorno = -1;
    int indice;
    char nombre[50];
    indice = publicacion_buscarPorId(array,limite,id);
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
*/

static int buscarLugarLibre(Publicacion* array,int limite)
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


static int proximoId()
{
    static int ultimoId = -1;
    ultimoId++;
    return ultimoId;
}

/*

int publicacion_ordenar(Publicacion* array,int limite, int orden)
{
    int retorno = -1;
    int flagSwap;
    int i;
    Publicacion auxiliar;

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
*/


int obtenerIdExistente(Cliente* array,int limite,int* idCliente)
{
    int i,auxiliar,retorno;
    retorno=-1;
    getValidInt("Id del cliente?","error",&auxiliar,0,500,10);
    if(limite>0 && array!=NULL)
    {
        for(i=0;i<limite;i++)
        {
            if(array[i].isEmpty==0 && array[i].idCliente==auxiliar)
            {
                *idCliente = auxiliar;
                retorno=0;
            }
        }
    }
    return retorno;
}

int idPublicacionExistente(Publicacion* array,int limite,int *idPublicacion,int *indice)
{
    int i,auxiliar,retorno;
    retorno=-1;
    getValidInt("Id de la publicacion?","Error",&auxiliar,0,500,10);
    if(limite>0 && array!=NULL)
    {
        for(i=0;i<limite;i++)
        {
            if(array[i].isEmpty==0 && array[i].idPublicacion == auxiliar)
            {
                *idPublicacion=auxiliar;
                *indice=i;
                retorno=0;
            }
        }
    }
    return retorno;
}

int publicacion_pausarPublicacion(Publicacion* array,int limite, int id)
{

    int retorno = -1;
    int indice;
    indice = publicacion_buscarPorId(array,limite,id);
    if(indice >= 0)
    {
        retorno = 0;
        array[indice].estado = PAUSADA;
    }
    return retorno;
}

int publicacion_renaudarPublicacion(Publicacion* array,int limite, int id)
{

    int retorno = -1;
    int indice;
    indice = publicacion_buscarPorId(array,limite,id);
    if(indice >= 0)
    {
        retorno = 0;
        array[indice].estado = ACTIVA;
    }
    return retorno;
}


int publiacion_cantidadPublicaciones(Publicacion* array,int limite,int idCliente)
{
    int i;
    int avisos=0;
    if(limite >0 && array!=NULL)
    {
        for(i=0;i<limite;i++)
        {
            if(array[i].isEmpty==0 && array[i].idCliente==idCliente)
            {
               avisos++;
            }
        }
    }
    return avisos;
}




































