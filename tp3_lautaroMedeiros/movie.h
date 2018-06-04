#ifndef MOVIE_H_INCLUDED
#define MOVIE_H_INCLUDED
typedef struct{
    char titulo[100];
    char genero[50];
    int duracion;
    int idMovie;
    char descripcion[200];
    int puntaje;
    char link[200];
}Movie;
#endif // MOVIE_H_INCLUDED


void movie_delete(Movie* this);
Movie* movie_new();
Movie* movie_newSet(char* titulo, char* genero,int duracion,char* descripcion,int puntaje,char* link, int id);


int movie_getId(Movie *this, int* id);
int movie_getTitulo(Movie *this, char* titulo);
int movie_getGenero(Movie *this, char* genero);
int movie_getDuracion(Movie *this, int* duracion);
int movie_getDescripcion(Movie *this, char* descripcion);
int movie_getPuntaje(Movie *this, int* puntaje);
int movie_getLink(Movie *this, char* link);


int movie_setTitulo(Movie *this, char* titulo);
int movie_setGenero(Movie *this, char* genero);
int movie_setDuracion(Movie *this, int duracion);
int movie_setDescripcion(Movie *this, char* descripcion);
int movie_setLink(Movie *this, char* link);
int movie_setPuntaje(Movie *this, int puntaje);



Movie* movie_newAlta(char* titulo, char* genero,int duracion,char* descripcion,int puntaje,char* link);
int movie_modificar(Movie** movie, int qtyMovieActual, int id);
int movie_Alta(Movie **ArrayMovie, int *qtyMovieActual);
int movie_Baja(Movie **ArrayMovie, int *qtyMovieActual, int id);
int movie_lista(Movie** movie, int qtyMovieActual);
Movie* movie_newMod(char* titulo, char* genero,int duracion,char* descripcion,int puntaje,char* link, int id);
