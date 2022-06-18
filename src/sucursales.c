/*
 * sucursales.c
 *
 *  Created on: 15 jun. 2022
 *      Author: Santiago
 */

#include "sucursales.h"

void MostrarUnaSucursal(eSucursal unaSucursal)
{
	printf("\n\n%d - %s - %d - %d", unaSucursal.idSucursal, unaSucursal.nombreSucursal, unaSucursal.cantidadMaximaDeServicios, unaSucursal.cantidadDeServiciosQueOpera);
}

void MostrarListaSucursales(eSucursal listaSucursales[], int sizeSucursales)
{
	for(int i=0; i<sizeSucursales; i++)
	{
		MostrarUnaSucursal(listaSucursales[i]);
	}
}




