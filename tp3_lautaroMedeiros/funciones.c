#include "movie.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

/** \brief Genera una pagina web con las peliculas dadas de alta
 *
 * \param movie Movie** array de peliculas
 * \param qtyMovieActual int* cantidad ocupada del array
 * \param qtyMovieTotal int cantidad total del array
 * \param path char* direccion a donde guardar el archivo generado
 * \return int retrona -1 en caso de error y 0 si funciono correctamente
 *
 */
int funciones_GenerarPaginaWeb(Movie **movie, int *qtyMovieActual, int qtyMovieTotal, char* path)
{
    int retorno = -1;
    int i;
    char titulo[100];
    char genero[50];
    int duracion;
    char descripcion[200];
    int puntaje;
    char link[200];
    FILE* pFile;
    pFile = fopen(path,"w");
    if(pFile != NULL && movie != NULL && qtyMovieTotal > 0 && *qtyMovieActual >= 0 &&  qtyMovieTotal > *qtyMovieActual)
    {
        retorno = 0;
        fprintf(pFile, "<!DOCTYPE html>\n");
        fprintf(pFile, "<!-- Template by Quackit.com -->\n");
        fprintf(pFile, "<html lang='en'>\n");
        fprintf(pFile, "<head>\n");
        fprintf(pFile, "<meta charset='utf-8'>\n");
        fprintf(pFile, "<meta http-equiv='X-UA-Compatible' content='IE=edge'>\n");
        fprintf(pFile, "<meta name='viewport' content='width=device-width, initial-scale=1'>\n");
        fprintf(pFile, "<!-- The above 3 meta tags *must* come first in the head; any other head content must come *after* these tags -->\n");
        fprintf(pFile, "<title>Lista peliculas</title>\n");
        fprintf(pFile, "<!-- Bootstrap Core CSS -->\n");
        fprintf(pFile, "<link href='css/bootstrap.min.css' rel='stylesheet'>\n");
        fprintf(pFile, "<!-- Custom CSS: You can use this stylesheet to override any Bootstrap styles and/or apply your own styles -->\n");
        fprintf(pFile, "<link href='css/custom.css' rel='stylesheet'>\n");
        fprintf(pFile, "<!-- HTML5 Shim and Respond.js IE8 support of HTML5 elements and media queries -->\n");
        fprintf(pFile, "<!-- WARNING: Respond.js doesn't work if you view the page via file:// -->\n");
        fprintf(pFile, "<!--[if lt IE 9]>\n");
        fprintf(pFile, "<script src='https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js'></script>\n");
        fprintf(pFile, "<script src='https://oss.maxcdn.com/libs/respond.js/1.4.2/respond.min.js'></script>\n");
        fprintf(pFile, "<![endif]-->\n");
        fprintf(pFile, "</head>\n");
        fprintf(pFile, "<body>\n");
        fprintf(pFile, "<div class='container'>\n");
        fprintf(pFile, "<div class='row'>\n");
        fprintf(pFile, "<!-- Repetir esto para cada pelicula -->\n");
        fprintf(pFile, "<article class='col-md-4 article-intro'>\n");
        for(i=0;i<*qtyMovieActual;i++)
        {
            movie_getTitulo(movie[i], titulo);
            movie_getGenero(movie[i], genero);
            movie_getDescripcion(movie[i], descripcion);
            movie_getDuracion(movie[i], &duracion);
            movie_getPuntaje(movie[i], &puntaje);
            movie_getLink(movie[i], link);
            fprintf(pFile,"<a href='#'> <img class='img-responsive img-rounded' src='%s' alt=''> </a> <h3> <a href='#'>%s</a> </h3> <ul> <li>Género:%s</li> <li>Puntaje:%d</li> <li>Duración:%d</li> </ul> <p>%s</p>",link,titulo,genero,puntaje,duracion,descripcion);
        }
        fprintf(pFile, "</article>\n");
        fprintf(pFile, "<!-- Repetir esto para cada pelicula -->\n");
        fprintf(pFile, "</div>\n");
        fprintf(pFile, "<!-- /.row -->\n");
        fprintf(pFile, "</div>\n");
        fprintf(pFile, "<!-- /.container -->\n");
        fprintf(pFile, "<!-- jQuery -->\n");
        fprintf(pFile, "<script src='js/jquery-1.11.3.min.js'></script>\n");
        fprintf(pFile, "<!-- Bootstrap Core JavaScript -->\n");
        fprintf(pFile, "<script src='js/bootstrap.min.js'></script>\n");
        fprintf(pFile, "<!-- IE10 viewport bug workaround -->\n");
        fprintf(pFile, "<script src='js/ie10-viewport-bug-workaround.js'></script>\n");
        fprintf(pFile, "<!-- Placeholder Images -->\n");
        fprintf(pFile, "<script src='js/holder.min.js'></script>\n");
        fprintf(pFile, "</body>\n");
        fprintf(pFile, "</html>\n");
    }
    fclose(pFile);
    return retorno;
}

/** \brief Carga los datos del archivo ya generado y los guarda en el array
 *
 * \param movie Movie** array de peliculas
 * \param qtyMovieActual int* cantidad ocupada del array
 * \param path char* direccion de donde se encuentra el archivo
 * \return int retrona -1 en caso de error y 0 si funciono correctamente
 *
 */
int funciones_movieLoad(Movie** movie, int* qtyMovieActual, char* path)
{
    int retorno = -1;
    FILE* pFile;
    Movie* auxMovie = movie_new();
    if(movie != NULL && path != NULL)
    {
        pFile = fopen(path, "rb");
        if(pFile != NULL)
        {
            while(fread(auxMovie, sizeof(Movie), 1, pFile) == 1)
            {
                movie[*qtyMovieActual] = movie_newSet(auxMovie->titulo, auxMovie->genero, auxMovie->duracion, auxMovie->descripcion, auxMovie->puntaje, auxMovie->link, auxMovie->idMovie);
                (*qtyMovieActual)++;
            }
            fclose(pFile);
            retorno = 0;
        }
    }
    return retorno;
}

/** \brief guarda los datos del array en el archivo
 *
 * \param movie Movie** array de peliculas
 * \param qtyMovieActual int cantidad ocupada del array
 * \param path char* donde guardar los datos
 * \return int retrona -1 en caso de error y 0 si funciono correctamente
 *
 */
int funciones_MovieDump(Movie** movie, int qtyMovieActual, char* path)
{
    FILE *pFile;
    int i;
    int retorno = -1;
    pFile = fopen(path, "wb");
    if(pFile!=NULL)
    {
        retorno = 0;
        for(i=0;i<qtyMovieActual;i++)
            fwrite(movie[i],sizeof(Movie), 1,pFile);
    }
    fclose(pFile);
    return retorno;
}
