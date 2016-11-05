/** Instituto Federal de Educação, Ciência e Tecnologia
                Campus - João Pessoa
    Curso Superior Tecnológico em Redes de Computadores

                    Estruturas de Dados

            Professores Crishane e Daniel Cardoso

      Aluno Illo Atayde Macedo Duarte - Mat 20161380041

PROJETO II - Conversor de Expressões na forma infixa para posfixa

    Arquivo destinado às funções de manipulação das pilhas          */


#include<stdlib.h>
#include<stdio.h>
#include"pilha.h"

int empilha(ptrTNo *pilha,char chPush,int chT,int chP){
    ptrTNo novoNo;

    if(!(novoNo = (tNo*)malloc(sizeof(tNo))))
        return 0;
    novoNo->proxNo =*pilha;
    novoNo->chPPT = chPush;
    novoNo->chTipo = chT;
    novoNo->chPrior = chP;
    *pilha = novoNo;
    return 1;
}

int desempilha(ptrTNo *pilha, char *chPop){
    ptrTNo auxNo;
    auxNo = *pilha;
    *chPop = auxNo->chPPT;
    *pilha = auxNo->proxNo;
    free(auxNo);
    return 1;
}

int vazia(ptrTNo pilha){
    if(pilha == NULL)
        return 1;
    return 0;
}

int cheia(ptrTNo pilha){
    return 0;
}

char topo(ptrTNo pilha){
    char topoPilha;

    topoPilha = pilha->chPPT;
    return topoPilha;
}

void exibe(ptrTNo pilha){
    ptrTNo auxNo;

    auxNo = pilha;

    while(auxNo != NULL){
        printf("%c\n",auxNo->chPPT);
        auxNo = auxNo->proxNo;
    }
}

///Funções específicas para estrutura apontada por ptrNoFl

int empilhaFl(ptrTNoFl *pilha,float flPush){
    ptrTNoFl novoNoFl;

    if(!(novoNoFl = (tNoFl*)malloc(sizeof(tNoFl))))
        return 0;
    novoNoFl->proxNoFl = *pilha;
    novoNoFl->flPPT = flPush;
    *pilha = novoNoFl;
    return 1;
}

int desempilhaFl(ptrTNoFl *pilha, float *flPop){
    ptrTNoFl auxNoFl;
    auxNoFl = *pilha;
    *flPop = auxNoFl->flPPT;
    *pilha = auxNoFl->proxNoFl;
    free(auxNoFl);
    return 1;
}
