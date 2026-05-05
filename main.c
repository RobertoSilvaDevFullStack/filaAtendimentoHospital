#include <stdio.h>
#include <stdlib.h>

#include "paciente.h"
#include "fila.h"

int main() {
    Fila fila;
    inicializarFila(&fila);

    int opcao;
    int id;
    int prioridade;

    do {
        printf("\n=== SISTEMA DE FILA HOSPITALAR ===\n");
        printf("1 - Inserir paciente\n");
        printf("2 - Atender paciente\n");
        printf("3 - Mostrar fila\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {

            case 1:
                printf("ID do paciente: ");
                scanf("%d", &id);

                printf("Prioridade (0=vermelho, 1=amarelo, 2=verde): ");
                scanf("%d", &prioridade);

                if (prioridade < 0 || prioridade > 2) {
                    printf("Prioridade inválida\n");
                    break;
                }

                Paciente* novo = criarPaciente(id, prioridade);

                if (novo == NULL) {
                    printf("Erro ao criar paciente\n");
                    break;
                }

                inserirPaciente(&fila, novo);
                printf("Paciente inserido!\n");

                break; // 🔥 ESSENCIAL

            case 2: {
                Paciente* atendido = atenderPaciente(&fila);

                if (atendido != NULL) {
                    printf("Paciente atendido: ID=%d Prioridade=%d\n",
                           atendido->id, atendido->prioridade);

                    free(atendido);
                } else {
                    printf("Fila vazia\n");
                }
                break;
            }

            case 3:
                printf("Fila atual:\n");
                mostrarFila(&fila);
                break;

            case 0:
                printf("Saindo...\n");
                break;

            default:
                printf("Opção inválida\n");
                break;
        }

    } while (opcao != 0);

    // 🔥 LIMPEZA FINAL CORRETA
    Paciente* temp;
    while ((temp = atenderPaciente(&fila)) != NULL) {
        free(temp);
    }

    return 0;
}