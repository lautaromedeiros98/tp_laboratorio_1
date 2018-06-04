#include "movie.h"
#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED


int funciones_GenerarPaginaWeb(Movie **movie, int *qtyMovieActual, int qtyMovieTotal, char* path);
int funciones_movieLoad(Movie** movie, int* qtyMovieActual, char* path);
int funciones_MovieDump(Movie** movie,int qtyMovieActual, char* path);


#endif // FUNCIONES_H_INCLUDED
