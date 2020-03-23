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

typedef struct auxElem{
    REGISTRO reg;
    struct auxElem* ant;
    struct auxElem* prox;
}ELEMENTO;

typedef ELEMENTO* PONT;

typedef struct{
    PONT cabeca;
}DEQUE;

//Inicialização

void inicializarDeque(DEQUE* d){
    d->cabeca = (PONT) malloc(sizeof(ELEMENTO));
    d->cabeca->prox = d->cabeca;
    d->cabeca->ant = d->cabeca;
}

//Retornar número de elementos

int tamanho (DEQUE* d){
    PONT end = d->cabeca->prox;
    int tam = 0;
    while (end != d->cabeca){
        tam++;
        end = end->prox;
    }
    return tam;
}

//Impressão dos elementos do Deque

void exibirDequeFim(DEQUE* d){
    PONT end = d->cabeca->ant;
    printf("Deque partindo do fim: \" ");
    while(end != d->cabeca){
        printf("%i", end->reg.chave);
        end = end->ant;
    }
    printf("\"\n");
}

//Inserção de um elemento

bool inserirDequeFim(DEQUE* d, REGISTRO reg){
    PONT novo = (PONT)malloc(sizeof(ELEMENTO));
    novo->reg = reg;
    novo->prox = d->cabeca;
    novo->ant = d->cabeca->ant;
    d->cabeca->ant = novo;
    novo->ant->prox = novo;
    return true;
}

//Exclusão de um elemento

bool excluirElemDequeInicio(DEQUE* d, REGISTRO* reg){
    if(d->cabeca->prox == d->cabeca) return false;
    PONT apagar = d->cabeca->prox;
    *reg = apagar->reg;
    d->cabeca->prox = apagar->prox;
    apagar->prox->ant = d->cabeca;
    free(apagar);
    return true;
}

//Reinicialização de deque

void reinicializarDeque(DEQUE* d){
    PONT end = d->cabeca->prox;
    while (end != d->cabeca){
        PONT apagar = end;
        end = end->prox;
        free(apagar);
    }
    d->cabeca->prox = d->cabeca;
    d->cabeca->ant = d->cabeca;
}


int main(){
    DEQUE deque;
    inicializarDeque(&deque);
    printf("Numero de elementos no deque: %i.\n",tamanho(&deque));
    REGISTRO reg;
    reg.chave = 9;
    inserirDequeFim(&deque, reg);
    reg.chave = 3;
    inserirDequeFim(&deque, reg);
    reg.chave = 7;
    inserirDequeFim(&deque, reg);
    printf("Numero de elementos no deque: %i.\n",tamanho(&deque));
    exibirDequeFim(&deque);
    excluirElemDequeInicio(&deque, &reg);
    exibirDequeFim(&deque);
    reinicializarDeque(&deque);
    exibirDequeFim(&deque);
    system("pause");
    return 0;
}
