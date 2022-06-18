/*
 * Nexo.c
 *
 *  Created on: 26 may. 2022
 *      Author: Santiago
 */

#include "Nexo.h"

int ModificarServicio(eServicio listaServicios[], int sizeServicios, sMecanico listaMecanicos[], int sizeMecanicos)
{
	int index = -1;
	int idIngresado;

	MostrarListaServicios(listaServicios, TAM);

	printf("\nIngresar el ID del servicio a modificar: ");
 	idIngresado = PedirEntero();

	for(int i=0; i<sizeServicios; i++)
	{
		if(idIngresado == listaServicios[i].idServicio && listaServicios[i].estado == OCUPADO)
		{
			int opcion;

			printf("\n¿Que desea modificar? \n1- Nombre del cliente \n2- Fecha del servicio \n3- Mecanico encargado\nElija una opcion: ");
			opcion = PedirEntero();

			switch(opcion)
			{
				case 1:
					PedirNombreCliente(listaServicios[i].nombreCliente);
					index = 1;
					break;
				break;
				case 2:
					printf("Ingrese la nueva fecha(En formato: DD/MM/AAAA): ");
					listaServicios[i].fecha.dia = PedirDia();
					listaServicios[i].fecha.mes = PedirMes();
					listaServicios[i].fecha.anio = PedirAnio();
					index = 1;
					break;
				break;
				case 3:
					if(listaServicios[i].idDiagnostico != -1)
					{
						listaMecanicos[i].estadoMecanico = LIBRE;
						MostrarListaMecanicos(listaMecanicos, sizeMecanicos);

						printf("Ingrese el id del nuevo mecanico encargado: ");
						listaServicios[i].idMecanico = PedirEntero();
						listaMecanicos[i].estadoMecanico = OCUPADO;
						index = 1;
						break;
					}
					else
					{
						printf("|Se debera diagnosticar el servicio antes de poder modificar su mecanico encargado|");
					}
				break;
				case 4:

				break;
			}
		}
	}

	return index;
}

int DiagnosticarServicio(eServicio listaServicios[], int sizeServicios, sMecanico listaMecanicos[], int sizeMecanicos, sDiagnostico listaDiagnosticos[], int sizeDiagnosticos, eSucursal listaSucursales[], int sizeSucursales)
{
	int index = -1;
	int idAuxMecanico;
	int idAuxServicio;
	int idAuxDiagnostico;
	int idAuxSucursal;

	MostrarListaSucursales(listaSucursales, sizeSucursales);

	printf("\nIngrese el ID de la sucursal donde quiere que se haga el servicio: ");
	idAuxSucursal = PedirEntero();

	for(int i=0; i<sizeSucursales; i++)
	{
		if(listaSucursales[i].idSucursal == idAuxSucursal)
		{
			if(listaSucursales[i].cantidadDeServiciosQueOpera < listaSucursales[i].cantidadMaximaDeServicios)
			{
				listaSucursales[i].cantidadDeServiciosQueOpera++;

				MostrarListaMecanicos(listaMecanicos, sizeMecanicos);

				printf("\nIngrese el ID del mecanico que se encargara del servicio: ");
				idAuxMecanico = PedirEntero();

				MostrarServiciosNoDiagnosticados(listaServicios, sizeServicios);

				printf("\nIngrese el ID del servicio a diagnosticar: ");
				fflush(stdin);
				idAuxServicio = PedirEntero();

				for(int k=0; k<sizeServicios; k++)
				{
					if(idAuxServicio == listaServicios[k].idServicio)
					{
						MostrarListaDeDiagnosticos(listaDiagnosticos, sizeDiagnosticos);
						printf("\nElija el diagnostico indicado para el servicio elegido: ");
						fflush(stdin);
						idAuxDiagnostico = PedirEntero();

						listaServicios[k].idMecanico = idAuxMecanico;
						listaServicios[k].idDiagnostico = idAuxDiagnostico;
						listaServicios[k].idSucursal = idAuxSucursal;

						for(int j=0; j<sizeDiagnosticos; j++)
						{
							if(listaServicios[k].idDiagnostico == listaDiagnosticos[j].idDiagnostico)
							{
								listaServicios[k].idDiagnostico = listaDiagnosticos[j].idDiagnostico;
							}
						}

						AsignarOcupadoAMecanico(listaMecanicos, T, idAuxMecanico, idAuxSucursal);

						printf("Ingrese la cotizacion del servicio: $");
						listaServicios[k].precioServicio = PedirFlotante();

						index = 1;
					}
				}
			}
			else
			{
				printf("La sucursal elegida esta saturada de servicios, elija otra.");
			}
		}
	}

	return index;
}

void ListarMecanicosYServiciosDeCadaSucursal(eServicio listaServicios[], int sizeServicios, sMecanico listaMecanicos[], int sizeMecanicos, eSucursal listaSucursales[], int sizeSucursales)
{
	printf("< Listado de Mecanicos y Servicios de cada Sucursal > ");

	for(int i=0; i<sizeSucursales; i++)
	{
		MostrarUnaSucursal(listaSucursales[i]);

		printf("\n| Servicios de la sucursal n°%d |", i+1);
		for(int j=0; j<sizeServicios; j++)
		{
			if(listaServicios[j].idSucursal == listaSucursales[i].idSucursal)
			{
				MostrarUnServicio(listaServicios[j]);
			}
		}
		printf("\n| Mecanicos de la sucursal n°%d |", i+1);
		for(int j=0; j<sizeMecanicos; j++)
		{
			if(listaMecanicos[j].idSucursal == listaSucursales[i].idSucursal)
			{
				MostrarUnMecanico(listaMecanicos[j]);
			}
		}
	}
}

void AsignarOcupadoAMecanico(sMecanico listaMecanicos[], int sizeMecanicos, int idAuxMecanico, int idAuxSucursal)
{
	for(int j=0; j<sizeMecanicos; j++)
	{
		if(listaMecanicos[j].idMecanico == idAuxMecanico)
		{
			listaMecanicos[j].estadoMecanico = OCUPADO;
			listaMecanicos[j].idSucursal = idAuxSucursal;
		}
	}
}

void CalcularCotizacionPromedioPorMecanico(eServicio listaServicios[], int sizeServicios, sMecanico listaMecanicos[], int sizeMecanicos)
{
	int contador;
	float sumaPrecio;
	float promedio;

	for(int i=0; i<sizeMecanicos; i++)
	{
		if(listaMecanicos[i].estadoMecanico == OCUPADO)
		{
			MostrarUnMecanico(listaMecanicos[i]);

			contador = 0;
			sumaPrecio = 0;

			for(int j=0; j<sizeServicios; j++)
			{
				if(listaMecanicos[i].idMecanico == listaServicios[j].idMecanico)
				{
					sumaPrecio += listaServicios[j].precioServicio;
					contador++;
					promedio = sumaPrecio / contador;
				}
			}
			printf("Promedio: %.2f \n\n", promedio);
		}
	}
}

void MecanicosConMasDiagnosticos(eServicio listaServicios[], int sizeServicios, sMecanico listaMecanicos[], int sizeMecanicos)
{
	int idMecanicoConMasServicios;
	int cantidadServiciosMayor;
	int contadorServicios;
	int flag = 0;

	for(int i=0; i<sizeMecanicos; i++)
	{
		if(listaMecanicos[i].estadoMecanico == OCUPADO)
		{
			contadorServicios = 0;

			for(int j=0; j<sizeServicios; j++)
			{
				if(listaServicios[j].idDiagnostico != -1)
				{
					if(listaServicios[j].idMecanico == listaMecanicos[i].idMecanico)
					{
						contadorServicios ++;
					}
				}
				if(flag == 0)
				{
					idMecanicoConMasServicios = listaMecanicos[0].idMecanico;
					cantidadServiciosMayor = contadorServicios;
					flag = 1;
				}
				else
				{
					if(contadorServicios > cantidadServiciosMayor)
					{
						cantidadServiciosMayor = contadorServicios;
						idMecanicoConMasServicios = listaMecanicos[i].idMecanico;
					}
				}
			}
		}
	}

	for(int i=0; i<sizeMecanicos; i++)
	{
		if(listaMecanicos[i].idMecanico == idMecanicoConMasServicios)
		{
			printf("\n< Mecanico con mas diagnosticos: > \n");
			MostrarUnMecanico(listaMecanicos[i]);
		}
	}
}

void OrdenarListadosAlfabeticamentePorEspecialidadDelMecanico(eServicio listaServicios[], int sizeServicios, sMecanico listaMecanicos[], int sizeMecanicos, sEspecialidad listaEspecialidades[], int sizeEspecialidad)
{
	OrdenarMecanicosAlfabeticamentePorEspecialidad(listaMecanicos, sizeMecanicos, listaEspecialidades, sizeEspecialidad);

	printf("\n< Servicios ordenados alfabeticamente por la especialidad del mecanico encargado >\n");

	for(int i=0; i<sizeMecanicos; i++)
	{
		for(int j=0; j<sizeServicios; j++)
		{
			if(listaServicios[j].idMecanico == listaMecanicos[i].idMecanico)
			{
				MostrarUnServicio(listaServicios[j]);
			}
		}
	}
	printf("\n");
}

void ListadoDeServiciosEntreMarzoYMayo2022(eServicio listaServicios[], int sizeServicios, sDiagnostico listaDiagnosticos[], int sizeDiagnosticos)
{
	int especialidadElegida;

	printf("\nElija la especialidad de los diagnosticos a listar (Entre Marzo y Mayo de 2022): ");
	MostrarListaDeDiagnosticos(listaDiagnosticos, sizeDiagnosticos);
	printf("Ingrese una opcion: ");
	especialidadElegida = PedirEntero();

	for(int i=0; i<sizeServicios; i++)
	{
		if(listaServicios[i].fecha.anio == 2022 && listaServicios[i].fecha.mes >= 3 && listaServicios[i].fecha.mes <= 5)
		{
			if(listaServicios[i].idDiagnostico == especialidadElegida)
			{
				printf("Servicios diagnosticados para la especialidad elegida entre Marzo y Mayo de 2022: ");
				MostrarUnServicio(listaServicios[i]);
				printf("\n");
				break;
			}
			else
			{
				printf("No se han encontrado servicios con esta especialidad en las fechas determinadas.");
				break;
			}
		}
		else
		{
			printf("No se han encontrado servicios con esta especialidad en las fechas determinadas.");
			break;
		}
	}
}

void CalcularPorcentajeDeDiagnosticosPorMecanico(eServicio listaServicios[], int sizeServicios, sMecanico listaMecanicos[], int sizeMecanicos)
{
	int contadorDiagnosticosTotales = 0;
	int contadorDiagnosticosPorMecanico;
	float porcentaje = 0;

	for(int i=0; i<sizeServicios; i++)
	{
		if(listaServicios[i].idDiagnostico != -1  && listaServicios[i].estado == OCUPADO)
		{
			contadorDiagnosticosTotales++;
		}
	}

	for(int i=0; i<sizeMecanicos; i++)
	{
		if(listaMecanicos[i].estadoMecanico == OCUPADO)
		{
			MostrarUnMecanico(listaMecanicos[i]);

			contadorDiagnosticosPorMecanico = 0;

			for(int j=0; j<sizeServicios; j++)
			{
				if(listaMecanicos[i].idMecanico == listaServicios[j].idMecanico && listaServicios[i].idDiagnostico != -1)
				{
					contadorDiagnosticosPorMecanico++;

					porcentaje = (contadorDiagnosticosPorMecanico * 100) / contadorDiagnosticosTotales;
				}
			}

			printf("Porcentaje de diagnosticos: %.2f \n", porcentaje);
		}
	}
}

int ListarServicios(eServicio listaServicios[], int sizeServicios, sMecanico listaMecanicos[], int sizeMecanicos, sDiagnostico listaDiagnosticos[], int sizeDiagnosticos, sAuxiliar listaAuxiliar[], int sizeAuxiliar, sEspecialidad listaEspecialidades[], int sizeEspecialidades, eSucursal listaSucursales[], int sizeSucursales)
{
	int opcionListados;
	int index = -1;

	opcionListados = MenuListados();

	switch(opcionListados)
	{
		case 1:
			MostrarListaMecanicos(listaMecanicos, sizeMecanicos);
			index = 1;
		break;
		case 2:
			MostrarListaServicios(listaServicios, sizeServicios);
			index = 1;
		break;
		case 3:
			MostrarMecanicosDesocupados(listaMecanicos, sizeMecanicos);
			index = 1;
		break;
		case 4:
			ServiciosOrdenadosPorFecha(listaServicios, sizeServicios);
			index = 1;
		break;
		case 5:
			CotizacionesEnFechaDeterminada(listaServicios, sizeServicios);
			index = 1;
		break;
		case 6:
			CalcularCotizacionPromedioPorMecanico(listaServicios, sizeServicios, listaMecanicos, sizeMecanicos);
			index = 1;
		break;
		case 7:
			MecanicosConMasDiagnosticos(listaServicios, sizeServicios, listaMecanicos, sizeMecanicos);
			index = 1;
		break;
		case 8:
			OrdenarListadosAlfabeticamentePorEspecialidadDelMecanico(listaServicios, sizeServicios, listaMecanicos, sizeMecanicos, listaEspecialidades, sizeEspecialidades);
			index = 1;
		break;
		case 9:
			ListadoDeServiciosEntreMarzoYMayo2022(listaServicios, sizeServicios, listaDiagnosticos, sizeDiagnosticos);
			index = 1;
		break;
		case 10:
			CalcularPorcentajeDeDiagnosticosPorMecanico(listaServicios, sizeServicios, listaMecanicos, sizeMecanicos);
			index = 1;
		break;
		case 11:
			CalcularTop3DesperfectosMasDiagnosticados(listaServicios, sizeServicios, listaDiagnosticos, sizeDiagnosticos, listaAuxiliar, sizeAuxiliar);
			index = 1;
		break;
		case 12:
			CalcularTop3EspecialidadesMasEstudiadas(listaEspecialidades, sizeEspecialidades, listaMecanicos, sizeMecanicos, listaAuxiliar, sizeAuxiliar);
			index = 1;
		break;
		case 13:
			ListarMecanicosYServiciosDeCadaSucursal(listaServicios, sizeServicios, listaMecanicos, sizeMecanicos, listaSucursales, sizeSucursales);
			index = 1;
		break;
	}

	return index;
}

void CalcularTop3DesperfectosMasDiagnosticados(eServicio listaServicios[], int sizeServicios, sDiagnostico listaDiagnosticos[], int sizeDiagnosticos, sAuxiliar listaAuxiliar[], int sizeAuxiliar)
{
	int maximo;
	sAuxiliar aux;
	int contador = 0;

	for(int i=0; i<sizeDiagnosticos; i++)
	{
		listaAuxiliar[i].id = listaDiagnosticos[i].idDiagnostico;
		listaAuxiliar[i].contador = 0;
	}

	for(int i=0; i<sizeDiagnosticos; i++)
	{
		for(int j=0; j<sizeServicios; j++)
		{
			if(listaServicios[j].idDiagnostico == listaAuxiliar[i].id)
			{
				listaAuxiliar[i].contador++;
			}
		}
	}

	for(int i=0; i<sizeDiagnosticos; i++)
	{
		if(i == 0 || listaAuxiliar[i].contador > maximo)
		{
			maximo = listaAuxiliar[i].contador;
		}
	}

	for(int i=0; i < sizeAuxiliar; i++)
	{
		for(int j=i+1; j<sizeAuxiliar; j++)
		{
			if(listaAuxiliar[i].contador < listaAuxiliar[j].contador)
			{
				aux = listaAuxiliar[i];
				listaAuxiliar[i] = listaAuxiliar[j];
				listaAuxiliar[j] = aux;
			}
		}
	}
	printf("< TOP 3 desperfectos mas diagnosticados >\n");
	printf("ID - Desperfecto - Veces diagnosticado\n");
	for(int i=0; i<sizeAuxiliar; i++)
	{
		for(int j=0; j<sizeDiagnosticos; j++)
		{
			if(listaAuxiliar[i].id == listaDiagnosticos[j].idDiagnostico)
			{
				contador++;

				if(contador <= 3)
				{
					printf("%d  - %s - %d\n", listaDiagnosticos[j].idDiagnostico, listaDiagnosticos[j].tipoDiagnostico, listaAuxiliar[i].contador);
				}
			}
		}
	}
}

void CalcularTop3EspecialidadesMasEstudiadas(sEspecialidad listaEspecialidades[], int sizeEspecialidades, sMecanico listaMecanicos[], int sizeMecanicos, sAuxiliar listaAuxiliar[], int sizeAuxiliar)
{
	int maximo;
	sAuxiliar aux;
	int contador = 0;

	for(int i=0; i<sizeEspecialidades; i++)
	{
		listaAuxiliar[i].id = listaEspecialidades[i].idEspecialidad;
		listaAuxiliar[i].contador = 0;
	}

	for(int i=0; i<sizeEspecialidades; i++)
	{
		for(int j=0; j<sizeMecanicos; j++)
		{
			if(listaMecanicos[j].idEspecialidad == listaAuxiliar[i].id)
			{
				listaAuxiliar[i].contador++;
			}
		}
	}

	for(int i=0; i<sizeMecanicos; i++)
	{
		if(i == 0 || listaAuxiliar[i].contador > maximo)
		{
			maximo = listaAuxiliar[i].contador;
		}
	}

	for(int i=0; i < sizeAuxiliar; i++)
	{
		for(int j=i+1; j<sizeAuxiliar; j++)
		{
			if(listaAuxiliar[i].contador < listaAuxiliar[j].contador)
			{
				aux = listaAuxiliar[i];
				listaAuxiliar[i] = listaAuxiliar[j];
				listaAuxiliar[j] = aux;
			}
		}
	}

	printf("< TOP 3 especialidades mas estudiadas >\n");
	printf("ID - Especialidad - Veces estudiada\n");

	for(int i=0; i<sizeAuxiliar; i++)
	{
		for(int j=0; j<sizeEspecialidades; j++)
		{
			if(listaAuxiliar[i].id == listaEspecialidades[j].idEspecialidad)
			{
				contador++;
				if(contador <= 3)
				{
					printf("%d  - %s - %d\n", listaEspecialidades[j].idEspecialidad, listaEspecialidades[j].descripcionEspecialidad, listaAuxiliar[i].contador);
				}
			}
		}
	}
}

void OrdenarMecanicosAlfabeticamentePorEspecialidad(sMecanico listaMecanicos[], int sizeMecanicos, sEspecialidad listaEspecialidades[], int sizeEspecialidad)
{
	sMecanico auxiliar;

	OrdenarEspecialidadesAlfabeticamente(listaEspecialidades, sizeEspecialidad);

	for(int i=0; i<sizeEspecialidad; i++)
	{
		for(int j=0; j<sizeMecanicos; j++)
		{
			if(listaEspecialidades[i].idEspecialidad == listaMecanicos[j].idEspecialidad)
			{
				auxiliar = listaMecanicos[i];
				listaMecanicos[i] = listaMecanicos[j];
				listaMecanicos[j] = auxiliar;
			}
		}
	}
}




