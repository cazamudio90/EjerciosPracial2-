#include "Compra.h"
#include "utn.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Compra* Compra_new()
{
    Compra* this;
    this=malloc(sizeof(Compra));
    return this;
}
void Compra_delete(Compra* this)
{
    free(this);
}
Compra* Compra_newConParametros(char* nombreCliente,char* precioUnitario,char* iva,char* montoTotal,char* idProducto,char* unidades)
{
    Compra* this;
    this=Compra_new();

    if(
    !Compra_setNombreCliente(this,nombreCliente)&&
    !Compra_setPrecioUnitario(this, atof(precioUnitario))&&
    !Compra_setIva(this,atof(iva))&&
    !Compra_setMontoTotal(this,atof(montoTotal))&&
    !Compra_setIdProducto(this,atoi(idProducto))&&
    !Compra_setUnidades(this,atoi(unidades)))
    return this;

    Compra_delete(this);
    return NULL;
}
int Compra_setNombreCliente(Compra* this,char* nombreCliente)
{
    int retorno=-1;
    if(this!=NULL)
    {
        strcpy(this->nombreCliente,nombreCliente);
        retorno=0;
    }
    return retorno;
}
int Compra_getNombreCliente(Compra* this,char* nombreCliente)
{
    int retorno=-1;
    if(this!=NULL && nombreCliente!=NULL)
    {
        strcpy(nombreCliente,this->nombreCliente);
        retorno=0;
    }
    return retorno;
}
int Compra_setPrecioUnitario(Compra* this,float precioUnitario)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->precioUnitario=precioUnitario;
        retorno=0;
    }
    return retorno;
}
int Compra_getPrecioUnitario(Compra* this,float* precioUnitario)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *precioUnitario=this->precioUnitario;
        retorno=0;
    }
    return retorno;
}
int Compra_setIva(Compra* this,float iva)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->iva=iva;
        retorno=0;
    }
    return retorno;
}

int Compra_getIva(Compra* this,float* iva)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *iva=this->iva;
        retorno=0;
    }
    return retorno;
}

int Compra_setMontoTotal(Compra* this,float montoTotal)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->montoTotal=montoTotal;
        retorno=0;
    }
    return retorno;
}

int Compra_getMontoTotal(Compra* this,float* montoTotal)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *montoTotal=this->montoTotal;
        retorno=0;
    }
    return retorno;
}

int Compra_setIdProducto(Compra* this,int idProducto)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->idProducto=idProducto;
        retorno=0;
    }
    return retorno;
}

int Compra_getIdProducto(Compra* this,int* idProducto)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *idProducto=this->idProducto;
        retorno=0;
    }
    return retorno;
}

int Compra_setUnidades(Compra* this,int unidades)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->unidades=unidades;
        retorno=0;
    }
    return retorno;
}

int Compra_getUnidades(Compra* this,int* unidades)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *unidades=this->unidades;
        retorno=0;
    }
    return retorno;
}

 int emp_print (LinkedList* this)
 {
   int retorno = -1;
    int i;
    Compra* auxPunteroCompra;
    char nombre[1024];
    int id;
    float precio;
    float iva;
    int unidades;
    float montoTotal;
    if(this != NULL)
    {
        for (i = 0; i< ll_len(this); i++)
        {
             auxPunteroCompra = ll_get(this,i);
             Compra_getIdProducto(auxPunteroCompra, &id);
             Compra_getNombreCliente(auxPunteroCompra,nombre);
             Compra_getIva(auxPunteroCompra, &iva);
             Compra_getPrecioUnitario(auxPunteroCompra, &precio);
             Compra_getUnidades(auxPunteroCompra, &unidades);
             Compra_getMontoTotal(auxPunteroCompra, &montoTotal);
             printf("\nId %d - Nombre: %s - Precio: %f - Iva: %f - Unidades: %d - Total: %f\n",id, nombre, precio, iva, unidades, montoTotal);
             retorno = 0;
        }
    }

    return retorno;
 }

int Compra_listaPorID(void* pElement, int idProducto)
{
    int retorno = -1;
    Compra* pCompra = pElement;
    if (pElement != NULL && idProducto >= 0)
    {

        if(pCompra->idProducto == idProducto)
        {
            retorno = 1;
        }else
        {
            retorno = 0;
        }
    }
    return retorno;
}

int Compra_CalcularMontoTotal(void* pElement)
{
    int retorno = -1;
    Compra * pCompra = pElement;
    float bufferPrecioXUnidades;
    if(pElement != NULL)
    {
        bufferPrecioXUnidades = (pCompra->precioUnitario * pCompra->unidades);
        pCompra->montoTotal = bufferPrecioXUnidades - (bufferPrecioXUnidades * (pCompra->iva / 100));
        retorno = 1;
        printf("hola");
    }
    return retorno;
}
