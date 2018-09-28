#ifndef PANTALLA_H_INCLUDED
#define PANTALLA_H_INCLUDED

typedef struct
{
    int id;
    char nombre[50];
    char direccion[50];
    int tipo;
    int isEmpty;
    float precio;
}Pantalla;


int dardeAlta(Pantalla *pantalla,int indice,int tamanio);

void pantalla_Imprimir(Pantalla*pantalla,int tamanio);

int buscarLugarlibre(Pantalla*pantalla,int tamanio);

int generarID();

int inicializarPantalla(Pantalla*pantalla,int tamanio);

int modificarDatos_Pantalla(Pantalla*pantalla,int tamanio,int indice);

int dardeBaja_Pantalla(Pantalla*pantalla,int id,int tamanio);

int buscarPantallaporid(Pantalla*pantalla,int tamanio,int id);




#endif // PANTALLA_H_INCLUDED
