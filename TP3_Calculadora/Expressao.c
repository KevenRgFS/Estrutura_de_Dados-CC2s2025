#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "expressao.h"

typedef struct GuardaNum{

    char calc[256];
    struct GuardaNum * Anterior;

} GuardaNum;

void Empilhar(GuardaNum ** topo, const char * calc)
{
    GuardaNum *novo = (GuardaNum *) malloc(sizeof(GuardaNum));
    strcpy(novo->calc, calc);
    novo->Anterior = *topo;
    *topo = novo;
};

char *Desempilhar(GuardaNum **topo)
{
    if(*topo == NULL)
    {
        printf("ERRO: a pilha está vázia.\n");
        return NULL;
    }

    GuardaNum *I = *topo;
    *topo = I->Anterior;
    char *restante = (char *) malloc(strlen(I->calc) + 1);
    strcpy(restante, I->calc);
    free(I);
    return restante;
};

char * getFormaInFixa(char *Str)
{
    GuardaNum * pilha = NULL;
    char Str2[512];
    strncpy(Str2, Str, sizeof(Str2));
    Str2[sizeof(Str2)-1] = 0;
        for (size_t i = 0; i < sizeof(Str2) && Str2[i] != '\0'; ++i) {
            if (Str2[i] == ',') Str2[i] = '.';
        }
    char *token = strtok(Str2, " ");

    while (token != NULL) 
    {
        if (strcmp(token, "+") != 0 && strcmp(token, "-") != 0 && strcmp(token, "*") != 0 && strcmp(token, "/") != 0 && strcmp(token, "^") != 0 && strcmp(token, "%") != 0 && strcmp(token, "seno") != 0 && strcmp(token, "sen") != 0 && strcmp(token, "sin") != 0 && strcmp(token, "cos") != 0 && strcmp(token, "tang") != 0 && strcmp(token, "tan") != 0 && strcmp(token, "raiz") != 0 && strcmp(token, "log") != 0) 
        {
            Empilhar(&pilha, token);
        }
        else
        {
            if (strcmp(token, "seno") == 0 || strcmp(token, "sen") == 0 || strcmp(token, "sin") == 0 || strcmp(token, "cos") == 0 || strcmp(token, "tang") == 0 || strcmp(token, "tan") == 0 || strcmp(token, "raiz") == 0 || strcmp(token, "log") == 0)
            {
                char *num = Desempilhar(&pilha);
                if (num == NULL) {
                    printf("ERRO: pilha vazia no cálculo de '%s'.\n", token);
                    return NULL;
                }
                char expr[512];
                snprintf(expr, sizeof(expr), "%s(%s)", token, num);
                Empilhar(&pilha, expr);
                free(num);
            }
            else
            {
                char *num1 = Desempilhar(&pilha);
                char *num2 = Desempilhar(&pilha);
                if (num1 == NULL || num2 == NULL) {
                    printf("ERRO: pilha vazia no cálculo de '%s'.\n", token);
                    free(num1);
                    free(num2);
                    return NULL;
                }

                char expr[512];
                snprintf(expr, sizeof(expr), "(%s%s%s)", num2, token, num1);
                Empilhar(&pilha, expr);
                free(num1);
                free(num2);
            }
        }
        token = strtok(NULL, " ");
    }

    char *inFixa = Desempilhar(&pilha);
    if (inFixa == NULL) {
        printf("ERRO: pilha ficou vazia na trasnformação para notação inFixa.\n");
        return NULL;
    }
    printf("\nA função declarada: %s\n", inFixa);

    return inFixa;
}

float getValorPosFixa(char *StrPosFixa)
{
    GuardaNum * pilha = NULL;
    char Str2[512];
    strncpy(Str2, StrPosFixa, sizeof(Str2));
    Str2[sizeof(Str2)-1] = 0;
    char *token = strtok(Str2, " ");
    #define PI 3.14159265

    while (token != NULL) 
    {
        if (strcmp(token, "+") != 0 && strcmp(token, "-") != 0 && strcmp(token, "*") != 0 && strcmp(token, "/") != 0 && strcmp(token, "^") != 0 && strcmp(token, "%") != 0 && strcmp(token, "seno") != 0 && strcmp(token, "sen") != 0 && strcmp(token, "sin") != 0 && strcmp(token, "cos") != 0 && strcmp(token, "tang") != 0 && strcmp(token, "tan") != 0 && strcmp(token, "raiz") != 0 && strcmp(token, "log") != 0) 
        {
            Empilhar(&pilha, token);
        }
        else
        {
            double resultado = 0.0;
            if (strcmp(token, "seno") == 0 || strcmp(token, "sen") == 0 || strcmp(token, "sin") == 0 || strcmp(token, "cos") == 0 || strcmp(token, "tang") == 0 || strcmp(token, "tan") == 0 || strcmp(token, "raiz") == 0 || strcmp(token, "log") == 0) {
                char *num1 = Desempilhar(&pilha);
                if (num1 == NULL) {
                    printf("ERRO: pilha vazia no cálculo de '%s'.\n", token);
                    return 0;
                }
                double num = atof(num1);
                free(num1);
                if (strcmp(token, "seno") == 0 || strcmp(token, "sen") == 0 || strcmp(token, "sin") == 0) {
                    resultado = sin(num * PI / 180);
                } else if (strcmp(token, "cos") == 0) {
                    resultado = cos(num * PI / 180);
                } else if (strcmp(token, "tang") == 0 || strcmp(token, "tan") == 0) {
                    resultado = tan(num * PI / 180);
                } else if (strcmp(token, "raiz") == 0) {
                    if (num < 0) {
                        printf("ERRO: números negativos não são aceitos.\n");
                        return 0;
                    }
                    resultado = sqrt(num);
                } else if (strcmp(token, "log") == 0) {
                    resultado = log10(num);
                }
            }
            else
            {
                char *k1 = Desempilhar(&pilha);
                char *k2 = Desempilhar(&pilha);
                if (k1 == NULL || k2 == NULL) {
                    printf("ERRO: pilha vazia no cálculo de '%s'.\n", token);
                    free(k1);
                    free(k2);
                    return 0;
                }
                double num1 = atof(k1);
                double num2 = atof(k2);
                free(k1);
                free(k2);

                if (strcmp(token, "+") == 0) {
                    resultado = num2 + num1;
                } else if (strcmp(token, "-") == 0) {
                    resultado = num2 - num1;
                } else if (strcmp(token, "*") == 0) {
                    resultado = num2 * num1;
                } else if (strcmp(token, "/") == 0) {
                    resultado = num2 / num1;
                } else if (strcmp(token, "^") == 0) {
                    resultado = pow(num2, num1);
                } else if (strcmp(token, "%") == 0) {
                    resultado = (num1/100) * num2;
                }
            }

            char buffer[50];
            snprintf(buffer, sizeof(buffer), "%f", resultado);
            Empilhar(&pilha, buffer);
        }
        token = strtok(NULL, " ");
    }

    char *k = Desempilhar(&pilha);
    if (k == NULL) {
        printf("ERRO: pilha vazia ao obter valor final.\n");
        return 0;
    }
    float valorFinal = atof(k);
    free(k);
    printf("O valor da expressão é: %.2f\n\n", valorFinal);
    return valorFinal;
}

