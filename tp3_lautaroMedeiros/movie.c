#include "movie.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

/** \brief Establece el id
 *
 * \param this Movie* Entidad a establecer el id
 * \param id int id a establecer
 * \return int retrona -1 en caso de error y 0 si funciono correctamente
 *
 */
static int movie_setId(Movie *this, int id);


/** \brief Genera un nuevo espacio en el array
 *
 * \return Movie* Retorna ese espacio en el array
 *
 */
Movie* movie_new()
{
    return (Movie*) malloc(sizeof(Movie));
}

/** \brief Borra el espacio en el array
 *
 * \param this Movie* Elemento a ser eliminado
 * \return void
 *
 */
void movie_delete(Movie* this)
{
    free(this);
}

/** \brief Establece todos los atributos a la entidad a dar de alta
 *
 * \param titulo char* titulo a establecer
 * \param genero char* genero a establecer
 * \param duracion int duracion a establecer
 * \param descripcion char* descripcion a establecer
 * \param puntaje int puntaje a establecer
 * \param link char* link de la imagen a mostrar
 * \return Movie* entidad con los datos seteadosw
 *
 */
Movie* movie_newAlta(char* titulo, char* genero,int duracion,char* descripcion,int puntaje,char* link)
{
    Movie *auxArray = movie_new();
    movie_setTitulo(auxArray, titulo);
    movie_setDescripcion(auxArray, descripcion);
    movie_setDuracion(auxArray, duracion);
    movie_setGenero(auxArray, genero);
    movie_setLink(auxArray, link);
    movie_setId(auxArray, -1);
    movie_setPuntaje(auxArray, puntaje);
    return auxArray;
}

/** \brief Establece todos los atributos a la entidad a ser modificada
 *
 * \param titulo char* titulo a establecer
 * \param genero char* genero a establecer
 * \param duracion int duracion a establecer
 * \param descripcion char* descripcion a establecer
 * \param puntaje int puntaje a establecer
 * \param link char* link de la imagen a mostrar
 * \param id int id a establecer
 * \return Movie* entidad con los datos seteadosw
 *
 */
Movie* movie_newModificar(char* titulo, char* genero,int duracion,char* descripcion,int puntaje,char* link, int id)
{
    Movie *auxArray = movie_new();
    movie_setTitulo(auxArray, titulo);
    movie_setDescripcion(auxArray, descripcion);
    movie_setDuracion(auxArray, duracion);
    movie_setGenero(auxArray, genero);
    movie_setLink(auxArray, link);
    movie_setPuntaje(auxArray, puntaje);
    movie_setId(auxArray, id);
    return auxArray;
}


/** \brief Da de alta una nueva entidad
 *
 * \param ArrayMovie Movie** array en el que se va a almacenar esta entidad
 * \param qtyMovieActual int* cantidad ocupada en el array
 * \return int retrona -1 en caso de error y 0 si funciono correctamente
 *
 */
int movie_Alta(Movie **ArrayMovie, int *qtyMovieActual)
{
    int retorno = -1;
    char auxTitulo[100];
    char auxGenero[50];
    int auxDuracion;
    char auxDescripcion[200];
    int auxPuntaje;
    char auxLink[200];
    if(ArrayMovie != NULL && *qtyMovieActual > -1)
    {
        retorno = -2;
        if(getString("Titulo de la pelicula:  ", auxTitulo))
        {
            retorno = -2;
            if(getString("Genero de la pelicula:  ", auxGenero))
            {
                retorno = -2;
                if(getString("Descripcion:  ", auxDescripcion))
                {
                    retorno = -2;
                    if(!getValidInt("Duracion (60/200)Minutos:  ", "Error", &auxDuracion, 60, 200, 2))
                    {
                        retorno = -2;
                        if(getString("Link de imagen:  ",auxLink))
                        {
                            retorno = -2;
                            if(!getValidInt("Puntaje(1/10):  ", "Error", &auxPuntaje, 1, 10, 2))
                            {
                                ArrayMovie[*qtyMovieActual] = movie_newAlta(auxTitulo, auxGenero, auxDuracion, auxDescripcion, auxPuntaje, auxLink);
                                *qtyMovieActual = *qtyMovieActual + 1;
                                retorno = 0;
                            }
                        }
                    }
                }
            }
        }
    }
    return retorno;
}

/** \brief Modifica los daatos de una pelicula ya dada de alta
 *
 * \param movie Movie** array donde esta la pelicula a modificar
 * \param qtyMovieActual int cantidad maxima del array
 * \param id int id de la pelicula a modificar
 * \return int int retrona -1 en caso de error y 0 si funciono correctamente
 *
 */
int movie_modificar(Movie** movie, int qtyMovieActual, int id)
{
    int retorno = -1;
    char auxTitulo[100];
    char auxGenero[50];
    int auxDuracion;
    char auxDescripcion[200];
    int auxPuntaje;
    char auxLink[200];
    int auxId;
    if(movie != NULL && qtyMovieActual > 0 && id >= 0)
    {
        int i;
        for(i = 0; i < qtyMovieActual; i++)
        {
            retorno = -2;
            movie_getId(movie[i], &auxId);
            if(auxId == id)
            {
                if(getString("Titulo?", auxTitulo))
                {
                    retorno = -3;
                    if(getString("Genero?", auxGenero))
                    {
                        retorno = -3;
                        if(getString("Descripcion?", auxDescripcion))
                        {
                            retorno = -3;
                            if(!getValidInt("Duracion?", "Error", &auxDuracion, 30, 250, 2))
                            {
                                retorno = -3;
                                if(getString("Link de imagen?",auxLink))
                                {
                                    retorno = -3;
                                    if(!getValidInt("Puntaje?", "Error", &auxPuntaje, 1, 10, 2))
                                    {
                                        movie[i] = movie_newModificar(auxTitulo, auxGenero, auxDuracion, auxDescripcion, auxPuntaje, auxLink, id);
                                        retorno = 0;
                                    }
                                }
                            }
                        }
                    }
                }
                break;
            }
        }
    }
    return retorno;
}


/** \brief da de baja una pelicula
 *
 * \param ArrayMovie Movie** array donde esta la pelicula
 * \param qtyMovieActual int* cantidad ocupada del array
 * \param id int id de lapelicula a ser dada de baja
 * \return  int retrona -1 en caso de error y 0 si funciono correctamente
 *
 */
int movie_Baja(Movie **ArrayMovie, int *qtyMovieActual, int id)
{
    int retorno = -1;
    int i;
    int auxId;
    if(ArrayMovie != NULL && *qtyMovieActual > 0)
    {
        retorno = -2;
        if(id >= 0)
        {
            for(i = 0; i < *qtyMovieActual; i++)
            {
                movie_getId(ArrayMovie[i], &auxId);
                if(auxId == id)
                {
                    retorno = 0;
                    break;
                }
                retorno = -3;
            }
            if(retorno == 0)
            {
                if(i < *qtyMovieActual)
                {
                    for(; i < *qtyMovieActual; i++)
                    {
                        ArrayMovie[i] = ArrayMovie[i+1];
                    }
                }
                movie_delete(ArrayMovie[*qtyMovieActual]);
                *qtyMovieActual = *qtyMovieActual - 1;
            }
        }
    }
    return retorno;
}

/** \brief establece el titulo a una pelicula
 *
 * \param this Movie* pelicula a la que se le establece el titulo
 * \param titulo char* titulo a ser establecido
 * \return int retrona -1 en caso de error y 0 si funciono correctamente
 *
 */
int movie_setTitulo(Movie *this, char* titulo)
{
    int retorno = -1;
    if(this != NULL && titulo != NULL)
    {
        strcpy(this->titulo, titulo);
        retorno = 0;
    }
    return retorno;
}


/** \brief obtiene el titulo de una pelicula
 *
 * \param this Movie* pelicula de la que vamos a obtener el titulo
 * \param titulo char* titulo a obtener
 * \return  int retrona -1 en caso de error y 0 si funciono correctamente
 *
 */
int movie_getTitulo(Movie *this, char* titulo)
{
    int retorno = -1;
    if(this != NULL && titulo != NULL)
    {
        strcpy(titulo, this->titulo);
        retorno = 0;
    }
    return retorno;
}

/** \brief genero de la pelicula a establecer
 *
 * \param this Movie* pelicula a la que se le va a establecer el genero
 * \param genero char* genero a ser establecido
 * \return int retrona -1 en caso de error y 0 si funciono correctamente
 *
 */
int movie_setGenero(Movie *this, char* genero)
{
    int retorno = -1;
    if(this != NULL && genero != NULL)
    {
        strcpy(this->genero, genero);
        retorno = 0;
    }
    return retorno;
}


/** \brief obtiene el genero de una pelicula
 *
 * \param this Movie* pelicula de la que vamos a obtener el genero
 * \param genero char*  genero a obtener
 * \return int retrona -1 en caso de error y 0 si funciono correctamente
 *
 */
int movie_getGenero(Movie *this, char* genero)
{
    int retorno = -1;
    if(this != NULL && genero != NULL)
    {
        strcpy(genero, this->genero);
        retorno = 0;
    }
    return retorno;
}


/** \brief establece la duracion de una pelicula
 *
 * \param this Movie* pelicula a ser establecida la duracion
 * \param duracion int duracion a ser establecida
 * \return int retrona -1 en caso de error y 0 si funciono correctamente
 *
 */
int movie_setDuracion(Movie *this, int duracion)
{
    int retorno = -1;
    if(this != NULL)
    {
        this->duracion = duracion;
        retorno = 0;
    }
    return retorno;
}


/** \brief obtiene la duracion de una pelicula
 *
 * \param this Movie* pelicula a ser obtenida la duracion
 * \param duracion int* duracion a obtener
 * \return int retrona -1 en caso de error y 0 si funciono correctamente
 *
 */
int movie_getDuracion(Movie *this, int* duracion)
{
    int retorno = -1;
    if(this != NULL && duracion != NULL)
    {
        *duracion = this->duracion;
        retorno = 0;
    }
    return retorno;
}


/** \brief establece la descripcion de una pelicula
 *
 * \param this Movie* pelicula a ser establecida la descripcion
 * \param descripcion char* descripcion a ser establecida
 * \return int retrona -1 en caso de error y 0 si funciono correctamente
 *
 */
int movie_setDescripcion(Movie *this, char* descripcion)
{
    int retorno = -1;
    if(this != NULL && descripcion != NULL)
    {
        strcpy(this->descripcion, descripcion);
        retorno = 0;
    }
    return retorno;
}


/** \brief obtiene la descripcion de una pelicula
 *
 * \param this Movie* pelicula a obtener la descripcion
 * \param descripcion char* descripcion  a obtener
 * \return int retrona -1 en caso de error y 0 si funciono correctamente
 *
 */
int movie_getDescripcion(Movie *this, char* descripcion)
{
    int retorno = -1;
    if(this != NULL && descripcion != NULL)
    {
        strcpy(descripcion, this->descripcion);
        retorno = 0;
    }
    return retorno;
}


/** \brief establece un link a la pelicula
 *
 * \param this Movie* pelicula a la que se le establece el link
 * \param link char* link a establecer
 * \return int retrona -1 en caso de error y 0 si funciono correctamente
 *
 */
int movie_setLink(Movie *this, char* link)
{
    int retorno = -1;
    if(this != NULL && link != NULL)
    {
        strcpy(this->link, link);
        retorno = 0;
    }
    return retorno;
}


/** \brief obtiene el link de una pelicula
 *
 * \param this Movie* pelicula de la que obtenemos el link
 * \param link char* link a obtener
 * \return int retrona -1 en caso de error y 0 si funciono correctamente
 *
 */
int movie_getLink(Movie *this, char* link)
{
    int retorno = -1;
    if(this != NULL && link != NULL)
    {
        strcpy(link, this->link);
        retorno = 0;
    }
    return retorno;
}


/** \brief establece un puntaje a la pelicula
 *
 * \param this Movie* pelicula a establecer el puntaje
 * \param puntaje int puntaje a establecer
 * \return int retrona -1 en caso de error y 0 si funciono correctamente
 *
 */
int movie_setPuntaje(Movie *this, int puntaje)
{
    int retorno = -1;
    if(this != NULL)
    {
        this->puntaje = puntaje;
        retorno = 0;
    }
    return retorno;
}


/** \brief obtiene el puntaje de una pelicula
 *
 * \param this Movie* pelicula a obtener el puntaje
 * \param puntaje int* puntaje a obtener
 * \return int retrona -1 en caso de error y 0 si funciono correctamente
 *
 */
int movie_getPuntaje(Movie *this, int* puntaje)
{
    int retorno = -1;
    if(this != NULL && puntaje != NULL)
    {
        *puntaje = this->puntaje;
        retorno = 0;
    }
    return retorno;
}

/** \brief establece el id a una pelicula
 *
 * \param this Movie* pelicla a establecer el id
 * \param id int ultimo id establecido
 * \return int retrona -1 en caso de error y 0 si funciono correctamente
 *
 */
static int movie_setId(Movie *this, int id)
{
    int retorno = -1;
    static int maximoId = -1;
    if(this != NULL)
    {
        retorno = 0;
        if(id >= 0)
        {
            if(id > maximoId)
                maximoId = id;
            this->idMovie = id;
        }
        else
        {
            maximoId++;
            this->idMovie = maximoId;
        }
    }
    return retorno;
}

/** \brief obtiene el id de una pelicula
 *
 * \param this Movie* pelicula a obtener el id
 * \param id int* id a obtener
 * \return int retrona -1 en caso de error y 0 si funciono correctamente
 *
 */
int movie_getId(Movie *this, int* id)
{
    int retorno = -1;
    if(this != NULL && id != NULL)
    {
        *id = this->idMovie;
        retorno = 0;
    }
    return retorno;
}



/** \brief lee del archivo y establece los datos creando un nuevo lugar en el array de peliculas
 *
 * \param titulo char* titulo a ser establecido
 * \param genero char* genero a ser establecido
 * \param duracion int duracion a ser establecida
 * \param descripcion char* descripcion a ser establecida
 * \param puntaje int puntaje a ser establecido
 * \param link char* link a ser establecido
 * \param id int id a ser establecido
 * \return Movie* un nuevo elemento del array con los datos ya establecidos
 *
 */
Movie* movie_newSet(char* titulo, char* genero,int duracion,char* descripcion,int puntaje,char* link, int id)
{
    Movie* auxMovie = movie_new();
    if(     !movie_setTitulo(auxMovie, titulo)
       &&   !movie_setGenero(auxMovie, genero)
       &&   !movie_setDuracion(auxMovie, duracion)
       &&   !movie_setDescripcion(auxMovie, descripcion)
       &&   !movie_setPuntaje(auxMovie, puntaje)
       &&   !movie_setLink(auxMovie, link)
       &&   !movie_setId(auxMovie, id))
    {
        return auxMovie;
    }
    movie_delete(auxMovie);
    return NULL;
}

/** \brief Lista las peliculas
 *
 * \param movie Movie** array de peliculas
 * \param qtyMovieActual int cantidad ocupada del array
 * \return int retrona -1 en caso de error y 0 si funciono correctamente
 *
 */
int movie_lista(Movie** movie, int qtyMovieActual)
{
    int retorno = -1;
    int i;
    char titulo[50];
    int id;
    if(movie != NULL && qtyMovieActual > 0)
    {
        retorno = 0;
        for(i = 0; i < qtyMovieActual; i++)
        {
            movie_getTitulo(movie[i], titulo);
            movie_getId(movie[i], &id);
            printf("Titulo: %s, ID: %d\n", titulo, id);
        }
    }
    return retorno;
}


