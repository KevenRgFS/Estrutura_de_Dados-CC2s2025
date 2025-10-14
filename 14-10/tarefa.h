#ifndef TAREFA_H
#define TAREFA_H

#define TAM_TITUTLO 96
#define TAM_NOME 48 

#define A_FAZER 0
#define EM_ANDAMENTO 1
#define FEITO 2

//typedef enum{A_FAZER, EM_ANDAMENTO, FEITO} TiposStatus; --> Pode ser feito desse jeito, para enumerar os termos de 0 para frente


//Definindo a estrutura de um elemento da LISTA:
typedef struct 
{
    char Titulo[TAM_TITUTLO];
    char Responsavel[TAM_NOME];
    int Status;
    float Progresso;
    int Avaliacao;

}Tarefa;

//Definindo a estrutura da LISTA de tarefas:
typedef struct 
{
    Tarefa * Dados;
    int Capacidade;
    int Tamanho;

}Lista;

Lista * CriarLista(int C);

void DestruirLista(Lista * L);
void AdicionarTarefa(Lista * L, Tarefa T);
void GerarHTMLTabela(Lista *Lista, char *CaminhoArquivo);
#endif