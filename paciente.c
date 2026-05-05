#include <stdlib.h>
#include "paciente.h"

Paciente* criarPaciente(int id, int prioridade) {
    Paciente* novo = (Paciente*) malloc(sizeof(Paciente));

    if (novo == NULL) return NULL;

    novo->id = id;
    novo->prioridade = prioridade;
    novo->prox = NULL;

    return novo;
}