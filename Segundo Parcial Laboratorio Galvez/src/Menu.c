/*
 * Menu.c
 *
 *  Created on: 31 jul. 2022
 *      Author: Tobias Galvez
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

int menu()
{
	int opcion;

	printf("\n************************MENU POKEMONES************************************\n");
	printf("1. Cargar archivo pokemones.\n");
	printf("2. Modificar valor ataque.\n");
	printf("3. Imprimir Pokemones.\n");
	printf("4. Filtrar tipo Fuego.\n");
	printf("5. Filtrar Extra Grandes de tipo Veneno.\n");
	printf("6. Salir\n");

	utn_getEntero(&opcion, 3, "Ingrese una opcion: \n", "Opcion invalida. Reintente \n", 1, 6);

	return opcion;
}
