/**
 * @file auxiliar.c
 * @date 24-10-2024
 * @authors Miguel Loaiza, Diego Sanhueza y Oscar Cifuentes
 * @brief Funciones auxiliares.
 *
 * Contiene las funciones auxiliares que son utilizadas para el correcto funcionamiento de los archivos de MEMORIA y PLANIFICACIÓN.
 */

#include "auxiliar.h" ///< Librería que contiene las funciones auxiliares.

/**
 * @brief Lee la entrada del archivo de texto (entrada.txt).
 * @param nombre_archivo Nombre del archivo de texto.
 * @param tamano_memoria Tamaño de la memoria TOTAL (2048 KB).
 * @param tamano_bloque Tamaño de los BLOQUES de MEMORIA (128 KB).
 * @param algoritmo_memoria Algoritmo de MEMORIA (FF).
 * @param algoritmo_planificacion Algoritmo de PLANIFICACIÓN (FIFO).
 * @param cola_procesos Cola de PROCESOS.
 */
void leer_entrada(const char *nombre_archivo, int *tamano_memoria, int *tamano_bloque, char *algoritmo_memoria, char *algoritmo_planificacion, Cola *cola_procesos)
{
    /**
     * Se abre el archivo de entrada en modo LECTURA y se VERIFICA si se abrió correctamente.
     * @code
     *  FILE *archivo_entrada = fopen(nombre_archivo, "r");
     *  if (archivo_entrada == NULL)
     *  {
     *      fprintf(stderr, "ERROR al abrir el archivo, saliendo...\n");
     *      exit(EXIT_FAILURE);
     *  }
     * @endcode
     */
    FILE *archivo_entrada = fopen(nombre_archivo, "r");
    if (archivo_entrada == NULL)
    {
        fprintf(stderr, "ERROR al abrir el archivo, saliendo...\n");
        exit(EXIT_FAILURE);
    }

    /**
     * Lee la cabecera del archivo de entrada (2048 128 ff) y VERIFICA si los valores son 3, también lee el algoritmo de planificación (FIFO) y verifica si el valor es 1.
     * @code
     *  if (fscanf(archivo_entrada, "%d %d %s", tamano_memoria, tamano_bloque, algoritmo_memoria) != 3)
     *  {
     *      fprintf(stderr, "ERROR al leer los valores de la memoria o bloque, saliendo...\n");
     *      exit(EXIT_FAILURE);
     *  }
     *
     *  if (fscanf(archivo_entrada, "%s", algoritmo_planificacion) != 1)
     *  {
     *      fprintf(stderr, "Error al leer el algoritmo de planificación\n");
     *      exit(EXIT_FAILURE);
     *  }
     * @endcode
     */
    if (fscanf(archivo_entrada, "%d %d %s", tamano_memoria, tamano_bloque, algoritmo_memoria) != 3)
    {
        fprintf(stderr, "ERROR al leer los valores de la memoria o bloque, saliendo...\n");
        exit(EXIT_FAILURE);
    }
    if (fscanf(archivo_entrada, "%s", algoritmo_planificacion) != 1)
    {
        fprintf(stderr, "Error al leer el algoritmo de planificación\n");
        exit(EXIT_FAILURE);
    }

    /**
     * VARIABLES del PROCESO (vienen de entrada.txt). Lee los VALORES de los PROCESOS del archivo de entrada y llama la función "asignar_valores_procesos", luego cierra el archivo.
     * @code
     *  int id, tiempo_llegada, tiempo_rafaga, memoria_solicitada;
     *  while (fscanf(archivo_entrada, "%d %d %d %d", &id, &tiempo_llegada, &tiempo_rafaga, &memoria_solicitada) != EOF)
     *      asignar_valores_procesos(id, tiempo_llegada, tiempo_rafaga, memoria_solicitada, cola_procesos);
     *  fclose(archivo_entrada);
     * @endcode
     */
    int id, tiempo_llegada, tiempo_rafaga, memoria_solicitada;
    while (fscanf(archivo_entrada, "%d %d %d %d", &id, &tiempo_llegada, &tiempo_rafaga, &memoria_solicitada) != EOF)
        asignar_valores_procesos(id, tiempo_llegada, tiempo_rafaga, memoria_solicitada, cola_procesos);
    fclose(archivo_entrada);
}

/**
 * @brief Crea un nuevo PROCESO y le asigna los VALORES.
 * @param id ID del proceso.
 * @param tiempo_llegada Tiempo de llegada del proceso.
 * @param tiempo_rafaga Tiempo de ráfaga del proceso.
 * @param memoria_solicitada Memoria solicitada por el proceso.
 * @param cola_procesos Cola de PROCESOS.
 */
void asignar_valores_procesos(int id, int tiempo_llegada, int tiempo_rafaga, int memoria_solicitada, Cola *cola_procesos)
{
    /**
     * Se CREA un NUEVO PROCESO y se ASIGNAN los VALORES necesarios, luego se llama a la función "enqueue" para colocar en la COLA el PROCESO.
     * @code
     *  Proceso *nuevo_proceso = (Proceso *)malloc(sizeof(Proceso));
     *  nuevo_proceso->pid = id;
     *  nuevo_proceso->tiempo_llegada = tiempo_llegada;
     *  nuevo_proceso->tiempo_rafaga = tiempo_rafaga;
     *  nuevo_proceso->memoria_solicitada = memoria_solicitada;
     *  nuevo_proceso->next = NULL;
     *  fprintf(stdout, "Proceso %d - T. Llegada %d - T. Ráfaga %d - M. Solicitada %d\n", id, tiempo_llegada, tiempo_rafaga, memoria_solicitada);
     *  enqueue(cola_procesos, nuevo_proceso);
     * @endcode
     */
    Proceso *nuevo_proceso = (Proceso *)malloc(sizeof(Proceso));
    nuevo_proceso->pid = id;
    nuevo_proceso->tiempo_llegada = tiempo_llegada;
    nuevo_proceso->tiempo_rafaga = tiempo_rafaga;
    nuevo_proceso->memoria_solicitada = memoria_solicitada;
    nuevo_proceso->next = NULL;
    fprintf(stdout, "Proceso %d - T. Llegada %d - T. Ráfaga %d - M. Solicitada %d\n", id, tiempo_llegada, tiempo_rafaga, memoria_solicitada);
    enqueue(cola_procesos, nuevo_proceso);
}

/**
 * @brief Imprime la COLA de PROCESOS.
 * @param cola Cola de PROCESOS.
 */
void imprimir_cola_procesos(Cola *cola)
{
    /**
     * Se IMPRIME la COLA de PROCESOS, se recorre la COLA y se imprime PROCESO actual, luego se actualiza el PROCESO actual.
     * @code
     *  Proceso *actual = cola->front;
     *  fprintf(stdout, "\nCola de procesos:\n");
     *  long actual_next = (long)actual->next;
     *  while (actual != NULL)
     *  {
     *      fprintf(stdout, "[Pid: %d]\t[Memoria Solicitada: %d]\t[Next: %ld]->\n", actual->pid, actual->memoria_solicitada, actual_next);
     *      actual = actual->next;
     *  }
     * @endcode
     */
    Proceso *actual = cola->front;
    fprintf(stdout, "\nCola de procesos:\n");
    long actual_next = (long)actual->next;
    while (actual != NULL)
    {
        fprintf(stdout, "[PID: %d]\t[Memoria Solicitada: %d]\t[Next: %ld]->\n", actual->pid, actual->memoria_solicitada, actual_next);
        actual = actual->next;
    }
}

/**
 * @brief Imprime los BLOQUES de MEMORIA INICIALIZADOS.
 * @param memoria Arreglo de BLOQUES de MEMORIA.
 * @param cantidad_bloques Cantidad de BLOQUES de MEMORIA.
 */
void imprimir_memoria(BloqueMemoria *memoria, int cantidad_bloques)
{
    /**
     * Se IMPRIME los BLOQUES de MEMORIA INICIALIZADOS, se recorre el ARREGLO de MEMORIA y se imprime el BLOQUE actual.
     * @code
     *  fprintf(stdout, "Bloques de memoria del SISTEMA OPERATIVO:\n\n");
     *  for (int i = 0; i < cantidad_bloques; i++)
     *      fprintf(stdout, "[Bloque %d]\t[Tamaño %d]\t[Estado %d][LIBRE]\n", i, memoria[i].tamano, memoria[i].estado);
     *  fprintf(stdout, "\n");
     * @endcode
     */
    fprintf(stdout, "Bloques de memoria del SISTEMA OPERATIVO:\n\n");
    for (int i = 0; i < cantidad_bloques; i++)
        fprintf(stdout, "[Bloque %d]\t[Tamaño %d]\t[Estado %d][LIBRE]\n", i, memoria[i].tamano, memoria[i].estado);
    fprintf(stdout, "\n");
}

/**
 * @brief Registra los TIEMPOS de los PROCESOS.
 * @param diagrama_gantt Diagrama de Gantt.
 * @param pid ID del proceso.
 * @param tiempo_inicio Tiempo de inicio del proceso.
 * @param tiempo_rafaga Tiempo de ráfaga del proceso.
 * @param indice Índice del diagrama de Gantt.
 */
void registrar_tiempos(Gantt *diagrama_gantt, int pid, int tiempo_inicio, int tiempo_rafaga, int *indice)
{
    /**
     * Se REGISTRAN los TIEMPOS de los PROCESOS, se asignan los valores al DIAGRAMA de GANTT y se actualiza el ÍNDICE del diagrama de Gantt.
     * @code
     *  diagrama_gantt[*indice].pid = pid;
     *  diagrama_gantt[*indice].tiempo_inicio = tiempo_inicio;
     *  diagrama_gantt[*indice].tiempo_final = tiempo_inicio + tiempo_rafaga;
     *  (*indice)++;
     * @endcode
     */
    diagrama_gantt[*indice].pid = pid;
    diagrama_gantt[*indice].tiempo_inicio = tiempo_inicio;
    diagrama_gantt[*indice].tiempo_final = tiempo_inicio + tiempo_rafaga;
    (*indice)++;
}

/**
 * @brief Imprime el DIAGRAMA de GANTT.
 * @param diagrama_gantt Diagrama de Gantt.
 * @param num_procesos Número de procesos.
 */
void imprimir_gantt(Gantt *diagrama_gantt, int num_procesos)
{
    /**
     * Se IMPRIME el DIAGRAMA de GANTT, se recorre el DIAGRAMA de GANTT y se imprime el PROCESO actual.
     * @code
     *  fprintf(stdout, "Diagrama de Gantt:\n\n");
     *  for (int i = 0; i < num_procesos; i++)
     *      fprintf(stdout, "[PID: %d]\t[Tiempo Inicio: %d]\t[Tiempo Final: %d]\n", diagrama_gantt[i].pid, diagrama_gantt[i].tiempo_inicio, diagrama_gantt[i].tiempo_final);
     * @endcode
     */
    fprintf(stdout, "Diagrama de Gantt:\n\n");
    for (int i = 0; i < num_procesos; i++)
        fprintf(stdout, "[PID: %d]\t[Tiempo Inicio: %d]\t[Tiempo Final: %d]\n", diagrama_gantt[i].pid, diagrama_gantt[i].tiempo_inicio, diagrama_gantt[i].tiempo_final);
}

/**
 * @brief Genera el ARCHIVO EPS que muestra la CARTA GANTT. Al final se convierte el archivo EPS a PNG.
 * @param diagrama_gantt Diagrama de Gantt.
 * @param num_procesos Número de procesos.
 * @param carta_gantt Nombre del archivo de la carta Gantt.
 */
void generar_archivo_gantt(Gantt *diagrama_gantt, int num_procesos, const char *carta_gantt)
{
    /**
     * Se abre el archivo de GANTT en modo ESCRITURA y se VERIFICA si se abrió correctamente.
     * @code
     *  FILE *archivo_gantt = fopen(carta_gantt, "w");
     *  if (archivo_gantt == NULL)
     *  {
     *      fprintf(stderr, "ERROR al abrir el archivo de Gantt, saliendo...\n");
     *      exit(EXIT_FAILURE);
     *  }
     * @endcode
     */
    FILE *archivo_gantt = fopen(carta_gantt, "w");
    if (archivo_gantt == NULL)
    {
        fprintf(stderr, "ERROR al abrir el archivo de Gantt, saliendo...\n");
        exit(EXIT_FAILURE);
    }

    /**
     * VARIABLES para DIBUJAR la CARTA GANTT. Se DIBUJAN los RECTÁNGULOS de los PROCESOS y se COLOREAN, se PINTA el BORDE del RECTÁNGULO y se ESCRIBE el ID del PROCESO en el eje Y.
     * @code
     *  int altura_proceso = 50;
     *  int margen_inferior = 100, margen_superior = 50, margen_lateral = 100;
     *  int ancho_total = 800, altura_total = (num_procesos * altura_proceso) + margen_superior + margen_inferior;
     *  fprintf(archivo_gantt, "%%!PS-Adobe-3.0 EPSF-3.0\n");
     *  fprintf(archivo_gantt, "%%%%BoundingBox: 0 0 %d %d\n", ancho_total + margen_lateral * 2, altura_total);
     *  for (int i = 0; i < num_procesos; i++)
     *  {
     *      int tiempo_inicio = diagrama_gantt[i].tiempo_inicio;
     *      int tiempo_final = diagrama_gantt[i].tiempo_final;
     *      int pid = diagrama_gantt[i].pid;
     *      int x_inicio = margen_lateral + tiempo_inicio * 10;
     *      int x_final = margen_lateral + tiempo_final * 10;
     *      int y = margen_inferior + i * altura_proceso;
     *      fprintf(archivo_gantt, "newpath\n");
     *      fprintf(archivo_gantt, "%d %d moveto\n", x_inicio, y);
     *      fprintf(archivo_gantt, "%d %d lineto\n", x_final, y);
     *      fprintf(archivo_gantt, "%d %d lineto\n", x_final, y + altura_proceso - 10);
     *      fprintf(archivo_gantt, "%d %d lineto\n", x_inicio, y + altura_proceso - 10);
     *      fprintf(archivo_gantt, "closepath\n");
     *      fprintf(archivo_gantt, "0.207 0.706 0.941 setrgbcolor\n");
     *      fprintf(archivo_gantt, "fill\n");
     *      fprintf(archivo_gantt, "0 0 0 setrgbcolor\n");
     *      fprintf(archivo_gantt, "stroke\n");
     *      fprintf(archivo_gantt, "/Times-Roman findfont 12 scalefont setfont\n");
     *      fprintf(archivo_gantt, "%d %d moveto\n", margen_lateral - 50, y + altura_proceso / 2);
     *      fprintf(archivo_gantt, "(ID %d) show\n", pid);
     *  }
     * @endcode
     */
    int altura_proceso = 50;
    int margen_inferior = 100, margen_superior = 50, margen_lateral = 100;
    int ancho_total = 800, altura_total = (num_procesos * altura_proceso) + margen_superior + margen_inferior;
    fprintf(archivo_gantt, "%%!PS-Adobe-3.0 EPSF-3.0\n");
    fprintf(archivo_gantt, "%%%%BoundingBox: 0 0 %d %d\n", ancho_total + margen_lateral * 2, altura_total);
    for (int i = 0; i < num_procesos; i++)
    {
        int tiempo_inicio = diagrama_gantt[i].tiempo_inicio;
        int tiempo_final = diagrama_gantt[i].tiempo_final;
        int pid = diagrama_gantt[i].pid;
        int x_inicio = margen_lateral + tiempo_inicio * 10;
        int x_final = margen_lateral + tiempo_final * 10;
        int y = margen_inferior + i * altura_proceso;
        fprintf(archivo_gantt, "newpath\n");
        fprintf(archivo_gantt, "%d %d moveto\n", x_inicio, y);
        fprintf(archivo_gantt, "%d %d lineto\n", x_final, y);
        fprintf(archivo_gantt, "%d %d lineto\n", x_final, y + altura_proceso - 10);
        fprintf(archivo_gantt, "%d %d lineto\n", x_inicio, y + altura_proceso - 10);
        fprintf(archivo_gantt, "closepath\n");
        fprintf(archivo_gantt, "0.207 0.706 0.941 setrgbcolor\n");
        fprintf(archivo_gantt, "fill\n");
        fprintf(archivo_gantt, "0 0 0 setrgbcolor\n");
        fprintf(archivo_gantt, "stroke\n");
        fprintf(archivo_gantt, "/Times-Roman findfont 12 scalefont setfont\n");
        fprintf(archivo_gantt, "%d %d moveto\n", margen_lateral - 50, y + altura_proceso / 2);
        fprintf(archivo_gantt, "(ID %d) show\n", pid);
    }

    /**
     * DIBUJA el eje X con los TIEMPOS REALES, se recorre el DIAGRAMA de GANTT y se imprime el TIEMPO de INICIO y FINAL del PROCESO en el eje X.
     * @code
     *  fprintf(archivo_gantt, "/Times-Roman findfont 12 scalefont setfont\n");
     *  for (int i = 0; i < num_procesos; i++)
     *  {
     *      int tiempo_inicio = diagrama_gantt[i].tiempo_inicio;
     *      int tiempo_final = diagrama_gantt[i].tiempo_final;
     *      int x_inicio = margen_lateral + tiempo_inicio * 10;
     *      fprintf(archivo_gantt, "newpath\n");
     *      fprintf(archivo_gantt, "%d %d moveto\n", x_inicio, margen_inferior - 5);
     *      fprintf(archivo_gantt, "%d %d lineto\n", x_inicio, margen_inferior + 5);
     *      fprintf(archivo_gantt, "stroke\n");
     *      fprintf(archivo_gantt, "%d %d moveto\n", x_inicio - 5, margen_inferior - 20);
     *      fprintf(archivo_gantt, "(%d) show\n", tiempo_inicio);
     *      int x_final = margen_lateral + tiempo_final * 10;
     *      fprintf(archivo_gantt, "newpath\n");
     *      fprintf(archivo_gantt, "%d %d moveto\n", x_final, margen_inferior - 5);
     *      fprintf(archivo_gantt, "%d %d lineto\n", x_final, margen_inferior + 5);
     *      fprintf(archivo_gantt, "stroke\n");
     *      fprintf(archivo_gantt, "%d %d moveto\n", x_final - 5, margen_inferior - 20);
     *      fprintf(archivo_gantt, "(%d) show\n", tiempo_final);
     *  }
     *  fprintf(archivo_gantt, "showpage\n");
     *  fclose(archivo_gantt);
     *  fprintf(stdout, "\nCARTA GANTT generada EXITOSAMENTE en el ARCHIVO %s\n\n", carta_gantt);
     * @endcode
     */
    fprintf(archivo_gantt, "/Times-Roman findfont 12 scalefont setfont\n");
    for (int i = 0; i < num_procesos; i++)
    {
        int tiempo_inicio = diagrama_gantt[i].tiempo_inicio;
        int tiempo_final = diagrama_gantt[i].tiempo_final;
        int x_inicio = margen_lateral + tiempo_inicio * 10;
        fprintf(archivo_gantt, "newpath\n");
        fprintf(archivo_gantt, "%d %d moveto\n", x_inicio, margen_inferior - 5);
        fprintf(archivo_gantt, "%d %d lineto\n", x_inicio, margen_inferior + 5);
        fprintf(archivo_gantt, "stroke\n");
        fprintf(archivo_gantt, "%d %d moveto\n", x_inicio - 5, margen_inferior - 20);
        fprintf(archivo_gantt, "(%d) show\n", tiempo_inicio);
        int x_final = margen_lateral + tiempo_final * 10;
        fprintf(archivo_gantt, "newpath\n");
        fprintf(archivo_gantt, "%d %d moveto\n", x_final, margen_inferior - 5);
        fprintf(archivo_gantt, "%d %d lineto\n", x_final, margen_inferior + 5);
        fprintf(archivo_gantt, "stroke\n");
        fprintf(archivo_gantt, "%d %d moveto\n", x_final - 5, margen_inferior - 20);
        fprintf(archivo_gantt, "(%d) show\n", tiempo_final);
    }
    fprintf(archivo_gantt, "showpage\n");
    fclose(archivo_gantt);
    fprintf(stdout, "\nCARTA GANTT generada EXITOSAMENTE en el ARCHIVO %s\n\n", carta_gantt);

    // CONVERTIR archivo EPS a PNG con GHOSTSCRIPT.

    /**
     * Se CONVIERTE el ARCHIVO EPS a PNG con GHOSTSCRIPT.
     * @code
     *  char comando[256];
     *  snprintf(comando, sizeof(comando), "gs -dSAFER -dBATCH -dNOPAUSE -dEPSCrop -sDEVICE=png16m -r300 -sOutputFile=%s.png %s", carta_gantt, carta_gantt);
     *  int resultado = system(comando);
     *  if (resultado != 0)
     *  {
     *      fprintf(stderr, "ERROR al convertir la CARTA GANTT a PNG, saliendo...\n");
     *      exit(EXIT_FAILURE);
     *  }
     *  fprintf(stdout, "\nCARTA GANTT convertida a PNG en el archivo %s.png\n\n", carta_gantt);
     * @endcode
     */
    char comando[256];
    snprintf(comando, sizeof(comando), "gs -dSAFER -dBATCH -dNOPAUSE -dEPSCrop -sDEVICE=png16m -r300 -sOutputFile=%s.png %s", carta_gantt, carta_gantt);
    int resultado = system(comando);
    if (resultado != 0)
    {
        fprintf(stderr, "ERROR al convertir la CARTA GANTT a PNG, saliendo...\n");
        exit(EXIT_FAILURE);
    }
    fprintf(stdout, "\nCARTA GANTT convertida a PNG en el archivo %s.png\n\n", carta_gantt);
}
