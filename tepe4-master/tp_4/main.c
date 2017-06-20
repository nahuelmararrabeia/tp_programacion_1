#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "empleados.h"

int main()
{
    char seguir='s';
    char opcion;
    ArrayList* lista;
    lista = al_newArrayList();

    while(seguir=='s')
    {

        printf("\n\n1- Agregar empleado\n");
        printf("2- Borrar empleado\n");
        printf("2- Modificar empleado\n");
        printf("4- Imprimir lista ordenada por  nombre\n");
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
                agregarEmpleado(lista);
                break;
            case '2':
                borrarEmpleado(lista);
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

    return 0;
}
