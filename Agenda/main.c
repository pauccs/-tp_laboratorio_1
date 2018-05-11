#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "funciones.h"
#define TAM 20

/*typedef struct {
    char nombre[50];
    int edad;
    int estado;
    int dni;
}EPersona; */

int main()
{
    EPersona persona[TAM];
    inicializar_estado(persona, TAM);
    //epersonas_hardcore (persona, TAM);

    int opcion;

    do
    {
      system("cls");
      printf("Agenda de Contacto\n");
      printf("\n1. Agregar persona");
      printf("\n2. Borrar una persona");
      printf("\n3. Imprimir listado ordenado por nombre");
      printf("\n4. Imprimir grafico de edades");
      printf("\n5. Salir");
      printf("\n");
      printf("Opcion: ");
      scanf("%d", &opcion);

      switch(opcion)
      {
        case 1:
          system("cls");
          cargar_agenda(persona,TAM); //CARGA MANUAL
          obtenerEspacioLibre(persona, TAM);
          system("pause");
         break;

        case 2:
          system("cls");
          borrar_agenda (persona, TAM);
          system("pause");
         break;

        case 3:
          system("cls");
          ordenado_nombre (persona, TAM);
          system("pause");
         break;
        case 4:
          system("cls");
          grafico_agenda(persona, TAM);
          system("pause");
          break;
        case 5:
        break;
     }
    }while(opcion<5);
   return 0;
}
