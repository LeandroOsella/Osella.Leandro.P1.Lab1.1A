#include "tipo.h"
#include "color.h"
#include "servicio.h"
#include "mascota.h"
#include "validacion.h"
#include "fecha.h"

#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED

typedef struct
{
    int id;
    int idMascota;
    int idServicio;
    eFecha fecha;
    int isEmpty;
}eTrabajo;

#endif // TRABAJO_H_INCLUDED
int inicializarTrabajos(eTrabajo trabajos[], int tamtra);
int buscarLibreTrabajo(eTrabajo trabajos[], int tamtra, int* pIndex);
int altaTrabajo(eTrabajo trabajos[], int tamtra, eMascota mascotas[], int tamm, eServicio servicios[], int tams, eColor colores[], int tamc, eTipo tipos[], int tamt, int* pProximoIdTrabajo);
int mostrarTrabajo(eTrabajo trabajo, int tamtra, eServicio servicios[], int tams, eMascota mascotas[], int tamm);
int listarTrabajos(eTrabajo trabajos[], int tamtra, eMascota mascotas[], int tamm, eServicio servicios[], int tams);
