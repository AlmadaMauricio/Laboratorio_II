#pragma once
#include <string>
class Estadisticas
{
private:
	int _anio;
	float _recaudacion;
public:
	Estadisticas();
	Estadisticas(int anio, float recaudacion);
	int getAnio();
	float getRecaudacion();
	void setAnio(int anio);
	void setRecaudacion(float recaudacion);
	void add(float recaudacion);
	std::string toString();
};

