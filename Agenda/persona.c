#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#define T 3

void inicializar_estado(EPersona persona[], int TAM)
{
    int i;

    for(i=0; i<TAM; i++)
    {
        persona[i].estado = 0;
    }
}

void epersonas_hardcore (EPersona persona[],int TAM)
{
    char nombre[20][20]={"Pedro","Juan","Luis","Carlos","Lucas","Natalia","Carina","Aaron","Maria","Josefina","Marcos","Federico","Camila","Veronica","Pablo","German","Tomas","Lidia","Nora","Jacinto"};
    int dni[20]={101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120};
    int edad[20]={20,24,28,39,56,79,42,76,28,19,17,27,37,61,17,46,30,10,34,62};

    int i;

    for(i=0; i<TAM; i++)
    {
      strcpy(persona[i].nombre,nombre[i]);
      fflush(stdin);
      persona[i].dni=dni[i];
      validar("ERROR. DNI: ",persona[i].dni,0,40000);
      persona[i].edad=edad[i];
      validar("ERROR. Edad: ",persona[i].edad,0,110);
      persona[i].estado=1;
    }
    mostrar_agenda (persona, TAM);
}

void cargar_agenda (EPersona persona[], int TAM)
{
    int i,dni,edad;
    printf("**Nuevo Contacto**\n");
    for(i=0;i<TAM;i++)
    {
      if(persona[i].estado == 0)
      {
        //Ingreso de los datos
         printf("Nombre: ");
         fflush(stdin);
         gets(persona[i].nombre);
         //validacion del nombre
         while(strlen(persona[i].nombre)>50)
         {
            printf("Nombre: ");
            fflush(stdin);
            gets(persona[i].nombre);
         }
         printf("Edad: ");
         scanf("%d",&edad);
         persona[i].edad = validar("ERROR. Edad: ",edad,0,110);
         printf("Dni: ");
         scanf("%d",&dni);
         persona[i].dni = validar("ERROR. Dni: ",dni,1,40000);
         persona[i].estado = 1;
      }
    }
    if(persona[i].estado == 1)
    {
       printf("\nNo hay espacio\n");
       obtenerEspacioLibre(persona, TAM);
    }
    mostrar_agenda (persona, TAM);
}


void mostrar_agenda(EPersona persona[], int TAM)
{
  int i;
  //muestra la agenda cargada
  printf("\n**Agenda**\n");
  printf("Nombre    Edad    Dni");
  for(i=0;i<TAM;i++)
  {
     printf("\n%-10s  %-4d  %-8d", persona[i].nombre, persona[i].edad, persona[i].dni);
     fflush(stdin);
  }
}

void borrar_agenda (EPersona persona[], int TAM)
{
    int i,dni=0;
    printf("**Borrar Contacto**\n");
    for(i=0;i<TAM;i++)
    {
        if(persona[i].estado == 1)
        {
            //LLAMA A LA FUNCION QUE BUSCA EL DNI INGRESADO POR EL USUARIO EN EL ARRAY CARGADO
            buscarPorDni(persona,dni);
            fflush(stdin);
            break;
        }
        if(persona[i].estado == 0)
        {
           printf("\nUps! No se cargo ningun dato\n\n");
           break;
        }
        break;
    }
}

int obtenerEspacioLibre(EPersona persona[], int TAM)
{
    int retorno = -1, i;
    int cont=0, dni = 0;
    if(TAM > 0 && persona != NULL)
    {
        retorno = -2;
        for(i=0;i<TAM;i++)
        {
            if(persona[i].estado == 0)
            {
                printf("\nLa posicion %d esta vacia\n", i);
                printf("Nombre: ");
                fflush(stdin);
                gets(persona[i].nombre);
                //validacion del nombre
                while(strlen(persona[i].nombre)>50)
                {
                    printf("Nombre: ");
                    fflush(stdin);
                    gets(persona[i].nombre);
                }
                printf("Edad: ");
                scanf("%d",&persona[i].edad);
                validar("ERROR. Edad: ",persona[i].edad ,0,110);
                printf("Dni: ");
                scanf("%d",&dni);
                persona[i].dni = validar("ERROR. Dni: ",dni ,1,40000);
                persona[i].estado = 1;
            }
            else
                cont++;
        }
        if(cont == 4)
        {
           mostrar_agenda(persona,TAM);
           printf("\n\nEsta todo ocupado\n\n");
        }
    }
    return retorno;
}


int buscarPorDni(EPersona persona[], int dni)
{
    int retorno = -1;
    int i, TAM=20, cont = 0;
    if(TAM > 0 && persona != NULL)
    {
       retorno = -2;
       //PIDE QUE INGRESE UN DNI
       printf("DNI: ");
       fflush(stdin);
       scanf("%d", &dni);
       for(i=0; i<TAM; i++)
       {
         //BUSCA EL DNI EN EL ARRAY CARGADO SIEMPRE QUE EL ESTADO SEA 1, QUE SE HAYA CARGADO
         if(persona[i].estado == 1 && persona[i].dni == dni)
         {
              //BORRO LOS DATOS DE ESA POSICION
              persona[i].dni=0;
              persona[i].edad=0;
              strcpy(persona[i].nombre,"    ");
              persona[i].estado=0;
              printf("\nBorrado exitosamente\n");
         }else{ //RECORRE TODO EL ARRAY BUSCANDO EL DNI INGRESADO HASTA LLEGAR EL LIMITE
               cont++;
         }
       }
       if (cont==20)
       {
          //SI AL LLEGAR AL FINAL DEL CONTEO NO LO ENCONTRO, LE AVISA AL USUARIO
          printf("\nNo se encontro el dni ingresado\n");
       }
    }
    return retorno;
}


int validar(char mensaje[], int dato, int min, int max)
{
   while(dato<min || dato>max)
   {
      printf("%s", mensaje);
      fflush(stdin);
      scanf("%d", &dato);
   }
   return dato;
}


void ordenado_nombre (EPersona persona[], int TAM)
{
    int i=0, j, uax;
    char aux[20];
    printf("*Listado ordenado por nombre*\n");
    //Si el usuario cargo datos: ejecuta las instrucciones
    if(persona[i].estado == 1)
    {//ordeno los nombres de forma ascendete al abecedario
      for(i=0;i<TAM-1;i++)
      {
         for(j=i+1;j<TAM;j++)
         {
            //comparo la cantidad de caracteres de mi array y lo ordeno
            if(strcmp(persona[i].nombre,persona[j].nombre)>0)
            {
               strcpy(aux, persona[i].nombre);
               strcpy(persona[i].nombre,persona[j].nombre);
               strcpy(persona[j].nombre,aux);

               //paso el array de edad y del dni a un auxiliar para ordenarlo
               uax = persona[i].edad;
               persona[i].edad = persona[j].edad;
               persona[j].edad = uax;

               uax = persona[i].dni;
               persona[i].dni = persona[j].dni;
               persona[j].dni = uax;
            }
         }
      }
      mostrar_agenda(persona,TAM);
    }//llamo a la funcion que me muestra mi listado
    if(persona[i].estado == 0){
    //muestra el mensaje en caso de no haber ingresado previamente los datos
      printf("\nUps! No se cargo ningun dato\n\n");
    }
}

int grafico_agenda(EPersona persona[], int TAM)
{
  int i, j, max=0, menor=0, entre=0, mayor=0, valor[T];

  printf("**Imprimir grafico de edades**\n\n");
  for (i = 0; i < TAM; i++)
  {
    if(persona[i].estado == 1)
    {

      for (i = 0; i < TAM; i++)
      {
        //ASIGNA A CADA CONTADOR SEGUN LA EDAD QUE TENGA
        if(persona[i].edad<18 && persona[i].edad > 0)
        {
             menor = menor + 1;
        }
        if(persona[i].edad>19 && persona[i].edad <= 35)
        {
            entre = entre + 1;
        }
        if(persona[i].edad>35)
        {
            mayor = mayor + 1;
        }
      }
      //pasas los valores que tenes del contador al array que va a mostrar el grafico
      valor[0] = menor;
      valor[1] = entre;
      valor[2] = mayor;

      //recorro hasta el final asignando un maaximo al vector con los datos: menor, entre y mayor
      for (i = 0; i < T; i++)
        if (valor[i] > max)
           max = valor[i];

      for (i = max; i > 0; i--){
         for (j = 0; j < T; j++)
            if (valor[j] >= i)
                printf("  *  ");
            else
                printf("     ");

         putchar('\n');
      }
      printf(" <18  19-35  >35 \n");
      break;
    }
    if(persona[i].estado == 0)
    {
      printf("Ups! No se cargo ningun dato\n\n");
      break;
    }
  }
  return 0;
}
