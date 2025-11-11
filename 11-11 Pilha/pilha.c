#include <stdio.h>
#include <stdlib.h>

#include "pilha.h"



Item * criarItem(int Chave){

    Item * I = (Item *) malloc(sizeof(Item));
    
    if(I==NULL)
    {
        printf("ERRO: não foi possível alocar memória para o Item.\n");
        return NULL;
    }

    I->Chave = Chave;
    I->Anterior = NULL;

    return I;
}

Pilha * criarPilha(){

    Pilha * P = (Pilha *) malloc(sizeof(Pilha));
    
    if(P==NULL)
    {
        printf("ERRO: não foi possível alocar memória para a Pilha.\n");
        return NULL;
    }

    P->Tamanho = 0;
    P->Topo = 0;
    
    return P;
}

void Empilhar(Pilha * P, Item * I){

    I->Anterior = P->Topo;
    P->Topo = I;
    P->Tamanho++;
}

void Desempilhar(Pilha * P){

    if(P->Tamanho == 0)
    {
        printf("ERRO: a pilha está vázia.\n");
        return ;
    }

    Item * I = P->Topo;
    (P->Topo);
    P->Topo = P->Topo->Anterior;
    free(I);
    P->Tamanho--;
}