#include <stdio.h>
#include <stdlib.h>
#include "Empleado.h"
#include "LinkedList.h"
#include "Parser.h"
#include "string.h"

/**
    Realizar un programa que lee de un archivo los datos de empleados y los guarda en un arraylist de entidades
    empleado.
    Luego, debera calcular el campo "sueldo" de cada uno de los empleados leidos, segun la horas que trabajaron, con el
    siguiente criterio:
    Los valores de horas varian entre 80 y 240.
    - Las primeras 120 horas la hora vale $180
    - De 120 a 160 horas, la hora vale $240
    - De 160 a 240 horas, la hora vale $350

    Para hacer este calculo, se debera desarrollar la funcion "map" en al biblioteca ArrayList, La cual recibe la lista y una funcion.
    La funcion map ejecutara la funcion recibida como parametro por cada item de la lista, y le pasaran en cada llamada, uno de los items.
    De esta manera la funcion pasada como parametro podra realizar un calculo con el item recibido, en este caso, calcular el sueldo.

    Una vez cargados los campos sueldo en las entidades, se debera generar un archivo de salida "sueldos.csv" el cual sera igual que el
    original pero con una columna mas al final, en donde se indicara el sueldo calculado.
*/

int generarArchivoSueldos(char* fileName,LinkedList* listaEmpleados);

int main()
{
    LinkedList* listaEmpleados = ll_newLinkedList();


    if(!parser_parseEmpleados("data.csv",listaEmpleados))
    {
        printf("Calculando sueldos de empleados\n");

        ll_map(listaEmpleados,em_calcularSueldo);
        emp_print(listaEmpleados);

       if(!generarArchivoSueldos("sueldos.csv",listaEmpleados))
        {
            printf("Archivo generado correctamente\n");
        }
        else
            printf("Error generando archivo\n");
    }
    else
        printf("Error leyendo empleados\n");

    return 0;
}
int generarArchivoSueldos(char* fileName,LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    Empleado* pEmpleado;
    int i;
    int bufferId;
    char bufferNombre[128];
    int bufferHorasTrabajadas;
    int bufferSueldo;
    FILE* pFile = fopen(fileName,"w");
    if(pFile != NULL)
    {
        retorno = 0;
        fprintf(pFile,"id,nombre,horasTrabajadas,sueldo");
        for(i=0;i<ll_len(pArrayListEmployee);i++)
        {
            pEmpleado = ll_get(pArrayListEmployee,i);
            Empleado_getId(pEmpleado,&bufferId);
            Empleado_getNombre(pEmpleado,bufferNombre);
            Empleado_getHorasTrabajadas(pEmpleado,&bufferHorasTrabajadas);
            Empleado_getSueldo(pEmpleado,&bufferSueldo);
            if( bufferId >= 0 && strlen(bufferNombre) > 0 &&
                bufferHorasTrabajadas > 0 && bufferSueldo > 0)
            {
                fprintf(pFile,"\n%d,%s,%d,%d",  bufferId,bufferNombre,
                                                bufferHorasTrabajadas,
                                                bufferSueldo);
            }
        }
    }
    return retorno;
}
