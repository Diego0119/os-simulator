/**
 * @file memoria.h
 * @date 24-10-2024
 * @authors Miguel Loaiza, Diego Sanhueza y Oscar Cifuentes
 * @brief Prototipos de funciones dedicadas a la memoria y estructura de los BLOQUES de MEMORIA.
 *
 * Contiene los prototipos de las funciones dedicadas a la asignación de memoria a los procesos (First Fit) y la estructura de los BLOQUES de MEMORIA.
 */

#ifndef MEMORIA_H
#define MEMORIA_H

#define MAX_PROCESOS 100 ///< Máximo de PROCESOS que se imprimen en el DIAGRAMA de GANTT.

#include "planificador.h" ///< Librería que contiene las funciones de PLANIFICACIÓN y la estructura de un PROCESO.

/**
 * @struct BloqueMemoria
 * @brief Estructura de un BLOQUE de MEMORIA.
 * @code
 *  typedef struct
 *  {
 *      int tamano;
 *      int estado;
 *  } BloqueMemoria;
 * @endcode
 *
 * En esta estructura se define un BLOQUE de MEMORIA con un tamaño y un estado (1 cuando está LIBRE y 0 cuando está OCUPADO).
 */
typedef struct
{
    int tamano;
    int estado;
} BloqueMemoria;

/**
 * @brief Inicializa los BLOQUES de MEMORIA.
 * @param memoria Arreglo de BLOQUES de MEMORIA.
 * @param cantidad_bloques Cantidad de BLOQUES de MEMORIA.
 * @param tamano_bloque Tamaño de los BLOQUES de MEMORIA.
 */
void inicializar_bloques_memoria(BloqueMemoria *, int, int);

/**
 * @brief Asigna MEMORIA a los PROCESOS para la EJECUCIÓN.
 * @param cola Cola de PROCESOS.
 * @param memoria Arreglo de BLOQUES de MEMORIA.
 * @param cantidad_bloques Cantidad de BLOQUES de MEMORIA.
 */
void asignar_memoria_procesos(Cola *, BloqueMemoria *, int);

/**
 * @brief Asigna un BLOQUE de MEMORIA a un PROCESO.
 * @param memoria Arreglo de BLOQUES de MEMORIA.
 * @param proceso PROCESO a asignar.
 * @param tamano_proceso Tamaño del PROCESO.
 * @param i Índice del BLOQUE de MEMORIA.
 */
void asignar_bloque_proceso(BloqueMemoria *, Proceso *, int *, int);

/**
 * @brief Verifica la FRAGMENTACIÓN INTERNA.
 * @param memoria Arreglo de BLOQUES de MEMORIA.
 * @param i Índice del BLOQUE de MEMORIA.
 */
void verificar_fragmentacion(BloqueMemoria *, int);

/**
 * @brief Maneja el PROCESO.
 * @param memoria Arreglo de BLOQUES de MEMORIA.
 * @param proceso PROCESO a manejar.
 * @param cantidad_bloques Cantidad de BLOQUES de MEMORIA.
 * @param diagrama_gantt Diagrama de Gantt.
 * @param tiempo_global Tiempo global de ejecución.
 * @param indice Índice del diagrama de Gantt.
 */
void manejar_proceso(BloqueMemoria *, Proceso *, int, Gantt *, int *, int *);

/**
 * @brief Simula la ejecución de un PROCESO.
 * @param memoria Arreglo de BLOQUES de MEMORIA.
 * @param proceso PROCESO a ejecutar.
 * @param i Índice del BLOQUE de MEMORIA.
 */
void ejecutar_proceso(BloqueMemoria *, Proceso *, int);

/**
 * @brief Libera la MEMORIA de un PROCESO.
 * @param memoria Arreglo de BLOQUES de MEMORIA.
 * @param i Índice del BLOQUE de MEMORIA.
 */
void liberar_memoria(BloqueMemoria *, int);

#endif
