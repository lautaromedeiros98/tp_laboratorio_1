#include <stdio.h>
#include <stdlib.h>
#include "Empleado.h"
#include "ArrayList.h"
#include "Parser.h"

int parser_load(char* path, ArrayList* empleados)
{
    FILE* pFile;
    int retorno=-1;
    char id[4096];
    char nombre[4096];
    char horas[4096];
    if(empleados!=NULL)
    {
        retorno=0;
        pFile=fopen(path,"r");
        Empleado* auxiliar=empleado_new();
        fscanf(pFile,"%[^,],%[^,],%[^\n]\n",id,nombre,horas);
        while(!feof(pFile))
        {
            fscanf(pFile,"%[^,],%[^,],%[^\n]\n",id,nombre,horas);
            auxiliar=empleado_newParametros(atoi(horas),nombre,atoi(id));
            al_add(empleados,auxiliar);
        }
    }
    return retorno; // OK
}

void parse_print(ArrayList* empleados, char* path)
{
    FILE* pFile;
    char nombre[64];
    int horas;
    int id;
    if(empleados != NULL && path != NULL)
    {
        pFile = fopen(path, "w");
        int i;
        Empleado* auxiliar = empleado_new();
        for(i = 0; i < al_len(empleados); i++)
        {
            auxiliar = al_get(empleados,i);
            empleado_getNombre(auxiliar, nombre);
            empleado_getHoras(auxiliar, &horas);
            empleado_getId(auxiliar, &id);
            fprintf(pFile, "%d,%s,%d\n",id,nombre,horas);
        }
        fclose(pFile);
    }
}
