#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "empleados.h"
#include <string.h>

int main()
{
    char seguir='s';
    char opcion;
    ArrayList* lista_destinatarios;
    lista_destinatarios = al_newArrayList();

    while(seguir=='s')
    {

        printf("\n\n1- Cargar destinatarios\n");
        printf("2- Cargar lista negra\n");
        printf("3- Depurar\n");
        printf("4- Listar\n");
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
                cargar_destinatarios(lista_destinatarios);
                break;
            case '2':
                //borrarEmpleado(lista);
                break;
            case '3':

                break;
            case '4':

                break;
            case '5':
                seguir = 'n';
                break;
        }
    }
    free(lista_destinatarios);
    return 0;
}
