#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


#define true 1
#define false 0

typedef int bool;
typedef int TIPOCHAVE;

typedef struct{
    TIPOCHAVE chave;
}REGISTRO;

typedef struct aux{
    REGISTRO reg;
    struct aux* prox;
}ELEMENTO;

typedef ELEMENTO* PONT;

typedef struct{
    PONT topo;
}PILHA;

//Inicialização

void inicializarPilha(PILHA* p){
    p->topo = NULL;
}

//Retornar número de elementos

int tamanhoPilha(PILHA* p){
    PONT end = p->topo;
    int tam = 0;
    while(end != NULL){
        tam++;
        end = end->prox; 
    }
    return tam;
}

//Verificando se a pilha está vazia

bool estaVazia(PILHA* p){
    if(p->topo == NULL) return true;
    return false;
}

//Exibir ou Imprimir Elementos da Pilha

void exibirPilha(PILHA* p){
    PONT end  = p->topo;
    printf("Pilha: \" ");
    while(end != NULL){
        printf("%i", end->reg.chave);
        end = end->prox;
    }
    printf("\" \n");
}

//Inserção de um elemento - Push

bool inserirElemento(PILHA* p, REGISTRO reg){
    PONT novo = (PONT) malloc(sizeof(ELEMENTO));
    novo->reg = reg;
    novo->prox = p->topo;
    p->topo = novo;
    return true;
}

//Exclusão de um elemento - Pop

bool excluirElementoPilha(PILHA* p, REGISTRO* reg){
    if(p->topo == NULL) return false;
    *reg = p->topo->reg;
    PONT apagar = p->topo;
    p->topo = p->topo->prox;
    free(apagar);
    return true;
}

//Reinicialização da Pilha

void reinicializarPilha(PILHA* p){
    PONT apagar;
    PONT posicao = p->topo;
    while(posicao != NULL){
        apagar = posicao;
        posicao = posicao->prox;
        free(apagar);
    }
    p->topo = NULL;
}


int main(){
    PILHA pilha;
    inicializarPilha(&pilha);
    printf("Numero de elementos na pilha: %i.\n",tamanhoPilha(&pilha));
    REGISTRO reg;
    reg.chave = 9;
    inserirElemento(&pilha, reg);
    reg.chave = 3;
    inserirElemento(&pilha, reg);
    reg.chave = 7;
    inserirElemento(&pilha, reg);
    printf("Numero de elementos na pilha: %i.\n",tamanhoPilha(&pilha));
    exibirPilha(&pilha);
    excluirElementoPilha(&pilha, &reg);
    exibirPilha(&pilha);
    reinicializarPilha(&pilha);
    exibirPilha(&pilha);
    system("pause");
    return 0;
}
