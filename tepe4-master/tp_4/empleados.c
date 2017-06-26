#include <stdio.h>
#include <string.h>
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
    void* empleado;
    if((aRch=fopen("destinatariios.csv","r+"))==NULL)
        {
             if((aRch=fopen("destinatariios.csv","w+"))==NULL)
             {
                 printf("\nEl archivo no puede ser abierto");
                 return -1;
             }
        }
    while(!feof(aRch))
    {
        fread(empleado, sizeof(void),1,aRch);
        if(feof(aRch))
            break;
        tam++;
    }

    fclose(aRch);
    return tam;
}

int cargar_destinatarios(ArrayList* lista_destinatarios)
{
    FILE* aRch, *aRch2;
    Edestinatarios* destinatarios;
    Edestinatarios* destinatario;
    int i, index=0;
    long int pos;
    char nombre[50],mail[50],cadena[50];

    destinatarios=(Edestinatarios*)malloc(sizeof(Edestinatarios));
    destinatario=(Edestinatarios*)malloc(sizeof(Edestinatarios));
    if((aRch=fopen("C:\\Users\\user\\Desktop\\Nahuel\\tp_programacion_1-master\\tepe4-master\\tp_4\\destinatarios.csv","r+"))==NULL)
        {
             if((aRch=fopen("C:\\Users\\user\\Desktop\\Nahuel\\tp_programacion_1-master\\tepe4-master\\tp_4\\destinatarios.csv","w+"))==NULL)
             {
                 printf("\nEl archivo no puede ser abierto");
                 return 0;
             }
        }
    rewind(aRch);
                if((aRch2=fopen("lola.txt","r+"))==NULL)
            {
                 if((aRch=fopen("lola.txt","w+"))==NULL)
                 {
                     printf("\nEl archivo no puede ser abierto");
                     return 0;
                 }
            }
    while(!feof(aRch))
    {

        i=0;
        fgets(cadena, 50, aRch);
        while(cadena[i]!=44){
            i++;
        }
        cadena[i]='\0';
        strcpy(nombre, cadena);
        //printf(" %s", nombre);
        //fseek(aRch,-(50-i), SEEK_SET);
        fgets(cadena,50,aRch);
        i=0;
        while(cadena[i]!=10){
            i++;
        }
        cadena[i]='\0';
        strcpy(mail, cadena);
        //printf(" %s\n", mail);
        //fseek(aRch,-(50-i), SEEK_CUR);
        destinatarios=(Edestinatarios*)realloc(destinatarios, sizeof(Edestinatarios)*index);
        strcpy(*(destinatarios+index)->nombre, nombre);
        strcpy(*(destinatarios+index)->mail, mail);
        lista_destinatarios->add(destinatarios+index);
        index++;


    }
    //printf("%d\n", lista_destinatarios->size);

    /*for(i=0;i<lista_destinatarios->size;i++)
    {
        destinatarios=(Edestinatarios*)al_get(lista_destinatarios, i);
        fprintf(" %s", destinatario->nombre);
        printf("%d\n", lista_destinatarios->size);
        //fprintf(aRch2," %s\t %s\n\n", destinatario->nombre, destinatario->mail);
    }*/
    fwrite(lista_destinatarios, sizeof(ArrayList),1,aRch2);


    fclose(aRch);
    fclose(aRch2);
    return 1;
}

/*void imprimir_al(ArrayList* lista_destinatarios)
{
    int i;
    Edestinatarios* destinatarios;
    destinatarios=(Edestinatarios*)malloc(Edestinatarios);
    for(i=0;i<lista_destinatarios;i++)
    {

    }
}*/


