#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

typedef struct
{
    int id;
    char nombreColor[20];
}eColor;

#endif // COLOR_H_INCLUDED

int listarColores(eColor colores[], int tamc);
int buscarColor(eColor colores[], int tamc, int id, int* pIndice);
int cargarDescripcionColor(eColor colores[], int tamc, int id, char descripcion[]);
