#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"


int utn_getCadena(char *pAux, int limite, int reintentos, char* mensaje, char* mensajeError)
{
	int todoOk = -1;
    char auxString[limite];

    if(pAux != NULL && mensaje != NULL && mensajeError != NULL && limite > 0 && reintentos >= 0){
        do{
        	printf("%s", mensaje);

            if(getCadena(auxString, limite) == 0 && isCharString(auxString) == 0)
            {
                strcpy(pAux, auxString);
                todoOk = 0; //exito
                break;
            }else
            {
            	printf("%s", mensajeError);
            }
            reintentos--;

        }while(reintentos>=0);
    }

    return todoOk;
}

int utn_getCadenaConNumeros(char *pAux, int limite, int reintentos, char* mensaje, char* mensajeError)
{
	int todoOk = -1;
    char auxString[limite];

    if(pAux != NULL && mensaje != NULL && mensajeError != NULL && limite > 0 && reintentos >= 0){
        do{
        	printf("%s", mensaje);

            if(getCadena(auxString, limite) == 0)
            {
                strcpy(pAux, auxString);
                todoOk = 0; //exito
                break;
            }else
            {
            	printf("%s", mensajeError);
            }
            reintentos--;

        }while(reintentos>=0);
    }

    return todoOk;
}


int utn_getCaracter(char *pAux, int reintentos, char* mensaje, char* mensajeError)
{
	int todoOk = -1;
    char auxChar;

    if(pAux != NULL && mensaje != NULL && mensajeError != NULL && reintentos >= 0){
        do{
        	printf("%s", mensaje);
        	fflush(stdin);
        	scanf("%c" , &auxChar);

            if(isChar(auxChar) == 0)
            {
                *pAux = auxChar;
                todoOk = 0; //exito
                break;
            }else
            {
            	printf("%s", mensajeError);
            }
            reintentos--;

        }while(reintentos>=0);
    }

    return todoOk;
}




int getCadena(char* pAux, int limite)
{
    char auxString[4000];
    int todoOk = -1;

    if (pAux != NULL && limite > 0)
    {
        fflush(stdin);
        fgets(auxString,sizeof(auxString),stdin);

        if (auxString[strlen(auxString)-1]=='\n')
        {
            auxString[strlen(auxString)-1]='\0';
        }
        if(strlen(auxString)<= limite)
        {
            strncpy(pAux, auxString, limite);
            todoOk=0; //exito
        }
    }

    return todoOk;
}

int isCharString(char str[])
{

	int todoOk = 0; //exito

	for(int i = 0; str[i] != '\0'; i++)
	{
		//si no es espacio, si es menor a 'a' o may a 'z', si es men a 'A' o may a 'Z', NO es letra:
		if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
		{
			todoOk = -1;
		}
	}

	return todoOk;

}

int isChar(char caracter)
{

	int todoOk = 0; //exito


		//si no es espacio, si es menor a 'a' o may a 'z', si es men a 'A' o may a 'Z', NO es letra:
		if((caracter != ' ') && (caracter < 'a' || caracter > 'z') && (caracter < 'A' || caracter > 'Z'))
		{
			todoOk = -1;
		}


	return todoOk;

}

int utn_getFlotante(float* pFloat, int reintentos, char* mensaje, char*mensajeError, float min, float max)
{
    int todoOk = -1;
    float auxFloat;

    if(pFloat != NULL&& mensaje != NULL && mensajeError != NULL && min <= max && reintentos >= 0)
    {
        do
        {
            reintentos--;
            printf("%s",mensaje);
            if(getFloat(&auxFloat) == 0 && auxFloat >= min && auxFloat <= max)
            {
                *pFloat= auxFloat;
                todoOk = 0; //exito
                break;
            }
            else
            {
                printf("%s",mensajeError);
            }
        }
        while(reintentos >= 0);
    }
    return todoOk;
}

int getFloat(float*pAux)
{
    char auxString[200];
    int todoOk =-1;

    if(getCadena(auxString,200) == 0 && isFloat(auxString) == 0)
    {
        *pAux = atof(auxString); //to float
        todoOk = 0; //exito
    }
    return todoOk;
}

int isFloat(char* pAux)
{
    int todoOk = -1;
    int contadorPuntos=0;
    int stringLong = strlen(pAux);
    int i = 0;

    do
    {
        if(*(pAux + i) == '.')
        {
            contadorPuntos++;
            if(contadorPuntos == 2)
            {
                break;
            }
        }
        else if(*(pAux + i) < '0'|| *(pAux + i) > '9')
        {
            break;
        }

        i++;

    }while (i < stringLong);

    if(i == stringLong)
    {
        todoOk = 0; //exito
    }
    return todoOk;
}

int utn_getEntero(int* pEntero, int reintentos, char* mensaje, char*mensajeError, int min, int max)
{
    int todoOk = -1;
    int auxInt;

    if(pEntero != NULL && mensaje != NULL && mensajeError != NULL && min <= max && reintentos >= 0)
    {
        do
        {
            reintentos--;
            printf("%s", mensaje);

            if(getInt(&auxInt) == 0 && auxInt >= min && auxInt <= max)
            {
                *pEntero = auxInt;
                todoOk = 0; //exito
                break;
            }
            else
            {
                printf("%s", mensajeError);
            }
        }
        while(reintentos >= 0);
    }
    return todoOk;
}

int utn_getEnteroSinRango(int* pEntero, int reintentos, char* mensaje, char*mensajeError)
{
    int todoOk = -1;
    int auxInt;

    if(pEntero != NULL && mensaje != NULL && mensajeError != NULL && reintentos >= 0)
    {
        do
        {
            reintentos--;
            printf("%s", mensaje);

            if(getInt(&auxInt) == 0)
            {
                *pEntero = auxInt;
                todoOk = 0; //exito
                break;
            }
            else
            {
                printf("%s", mensajeError);
            }
        }
        while(reintentos >= 0);
    }
    return todoOk;
}



int getInt(int* pAux)
{
    char auxString[400];
    int todoOk = -1;

    if(getCadena(auxString, sizeof(auxString)) == 0 && isInt(auxString ) == 0)
    {
        *pAux = atoi(auxString); //to integer
        todoOk = 0; //exito
    }
    return todoOk;
}

int isInt(char *pAux)
{
    int todoOk = -1;
    int stringLong = strlen(pAux);
    int i;

    for(i = 0;i < stringLong; i++)
    {
       if(*(pAux + i) < '0' || *(pAux + i) > '9')
        {
            break;
        }
    }

    if(i == stringLong)
    {
        todoOk = 0; //exito
    }

    return todoOk;
}
