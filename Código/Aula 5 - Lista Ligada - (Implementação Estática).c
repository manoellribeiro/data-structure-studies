#define MAX 50
#define INVALIDO -1
#define false 0
#define true 1
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

typedef int TIPOCHAVE;
typedef int bool;

typedef struct {
    TIPOCHAVE chave;
} REGISTRO;

typedef struct{
    REGISTRO reg;
    int prox;
} ELEMENTO;

typedef struct {
    ELEMENTO A[MAX];
    int inicio;
    int dispo;  //Mostra a posição do primeiro elemento disponível
} LISTA;

//Inicialização

void inicializarLista (LISTA* l){
    int i;
    for (i = 0; i<MAX; i++)
        l->A[i].prox = i + 1;
    l->A[MAX - 1].prox = INVALIDO;
    l->inicio = INVALIDO;
    l->dispo = 0;
}

//Retornar número de elementos

int tamanho (LISTA* l){
   int i = l->inicio;
   int tam = 0;
   while (i != INVALIDO){
       tam++;
       i = l->A[i].prox;
   }
   return tam;
}

//Imprimindo os valores da lista

void exibirLista(LISTA* l){
    int i = l->inicio;
    printf("Lista: \" ");
    while (i != INVALIDO){
        printf("%i", l->A[i].reg.chave);
        i = l->A[i].prox;
    }
    printf("\"\n");
}

//Busca Sequencial Ordenada

int buscaSequencialOrd(LISTA* l, TIPOCHAVE ch){
    int i = l->inicio;
    while(i != INVALIDO && l->A[i].reg.chave < ch){
        i = l->A[i].prox;
    }
    if (i != INVALIDO && l->A[i].reg.chave == ch){
        return i;
    }else{
        return INVALIDO;
    }
    
}

// Inserção de um elemento

    //Função Auxiliar - Obter No
    int obterNo(LISTA* l){
        int resultado = l->dispo;
        if (l->dispo != INVALIDO){
            l->dispo = l->A[l->dispo].prox;
        }
        return resultado;
    }

bool inserirElemListaOrd(LISTA* l, REGISTRO reg){
    if (l->dispo == INVALIDO) return false;
    int ant = INVALIDO;
    int i = l->inicio;
    TIPOCHAVE ch = reg.chave;
    while((i!=INVALIDO) && (l->A[i].reg.chave < ch)){
        ant = i;
        i = l->A[i].prox;
    }
    if( i != INVALIDO && l->A[i].reg.chave == ch) return false;
    i = obterNo(l);
    l->A[i].reg = reg;
    if(ant == INVALIDO){
        l->A[i].prox = l->inicio;
        l->inicio = i;
    }else{
        l->A[i].prox = l->A[ant].prox;
        l->A[ant].prox = i;
    }
    return true;
}

//Exclusão de um element

    //Função auxiliar - Devolver No
    void devolverNo(LISTA* l, int j){
        l->A[j].prox = l->dispo;
        l->dispo = j;
    }

bool excluirElemLista(LISTA* l, TIPOCHAVE ch){
    int ant = INVALIDO;
    int i = l->inicio;
    while(( i != INVALIDO) && (l->A[i].reg.chave < ch)){
        ant = i;
        i = l->A[i].prox;
    }
    if(i == INVALIDO || l->A[i].reg.chave != ch) return false;
    if(ant == INVALIDO){
        l->inicio = l->A[i].prox;
    }else{
        l->A[ant].prox = l->A[i].prox;
    }
    devolverNo(l, i);
    return true;
}

//Reinicialização da Lista

void reinicializarLista(LISTA* l){
    inicializarLista(l);
}


int main(){
    LISTA lista;
    inicializarLista(&lista);
    exibirLista(&lista);
    REGISTRO reg;
    printf("Numero de elementos na lista: %i.\n",tamanho(&lista));
    reg.chave = 9;
    inserirElemListaOrd(&lista, reg);
    reg.chave = 2;
    inserirElemListaOrd(&lista, reg);
    reg.chave = 10;
    inserirElemListaOrd(&lista, reg);
    exibirLista(&lista);
    system("pause");
    return 0;
}
