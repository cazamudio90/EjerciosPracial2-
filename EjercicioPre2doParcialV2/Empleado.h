#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED
#include "LinkedList.h"
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Empleado;
int empleado_getNextId();
int empleado_getById(LinkedList* pArrayListEmpleado, int* index);
int empleado_getIndexById(LinkedList* pArrayListEmpleado,int id, int* index);
int empleado_setId(Empleado* this,int id);
int empleado_getId(Empleado* this,int* id);
int empleado_setNombre(Empleado* this,char* nombre);
int empleado_getNombre(Empleado* this,char* nombre);
int empleado_setHorasTrabajadas(Empleado* this,int horasTrabajadas);
int empleado_getHorasTrabajadas(Empleado* this,int* horasTrabajadas);
int empleado_setSueldo(Empleado* this,int sueldo);
int empleado_getSueldo(Empleado* this,int* sueldo);
int empleado_setAll(Empleado* this, int id,char* nombre, int horasTrabajadas, int sueldo);
int empleado_showInfo(Empleado* this);
Empleado* empleado_new();
int empleado_delete(Empleado* this);
Empleado* empleado_newConParametros(char* idString,char* nombre,int lenNombre,
                                    char* horasTrabajadasString,char* sueldoString);
Empleado* empleado_newConParametrosSinSueldo(   char* idString,char* nombre,int lenNombre,
                                                char* horasTrabajadasString);
int empleado_add(LinkedList* pArrayListEmpleado);
int empleado_edit(LinkedList* pArrayListEmpleado);
int empleado_menuEdicion(Empleado* this);
int empleado_remove(LinkedList* pArrayListEmpleado);
int empleado_confirmEditOrRemove(Empleado* this);
int empleado_list(LinkedList* pArrayListEmpleado);
int empleado_sort(LinkedList* pArrayListEmpleado);
int empleado_criterioSortId(void* thisA, void* thisB);
int empleado_criterioSortNombre(void* thisA, void* thisB);
int empleado_criterioSortHorasTrabajadas(void* thisA, void* thisB);
int empleado_criterioSortSueldo(void* thisA, void* thisB);
int em_calcularSueldo(void* pElement);
int emp_print (LinkedList* this);
#endif // EMPLEADO_H_INCLUDED
