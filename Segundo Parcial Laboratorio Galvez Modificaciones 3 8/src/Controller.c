/*
 * Controller.c
 *
 *  Created on: 31 jul. 2022
 *      Author: Tobias Galvez
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Controller.h"
#include "Pokemon.h"
#include "Parser.h"
#include "utn.h"



int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	int todoOk = -1;
	FILE* archivo = NULL;

	if(path!=NULL && pArrayListPassenger!=NULL)
	{
		archivo = fopen(path,"r");

		if(archivo!= NULL)
		{
			if(parser_PokemonFromText(archivo, pArrayListPassenger) == 0)
			{
				printf("Archivo '%s' cargado de manera exitosa!!!\n" , path);
				todoOk=0;
			}
		}
		else
		{
			printf("Lo sentimos, hubo un error al abrir el archivo en modo texto\n");
		}
		fclose(archivo);
	}


    return todoOk;
}

int controller_ListPokemones(LinkedList* pArrayListPokemones)
{
	int todoOk =-1;

		if(pArrayListPokemones!=NULL)
		{
			printf("**********************************************Lista pokemones******************************************\n");
			if(Pokemon_printList(pArrayListPokemones)==-1)
			{
				printf("Lo sentimos, no hay pokemones para mostrar\n");

			}
			else
			{
				todoOk=0;
			}
		}

	    return todoOk;
}


int controller_editPokemon(LinkedList* pArrayListPokemones)
{
	int todoOk = -1;

		if(pArrayListPokemones!=NULL)
		{
			printf("\n*********************Modificacion valor de ataque pokemon********************************\n");
			if(Pokemon_edit(pArrayListPokemones) == -1)
			{
				printf("Hubo un error al realizar la modificacion\n");
			}
			else
			{
				printf("Valor de ataque modificado con exito!!!\n");
				todoOk=0;
			}
		}
		return todoOk;
}

int controller_filterFire(LinkedList* lista)
{
    int todoOk=-1;

    char path[30];
    LinkedList* nuevaLista;

        if(lista!=NULL)
        {
            nuevaLista = ll_filter(lista,Pokemon_filterFire);
            strcpy(path, "dataPokemonesTipoFire.csv");

            if(controller_saveAsText(path,nuevaLista)==0)
            {
				printf("\n\n Archivo con pokemones de tipo 'fire' generado con exito!!! \n\n");
            }
            else
            {
            	printf("Lo sentimos, hubo un error al intentar crear el archivo con pokemones de tipo 'fire'\n");
            }


            todoOk=1;
        }





    return todoOk;

}

int controller_filterTamanioYTipo(LinkedList* lista)
{
    int todoOk=-1;

    LinkedList* nuevaLista;

        if(lista!=NULL)
        {
            nuevaLista = ll_filter(lista,Pokemon_filterTipoYTamanio);

			if(controller_ListPokemones(nuevaLista)==0)
			{
				printf("\n\n Lista filtrada con exito!!! \n\n");
			}
			else
			{
				printf("Hubo un error al intentar filtrar la lista por pokemones de tamanio 'XL' y tipo 'Poison'\n");
			}
			todoOk=0;
        }

    return todoOk;

}


int controller_mapAtaqueCargado(LinkedList* lista)
{
	int todoOk=-1;

	LinkedList* nuevaLista;

	if(lista != NULL)
	{
		nuevaLista = ll_map(lista, Pokemon_mapAtaqueCargado);

		if(nuevaLista!=NULL)
		{
			if(/*controller_saveAsText("dataPokemones.csv", nuevaLista) ==0 */controller_ListPokemones(nuevaLista)==0)//cambiar lista original?
			{
				printf("\n\n Lista mapeada con exito!!! \n\n");
			}
			else
			{
				printf("Lo sentimos, hubo un error al realizar el mapeado\n");
			}
		}

		todoOk=0;
	}


	return todoOk;
}


int controller_ganarBatalla(LinkedList* lista)
{
	int todoOk=-1;
	int contadorBatalla;

	if(lista != NULL)
	{
		contadorBatalla = ll_count(lista, Pokemon_batalla);

		if(contadorBatalla >= 3)
		{
			printf("Hemos ganado la batalla, gracias a que peleamos con %d pokemones "
					"que cumplieron con los requisitos!!!!\n", contadorBatalla);
		}
		else
		{
			printf("No hemos podido ganar la batalla :( \n");
		}

		todoOk=0;
	}

	return todoOk;
}

int controller_saveAsText(char* path , LinkedList* pArrayListPokemones)
{
	int todoOk = -1;
	int auxNum;
	char auxNombre[50];
	char auxTipo[50];
	char auxTamanio[50];
	char auxAtaqueCargado[50];
	int auxValorDeAtaque;
	int auxEsVarioColor;

	FILE* archivo;
	ePokemon* auxiliar = NULL;

	if(path!=NULL && pArrayListPokemones!=NULL)
	{
		archivo = fopen(path,"w");

		if(archivo!= NULL && ll_len(pArrayListPokemones)>0)
		{
			for(int i=0; i<ll_len(pArrayListPokemones) ;i++)
			{
				auxiliar = (ePokemon*) ll_get(pArrayListPokemones,i);
				if(auxiliar!=NULL)
				{
					if(Pokemon_getAll(auxiliar, &auxNum, auxNombre, auxTipo, auxTamanio, auxAtaqueCargado, &auxValorDeAtaque, &auxEsVarioColor)==0)
					{
						fprintf(archivo,"%d,%s,%s,%s,%s,%d,%d\n",auxNum,auxNombre,auxTipo,auxTamanio,auxAtaqueCargado,auxValorDeAtaque,auxEsVarioColor);
						todoOk=0;
					}
					else
					{
						Pokemon_delete(auxiliar);
						printf("Lo sentimos, hubo un error al guardar el archivo\n");
					}
				}
			}
			printf("Archivo cargado en modo texto de manera exitosa!!!\n");
		}
		else
		{
			printf("Lo sentimos, hubo un error al abrir el archivo\n");
		}
		fclose(archivo);
	}

		return todoOk;
}
