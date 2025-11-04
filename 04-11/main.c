#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "musica.h"

int main()
{
    Item * D = criarItem("Aquarela", "Toquinho", 1983);
    Item * E = criarItem("Romaria", "Renato Teixeira", 1978);
    Item * F = criarItem("Eu nasci a dez mil anos atrás", "Raul Seixas", 1976);
    Item * G = criarItem("Cálice", "Chico Buarque e Gilberto Gil", 1978);
    Item * H = criarItem("Tempo Perdido", "Renato Russo", 1986);

    //construindo o encadeamento D, E, F, G, H

    D->Anterior = NULL;
    D->Posterior = E;
    E->Anterior = D;
    E->Posterior = F;
    F->Anterior = E;
    F->Posterior = G;
    G->Anterior = F;
    G->Posterior = H;
    H->Anterior = G;
    H->Posterior = NULL;

    //Criando uma Lista

    Lista * Playlist = (Lista *) malloc(sizeof(Lista));
    if(Playlist == NULL)
    {
        exit(1);
    }

    Playlist->Tamanho = 5;
    Playlist->Inicio = D;
    Playlist->Fim = H;

    exibirInicio(Playlist);
    exibirFinal(Playlist);

    /*//exercício

    Item * Atual = E;
    Atual = Atual->Posterior;
    Atual = Atual->Posterior;
    Atual = Atual->Posterior;
    Atual = Atual->Posterior;

    printf("%s\t%s\t%d\n", Atual->Titulo, Atual->Autor, Atual->Ano);

    //exercicio2

    D->Anterior = NULL;
    D->Posterior = F;
    E->Anterior = D;
    E->Posterior = F;
    F->Anterior = D;
    F->Posterior = G;
    G->Anterior = F;
    G->Posterior = H;
    H->Anterior = G;
    H->Posterior = NULL;
    free(E)*/



    
}