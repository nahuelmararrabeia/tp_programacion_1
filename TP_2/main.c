#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#define E 8

int main()
{
    char seguir='s';
    char opcion;
    Epersona persona[E];
    inicEstado(persona,E);


    while(seguir=='s')
    {

        printf("\n\n1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");
        printf("\nOPCION: ");
        fflush(stdin);
        scanf("%c",&opcion);
        while(opcion<'1' || opcion>'5')
        {
            printf("Opcion invalida.\nSeleccione una opcion: ");
            fflush(stdin);
            scanf("%c",&opcion);
        }
        system("cls");

        switch(opcion)
        {
            case '1':
                agregarPersona(persona, E);

                break;
            case '2':
                borrarPersona(persona,E);
                break;
            case '3':
                listaOrdenada(persona,E);
                break;
            case '4':
                graficoBarras(persona,E);
                break;
            case '5':
                seguir = 'n';
                break;
        }
    }


    return 0;
}
