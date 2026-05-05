#include <stdio.h>
#include "fila.h"


void inicializarFila(Fila* fila) {
    fila->inicio = NULL;
}

void inserirPaciente(Fila* fila, Paciente* novo){
    //fila vazia
    if (fila-> inicio == NULL) {
        fila->inicio = novo;
        return;
    }

    //maior prioridade entra na frente
    if (novo->prioridade < fila->inicio->prioridade) {
        novo->prox = fila->inicio;
        fila->inicio = novo;
        return;
    }

    Paciente* atual = fila->inicio;

    //percorre até achar posição correta

    while (atual->prox != NULL &&
        atual->prox->prioridade <= novo->prioridade) {
        atual = atual->prox;
    }

    novo->prox = atual->prox;
    atual->prox = novo;
}

    Paciente* atenderPaciente(Fila* fila) {
    if (fila->inicio == NULL) return NULL;

    Paciente* atendido = fila->inicio;
    fila->inicio = fila->inicio->prox;

    return atendido;

}

    void mostrarFila(Fila* fila) {
    Paciente* atual = fila->inicio;

    while (atual != NULL) {
        printf("Paciente: ID=%d Prioridade=%d\n",
            atual->id, atual->prioridade);
        atual = atual->prox;
    }
}