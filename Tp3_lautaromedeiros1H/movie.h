#ifndef MOVIE_H_INCLUDED
#define MOVIE_H_INCLUDED
typedef struct
{
    char titulo[50];
    char genero[20];
    char duracion[20];
    char descripcion[100];
    int puntaje;
    char link[50];
    int idMovie;
}Movie;
#endif // MOVIE_H_INCLUDED
void movie_delete(Movie* this);
Movie* movie_new();

int movie_setTitulo(Movie *this, char* titulo);
int movie_getTitulo(Movie *this, char* titulo);
int movie_setGenero(Movie *this, char* genero);
int movie_getGenero(Movie *this, char* genero);
int movie_setDuracion(Movie *this, char* duracion);
int movie_getDuracion(Movie *this, char* duracion);
int movie_setDescripcion(Movie *this, char* descripcion);
int movie_getDescripcion(Movie *this, char* descripcion);
int movie_setLink(Movie *this, char* link);
int movie_getLink(Movie *this, char* link);
int movie_setPuntaje(Movie *this, int puntaje);
int movie_getPuntaje(Movie *this, int* puntaje);

Movie movie_newParametros(char* titulo, char* genero,char* duracion,char* descripcion,int puntaje,char* link);
int movie_alta(Movie **ArrayMovie, int *qtyMovieActual);
int movie_baja(Movie **ArrayMovie, int *qtyMovieActual, int id);
