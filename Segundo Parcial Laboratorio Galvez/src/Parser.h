/*
 * Parser.h
 *
 *  Created on: 31 jul. 2022
 *      Author: Tobias Galvez
 */

#ifndef PARSER_H_
#define PARSER_H_

/** \brief Parsea los datos los datos de los pokemones desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PokemonFromText(FILE* pFile , LinkedList* pArrayListPassenger);

#endif /* PARSER_H_ */
