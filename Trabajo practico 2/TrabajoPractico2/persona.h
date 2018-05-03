#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED
typedef struct
{
    char nombre[50];
    int edad;
    int dni;
    //------------
    int idPersona;
    int isEmpty;
}Persona;
#endif // PERSONA_H_INCLUDED
int persona_init(Persona* array,int limite);
int persona_buscarPorId(Persona* array,int limite, int id);
int persona_baja(Persona* array,int limite, int id);
int persona_mostrar(Persona* array,int limite);
int persona_mostrarDebug(Persona* array,int limite);
int persona_alta(Persona* array,int limite);
int persona_modificacion(Persona* array,int limite, int id);
int persona_ordenar(Persona* array,int limite, int orden);
int contador(Persona * array,int limite, int * contadorA , int * contadorB );
int buscarLugarLibre(Persona* array,int limite);
int proximoId();
void graficoDatos(Persona * array, int menor18,int de19a35, int mayorDe35,int total,int limite);






