#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cidades.h"

// =======================================
// Função auxiliar: criar cidade
// =======================================
Cidade *criarCidade(const char *nome, int posicao) {
    Cidade *nova = (Cidade*) malloc(sizeof(Cidade));
    if (nova == NULL) return NULL;

    strcpy(nova->Nome, nome);
    nova->Posicao = posicao;
    nova->Proximo = NULL;
    return nova;
}

// =======================================
// Função 1: getEstrada
// =======================================
Estrada *getEstrada(const char *nomeArquivo) {
    FILE *arq = fopen(nomeArquivo, "r");
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo %s\n", nomeArquivo);
        return NULL;
    }

    Estrada *nova = malloc(sizeof(Estrada));
    if (nova == NULL) {
        printf("Erro ao alocar memória para Estrada\n");
        fclose(arq);
        return NULL;
    }

    // Exemplo: lendo os dados iniciais
    fscanf(arq, "%d", &nova->T);
    for (int i = 0; i < nova->T; i++) {
        fscanf(arq, "%s %d", nova->Inicio[i].Nome, &nova->Inicio[i].Proximo);
    }

    fclose(arq);
    return nova;
}


// =======================================
// Função 2: calcularMenorVizinhanca
// =======================================
double calcularMenorVizinhanca(const char *nomeArquivo) {
    FILE *arq = fopen(nomeArquivo, "r");
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo %s\n", nomeArquivo);
        return -1;
    }

    int n;
    fscanf(arq, "%d", &n);
    double menor = 9999999.0;

    for (int i = 0; i < n; i++) {
        char nome[50];
        double viz;
        fscanf(arq, "%s %lf", nome, &viz);
        if (viz < menor)
            menor = viz;
    }

    fclose(arq);
    return menor;
}


// =======================================
// Função 3: cidadeMenorVizinhanca
// =======================================
char *cidadeMenorVizinhanca(const char *nomeArquivo) {
    FILE *arq = fopen(nomeArquivo, "r");
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo %s\n", nomeArquivo);
        return NULL;
    }

    int n;
    fscanf(arq, "%d", &n);
    static char menorCidade[50];
    double menor = 9999999.0;

    for (int i = 0; i < n; i++) {
        char nome[50];
        double viz;
        fscanf(arq, "%s %lf", nome, &viz);
        if (viz < menor) {
            menor = viz;
            strcpy(menorCidade, nome);
        }
    }

    fclose(arq);
    return menorCidade;
}

