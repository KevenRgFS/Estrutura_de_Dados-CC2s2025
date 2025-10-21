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

    A->Chave = 17;
    A->Proximo = C;
    B->Chave = 29;
    B->Proximo = D;
    C->Chave = 41;
    C->Proximo = B;
    D->Chave = 97;
    D->Proximo = NULL;
    

    //Alguns testes (printf's)

    printf("%X\t %d\n", A, A->Chave);
    printf("%d\n", A->Proximo->Chave);
    printf("%X\t %d\n", B, B->Chave);
    printf("%X\t %d\n", C, C->Chave);
    printf("%d\n", C->Proximo->Proximo->Chave);
    printf("%X\t %d\n", D, D->Chave);

}