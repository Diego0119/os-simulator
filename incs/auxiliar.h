#ifndef AUXILIAR_H
#define AUXILIAR_H

#include "memoria.h"

// Funciones AUXILIARES para las funciones de MEMORIA y PLANIFICACIÓN.
void leer_entrada(const char *, int *, int *, char *, char *, Cola *);                        // LEER la entrada del ARCHIVO.
void asignar_valores_procesos(int, int, int, int, Cola *);                                    // Asignar VALORES a los PROCESOS.
void imprimir_cola_procesos(Cola *);                                                          // Imprimir la COLA de PROCESOS.
void imprimir_memoria(BloqueMemoria *, int);                                                  // Imprimir los BLOQUES de MEMORIA INICIALIZADOS.
void registrar_tiempos(Gantt *, int, int, int, int *);                                        // Registrar los TIEMPOS de los PROCESOS.
void imprimir_gantt(Gantt *, int);                                                            // Imprimir el DIAGRAMA de GANTT.
void generar_archivo_gantt(Gantt *, int, const char *);                                       // Generar el ARCHIVO EPS que muestra la CARTA GANTT.
void generar_archivo_gantt(Gantt *diagrama_gantt, int num_procesos, const char *carta_gantt); // Generar el ARCHIVO EPS que muestra la CARTA GANTT.

#endif // AUXILIAR_H
