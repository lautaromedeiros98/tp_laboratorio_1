#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#include "publicacion.h"
#include "utn.h"
#define CANTIDAD_CLI 100
#define CANTIDAD_PUB 1000
int informes_imprimirClientes(Cliente* arrayClientes,int limiteClientes,Publicacion* arrayPublicaciones,int limitePublicaciones)
{
    int retorno,i,cantidad;
    retorno=-1;
    if(limiteClientes>0 && arrayClientes!=NULL && arrayPublicaciones!=NULL)
    {
        retorno=0;
        for(i=0;i<limiteClientes;i++)
        {
            if(arrayClientes[i].isEmpty==0)
            {
            cantidad=publiacion_cantidadPublicaciones(arrayPublicaciones,limitePublicaciones,arrayClientes[i].idCliente);
            printf("Nombre:%s - Apellido:%s - Cuit:%s - Id:%d - Cantidad avisos:%d\n\n\n",arrayClientes[i].nombre,arrayClientes[i].apellido,arrayClientes[i].cuit,arrayClientes[i].idCliente,cantidad);
            }
        }
    }
    return retorno;
}

int informes_cuitCliente(Cliente* array,int limiteClientes,int limitePublicaciones,Publicacion* arrayPublicaciones,int idCliente)
{
    int indice;
    if(limiteClientes>0 && limitePublicaciones>0 && array!=NULL && arrayPublicaciones!=NULL)
    {
        for(indice=0;indice<limiteClientes;indice++)
        {
            if(array[indice].isEmpty==0 && array[indice].idCliente==idCliente)
            {
                return indice;
            }
        }
    }
    return -1;
}


int informes_imprimirPublicaciones(Cliente* arrayClientes,int limiteClientes,Publicacion* publicaciones,int limitePublicaciones)
{
    int retorno = -1;
    int i;
    int indiceB;
    if(limiteClientes > 0 && publicaciones != NULL)
    {
        retorno = 0;
        for(i=0;i<limitePublicaciones;i++)
        {
           if(publicaciones[i].estado==1 && publicaciones[i].isEmpty==0)
           {
               indiceB = informes_cuitCliente(arrayClientes,limiteClientes,limitePublicaciones,publicaciones,publicaciones[i].idCliente);
               printf("Texto de la publicacion : %s , Cuit del cliente: %s \n",publicaciones[i].texto,arrayClientes[indiceB].cuit);
           }
        }
    }
    return retorno;
}



int informes_conMasAvisos(Cliente* clientes,int limiteClientes,Publicacion* publicaciones,int limitePublicaciones)
{
    int i,indiceAux,j,retorno=-1;
    int contador=0;
    int mayor=0;
    if(limiteClientes>0 && clientes!=NULL && limitePublicaciones>0 && publicaciones!= NULL)
    {
            retorno=0;
            for(i=0;i<limiteClientes;i++)
            {
                if(contador>mayor)
                {
                    mayor=contador;
                    indiceAux=i-1;
                }
                contador=0;
                for(j=0;j<limitePublicaciones;j++)
                {
                    if(publicaciones[j].isEmpty==0 && publicaciones[j].idCliente==clientes[i].idCliente)
                    {
                        contador++;
                    }
                }
            }
    }
    printf("El cliente con mas avisos es :%s con una cantidad de :%d\n",clientes[indiceAux].nombre,mayor);
    return retorno;
}


int informes_conMasAvisosActivos(Cliente* clientes,int limiteClientes,Publicacion* publicaciones,int limitePublicaciones)
{
    int i,indiceAux,j,retorno=-1;
    int contador=0;
    int mayor=0;
    if(limiteClientes>0 && clientes!=NULL && limitePublicaciones>0 && publicaciones!= NULL)
    {
            retorno=0;
            for(i=0;i<limiteClientes;i++)
            {
                if(contador>mayor)
                {
                    mayor=contador;
                    indiceAux=i-1;
                }
                contador=0;
                for(j=0;j<limitePublicaciones;j++)
                {
                    if(publicaciones[j].isEmpty==0 && publicaciones[j].idCliente==clientes[i].idCliente && publicaciones[j].estado==1)
                    {
                        contador++;
                    }
                }
            }
    }
    printf("El cliente con mas avisos activos es :%s con una cantidad de :%d\n",clientes[indiceAux].nombre,mayor);
    return retorno;
}


int informes_conMasAvisosPausados(Cliente* clientes,int limiteClientes,Publicacion* publicaciones,int limitePublicaciones)
{
    int i,indiceAux,j,retorno=-1;
    int contador=0;
    int mayor=0;
    if(limiteClientes>0 && clientes!=NULL && limitePublicaciones>0 && publicaciones!= NULL)
    {
            retorno=0;
            for(i=0;i<limiteClientes;i++)
            {
                if(contador>mayor)
                {
                    mayor=contador;
                    indiceAux=i-1;
                }
                contador=0;
                for(j=0;j<limitePublicaciones;j++)
                {
                    if(publicaciones[j].isEmpty==0 && publicaciones[j].idCliente==clientes[i].idCliente && publicaciones[j].estado==0)
                    {
                        contador++;
                    }
                }
            }
    }
    printf("El cliente con mas avisos pausados es :%s con una cantidad de :%d\n",clientes[indiceAux].nombre,mayor);
    return retorno;
}


int informes_ingresarRubroImprimirPubs(Publicacion* publicaciones,int limitePublicaciones)
{
    int i,rubro;
    int contador=0;
    int retorno=-1;
    getValidInt("Ingrese un numero de rubro:","rubro no valido",&rubro,0,100,10);
    if(limitePublicaciones>0 && publicaciones!=NULL)
    {
        retorno=0;
        for(i=0;i<limitePublicaciones;i++)
        {
            if(publicaciones[i].isEmpty==0 && publicaciones[i].rubro==rubro)
            {
                contador++;
            }
        }
    }
    printf("El rubro ingresado tiene %d publicaciones\n",contador);
    return retorno;
}

int informes_rubroMasAvisosActivos(Publicacion* publicaciones,int limitePublicaciones)
{
    int i,indice,j;
    int retorno=-1;
    int mayor=0;
    int contador=0;
    if(limitePublicaciones>0 && publicaciones!=NULL)
    {
        retorno=0;
        for(i=0;i<limitePublicaciones;i++)
        {
            if(contador>mayor)
            {
                mayor=contador;
                indice=i-1;
            }
            contador=0;
            for(j=i+1;j<limitePublicaciones;j++)
            {
                if(publicaciones[j].isEmpty==0 && publicaciones[j].estado==1 && publicaciones[j].rubro == publicaciones[i].rubro)
                {
                    contador++;
                }
            }
        }
    }
    printf("El rubro con mas avisos activos es el %d con una cantidad de: %d avisos \n",publicaciones[indice].rubro,mayor);
    return retorno;
}


int informes_rubroMenosAvisosActivos(Publicacion* publicaciones,int limitePublicaciones)
{
    int i,indice,j;
    int retorno=-1;
    int mayor=0;
    int contador=0;
    if(limitePublicaciones>0 && publicaciones!=NULL)
    {
        retorno=0;
        for(i=0;i<limitePublicaciones;i++)
        {
            if(contador<mayor)
            {
                mayor=contador;
                indice=i-1;
            }
            contador=0;
            for(j=i+1;j<limitePublicaciones;j++)
            {
                if(publicaciones[j].isEmpty==0 && publicaciones[j].estado==1 && publicaciones[j].rubro == publicaciones[i].rubro)
                {
                    contador++;
                }
            }
        }
    }
    printf("El rubro con menos avisos activos es el %d con una cantidad de: %d avisos \n",publicaciones[indice].rubro,mayor);
    return retorno;
}
