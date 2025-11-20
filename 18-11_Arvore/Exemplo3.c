#include <stdio.h>
#include <stdlib.h>

typedef struct No{

    int Chave;

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

int contarNos(No * N)
{
    if(N==NULL) return 0;
    return 1 + contarNos(N->Direita) + contarNos(N->Esquerda);
}

int main()
{

    system("cls");

    /*No * A = criarNo(10);
    No * B = criarNo(12);
    No * C = criarNo(15);
    No * D = criarNo(16);
    No * E = criarNo(18);
    No * F = criarNo(20);
    
    A->Esquerda = B;
    A->Direita = C;
    B->Esquerda = D;
    B->Direita = E;
    C->Direita = F;*/

    //ou pode se fazer assim, sem precisar criar uma variável

    No * A = criarNo(10);

    A->Esquerda = criarNo(12);
    A->Direita = criarNo(15);

    A->Esquerda->Esquerda = criarNo(16);
    A->Esquerda->Direita = criarNo(18);
    A->Direita->Direita = criarNo(20);

    A->Direita->Direita->Esquerda = criarNo(17);
    A->Direita->Direita->Direita = criarNo(19);



    printf("%d", A->Direita->Direita->Esquerda->Chave);
}



