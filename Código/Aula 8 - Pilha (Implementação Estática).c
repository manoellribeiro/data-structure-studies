#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX 50
#define true 1
#define false 0

typedef int bool;
typedef int TIPOCHAVE;

typedef struct{
    TIPOCHAVE chave; 
}REGISTRO;

typedef struct{
    REGISTRO A[MAX];
    int topo;
}PILHA;

//Inicialização

void inicializarPilha(PILHA* p){
    p->topo = -1;
}

//Retornar número de elementos

int tamanhoPilha(PILHA* p){
    return (p->topo + 1);
}

//Exibir ou imprimir elementos da Pilha

void exibirPilha(PILHA* p){
    printf("Pilha: \" ");
    int i;
    for (i = p->topo; i >= 0; i--){
        printf("%i", p->A[i].chave);
    }
    printf("\" \n ");
}

//Inserção de um elemento - Push

bool inserirElemento(PILHA* p, REGISTRO reg){
    if(p->topo >= (MAX - 1)) return false;
    p->topo = (p->topo + 1);
    p->A[p->topo] = reg;
    return true;
}

//Exclusão de um elemento - Pop

bool excluirElementoPilha(PILHA* p, REGISTRO* reg){
    if(p->topo == -1) return false;
    *reg = p->A[p->topo];
    p->topo = (p->topo - 1);
}

//Reinicialização da Pilha

void reinicializarPilha(PILHA* p){
    p->topo = -1;
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



