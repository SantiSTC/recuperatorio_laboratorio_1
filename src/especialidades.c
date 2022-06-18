/*
 * especialidades.c
 *
 *  Created on: 14 jun. 2022
 *      Author: Santiago
 */

#include "especialidades.h"

void OrdenarEspecialidadesAlfabeticamente(sEspecialidad listaEspecialidades[], int sizeEspecialidad)
{
	sEspecialidad auxiliar;

	for(int i=0; i<sizeEspecialidad; i++)
	{
		for(int j=i+1; j<sizeEspecialidad; j++)
		{
			if(strcmp(listaEspecialidades[i].descripcionEspecialidad, listaEspecialidades[j].descripcionEspecialidad)>0)
			{
				auxiliar = listaEspecialidades[i];
				listaEspecialidades[i] = listaEspecialidades[j];
				listaEspecialidades[j] = auxiliar;
			}
		}
	}
}
