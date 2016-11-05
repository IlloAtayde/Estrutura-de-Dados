/*typedef struct noArvore{
    int dado;
    struct noArvore noEsq;
    struct noArvore noDir;
}tNoArvore;

typedef tNoArvore* ptr_tNoArvore;*/

#include<stdlib.h>
#include<stdio.h>
#include"arvorebin.h"

int inicializaRaiz(ptr_tNoArvore *arvore, int valor){
    ptr_tNoArvore novoNo;

    novoNo = (tNoArvore*) malloc(sizeof(tNoArvore));
    if(novoNo == NULL) return 0;
    novoNo->dado = valor;
    novoNo->noDir = NULL;
    novoNo->noEsq = NULL;
    *arvore = novoNo;
    return 1;
}


ptr_tNoArvore buscaNo(ptr_tNoArvore arvore, int valBusca){
    ptr_tNoArvore auxBusca = NULL;

    if (arvore == NULL) return NULL;
    if (arvore->dado == valBusca) return arvore;
    auxBusca = buscaNo(arvore->noEsq, valBusca);
    if (auxBusca != NULL)
        return auxBusca;
    auxBusca = buscaNo(arvore->noDir, valBusca);
    if (auxBusca != NULL)
        return auxBusca;
    return NULL;
}

int insereEsquerda(ptr_tNoArvore *arvore,int valor, int valRaiz){
    ptr_tNoArvore auxInsEsq, novoNo = NULL;

    auxInsEsq = buscaNo(*arvore,valRaiz);
    if (auxInsEsq == NULL) return 0;
    novoNo = (tNoArvore*) malloc(sizeof(tNoArvore));
    if (novoNo == NULL) return 0;
    novoNo->dado = valor;
    novoNo->noEsq = NULL;
    novoNo->noDir = NULL;
    auxInsEsq->noEsq = novoNo;
    return 1;

}

int insereDireita(ptr_tNoArvore *arvore,int valor, int valRaiz){
    ptr_tNoArvore auxInsDir, novoNo = NULL;

    auxInsDir = buscaNo(*arvore,valRaiz);
    if (auxInsDir == NULL) return 0;
    novoNo = (tNoArvore*) malloc(sizeof(tNoArvore));
    if (novoNo == NULL) return 0;
    novoNo->dado = valor;
    novoNo->noEsq = NULL;
    novoNo->noDir = NULL;
    auxInsDir->noDir = novoNo;
    return 1;

}

void exibePreOrdem(ptr_tNoArvore arvore){
    if(arvore == NULL) return;
    printf("%d ",arvore->dado);
    exibePreOrdem(arvore->noEsq);
    exibePreOrdem(arvore->noDir);
    return;
}

void exibeInOrdem(ptr_tNoArvore arvore){
    if(arvore == NULL) return;
    exibeInOrdem(arvore->noEsq);
    printf("%d ",arvore->dado);
    exibeInOrdem(arvore->noDir);
    return;
}

void exibePosOrdem(ptr_tNoArvore arvore){
    if(arvore == NULL) return;
    exibePosOrdem(arvore->noEsq);
    exibePosOrdem(arvore->noDir);
    printf("%d ",arvore->dado);
    return;
}
