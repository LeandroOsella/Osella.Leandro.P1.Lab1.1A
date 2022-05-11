#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[25];
    float precio;
}eServicio;

#endif // SERVICIO_H_INCLUDED
int listarServicios(eServicio servicios[], int tams);
int buscarServicio(eServicio servicios[], int tams, int id, int* pIndice);
int cargarDescripcionServicio(eServicio servicios[], int tams, int id, char descripcion[]);
