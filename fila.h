#include "paciente.h"
#ifndef FILA_H
#define FILA_H

#include "paciente.h"

typedef struct {
    Paciente* inicio;
} Fila;

void inicializarFila(Fila* fila);
void inserirPaciente(Fila* fila, Paciente* paciente);
Paciente* atenderPaciente(Fila* fila);
void mostrarFila(Fila* fila);

#endif