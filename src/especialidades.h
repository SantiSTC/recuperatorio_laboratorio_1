/*
 * especialidades.h
 *
 *  Created on: 14 jun. 2022
 *      Author: Santiago
 */

#ifndef ESPECIALIDADES_H_
#define ESPECIALIDADES_H_

#include "inputs.h"

typedef struct
{
	int idEspecialidad;
	char descripcionEspecialidad[21];
}sEspecialidad;//Estructura punto 2

void OrdenarEspecialidadesAlfabeticamente(sEspecialidad listaEspecialidades[], int sizeEspecialidad);

#endif /* ESPECIALIDADES_H_ */
