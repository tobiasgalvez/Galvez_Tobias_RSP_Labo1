/*
 * Parser.c
 *
 *  Created on: 31 jul. 2022
 *      Author: Tobias Galvez
 */


#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Pokemon.h"


int parser_PokemonFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int todoOk = -1;
	char id[50];
	char nombre[50];
	char tipo[50];
	char tamanio[50];
	char ataqueCargado[50];
	char valorAtaque[50];
	char esVarioColor[3];
	int cantidad = 0;
	ePokemon* auxiliar;

	if(pFile!=NULL && pArrayListPassenger!=NULL)
	{
		//fscanf(pFile,"%[^,] , %[^,] , %[^,] , %[^,] , %[^,] , %[^,] , %[^\n]\n",id,nombre,apellido,precio,codigoVuelo, tipoPasajero, estadoVuelo);//ESTO ES PARA QUE NO MUESTRE EL TITULO (FALSA LECTURA)
		do
		{
			cantidad = fscanf(pFile,"%[^,] , %[^,] , %[^,] , %[^,] , %[^,] , %[^,] , %[^\n]\n",id,nombre,tipo,tamanio,ataqueCargado,valorAtaque,esVarioColor);

			if((cantidad==7))
			{
				auxiliar = Pokemon_newParametros(id,nombre,tipo,tamanio,ataqueCargado,valorAtaque,esVarioColor );

				if(auxiliar!=NULL)
				{
					ll_add(pArrayListPassenger, auxiliar);
					todoOk=0;
				}
				else
				{
					Pokemon_delete(auxiliar);
				}
			}
			else
			{
				printf("Hubo un error al querer parsear datos\n");
			}

		}
		while(!feof(pFile));
	}

    return todoOk;
}



