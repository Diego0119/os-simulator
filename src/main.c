#include "header.h"

int main(int argc, char *argv[])
{
    BloqueMemoria *memoria;
    memoria = leer_entrada(argc, argv); // aca se asignara la memoria al sistema operativo
    FILE *archivo = fopen("entrada.txt", "r");
    int proceso_id, tiempo_llegada, memoria_solicitada, tamano_memoria, tamano_bloque;
    // asignar memoria
    int saltar_cabecera = 0; // bandera

    // se lee el encabezado
    fscanf(archivo, "%d %d", &tamano_memoria, &tamano_bloque); // se lee la cabecera pero no se hace nada

    while (fscanf(archivo, "%d %d %d", &proceso_id, &tiempo_llegada, &memoria_solicitada) != EOF)
    {

        printf("Valores del txt:\n");
        printf("Proceso_id: %d\n", proceso_id);
        printf("Tiempo de llegada: %d\n", tiempo_llegada);
        printf("Memoria solicitada: %d\n", memoria_solicitada);
        asignar_memoria_ff(memoria, proceso_id, tiempo_llegada, memoria_solicitada);
    }

    imprimir_memoria(memoria);

    // char algoritmo_memoria[10], algoritmo_planificacion[10];
    // Queue *cola_lista;

    // Llamada función lectura archivo.

    // Planificar y ejecutar procesos.

    // Llamada función output carta gantt (?).

    return EXIT_SUCCESS;
}
