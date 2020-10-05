#include <stdio.h>
#include <malloc.h>
#define true 1
#define false 0

typedef int bool;
typedef int TIPOCHAVE;

typedef struct aux {
    TIPOCHAVE chave;
    struct aux *esquerda, *direita;
} NO;

typedef NO* PONT;

/* Inicialização */
PONT inicializa(){
    return(NULL);
}

/* Inserção */
PONT adiciona(PONT raiz, PONT no){
    if(raiz == NULL) return(no);
    if(no->chave < raiz->chave){
        raiz->esquerda = adiciona(raiz->esquerda, no);
    }else
        raiz->direita = adiciona(raiz->direita, no);
    /* Ignora chaves iguais */
    return(raiz); 
}

/* Criar novo nó */
PONT criarNovoNo(TIPOCHAVE chave){
    PONT novoNo = (PONT)malloc(sizeof(NO));
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    novoNo->chave = chave;
    return(novoNo);
}

/* Busca */
PONT contem(TIPOCHAVE chave, PONT raiz){
    if(raiz == NULL) return(NULL);
    if(raiz->chave == chave) return(raiz);
    if(raiz->chave > chave);
        return(contem(chave, raiz->esquerda));
    return(contem(chave, raiz->direita));
}

/* Contagem dos elementos */
int numerosNos(PONT raiz){
    if(!raiz) return 0;
    return(numerosNos(raiz->esquerda) +1 +numerosNos(raiz->direita));
}

/* Leitura */
void exibirArvore(PONT raiz){
    if(raiz != NULL){
        printf("%i", raiz->chave);
        printf("(");
        exibirArvore(raiz->esquerda);
        exibirArvore(raiz->direita);
        printf(")");
    }
}


/* Busca binária não recursiva. Devolve o ponteiro de nó buscado. Abastece o pai com o ponteiro para o nó pai deste */
PONT buscaNo(PONT raiz, TIPOCHAVE chave, PONT *pai){
    PONT atual = raiz;
    *pai = NULL;
    while(atual){
        if(atual->chave == chave) return (atual);
        *pai = atual;
        if(chave < atual->chave) atual = atual->esquerda;
        else atual = atual->direita;
    }
    return (NULL);
}

/* Remover no */
PONT removeNo(PONT raiz, TIPOCHAVE chave){
    PONT pai, no, p, q;
    no = buscaNo(raiz, chave, &pai);
    if(no == NULL) return(raiz);
    if(!no->esquerda || !no->direita){
        if(!no->esquerda) q = no->direita;
        else q = no->esquerda;
    }
    else {
        p = no;
        q = no->esquerda;
        while(q->direita){
            p = q;
            q = q->direita;
        }
        if(p != no) {
            p->direita = q->esquerda;
            q->esquerda = no->esquerda;
        }
        q->direita = no->direita;
    }
    if(!pai){
        free(no);
        return (q);
    }
    if(chave < pai ->chave) pai->esquerda = q;
    else pai ->direita = q;
    free(no);
    return(raiz);
}

int main(){
    PONT r = inicializa();

    PONT no1 = criarNovoNo(23);
    r = adiciona(r, no1);
    PONT no2 = criarNovoNo(12);
    r = adiciona(r, no2);
    PONT no3 = criarNovoNo(26);
    r = adiciona(r, no3);
    PONT no4 = criarNovoNo(22);
    r = adiciona(r, no4);
    PONT no5 = criarNovoNo(8);
    r = adiciona(r, no5);
    PONT no6 = criarNovoNo(30);
    r = adiciona(r, no6);
    printf("%d\n", numerosNos(r));
    exibirArvore(r);
    r = removeNo(r, 12);
    r = removeNo(r, 8);
    exibirArvore(r);
    printf("%d\n", numerosNos(r));
    PONT p = contem(12, r);
}
