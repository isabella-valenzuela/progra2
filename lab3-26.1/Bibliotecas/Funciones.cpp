//
// Created by Isabella on 25/09/2026.
//

#include "Funciones.h"
enum camposPacientes {ID, NOMBRE, EDAD, GENERO, VISITAS, GASTADO};
enum camposVisita {FECHA, HORA, COSTO};
#define INCREMENTO 5
#define NOENCONTRADO -1

void cargarPacientes(const char *nombArch, void *&pacientes) {
    ifstream arch = abrirIfstream(nombArch);
    void **pacientesAux = nullptr, *unPaciente;
    int nd = 0, cap = 0;
    while (true) {
        leerArchivo(arch, unPaciente);
        if (arch.eof()) break;
        if (nd==cap) {
            incrementarEspacios(pacientesAux, nd, cap);
        }
        pacientesAux[nd] = unPaciente;
        nd++;

    }
    pacientes = pacientesAux;

}

void cargarVisitas(const char *nombArch, void *&pacientes) {
    ifstream arch = abrirIfstream(nombArch);
    void **pacientesAux = (void **)pacientes;

    int cantPacientes = 0;
    for (int i = 0; pacientesAux[i]; i++)
        cantPacientes++;

    int *nd = new int[cantPacientes]{};
    int *cap = new int[cantPacientes]{};

    while (true) {
        leeVisitas(arch, pacientesAux, nd, cap);
        if (arch.eof()) break;
    }
}

void leeVisitas(ifstream &arch, void **pacientesAux, int *nd, int *cap) {
    int anho, mes, dia, fecha, hh, mm, hora, idPac;
    char c;
    double costoAtencion;

    arch >> anho;
    if (arch.eof()) return;
    arch >> c >> mes >> c >> dia >> c >> hh >> c >> mm >> c >> idPac >> c >> costoAtencion;

    fecha = anho * 10000 + mes * 100 + dia;
    hora = 100 * hh + mm;

    int pos = buscarPaciente(idPac, pacientesAux);
    if (pos == -1) return;   // no existe, se descarta la línea

    void *unaVisita = rellenarVisita(fecha, hora, costoAtencion);
    colocaVisita(unaVisita, pacientesAux[pos], costoAtencion, nd[pos], cap[pos]);
}
void colocaVisita(void *unaVisita, void *unPaciente, double costoAtencion, int &nd, int &cap) {
    void **paciente = (void **)unPaciente;

    if (nd == cap)
        incrementarEspacios(paciente[VISITAS], nd, cap);

    void **visitasDelPaciente = (void **)paciente[VISITAS];
    visitasDelPaciente[nd] = unaVisita;
    nd++;

    double *pGastado = (double *)paciente[GASTADO];
    *pGastado += costoAtencion;
}

void *rellenarVisita(int fecha, int hora, double costoAtencion) {
    void **visita = new void *[3];

    int *ptrFecha = new int;
    *ptrFecha = fecha;
    visita[FECHA] = ptrFecha;

    int *ptrHora = new int;
    *ptrHora = hora;
    visita[HORA] = ptrHora;

    double *ptrCosto = new double;
    *ptrCosto = costoAtencion;
    visita[COSTO] = ptrCosto;

    return visita;
}

int buscarPaciente(int idBuscado, void **pacientesAux) {
    for (int i = 0; pacientesAux[i]; i++) {
        void **paciente = (void **)pacientesAux[i];
        int *idActual = (int *)paciente[ID];
        if (*idActual == idBuscado) return i;
    }
    return -1;
}
void incrementarEspacios(void *&campoVisitas, int &nd, int &cap) {
    void **visitas = (void **)campoVisitas;
    void **aux;
    cap += INCREMENTO;
    if (visitas == nullptr) {
        visitas = new void *[cap]{};
    } else {
        aux = new void *[cap]{};
        for (int i = 0; i < nd; i++)
            aux[i] = visitas[i];
        delete[] visitas;
        visitas = aux;
    }
    campoVisitas = visitas;
}

void incrementarEspacios(void **&pacientesAux, int& nd, int& cap) {
    void **aux;
    cap += INCREMENTO;
    if (pacientesAux == nullptr) {
        pacientesAux = new void *[cap]{};
    }else {
        aux = new void*[cap]{};
        for (int i = 0; i < nd; i++)
            aux[i] = pacientesAux[i];
        delete[] pacientesAux;
        pacientesAux = aux;    }
}

void leerArchivo(ifstream &arch, void *&paciente) {
    int id, edad;
    char *nombre, genero, c;
    arch >> id;
    if (arch.eof()) return;
    arch.get();
    nombre = leerCadenaExacta(arch, ',');
    arch >> edad>>c>>genero;
    paciente = rellenarPaciente(id, nombre, edad, genero);
}

void *rellenarPaciente(int id, char *nombre, int edad, char genero) {
    void **registro = new void *[6];

    int *ptrId = new int;
    *ptrId = id;
    registro[ID] = ptrId;

    int *ptrEdad = new int;
    *ptrEdad = edad;
    registro[EDAD] = ptrEdad;

    char *ptrGenero = new char;
    *ptrGenero = genero;
    registro[GENERO] = ptrGenero;

    registro[NOMBRE] = nombre;
    registro[VISITAS] = nullptr;

    double *ptrTotGastado = new double;
    *ptrTotGastado = 0.0;
    registro[GASTADO] = ptrTotGastado;

    return registro;
}

ifstream abrirIfstream(const char *nombArch) {
    ifstream arch = ifstream(nombArch, ios::in);
    if(not arch.is_open()) {
        cout<<"Error al abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    return arch;
}
ofstream abrirOfstream(const char *nombArch) {
    ofstream arch = ofstream(nombArch, ios::out);
    if(not arch.is_open()) {
        cout<<"Error al abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    return arch;
}
char *leerCadenaExacta(ifstream &arch, char delim) {
    char *ptr, buffer[100];
    arch.getline(buffer, 100, delim);
    if (arch.eof()) return nullptr;
    ptr = new char [strlen(buffer)+1];
    strcpy(ptr, buffer);
    return ptr;
}