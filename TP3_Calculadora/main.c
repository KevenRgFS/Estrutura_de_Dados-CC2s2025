#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "expressao.h"

int main(){

    Expressao *expre = (Expressao *) malloc(sizeof(Expressao));

    printf("\nDeclare sua expressão para a Calculadora de NPR:\n");
    fgets(expre->posFixa, sizeof(expre->posFixa), stdin);
    printf("----------------------------------------\n");

    expre->posFixa[strcspn(expre->posFixa, "\n")] = '\0';

    getFormaInFixa(expre->posFixa);
    getValorPosFixa(expre->posFixa);

}