#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
 
#include "cidades.h" 
 
int main () { 
    
    FILE *test = fopen("teste02.txt", "r");
    if (test == NULL) {
    printf("Erro: não foi possível abrir o arquivo teste02.txt\n");
    return 1;
    }
    fclose(test);

    int Soma = 0; 
    int NumTeste = 0; 
 
    FILE *Resposta = fopen("Resultado.txt", "w"); 
 
    Estrada *T1 = getEstrada("teste02.txt"); 
    double D1 = calcularMenorVizinhanca("teste02.txt"); 
    char *C1 = cidadeMenorVizinhanca("teste02.txt"); 
 
    if (T1->T == 10) Soma++; 
    NumTeste++; 
 
    if (T1->N == 2) Soma++; 
    NumTeste++; 
 
    if (D1 == 3.5) Soma++; 
    NumTeste++; 
 
    if (strcmp(C1, "Birnin Zana")==0) Soma++; 
    NumTeste++; 
 
    fprintf(Resposta, "\n\nATENÇÃO: Você acertou %d de %d itens. Logo, em 1.50 pontos, sua nota foi %.2f.\n", Soma, NumTeste, 2.0 * (float)Soma/(float)NumTeste); 
} 
