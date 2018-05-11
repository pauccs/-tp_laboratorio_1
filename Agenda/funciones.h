#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED


typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;

}EPersona;


/**
 * Obtiene el primer indice libre del array.
 * @param persona el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(EPersona persona[],int);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param persona el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(EPersona persona[], int);

/**
 * Inicializa el estado del array en 0
 * \param persona el array se pasa como parametro.
 * \param tam tamanio del array
 *
 */
void inicializar_estado(EPersona persona[], int);

/**
 * Muestra mi listado precargado
 * \param persona listado con nombres ya cargados
 * \param tam tamanio del aaray
 * \return
 *
 */
void epersonas_hardcore (EPersona persona[], int);

/**
 * Carga los datos de la persona
 * \param persona el array se pasa como parametro.
 * \param tam tamanio del array
 *
 */
void cargar_agenda (EPersona persona[], int);

/**
 * Muestra la agenda que cargo el usuario anteriormente
 * \param persona el array se pasa como parametro.
 * \param tam tamanio del array
 *
 */

void mostrar_agenda (EPersona persona[], int);

/**
 * Busca la persona que paso el usuario por consola en el array cargado
 * \param persona el array se pasa como parametro.
 * \param tam tamanio del array
 *
 */

void borrar_agenda (EPersona persona[], int);

/**
 * Ordena por nombre el array cargado
 * \param persona el array se pasa como parametro.
 * \param tam tamanio del array
 *
 */
void ordenado_nombre (EPersona persona[], int);

/**
 * Muestra el grafico de las edades
 * \param persona el array se pasa como parametro.
 * \param tam tamanio del array
 *
 */
int grafico_agenda(EPersona persona[], int);


/**
 * Valida si el numero se encuentra en el rango que le digo
 * \param dato numero que le paso
 * \param mensaje es el mensaje que le muestro al usuario
 * \param min numero minimo para que valide
 * \param max numero maximo para que valide
 */
int validar(char mensaje[], int, int, int);
#endif // FUNCIONES_H_INCLUDED
