#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pantalla.h"
#include "funciones.h"
#define TRUE 1
#define FALSE 0

static int getString(char* pBuffer, int limite)
{
    char bufferString [4096];
    int retorno = -1;
    if(pBuffer != NULL && limite > 0)
    {
        fflush(stdin);
        fgets(bufferString,sizeof(bufferString),stdin);
        if(bufferString[strlen(bufferString)-1]=='\n')
        {
            bufferString[strlen(bufferString)-1]='\0';
        }
        if(strlen(bufferString) <= limite)
        {
            strncpy(pBuffer,bufferString,limite);
            retorno = 0;
        }
    }
    return retorno;
}



int dardeAlta(Pantalla*pantalla,int indice,int tamanio)
{
    int retorno=-1;
    char nombreAuxiliar[50];
    int tipoAuxiliar;
    char direccionAuxiliar[50];
    float precioAuxiliar;

        if(indice>=0 && indice<tamanio)
        {
            if(utn_getLetras(nombreAuxiliar,50,3,"\ningrese nombre\n","\nerror\n")==0)
            {
                if(utn_getFloat(&precioAuxiliar,"\ningrese precio\n","error",0,1000000,3)==0)
                {
                    if(utn_getInt(&tipoAuxiliar,"\ningrese 1 para LCD 0 para LED\n","\n error\n",0,1,3)==0)
                    {
                        printf("\ningrese direccion \n");
                        if(getString(direccionAuxiliar,50)==0)
                        {
                            strncpy(pantalla[indice].nombre,nombreAuxiliar,50);
                            strncpy(pantalla[indice].direccion,direccionAuxiliar,50);
                            pantalla[indice].tipo=tipoAuxiliar;
                            pantalla[indice].precio=precioAuxiliar,
                            pantalla[indice].id=generarID();
                            pantalla[indice].isEmpty=FALSE;
                            retorno=0;
                        }

                    }
                }
            }
    }
return retorno;

}

void pantalla_Imprimir(Pantalla*pantalla,int tamanio)
{
    int i;
    for(i=0;i<tamanio;i++)
        {
            if(pantalla[i].isEmpty==FALSE)
                {
                    printf("\nNOMBRE:%s \nDIRECCION:%s \nTIPO:%d \nID:%d \nPRECIO:%.2f \nISEMPTY:%d \n",pantalla[i].nombre,pantalla[i].direccion,pantalla[i].tipo,pantalla[i].id,pantalla[i].precio,pantalla[i].isEmpty);
                }
        }
    }

int buscarLugarlibre(Pantalla*pantalla,int tamanio)
{
    int i;
    int retornoIndice=-1;
    for(i=0;i<tamanio;i++)
    {
        if(pantalla[i].isEmpty==TRUE)
        {
            retornoIndice=i;
            break;
        }
    }
    return retornoIndice;
}
int generarID()
{
    static int contID=0;

    return contID++;
}


int inicializarPantalla(Pantalla*pantalla,int len)
{
    int i;
    int retorno=-1;
    if(pantalla!=NULL && len>0)
    {
        for(i=0;i<len;i++)
        {
            pantalla[i].isEmpty=TRUE;
            retorno=0;
        }
    }
    return retorno;
}

int buscarPantallaporid(Pantalla*pantalla,int len,int id)
{
    int i;
    int retorno=-1;
    for(i=0;i<len;i++)
    {
        if(pantalla[i].isEmpty==FALSE && pantalla[i].id==id)
        {
            retorno=i;
            break;
        }
    }
    return retorno;
}


int modificarDatos_Pantalla(Pantalla*pantalla,int len,int indice)
 {
     int retorno=-1;
     int opcion;
     char nombreAuxiliar[50];
     char direccionAuxiliar[50];
     float precioAuxiliar;
     int tipoAuxiliar;

     if (indice>=0 && indice<len)
        {
            if(utn_getInt(&opcion,"\nIngrese:\n1 para modificar nombre\n2 para modificar direccion\n3 para modificar precio\n4 para modificar tipo\n","\Error, ingrese opcion valida\n",1,4,3)==0)
                {
                    switch(opcion)
                    {
                        case 1:
                            if(utn_getLetras(nombreAuxiliar,50,3,"\nIngrese nuevo nombre\n","\nError, nombre no valido")==0)
                                {
                                    strncpy(pantalla[indice].nombre,nombreAuxiliar,50);
                                    retorno=0;
                                }
                            break;

                        case 2:
                            if(utn_getLetras(direccionAuxiliar,50,3,"\nIngrese nueva direccion\n","\nError\n")==0)
                                {
                                    strncpy(pantalla[indice].direccion,direccionAuxiliar,50);
                                    retorno=0;
                                }
                            break;

                        case 3:
                            if(utn_getFloat(&precioAuxiliar,"\nIngrese nuevo precio\n","\nError salario no valido\n",0,10000000,3)==0)
                                {
                                    pantalla[indice].precio=precioAuxiliar;
                                    retorno=0;
                                }
                            break;

                        case 4:
                            if(utn_getInt(&tipoAuxiliar,"\nIngrese nuevo tipo\n","\nError sector no valido",0,1,3)==0)
                                {
                                    pantalla[indice].tipo=tipoAuxiliar;
                                    retorno=0;
                                }
                            break;

                    }
                }
        }

     return retorno;
 }

 int dardeBaja_Pantalla(Pantalla*pantalla,int id,int len)
{
    int i=0;
    int retorno=-1;
    if(pantalla!=NULL && id>=0)
        {
            for (i=0;i<len;i++)
                {
                    if(pantalla[i].id==id)
                        {
                            pantalla[i].isEmpty=TRUE;
                            retorno=0;
                            break;
                        }
                }
        }
        return retorno;
}
