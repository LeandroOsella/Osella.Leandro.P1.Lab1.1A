#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "trabajo.h"

int inicializarTrabajos(eTrabajo trabajos[], int tamtra)
{
    int todoOk = 0;

    if(trabajos!=NULL && tamtra>0)
    {
        for(int i=0; i<tamtra; i++)
        {
            trabajos[i].isEmpty = 1;
        }
        todoOk = 1;
    }
    return todoOk;
}

int buscarLibreTrabajo(eTrabajo trabajos[], int tamtra, int* pIndex)
{
    int todoOk = 0;

    if(trabajos!=NULL && tamtra>0 && pIndex!=NULL)
    {
        *pIndex = -1;
        for(int i=0; i<tamtra; i++)
        {
            if(trabajos[i].isEmpty == 1)
            {
                *pIndex = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int altaTrabajo(eTrabajo trabajos[], int tamtra, eMascota mascotas[], int tamm, eServicio servicios[], int tams, eColor colores[], int tamc, eTipo tipos[], int tamt, int* pProximoIdTrabajo)
{
    int todoOk = 0;
    int indice;
    eTrabajo auxTrabajo;
    eFecha auxFecha;

    if(trabajos!=NULL && tamtra>0 && mascotas!=NULL && tamm>0 && servicios!=NULL && tams>0 && colores!=NULL && tamc>0 && tipos!=NULL && tamt>0 && pProximoIdTrabajo!=NULL)
    {
        if(buscarLibreTrabajo(trabajos,tamtra, &indice))
        {
            if(indice == -1)
            {
                printf("No hay lugar en el sistema!!\n");
            }
            else
            {
                listarMascotas(mascotas,tamm,colores,tamc,tipos,tamt);
                utn_getInt("Ingrese Id de la mascota: ", "Error. Ingrese id valido.",10000,20000,100,&auxTrabajo.idMascota);

                if(buscarMascota(mascotas, tamm, auxTrabajo.idMascota, &indice))
                {
                    if(indice == -1)
                    {
                        printf("No hay una mascota con id %d\n", auxTrabajo.idMascota);
                    }
                    else
                    {
                        listarServicios(servicios, tams);

                        utn_getInt("Ingrese Id del Servicio que desea: ", "Error. Id invalido.", 20000,20003,100, &auxTrabajo.idServicio);

                        if(buscarServicio(servicios,tams,auxTrabajo.idServicio, &indice))
                        {
                            if(indice==-1)
                            {
                                printf("No hay un servicio con id %d\n", auxTrabajo.idServicio);
                            }
                            else
                            {
                                printf("Ingrese fecha (dd/mm/aaaa): ");
                                scanf("%d/%d/%d", &auxFecha.dia, &auxFecha.mes, &auxFecha.anio);
                                while((auxFecha.dia<1 || auxFecha.dia>31) && (auxFecha.mes<1 || auxFecha.mes>12) && (auxFecha.anio<2000 || auxFecha.anio>2022))
                                {
                                    printf("Error. Reingrese fecha (dd/mm/aaaa): ");
                                    scanf("%d/%d/%d", &auxFecha.dia, &auxFecha.mes, &auxFecha.anio);
                                }
                            }
                        }
                    }
                }
            }
        }
        auxTrabajo.isEmpty = 0;

        auxTrabajo.id= *pProximoIdTrabajo;
        (*pProximoIdTrabajo)++;

        auxTrabajo.fecha = auxFecha;

        trabajos[indice] = auxTrabajo;
        todoOk = 1;
    }

    return todoOk;
}


int mostrarTrabajo(eTrabajo trabajo, int tamtra, eServicio servicios[], int tams, eMascota mascotas[], int tamm)
{
    int todoOk = 0;
    char descripcionServicio[20];
    char nombreMascota[20];

    if(tamtra>0 && servicios !=NULL && tams>0 && mascotas!=NULL && tamm>0)
    {
        cargarDescripcionServicio(servicios, tams,trabajo.idServicio,descripcionServicio);
        cargarDescripcionMascota(mascotas,tamm,trabajo.idMascota,nombreMascota);

        printf("%d   %-16s   %-16s      %02d/%02d/%02d\n", trabajo.id, nombreMascota, descripcionServicio, trabajo.fecha.dia, trabajo.fecha.mes, trabajo.fecha.anio);

        todoOk = 1;
    }
    return todoOk;
}

int listarTrabajos(eTrabajo trabajos[], int tamtra, eMascota mascotas[], int tamm, eServicio servicios[], int tams)
{
    int todoOk = 0;
    int flag = 0;
    if(trabajos!=NULL && tamtra>0 && servicios !=NULL && tams>0 && mascotas!=NULL && tamm>0)
    {
        printf("      ******Listado de Trabajos******      \n\n");
        printf("Id       Mascota           Servicio             Fecha\n");
        for(int i=0; i<tamtra; i++)
        {
            if(trabajos[i].isEmpty == 0)
            {
                mostrarTrabajo(trabajos[i], tamtra,servicios,tams,mascotas,tamm);
                flag++;
            }
        }
        if(flag == 0)
        {
            printf("No hay servicios en el sistema!!\n");
        }
    }
    return todoOk;
}
