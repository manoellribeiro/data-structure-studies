#include <conio.h>
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
} REGISTRO;

typedef struct {
    REGISTRO A[MAX];
    int inicio;
    int numeroDeElementos;
} FILA;

//Inicialização

void inicializarFila(FILA* f){
    f->inicio = 0;
    f->numeroDeElementos = 0; 
}

//Retornar número de Elementos

int tamanhoDaFila(FILA* f){
    return f->numeroDeElementos;
}

//Impressão dos Elementos

void exibirFila(FILA* f){
    printf("FILA: \" ");
    int i = f->inicio;
    int elementosImprimidos;
    for(elementosImprimidos = 0; elementosImprimidos < f->numeroDeElementos; elementosImprimidos++){
        printf("%i", f->A[i].chave);
        i = (i + 1) % MAX;
    }
    printf("\"\n");
}

//Inserção de um elemento

bool inserirElementoNaFila(FILA* f, REGISTRO registro){
    if(f->numeroDeElementos >= MAX) return false;
    int posicaoDaInsercao = (f->inicio + f->numeroDeElementos) % MAX;
    f->A[posicaoDaInsercao] = registro;
    f->numeroDeElementos++;
    return true;
}

//Exclusão de um elemento

bool excluirElementoDaFila(FILA* f, REGISTRO* registro){
    if(f->numeroDeElementos == 0) return false;
    *registro = f->A[f->inicio];
    f->inicio = (f->inicio + 1) % MAX;
    f->numeroDeElementos--;
    return true;
}

//Reinicialização da Fila Estática

void reinicializarFila(FILA* f){
    f->inicio = 0;
    f->numeroDeElementos = 0;
}


int main(){
    FILA fila;
    inicializarFila(&fila);
    printf("Numero de elementos no fila: %i.\n",tamanhoDaFila(&fila));
    REGISTRO registro;
    registro.chave = 9;
    inserirElementoNaFila(&fila, registro);
    registro.chave = 3;
    inserirElementoNaFila(&fila, registro);
    registro.chave = 7;
    inserirElementoNaFila(&fila, registro);
    printf("Numero de elementos no fila: %i.\n",tamanhoDaFila(&fila));
    exibirFila(&fila);
    excluirElementoDaFila(&fila, &registro);
    exibirFila(&fila);
    reinicializarFila(&fila);
    exibirFila(&fila);
    system("pause");
    return 0;
}

