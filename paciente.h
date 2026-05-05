#ifndef PACIENTE_H
#define PACIENTE_H

typedef struct Paciente {
    int id;
    int prioridade; // 0 = vermelho, 1 = amarelo, 2 = verde
    struct Paciente* prox;
} Paciente;

Paciente* criarPaciente(int id, int prioridade);

#endif