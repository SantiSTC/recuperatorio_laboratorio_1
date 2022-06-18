/*
 ============================================================================
 Name        : Recuperatorio.c
 Author      : Santiago Iannello - 1B
 Version     : Recuperatorio Primer Parcial
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "inputs.h"
#include "Nexo.h"

sMecanico listaMecanicos[T] = {{1,"German", 4, LIBRE},
								{2,"Mariano", 6, LIBRE},
								{3,"Ezequiel", 4, LIBRE},
								{4,"Giovanni", 1, LIBRE},
								{5,"Leonel", 2, LIBRE},
								{6,"Manolo", 4, LIBRE}};

eServicio listaServicios[TAM]; /*= {{1,"a",{1,1,1}, 100, 1, 1, OCUPADO},
								{2,"b",{1,1,1}, 100, 2, 1, OCUPADO},
								{3,"c",{1,1,1}, 100, 1, 3, OCUPADO},
								{4,"d",{1,1,1}, 100, 3, 4, OCUPADO},
								{5,"e",{1,1,1}, 100, 4, 4, OCUPADO},
								{6,"f",{1,1,1}, 100, 1, 4, OCUPADO}};*/
sDiagnostico listaDiagnosticos[SIZE] = {{1,"Cambio de aceite"},
										{2, "Reparacion de motor"},
										{3, "Suspension"},
										{4, "Pintura"},
										{5, "Ruedas"},
										{6, "Cristales"}};
sEspecialidad listaEspecialidades[T1] = {{1,"Cambio de Aceite"},
										{2,"Reparacion de motor"},
										{3,"Suspension"},
										{4, "Pintura"},
										{5, "Ruedas"},
										{6, "Cristales"}};
eSucursal listaSucursales[S1] = {{1, "Primera", 5, 0},
								{2, "Segunda", 3, 0}};

sAuxiliar listaAuxiliar[SIZE];

int cantidadAltas = 0;

int main()
{
	setbuf(stdout, NULL);

	int opcion;
	int retorno;

	InicializarServicio(listaServicios, TAM);

	do
	{
		opcion = MenuPrincipal();

		switch(opcion)
		{
			case 1:
				printf("\n< Alta de servicio >\n");

				retorno = CargarListaServicios(listaServicios, TAM);
				switch(retorno)
				{
					case -1:
						printf("No se ha podido cargar el servicio");
					break;
					default:
						printf("Se ha cargado correctamente el servicio");
						cantidadAltas++;
					break;
				}
			break;
			case 2:
				printf("\n< Modificar Servicio >\n");

				if(cantidadAltas != 0)
				{
					retorno = ModificarServicio(listaServicios, TAM, listaMecanicos, T);
					switch(retorno)
					{
						case -1:
							printf("\nNo se ha podido modificar el servicio \n");
						break;
						default:
							printf("\nSe ha modificado correctamente el servicio \n");
						break;
					}
				}
				else
				{
					printf("Se debera dar de alta por lo menos a un servicio antes acceder a esta funcion. \n");
				}
			break;
			case 3:
				printf("\n< Cancelar Servicio >\n");

				if(cantidadAltas != 0)
				{
					retorno = EliminarServicio(listaServicios, TAM);
					switch(retorno)
					{
						case -1:
							printf("\nNo se ha podido cancelar el servicio \n");
						break;
						default:
							printf("\nSe ha cancelado correctamente el servicio \n");
						break;
					}
				}
				else
				{
					printf("Se debera dar de alta por lo menos a un servicio antes acceder a esta funcion. \n");
				}
			break;
			case 4:
				printf("\n< Diagnosticar Servicio >\n");

				if(cantidadAltas != 0)
				{
					retorno = DiagnosticarServicio(listaServicios, TAM, listaMecanicos, T, listaDiagnosticos, SIZE, listaSucursales, S1);
					switch(retorno)
					{
						case -1:
							printf("\nNo se ha podido diagnosticar el servicio \n");
						break;
						default:
							printf("\nSe ha diagnosticado correctamente el servicio \n");
						break;
					}
				}
				else
				{
					printf("Se debera dar de alta por lo menos a un servicio antes acceder a esta funcion. \n");
				}
			break;
			case 5:
				printf("\n< Listados >\n");

				if(cantidadAltas != 0)
				{
					retorno = ListarServicios(listaServicios, TAM, listaMecanicos, T, listaDiagnosticos, SIZE, listaAuxiliar, SIZE, listaEspecialidades, T1, listaSucursales, S1);
					switch(retorno)
					{
						case -1:
							printf("\nNo se ha podido acceder al listado \n");
						break;
						default:
							printf("\nSe ha accedido correctamente al listado \n");
						break;
					}
				}
				else
				{
					printf("Se debera dar de alta por lo menos a un servicio antes acceder a esta funcion. \n");
				}
			break;
		}

	}while(opcion < 6);


	return 0;
}
