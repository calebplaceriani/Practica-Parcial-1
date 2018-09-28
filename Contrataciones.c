#include <stdio.h>
#include <stdlib.h>
#include "pantalla.h"
#include "funciones.h"
#include "contrataciones.h"
#include <string.h>
#include <stdio_ext.h>
#define LEN 100

int inicializarContrataciones(Contratacion* contratacion,int len)
{
    int i;
    int retorno=-1;
    if(contratacion!=NULL && len>0)
    {
        for(i=0;i<len;i++)
        {
            contratacion[i].isEmpty=1;
            retorno=0;
        }
    }
    return retorno;
}

int altaContratacion(Contratacion* contrataciones,int len, int id)
{
    int retorno = -1;
    char cuitAux[14];
    float duracionAux;
    char tipoDeArchivoAux[21];

    if(contrataciones!=NULL && len>0)
    {
        printf("Ingrese CUIT ");
        __fpurge(stdin);
        scanf("\n%s",cuitAux);
        if(verificarCuit(cuitAux)==0)
        {
            if(utn_getFloat(&duracionAux,"Ingrese la duracion del archivo","-aca- Error de ingreso\n",0.1,5,2)==0)
            {
                if(utn_getLetras(tipoDeArchivoAux,21,2,"Ingrese el tipo de archivo"," Error de ingreso\n")==0)
                {
                    strncpy(contrataciones[id].cuitDeCLiente,cuitAux,14);
                    contrataciones[id].duracion=duracionAux;
                    strncpy(contrataciones[id].tipoDeArchivo,tipoDeArchivoAux,21);
                    contrataciones[id].isEmpty=0;
                    contrataciones[id].idPantalla=id;
                    retorno=0;
                }

            }


        }


    }
    printf("%d",retorno);
    return retorno;
}
