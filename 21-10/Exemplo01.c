#include <stdio.h>
#include <stdlib.h>

// Definindo a estrutura de um ITEM da lista ENCADEADA

typedef struct Item
{
    int Chave;
    struct Item * Proximo;
}Item;

// bloco principal

int main()
{
    Item * I = (Item *) malloc(sizeof(Item));

    I->Chave = 23;
    I->Proximo = NULL;

    //Alguns testes (printf's)

    printf("%d\n", I);
    printf("(Endereço Hexadecimal: %X\n", I);
    printf("%d\n", I->Chave);
    printf("%d(Vazio,null, pq não foi inicializado)\n", I->Proximo);
}