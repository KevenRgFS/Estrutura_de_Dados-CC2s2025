#include <stdio.h>
#include <stdlib.h>

typedef struct Item
{
    int Chave;
    struct Item * Proximo;

}Item;

Item * CriarItem(int Chave);
void ExibirLista(Item * Inicio); // Para lista não circular 
void InserirItem(Item * Inicio, Item * Inserido, int Posicao);
void ExcluirItem(Item * Inicio, int Posicao);

int main()
{
    Item * A = CriarItem(17);
    Item * B = CriarItem(29);
    Item * C = CriarItem(41);
    Item * D = CriarItem(97);

    // Construindo o encadeamento (LISTA) A, B, C, D

    A->Proximo = B;
    B->Proximo = C;
    C->Proximo = D;
    ExibirLista(A);

    // Inserir o item P, cuja a chave seja 67, logo após C.

    Item * P = CriarItem(67);
    P->Proximo = D;
    C->Proximo = P;
    printf("\n");
    ExibirLista(A);
    printf("\n");
    // Exclua o Item B da lista.

    A->Proximo = C;
    //"A->Proximo = B->Proximo;" Essa poderia ser uma segunda opção.
    free(B);
    ExibirLista(A);
}

Item * CriarItem(int Chave)
{
    Item * X = (Item *) malloc(sizeof(Item));
    X->Chave = Chave;
    X->Proximo = NULL;
    return X;
}

void ExibirLista(Item * Inicio)
{
    Item * X = Inicio;
    for(int i ; X != NULL; i++, X = X->Proximo)
    printf("%d\t", X->Chave);
}

void InserirItem(Item * Inicio, Item * Inserido, int Posicao)
{
    //X->Proximo = C;
}
