/**
 * @file auxiliar.h
 * @date 24-10-2024
 * @authors Miguel Loaiza, Diego Sanhueza y Oscar Cifuentes
 * @brief Prototipos de funciones auxiliares.
 *
 * Contiene los prototipos de las funciones auxiliares que son utilizadas para el correcto funcionamiento de los archivos de MEMORIA y PLANIFICACIÓN.
 */

#ifndef AUXILIAR_H
#define AUXILIAR_H

#include "memoria.h" ///< Librería que contiene las funciones de MEMORIA y la estructra del BLOQUE de MEMORIA.

/**
 * @brief Lee la entrada del archivo de texto (entrada.txt).
 * @param nombre_archivo Nombre del archivo de texto.
 * @param tamano_memoria Tamaño de la memoria TOTAL (2048 KB).
 * @param tamano_bloque Tamaño de los BLOQUES de MEMORIA (128 KB).
 * @param algoritmo_memoria Algoritmo de MEMORIA (FF).
 * @param algoritmo_planificacion Algoritmo de PLANIFICACIÓN (FIFO).
 * @param cola_procesos Cola de PROCESOS.
 */
void leer_entrada(const char *, int *, int *, char *, char *, Cola *);

/**
 * @brief Crea un nuevo PROCESO y le asigna los VALORES.
 * @param id ID del proceso.
 * @param tiempo_llegada Tiempo de llegada del proceso.
 * @param tiempo_rafaga Tiempo de ráfaga del proceso.
 * @param memoria_solicitada Memoria solicitada por el proceso.
 * @param cola_procesos Cola de PROCESOS.
 */
void asignar_valores_procesos(int, int, int, int, Cola *);

/**
 * @brief Imprime la COLA de PROCESOS.
 * @param cola Cola de PROCESOS.
 */
void imprimir_cola_procesos(Cola *);

/**
 * @brief Imprime los BLOQUES de MEMORIA INICIALIZADOS.
 * @param memoria Arreglo de BLOQUES de MEMORIA.
 * @param cantidad_bloques Cantidad de BLOQUES de MEMORIA.
 */
void imprimir_memoria(BloqueMemoria *, int);

/**
 * @brief Registra los TIEMPOS de los PROCESOS.
 * @param diagrama_gantt Diagrama de Gantt.
 * @param pid ID del proceso.
 * @param tiempo_inicio Tiempo de inicio del proceso.
 * @param tiempo_rafaga Tiempo de ráfaga del proceso.
 * @param indice Índice del diagrama de Gantt.
 */
void registrar_tiempos(Gantt *, int, int, int, int *);

/**
 * @brief Imprime el DIAGRAMA de GANTT.
 * @param diagrama_gantt Diagrama de Gantt.
 * @param num_procesos Número de procesos.
 */
void imprimir_gantt(Gantt *, int);

/**
 * @brief Genera el ARCHIVO EPS que muestra la CARTA GANTT.
 * @param diagrama_gantt Diagrama de Gantt.
 * @param num_procesos Número de procesos.
 * @param carta_gantt Nombre del archivo de la carta Gantt.
 */
void generar_archivo_gantt(Gantt *, int, const char *);

/**
 * @brief Genera un ARCHIVO que muestra la CARTA GANTT.
 * @param diagrama_gantt Diagrama de Gantt.
 * @param num_procesos Número de procesos.
 * @param carta_gantt Nombre del archivo de la carta Gantt.
 */
void generar_archivo_gantt(Gantt *, int, const char *);

#endif
