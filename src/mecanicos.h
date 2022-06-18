/*
 * mecanicos.h
 *
 *  Created on: 26 may. 2022
 *      Author: Santiago
 */

#ifndef MECANICOS_H_
#define MECANICOS_H_

#include "inputs.h"

typedef struct
{
	int idMecanico;//PK
	char nombreMecanico[51];
	int idEspecialidad;
	int estadoMecanico;
	int idSucursal;//FK
}sMecanico;

/// @brief Muestra un mecanico en concreto.
/// @param unMecanico Recibe la informacion de UN mecanico.
void MostrarUnMecanico(sMecanico unMecanico);

/// @brief Muestra la lista de mecanicos.
/// @param listaMecanicos Recibe la lista de mecanicos(hardcodeada).
/// @param sizeMecanicos Recibe el tamaño de la lista de mecanicos(T).
void MostrarListaMecanicos(sMecanico listaMecanicos[], int sizeMecanicos);

/// @brief Muestra los mecanicos a los que NO se les asigno ningun servicio.
/// @param listaMecanicos Recibe la lista de mecanicos(hardcodeada).
/// @param sizeMecanicos Recibe el tamaño de la lista de mecanicos(T).
void MostrarMecanicosDesocupados(sMecanico listaMecanicos[], int sizeMecanico);

/// @brief Muestra los mecanicos a los que SI se les asigno un servicio.
/// @param listaMecanicos Recibe la lista de mecanicos(hardcodeada).
/// @param sizeMecanicos Recibe el tamaño de la lista de mecanicos(T).
void MostrarMecanicosOcupados(sMecanico listaMecanicos[], int sizeMecanico);





#endif /* MECANICOS_H_ */
