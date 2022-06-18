/*
 * servicios.c
 *
 *  Created on: 27 may. 2022
 *      Author: Santiago
 */

#include "servicios.h"

int ObtenerID()
{
	static int idAutoIncremental = 1;
	return idAutoIncremental++;
}

eServicio CargarServicio()
{
	eServicio unServicio;

	unServicio.idServicio = ObtenerID();
	PedirNombreCliente(unServicio.nombreCliente);
	printf("< Ingrese una fecha: >");
	unServicio.fecha.dia = PedirDia();
	unServicio.fecha.mes = PedirMes();
	unServicio.fecha.anio = PedirAnio();

	unServicio.idDiagnostico = -1;
	unServicio.estado = OCUPADO;

	return unServicio;
}

int BuscarEspacio(eServicio listaServicios[], int sizeServicios)
{
	int index = -1;

	for(int i = 0; i < sizeServicios; i++)
	{
		if(listaServicios[i].estado == LIBRE)
	    {
			index = i;
	        break;
	    }
	}

	return index;
}

int CargarListaServicios(eServicio listaServicios[], int sizeServicios)
{
	int index;

	index = BuscarEspacio(listaServicios, sizeServicios);
	if(index != -1)
	{
		listaServicios[index] = CargarServicio();
	}

	return index;
}

void MostrarUnServicio(eServicio unServicio)
{
	if(unServicio.idDiagnostico == -1)
	{
		printf("\n%d - %s - %d/%d/%d", unServicio.idServicio,
				unServicio.nombreCliente, unServicio.fecha.dia,
				unServicio.fecha.mes, unServicio.fecha.anio);
	}
	else
	{
		printf("\n%d - %s - %d/%d/%d - %d", unServicio.idServicio,
				unServicio.nombreCliente, unServicio.fecha.dia,
				unServicio.fecha.mes, unServicio.fecha.anio, unServicio.idDiagnostico);
	}

}

void MostrarListaServicios(eServicio listaServicios[], int sizeServicios)
{
	for(int i=0; i<sizeServicios; i++)
	{
		if(listaServicios[i].estado == OCUPADO)
		{
			MostrarUnServicio(listaServicios[i]);
		}
	}
}

void InicializarServicio(eServicio listaServicios[], int sizeServicios)
{
	int index;

	index = BuscarEspacio(listaServicios, sizeServicios);
	for(int i=0; i<sizeServicios; i++)
	{
		if(index != -1)
		{
			listaServicios[i].estado = LIBRE;
		}
	}
}

int EliminarServicio(eServicio listaServicios[], int sizeServicios)
{
	int index = -1;
	int idIngresado;

	MostrarListaServicios(listaServicios, TAM);

	printf("\nIngresar el ID del servicio a cancelar: ");
	idIngresado = PedirEntero();

	for(int i=0; i<sizeServicios; i++)
	{
		if(idIngresado == listaServicios[i].idServicio && listaServicios[i].estado == OCUPADO)
		{
			listaServicios[i].estado = LIBRE;
			listaServicios[i].idDiagnostico = -1;
			index = 1;
			break;
		}
	}

	return index;
}

void ServiciosOrdenadosPorFecha(eServicio listaServicios[], int sizeServicios)
{
	eServicio auxiliar;

	for(int i=0; i<sizeServicios; i++)
	{
		for(int j=i+1; j<sizeServicios; j++)
		{
			if(listaServicios[i].fecha.anio > listaServicios[j].fecha.anio)
			{
				auxiliar = listaServicios[i];
				listaServicios[i] = listaServicios[j];
				listaServicios[j] = auxiliar;
			}
			else
			{
				if(listaServicios[i].fecha.mes > listaServicios[j].fecha.mes)
				{
					auxiliar = listaServicios[i];
					listaServicios[i] = listaServicios[j];
					listaServicios[j] = auxiliar;
				}
				else
				{
					if(listaServicios[i].fecha.dia > listaServicios[j].fecha.dia)
					{
						auxiliar = listaServicios[i];
						listaServicios[i] = listaServicios[j];
						listaServicios[j] = auxiliar;
					}
				}
			}
		}
	}

	MostrarListaServicios(listaServicios, sizeServicios);
}

void CotizacionesEnFechaDeterminada(eServicio listaServicios[], int sizeServicios)
{
	int diaAux;
	int mesAux;
	int anioAux;
	float SumaCotizaciones = 0;

	printf("Ingrese la fecha de la cual desea conocer el dinero ingresado en concepto de ""cambio de aceite"" para tal dia: ");
	diaAux = PedirDia();
	mesAux = PedirMes();
	anioAux = PedirAnio();

	for(int i=0; i<sizeServicios; i++)
	{
		if(anioAux == listaServicios[i].fecha.anio && mesAux == listaServicios[i].fecha.mes && diaAux == listaServicios[i].fecha.dia)
		{
			if(listaServicios[i].idDiagnostico == 1)
			{
				SumaCotizaciones += listaServicios[i].precioServicio;
			}
		}
	}

	printf("El dinero ingresado en concepto de cambio de aceite en el dia %d/%d/%d fue: %.2f", diaAux, mesAux, anioAux, SumaCotizaciones);
}

void MostrarServiciosNoDiagnosticados(eServicio listaServicios[], int sizeServicios)
{
	for(int i=0; i<sizeServicios; i++)
	{
		if(listaServicios[i].idDiagnostico == -1)
		{
			MostrarUnServicio(listaServicios[i]);
		}
	}
}













