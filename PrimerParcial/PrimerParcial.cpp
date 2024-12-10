#include "PrimerParcial.h"
#include "PagosArchivo.h"
#include "Pago.h"
#include "EstudiantesArchivo.h"
#include "Estudiante.h"
#include "Estadisticas.h"
#include <iostream>
using namespace std;

void PrimerParcial::listarRecaudacion()
{
	float recaudacion[10] = {};

	PagosArchivo ps;
	int cant = ps.getCantidad();
	Pago* pagos = new Pago[cant];
	ps.leerTodos(pagos, cant);
	for (int i = 0; i < cant; i++)
	{
		if (pagos[i].getFecha().getAnio() > 2020 || (pagos[i].getFecha().getAnio() == 2020 && pagos[i].getFecha().getMes() > 5) || (pagos[i].getFecha().getAnio() == 2020 && pagos[i].getFecha().getMes() == 5 && pagos[i].getFecha().getDia() >= 10))
		{
			recaudacion[pagos[i].getIdCurso() - 1] += pagos[i].getMonto();
		}
	}

	for (int i = 0; i < 10; i++)
	{
		cout << "Curso #" << i + 1 << ": " << recaudacion[i] << endl;
	}
}

void PrimerParcial::listarAlumnosNoMorosos()
{
	// CARGAMOS TODOS LOS ESTUDIANTES//
	EstudiantesArchivo ea;
	int cantidadEstudiantes = ea.getCantidad();
	Estudiante* estudiantes = new Estudiante[cantidadEstudiantes];
	ea.leerTodos(estudiantes, cantidadEstudiantes);


	// CARGAMOS TODOS LOS PAGOS//
	PagosArchivo pa;
	int cantidadPagos = pa.getCantidad();
	Pago* pagos = new Pago[cantidadPagos];
	pa.leerTodos(pagos, cantidadPagos);

	/*     --- CICLOS COMBINADOS --- 
		POR CADA UNO DE LOS ESTUDIANTES, ME FIJO ENTRE TODOS SUS PAGOS,
		A VER SI HUBO UN PAGO DE ESE ESTUDIANTE. 
		SI ESTUDIANTE REALIZO UN PAGO, LO PONGO EN TRUE (LINEA 63). 
		LUEGO ME FIJO SI ESTA VENCIDO. SI ESTA VENCIDO, LO PONGO EN FALSE (LINEA 67)
		POR ULTIMO MUESTRO SI sinVencido ES FALSE (LINEA 74).
	*/

	for (int i = 0; i < cantidadEstudiantes; i++)
	{
		Estudiante e = estudiantes[i];
		bool sinPagos = true;
		bool pago = false;

		for (int j = 0; j < cantidadPagos; j++)
		{
			if (pagos[j].getLegajo() == e.getLegajo())
			{
				pago = true;

				if (pagos[j].esPagoVencido())
				{
					sinPagos = false;
				}
			}
		}
		if (sinPagos && pago)
		{
			cout << e.getLegajo() << endl;
		}
	}
}

void PrimerParcial::soloUnCurso()
{
	EstudiantesArchivo ea;
	int cantidadEstudiantes = ea.getCantidad();
	Estudiante* estudiantes = new Estudiante[cantidadEstudiantes];
	ea.leerTodos(estudiantes, cantidadEstudiantes);

	PagosArchivo pa;
	int cantidadPagos = pa.getCantidad();
	Pago* pagos = new Pago[cantidadPagos];
	pa.leerTodos(pagos, cantidadPagos);

	for (int i = 0; i < cantidadEstudiantes; i++)
	{
		Estudiante e = estudiantes[i];
		int cursos[10] = {};

		for (int j = 0; j < cantidadPagos; j++)
		{
			if (e.getLegajo() == pagos[j].getLegajo() && pagos[j].getAnio() == 2021)
			{
				cursos[pagos[j].getIdCurso() - 1] = 1;
			}
		}
		int cantidad = 0;
		for (int i = 0; i < 10; i++)
		{
			cantidad += cursos[i];
		}

		if (cantidad == 1)
		{
			cout << e.getLegajo() << " " << e.getNombres() << " " << e.getApellidos() << endl;
		}
	}
}

void PrimerParcial::cursosPremium(int legajo)
{
	PagosArchivo pa;
	int cantidadPagos = pa.getCantidad();
	Pago* pagos = new Pago[cantidadPagos];
	pa.leerTodos(pagos, cantidadPagos);

	
	float maximo = 0;

	// BUSCO UN MAXIMO MONTO DE UN LEGAJO.
	for (int i = 0; i < cantidadPagos; i++)
	{
		if (pagos[i].getLegajo() == legajo && pagos[i].getMonto() > maximo) 
		{
			maximo = pagos[i].getMonto();
		}
	}

	//	CREAMOS UN VECTOR DE ENTEROS INICIALIZADO CERO.
	int cursos[10] = {};


	/* 
		BUSCAMOS DE ESE LEGAJO, CUAL ES EL MONTO IGUAL AL MAXIMO.
		CREE EL VECTOR DE 10 ENTEROS PARA EVITAR QUE HAYAN CODIGOS REPETIDOS.
		SI ESTA EN CERO, LO MUESTRO Y LO PONGO EN 1, ENTONCES LA PROXIMA QUE ENCUENTRE CURSO, NO VA A ESTAR 0 Y NO LO VA A MOSTRAR.
	*/

	for (int i = 0; i < cantidadPagos; i++)
	{
		if (pagos[i].getLegajo() == legajo && pagos[i].getMonto() == maximo)
		{
			if (cursos[pagos[i].getIdCurso() - 1] == 0)
			{
				cout << pagos[i].getIdCurso() << endl;
				cursos[pagos[i].getIdCurso() - 1] = 1;
			}
		}
	}

}

void PrimerParcial::generarEstadisticas()
{
	// LEEMOS LOS PAGOS
	PagosArchivo pa;
	int cantidadPagos = pa.getCantidad();
	Pago* pagos = new Pago[cantidadPagos];
	pa.leerTodos(pagos, cantidadPagos);

	int anioMin = 0, anioMax = 0;

	/*
		CREO DOS FOR PARA BUSCAR EL AÑO MINIMO Y MAXIMO ENTRE TODOS LOS PAGOS

	*/

	for (int i = 0; i < cantidadPagos; i++)
	{
		if (i == 0)
		{
			anioMax = anioMin = pagos[i].getFecha().getAnio();
		}

		if (pagos[i].getFecha().getAnio() > anioMax)
		{
			anioMax = pagos[i].getFecha().getAnio();
		}

		if (pagos[i].getFecha().getAnio() < anioMin)
		{
			anioMin = pagos[i].getFecha().getAnio();
		}
	}

	// CREAMOS UN VECTOR DE ESTADISTICAS
	Estadisticas* anios = new Estadisticas[anioMax - anioMin + 1]; // AGREGAMOS +1 PORQUE ESTAN INCLUIDOS EL PRIMERO Y EL ULTIMO, CUANDO HAGO LA DIFERENCIA, NO LOS INCLUYE

	// SETEAMOS EL AÑO DE CADA UNA DE LAS ESTADISTICAS Y LA RECAUDACION EN 0
	for (int i = 0; i <= anioMax - anioMin; i++)
	{
		anios[i].setAnio(i + anioMin);
		anios[i].setRecaudacion(0);
	}

	// RECORRO LOS PAGOS Y PARA CADA UNO DE LOS AÑOS DE ESE PAGO, LE AGREGO EL MONTO
	for (int i = 0; i < cantidadPagos; i++)
	{
		anios[pagos[i].getFecha().getAnio() - anioMin].add(pagos[i].getMonto());
	}

	// UNA VEZ TERMINADO, ABRO EL ARCHIVO
	// 
	FILE* pFile;
	pFile = fopen("estadisticas.dat", "wb");
	fwrite(anios, sizeof Estadisticas, anioMax - anioMin + 1, pFile);
	fclose(pFile);

}

void PrimerParcial::mostrarEstadisticas()
{
	FILE* pFile;
	pFile = fopen("estadisticas.dat", "rb");
	Estadisticas es;
	while (fread(&es,sizeof Estadisticas, 1, pFile))
	{
		cout << es.toString() << endl;
	}
}
