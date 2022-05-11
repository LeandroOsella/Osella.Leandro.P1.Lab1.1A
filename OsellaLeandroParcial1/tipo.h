#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];
}eTipo;

#endif // TIPO_H_INCLUDED

int listarTipos(eTipo tipos[], int tamt);
int buscarTipo(eTipo tipos[], int tamt, int id, int* pIndice);
int cargarDescripcionTipo(eTipo tipos[], int tamt, int id, char descripcion[]);
