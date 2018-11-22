#include "LinkedList.h"
#include "string.h"
#include "Empleado.h"
#include <stdio.h>
int parser_parseEmpleados(char* fileName, LinkedList* listaEmpleados)
{
    char bufferLine[1024];
    char* delimitador = ",";
    char* token;
    char bufferId[1024];
    char bufferNombre[1024];
    char bufferHorasTrabajadas[1024];
    int retorno = -1;
    int flagOnce = 1;
    Empleado* pEmpleado;
    FILE* pFile;
    pFile = fopen(fileName,"r");
    if(pFile!=NULL)
    {
        while(!feof(pFile))
        {
            if(flagOnce)
            {
                fscanf(pFile,"%[^\n]\n",bufferLine);
                flagOnce = 0;
            }
            fscanf(pFile,"%[^\n]\n",bufferLine);
            token = strtok(bufferLine, delimitador);
            strncpy(bufferId, token, 1024);
            token = strtok(NULL, delimitador);
            strncpy(bufferNombre, token, 1024);
            token = strtok(NULL, "\n");
            strncpy(bufferHorasTrabajadas, token, 1024);
            pEmpleado = Empleado_newConParametrosSinSueldo( bufferId,
                                                            bufferNombre,
                                                            bufferHorasTrabajadas);
            if(pEmpleado != NULL)
            {
                retorno = 0;
                //printf("%s,%s,%s\n",bufferId, bufferNombre,bufferHorasTrabajadas);
                ll_add(listaEmpleados, pEmpleado);
                    //printf("%s,%s,%s\n",bufferId, bufferNombre,bufferHorasTrabajadas);
            }
        }
    }
    return retorno;
}

