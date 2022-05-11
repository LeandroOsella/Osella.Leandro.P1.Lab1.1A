#include "tipo.h"
#include "color.h"

#ifndef MASCOTA_H_INCLUDED
#define MASCOTA_H_INCLUDED

typedef struct
{
    int id;
    char nombre[20];
    int idTipo;
    int idColor;
    int edad;
    char vacunado;
    int isEmpty;
}eMascota;


#endif // MASCOTA_H_INCLUDED

int inicializarMascotas(eMascota mascotas[], int tamm);
int buscarLibre(eMascota mascotas[], int tamm, int* pIndex);
int altaMascota(eMascota mascotas[], int tamm, int* pProximoIdMascota, eTipo tipos[], int tamt, eColor colores[], int tamc);
int mostrarMascota(eMascota mascota, int tamm, eColor colores[], int tamc, eTipo tipos[], int tamt);
int listarMascotas(eMascota mascotas[], int tamm, eColor colores[], int tamc, eTipo tipos[], int tamt);
int buscarMascota(eMascota mascotas[], int tamm, int id, int* pIndex);
int modificarMascota(eMascota mascotas[], int tamm, eColor colores[], int tamc, eTipo tipos[], int tamt);
int bajaMascota(eMascota mascotas[], int tamm, eColor colores[], int tamc, eTipo tipos[], int tamt);
int cargarDescripcionMascota(eMascota mascotas[], int tamm, int id, char descripcion[]);
