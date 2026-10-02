#include  "BibliotecaGenerica.hpp"
#include  "BibliotecaEnteros.hpp"
#include  "BibliotecaRegistros.hpp"
int main() {
    void *lista;
    //creaLista(lista, leenum, clasificaEntero, "numeros2.txt");
    //imprimeLista(lista, imprimenum, "ReporteNum2.txt");

    creaLista(lista, leereg, clasificaRegistro, "RegistroDeFaltas1.csv");
    imprimeLista(lista, imprimereg, "ReporteRegistro.txt");
    return 0;
}