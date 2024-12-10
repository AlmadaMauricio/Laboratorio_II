#include <iostream>
#include "PrimerParcial.h"
using namespace std;

int main() 
{
	PrimerParcial pp;
	//pp.soloUnCurso();
	//pp.listarAlumnosNoMorosos();
	//pp.listarRecaudacion();
	//pp.cursosPremium(1030);
	pp.generarEstadisticas();
	pp.mostrarEstadisticas();



	cout << endl;
	system("pause");
	return 0;
}