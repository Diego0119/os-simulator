#include "../incs/header.h"

void leer_entrada()
{
    FILE *archivo;
    int tamano_memoria, tamano_bloque;
    char algoritmo[3]; // aca se guardara first fit

    archivo = fopen("../entrada.txt", "r");
    if (archivo == NULL)
    {
        printf("Error al abrir el archivo\n");
        exit(EXIT_FAILURE);
    }

    // leer la cabecera del archivo
    fscanf(archivo, "%d %d %s", &tamano_memoria, &tamano_bloque, algoritmo);

    int proceso_id, num_bloques, memoria_solicitada;

    while (fscanf(archivo, "%d %d %d", &proceso_id, &num_bloques, &memoria_solicitada) != EOF)
    {
        // aca los procesos se iran recorriendo y se deben ir asignando
    }

    fclose(archivo);
}