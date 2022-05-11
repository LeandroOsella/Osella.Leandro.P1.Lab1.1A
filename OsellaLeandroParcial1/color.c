#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "color.h"

int listarColores(eColor colores[], int tamc)
{
    int todoOk = 0;
    if(colores!=NULL && tamc>0)
    {
        system("cls");
        printf("      ******Colores******\n");
        printf(" Id     Descripcion\n");
        printf("-------------------\n");
        for(int i=0; i<tamc; i++)
        {
            printf("%d      %-16s\n", colores[i].id, colores[i].nombreColor);
        }
        todoOk = 1;
    }
    return todoOk;
}

int buscarColor(eColor colores[], int tamc, int id, int* pIndice)
{
    int todoOk = 0;
    if(colores!=NULL && tamc>0 && pIndice!=NULL)
    {
        *pIndice = -1;
        for(int i=0; i<tamc; i++)
        {
            if(colores[i].id == id)
            {
                *pIndice = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int cargarDescripcionColor(eColor colores[], int tamc, int id, char descripcion[])
{
    int todoOk = 0;
    int indice;

    buscarColor(colores, tamc, id, &indice);

    if(descripcion!=NULL && indice!=-1)
    {
        strcpy(descripcion, colores[indice].nombreColor);
        todoOk = 1;
    }
    return todoOk;
}
