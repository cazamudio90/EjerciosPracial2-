#include <stdio_ext.h>
#include <stdlib.h>
#include "parse.h"
#include "ventas.h"
#include "LinkedList.h"

int main()
{
    LinkedList * listadoVentas = ll_newLinkedList();

    if(parser_parseVentas("data.csv", listadoVentas) == 0)
    {
        //printf("Archivo creado");
        ventas_print(listadoVentas);

    }
    generarArchivoSueldos("informes.txt",listadoVentas);
    return 0;
}
