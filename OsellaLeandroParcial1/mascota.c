#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "mascota.h"
#include "validacion.h"
#include "tipo.h"
#include "color.h"

int inicializarMascotas(eMascota mascotas[], int tamm)
{
    int todoOk = 0;

    if(mascotas!=NULL && tamm>0)
    {
        for(int i=0; i<tamm; i++)
        {
            mascotas[i].isEmpty = 1;
        }
        todoOk = 1;
    }
    return todoOk;
}

int buscarLibre(eMascota mascotas[], int tamm, int* pIndex)
{
    int todoOk = 0;

    if(mascotas!=NULL && tamm>0 && pIndex!=NULL)
    {
        *pIndex = -1;
        for(int i=0; i<tamm; i++)
        {
            if(mascotas[i].isEmpty == 1)
            {
                *pIndex = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}



int altaMascota(eMascota mascotas[], int tamm, int* pProximoIdMascota, eTipo tipos[], int tamt, eColor colores[], int tamc)
{
    int todoOk = 0;
    int indice;
    eMascota auxMascota;

    if(mascotas!=NULL && tamm>0 && pProximoIdMascota!=NULL && tipos!=NULL && tamt>0 && colores!=NULL && tamc>0)
    {
        if(buscarLibre(mascotas, tamm, &indice))
        {
            if(indice == -1)
            {
                printf("No hay lugar en el sistema!!\n\n");
            }
            else
            {
                utn_getString("Ingrese nombre: ", "Error!! Ingrese nombre valido. ", 20, 100, auxMascota.nombre);

                listarTipos(tipos, tamt);
                utn_getInt("Ingrese Id tipo: ", "Error. Ingrese id valido. ", 1000, 1004, 100, &auxMascota.idTipo);

                listarColores(colores, tamc);
                utn_getInt("Ingrese Id Color: ", "Error. Ingrese Id valido. ", 5000, 5004, 100, &auxMascota.idColor);

                utn_getInt("Ingrese edad: ", "Error. Ingrese edad valida.", 1, 80, 100, &auxMascota.edad);

                printf("Ingrese estado de vacunacion (s/n): ");
                fflush(stdin);
                scanf("%c", &auxMascota.vacunado);
                auxMascota.vacunado = tolower(auxMascota.vacunado);
                while(auxMascota.vacunado != 's' && auxMascota.vacunado!= 'n')
                {
                    printf("Error. Reingrese estado de vacunacion (s/n): ");
                    fflush(stdin);
                    scanf("%c", &auxMascota.vacunado);
                    auxMascota.vacunado = tolower(auxMascota.vacunado);
                }

                auxMascota.isEmpty = 0;

                auxMascota.id = *pProximoIdMascota;
                (*pProximoIdMascota)++;

                mascotas[indice] = auxMascota;

                todoOk = 1;
            }
        }
        else
        {
            printf("Ocurrio un problema con los parametros!!\n\n");
        }
    }
    return todoOk;
}

int menuModificarMascota()
{
    int opcion;

    printf("      ******Campos a Modificar******      \n");
    printf("-------------------------------------\n\n");
    printf("1- Tipo\n");
    printf("2- Vacunado\n");
    printf("3- Salir\n");
    utn_getInt("Ingrese opcion: ", "Error. Ingrese opcion valida. ",1,3,100,&opcion);

    return opcion;
}

int mostrarMascota(eMascota mascota, int tamm, eColor colores[], int tamc, eTipo tipos[], int tamt)
{
    int todoOk = 0;
    char descripcionColor[20];
    char descripcionTipo[20];

    if(tamm>0 && colores!=NULL && tamc>0 && tipos!=NULL && tamt>0)
    {
        cargarDescripcionColor(colores, tamc,mascota.idColor,descripcionColor);
        cargarDescripcionTipo(tipos, tamt, mascota.idTipo, descripcionTipo);

        printf("%d   %-16s   %-10s   %-10s   %d         %c\n", mascota.id, mascota.nombre, descripcionTipo, descripcionColor, mascota.edad, mascota.vacunado);

        todoOk = 1;
    }
    return todoOk;
}

int listarMascotas(eMascota mascotas[], int tamm, eColor colores[], int tamc, eTipo tipos[], int tamt)
{
    int todoOk = 0;
    int flag = 0;
    if(mascotas != NULL && tamm>0 && colores!=NULL && tamc>0 && tipos!=NULL && tamt>0)
    {
        printf("      ******Listado de Mascotas******      \n\n");
        printf("Id       Nombre             Tipo        Color        Edad      Vacunado\n");
        for(int i=0; i<tamm; i++)
        {
            if(mascotas[i].isEmpty == 0)
            {
                mostrarMascota(mascotas[i], tamm, colores, tamc, tipos, tamt);
                flag++;
            }
        }
        if(flag == 0)
        {
            printf("No hay mascotas en el sistema!!\n");
        }
    }
    return todoOk;
}

int buscarMascota(eMascota mascotas[], int tamm, int id, int* pIndex)
{
    int todoOk = 0;

    if(mascotas!=NULL && tamm>0 && pIndex!=NULL && id > 0)
    {
        *pIndex = -1;
        for(int i=0; i<tamm; i++)
        {
            if(mascotas[i].isEmpty == 0 && mascotas[i].id == id)
            {
                *pIndex = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int modificarMascota(eMascota mascotas[], int tamm, eColor colores[], int tamc, eTipo tipos[], int tamt)
{
    int todoOk = 0;
    int indice;
    int idMascota;
    int auxIdTipo;
    char auxVacunado;
    char salir = 'n';

    if(mascotas != NULL && tamm>0 && colores!=NULL && tamc>0 && tipos!=NULL && tamt>0)
    {
        listarMascotas(mascotas,tamm,colores,tamc,tipos,tamt);

        utn_getInt("Ingrese Id de la Mascota: ", "Error Id invalido. ", 10000, 20000, 100, &idMascota);

        if(buscarMascota(mascotas, tamm, idMascota, &indice))
        {
            if(indice == -1)
            {
                printf("No hay una mascota con id %d\n", idMascota);
            }
            else
            {
                mostrarMascota(mascotas[indice],tamm,colores,tamc,tipos,tamt);
                do
                {
                    switch(menuModificarMascota())
                    {
                    case 1:
                        listarTipos(tipos, tamt);
                        utn_getInt("Ingrese Id del nuevo tipo: ", "Error. Id invalido.",1000,1004,100,&auxIdTipo);

                        mascotas[indice].idTipo = auxIdTipo;
                        printf("\nModificacion exitosa!!\n");
                        break;
                    case 2:
                        printf("Ingrese estado de vacunacion (s/n): ");
                        fflush(stdin);
                        scanf("%c", &auxVacunado);
                        auxVacunado = tolower(auxVacunado);
                        while(auxVacunado != 's' && auxVacunado!= 'n')
                        {
                            printf("Error. Reingrese estado de vacunacion (s/n): ");
                            fflush(stdin);
                            scanf("%c", &auxVacunado);
                            auxVacunado = tolower(auxVacunado);
                        }

                        mascotas[indice].vacunado = auxVacunado;
                        printf("\nModificacion exitosa!!\n");
                        break;
                    case 3:
                        salir = 's';
                        break;
                    }
                }
                while(salir != 's');

                todoOk = 1;
            }
        }
        else
        {
            printf("Ocurrio un problema al buscar empleado!!\n\n");
        }

        todoOk = 1;
    }
    return todoOk;
}

int bajaMascota(eMascota mascotas[], int tamm, eColor colores[], int tamc, eTipo tipos[], int tamt)
{
    int todoOk = 0;
    int indice;
    int idMascota;
    char confirma;

    if(mascotas != NULL && tamm>0 && colores!=NULL && tamc>0 && tipos!=NULL && tamt>0)
    {
        listarMascotas(mascotas,tamm,colores,tamc,tipos,tamt);

        utn_getInt("Ingrese id Mascota: ", "Error. Ingrese Id valido. ", 10000,20000,100, &idMascota);

        if(buscarMascota(mascotas, tamm, idMascota, &indice))
        {
            if(indice == -1)
            {
                printf("No hay una mascota con id %d\n", idMascota);
            }
            else
            {
                mostrarMascota(mascotas[indice],tamm, colores, tamc, tipos,tamt);
                printf("Confirma baja?: ");
                fflush(stdin);
                scanf("%c", &confirma);
                if(confirma != 'S' && confirma != 's')
                {
                    printf("Baja cancelada por el usuario!!\n");
                }
                else
                {
                    mascotas[indice].isEmpty = 1;
                    printf("Baja realizada con exito!!\n\n");
                    todoOk = 1;
                }
            }
        }
        else
        {
            printf("Ocurrio un problema al buscar empleado!!\n\n");
        }

        todoOk = 1;
    }
    return todoOk;
}

int cargarDescripcionMascota(eMascota mascotas[], int tamm, int id, char descripcion[])
{
    int todoOk = 0;
    int indice;

    buscarMascota(mascotas, tamm, id, &indice);

    if(descripcion!=NULL && indice!=-1)
    {
        strcpy(descripcion, mascotas[indice].nombre);
        todoOk = 1;
    }
    return todoOk;
}



