#include "tarefas.h"

void add_tarefa(StrTarefas Tarefas[], int *tarefas_registradas)
{
    if (*tarefas_registradas >= Max_tarefas)
    {
        printf("Limite de tarefas excedido!\n");
        return;
    }

    StrTarefas nova_tarefa;
    getchar();

    printf("Titulo da tarefa:\n");
    fgets(nova_tarefa.nome, tam_nome, stdin);
    nova_tarefa.nome[strcspn(nova_tarefa.nome, "\n")] = '\0';

    printf("Descrição:\n");
    fgets(nova_tarefa.descricao, tam_descricao, stdin);
    nova_tarefa.descricao[strcspn(nova_tarefa.descricao, "\n")] = '\0';

    printf("Importância (1 a 5):\n");
    scanf("%d", &nova_tarefa.inportancia);
    getchar();

    printf("Prazo:\n");
    fgets(nova_tarefa.validade, tam_validade, stdin);
    nova_tarefa.validade[strcspn(nova_tarefa.validade, "\n")] = '\0';

    Tarefas[*tarefas_registradas] = nova_tarefa;
    (*tarefas_registradas)++;

    printf("Tarefa criada com sucesso!\nID da tarefa: %d\n", *tarefas_registradas - 1);
}

void listar_tarefa(StrTarefas Tarefas[], int tarefas_registradas)
{
    int i, sub_opcao;

    if (tarefas_registradas == 0)
    {
        printf("Sem tarefas registradas.\n");
        return;
    }

    printf("Opções:\n1. Procurar tarefa específica\n2. Listar todas\n");
    scanf("%d", &sub_opcao);

    switch (sub_opcao)
    {
    case 1:
        printf("ID da tarefa: ");
        scanf("%d", &i);

        printf("\n Tarefa %d:", i);
        printf("\n Título: %s", Tarefas[i].nome);    
        printf("\n Descrição: %s", Tarefas[i].descricao);    
        printf("\n Importância: %d", Tarefas[i].inportancia);    
        printf("\n Validade: %s \n", Tarefas[i].validade);   

        break;

    case 2:
        for (i = 0; i < tarefas_registradas; i++)
        {
            printf("\n Tarefa %d:", i);
            printf("\n Título: %s", Tarefas[i].nome);    
            printf("\n Descrição: %s", Tarefas[i].descricao);   
            printf("\n Importância: %d", Tarefas[i].inportancia);
            printf("\n Validade: %s \n", Tarefas[i].validade);
        }
        break;

    default:
        printf("Opção inválida!\n");
    }
}

void apagar_tarefa(StrTarefas Tarefas[], int *tarefas_registradas)
{
    int p;

    if (*tarefas_registradas == 0)
    {
        printf("Não há tarefas para apagar.\n");
        return;
    }

    printf("ID da tarefa a apagar: ");
    scanf("%d", &p);

    if (p < 0, p > *tarefas_registradas)
    {
        printf("Tarefa não existe!\n");
        return;
    }

    for (int j = p; j < *tarefas_registradas - 1; j++)
    {
        Tarefas[j] = Tarefas[j + 1];
    }

    (*tarefas_registradas)--;
    printf("Tarefa apagada com sucesso!\n");
}