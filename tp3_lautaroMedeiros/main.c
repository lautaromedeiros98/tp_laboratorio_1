#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "movie.h"
#include "utn.h"
int main()
{
    Movie* arrayMovie[50];
    int cantidadOcupada=0;
    int menu,id;
    funciones_movieLoad(arrayMovie,&cantidadOcupada,"pelis.bin");
    do
    {
        getValidInt("1.AGREGAR PELICULA\n2.BORRAR PELICULA\n3.MODIFICAR PELICULA\n4.GENERAR PAGINA WEB\n5.SALIR\n","opcion invalida",&menu,0,5,10);
        switch(menu)
        {
        case 1:
            system("cls");
            movie_Alta(arrayMovie,&cantidadOcupada);
            system("cls");
            break;
        case 2:
            system("cls");
            movie_lista(arrayMovie,cantidadOcupada);
            getValidInt("Id de la pelicula a borrar","error\n",&id,0,50,10);
            movie_Baja(arrayMovie,&cantidadOcupada,id);
            break;
        case 3:
            system("cls");
            movie_lista(arrayMovie,cantidadOcupada);
            getValidInt("Id de la pelicula a modificar","error",&id,0,50,10);
            movie_modificar(arrayMovie,cantidadOcupada,id);
            break;
        case 4:
            system("cls");
            funciones_GenerarPaginaWeb(arrayMovie,&cantidadOcupada,50,"index.html");
            printf("Pagina generada");
            break;
        case 5:
            system("cls");
            printf("Programa finalizado");
            break;
        }
        funciones_MovieDump(arrayMovie, cantidadOcupada, "pelis.bin");
    }while(menu!=5);
}
