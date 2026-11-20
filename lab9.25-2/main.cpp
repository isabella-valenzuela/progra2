#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "Bibliotecas/MinisterioDeTransporte.h"
using namespace std;

int main() {

    class MinisterioDeTransporte ministerio;

    ministerio.cargaDeInfracciones("ArchivosDeDatos/TablaDeInfracciones.csv");
    ministerio.cargaEmpresas("ArchivosDeDatos/EmpresasRegistradas.csv");
    ministerio.cargaVehiculos("ArchivosDeDatos/VehiculosRegistrados.csv");
    ministerio.cargaInfraccionesCometidas("ArchivosDeDatos/InfraccionesCometidas.csv");

    ministerio.reporteDeEmpresasConInfracciones("ArchivosDeReporte/ReporteDeInfracciones.txt");

    ministerio.eliminaInfraccionesPagadas();
    ministerio.reporteDeEmpresasConInfracciones("ArchivosDeReporte/ReporteDeInfraccionesNP.txt");
    return 0;
}
