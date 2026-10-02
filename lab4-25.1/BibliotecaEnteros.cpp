#include  "BibliotecaEnteros.hpp"
void * leenum(ifstream &input) {
    int *numero = new int[1]{};
    input>>*numero;
    if (input.eof()) return nullptr;
    input.get();
    return numero;
}
int clasificaEntero(void *&dato) {
    if (dato == nullptr) return -1;
    int *numero = (int *) dato;
    if (*numero < 10 ) return 1;
    return 2;
}
void imprimenum(ofstream &output, void *dato) {
    if (dato == nullptr) return;
    int *numero = (int *) dato;
    output<<*numero<<endl;
}