/*
 * servicios.h
 *
 *  Created on: 27 may. 2022
 *      Author: Santiago
 */
#ifndef SERVICIOS_H_
#define SERVICIOS_H_

#include "inputs.h"

typedef struct
{
	int dia;
	int mes;
	int anio;
}sFecha;

typedef struct
{
	int idServicio;
	char nombreCliente[51];
	sFecha fecha;
	float precioServicio;
	int idMecanico;//FK
	int idDiagnostico;//FK
	int estado;
	int idSucursal;//FK
}eServicio;

/// @brief Permite generar un ID autoincremental para cada servicio.
/// @return Retorna el ID generado.
int ObtenerID();

/// @brief Permite la carga de un servicio, obtiene su ID, pide el nombre y la fecha, y marca el espacio como "OCUPADO" en el array.
/// @return El servicio generado.
eServicio CargarServicio();

/// @brief Busca el primer espacio libre dentro del array para crear un nuevo servicio.
/// @param listaServicios Recibe la lista de servicios que cargó el usuario.
/// @param sizeServicios Recibe el tamaño de la lista de servicios(TAM).
/// @return Retorna 1 si encontró el espacio para crear el servicio, -1 si no pudo encontrarlo.
int BuscarEspacio(eServicio listaServicios[], int sizeServicios);

/// @brief Carga un servicio a la lista.
/// @param listaServicios Recibe la lista de servicios que cargó el usuario.
/// @param sizeServicios Recibe el tamaño de la lista de servicios(TAM).
/// @return Retorna 1 si pudo cargar el servicio, -1 si no pudo hacerlo.
int CargarListaServicios(eServicio listaServicios[], int sizeServicios);

/// @brief Permite eliminar un servicio del sistema.
/// @param listaServicios Recibe la lista de servicios que cargó el usuario.
/// @param sizeServicios Recibe el tamaño de la lista de servicios(TAM).
/// @return Retorna -1 o 1 para corroborar que pudo funcionar correctamente e informarlo al usuario.
int EliminarServicio(eServicio listaServicios[], int sizeServicios);

/// @brief
/// @param listaServicios Recibe la lista de servicios que cargó el usuario.
/// @param sizeServicios Recibe el tamaño de la lista de servicios(TAM).
void InicializarServicio(eServicio listaServicios[], int sizeServicios);

/// @brief Muestra la lista de todos los servicios ingresados.
/// @param listaServicios Recibe la lista de servicios que cargó el usuario.
/// @param sizeServicios Recibe el tamaño de la lista de servicios(TAM).
void MostrarListaServicios(eServicio listaServicios[], int sizeServicios);

/// @brief Muestra un servicio en concreto.
/// @param unServicio Recibe un solo servicio para mostrar.
void MostrarUnServicio(eServicio unServicio);

/// @brief Ordena y muestra los servicios ordenados por su fecha.
/// @param listaServicios Recibe la lista de servicios que cargó el usuario.
/// @param sizeServicios Recibe el tamaño de la lista de servicios(TAM).
void ServiciosOrdenadosPorFecha(eServicio listaServicios[], int sizeServicios);

/// @brief Permite ingresar una fecha determinada, y conocer el dinero que ingresó en tal fecha.
/// @param listaServicios Recibe la lista de servicios que cargó el usuario.
/// @param sizeServicios Recibe el tamaño de la lista de servicios(TAM).
void CotizacionesEnFechaDeterminada(eServicio listaServicios[], int sizeServicios);

/// @brief Muestra los servicios que no fueron diagnosticados.
/// @param listaServicios Recibe la lista de servicios que cargó el usuario.
/// @param sizeServicios Recibe el tamaño de la lista de servicios(TAM).
void MostrarServiciosNoDiagnosticados(eServicio listaServicios[], int sizeServicios);

#endif /* SERVICIOS_H_ */
