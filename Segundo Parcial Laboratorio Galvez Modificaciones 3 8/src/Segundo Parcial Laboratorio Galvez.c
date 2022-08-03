/*
 ============================================================================
 Name        : Segundo.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Pokemon.h"
#include "utn.h"
#include "Menu.h"

int main(void) {

	setbuf(stdout, NULL);
	char seguir = 's';
	LinkedList* listaPokemones = ll_newLinkedList();
	int flagLoadFromText=0;
	char auxPath[50];

		do{
	        switch(menu())
	        {
	            case 1:
	            	if(/*ll_isEmpty(listaPasajeros)==1 ||*/ (flagLoadFromText == 0))
	            	{
	            		utn_getCadenaConNumeros(auxPath, 50, 3, "Ingrese el nombre del path del archivo que desea leer:\n", "Error, reintente nuevamente\n");
	            		if(controller_loadFromText(auxPath,listaPokemones)==0)
	            		{
	            			printf("Lista cargada en modo texto con exito!!!\n");
	            			flagLoadFromText=1;
	            		}

	            	}
	            	else
	            	{
	            		printf("No es posible cargar el archivo dos veces!!!\n");
	            	}
	                break;
	            case 2:
	            	if(ll_isEmpty(listaPokemones)==0)
	            	{

	            		if(controller_editPokemon(listaPokemones)==-1)
	            		{
	            			printf("Error al realizar la modificacion\n");
	            		}
	            		else
	            		{
	            			printf("Modificacion exitosa!!!\n");
	            		}
	            	}
	            	else
	            	{
	            		printf("Lo sentimos no hay pokemones para realizar la modificacion\n");
	            	}
	            	break;


	            case 3:
	            	if(ll_isEmpty(listaPokemones)==0)
	            	{
	            		controller_ListPokemones(listaPokemones);
	            	}
	            	else
	            	{
	            		printf("Lo sentimos, no hay pokemones para mostrar\n");
	            	}
	            	break;
	            case 4:
	            	if(ll_isEmpty(listaPokemones)==0)
	            	{
	            		controller_filterFire(listaPokemones);
	            	}
	            	else
	            	{
	            		printf("Lo sentimos, no hay pokemones para mostrar\n");
	            	}
	            	break;

	            case 5:
	            	if(ll_isEmpty(listaPokemones)==0)
	            	{
	            		controller_filterTamanioYTipo(listaPokemones);
	            	}
	            	else
	            	{
	            		printf("Lo sentimos, no hay pokemones para mostrar\n");
	            	}
	            	break;

	            case 6:
	            	if(ll_isEmpty(listaPokemones)==0)
	            	{
	            		controller_mapAtaqueCargado(listaPokemones);
	            	}
	            	else
	            	{
	            		printf("Lo sentimos, no hay pokemones para mostrar\n");
	            	}
	            	break;

	            case 7:
	            	if(ll_isEmpty(listaPokemones)==0)
	            	{
	            		controller_ganarBatalla(listaPokemones);
	            	}
	            	else
	            	{
	            		printf("Lo sentimos, no hay pokemones para mostrar\n");
	            	}
	            	break;

	            case 8:
            		//controller_saveAsText(auxPath,listaPokemones);
	            		seguir = 'n';
	            		printf("Saliendo del programa...\n");
	            		break;
	            default:
	            		printf("Opcion invalida\n");
	        }

	    	printf("\nPresione cualquier tecla para continuar...\n");
	    	fflush(stdin);
	    	getchar();


	    }while(seguir == 's');

	return EXIT_SUCCESS;
}
