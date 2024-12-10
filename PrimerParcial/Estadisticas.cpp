#include "Estadisticas.h"

Estadisticas::Estadisticas()
{
	_anio = 0;
	_recaudacion = 0;
}

Estadisticas::Estadisticas(int anio, float recaudacion)
{
	_anio = anio;
	_recaudacion = recaudacion;
}

int Estadisticas::getAnio()
{
	return _anio;
}

float Estadisticas::getRecaudacion()
{
	return _recaudacion;
}

void Estadisticas::setAnio(int anio)
{
	_anio = anio;
}

void Estadisticas::setRecaudacion(float recaudacion)
{
	_recaudacion = recaudacion;
}

void Estadisticas::add(float recaudacion)
{

}

std::string Estadisticas::toString()
{
	return "Anio: " + std::to_string(_anio) + " - Recaudacion: " + std::to_string(_recaudacion);
}

