#ifndef COMPRA_H_INCLUDED
#define COMPRA_H_INCLUDED
#include "LinkedList.h"
typedef struct
{
  char nombreCliente[128];
  float precioUnitario;
  float iva;
  float montoTotal;
  int idProducto;
  int unidades;
}Compra;

Compra* Compra_new();
void Compra_delete();
Compra* Compra_newConParametros(char* nombreCliente,char* precioUnitario,char* iva,char* montoTotal,char* idProducto,char* unidades);

int Compra_setNombreCliente(Compra* this,char* nombreCliente);
int Compra_getNombreCliente(Compra* this,char* nombreCliente);

int Compra_setPrecioUnitario(Compra* this,float precioUnitario);
int Compra_getPrecioUnitario(Compra* this,float* precioUnitario);

int Compra_setIva(Compra* this,float iva);
int Compra_getIva(Compra* this,float* iva);

int Compra_setMontoTotal(Compra* this,float montoTotal);
int Compra_getMontoTotal(Compra* this,float* montoTotal);

int Compra_setIdProducto(Compra* this,int idProducto);
int Compra_getIdProducto(Compra* this,int* idProducto);

int Compra_setUnidades(Compra* this,int unidades);
int Compra_getUnidades(Compra* this,int* unidades);

int Compra_listaPorID(void* pElement, int idProducto);
int Compra_CalcularMontoTotal(void* pElement);

 int emp_print (LinkedList* this);
#endif // COMPRA_H_INCLUDED
