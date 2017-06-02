#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0,tam;
    tam=cantidadRegistros();
    EMovie *movies;
    EMovie movie1[tam];
    movies=movie1;
    while(seguir=='s')
    {
        system("cls");
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Generar pagina web\n");
        printf("4- Salir\n");
        printf("\nOPCION: ");
        scanf("%d",&opcion);
        while(opcion<1||opcion>4)
        {
            printf("Opcion invalida. Ingrese la opcion: ");
            printf("\nOPCION: ");
            scanf("%d",&opcion);
        }

        switch(opcion)
        {
            case 1:
                agregarPelicula(movies);
                break;
            case 2:
                borrarPelicula(movies);
                break;
            case 3:
                generarPagina(movies);
               break;
            case 4:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
