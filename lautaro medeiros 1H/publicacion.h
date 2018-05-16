#ifndef PUBLICACION_H_INCLUDED
#define PUBLICACION_H_INCLUDED
typedef struct
{
    char texto[64];
    int idCliente;
    int rubro;
    int estado;
    //------------
    int idPublicacion;
    int isEmpty;
}Publicacion;
#endif // PUBLICACION_H_INCLUDED
#include "cliente.h"

int publicacion_init(Publicacion* array,int limite);
int publicacion_buscarPorId(Publicacion* array,int limite, int id);
int publicacion_baja(Publicacion* array,int limite, int id);

int publicacion_mostrar(Publicacion* array,int limite);
int publicacion_mostrarDebug(Publicacion* array,int limite);
int publicacion_alta(Publicacion* array,int limite,Cliente* arrayClientes,int limiteClientes);
int publicacion_modificacion(Publicacion* array,int limite, int id);
int publicacion_ordenar(Publicacion* array,int limite, int orden);
int obtenerIdExistente(Cliente* array,int limite,int* idCliente);
int idPublicacionExistente(Publicacion* array,int limite,int *idPublicacion,int *indice);
int publicacion_renaudarPublicacion(Publicacion* array,int limite, int id);
int publicacion_pausarPublicacion(Publicacion* array,int limite, int id);
int publiacion_cantidadPublicaciones(Publicacion* array,int limite,int idCliente);



