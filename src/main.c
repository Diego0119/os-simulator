#include "header.h"

int main(int argc, char *argv[])
{
    if (argc != 3 || strcmp(argv[1], "--file") != 0)
    {
        fprintf(stderr, "Error de utilización. Uso: %s --file <archivo>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    leer_entrada();

    // char algoritmo_memoria[10], algoritmo_planificacion[10];
    // Queue *cola_lista;

    // Llamada función lectura archivo.

    // Planificar y ejecutar procesos.

    // Llamada función output carta gantt (?).

    return EXIT_SUCCESS;
}
