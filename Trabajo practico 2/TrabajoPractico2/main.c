#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "persona.h"
#define cantidad 20

int main()
{
    char seguir='s';
    Persona persona[20];
    int opcion=0;
    int auxiliar;
    persona_init(persona,cantidad);
    int i;
    int menor;
    int joven;
    int mayor;
    int total;

    while(seguir=='s')
    {
        menu();
        getValidInt(" ","INGRESE UNA OPCION CORRECTA \n",&opcion,0,7,1000);
        switch(opcion)
        {
            case 1:
                system("cls");
                persona_alta(persona,cantidad);
                system("pause");
                system("cls");
                break;
            case 2:
                getValidInt("Id?\n","ingrese un id valido",&auxiliar,0,100,2);
                persona_baja(persona,cantidad,auxiliar);
                break;
            case 3:
                system("cls");
                persona_ordenar(persona,cantidad,0);
                persona_mostrar(persona,cantidad);
                system("pause");
                break;
            case 4:
                system("cls");
                menor = 0;
                joven = 0;
                mayor = 0;
                total = 0;
                graficoDatos(persona,menor,joven,mayor,total,cantidad);
                system("pause");

                break;
            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
