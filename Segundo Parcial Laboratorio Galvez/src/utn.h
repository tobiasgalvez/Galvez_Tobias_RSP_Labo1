#ifndef UTN_H_
#define UTN_H_

/**
 * Funcion que permite validar que el usuario ingrese una cadena de caracteres.
 * @param Puntero a variable char en la que cargar la cadena validada.
 * @param Limite de caracteres a ingresar
 * @param Numero de reintentos
 * @param Mensaje a mostrar
 * @param Mensaje de error
 * @return 0 si tuvo exito, y -1 si no.
 */
int utn_getCadena(char*, int, int, char*, char*);

int utn_getCadenaConNumeros(char *pAux, int limite, int reintentos, char* mensaje, char* mensajeError);

int utn_getCaracter(char *pAux, int reintentos, char* mensaje, char* mensajeError);

/**
 * Funcion que permite tomar la cadena ingresada y le quita el '\n' al fgets.
 * @param Puntero a variable char en la que cargar la cadena validada.
 * @return 0 si tuvo exito, y -1 si no.
 */
int getCadena(char*, int);

/**
 * Funcion que permite validar que cada posicion de la cadena sea letra.
 * @param Cadena a analizar
 * @return 0 si todas las posiciones son letras, y -1 si no.
 */
int isCharString(char[]);

int isChar(char caracter);

/**
 * Funcion que permite validar que lo ingresado sea un numero flotante
 * @param Puntero a la variable float a cargar el numero validado.
 * @param Numero de reintentos
 * @param Mensaje
 * @param Mensaje de error
 * @param Minimo numero a ingresar
 * @param Maximo numero a ingresar
 * @return 0 si tuvo exito, y -1 si no.
 */
int utn_getFlotante(float*, int, char*, char*, float, float);

/**
 * Funcion que permite obtener una cadena mediante getCadena y valida mediante isFLoat. Pasa la cadena validada a flotante.
 * @param Puntero a flotante donde escribir el resultado de la validacion.
 * @return 0 si tuvo exito, -1 si no.
 */
int getFloat(float*);

/**
 *Funcion que permite validar que lo ingresado sea un numero flotante. Cuenta los puntos (que sea solo uno) y valida todas las posiciones de la cadena.
 * @param Cadena a cargar el numero flotante resultando de la validacion.
 * @return Retorna 0 si la cadena es de numeros y un solo punto (o sin punto), -1 si no.
 */
int isFloat(char*);

/**
 * Funcion que permite validar que lo ingresado sea un numero entero.
 * @param Puntero a entero donde cargar lo validado.
 * @param Cantidad de reintentos
 * @param Mensaje
 * @param Mensaje de error
 * @param Minimo numero a ingresar
 * @param Maximo numero a ingresar
 * @return
 */
int utn_getEntero(int*, int, char*, char*, int, int);

int utn_getEnteroSinRango(int* pEntero, int reintentos, char* mensaje, char*mensajeError);
/**
 * Funcion que permite llamar a getInt y a isCadena para validar que lo ingresado es un numero entero y pasa la cadena a integer.
 * @param Puntero a variable a cargar el numero validado.
 * @return Retorna 0 si logra validar, o -1 si no.
 */
int getInt(int*);

/**
 * Funcion que permite recorrer la cadena validando que cada posicion sea un numero (0 - 9)
 * @param Cadena a cargar el numero validado
 * @return Retorna 0 si logra validar, o -1 si no.
 */
int isInt(char*);

#endif /* UTN_H_ */
