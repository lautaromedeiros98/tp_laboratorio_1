#include "ArrayList.h"
#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED

typedef struct
{
  int id;
  char nombre[128];
  int horasTrabajadas;
}Empleado;

int em_trabajaMasDe120Horas(void* item);

#endif // EMPLEADO_H_INCLUDED
void empleado_delete(Empleado* this);

Empleado* empleado_new();

Empleado* empleado_newParametros(int horas,char* nombre,int id);

int empleado_setHoras(Empleado* this, float horas);

int empleado_getHoras(Empleado* this,int* horas);

int empleado_setNombre(Empleado* this, char* nombre);

int empleado_getNombre(Empleado* this, char* nombre);

int empleado_setId(Empleado* this, int ids);

int empleado_getId(Empleado* this, int* id);

int empleado_filtro(ArrayList* this,Empleado* auxiliar,int i);
