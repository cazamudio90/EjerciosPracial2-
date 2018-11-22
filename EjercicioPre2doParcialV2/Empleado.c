#include "Empleado.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "utn.h"

Empleado* Empleado_new()
{
    Empleado* this;
    this=malloc(sizeof(Empleado));
    return this;
}

void Empleado_delete(Empleado* this)
{
    free(this);
}

Empleado* Empleado_newConParametros(int id,char* nombre,int horasTrabajadas,int sueldo)
{
    Empleado* this;
    this=Empleado_new();

    if(
    !Empleado_setId(this,id)&&
    !Empleado_setNombre(this,nombre)&&
    !Empleado_setHorasTrabajadas(this,horasTrabajadas)&&
    !Empleado_setSueldo(this,sueldo))
        return this;

    Empleado_delete(this);
    return NULL;
}

Empleado* Empleado_newConParametrosSinSueldo(char* id,char* nombre,char* horasTrabajadas)
{
    Empleado* this;
    this=Empleado_new();

    if(
    !Empleado_setId(this, atoi(id))&&
    !Empleado_setNombre(this,nombre)&&
    !Empleado_setHorasTrabajadas(this, atoi(horasTrabajadas)))
        return this;

    Empleado_delete(this);
    return NULL;
}


int Empleado_setId(Empleado* this,int id)
{
    int retorno=-1;
    static int proximoId=-1;

    if(this!=NULL && id==-1)
    {
        proximoId++;
        this->id=proximoId;
        retorno=0;
    }
    else if(id>proximoId)
    {
        proximoId=id;
        this->id=proximoId;
        retorno=0;
    }
    return retorno;
}

int Empleado_getId(Empleado* this,int* id)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *id=this->id;
        retorno=0;
    }
    return retorno;
}

int Empleado_setNombre(Empleado* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(this->nombre,nombre);
        retorno=0;
    }
    return retorno;
}

int Empleado_getNombre(Empleado* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
        retorno=0;
    }
    return retorno;
}

int Empleado_setHorasTrabajadas(Empleado* this,int horasTrabajadas)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->horasTrabajadas=horasTrabajadas;
        retorno=0;
    }
    return retorno;
}

int Empleado_getHorasTrabajadas(Empleado* this,int* horasTrabajadas)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *horasTrabajadas=this->horasTrabajadas;
        retorno=0;
    }
    return retorno;
}

int Empleado_setSueldo(Empleado* this,int sueldo)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->sueldo=sueldo;
        retorno=0;
    }
    return retorno;
}

int Empleado_getSueldo(Empleado* this,int* sueldo)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *sueldo=this->sueldo;
        retorno=0;
    }
    return retorno;
}

int em_calcularSueldo(void* pElement)
{
    int retorno = -1;
    int bufferSueldo;
    Empleado * pEmpleado = pElement;
    int horas = pEmpleado->horasTrabajadas;
    int auxHoras;

    if (pEmpleado != NULL)
    {
        if(horas <= 120)
        {
            bufferSueldo = horas * 180;
        }else if (horas > 120 && horas <= 160)
        {
            auxHoras = horas - 120;
            bufferSueldo = (120 * 180) + (auxHoras * 240);
        }else if (horas > 160 && horas <= 240 )
        {
            auxHoras = (120 * 180);
            bufferSueldo = auxHoras + (40 * 240)+ ( (horas - 160) * 350);
        }
        retorno =  1;
        pEmpleado->sueldo = bufferSueldo;
    }
    return retorno;
}
 int emp_print (LinkedList* this)
 {
   int retorno = -1;
    int i;
    Empleado* auxPunteroEmpleado;
    char nombre[1024];
    int id;
    int bufferHorasTrabajo;
    int bufferSueldo;
    if(this != NULL)
    {
        for (i = 0; i< ll_len(this); i++)
        {
             auxPunteroEmpleado = ll_get(this,i);
             Empleado_getNombre(auxPunteroEmpleado,nombre);
             Empleado_getId(auxPunteroEmpleado, &id);
             Empleado_getHorasTrabajadas(auxPunteroEmpleado, &bufferHorasTrabajo);
             Empleado_getSueldo(auxPunteroEmpleado, &bufferSueldo);
             printf("\nId %d - Nombre: %s - Horas: %d - Sueldo: %d \n",id, nombre, bufferHorasTrabajo, bufferSueldo);
             retorno = 0;
        }
    }

    return retorno;
 }
