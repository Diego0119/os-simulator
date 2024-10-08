#include "header.h"

int main()
{
    // printf("Entro al main\n");

    BloqueMemoria memoria = inicializar_memoria();

    FILE *archivo = fopen("../entrada.txt", "r");
    if (archivo == NULL)
    {
        printf("No se pudo abrir el archivo.\n");
        exit(EXIT_FAILURE);
    }

    int tiempo_ejecucion;
    int memoria_solicitada;

    while (fscanf(archivo, "%d %d", &tiempo_ejecucion, &memoria_solicitada) != EOF)
    {
        Proceso *proceso = crear_proceso(tiempo_ejecucion, memoria_solicitada);
        asignar_memoria(proceso, &memoria, Front);
    }

    return EXIT_SUCCESS;
}
