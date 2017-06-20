#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "empleados.h"

int stringNumerico(char mensaje[], char input[])
{
    char aux[25];
    getString(mensaje, aux);
    if(esNumero(aux))
    {
        strcpy(input, aux);
        return 1;
    }
    return 0;
}//stringNumerico


/**
*brief Pide un numero al usuario y lo guarda
*param1 Mensaje a imprimir
* param2 variable que guarda string
* return void
**/
void getString(char mensaje[], char input[])
{
    printf("%s", mensaje);
    gets(input);
}// getString

/**
*brief Valida que un string sea solo numeros
* param1 variable que guarda string validado
* return 1 si es solo numeros, sino 0
**/
int esNumero(char str[])
{
    int i = 0;
    while(str[i]!='\0')
    {
        if(str[i]<'0' || str[i]>'9')
            return 0;
        i++;
    }
    return 1;
}// esNumero

/**
*brief recibe un string y cuenta la cantidad de caracteres ingresados
* param1 string a calcular la cantidad de caracteres
*return cantidad de caracteres de string
**/
int contadorChar(char str[])
 {
     int aux;
     aux=strlen(str);
     return aux;
 }//contadorChar

/**
*brief pide y guarda dni, edad y nombre al usuario
*param1 array de persona
* param2 cantidad de posiciones del array
* return void
**/
void agregarEmpleado(ArrayList* lista)
{
    printf("-----------AGREGAR EMPLEADO-----------\n");
    FILE *aRch;
    Eempleado* empleado;
    empleado=(Eempleado *)malloc(sizeof(Eempleado));
    if((aRch=fopen("empleados.dat","rb+"))==NULL)
        {
             if((aRch=fopen("empleados.dat","wb+"))==NULL)
             {
                 printf("\nEl archivo no puede ser abierto");
                 return 0;
             }
        }
    if(fseek(aRch, 0L, SEEK_END)==0)
    {
            printf("\nNombre: ");
            fflush(stdin);
            gets(empleado->nombre);
            while(stringLetras(empleado->nombre)==0)
            {
                printf("\nEl nombre no acepta numeros ");
                printf("\nNombre: ");
                fflush(stdin);
                gets(empleado->nombre);
            }

             printf("\nApellido: ");
            fflush(stdin);
            gets(empleado->apellido);
            while(stringLetras(empleado->apellido)==0)
            {
                printf("\nEl apellido no acepta numeros ");
                printf("\nApellido: ");
                fflush(stdin);
                gets(empleado->apellido);
            }

            fflush(stdin);
            while(stringNumerico("\nEdad: ", empleado->edad)==0)
            {
                printf("\nEdad debe ser numerico! ");
            }


            fflush(stdin);
            while(stringNumerico("\nDNI: ", empleado->dni)==0)
            {
            printf("\nDNI debe ser numerico ");
            }

            while(contadorChar(empleado->dni)<7 || contadorChar(empleado->dni)>8)
                   {
                       printf("\nCantidad de digitos invalida");
                        stringNumerico("\nDNI: ", empleado->dni);
                   }

            /*while(unicoDni(empleado,i,tam)==0)
            {
                printf("\nEl DNI ingresado ya existe en otro registro");
                stringNumerico("\nDNI: ", persona[i].dni);
            }*/

            //persona[i].estado=1;
            fflush(stdin);
            al_add(lista, empleado);
            fwrite (empleado, sizeof(Eempleado) , 1, aRch);
            fclose(aRch);
            system("cls");
            printf("\n----------PELICULA AGREGADA EXITOSAMENTE!--------");
            //break;

    }else{
        printf("Error al cargar nuevo registro");
        fclose(aRch);
        system("pause");
        return 0;
    }
}

/**
*brief pide dni al usuario para ubicar un registro y darlo de baja
*param1 array de persona
* param2 cantidad de posiciones del array
* return void
**/
 int borrarEmpleado(ArrayList* lista)
{
    printf("-----------BORRAR EMPLEADO-----------\n");
    FILE* aRch;
    Eempleado* empleado;
    char auxString[10];
    int i,flagEncontro=0, tam;
    char opcion, auxDNI[10];
    empleado=(Eempleado*)malloc(sizeof(Eempleado)*lista->size);
    lista->pElements=empleado;

    if((aRch=fopen("empleados.dat","rb+"))==NULL)
        {
             if((aRch=fopen("empleados.dat","wb+"))==NULL)
             {
                 printf("\nEl archivo no puede ser abierto");
                 return -1;
             }
        }
    rewind(aRch);
    printf("Ingrese el DNI de la persona a borrar: ");
    fflush(stdin);
    gets(auxString);
    for(i=0; i<lista->size ;i++)
    {
        fread(lista->pElements[i], sizeof(Eempleado), 1, aRch);
    }


    scanf(" %c", &auxDNI);
    for(i=0; i<lista->size; i++)
    {
        if(auxDNI == *(lista->pElements[i])->dni)
        {
            if(al_remove(lista, i)==0)
            {
                printf("Registro borrado");
            }else{
                printf("Error al eliminar el registro");
            }
    }
    if(flagEncontro==0)
        printf("No se encontro el DNI ingresado");

    rewind(aRch);
    fflush(stdin);
    fwrite(lista, sizeof(lista), 1, aRch);

    fclose(aRch);
    }
     return 0;
}// borrarPersona

/**
*brief ordena los registros de personas ingresados por nombre de manera descendente
*param1 array de persona
* param2 cantidad de posiciones del array
* return void
**/
/* void listaOrdenada(Epersona persona[], int tam)
{
    printf("-----------LISTA POR NOMBRE-----------\n\n");
    int i,j;
    Epersona auxStruct;
    printf("DNI\t\tNOMBRE\tEDAD\n");
    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(strcmp(persona[i].nombre, persona[j].nombre)<0)
            {
                auxStruct = persona[i];
                persona[i] = persona[j];
                persona[j] = auxStruct;
            }
        }
            if(persona[i].estado==1)
                printf("%s\t%s\t%s\n", persona[i].dni,persona[i].nombre,persona[i].edad);

    }
}// listaOrdenada
*/

/**
*brief inicializa los estados de todos los registros del array en 0
*param1 array de persona
* param2 cantidad de posiciones del array
* return void
**/
/*void inicEstado(Epersona persona[],  int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        persona[i].estado=0;
    }
}// inicEstado */


 int stringLetras(char str[])
{
    int i =0;
    while(str[i]!='\0')
    {
        if((str[i]<'a' || str[i]>'z')&&(str[i]<'A' || str[i]>'A') && str[i]!=' ')
            return 0;
        i++;
    }
    return 1;
}

int cantidadRegistros()
{
    int tam=0;
    FILE* aRch;
    Eempleado* empleado;
    if((aRch=fopen("empleados.dat","rb+"))==NULL)
        {
             if((aRch=fopen("empleados.dat","wb+"))==NULL)
             {
                 printf("\nEl archivo no puede ser abierto");
                 return -1;
             }
        }
    while(!feof(aRch))
    {
        fread(empleado, sizeof(Eempleado),1,aRch);
        if(feof(aRch))
            break;
        tam++;
    }

    fclose(aRch);
    return tam;
}


