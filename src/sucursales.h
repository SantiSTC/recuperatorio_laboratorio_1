/*
 * sucursales.h
 *
 *  Created on: 15 jun. 2022
 *      Author: Santiago
 */

#ifndef SUCURSALES_H_
#define SUCURSALES_H_

#include "inputs.h"

typedef struct
{
	int idSucursal;//PK
	char nombreSucursal[21];
	int cantidadMaximaDeServicios;
	int cantidadDeServiciosQueOpera;
}eSucursal;
//estructura inventada(Recuperatorio)

/// @brief  Muestra una sucursal.
/// @param unaSucursal Recibe la informacion de UNA sucursal.
void MostrarUnaSucursal(eSucursal unaSucursal);

/// @brief Muestra la lista de sucursales.
/// @param listaSucursales Recibe la lista de sucursales(hardcodeada).
/// @param sizeSucursales Recibe el tamaño de la lista de sucursales(S1).
void MostrarListaSucursales(eSucursal listaSucursales[], int sizeSucursales);

#endif /* SUCURSALES_H_ */
