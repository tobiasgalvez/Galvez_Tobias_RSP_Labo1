/*
 * Pokemon.h
 *
 *  Created on: 31 jul. 2022
 *      Author: Tobias Galvez
 */

#include "LinkedList.h"
#ifndef POKEMON_H_
#define POKEMON_H_

typedef struct
{
	int numero;
	char nombre[50];
	char tipo[50];
	char tamanio[3];
	char ataqueCargado[50];
	int valorAtaque;
	int esVarioColor;
}ePokemon;

/**
 * Funcion que permite construir un pokemon
 * @return un pokemon
 */
ePokemon* Pokemon_new();
/**
 * Funcion que permite construir un pokemon parametrizado
 * @param numeroStr
 * @param nombreStr
 * @param tipoStr
 * @param tamanioStr
 * @param ataqueCargadoStr
 * @param valorAtaqueStr
 * @param esVarioColorStr
 * @return un pokemon
 */
ePokemon* Pokemon_newParametros(char* numeroStr, char* nombreStr, char* tipoStr, char* tamanioStr, char* ataqueCargadoStr, char* valorAtaqueStr, char* esVarioColorStr);
/**
 * Funcion que permite eliminar un pokemon
 * @param pokemon
 */
void Pokemon_delete(ePokemon* pokemon);
/**
 * Funcion que permite mostrar un pokemon
 * @param this
 * @return -1 si algo salio mal, 0 si esta ok
 */
int Pokemon_printOne(ePokemon* this);
/**
 * Funcion que permite mostrar una lista de pokemones
 * @param listaPokemones
 * @return -1 si algo salio mal, 0 si esta ok
 */
int Pokemon_printList(LinkedList* listaPokemones);
/**
 * Funcion que permite buscar un pokemon por numero
 * @param listaPokemones
 * @param numero
 * @return numero de pokemon
 */
int Pokemon_findNumero(LinkedList* listaPokemones, int numero);
/**
 * Funcion que permite modificar valor de ataque de un pokemon
 * @param listaPokemones
 * @return -1 si algo salio mal, 0 si esta ok
 */
int Pokemon_edit(LinkedList* listaPokemones);


/**
 * Funcion que permite averiguar si un pokemon es de tipo Fire
 * @param elemento
 * @return 0 si no es de ese tipo, 1 si lo es
 */
int Pokemon_filterFire(void* elemento);
/**
 * Funcion que permite averiguar si un pokemon es de tamaño XL y de tipo Poison
 * @param elemento
 * @return 0 si no es de ese tamaño y/o de ese tipo, 1 si lo es
 */
int Pokemon_filterTipoYTamanio(void* elemento);


//SETTERS
/**
 * Funcion que permite settear un numero de pokemon
 * @param this
 * @param numero
 * @return -1 si algo salio mal, 0 si esta ok
 */
int Pokemon_setNumero(ePokemon* this, int numero);
/**
 * Funcion que permite settear un nombre de pokemon
 * @param this
 * @param nombre
 * @return -1 si algo salio mal, 0 si esta ok
 */
int Pokemon_setNombre(ePokemon* this, char* nombre);
/**
 * Funcion que permite settear un tipo de pokemon
 * @param this
 * @param tipo
 * @return -1 si algo salio mal, 0 si esta ok
 */
int Pokemon_setTipo(ePokemon* this, char* tipo);
/**
 * Funcion que permite settear un tamanio de pokemon
 * @param this
 * @param tamanio
 * @return -1 si algo salio mal, 0 si esta ok
 */
int Pokemon_setTamanio(ePokemon* this, char* tamanio);
/**
 * Funcion que permite settear un ataque cargado de pokemon
 * @param this
 * @param ataqueCargado
 * @return -1 si algo salio mal, 0 si esta ok
 */
int Pokemon_setAtaqueCargado(ePokemon* this, char* ataqueCargado);
/**
 * Funcion que permite settear un valor de ataque de pokemon
 * @param this
 * @param valorAtaque
 * @return -1 si algo salio mal, 0 si esta ok
 */
int Pokemon_setValorAtaque(ePokemon* this, int valorAtaque);
/**
 * Funcion que permite settear si el pokemon es de varios colores o no
 * @param this
 * @param esVarioColor
 * @return -1 si algo salio mal, 0 si esta ok
 */
int Pokemon_setEsVarioColor(ePokemon* this, int esVarioColor);
/**
 * Funcion que permite settear todos los datos de un pokemon
 * @param this
 * @param numero
 * @param nombre
 * @param tipo
 * @param tamanio
 * @param ataqueCargado
 * @param valorAtaque
 * @param esVarioColor
 * @return -1 si algo salio mal, 0 si esta ok
 */
int Pokemon_setAll(ePokemon* this, int numero, char* nombre, char* tipo, char* tamanio, char* ataqueCargado, int valorAtaque, int esVarioColor);

//GETTERS
/**
 * Funcion que permite obtener un numero de pokemon
 * @param this
 * @param numero
 * @return -1 si algo salio mal, 0 si esta ok
 */
int Pokemon_getNumero(ePokemon* this, int* numero);
/**
 * Funcion que permite obtener un nombre de pokemon
 * @param this
 * @param nombre
 * @return -1 si algo salio mal, 0 si esta ok
 */
int Pokemon_getNombre(ePokemon* this, char* nombre);
/**
 * Funcion que permite obtener un tipo de pokemon
 * @param this
 * @param tipo
 * @return -1 si algo salio mal, 0 si esta ok
 */
int Pokemon_getTipo(ePokemon* this, char* tipo);
/**
 * Funcion que permite obtener un tamanio de pokemon
 * @param this
 * @param tamanio
 * @return -1 si algo salio mal, 0 si esta ok
 */
int Pokemon_getTamanio(ePokemon* this, char* tamanio);
/**
 * Funcion que permite obtener un ataque cargado de pokemon
 * @param this
 * @param ataqueCargado
 * @return -1 si algo salio mal, 0 si esta ok
 */
int Pokemon_getAtaqueCargado(ePokemon* this, char* ataqueCargado);
/**
 * Funcion que permite obtener un valor de ataque de pokemon
 * @param this
 * @param valorAtaque
 * @return -1 si algo salio mal, 0 si esta ok
 */
int Pokemon_getValorAtaque(ePokemon* this, int* valorAtaque);
/**
 * Funcion que permite obtener si un pokemon es de varios colores o no
 * @param this
 * @param esVarioColor
 * @return -1 si algo salio mal, 0 si esta ok
 */
int Pokemon_getEsVarioColor(ePokemon* this, int* esVarioColor);
/**
 * Funcion que permite obtener todos los datos de un pokemon
 * @param this
 * @param numero
 * @param nombre
 * @param tipo
 * @param tamanio
 * @param ataqueCargado
 * @param valorAtaque
 * @param esVarioColor
 * @return -1 si algo salio mal, 0 si esta ok
 */
int Pokemon_getAll(ePokemon* this, int* numero, char* nombre, char* tipo, char* tamanio, char* ataqueCargado, int* valorAtaque, int* esVarioColor);


#endif /* POKEMON_H_ */
