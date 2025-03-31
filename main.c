#include "tarefas.h"

int main() {
    StrTarefas tarefa[Max_tarefas];
    int tarefas_registradas = 0;
    int opcoes;

    do {
        printf("\nMenu:\n1. Criar tarefa\n2. Listar tarefas\n3. Apagar tarefa\n4. Sair\nOpção: ");
        scanf("%d", &opcoes);

        switch (opcoes) {
            case 1:
                add_tarefa(tarefa, &tarefas_registradas);
                break;
            case 2:
                listar_tarefa(tarefa, tarefas_registradas);
                break;
            case 3:
                apagar_tarefa(tarefa, &tarefas_registradas);
                break;
            case 4:
                printf("Saindo");
                for (int a = 0; a < 3; a++) {
                    fflush(stdout);
                    sleep(1);
                    printf(".");
                }
                printf("\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcoes != 4);

    return 0;
}