#include "ClaseParticular.h"
#include "ClasesParticularesArchivo.h"
#include "Estudiante.h"
#include "EstudiantesArchivo.h"
#include "RecuperatorioPrimerParcial.h"
#include <iostream>
using namespace std;


void RecuperatorioPrimerParcial::cursosConMayorAyuda()
{
    ClasesParticularesArchivo clasesPartArchivo;
    int cantidad = clasesPartArchivo.getCantidad();

    ClaseParticular* clasesPart = new ClaseParticular[cantidad]{};

    int cursos[10]{};

    for (int x = 0; x < cantidad; x++)
    {
        clasesPart[x] = clasesPartArchivo.leer(x);


        cursos[clasesPart[x].getIdCurso() - 1] += (clasesPart[x].getDuracion());

    }

    int mayorDuracion;

    for (int i = 0; i < 10; i++)
    {


        if (i == 0 || cursos[i] > mayorDuracion)
        {
            mayorDuracion = cursos[i];

        }

    }

    for (int i = 0; i < 10; i++)
    {
        if (mayorDuracion == cursos[i])
        {
            cout << "El id tiene: " << i + 1 << "  " << mayorDuracion / 60 << " duracion" << endl;
        }
    }


    delete[] clasesPart;

}

void RecuperatorioPrimerParcial::alumnosConPocaAyuda()
{
    ClaseParticular clasPartic;
    ClasesParticularesArchivo clasParArchivo;
    int cantidadClases = clasParArchivo.getCantidad();

    Estudiante estudiante;
    EstudiantesArchivo estudiantesArchivo;
    int cantidadEst = estudiantesArchivo.getCantidad();


    for (int x = 0; x < cantidadEst; x++)
    {
        bool bandera = false;
        estudiante = estudiantesArchivo.leer(x);

        for (int i = 0; i < cantidadClases; i++)
        {
            clasPartic = clasParArchivo.leer(i);

            if (estudiante.getLegajo() == clasPartic.getLegajoAlumno() && clasPartic.getDuracion() > 60)
            {
                bandera = true;
            }
        }
        if (bandera == false)
        {
            cout << estudiante.getLegajo() << " " << estudiante.getNombres() << endl;
        }
    }
}

void RecuperatorioPrimerParcial::generarEstadisticasAyuda()
{
    ClaseParticular clasPar;
    ClasesParticularesArchivo clasParArc;
    int cantidadClases = clasParArc.getCantidad();
    float cursos[10] = {};
    float prom[10] = {};
    int acu[10] = {};
    RecuperatorioPrimerParcial rp;

    for (int x = 0; x < cantidadClases; x++)
    {
        clasPar = clasParArc.leer(x);
        for (int i = 0; i < 10; i++)
        {
            cursos[clasPar.getIdCurso() - 1] += clasPar.getMonto();
            acu[clasPar.getIdCurso() - 1]++;
        }
    }

    for (int i = 0; i < 10; i++)
    {
        prom[i] = cursos[i] / acu[i];
        rp.setId(i + 1);
        rp.setMonto(prom[i]);
        guardar(rp);
    }
}



bool RecuperatorioPrimerParcial::guardar(RecuperatorioPrimerParcial recup)
{
    FILE* p = fopen("estadisticas.dat", "ab");
    if (p == NULL)
    {
        return false;
    }
    bool ok = fwrite(&recup, sizeof(RecuperatorioPrimerParcial), 1, p);
    fclose(p);
    return ok;
}

RecuperatorioPrimerParcial RecuperatorioPrimerParcial::leer(int numeroRegistro)
{
    RecuperatorioPrimerParcial rec{};
    FILE* p;
    p = fopen("estadisticas.dat", "rb");
    if (p == NULL) {
        return rec;
    }
    fseek(p, numeroRegistro * sizeof(RecuperatorioPrimerParcial), SEEK_SET);
    fread(&rec, sizeof(RecuperatorioPrimerParcial), 1, p);
    fclose(p);
    return rec;
}

void RecuperatorioPrimerParcial::mostrarEstadisticas()
{
    RecuperatorioPrimerParcial recuperatorioPrimerParcial, RecuperatorioPrimerParcialI;
    for (int i = 0; i < 10; i++)
    {
        RecuperatorioPrimerParcialI = recuperatorioPrimerParcial.leer(i);
        cout << "id:" << RecuperatorioPrimerParcialI.getId() << " - " << "promedio: " << RecuperatorioPrimerParcialI.getMonto() << endl;
    }
}

void RecuperatorioPrimerParcial::nuncaRecibioAyuda(int legajo)
{
    ClaseParticular clasParticular;
    ClasesParticularesArchivo clasParArchivo;
    Estudiante estudiante;
    EstudiantesArchivo estArchivo;
    int cantidadClases = clasParArchivo.getCantidad();
    int cantidadEst = estArchivo.getCantidad();

    for (int x = 0; x < cantidadEst; x++)
    {
        bool sinAyuda = true;
        estudiante = estArchivo.leer(x);

        for (int i = 0; i < cantidadClases; i++)
        {
            clasParticular = clasParArchivo.leer(i);

            if (estudiante.getLegajo() == clasParticular.getLegajoAlumno() && legajo == clasParticular.getLegajoProfesor())
            {
                sinAyuda = false;
            }
        }
        if (sinAyuda == true)
        {
            cout << estudiante.getLegajo() << endl;
        }
    }
}



