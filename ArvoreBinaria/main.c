#include<stdio.h>
#include<stdlib.h>
#include"arvorebin.h"

int main()
{
    ptr_tNoArvore arvore1 = NULL;

    inicializaRaiz(&arvore1,20);
    //exibePreOrdem(arvore1);
    insereEsquerda(&arvore1,30,20);
    insereDireita(&arvore1,40,20);
    insereEsquerda(&arvore1,50,30);
    insereDireita(&arvore1,60,30);
    insereEsquerda(&arvore1,70,40);
    insereDireita(&arvore1,80,40);
    exibePreOrdem(arvore1);
    putchar('\n');
    exibeInOrdem(arvore1);
    putchar('\n');
    exibePosOrdem(arvore1);
    putchar('\n');
    return 0;
}
