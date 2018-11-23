#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "ventas.h"
#include "utn.h"


int parser_parseVentas(char* fileName, LinkedList* listaVentas)
{
    int retorno = -1;
    char bufferId[1024];
    char bufferFecha[1024];
    char bufferCodigo[1024];
    char buferCantidad[1024];
    char BufferPrecio[1024];
    char bufferCuit[1024];
    int flagOnce = 1;
    Ventas* pVentas;
    FILE* pFile;
    pFile = fopen(fileName,"r");
    if(pFile!=NULL)
    {
        while(!feof(pFile))
        {
            if(flagOnce)
            {
                fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",
                        bufferId,
                        bufferFecha,
                        bufferCodigo,
                        buferCantidad,
                        BufferPrecio,
                        bufferCuit);
                flagOnce = 0;
            }
            fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",
                        bufferId,
                        bufferFecha,
                        bufferCodigo,
                        buferCantidad,
                        BufferPrecio,
                        bufferCuit);

            pVentas = ventas_newConParametros( bufferId, bufferFecha, bufferCodigo, buferCantidad, BufferPrecio, bufferCuit);
            /*printf("\nId %s - Fecha: %s -Codigo: %s - Cantidad: %s - Precio: %s - Cuit: %s \n"
             ,bufferId, bufferFecha, bufferCodigo, buferCantidad, BufferPrecio, bufferCuit );*/
            if(pVentas != NULL)
            {
                retorno = 0;
                //printf("%s,%s,%s\n",bufferId, bufferNombre,bufferHorasTrabajadas);
                ll_add(listaVentas, pVentas);
                /*  printf("\nId %s - Fecha: %s -Codigo: %s - Cantidad: %s - Precio: %s - Cuit: %s \n"
             ,bufferId, bufferFecha, bufferCodigo, buferCantidad, BufferPrecio, bufferCuit );*/
            }
        }
    }
    return retorno;
}

int generarArchivoSueldos(char* fileName,LinkedList* unidadesVendidas)
{
    int retorno = -1;
    int i;
    int cantidadVentas;
    int cantidad10000;
    int cantidad20000;
    int cantTVs;
    FILE* pFile = fopen(fileName,"w");
    if(pFile != NULL)
    {
        retorno = 0;
        fprintf(pFile,"CantidadUnidadesVendidas,ventasMayoresA10000,ventasMayoresA20000,CantidadTvsVendidas");
        for(i=0;i<ll_len(unidadesVendidas);i++)
        {
            cantidadVentas = ll_count(unidadesVendidas, Ventas_CalcularTotal);
            cantidad10000 = ll_count(unidadesVendidas, Ventas_CantidadMayor10000);
            cantidad20000 = ll_count(unidadesVendidas, Ventas_CantidadMayor20000);
            cantTVs = ll_count(unidadesVendidas, Ventas_tipoProduct);
            fprintf(pFile,"\n%d,%d,%d,%d",  cantidadVentas,
                                            cantidad10000,
                                            cantidad20000,
                                            cantTVs);
        }
    }
    return retorno;
}
