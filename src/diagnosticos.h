/*
 * diagnosticos.h
 *
 *  Created on: 14 jun. 2022
 *      Author: Santiago
 */

#ifndef DIAGNOSTICOS_H_
#define DIAGNOSTICOS_H_

#include "inputs.h"

typedef struct
{
	int idDiagnostico;//PK
	char tipoDiagnostico[21];
}sDiagnostico;//Estructura punto 2

/// @brief Muestra un diagnostico en concreto.
/// @param unDiagnostico Recibe un diagnostico para mostrar.
void MostrarUnDiagnostico(sDiagnostico unDiagnostico);

/// @brief Muestra la lista de los diagnosticos.
/// @param listaDiagnosticos Recibe la lista de diagnosticos(hardcodeada).
/// @param sizeDiagnosticos Recibe el tamaño de la lista de diagnosticos(SIZE).
void MostrarListaDeDiagnosticos(sDiagnostico listaDiagnosticos[], int sizeDiagnosticos);




#endif /* DIAGNOSTICOS_H_ */
