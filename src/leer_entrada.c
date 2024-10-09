#include "header.h"

BloqueMemoria *leer_entrada()
{
    FILE *archivo;
    int tamano_memoria, tamano_bloque;
    char algoritmo[3]; // aca se guardara first fit
    BloqueMemoria *memoria;

    archivo = fopen("../entrada.txt", "r");
    if (archivo == NULL)
    {
        fprintf(stdout, "Error al abrir el archivo\n");
        exit(EXIT_FAILURE);
    }

    // leer la cabecera del archivo
    fscanf(archivo, "%d %d %s", &tamano_memoria, &tamano_bloque, algoritmo);
    // aca se debe crear la particion de memoria del sistema operativo segun la cabecera del txt
    memoria = inicializar_memoria(tamano_memoria, tamano_bloque); // esta funcion creara la cantidad de bloques necesarias para el sistema operativo segun la entrada del txt

    int proceso_id,
        tiempo_llegada, memoria_solicitada;

    while (fscanf(archivo, "%d %d %d", &proceso_id, &tiempo_llegada, &memoria_solicitada) != EOF)
    {
        // aca los procesos se iran recorriendo y se deben ir asignando a la cola, hacer el encolamiento
        // en teoria aca se asignaria la memoria a cada proceso del txt
        asignar_memoria(memoria, proceso_id, tiempo_llegada, memoria_solicitada);
    }

    fclose(archivo);
}