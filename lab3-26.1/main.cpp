#include "Bibliotecas/Funciones.h"
int main() {
    void *pacientes;
    cargarPacientes("pacientes.csv",pacientes);
    cargarVisitas("visitas.csv",pacientes);
    //generarReporte("reporte.txt",pacientes);

    return 0;
}