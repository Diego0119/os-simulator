#include "header.h"

int main()
{
    BloqueMemoria memoria = inicializar_memoria();

    FILE *archivo = fopen("../entrada.txt", "r");
    if (archivo == NULL)
    {
        printf("No se pudo abrir el archivo.\n");
        exit(EXIT_FAILURE);
    }

    int tiempo_ejecucion;
    int memoria_solicitada;

    return EXIT_SUCCESS;
}
