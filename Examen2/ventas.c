#include "ventas.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
Ventas* ventas_new()
{
    Ventas* this;
    this=malloc(sizeof(Ventas));
    return this;
}

void ventas_delete(Ventas* this)
{
    free(this);
}

Ventas* ventas_newConParametros(char* idVentas,char* fecha_venta,char* codigoProducto,char* cantidad,char* precioUnitario,char* cuit)
{
    Ventas* this;
    this=ventas_new();

    if(
    !ventas_setIdVentas(this,atoi(idVentas))&&
    !ventas_setFecha_venta(this,fecha_venta)&&
    !ventas_setCodigoProducto(this,codigoProducto)&&
    !ventas_setCantidad(this,atoi(cantidad))&&
    !ventas_setPrecioUnitario(this, atof(precioUnitario))&&
    !ventas_setCuit(this,cuit))
        return this;

    ventas_delete(this);
    return NULL;
}

int ventas_setIdVentas(Ventas* this,int idVentas)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->idVentas=idVentas;
        retorno=0;
    }
    return retorno;
}

int ventas_getIdVentas(Ventas* this,int* idVentas)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *idVentas=this->idVentas;
        retorno=0;
    }
    return retorno;
}

int ventas_setFecha_venta(Ventas* this,char* fecha_venta)
{
    int retorno=-1;
    if(this!=NULL && fecha_venta!=NULL)
    {
        strcpy(this->fecha_venta,fecha_venta);
        retorno=0;
    }
    return retorno;
}

int ventas_getFecha_venta(Ventas* this,char* fecha_venta)
{
    int retorno=-1;
    if(this!=NULL && fecha_venta!=NULL)
    {
        strcpy(fecha_venta,this->fecha_venta);
        retorno=0;
    }
    return retorno;
}

int ventas_setCodigoProducto(Ventas* this,char* codigoProducto)
{
    int retorno=-1;
    if(this!=NULL)
    {
        strcpy(this->codigoProducto,codigoProducto);
        retorno=0;
    }
    return retorno;
}

int ventas_getCodigoProducto(Ventas* this,char* codigoProducto)
{
    int retorno=-1;
    if(this!=NULL)
    {
        strcpy(codigoProducto,this->codigoProducto);
        retorno=0;
    }
    return retorno;
}

int ventas_setCantidad(Ventas* this,int cantidad)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->cantidad=cantidad;
        retorno=0;
    }
    return retorno;
}

int ventas_getCantidad(Ventas* this,int* cantidad)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *cantidad=this->cantidad;
        retorno=0;
    }
    return retorno;
}

int ventas_setPrecioUnitario(Ventas* this,float precioUnitario)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->precioUnitario=precioUnitario;
        retorno=0;
    }
    return retorno;
}

int ventas_getPrecioUnitario(Ventas* this,float* precioUnitario)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *precioUnitario=this->precioUnitario;
        retorno=0;
    }
    return retorno;
}

int ventas_setCuit(Ventas* this,char* cuit)
{
    int retorno=-1;
    if(this!=NULL && cuit!=NULL)
    {
        strcpy(this->cuit,cuit);
        retorno=0;
    }
    return retorno;
}

int ventas_getCuit(Ventas* this,char* cuit)
{
    int retorno=-1;
    if(this!=NULL && cuit!=NULL)
    {
        strcpy(cuit,this->cuit);
        retorno=0;
    }
    return retorno;
}

int ventas_print(LinkedList* this)
 {
   int retorno = -1;
   Ventas * pVentas = NULL;
   int bufferId;
   char bufferFecha[1024];
   int bufferCodigo[1024];
   int buferCantidad;
   float BufferPrecio;
   char bufferCuit[1024];
   int i;
    if(this != NULL)
    {
        for (i = 0; i< ll_len(this); i++)
        {
             pVentas = ll_get(this,i);
             ventas_getIdVentas(pVentas, &bufferId);
             ventas_getFecha_venta(pVentas, bufferFecha);
             ventas_getCodigoProducto(pVentas, bufferCodigo);
             ventas_getCantidad(pVentas, &buferCantidad);
             ventas_getPrecioUnitario(pVentas, &BufferPrecio);
             ventas_getCuit(pVentas, bufferCuit);
             printf("\nId %d - Fecha: %s -Codigo: %s - Cantidad: %d - Precio: %f - Cuit: %s \n"
             ,bufferId, bufferFecha, bufferCodigo, buferCantidad, BufferPrecio, bufferCuit );
             retorno = 0;
        }
    }

    return retorno;
 }

 int Ventas_CalcularTotal (void* pElement )
 {
    int retorno = 0;
    Ventas* pVentas = pElement;

    if (pElement != NULL)
    {
        retorno = pVentas->cantidad;
        //printf("%d\n", retorno);

    }
    return retorno;
 }

 int Ventas_CantidadMayor10000 (void* pElement )
 {
    int retorno = 0;
    Ventas* pVentas = pElement;

    if (pElement != NULL)
    {
        if(pVentas->precioUnitario >= 10000 && pVentas->precioUnitario <= 20000)
        {
            retorno = 1;
        }
    }
    return retorno;
 }
  int Ventas_CantidadMayor20000 (void* pElement )
 {
    int retorno = 0;
    Ventas* pVentas = pElement;

    if (pElement != NULL)
    {
        if(pVentas->precioUnitario >= 20000)
        {
            retorno =1;
        }
    }
    return retorno;
 }
  int Ventas_tipoProduct(void* pElement )
 {
    int retorno = 0;
    Ventas* pVentas = pElement;
    if (pElement != NULL)
    {
        if( strncmp(pVentas->codigoProducto, "LCD_TV", 1024)== 0 )
        {
            retorno = 1;
        }
    }
    return retorno;
 }
