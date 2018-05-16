#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#include "publicacion.h"
#include "utn.h"
#define CANTIDAD_CLI 100
#define CANTIDAD_PUB 1000
int informes_imprimirClientes(Cliente* arrayClientes,int limiteClientes,Publicacion* arrayPublicaciones,int limitePublicaciones);
int informes_imprimirPublicaciones(Cliente* arrayClientes,int limiteClientes,Publicacion* publicaciones,int limitePublicaciones);
//int informes_funcAuxiliarPub(Cliente* arrayClientes,int limiteClientes,Publicacion* arrayPublicaciones,int limitePublicaiones,int idPublicacion);
int informes_cuitClienteAux(Cliente* array,int limiteClientes,int limitePublicaciones,Publicacion* arrayPublicaciones,int idCliente);
int informes_cuitCliente(Cliente* array,int limiteClientes,int limitePublicaciones,Publicacion* arrayPublicaciones,int idCliente);
int informes_conMasAvisos(Cliente* clientes,int limiteClientes,Publicacion* publicaciones,int limitePublicaciones);
int informes_conMasAvisosPausados(Cliente* clientes,int limiteClientes,Publicacion* publicaciones,int limitePublicaciones);
int informes_conMasAvisosActivos(Cliente* clientes,int limiteClientes,Publicacion* publicaciones,int limitePublicaciones);
int informes_cuitCliente(Cliente* array,int limiteClientes,int limitePublicaciones,Publicacion* arrayPublicaciones,int idCliente);
int informes_ingresarRubroImprimirPubs(Publicacion* publicaciones,int limitePublicaciones);
int informes_rubroMasAvisosActivos(Publicacion* publicaciones,int limitePublicaciones);
int informes_rubroMenosAvisosActivos(Publicacion* publicaciones,int limitePublicaciones);

