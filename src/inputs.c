/*
 * inputs.c
 *
 *  Created on: 26 may. 2022
 *      Author: Santiago
 */

#include "inputs.h"

int PedirEntero()
{
	int unEntero;

	scanf("%d", &unEntero);

	while(isdigit(unEntero) != 0)
	{
		printf("ERROR, debe ingresar un numero\n");
		fflush(stdin);
		scanf("%d", &unEntero);
	}

	return unEntero;
}

float PedirFlotante()
{
	float unFlotante;

	scanf("%f", &unFlotante);
	while(isdigit(unFlotante) != 0)
	{
		printf("ERROR, debe ingresar un numero\n");
		fflush(stdin);
		scanf("%f", &unFlotante);
	}

	return unFlotante;
}

void PedirCadenaDeCaracteres(char cadenaCaracteres[])
{
	fflush(stdin);
	gets(cadenaCaracteres);
}

void PedirNombreCliente(char cadenaCaracteres[])
{
	printf("Ingrese el nombre del cliente: ");
	PedirCadenaDeCaracteres(cadenaCaracteres);
}

int PedirDia()
{
	int dia;

		printf("\nIngrese el dia: ");
		dia = PedirEntero();
		while(dia < 1 && dia > 31)
		{
			printf("\nERROR, Ingrese un dia valido: ");
			dia = PedirEntero();
		}

	return dia;
}

int PedirMes()
{
	int mes;

	printf("\nIngrese el mes: ");
	mes = PedirEntero();
	while(mes < 1 && mes > 12)
	{
		printf("\nERROR, Ingrese un mes valido: ");
		mes = PedirEntero();
	}

	return mes;
}

int PedirAnio()
{
	int anio;

	printf("\nIngrese el a�o: ");
	anio = PedirEntero();
	while(anio < 0 && anio > 10000)
	{
		printf("\nERROR, Ingrese un a�o valido: ");
		anio = PedirEntero();
	}

	return anio;
}

int MenuListados()
{
	int opcion;

	printf("\n1- Todos los mec�nicos."
			"\n2- Todos los servicios. "
			"\n3- Todos los mec�nicos a los cuales no se les haya asignado ning�n servicio"
			"\n4- Listado de servicios ordenados por fecha, desde el m�s antiguo hasta el m�s reciente. "
			"\n5- Para una fecha determinada se necesita saber cu�l fue la suma de cotizaciones en concepto de cambio de aceite. "
			"\n6- Cotizaci�n promedio de cada uno de los mec�nicos."
			"\n7- Determinar cu�l/cu�les son los mec�nicos que diagnosticaron m�s servicios. "
			"\n8- Listado de servicios ordenados por especialidad del mec�nico alfab�ticamente "
			"\n9- Listado de todos los servicios entre el mes de Marzo y Mayo del 2022 para una especialidad determinada."
			"\n10- Porcentaje de servicio diagnosticados que atiende cada mec�nico en funci�n del total de diagn�sticos."
			"\n11- Top 3 desperfectos mas diagnosticados."
			"\n12- Top 3 especialidades mas estudiadas por mecanicos."
			"\n13- Listar servicios y mecanicos de cada sucursal. \n"
			"Elija una opcion: ");
	opcion = PedirEntero();

	return opcion;
}

int MenuPrincipal()
{
	int opcion;

	printf("\n< Men� >\n1- Alta de Servicio "
			"\n2- Modificar Servicio "
			"\n3- Cancelar Servicio "
			"\n4- Diagnosticar "
			"\n5- Listar "
			"\n6- Salir "
			"\nDigite una opcion: ");
	opcion = PedirEntero();

	return opcion;
}


