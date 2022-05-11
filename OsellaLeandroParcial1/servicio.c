#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "servicio.h"

int listarServicios(eServicio servicios[], int tams)
{
    int todoOk = 0;
    if(servicios!=NULL && tams>0)
    {
        system("cls");
        printf("      ******Servicios******\n");
        printf(" Id     Descripcion           Precio\n");
        printf("------------------------------------\n");
        for(int i=0; i<tams; i++)
        {
            printf("%d      %-16s   %.2f\n", servicios[i].id, servicios[i].descripcion, servicios[i].precio);
        }
        todoOk = 1;
    }
    return todoOk;
}

int buscarServicio(eServicio servicios[], int tams, int id, int* pIndice)
{
    int todoOk = 0;
    if(servicios!=NULL && tams>0 && pIndice!=NULL)
    {
        *pIndice = -1;
        for(int i=0; i<tams; i++)
        {
            if(servicios[i].id == id)
            {
                *pIndice = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int cargarDescripcionServicio(eServicio servicios[], int tams, int id, char descripcion[])
{
    int todoOk = 0;
    int indice;

    buscarServicio(servicios, tams, id, &indice);

    if(descripcion!=NULL && indice!=-1)
    {
        strcpy(descripcion, servicios[indice].descripcion);
        todoOk = 1;
    }
    return todoOk;
}
