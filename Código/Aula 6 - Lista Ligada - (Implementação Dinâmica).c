#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define false 0
#define true 1

typedef int bool;
typedef int TIPOCHAVE;

//Modelando Estrutura

typedef struct{
     TIPOCHAVE chave;
 }REGISTRO;

typedef struct aux{
    REGISTRO reg;
    struct aux* prox;  //Endereço de memória do próximo elemento
}ELEMENTO;

typedef ELEMENTO* PONT;

typedef struct{
    PONT inicio;
}LISTA;

//Inicialização

void inicializarLista(LISTA* l){
    l->inicio = NULL;
}

//Retornar número de elementos

int tamanho(LISTA* l){
    PONT end = l->inicio;
    int tam = 0;
    while (end != NULL){
        tam++;
        end = end->prox;
    }
    return tam;
}

//Impressão dos valores

void exibirLista(LISTA* l){
    PONT end = l->inicio;
    printf("Lista: \" ");
    while(end != NULL){
        printf("%i", end->reg.chave);
        end = end->prox;
    }
    printf("\"\n");
}

//Buscar por um elemento

PONT buscaSeqOrd(LISTA* l, TIPOCHAVE ch){
    PONT pos = l->inicio;
    while(pos != NULL && pos->reg.chave < ch){
        pos = pos->prox;
    }
    if(pos != NULL && pos->reg.chave == ch){
        return pos;
    }else{
        return NULL;
    }
}

//Inserção de um elemento

    //Busca Auxiliar

    PONT buscaSequencialExc(LISTA* l, TIPOCHAVE ch, PONT* ant){
        *ant = NULL;
        PONT atual = l->inicio;
        while((atual != NULL) && (atual->reg.chave < ch)){
            *ant = atual;
            atual = atual->prox;
        }
        if((atual != NULL) && (atual-> reg.chave == ch)){
            return atual;
        }else{
            return NULL;
        }
    }

bool inserirElemListaOrd(LISTA* l, REGISTRO reg){
    TIPOCHAVE ch = reg.chave;
    PONT ant, i;
    i = buscaSequencialExc(l, ch, &ant);
    if (i != NULL) return false;
    i = (PONT) malloc(sizeof(ELEMENTO));
    i->reg = reg;
    if(ant == NULL){
        i->prox = l->inicio;
        l->inicio = i;
    }else{
        i->prox = ant->prox;
        ant->prox = i;
    }
    return true;
}

//Exclusão de um elemento

bool excluirElemLista(LISTA* l, TIPOCHAVE ch){
    PONT ant, i;
    i = buscaSequencialExc(l, ch, &ant);
    if(i == NULL) return false;
    if(ant == NULL) l->inicio = i->prox;
    else ant->prox = i->prox;
    free(i);
    return true;
}

//Reinicialização da lista

void reinicializarLista(LISTA* l){
    PONT end = l->inicio;
    while(end != NULL){
        PONT apagar = end;
        end = end->prox;
        free(apagar);
    }
    l->inicio = NULL;
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
    printf("Numero de elementos na lista: %i.\n",tamanho(&lista));
    exibirLista(&lista);
    system("pause");
    return 0;
}
