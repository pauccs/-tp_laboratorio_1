#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0;
    int flag = 0;
	float A, B;
    while(seguir=='s')
    {
		system("cls");
        printf("1- Ingresar 1er operando (A=x)\n");
        printf("2- Ingresar 2do operando (B=y)\n");
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operaciones\n");
        printf("9- Salir\n");
        printf("\n");
        fflush(stdin);
		printf("Opcion: ");
	    scanf("%d",&opcion);
        switch(opcion)
        {
            case 1:
                flag = 1;
				A = getNumero1("Ingrese un numero: ");
				getch();
                break;
            case 2:
                flag = 1;
				B = getNumero2("Ingrese un numero: ");
				getch();
                break;
            case 3:
                if(flag == 1){
                  sumar("La suma es: ", A,B);}
                else
                  printf("No se encontro ningun numero");
				getch();
                break;
            case 4:
                if(flag == 1){
                restar("La resta es: ", A,B);}
                else
                  printf("No se encontro ningun numero");
				getch();
                break;
            case 5:
                if(flag == 1){
                dividir("La division es: ", A,B);}
                else
                  printf("No se encontro ningun numero");
				getch();
                break;
            case 6:
                if(flag == 1){
                producto("El producto es: ", A,B);}
                else
                  printf("No se encontro ningun numero");
			  getch();
                break;
            case 7:
                if(flag == 1){
                factorial("El factorial es: ", A);}
                else
                  printf("No se encontro ningun numero");
			  getch();
                break;
            case 8:
                printf("\n-----------------\n");
                if(flag == 1){
                sumar("La suma es: ", A,B);
                restar("\nLa resta es: ", A,B);
                dividir("\nLa division es: ", A,B);
                producto("\nEl producto es: ", A,B);
                factorial("\nEl factorial es: ", A);}
                else
                  printf("No se encontro ningun numero");
                printf("\n-----------------\n");
			  getch();
                break;
            case 9:
                seguir = 'n';
                break;
		}
	}
    return 0;
}
