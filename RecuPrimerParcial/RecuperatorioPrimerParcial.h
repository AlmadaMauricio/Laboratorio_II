#pragma once
class RecuperatorioPrimerParcial
{
private:
	int _id;
	float _monto;
public:
	void cursosConMayorAyuda(); // PUNTO 1
	void alumnosConPocaAyuda(); // PUNTO 2
	void generarEstadisticasAyuda();
	bool guardar(RecuperatorioPrimerParcial recup);
	RecuperatorioPrimerParcial leer(int numeroRegistro);
	void mostrarEstadisticas();
	void nuncaRecibioAyuda(int); // PUNTO 4

	void setId(int id)
	{
		_id = id;
	}

	void setMonto(float monto)
	{
		_monto = monto;
	}

	int getId()
	{
		return _id;
	}

	float getMonto()
	{
		return _monto;
	}

};

