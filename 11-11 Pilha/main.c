#include <stdio.h>
#include <stdlib.h>

#include "pilha.h"

int main()
{

    system("cls");

    Item * I1 = criarItem(30);
    Item * I2 = criarItem(26);
    Item * I3 = criarItem(12);
    Item * I4 = criarItem(9);
    Item * I5 = criarItem(5);
    Item * I6 = criarItem(10);
    Item * I7 = criarItem(27);

    Pilha * MinhaPilha = criarPilha();
    printf("%X", MinhaPilha);

    printf("\n");

    Empilhar(MinhaPilha, I1);
    Empilhar(MinhaPilha, I2);
    Empilhar(MinhaPilha, I3);
    Empilhar(MinhaPilha, I4);
    Empilhar(MinhaPilha, I5);
    Empilhar(MinhaPilha, I6);
    Empilhar(MinhaPilha, I7);

    printf("%d\t%d \n", MinhaPilha->Topo->Chave, MinhaPilha->Tamanho);

    Desempilhar(MinhaPilha);

    printf("%d\t%d", MinhaPilha->Topo->Chave, MinhaPilha->Tamanho);
    
}