// tamanho maximo do vetor estatico
#define MAX 50
#define LISTA_VAZIA -1
#define ERRO -1
#define true 1
#define false 0
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

// ------ Listas Lineares Sequenciais -----
typedef int bool;

typedef int TIPOCHAVE;

typedef struct{
  TIPOCHAVE chave;
  // outros campos...
} REGISTRO;

typedef struct {
	REGISTRO A[MAX + 1];    //Para permitir a busca utilizando um sentinela, essa posição extra nunca terá um valor válido.
	int nroElem;
} LISTA;

void inicializaListaSequencial(LISTA* l){
     l->nroElem = 0;
     }

void exibeLista(LISTA* l){
     int i;
     printf("Lista: \" ");
     for (i = 0; i < l->nroElem; i++)
         printf("%i", l->A[i].chave);
     printf("\"\n");
     }
     
     
int tamanho(LISTA* l){
    return l->nroElem;
    }
    
    
int ultimoElem(LISTA* l){
    if(l->nroElem > 0) return l->A[l->nroElem-1].chave;
    else return ERRO;
    }
    
    
int primeiroElem(LISTA* l){
    if(l->nroElem > 0) return l->A[0].chave;
    else return ERRO;
    }
    
    
int enesimoElem(LISTA* l, int n){
    if(l->nroElem > 0){
       if( n >= 0 && (n < l->nroElem)) return l->A[n].chave;
       else return ERRO;
    }else return ERRO;
    }
    
    
bool insere_na_posicao_i(REGISTRO elem, int i, LISTA *l){
     int j;
     if((l->nroElem == MAX) || (i < 0) || (i > l->nroElem)) 
        return (false);
     for (j = l->nroElem; j > i; j--) l->A[j] = l->A[j-1];
     l->A[i] = elem;
     l->nroElem++;
     return true;   
     }

int busca_sequencial(TIPOCHAVE elem, LISTA* l){
    int i = 0;
    l->A[l->nroElem].chave = elem;
    while(l->A[i].chave != elem) i++;
    if (i == l->nroElem) return ERRO;
    else return i;
    }  
    
    
int main(){
    LISTA lista;
    inicializaListaSequencial(&lista);
    exibeLista(&lista);
    REGISTRO reg;
    printf("Numero de elementos na lista: %i.\n",tamanho(&lista));
    reg.chave = 9;
    insere_na_posicao_i(reg, 0, &lista);
    reg.chave = 4;
    insere_na_posicao_i(reg, 1, &lista);
    reg.chave = 5;
    insere_na_posicao_i(reg, 2, &lista);
    exibeLista(&lista);
    printf("Numero de elementos na lista: %i.\n",tamanho(&lista));
    printf("Chave 4 encontrada na posicao: %i do arranjo A.\n",busca_sequencial(4,&lista));
    system ("pause");
    return 0;
    }
