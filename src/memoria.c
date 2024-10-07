#include "../incs/memoria.h"

// aca se le deberia asignar memoria al so
void inicializar_memoria()
{
    BloqueMemoria memoria[TAMANO_MEMORIA];
    for (int i = 0; i < TAMANO_MEMORIA; i++)
    {
        memoria[i].tamaño = 1;            // bloques de 1 kb
        memoria[i].estado = 1;            // 1 es bloque libre, 0 es ocupado
        memoria[i].proceso_asignado = -1; // nigun bloque tiene procesos asignados
    }
}

// se debe crear la funcion de asignar memoria

BloqueAsignado asignar_memoria(Proceso *proceso, Lista *lista_procesos, BloqueMemoria *memoria)
{
    // esta funcion debera ver la memoria total del sistema op, y recorrer hasta que encuentre el espacio libre
    // luego cuando lo encuentra, cambiar a 0 los valores de los espacios libres del array, y hacer la lista
    // doblemente enlazada para tener en linea los procesos y trabajar con la cola
    int count = 0;
    for (int i = 0; i < TAMANO_MEMORIA; i++)
    {
        while (memoria[i].estado == 1)
        {
            count++;
            if (count == proceso->memoria_solicitada)
                for (int j = 0; j < count; j++)
                    memoria[j].estado = 0; // se coloca que la memoria esta ocupada
            return;                        // se encontro el espacio de memoria contiguo disponible
        }
    }
    BloqueAsignado *nuevo_bloque = malloc(sizeof(BloqueAsignado));
    nuevo_bloque->siguiente = "";
    nuevo_bloque->atras = "";
    nuevo_bloque->proceso = *proceso; // se copiaran todos los campos de proceso al struct del bloque, pero no se hara referencia a el, solo se copiaran los datos
    return *nuevo_bloque;
}