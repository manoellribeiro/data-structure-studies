#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define true 1
#define false 0

typedef int bool;
typedef int TIPOCHAVE;

typedef struct {
    TIPOCHAVE chave;
} REGISTRO;

typedef struct auxiliar{
    REGISTRO registro;
    struct auxilar* proximoElemento;
} ELEMENTO, *PONTEIROPARAELEMENTO;

typedef struct{
    PONTEIROPARAELEMENTO inicio;
    PONTEIROPARAELEMENTO fim;
} FILA;

//Inicialização

void inicializarFila(FILA* fila){
    fila->inicio = NULL;
    fila->fim = NULL;
}

//Retornar tamanho da Fila

int tamanhoDaFila(FILA* fila){
    PONTEIROPARAELEMENTO elementoAtual = fila->inicio;
    int tamanho = 0;
    while (elementoAtual != NULL){
        tamanho ++;
        elementoAtual = elementoAtual->proximoElemento;
    }
    return tamanho;
}

//Impressão dos elementos da Fila

void exibirFila(FILA* fila){
    PONTEIROPARAELEMENTO posicaoNaFila = fila->inicio;
    printf("Fila: \" ");
    while (posicaoNaFila != NULL){
        printf("%i", posicaoNaFila->registro.chave);
        posicaoNaFila = posicaoNaFila->proximoElemento;
    }
    printf("\"\n");
}

//Inserção de Um Elemento

bool inserirElementoNaFila(FILA* fila, REGISTRO registro){
    PONTEIROPARAELEMENTO novoElemento = (PONTEIROPARAELEMENTO)malloc(sizeof(ELEMENTO));
    novoElemento->registro = registro;
    novoElemento->proximoElemento = NULL;
    if(fila->inicio == NULL) fila->inicio = novoElemento;
    else fila->fim->proximoElemento = novoElemento;
    fila->fim = novoElemento;
    return true;
}

//Exclusão de um Elemento

bool excluirElementoDaFila(FILA* fila, REGISTRO* registro){
    if(fila->inicio == NULL) return false;
    *registro = fila->inicio->registro;
    PONTEIROPARAELEMENTO elementoQueSeraApagado = fila->inicio;
    fila->inicio = fila->inicio->proximoElemento;
    free(elementoQueSeraApagado);
    if(fila->inicio == NULL) fila->fim = NULL;
    return true;
}

//Reinicializar a Fila

void reinicializarFila(FILA* fila){
    PONTEIROPARAELEMENTO elementoAtual = fila->inicio;
    while(elementoAtual != NULL){
        PONTEIROPARAELEMENTO elementoQueSeraApagado = elementoAtual;
        elementoAtual = elementoAtual->proximoElemento;
        free(elementoQueSeraApagado);
    }
    fila->inicio = NULL;
    fila->fim = NULL;
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



