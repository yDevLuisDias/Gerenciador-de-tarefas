#ifndef TAREFAS_H
#define TAREFAS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define Max_tarefas 100
#define tam_descricao 121
#define tam_nome 51
#define tam_validade 9

typedef struct {
    char nome[tam_nome];
    char descricao[tam_descricao];
    int inportancia;
    char validade[tam_validade];
} StrTarefas;

void add_tarefa(StrTarefas Tarefas[], int *tarefas_registradas);
void listar_tarefa(StrTarefas Tarefas[], int tarefas_registradas);
void apagar_tarefa(StrTarefas Tarefas[], int *tarefas_registradas);

#endif