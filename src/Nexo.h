/*
 * Nexo.h
 *
 *  Created on: 26 may. 2022
 *      Author: Santiago
 */

#ifndef NEXO_H_
#define NEXO_H_

#include "inputs.h"
#include "servicios.h"
#include "mecanicos.h"
#include "diagnosticos.h"
#include "especialidades.h"
#include "sucursales.h"//Estructura inventada(Recuperatorio)

typedef struct
{
	int id;
	int contador;
}sAuxiliar;

/// @brief Permite modificar el nombre, la fecha o el mecanico encargado de cada uno de los servicios ingresados.
/// @param listaServicios Recibe la lista de servicios que cargó el usuario.
/// @param sizeServicios Recibe el tamaño de la lista de servicios(TAM).
/// @param listaMecanicos Recibe la lista de mecanicos(hardcodeada).
/// @param sizeMecanicos Recibe el tamaño de la lista de mecanicos(T).
/// @return Retorna -1 o 1 para corroborar que pudo funcionar correctamente e informarlo al usuario.
int ModificarServicio(eServicio listaServicios[], int sizeServicios, sMecanico listaMecanicos[], int sizeMecanicos);

/// @brief Permite asignar un diagnostico a cada uno de los servicios ingresados, ademas se le asigna la cotizacion a este mismo.
/// @param listaServicios Recibe la lista de servicios que cargó el usuario.
/// @param sizeServicios Recibe el tamaño de la lista de servicios(TAM).
/// @param listaMecanicos Recibe la lista de mecanicos(hardcodeada).
/// @param sizeMecanicos Recibe el tamaño de la lista de mecanicos(T).
/// @param listaDiagnosticos Recibe la lista de diagnosticos(hardcodeada).
/// @param sizeDiagnosticos Recibe el tamaño de la lista de diagnosticos(SIZE).
/// @return Retorna -1 o 1 para corroborar que pudo funcionar correctamente e informarlo al usuario.
int DiagnosticarServicio(eServicio listaServicios[], int sizeServicios, sMecanico listaMecanicos[], int sizeMecanicos, sDiagnostico listaDiagnosticos[], int sizeDiagnosticos, eSucursal listaSucursales[], int sizeSucursales);

/// @brief Cambia el estado de un mecanico a OCUPADO.
/// @param listaMecanicos Recibe la lista de mecanicos(hardcodeada).
/// @param sizeMecanicos Recibe el tamaño de la lista de mecanicos(T).
/// @param idAuxMecanico Recibe un ID ingresado por el usuario que indica el ID del mecanico sobre el que se hará la modificacion.
void AsignarOcupadoAMecanico(sMecanico listaMecanicos[], int sizeMecanicos, int idAuxMecanico, int idAuxSucursal);

/// @brief Permite calcular el dinero promedio que le ha ingresado a cada mecanico.
/// @param listaServicios Recibe la lista de servicios que cargó el usuario.
/// @param sizeServicios Recibe el tamaño de la lista de servicios(TAM).
/// @param listaMecanicos Recibe la lista de mecanicos(hardcodeada).
/// @param sizeMecanicos Recibe el tamaño de la lista de mecanicos(T).
void CalcularCotizacionPromedioPorMecanico(eServicio listaServicios[], int sizeServicios, sMecanico listaMecanicos[], int sizeMecanicos);

/// @brief Muestra al mecanico que mas diagnosticos tiene asignados.
/// @param listaServicios Recibe la lista de servicios que cargó el usuario.
/// @param sizeServicios Recibe el tamaño de la lista de servicios(TAM).
/// @param listaMecanicos Recibe la lista de mecanicos(hardcodeada).
/// @param sizeMecanicos Recibe el tamaño de la lista de mecanicos(T).
void MecanicosConMasDiagnosticos(eServicio listaServicios[], int sizeServicios, sMecanico listaMecanicos[], int sizeMecanicos);

/// @brief Ordena la lista de servicios, alfabeticamente, segun la especialidad del mecanico encargado.
/// @param listaServicios Recibe la lista de servicios que cargó el usuario.
/// @param sizeServicios Recibe el tamaño de la lista de servicios(TAM).
/// @param listaMecanicos Recibe la lista de mecanicos(hardcodeada).
/// @param sizeMecanicos Recibe el tamaño de la lista de mecanicos(T).
void OrdenarListadosAlfabeticamentePorEspecialidadDelMecanico(eServicio listaServicios[], int sizeServicios, sMecanico listaMecanicos[], int sizeMecanicos, sEspecialidad listaEspecialidades[], int sizeEspecialidad);

/// @brief Muestra una lista de los servicios con fechas entre Marzo y Mayo de 2022, para una especialidad determinada(ingresada por el usuario).
/// @param listaServicios Recibe la lista de servicios que cargó el usuario.
/// @param sizeServicios Recibe el tamaño de la lista de servicios(TAM).
/// @param listaDiagnosticos Recibe la lista de diagnosticos(hardcodeada).
/// @param sizeDiagnosticos Recibe el tamaño de la lista de diagnosticos(SIZE).
void ListadoDeServiciosEntreMarzoYMayo2022(eServicio listaServicios[], int sizeServicios, sDiagnostico listaDiagnosticos[], int sizeDiagnosticos);

/// @brief Calcula el porcentaje de diagnosticos que atendió cada mecanico en funcion al total de servicios diagnosticados.
/// @param listaServicios Recibe la lista de servicios que cargó el usuario.
/// @param sizeServicios Recibe el tamaño de la lista de servicios(TAM).
/// @param listaMecanicos Recibe la lista de mecanicos(hardcodeada).
/// @param sizeMecanicos Recibe el tamaño de la lista de mecanicos(T).
void CalcularPorcentajeDeDiagnosticosPorMecanico(eServicio listaServicios[], int sizeServicios, sMecanico listaMecanicos[], int sizeMecanicos);

/// @brief Permite ingresar a los listados, mostrando las 10 opciones disponibles.
/// @param listaServicios Recibe la lista de servicios que cargó el usuario.
/// @param sizeServicios Recibe el tamaño de la lista de servicios(TAM).
/// @param listaMecanicos Recibe la lista de mecanicos(hardcodeada).
/// @param sizeMecanicos Recibe el tamaño de la lista de mecanicos(T).
/// @return Retorna -1 o 1 para corroborar que pudo funcionar correctamente e informarlo al usuario.
int ListarServicios(eServicio listaServicios[], int sizeServicios, sMecanico listaMecanicos[], int sizeMecanicos, sDiagnostico listaDiagnosticos[], int sizeDiagnosticos, sAuxiliar listaAuxiliar[], int sizeAuxiliar, sEspecialidad listaEspecialidades[], int sizeEspecialidades, eSucursal listaSucursales[], int sizeSucursales);

/// @brief Calcula los 3 desperfectos mas elegidos a la hora de diagnosticar.
/// @param listaServicios Recibe la lista de servicios que cargó el usuario.
/// @param sizeServicios Recibe el tamaño de la lista de servicios(TAM).
/// @param listaDiagnosticos Recibe la lista de diagnosticos(hardcodeada).
/// @param sizeDiagnosticos Recibe el tamaño de la lista de diagnosticos(SIZE).
/// @param listaAuxiliar Recibe una lista auxiliar para poder realizar un ordenamiento.
/// @param sizeAuxiliar Recibe el tamaño de la lista auxiliar(SIZE).
void CalcularTop3DesperfectosMasDiagnosticados(eServicio listaServicios[], int sizeServicios, sDiagnostico listaDiagnosticos[], int sizeDiagnosticos, sAuxiliar listaAuxiliar[], int sizeAuxiliar);

/// @brief Calcula las 3 especialidades que mas aparecen entre los mecanicos.
/// @param listaEspecialidades Recibe la lista de especialidades posibles que puede tener un mecanico.
/// @param sizeEspecialidades Recibe el tamaño de la lista de especialidades(T1).
/// @param listaMecanicos Recibe la lista de mecanicos(hardcodeada).
/// @param sizeMecanicos Recibe el tamaño de la lista de mecanicos(T).
/// @param listaAuxiliar Recibe una lista auxiliar para poder realizar un ordenamiento.
/// @param sizeAuxiliar Recibe el tamaño de la lista auxiliar(SIZE).
void CalcularTop3EspecialidadesMasEstudiadas(sEspecialidad listaEspecialidades[], int sizeEspecialidades, sMecanico listaMecanicos[], int sizeMecanicos, sAuxiliar listaAuxiliar[], int sizeAuxiliar);

/// @brief Ordena la lista de mecanicos alfabeticamente, por su especialidad.
/// @param listaMecanicos Recibe la lista de mecanicos(hardcodeada).
/// @param sizeMecanicos Recibe el tamaño de la lista de mecanicos(T).
void OrdenarMecanicosAlfabeticamentePorEspecialidad(sMecanico listaMecanicos[], int sizeMecanicos, sEspecialidad listaEspecialidades[], int sizeEspecialidad);


//Filtro inventado para la esctructura inventada(Recuperatorio)
/// @brief Muestra los mecanicos y servicios que operan en cada sucursal
/// @param listaServicios Recibe la lista de servicios que cargó el usuario.
/// @param sizeServicios Recibe el tamaño de la lista de servicios(TAM).
/// @param listaMecanicos Recibe la lista de mecanicos(hardcodeada).
/// @param sizeMecanicos Recibe el tamaño de la lista de mecanicos(T).
/// @param listaSucursales Recibe la lista de sucursales(hardcodeada).
/// @param sizeSucursales Recibe el tamaño de la lista de sucursales(S1).
void ListarMecanicosYServiciosDeCadaSucursal(eServicio listaServicios[], int sizeServicios, sMecanico listaMecanicos[], int sizeMecanicos, eSucursal listaSucursales[], int sizeSucursales);
#endif /* NEXO_H_ */
