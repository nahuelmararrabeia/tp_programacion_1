#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

int agregarPelicula(EMovie* movies)
{
    printf("-----------AGREGAR PELICULA-----------\n");
    FILE *aRch;
    if((aRch=fopen("movies.dat","rb+"))==NULL)
        {
             if((aRch=fopen("movies.dat","wb+"))==NULL)
             {
                 printf("\nEl archivo no puede ser abierto");
                 return 0;
             }
        }
    if(fseek(aRch, 0L, SEEK_END)==0)
    {
        printf("\nIngrese el titulo: ");
        fflush(stdin);
        gets(movies->titulo);
        printf("\nIngrese el genero: ");
        fflush(stdin);
        gets(movies->genero);
        printf("\nIngrese la descripcion: ");
        fflush(stdin);
        gets(movies->descripcion);
        printf("\nIngrese la duracion: ");
        scanf("%d", &movies->duracion);
        printf("\nIngrese el puntaje: ");
        scanf("%d", &movies->puntaje);
        printf("\nIngrese el link de la imagen: ");
        fflush(stdin);
        gets(movies->linkImagen);
        movies->estado=1;
        fflush(stdin);
        fwrite (movies, sizeof(EMovie) , 1, aRch);
        fclose(aRch);
        system("cls");
            printf("\n----------PELICULA AGREGADA EXITOSAMENTE!--------");
    }else{
        printf("Error al cargar nuevo registro");
        fclose(aRch);
        system("pause");
        return 0;
    }
}

int borrarPelicula(EMovie* movies)
{
    printf("-----------BORRAR PELICULA-----------\n");
    FILE* aRch;
    char auxString[50];
    int flag,tam,i;
    tam=cantidadRegistros();
    if((aRch=fopen("movies.dat","rb+"))==NULL)
        {
             if((aRch=fopen("movies.dat","wb+"))==NULL)
             {
                 printf("\nEl archivo no puede ser abierto");
                 return 0;
             }
        }
    rewind(aRch);
    printf("\nIngrese el titulo de la pelicula: ");
    fflush(stdin);
    gets(auxString);
    for(i=0;i<tam;i++)
    {
        fread(movies+i,sizeof(EMovie), 1, aRch);

    }
    for(i=0;i<tam;i++)
    {
        if(strcmp(auxString, (movies+i)->titulo)==0)
        {
            flag=1;
            (movies+i)->estado=0;
            system("cls");
            printf("Registro de pelicula borrado con exito\n");

        }
    }

    if(flag==0)
    {
        system("cls");
        printf("No fue encontrado el registro buscado");

    }

    rewind(aRch);
    fflush(stdin);
    fwrite(movies,sizeof(EMovie),tam, aRch);

    fclose(aRch);
}

void generarPagina(EMovie* movies)
{
    FILE* aRch;
    FILE* aRchHTML;
    int tam,i;
    tam=cantidadRegistros();

    //movies=((EMovie*)malloc(tam*sizeof(EMovie)));

    if((aRch=fopen("movies.dat","rb+"))==NULL)
        {
             if((aRch=fopen("movies.dat","wb+"))==NULL)
             {
                 printf("\nEl archivo no puede ser abierto");
                 return 0;
             }
        }

    if((aRchHTML=fopen("movies.html","r+"))==NULL)
        {
             if((aRchHTML=fopen("movies.html","w+"))==NULL)
             {
                 printf("\nEl archivo no puede ser abierto");
                 return 0;
             }
        }
    fprintf(aRchHTML,"<!DOCTYPE html>\n<html lang='en'>\n<head>\n    <meta charset='utf-8'>\n    <meta http-equiv='X-UA-Compatible' content='IE=edge'>\n    <meta name='viewport' content='width=device-width, initial-scale=1'>\n    <!-- The above 3 meta tags *must* come first in the head; any other head content must come *after* these tags -->\n    <title>Lista peliculas</title>\n    <!-- Bootstrap Core CSS -->\n    <link href='css/bootstrap.min.css' rel='stylesheet'>\n    <!-- Custom CSS: You can use this stylesheet to override any Bootstrap styles and/or apply your own styles -->\n    <link href='css/custom.css' rel='stylesheet'>\n    <!-- HTML5 Shim and Respond.js IE8 support of HTML5 elements and media queries -->\n    <!-- WARNING: Respond.js doesn't work if you view the page via file:// -->\n    <!--[if lt IE 9]>\n        <script src='https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js'></script>\n        <script src='https://oss.maxcdn.com/libs/respond.js/1.4.2/respond.min.js'></script>\n    <![endif]-->\n</head>\n<body>\n    <div class='container'>\n        <div class='row'>\n\n		" );

    for(i=0;i<tam;i++)
    {

        fread(movies+i, sizeof(EMovie), 1, aRch);
        fflush(stdin);

        if((movies+i)->estado==1)
        {
            fprintf(aRchHTML,"\n            <article class='col-md-4 article-intro'>\n                <a href='#'>\n                    <img class='img-responsive img-rounded' src=' %s ' alt=''>\n                </a>\n                <h3>\n                    <a href='#'> %s </a>\n                </h3>\n				<ul>\n					<li>Genero: %s </li>\n					<li>Puntaje: %d </li>\n					<li>Duracion: %d </li>					\n				</ul>\n               <p> %s </p>\n            </article>" ,(movies+i)->linkImagen,(movies+i)->titulo,(movies+i)->genero,(movies+i)->puntaje,(movies+i)->duracion,(movies+i)->descripcion);
        }
    }

    fprintf(aRchHTML,"\n\n        </div>\n        <!-- /.row -->\n    </div>\n    <!-- /.container -->\n    <!-- jQuery -->\n    <script src='js/jquery-1.11.3.min.js'></script>\n    <!-- Bootstrap Core JavaScript -->\n    <script src='js/bootstrap.min.js'></script>\n	<!-- IE10 viewport bug workaround -->\n	<script src='js/ie10-viewport-bug-workaround.js'></script>\n	<!-- Placeholder Images -->\n	<script src='js/holder.min.js'></script>\n</body>\n</html>");

    fclose(aRch);
    fclose(aRchHTML);
    system("cls");
    printf("Pagina generada con exito!!!\n");
    system("pause");
}




int cantidadRegistros()
{
    int tam=0;
    FILE* aRch;
    EMovie movie;
    if((aRch=fopen("movies.dat","rb+"))==NULL)
        {
             if((aRch=fopen("movies.dat","wb+"))==NULL)
             {
                 printf("\nEl archivo no puede ser abierto");
                 return -1;
             }
        }
    while(!feof(aRch))
    {

        fread(&movie, sizeof(EMovie),1,aRch);
        if(feof(aRch))
            break;
        tam++;
    }

    fclose(aRch);
    return tam;
}
