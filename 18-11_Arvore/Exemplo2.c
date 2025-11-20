#include <stdio.h>
#include <stdlib.h>

typedef struct No{

    char Chave;

    // No caso de árvore BINÁRIA(Máximo 2 filhos):

    struct No * Esquerda; // Indica o 1° filho
    struct No * Direita; // Indica o 2° filho

    struct No * F[2]; //Filhos F[0], F[1]
}No;

No * criarNo(char Chave)
{
    
    No * N = (No *) malloc(sizeof(No));

    if(N==NULL)
    {
        printf("ERRO: não há memória para o Nó.\n");
        return NULL;
    }

    N->Chave = Chave;
    N->Esquerda = NULL;
    N->Direita = NULL;

    //for(int i = 0; i>= 2; i++) N->F[i] == NULL;

    return N;
}

int main()
{
    No * A = criarNo('a');
    No * B = criarNo('b');
    No * C = criarNo('c');
    No * D = criarNo('d');

    A->Esquerda = B;
    A->Direita = C;
    C->Direita = D;

    printf("%c", A->Direita->Direita->Chave);
}



