/*
 * inputs.h
 *
 *  Created on: 26 may. 2022
 *      Author: Santiago
 */

#ifndef INPUTS_H_
#define INPUTS_H_

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define T 6
#define TAM 100
#define SIZE 6
#define T1 6
#define S1 2
#define LIBRE 0
#define OCUPADO 1

/// @brief Pide el ingreso de un numero entero.
/// @return Retorna el numero ingresado.
int PedirEntero();

/// @brief Pide el ingreso de un numero flotante.
/// @return Retorna el numero ingresado.
float PedirFlotante();

/// @brief Pide el ingreso de una cadena de caracteres.
/// @param cadenaCaracteres Recibe una cadena de caracteres.
void PedirCadenaDeCaracteres(char cadenaCaracteres[]);

/// @brief Pide el nombre de un cliente.
/// @param cadenaCaracteres Recibe una cadena de caracteres.
void PedirNombreCliente(char cadenaCaracteres[]);

/// @brief Pide el dia de una fecha.
/// @return Retorna el numero ingresado.
int PedirDia();

/// @brief Pide el mes de una fecha.
/// @return Retorna el numero ingresado.
int PedirMes();

/// @brief Pide el año de una fecha.
/// @return Retorna el numero ingresado.
int PedirAnio();

/// @brief Despliega el menu de los listados disponibles, y pide que se elija uno.
/// @return Retorna el numero elegido para la opcion correspondiente.
int MenuListados();

/// @brief Despliega el menu principal y pide que se elija una opcion.
/// @return Retorna el numero elegido para la opcion correspondiente.
int MenuPrincipal();

#endif /* INPUTS_H_ */
