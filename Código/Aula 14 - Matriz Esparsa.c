#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define true 1
#define false 0

typedef int bool;

typedef struct tempNo {
    float valor;
    int coluna;
    struct tempNo* prox;
} NO;

typedef NO* PONT;

typedef struct {
    PONT* A;
    int linhas;
    int colunas;
} MATRIZ;

//Inicialização

void inicializarMatriz(MATRIZ* matriz, int linhas, int colunas){
    int i;
    matriz->linhas = linhas;
    matriz->colunas = colunas;
    matriz->A = (PONT*) malloc(linhas*sizeof(PONT));
    for (i = 0; i < linhas; i++) matriz->A[i] = NULL;
}

//Atribuir valor

bool atribuirValorNaMatriz(MATRIZ* matriz, int linha, int coluna, float valor){
    if(linha < 0 || linha >= matriz->linhas || coluna < 0 || coluna >= matriz->colunas) return false;
    PONT anterior = NULL;
    PONT atual = matriz->A[linha];
    while (atual != NULL && atual->coluna < coluna)
    {
        anterior = atual;
        atual = atual->prox;
    }
    if(atual != NULL && atual->coluna == coluna){
        if(valor == 0){
            if(anterior == NULL) matriz->A[linha] = atual->prox;
            else anterior->prox = atual->prox;
            free(atual);
        }
        else atual->valor = valor;
    }
    else {
        PONT novo = (PONT) malloc(sizeof(NO));
        novo->coluna = coluna;
        novo->valor = valor;
        novo->prox = atual;
        if (anterior == NULL) matriz->A[linha] = novo;
        else anterior->prox = novo;
    }
    return true;
}

//Acessar valor

float acessarValorDaMatriz(MATRIZ* matriz, int linha, int coluna){
    if(linha < 0 || linha >= matriz->linhas || coluna<0 || coluna >= matriz->colunas){
        return 0;
    }
    PONT atual = matriz->A[linha];
    while (atual != NULL && atual->coluna < coluna)
    {
        atual = atual->prox;
    }
    if (atual != NULL && atual->coluna == coluna)
    {
        return atual->valor;
    }
    return 0;
}

int main(){
    MATRIZ matriz;
    inicializarMatriz(&matriz, 3, 3);
    atribuirValorNaMatriz(&matriz, 1, 1, 1);
    atribuirValorNaMatriz(&matriz, 2, 1, 2);
    atribuirValorNaMatriz(&matriz, 3, 2, 3);
    printf("Valor da matriz: %f.\n",acessarValorDaMatriz(&matriz, 1, 1));
    printf("Valor da matriz: %f.\n",acessarValorDaMatriz(&matriz, 2, 1));
    printf("Valor da matriz: %f.\n",acessarValorDaMatriz(&matriz, 3, 2  ));
    printf("Valor da matriz: %f.\n",acessarValorDaMatriz(&matriz, 1, 2));
    system("pause");
    return 0;
}