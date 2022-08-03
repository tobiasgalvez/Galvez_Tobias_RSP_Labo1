/*
 * Controller.h
 *
 *  Created on: 31 jul. 2022
 *      Author: Tobias Galvez
 */
#include "LinkedList.h"
#ifndef CONTROLLER_H_
#define CONTROLLER_H_

/** \brief Carga los datos de los pokemones desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger);

/**
 * Listar pokemones
 * @param pArrayListPokemones
 * @return -1 si algo salio mal, 0 si esta ok
 */
int controller_ListPokemones(LinkedList* pArrayListPokemones);
/**
 * Modificar valor de ataque de pokemon
 * @param pArrayListPokemones
 * @return -1 si algo salio mal, 0 si esta ok
 */
int controller_editPokemon(LinkedList* pArrayListPokemones);

/**
 * Generar archivo filtrado con pokemones de tipo 'Fire'
 * @param lista
 * @return -1 si algo salio mal, 0 si esta ok
 */
int controller_filterFire(LinkedList* lista);
/**
 * Mostrar lista filtrada de pokemones por tamanio 'XL' y tipo 'Poison'
 * @param lista
 * @return -1 si algo salio mal, 0 si esta ok
 */
int controller_filterTamanioYTipo(LinkedList* lista);

/**
 * Guarda los datos de los pokemones en el archivo data.csv (modo texto).
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPokemones);


#endif /* CONTROLLER_H_ */
