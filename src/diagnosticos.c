/*
 * diagnosticos.c
 *
 *  Created on: 14 jun. 2022
 *      Author: Santiago
 */

#include "diagnosticos.h"

void MostrarUnDiagnostico(sDiagnostico unDiagnostico)
{
	printf("\n%d - %s \n", unDiagnostico.idDiagnostico, unDiagnostico.tipoDiagnostico);
}


void MostrarListaDeDiagnosticos(sDiagnostico listaDiagnosticos[], int sizeDiagnosticos)
{
	for(int i=0; i<sizeDiagnosticos; i++)
	{
		MostrarUnDiagnostico(listaDiagnosticos[i]);
	}
}
