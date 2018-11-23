#ifndef VENTAS_H_INCLUDED
#define VENTAS_H_INCLUDED
#include "LinkedList.h"
typedef struct
{
    int idVentas;
    char fecha_venta[1024];
    char codigoProducto[1024];
    int cantidad;
    float precioUnitario;
    char cuit[1024];
}Ventas;






Ventas* ventas_new();
void ventas_delete();
Ventas* ventas_newConParametros(char* idVentas,char* fecha_venta,char* codigoProducto,char* cantidad,char* precioUnitario,char* cuit);

int ventas_setIdVentas(Ventas* this,int idVentas);
int ventas_getIdVentas(Ventas* this,int* idVentas);

int ventas_setFecha_venta(Ventas* this,char* fecha_venta);
int ventas_getFecha_venta(Ventas* this,char* fecha_venta);

int ventas_setCodigoProducto(Ventas* this,char* codigoProducto);
int ventas_getCodigoProducto(Ventas* this,char* codigoProducto);

int ventas_setCantidad(Ventas* this,int cantidad);
int ventas_getCantidad(Ventas* this,int* cantidad);

int ventas_setPrecioUnitario(Ventas* this,float precioUnitario);
int ventas_getPrecioUnitario(Ventas* this,float* precioUnitario);

int ventas_setCuit(Ventas* this,char* cuit);
int ventas_getCuit(Ventas* this,char* cuit);

int ventas_print(LinkedList* this);
 int Ventas_CalcularTotal (void* pElement );
 int Ventas_CantidadMayor10000 (void* pElement );
 int Ventas_CantidadMayor20000 (void* pElement );
  int Ventas_tipoProduct(void* pElement );

#endif // VENTAS_H_INCLUDED
