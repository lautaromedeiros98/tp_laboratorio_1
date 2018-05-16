#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#include "utn.h"
#include "publicacion.h"
#include "informes.h"
#define CANTIDAD_CLI 100
#define CANTIDAD_PUB 1000

int main()
{
    Cliente clientes[CANTIDAD_CLI];
    Publicacion publicaciones[CANTIDAD_PUB];

    int auxiliar;
    int auxiliarDos;
    int flagAlta;
    int flagAltaDos;

    cliente_init(clientes,CANTIDAD_CLI);
    publicacion_init(publicaciones,CANTIDAD_PUB);
    do
    {
        getValidInt("1.ALTA DE CLIENTE\n2.MODIFICAR DATOS DEL CLIENTE\n3.BAJA DE CLIENTE\n4.PUBLICAR\n5.PAUSAR PUBLICACION\n6.RENAUDAR PUBLICACION\n7.IMPRIMIR CLIENTES\n8.IMPRIMIR PUBLICACIONES\n9.INFORMAR CLIENTES\n10.INFORMAR PUBLICACIONES POR RUBRO\n11.INFORMAR PUBLICACIONES\n12.SALIR\n\n\n","Ingrese una opcion valida\n\n",&auxiliar,0,12,10);
        switch(auxiliar)
        {
        case 1:
            if(!cliente_alta(clientes,CANTIDAD_CLI))
            {
                flagAlta=1;
            }
            break;
        case 2:
            if(flagAlta==1)
            {
                cliente_mostrar(clientes,CANTIDAD_CLI);
                getValidInt("Id del cliente a modificar?\n","Id no valido\n",&auxiliarDos,0,CANTIDAD_CLI,10);
                cliente_modificacion(clientes,CANTIDAD_CLI,auxiliarDos);
            }
            else
            {
                printf("\n*ERROR* No hay cliente dado de alta\n\n\n");
            }
            break;
        case 3:
             if(flagAlta==1)
            {
                cliente_mostrar(clientes,CANTIDAD_CLI);
                getValidInt("Id del cliente a dar de baja?\n","Id no valido\n",&auxiliarDos,0,CANTIDAD_CLI,10);
                cliente_baja(clientes,CANTIDAD_CLI,auxiliarDos);
            }
            else
            {
                printf("\n*ERROR* No hay cliente dado de alta\n\n\n");
            }
            break;
        case 4:
            if(flagAlta==1)
            {
                cliente_mostrar(clientes,CANTIDAD_CLI);
                if(!publicacion_alta(publicaciones,CANTIDAD_PUB,clientes,CANTIDAD_CLI))
                {
                    flagAltaDos=1;
                }
            }
            else
            {
                printf("\n*ERROR* No hay cliente dado de alta\n\n\n");
            }
            break;
        case 5:
            if(flagAltaDos==1)
            {
                publicacion_mostrar(publicaciones,CANTIDAD_PUB);
                getValidInt("Id de la publicacion a pausar?","id no valido\n",&auxiliarDos,0,CANTIDAD_PUB,10);
                publicacion_pausarPublicacion(publicaciones,CANTIDAD_PUB,auxiliarDos);
            }
            else
            {
                printf("*ERROR* No hay publicaciones dadas de alta\n\n");
            }
            break;
        case 6:
            if(flagAltaDos==1)
            {
                publicacion_mostrar(publicaciones,CANTIDAD_PUB);
                getValidInt("Id de la publicacion a renaudar?","id no valido\n",&auxiliarDos,0,CANTIDAD_PUB,10);
                publicacion_renaudarPublicacion(publicaciones,CANTIDAD_PUB,auxiliarDos);
            }
            else
            {
                printf("*ERROR* No hay publicaciones dadas de alta\n\n");
            }
            break;
        case 7:
            if(flagAlta==1 && flagAltaDos==1)
            {
                informes_imprimirClientes(clientes,CANTIDAD_CLI,publicaciones,CANTIDAD_PUB);
            }
            else
            {
                printf("*ERROR* No hay cliente o publicacion dada de alta\n\n");
            }
            break;
        case 8:
            if(flagAlta==1 && flagAltaDos==1)
            {
                informes_imprimirPublicaciones(clientes,CANTIDAD_CLI,publicaciones,CANTIDAD_PUB);
            }
            else
            {
                printf("*ERROR* No hay cliente o publicacion dada de alta\n\n");
            }
            break;
        case 9:
            if(flagAlta==1 && flagAltaDos==1)
            {
                informes_conMasAvisosActivos(clientes,CANTIDAD_CLI,publicaciones,CANTIDAD_PUB);
                informes_conMasAvisosPausados(clientes,CANTIDAD_CLI,publicaciones,CANTIDAD_PUB);
                informes_conMasAvisos(clientes,CANTIDAD_CLI,publicaciones,CANTIDAD_PUB);
            }
            else
            {
                printf("*ERROR* No hay cliente o publicacion dada de alta\n\n");
            }
            break;
        case 10:
            if(flagAlta==1 && flagAltaDos==1)
            {
                informes_ingresarRubroImprimirPubs(publicaciones,CANTIDAD_PUB);
            }
            break;
        case 11:
            if(flagAlta==1 && flagAltaDos==1)
            {
                informes_rubroMasAvisosActivos(publicaciones,CANTIDAD_PUB);
                informes_rubroMenosAvisosActivos(publicaciones,CANTIDAD_PUB);
                break;
            }
        }
    }while(auxiliar != 12);
    return 0;
}
