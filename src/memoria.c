/**
 * @file memoria.c
 * @date 24-10-2024
 * @authors Miguel Loaiza, Diego Sanhueza y Oscar Cifuentes
 * @brief Funciones de memoria.
 *
 * Contiene las funciones qe son utilizadas para la CORRECTA asignación de MEMORIA a los PROCESOS.
 */

#include "auxiliar.h" ///< Librería que contiene las funciones auxiliares.

/**
 * @brief Inicializa los BLOQUES de MEMORIA.
 * @param memoria Arreglo de BLOQUES de MEMORIA.
 * @param cantidad_bloques Cantidad de BLOQUES de MEMORIA.
 * @param tamano_bloque Tamaño de los BLOQUES de MEMORIA.
 */
void inicializar_bloques_memoria(BloqueMemoria *memoria, int cantidad_bloques, int tamano_bloque)
{
    /**
     * Recorre el ARREGLO de MEMORIA y asigna el TAMAÑO del BLOQUE y el ESTADO del BLOQUE.
     * @code
     *  for (int i = 0; i < cantidad_bloques; i++)
     *  {
     *      memoria[i].tamano = tamano_bloque;
     *      memoria[i].estado = 1;
     *  }
     * @endcode
     */
    for (int i = 0; i < cantidad_bloques; i++)
    {
        memoria[i].tamano = tamano_bloque;
        memoria[i].estado = 1;
    }
}

/**
 * @brief Asigna la MEMORIA a los PROCESOS para la EJECUCIÓN.
 * @param cola Cola de PROCESOS.
 * @param memoria Arreglo de BLOQUES de MEMORIA.
 * @param cantidad_bloques Cantidad de BLOQUES de MEMORIA.
 */
void asignar_memoria_procesos(Cola *cola, BloqueMemoria *memoria, int cantidad_bloques)
{
    /**
     * Se CREA una COPIA de la COLA de PROCESOS y se EXTRAE el PROCESO de la COLA. Se CREA un DIAGRAMA de GANTT y se INICIALIZAN las VARIABLES.
     * @code
     *  Cola *temp_cola = malloc(sizeof(Cola));
     *  temp_cola = cola;
     *  Proceso *proceso_extraido = malloc(sizeof(Proceso));
     *  Gantt diagrama_gantt[MAX_PROCESOS];
     *  int indice = 0, tiempo_global = 0;
     * @endcode
     */
    Cola *temp_cola = malloc(sizeof(Cola));
    temp_cola = cola;
    Proceso *proceso_extraido = malloc(sizeof(Proceso));
    Gantt diagrama_gantt[MAX_PROCESOS];
    int indice = 0, tiempo_global = 0;

    /**
     * MIENTRAS la COLA de PROCESOS NO esté VACÍA, se EXTRAE el PROCESO de la COLA y se MANEJA el PROCESO. Depués de manejar el proceso, se libera el PROCESO EXTRAIDO. Posteriormente se IMPRIME el DIAGRAMA de GANTT.
     * @code
     *  while (temp_cola->front != NULL)
     *  {
     *      proceso_extraido = dequeue(temp_cola);
     *      if (proceso_extraido == NULL)
     *      {
     *          fprintf(stdout, "No hay procesos en la cola para asignar memoria.\n");
     *          return;
     *      }
     *      manejar_proceso(memoria, proceso_extraido, cantidad_bloques, diagrama_gantt, &tiempo_global, &indice);
     *      free(proceso_extraido);
     *  }
     *  imprimir_gantt(diagrama_gantt, indice);
     *  generar_archivo_gantt(diagrama_gantt, indice, "gantt.eps");
     * @endcode
     */
    while (temp_cola->front != NULL)
    {
        proceso_extraido = dequeue(temp_cola);
        if (proceso_extraido == NULL)
        {
            fprintf(stdout, "No hay procesos en la cola para asignar memoria.\n");
            return;
        }
        manejar_proceso(memoria, proceso_extraido, cantidad_bloques, diagrama_gantt, &tiempo_global, &indice);
        free(proceso_extraido);
    }
    imprimir_gantt(diagrama_gantt, indice);
    generar_archivo_gantt(diagrama_gantt, indice, "gantt.eps");
}

/**
 * @brief Maneja el PROCESO, asigna MEMORIA y REGISTRA los tiempos de los procesos.
 * @param memoria Arreglo de BLOQUES de MEMORIA.
 * @param proceso_extraido Proceso extraído de la COLA.
 * @param cantidad_bloques Cantidad de BLOQUES de MEMORIA.
 * @param diagrama_gantt Diagrama de Gantt.
 * @param tiempo_global Tiempo global.
 * @param indice Índice del diagrama de Gantt.
 */
void manejar_proceso(BloqueMemoria *memoria, Proceso *proceso_extraido, int cantidad_bloques, Gantt *diagrama_gantt, int *tiempo_global, int *indice)
{
    /**
     * Se GUARDA el TIEMPO de INICIO del PROCESO y el TAMAÑO del PROCESO. Si el TAMAÑO del PROCESO es mayor a 2048, se imprime un MENSAJE de ERROR. Se RECORRE los BLOQUES de MEMORIA y se ASIGNA la MEMORIA al PROCESO.
     * @code
     *  int tiempo_inicio = *tiempo_global;
     *  int tamano_proceso = proceso_extraido->memoria_solicitada;
     *  if (tamano_proceso > 2048)
     *  {
     *      fprintf(stderr, "No hay suficiente memoria disponible para asignar al PROCESO %d, pasando al siguiente PROCESO.\n\n", proceso_extraido->pid);
     *      return;
     *  }
     *  for (int i = 0; i < cantidad_bloques && tamano_proceso > 0; i++)
     *  {
     *      if (memoria[i].estado == 1)
     *      {
     *          asignar_bloque_proceso(memoria, proceso_extraido, &tamano_proceso, i);
     *      }
     *  }
     *  *tiempo_global += proceso_extraido->tiempo_rafaga;
     *  registrar_tiempos(diagrama_gantt, proceso_extraido->pid, tiempo_inicio, proceso_extraido->tiempo_rafaga, indice);
     *  fprintf(stdout, "Proceso %d EJECUTADO EXITOSAMENTE.\n\n", proceso_extraido->pid);
     * @endcode
     */
    int tiempo_inicio = *tiempo_global;
    int tamano_proceso = proceso_extraido->memoria_solicitada;
    if (tamano_proceso > 2048)
    {
        fprintf(stderr, "No hay suficiente memoria disponible para asignar al PROCESO %d, pasando al siguiente PROCESO.\n\n", proceso_extraido->pid);
        return;
    }
    for (int i = 0; i < cantidad_bloques && tamano_proceso > 0; i++)
    {
        if (memoria[i].estado == 1)
        {
            asignar_bloque_proceso(memoria, proceso_extraido, &tamano_proceso, i);
        }
    }
    *tiempo_global += proceso_extraido->tiempo_rafaga;
    registrar_tiempos(diagrama_gantt, proceso_extraido->pid, tiempo_inicio, proceso_extraido->tiempo_rafaga, indice);
    fprintf(stdout, "Proceso %d EJECUTADO EXITOSAMENTE.\n\n", proceso_extraido->pid);
}

/**
 * @brief Asigna el BLOQUE de MEMORIA al PROCESO.
 * @param memoria Arreglo de BLOQUES de MEMORIA.
 * @param proceso Proceso.
 * @param tamano_proceso Tamaño del proceso.
 * @param i Índice.
 */
void asignar_bloque_proceso(BloqueMemoria *memoria, Proceso *proceso, int *tamano_proceso, int i)
{
    /**
     * Si el TAMAÑO de MEMORIA del PROCESO alcanza en un solo BLOQUE hace la signación COMPLETA del BLOQUE, si no, toma más de uno y lo asigna PARCIALMENTE.
     * @code
     *  if (memoria[i].tamano >= *tamano_proceso)
     *  {
     *      fprintf(stdout, "El proceso %d usó MEMORIA hasta el BLOQUE %d\n", proceso->pid, i);
     *      memoria[i].tamano -= *tamano_proceso;
     *      memoria[i].estado = 0;
     *      *tamano_proceso = 0;
     *      verificar_fragmentacion(memoria, i);
     *      ejecutar_proceso(memoria, proceso, i);
     *  }
     *  else
     *  {
     *      *tamano_proceso -= memoria[i].tamano;
     *      memoria[i].tamano = 0;
     *      memoria[i].estado = 0;
     *      fprintf(stdout, "Proceso %d en EJECUCIÓN, bloque (%d)\n", proceso->pid, i);
     *      ejecutar_proceso(memoria, proceso, i);
     *      verificar_fragmentacion(memoria, i);
     *  }
     * @endcode
     */
    if (memoria[i].tamano >= *tamano_proceso)
    {
        fprintf(stdout, "El proceso %d usó MEMORIA hasta el BLOQUE %d\n", proceso->pid, i);
        memoria[i].tamano -= *tamano_proceso;
        memoria[i].estado = 0;
        *tamano_proceso = 0;
        verificar_fragmentacion(memoria, i);
        ejecutar_proceso(memoria, proceso, i);
    }
    else
    {
        *tamano_proceso -= memoria[i].tamano;
        memoria[i].tamano = 0;
        memoria[i].estado = 0;
        fprintf(stdout, "Proceso %d en EJECUCIÓN, bloque (%d)\n", proceso->pid, i);
        ejecutar_proceso(memoria, proceso, i);
        verificar_fragmentacion(memoria, i);
    }
}

/**
 * @brief Verifica la FRAGMENTACIÓN INTERNA.
 * @param memoria Arreglo de BLOQUES de MEMORIA.
 * @param i Índice.
 */
void verificar_fragmentacion(BloqueMemoria *memoria, int i)
{
    /**
     * Calcula la FRAGMENTACIÓN INTERNA. Si el tamaño de la memoria del PROCESO es mayor a 0, hay fragmentación interna.
     * @code
     *  int fragmentacion_interna = memoria[i].tamano;
     *  if (fragmentacion_interna > 0)
     *      fprintf(stdout, "FRAGMENTACIÓN INTERNA: %d KB en el BLOQUE %d\n", fragmentacion_interna, i);
     * @endcode
     */
    int fragmentacion_interna = memoria[i].tamano;
    if (fragmentacion_interna > 0)
        fprintf(stdout, "FRAGMENTACIÓN INTERNA: %d KB en el BLOQUE %d\n", fragmentacion_interna, i);
}

/**
 * @brief Ejecuta el PROCESO.
 * @param memoria Arreglo de BLOQUES de MEMORIA.
 * @param proceso Proceso.
 * @param posicion Posición.
 */
void ejecutar_proceso(BloqueMemoria *memoria, Proceso *proceso, int posicion)
{
    /**
     * SIMULA la ejecución del PROCESO y luego LIBERA la MEMORIA del PROCESO.
     * @code
     *  sleep(proceso->tiempo_rafaga);
     *  liberar_memoria(memoria, posicion);
     * @endcode
     */
    sleep(proceso->tiempo_rafaga);
    liberar_memoria(memoria, posicion);
}

/**
 * @brief Libera la MEMORIA de un PROCESO.
 * @param memoria Arreglo de BLOQUES de MEMORIA.
 * @param posicion Posición.
 */
void liberar_memoria(BloqueMemoria *memoria, int posicion)
{
    /**
     * LIBERA la MEMORIA de un PROCESO y la MARCA como LIBRE (1).
     * @code
     *  memoria[posicion].estado = 1;
     *  memoria[posicion].tamano = 128;
     * @endcode
     */
    memoria[posicion].estado = 1;
    memoria[posicion].tamano = 128;
}
