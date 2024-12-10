#include <iostream>
#include "RecuperatorioPrimerParcial.h"
#include "ClasesParticularesArchivo.h"
#include "ClaseParticular.h"
using namespace std;

int main() {

	RecuperatorioPrimerParcial rpp;

	//rpp.cursosConMayorAyuda();
	//rpp.alumnosConPocaAyuda();
	rpp.generarEstadisticasAyuda();
	rpp.mostrarEstadisticas();
	//rpp.nuncaRecibioAyuda(1000);

	

	cout << endl;
	system("pause");
	return 0;
}