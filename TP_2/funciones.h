#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    char edad[4];
    int estado;
    char dni[9];

}Epersona;

int stringNumerico(char [], char []);
void getString(char [], char []);
int esNumero(char []);
int contadorChar(char []);

void agregarPersona(Epersona [],int);
void borrarPersona(Epersona[],int);
void listaOrdenada(Epersona[],int);
void inicEstado(Epersona[],int);
int stringLetras(char []);
int unicCod(Epersona[],int);
void graficoBarras(Epersona[],int);
int unicoDni(Epersona[], int, int);

#endif // FUNCIONES_H_INCLUDED

