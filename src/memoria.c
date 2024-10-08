#include "header.h"

// aca se le deberia asignar memoria al so
BloqueMemoria inicializar_memoria(void)
{
    BloqueMemoria memoria[TAMANO_MEMORIA];
    for (int i = 0; i < TAMANO_MEMORIA; i++)
    {
        memoria[i].tamaño = 1;            // bloques de 1 kb
        memoria[i].estado = 1;            // 1 es bloque libre, 0 es ocupado
        memoria[i].proceso_asignado = -1; // nigun bloque tiene procesos asignados
    }
    return *memoria;
}

Nodo *asignar_memoria(Proceso *proceso, BloqueMemoria *memoria, Nodo *Front)
{
    int count = 0;
    int start = -1;

    // aqui hay que implementar first fit
    for (int i = 0; i < TAMANO_MEMORIA; i++)
    {

        if (memoria[i].estado == 1) // bloque libre
        {
            count++;
            if (start == -1)
                start = i; // inicio de bloques contiguos

            if (count == proceso->memoria_solicitada)
            {
                for (int j = start; j < start + count; j++)
                {
                    memoria[j].estado = 0; // estado ocupado
                    // memoria[j].proceso_asignado = proceso->nombre;
                }

                insertar(*proceso, Front);
                return NULL;
            }
        }
        else
        {
            count = 0;
            start = -1;
        }
    }

    printf("No hay suficiente memoria disponible para el proceso.\n");
    return NULL;
}

int esta_vacia(Nodo *Front)
{
    return Front->next == NULL;
    // esto retornara un 1 o 0 dependiendo si esta o no vacia
}

void insertar(Proceso proceso, Nodo *Front)
{
    Nodo *nuevo_nodo = malloc(sizeof(Nodo));
    if (nuevo_nodo == NULL)
    {
        printf("Error de asignación de memoria\n");
        return;
    }
    nuevo_nodo->proceso = proceso;
    nuevo_nodo->next = NULL;

    if (esta_vacia(Front))
    {
        Front = nuevo_nodo;
        Rear = nuevo_nodo;
    }
    else
    {
        Rear->next = nuevo_nodo;
        Rear = nuevo_nodo;
    }
}

Proceso extraer(Nodo *Front, Nodo *Rear)
{
    if (!esta_vacia(Front))
    {
        Proceso proceso_extraido = Front->proceso;
        Nodo *temp_nodo = Front;
        if (Front == Rear)
        {
            Front = NULL;
            Rear = NULL;
        }
        else
        {
            Front = Front->next;
        }
        free(temp_nodo);
        return proceso_extraido;
    }
    else
    {
        printf("La cola de procesos esta vacia\n");
    }
}
