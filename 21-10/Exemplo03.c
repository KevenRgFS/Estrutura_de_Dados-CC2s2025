#include <stdio.h>
#include <stdlib.h>

typedef struct Item
{
    int Chave;
    struct Item * Proximo;

}Item;

int main()
{
    Item * A = (Item *) malloc(sizeof(Item));
    Item * B = (Item *) malloc(sizeof(Item));
    Item * C = (Item *) malloc(sizeof(Item));
    Item * D = (Item *) malloc(sizeof(Item));

    // Construindo o encadeamento (LISTA) A, B, C, D

    A->Chave = 17;
    A->Proximo = B;
    B->Chave = 29;
    B->Proximo = C;
    C->Chave = 41;
    C->Proximo = D;
    D->Chave = 97;
    D->Proximo = NULL;
    

    //Alguns testes (printf's)

    /*printf("%d\n", A->Chave);
    printf("%d\n", A->Proximo->Chave);
    printf("%d\n", A->Proximo->Proximo->Chave);
    printf("%d\n", A->Proximo->Proximo->Proximo->Chave);*/

    // Inserir o item X, com chave 73, antes do A

    Item * X = (Item *) malloc(sizeof(Item));
    X->Chave = 73;
    X->Proximo = NULL; // Desnecessário

    X->Proximo = A;




}