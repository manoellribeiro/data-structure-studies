#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define MAX 50

#define true 1
#define false 0

typedef int bool;
typedef int TIPOCHAVE;

typedef struct {
    TIPOCHAVE chave;
}REGISTRO;

typedef struct {
    REGISTRO A[MAX];
    int topo1;
    int topo2;
}PILHADUPLA;


//Inicialização

void inicializarPilhaDupla(PILHADUPLA* pilha){
    pilha->topo1 = -1;
    pilha->topo2 = MAX;
}

//Retornar número de elementos

int tamanhoPilhaDupla(PILHADUPLA* pilha){
    int tamanhoPilha1 = (pilha->topo1 + 1);
    int tamanhoPilha2 = (MAX - pilha->topo2); 
    return tamanhoPilha1 + tamanhoPilha2;
}

//Exibição ou Impressão

bool exibirUmaPilha(PILHADUPLA* pilha, int qualPilhaExibir){
    if(qualPilhaExibir < 1 || qualPilhaExibir > 2) return false;
    printf("Pilha %i:\" ", qualPilhaExibir);
    int i;
    if(qualPilhaExibir == 1){
        for(i = pilha->topo1; i > 0; i--) printf("%i", pilha->A[i].chave);
    } else for(i = pilha->topo2; i<MAX; i++) printf("%i", pilha->A[i].chave);
    printf("\"\n");
    return true;
}

//Inserção de um elemento (push)

bool inserirElementoPilha(PILHADUPLA* pilha, REGISTRO registro, int qualPilharInserir){
    if(qualPilharInserir < 1 || qualPilharInserir > 2) return false;
    if(pilha->topo1 + 1 == pilha->topo2) return false;
    if(qualPilharInserir == 1){
        pilha->topo1 = pilha->topo1 + 1;
        pilha->A[pilha->topo1] = registro;
    } else {
        pilha->topo2 = pilha->topo2 - 1;
        pilha->A[pilha->topo2] = registro;
    }
    return true;
}

//Exclusão de um elemento (pop)

bool excluirElementoPilha(PILHADUPLA* pilha, REGISTRO* registro, int deQualPilharExcluir){
    if(deQualPilharExcluir < 1 || deQualPilharExcluir > 2) return false;
    if(deQualPilharExcluir == 1){
        if(pilha->topo1 == -1) return false;
        *registro = pilha->A[pilha->topo1];
    } else {
        if(pilha->topo2 == MAX) return false;
        *registro = pilha->A[pilha->topo2];
        pilha->topo2 = pilha->topo2 + 1;
    }
    return true;
}

//Reinicialização de uma Pilha Dupla

void reinicializarPilha(PILHADUPLA* pilha){
    inicializarPilhaDupla(pilha);
}

int main(){
    PILHADUPLA pillhaDupla;
    inicializarPilhaDupla(&pillhaDupla);
    printf("Numero de elementos na pilha: %i.\n",tamanhoPilhaDupla(&pillhaDupla));
    REGISTRO registro;
    registro.chave = 9;
    inserirElementoPilha(&pillhaDupla, registro, 1);
    registro.chave = 3;
    inserirElementoPilha(&pillhaDupla, registro, 2);
    registro.chave = 7;
    inserirElementoPilha(&pillhaDupla, registro, 1);
    printf("Numero de elementos no pillhaDupla: %i.\n",tamanhoPilhaDupla(&pillhaDupla));
    exibirUmaPilha(&pillhaDupla, 1);
    exibirUmaPilha(&pillhaDupla, 2);
    excluirElementoPilha(&pillhaDupla, &registro, 1);
    exibirUmaPilha(&pillhaDupla, 1);
    reinicializarPilha(&pillhaDupla);
    exibirUmaPilha(&pillhaDupla, 1);
    exibirUmaPilha(&pillhaDupla, 2);
    system("pause");
    return 0;
}