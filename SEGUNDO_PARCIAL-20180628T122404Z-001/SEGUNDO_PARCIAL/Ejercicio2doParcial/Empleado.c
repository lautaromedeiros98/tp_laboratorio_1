#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Empleado.h"
#include "ArrayList.h"
#include "Parser.h"

void empleado_delete(Empleado* this)
{
    free(this);
}
Empleado* empleado_new()
{
    return (Empleado*) malloc(sizeof(Empleado));
}
Empleado* empleado_newParametros(int horas,char* nombre,int id)
{
    Empleado* auxiliar = empleado_new();
    if(!empleado_setNombre(auxiliar,nombre) && !empleado_setHoras(auxiliar,horas) && !empleado_setId(auxiliar,id))
       {
           return auxiliar;
       }
    empleado_delete(auxiliar);
    return NULL;
}
int empleado_setHoras(Empleado* this, float horas)
{
    int retorno = -1;
    if(this != NULL && horas > 0)
    {
        this->horasTrabajadas = horas;
        retorno = 0;
    }
    return retorno;
}
int empleado_getHoras(Empleado* this,int* horas)
{
    int retorno = -1;
    if(this != NULL)
    {
        *horas = this->horasTrabajadas;
        retorno = 0;
    }
    return retorno;
}

int empleado_setNombre(Empleado* this, char* nombre)
{
    int retorno = -1;
    if(this != NULL && nombre!=NULL)
    {
        strcpy(this->nombre, nombre);
        retorno = 0;
    }
    return retorno;
}
int empleado_getNombre(Empleado* this, char* nombre)
{
    int retorno = -1;
    if(this != NULL)
    {
        strcpy(nombre, this->nombre);
        retorno = 0;
    }
    return retorno;
}

int empleado_setId(Empleado* this, int ids)
{
    int retorno = -1;
    static int maximo = -1;
    if(this != NULL)
    {
        if(ids >= 0)
        {
            this->id = ids;
            if(ids > maximo)
            maximo = ids;
        }
        else
        {
            maximo++;
            this->id = maximo;
        }
        retorno = 0;
    }
    return retorno;
}
int empleado_getId(Empleado* this, int* id)
{
    int retorno = -1;
    if(this != NULL)
    {
        *id= this->id;
        retorno = 0;
    }
    return retorno;
}

int empleado_filtro(ArrayList* this,Empleado* auxiliar,int i)
{
    int retorno=-1;
    int horas;
        auxiliar=al_get(this,i);
        empleado_getHoras(auxiliar,&horas);
        if(horas>120)
        {
            retorno=1;
        }
        else
        {
            retorno=0;
        }
    return retorno;
}
