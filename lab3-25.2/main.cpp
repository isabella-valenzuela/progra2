
#include "Bibliotecas/PunterosGenericos.h"

int main() {
    void *streamers, *comentarios;

    cargaStreamers(streamers);
    cargaComentarios(comentarios);
    actualizaComentarios(streamers, comentarios);
    imprimeStreamers(streamers);


    return 0;
}