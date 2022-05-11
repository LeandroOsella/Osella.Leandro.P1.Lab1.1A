#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "tipo.h"

int listarTipos(eTipo tipos[], int tamt)
{
    int todoOk = 0;
    if(tipos!=NULL && tamt>0)
    {
        system("cls");
        printf("      ******Tipos******\n");
        printf(" Id     Descripcion\n");
        printf("-------------------\n");
        for(int i=0; i<tamt; i++)
        {
            printf("%d      %-16s\n", tipos[i].id, tipos[i].descripcion);
        }
        todoOk = 1;
    }
    return todoOk;
}

int buscarTipo(eTipo tipos[], int tamt, int id, int* pIndice)
{
    int todoOk = 0;
    if(tipos!=NULL && tamt>0 && pIndice!=NULL)
    {
        *pIndice = -1;
        for(int i=0; i<tamt; i++)
        {
            if(tipos[i].id == id)
            {
                *pIndice = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int cargarDescripcionTipo(eTipo tipos[], int tamt, int id, char descripcion[])
{
    int todoOk = 0;
    int indice;

    buscarTipo(tipos, tamt, id, &indice);

    if(descripcion!=NULL && indice!=-1)
    {
        strcpy(descripcion, tipos[indice].descripcion);
        todoOk = 1;
    }
    return todoOk;
}
