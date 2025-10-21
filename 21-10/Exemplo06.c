#include <stdio.h>
#include <stdlib.h>

typedef struct Item
{
    int Chave;
    struct Item * Proximo;

}Item;

void ExibirLista(Item * Inicio); // Para lista não circular 
void InserirItem(Item * Inicio, Item * Inserido, int Posicao);
void ExcluirItem(Item * Inicio, int Posicao)

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
    D->Proximo = A;
    

    //Alguns testes (printf's)

    /*printf("%d\n", A->Chave);
    printf("%d\n", A->Proximo->Chave);
    printf("%d\n", A->Proximo->Proximo->Chave);
    printf("%d\n", A->Proximo->Proximo->Proximo->Chave);*/

    // Percorrer a lista (visitar todos os nós da lista)

    printf("\nLista\n\n");

    Item * X = A;

    /*for(Item * X = A ; X != NULL; X = X->Proximo)
    {
        printf("%X\t %d\n", X, X->Chave);
    }*/

    for(int i ; i < 15; i++, X = X->Proximo)
    printf("%X\t %d\n", X, X->Chave);
    


}