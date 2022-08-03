/*
 * Pokemon.c
 *
 *  Created on: 31 jul. 2022
 *      Author: Tobias Galvez
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Pokemon.h"
#include "utn.h"


ePokemon* Pokemon_new()
{
	ePokemon* pokemon;

	pokemon = (ePokemon*) malloc(sizeof(ePokemon));

	if(pokemon != NULL)
	{
		Pokemon_setAll(pokemon, 0, "\0", "\0", "\0", "\0", 0, -1);

	}

	return pokemon;
}

ePokemon* Pokemon_newParametros(char* numeroStr, char* nombreStr, char* tipoStr, char* tamanioStr, char* ataqueCargadoStr, char* valorAtaqueStr, char* esVarioColorStr)
{
	ePokemon* pokemon;
	int numero;
	int valorAtaque;
	int esVarioColor;

	pokemon = Pokemon_new();

	if(pokemon != NULL)
	{
		numero=atoi(numeroStr);
		valorAtaque=atoi(valorAtaqueStr);
		esVarioColor=atoi(esVarioColorStr);

		Pokemon_setAll(pokemon, numero, nombreStr, tipoStr, tamanioStr, ataqueCargadoStr, valorAtaque, esVarioColor);

	}

	return pokemon;
}


void Pokemon_delete(ePokemon* pokemon)
{
	if(pokemon != NULL)
	{
		free(pokemon);
		pokemon = NULL;
	}
}


int Pokemon_printOne(ePokemon* this)
{
	int todoOk = -1;
	int auxNumero;
	char auxNombre[50];
	char auxTipo[50];
	char auxTamanio[50];
	char auxAtaqueCargado[50];
	int auxValorAtaque;
	int auxEsVarioColor;
	char auxEsVarioColorStr[3];


	if(this!=NULL)
	{
		if(Pokemon_getAll(this, &auxNumero, auxNombre, auxTipo, auxTamanio, auxAtaqueCargado, &auxValorAtaque, &auxEsVarioColor) == 0
		   )
		{
			strcpy(auxEsVarioColorStr, "no");
			if(auxEsVarioColor == 1)
			{
				strcpy(auxEsVarioColorStr, "si");
			}
			printf("%2d\t%15s\t%12s\t%5s\t%15s\t%15d\t%18s\n",auxNumero
													   	   	 ,auxNombre
															 ,auxTipo
															 ,auxTamanio
															 ,auxAtaqueCargado
															 ,auxValorAtaque
															 ,auxEsVarioColorStr);
			todoOk=0;
		}
		else
		{
			printf("Error para mostrar el pokemon");
		}
	}

	return todoOk;
}

int Pokemon_printList(LinkedList* listaPokemones)
{
	int todoOk = -1;
	ePokemon* aux = NULL;

	if(listaPokemones!=NULL)
	{
		if(ll_len(listaPokemones)>0)
		{
			printf("NUMERO\t\tNOMBRE\t\tTIPO\tTAMANIO\t  ATAQUE CARGADO\tVALOR ATAQUE\tES DE VARIOS COLORES?\n");

			for(int i=0; i<ll_len(listaPokemones);i++)
			{
				aux = (ePokemon*) ll_get(listaPokemones,i);

				if(aux != NULL)
				{
					Pokemon_printOne(aux);
					todoOk=0;
				}
			}
		}
	}

	return todoOk;
}

int Pokemon_findNumero(LinkedList* listaPokemones, int numero)
{
	int index=-1;
	ePokemon* auxiliar;
	int auxNum;

	if(listaPokemones!=NULL && numero > 0)
	{
		if(ll_len(listaPokemones)>0)
		{
			for(int i=0; i<ll_len(listaPokemones) ;i++)
			{
				auxiliar = (ePokemon*)ll_get(listaPokemones,i);
				Pokemon_getNumero(auxiliar, &auxNum);

				if(auxNum==numero)
				{
					index=i;
					break;
				}
			}
		}
	}

	return index;
}


int Pokemon_edit(LinkedList* listaPokemones)
{
	int todoOk = -1;
	int auxNum;
	int indice;

	ePokemon* auxiliar = NULL;
	char confirma;

	int auxValorAtaque;

	if(listaPokemones!=NULL)
	{
		utn_getEntero(&auxNum, 3, "Ingrese numero de pokemon a modificar:\n", "ERROR, id invalido", 1, 150);
		indice = Pokemon_findNumero(listaPokemones, auxNum);

		if(indice == -1)
		{
			printf("No se encontró el numero ingresado\n");
		}
		else
		{
			auxiliar = (ePokemon*) ll_get(listaPokemones, indice);
			Pokemon_printOne(auxiliar);
			utn_getCaracter(&confirma, 3, "Desea modificar valor de ataque de pokemon?(s/n): \n", "ERROR, reintente\n");
			confirma = tolower(confirma);
			if(confirma == 's')
			{

				utn_getEnteroSinRango(&auxValorAtaque, 3, "Ingrese nuevo valor de ataque de pokemon: \n", "ERROR, numero invalido\n");
				Pokemon_setValorAtaque(auxiliar, auxValorAtaque);
				todoOk=0;
			}
			else
			{
				printf("Se ha cancelado la modificacion\n");
			}
		}
	}
	return todoOk;

}


int Pokemon_filterFire(void* elemento)
{
    int retorno = -1;
    ePokemon* pokemon;

    char tipo[50];

    if(elemento != NULL)
    {
    	strcpy(tipo, "Fire");
    	pokemon = (ePokemon*) elemento;

    	if(strcmp(tipo,pokemon->tipo)==0)
    	{
    	   retorno=1;
    	}
    }



    return retorno;
}

int Pokemon_filterTipoYTamanio(void* elemento)
{
    int retorno = -1;
    ePokemon* pokemon;

    char tamanio[50];
    char tipo[50];

    if(elemento != NULL)
    {
        strcpy(tamanio, "XL");
        strcpy(tipo, "Poison");

        pokemon = (ePokemon*) elemento;

        if(strcmp(tipo,pokemon->tipo)==0 && strcmp(tamanio,pokemon->tamanio) == 0)
        {
        	retorno=1;
        }
    }


    return retorno;
}


//SETTERS
int Pokemon_setNumero(ePokemon* this, int numero)
{
	int todoOk = -1;

	if(this!=NULL && numero>0)
	{
		this->numero = numero;
		todoOk=0;
	}

	return todoOk;
}

int Pokemon_setNombre(ePokemon* this, char* nombre)
{
	int todoOk = -1;

	if(this!=NULL && nombre!=NULL)
	{
		strcpy(this->nombre, nombre);
		todoOk=0;
	}

	return todoOk;
}

int Pokemon_setTipo(ePokemon* this, char* tipo)
{
	int todoOk = -1;

	if(this!=NULL && tipo!=NULL)
	{
		strcpy(this->tipo, tipo);
		todoOk=0;
	}

	return todoOk;
}

int Pokemon_setTamanio(ePokemon* this, char* tamanio)
{
	int todoOk = -1;

	if(this!=NULL && tamanio!=NULL)
	{
		strcpy(this->tamanio, tamanio);
		todoOk=0;
	}

	return todoOk;
}

int Pokemon_setAtaqueCargado(ePokemon* this, char* ataqueCargado)
{
	int todoOk = -1;

	if(this!=NULL && ataqueCargado!=NULL)
	{
		strcpy(this->ataqueCargado, ataqueCargado);
		todoOk=0;
	}

	return todoOk;
}


int Pokemon_setValorAtaque(ePokemon* this, int valorAtaque)
{
	int todoOk = -1;

	if(this!=NULL && valorAtaque>0)
	{
		this->valorAtaque = valorAtaque;
		todoOk=0;
	}

	return todoOk;
}

int Pokemon_setEsVarioColor(ePokemon* this, int esVarioColor)
{
	int todoOk = -1;

	if(this!=NULL && (esVarioColor == 0 || esVarioColor == 1))
	{
		this->esVarioColor = esVarioColor;
		todoOk=0;
	}

	return todoOk;
}


int Pokemon_setAll(ePokemon* this, int numero, char* nombre, char* tipo, char* tamanio, char* ataqueCargado, int valorAtaque, int esVarioColor)
{
	int todoOk = -1;

	if(this != NULL)
	{
		if(numero > 0 && nombre != NULL && tipo != NULL && tamanio != NULL && ataqueCargado != NULL && valorAtaque > 0 && (esVarioColor == 0 || esVarioColor == 1))
		{
			if(		   Pokemon_setNumero(this, numero) 				 == 0   &&
					   Pokemon_setNombre(this, nombre) 				 == 0   &&
					   Pokemon_setTipo(this, tipo)					 == 0   &&
					   Pokemon_setTamanio(this, tamanio) 			 == 0   &&
					   Pokemon_setAtaqueCargado(this, ataqueCargado) == 0   &&
					   Pokemon_setValorAtaque(this, valorAtaque)     == 0   &&
					   Pokemon_setEsVarioColor(this, esVarioColor)   == 0)
			{
				todoOk=0;
			}
		}
	}

	return todoOk;

}


//GETTERS
int Pokemon_getNumero(ePokemon* this, int* numero)
{
	int todoOk= -1;

	if(this!=NULL && numero!=NULL)
	{
		*numero = this->numero;
		todoOk=0;
	}

	return todoOk;
}

int Pokemon_getNombre(ePokemon* this, char* nombre)
{
	int todoOk= -1;

	if(this!=NULL && nombre!=NULL)
	{
		strcpy(nombre, this->nombre);
		todoOk=0;
	}

	return todoOk;
}

int Pokemon_getTipo(ePokemon* this, char* tipo)
{
	int todoOk= -1;

	if(this!=NULL && tipo!=NULL)
	{
		strcpy(tipo, this->tipo);
		todoOk=0;
	}

	return todoOk;
}

int Pokemon_getTamanio(ePokemon* this, char* tamanio)
{
	int todoOk= -1;

	if(this!=NULL && tamanio!=NULL)
	{
		strcpy(tamanio, this->tamanio);
		todoOk=0;
	}

	return todoOk;
}

int Pokemon_getAtaqueCargado(ePokemon* this, char* ataqueCargado)
{
	int todoOk= -1;

	if(this!=NULL && ataqueCargado!=NULL)
	{
		strcpy(ataqueCargado, this->ataqueCargado);
		todoOk=0;
	}

	return todoOk;
}

int Pokemon_getValorAtaque(ePokemon* this, int* valorAtaque)
{
	int todoOk= -1;

	if(this!=NULL && valorAtaque!=NULL)
	{
		*valorAtaque = this->valorAtaque;
		todoOk=0;
	}

	return todoOk;
}

int Pokemon_getEsVarioColor(ePokemon* this, int* esVarioColor)
{
	int todoOk= -1;

	if(this!=NULL && esVarioColor!=NULL)
	{
		*esVarioColor = this->esVarioColor;
		todoOk=0;
	}

	return todoOk;
}


int Pokemon_getAll(ePokemon* this, int* numero, char* nombre, char* tipo, char* tamanio, char* ataqueCargado, int* valorAtaque, int* esVarioColor)
{
	int todoOk = -1;

	if(this != NULL)
	{
		if(numero != NULL && nombre != NULL && tipo != NULL && tamanio != NULL && ataqueCargado != NULL && valorAtaque != NULL && esVarioColor != NULL)
		{
			if(		   Pokemon_getNumero(this, numero) 				 == 0   &&
					   Pokemon_getNombre(this, nombre) 				 == 0   &&
					   Pokemon_getTipo(this, tipo)					 == 0   &&
					   Pokemon_getTamanio(this, tamanio) 			 == 0   &&
					   Pokemon_getAtaqueCargado(this, ataqueCargado) == 0   &&
					   Pokemon_getValorAtaque(this, valorAtaque)     == 0   &&
					   Pokemon_getEsVarioColor(this, esVarioColor)   == 0)
			{
				todoOk=0;
			}
		}
	}

	return todoOk;

}
