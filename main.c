#include <stdio.h>
#include <stdlib.h>
#include "pantalla.h"
#include "funciones.h"
#include "contrataciones.h"
#include <strings.h>
#define LEN 100

int main()
{
    Pantalla pantallas[LEN];
    Contratacion contrataciones[LEN];

    inicializarPantalla(pantallas,LEN);
    inicializarContrataciones(contrataciones,LEN);

    int opcion;
    int indice;
    int id;
    int idAux;
    int pantallaEncontrada;

    printf("\nPractica\n");
    do
        {
            if(utn_getInt(&opcion,"\n1-DAR DE ALTA PANTALLA \n\n2-MODIFICAR DATOS DE PANTALLA \n\n3-DAR DE BAJA PANTALLA \n\n4-MOSTRAR\n\n","\nError,opcion invalida\n",1,11,3)==0)
                {
                    switch(opcion)
                    {
                        case 1:
                                indice=buscarLugarlibre(pantallas,LEN);
                                if(indice>=0)
                                    {
                                        if(dardeAlta(pantallas,indice,LEN)==0)
                                            {

                                                printf("\nAlta exitosa\n");
                                            }
                                            else
                                                {printf("\nError - No se cargo pantalla\n");}
                                    }else
                                    {
                                        printf("\nEl id no existe\n");
                                    }
                                    break;

                        case 2:
                                if(utn_getInt(&id,"\nIngrese numero id\n","\nError no es un id correcto\n",0,99,3)==0)
                                    {
                                        indice=buscarPantallaporid(pantallas,LEN,id);
                                        if(indice>=0)
                                            {
                                                if(modificarDatos_Pantalla(pantallas,LEN,indice)==0)
                                                    {
                                                        printf("\nSe modificaron los datos correctamente\n");
                                                    }
                                                    else{printf("\nNo se modificaron los datos correctamente\n");}
                                            }
                                            else{printf("\nID no existe\n");}
                                    }
                                    else{printf("\nNo se pudo cargar id");}
                                    break;

                        case 3:
                                if(utn_getInt(&id,"\nIngrese id de la pantalla a dar de baja\n","\nerror id no valido\n",0,99,3)==0)
                                                    {
                                                        indice=buscarPantallaporid(pantallas,LEN,id);
                                                        if(indice>=0)
                                                        {
                                                            if(dardeBaja_Pantalla(pantallas,id,LEN)==0)
                                                                {
                                                                    printf("\nSe ha dado de baja la pantalla\n");
                                                                }
                                                                else
                                                                {
                                                                    printf("\nError,no se pudo dar de baja la pantalla");
                                                                }

                                                        }
                                                        else
                                                        {
                                                            printf("\nEl id no existe\n");
                                                        }
                                                }
                                                else{printf("\nNo se pudo cargar id\n");}
                                                break;


                        case 4:

                                pantalla_Imprimir(pantallas,LEN);
                                if(utn_getInt(&idAux,"Ingrese el ID de la pantalla que desea contratar","Error - id invalido",0,LEN,2)==0)
                                {
                                    pantallaEncontrada=buscarPantallaporid(pantallas,LEN,idAux);
                                    if(pantallaEncontrada>=0)
                                    altaContratacion(contrataciones,LEN,pantallaEncontrada);
                                    else{printf("\n\nNO se encontro la pantalla deseada\n\n");}

                                }

                                break;
                        }
                }
                }while(opcion!=11);
    return 0;
}

