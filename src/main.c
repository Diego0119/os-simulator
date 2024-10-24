/**
 * @file main.c
 * @date 24-10-2024
 * @authors Miguel Loaiza, Diego Sanhueza y Oscar Cifuentes
 * @brief Función principal.
 *
 * Contiene la función principal del programa, donde se leen los argumentos de la terminal y se ejecutan las funciones de MEMORIA y PLANIFICACIÓN.
 */

#include "auxiliar.h" ///< Librería que contiene las funciones auxiliares.

/**
 * @brief Función principal del programa.
 * @param argc Cantidad de argumentos.
 * @param argv Argumentos.
 * @return EXIT_SUCCESS si el programa termina correctamente.
 */
int main(int argc, char *argv[])
{
    /**
     * Se LEEN los ARGUMENTOS de la TERMINAL y se GUARDAN en VARIABLES. Mientras se LEEN los ARGUMENTOS, se VALIDAN y se IMPRIMEN MENSAJES de AYUDA o ERROR. En caso de que sea correcto, se GUARDA el NOMBRE del ARCHIVO de ENTRADA.
     * @code
     *  int opt;
     *  char *nombre_archivo = NULL;
     *  while ((opt = getopt(argc, argv, "hf:")) != -1)
     *  {
     *      switch (opt)
     *      {
     *          case 'h':
     *              fprintf(stdout, "\nPara leer sus procesos, porfavor coloque el parametro <-f> <nombre_archivo.txt>\n\n");
     *              break;
     *          case 'f':
     *              nombre_archivo = optarg;
     *              printf("\nArchivo: %s\n\n", nombre_archivo);
     *              break;
     *          case '?':
     *              fprintf(stderr, "Opción no reconocida: -%c\n", optopt);
     *              exit(EXIT_FAILURE);
     *          default:
     *              fprintf(stderr, "Uso: %s [-h] [-f filename]\n", argv[0]);
     *              exit(EXIT_FAILURE);
     *      }
     *  }
     * @endcode
     */
    int opt;
    char *nombre_archivo = NULL;
    while ((opt = getopt(argc, argv, "hf:")) != -1)
    {
        switch (opt)
        {
        case 'h':
            fprintf(stdout, "\nPara leer sus procesos, porfavor coloque el parametro <-f> <nombre_archivo.txt>\n\n");
            break;
        case 'f':
            nombre_archivo = optarg;
            printf("\nArchivo: %s\n\n", nombre_archivo);
            break;
        case '?':
            fprintf(stderr, "Opción no reconocida: -%c\n", optopt);
            exit(EXIT_FAILURE);
        default:
            fprintf(stderr, "Uso: %s [-h] [-f filename]\n", argv[0]);
            exit(EXIT_FAILURE);
        }
    }

    /**
     * Se LEEN los VALORES de los PROCESOS del ARCHIVO de ENTRADA y se GUARDAN en VARIABLES. Se CALCULA la CANTIDAD de BLOQUES de MEMORIA y se INICIALIZAN los BLOQUES de MEMORIA. Se IMPRIME la MEMORIA y se ASIGNA la MEMORIA a los PROCESOS.
     * @code
     *  int tamano_memoria, tamano_bloque;
     *  char algoritmo_memoria[10], algoritmo_planificacion[10];
     *  Cola cola_procesos = {NULL, NULL};
     *  leer_entrada(nombre_archivo, &tamano_memoria, &tamano_bloque, algoritmo_memoria, algoritmo_planificacion, &cola_procesos);
     *  int cantidad_bloques = tamano_memoria / tamano_bloque;
     *  BloqueMemoria memoria[cantidad_bloques];
     *  inicializar_bloques_memoria(memoria, cantidad_bloques, tamano_bloque);
     *  imprimir_memoria(memoria, cantidad_bloques);
     *  asignar_memoria_procesos(&cola_procesos, memoria, cantidad_bloques);
     *  return EXIT_SUCCESS;
     * @endcode
     */
    int tamano_memoria, tamano_bloque;
    char algoritmo_memoria[10], algoritmo_planificacion[10];
    Cola cola_procesos = {NULL, NULL};
    leer_entrada(nombre_archivo, &tamano_memoria, &tamano_bloque, algoritmo_memoria, algoritmo_planificacion, &cola_procesos);
    int cantidad_bloques = tamano_memoria / tamano_bloque;
    BloqueMemoria memoria[cantidad_bloques];
    inicializar_bloques_memoria(memoria, cantidad_bloques, tamano_bloque);
    imprimir_memoria(memoria, cantidad_bloques);
    asignar_memoria_procesos(&cola_procesos, memoria, cantidad_bloques);
    return EXIT_SUCCESS;
}
