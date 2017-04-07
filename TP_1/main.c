#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    float operandoA=0;
    float operandoB=0;
    float result;
    int opcion=0;

    while(seguir=='s')
    {
        system("cls");
        printf("1- Ingresar 1er operando (A=%.2f)\n", operandoA);
        printf("2- Ingresar 2do operando (B=%.2f)\n", operandoB);
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operaciones\n");
        printf("9- Salir\n");



        printf("\n\nOpcion: ");
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                printf("Ingrese el 1er operando: ");
                scanf("%f", &operandoA);
                break;
            case 2:
                printf("Ingrese el 2do operando: ");
                scanf("%f", &operandoB);
                break;
            case 3:
                result=suma2nros(operandoA,operandoB);
                printf("\n%.2f + %.2f = %.2f\n",operandoA,operandoB,result);
                system("pause");
                break;
            case 4:
                result = resta2nros(operandoA,operandoB);
                printf("\n%.2f - %.2f = %.2f\n",operandoA,operandoB,result);
                system("pause");
                break;
            case 5:
                if(operandoB==0)
                {
                    printf("Para poder dividir, el divisor debe ser distinto de 0\n");
                    system("pause");
                }else
                {
                result=div2nros(operandoA,operandoB);
                printf("\n%.2f / %.2f = %.2f\n",operandoA,operandoB,result);
                system("pause");
                }
                break;
            case 6:
                result=mult2nros(operandoA,operandoB);
                printf("\n%.2f * %.2f = %.2f\n",operandoA,operandoB,result);
                system("pause");
                break;
            case 7:
                if(operandoA<0)
                {
                    printf("No se puede calcular el factorial del nro ingresado\n");
                }else
                {
                    result=factorial(operandoA);
                    printf("\n%.0f! = %.0f\n", operandoA,result);
                }
                system("pause");
                break;
            case 8:
                result=suma2nros(operandoA,operandoB);
                printf("\n%.2f + %.2f = %.2f\n",operandoA,operandoB,result);
                result = resta2nros(operandoA,operandoB);
                printf("\n%.2f - %.2f = %.2f\n",operandoA,operandoB,result);
                if(operandoB==0)
                {
                   printf("\nPara poder dividir, el divisor debe ser distinto de 0\n");
                }else
                {
                    result=div2nros(operandoA,operandoB);
                    printf("\n%.2f / %.2f = %.2f\n",operandoA,operandoB,result);
                }
                result=mult2nros(operandoA,operandoB);
                printf("\n%.2f * %.2f = %.2f\n",operandoA,operandoB,result);
                if(operandoA<0)
                {
                    printf("\nNo se puede calcular el factorial del numero ingresado\n\n\n");
                }else
                {
                    result=factorial(operandoA);
                    printf("\n%.0f! = %.0f\n\n\n", operandoA,result);
                }

                system("pause");
                break;
            case 9:
                printf("\n                      CHAU!\n");
                seguir = 'n';
                break;
            }

        }


        return 0;

}
