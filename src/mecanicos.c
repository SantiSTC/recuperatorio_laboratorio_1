/*
 * mecanicos.c
 *
 *  Created on: 26 may. 2022
 *      Author: Santiago
 */

#include "mecanicos.h"

void MostrarUnMecanico(sMecanico unMecanico)
{
	printf("\n%d - %s - %d", unMecanico.idMecanico, unMecanico.nombreMecanico, unMecanico.idEspecialidad);
}

void MostrarListaMecanicos(sMecanico listaMecanicos[], int sizeMecanicos)
{
	for(int i=0; i<sizeMecanicos; i++)
	{
		MostrarUnMecanico(listaMecanicos[i]);
	}
}

void MostrarMecanicosDesocupados(sMecanico listaMecanicos[], int sizeMecanico)
{
	for(int i=0; i<sizeMecanico; i++)
	{
		if(listaMecanicos[i].estadoMecanico == LIBRE)
		{
			MostrarUnMecanico(listaMecanicos[i]);
		}
	}
}

void MostrarMecanicosOcupados(sMecanico listaMecanicos[], int sizeMecanico)
{
	for(int i=0; i<sizeMecanico; i++)
	{
		if(listaMecanicos[i].estadoMecanico == OCUPADO)
		{
			MostrarUnMecanico(listaMecanicos[i]);
		}
	}
}
















