#include "./incs/header.h"
#define TAMANO_MEMORIA 1024

int main()
{
    // printf("Entro al main\n");

    BloqueMemoria memoria = inicializar_memoria();

    FILE *archivo = fopen("../entrada.txt", "r");
    if (archivo == NULL)
    {
        printf("No se pudo abrir el archivo.\n");
        return 1;
    }

    char nombre_proceso[20];
    int tiempo_ejecucion;
    int memoria_solicitada;

    while (fscanf(archivo, "%s %d %d", nombre_proceso, &tiempo_ejecucion, &memoria_solicitada) != EOF)
    {

        Proceso *proceso = crear_proceso(nombre_proceso, tiempo_ejecucion, memoria_solicitada);
    }

    return 0;
}
