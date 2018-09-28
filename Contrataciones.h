#ifndef CONTRATACIONES_H_INCLUDED
#define CONTRATACIONES_H_INCLUDED

typedef struct
{
    int id;
    char cuitDeCLiente[15];//cambiar a CHAR[] Y VALIDAR CON FUNCION
    float duracion;
    char tipoDeArchivo[61];
    int idPantalla;
    int isEmpty;

}Contratacion;

int inicializarContrataciones(Contratacion* contratacion,int len);
int altaContratacion(Contratacion* contratacion,int len, int id);


#endif // CONTRATACIONES_H_INCLUDED
