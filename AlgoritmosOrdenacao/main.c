#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <conio2.h>
#include <windows.h>
#include "geraArray.h"
#include "hr_time.h"

long trocas = 0, comparacoes = 0, chRecur = 0;

void bubbleSort(tipoArray *arrayDesord, int tamArray);

void quickSort(int *arrayDesord, int eleEsq, int eleDir);

void selecaoDireta(int *arrayDesord, int tamArray);

void contagemMenores(tipoArray *arrayDesord, int tamArray);

int main()
{
    int tamArray = 0;
    double tTempo;
    stopWatch tempo;
    tipoArray *crescente = NULL, *decrescente = NULL, *desordenado = NULL, *copiaDesord = NULL;

    do{
        system("cls");
        textcolor(YELLOW);
        printf("PERFORMANCE EM ALGORITMOS DE ORDENACAO\n\n\n");
        textcolor(WHITE);
        printf("Digite um numero para o tamanho do ARRAY: ");
        scanf("%d",&tamArray);
        fflush(stdin);

        ///Geração e cópia dos arrays

        geraArray(tamArray,&crescente,&decrescente);
        geraArrayDesord(tamArray,&desordenado);
        copiaArray(tamArray,desordenado,&copiaDesord);
        imprimirArray(tamArray,crescente);
        putchar('\n');
        imprimirArray(tamArray,decrescente);
        putchar('\n');
        imprimirArray(tamArray,desordenado);
        putchar('\n');

        ///Seção BubbleSort

        ///Melhor caso

        startTimer(&tempo);
        bubbleSort(crescente,tamArray);
        stopTimer(&tempo);
        tTempo = getElapsedTime(&tempo);
        printf("\n------------------------------BubbleSort------------------------------\n\n");
        printf("Melhor caso\n%ld trocas, %ld comparacoes, %ld c.recur e t.proc de %fms\n\n",trocas,comparacoes,chRecur,tTempo);
        comparacoes=chRecur=trocas=0;

        ///Pior caso

        startTimer(&tempo);
        bubbleSort(decrescente,tamArray);
        stopTimer(&tempo);
        tTempo = getElapsedTime(&tempo);
        printf("Pior caso\n%ld trocas, %ld comparacoes, %ld c.recur e t.proc de %fms\n\n",trocas,comparacoes,chRecur,tTempo);
        comparacoes=chRecur=trocas=0;

        ///Caso Médio

        startTimer(&tempo);
        bubbleSort(copiaDesord,tamArray);
        stopTimer(&tempo);
        tTempo = getElapsedTime(&tempo);
        printf("Caso medio\n%ld trocas, %ld comparacoes, %ld c.recur e t.proc de %fms\n\n",trocas,comparacoes,chRecur,tTempo);
        comparacoes=chRecur=trocas=0;

        ///Impressão dos arrays ordenados

        imprimirArray(tamArray,crescente);
        putchar('\n');
        imprimirArray(tamArray,decrescente);
        putchar('\n');
        imprimirArray(tamArray,copiaDesord);
        putchar('\n');

        ///Geração e cópia dos arrays

        geraArray(tamArray,&crescente,&decrescente);
        copiaArray(tamArray,desordenado,&copiaDesord);

        ///Seção QuickSort

        ///Melhor caso

        startTimer(&tempo);
        quickSort(crescente,0,tamArray-1);
        stopTimer(&tempo);
        tTempo = getElapsedTime(&tempo);
        printf("\n------------------------------QuickSort------------------------------\n\n");
        printf("Melhor caso\n%ld trocas, %ld comparacoes, %ld c.recur e t.proc de %fms\n\n",trocas,comparacoes,chRecur,tTempo);
        comparacoes=chRecur=trocas=0;

        ///Pior caso

        startTimer(&tempo);
        quickSort(decrescente,0,tamArray-1);
        stopTimer(&tempo);
        tTempo = getElapsedTime(&tempo);
        printf("Pior caso\n%ld trocas, %ld comparacoes, %ld c.recur e t.proc de %fms\n\n",trocas,comparacoes,chRecur,tTempo);
        comparacoes=chRecur=trocas=0;

        ///Caso médio

        startTimer(&tempo);
        quickSort(copiaDesord,0,tamArray-1);
        stopTimer(&tempo);
        tTempo = getElapsedTime(&tempo);
        printf("Caso medio\n%ld trocas, %ld comparacoes, %ld c.recur e t.proc de %fms\n\n",trocas,comparacoes,chRecur,tTempo);
        comparacoes=chRecur=trocas=0;

        ///Impressão dos arrays ordenados

        imprimirArray(tamArray,crescente);
        putchar('\n');
        imprimirArray(tamArray,decrescente);
        putchar('\n');
        imprimirArray(tamArray,copiaDesord);
        putchar('\n');

        ///Geração e cópia dos arrays

        geraArray(tamArray,&crescente,&decrescente);
        copiaArray(tamArray,desordenado,&copiaDesord);

        ///Seção Seleção direta

        ///Melhor caso

        startTimer(&tempo);
        selecaoDireta(crescente,tamArray);
        stopTimer(&tempo);
        tTempo = getElapsedTime(&tempo);
        printf("\n------------------------------SelecaoDireta------------------------------\n\n");
        printf("Melhor caso\n%ld trocas, %ld comparacoes, %ld c.recur e t.proc de %fms\n\n",trocas,comparacoes,chRecur,tTempo);
        comparacoes=chRecur=trocas=0;

        ///Pior caso

        startTimer(&tempo);
        selecaoDireta(decrescente,tamArray);
        stopTimer(&tempo);
        tTempo = getElapsedTime(&tempo);
        printf("Pior caso\n%ld trocas, %ld comparacoes, %ld c.recur e t.proc de %fms\n\n",trocas,comparacoes,chRecur,tTempo);
        comparacoes=chRecur=trocas=0;

        ///Caso médio

        startTimer(&tempo);
        selecaoDireta(copiaDesord,tamArray);
        stopTimer(&tempo);
        tTempo = getElapsedTime(&tempo);
        printf("Caso medio\n%ld trocas, %ld comparacoes, %ld c.recur e t.proc de %fms\n\n",trocas,comparacoes,chRecur,tTempo);
        comparacoes=chRecur=trocas=0;

        ///Impressão dos arrays ordenados

        imprimirArray(tamArray,crescente);
        putchar('\n');
        imprimirArray(tamArray,decrescente);
        putchar('\n');
        imprimirArray(tamArray,copiaDesord);
        putchar('\n');

         ///Geração e cópia dos arrays

        geraArray(tamArray,&crescente,&decrescente);
        copiaArray(tamArray,desordenado,&copiaDesord);

        ///Seção Contagem do menores

        ///Melhor caso

        startTimer(&tempo);
        contagemMenores(crescente,tamArray);
        stopTimer(&tempo);
        tTempo = getElapsedTime(&tempo);
        printf("\n------------------------------ContagemMenores------------------------------\n\n");
        printf("Melhor caso\n%ld trocas, %ld comparacoes, %ld c.recur e t.proc de %fms\n\n",trocas,comparacoes,chRecur,tTempo);
        comparacoes=chRecur=trocas=0;

        ///Pior caso

        startTimer(&tempo);
        contagemMenores(decrescente,tamArray);
        stopTimer(&tempo);
        tTempo = getElapsedTime(&tempo);
        printf("Pior caso\n%ld trocas, %ld comparacoes, %ld c.recur e t.proc de %fms\n\n",trocas,comparacoes,chRecur,tTempo);
        comparacoes=chRecur=trocas=0;

        ///Caso médio

        startTimer(&tempo);
        contagemMenores(copiaDesord,tamArray);
        stopTimer(&tempo);
        tTempo = getElapsedTime(&tempo);
        printf("Caso medio\n%ld trocas, %ld comparacoes, %ld c.recur e t.proc de %fms\n\n",trocas,comparacoes,chRecur,tTempo);
        comparacoes=chRecur=trocas=0;

        ///Impressão dos arrays ordenados

        imprimirArray(tamArray,crescente);
        putchar('\n');
        imprimirArray(tamArray,decrescente);
        putchar('\n');
        imprimirArray(tamArray,copiaDesord);
        putchar('\n');

        printf("\n\n\n\n ESC para sair.... Qualquer tecla para continuar...");
        fflush(stdin);
    }while(getch() != 27);

    free(crescente);
    free(decrescente);
    free(desordenado);
    free(copiaDesord);

    return 0;
}

void bubbleSort(tipoArray *arrayDesord, int tamArray){///Função ordena no mesmo array do recebimento
    tipoArray varAux;
    int i = 0, j = 0, tam;
    tam = tamArray;

    for (i=0; i < tam-1; i++){
        for (j=0; j < tam-1; j++){
            comparacoes++;
            if(arrayDesord[j] > arrayDesord[j+1]){
                varAux = arrayDesord[j];
                arrayDesord[j] = arrayDesord[j+1];
                arrayDesord[j+1] = varAux;
                trocas++;
            }else varAux = arrayDesord[j+1];
        }j = 0;
    }
    return;
}

void quickSort(tipoArray *arrayDesord, int eleEsq, int eleDir){
    int i, j, elePivo, temp;

    chRecur++;
    i = eleEsq;///eleEsq recebe zero
    j = eleDir;///eleDir recebe tamArray - 1
    elePivo = arrayDesord[(eleEsq + eleDir) / 2];/// Pivô recebe o elemento do meio do vetor passado

    while(i <= j) {
        while(arrayDesord[i] < elePivo && i < eleDir){
            comparacoes++;
            i++;
        }
        while(arrayDesord[j] > elePivo && j > eleEsq){
            comparacoes++;
            j--;
        }
        if(i <= j) {
            trocas++;
            temp = arrayDesord[i];
            arrayDesord[i] = arrayDesord[j];
            arrayDesord[j] = temp;
            i++;
            j--;
        }
    }
    if(j > eleEsq)
        quickSort(arrayDesord, eleEsq, j);
    if(i < eleDir)
        quickSort(arrayDesord, i, eleDir);
}

void selecaoDireta(int *arrayDesord, int tamArray){

    int i, j, menor, temp;

    for(i=0;i<tamArray-1;i++){
        menor = i;
        for(j=i+1;j<tamArray;j++){
            comparacoes++;
            if(arrayDesord[j] < arrayDesord[menor])
                menor = j;
        }
        temp = arrayDesord[i];
        arrayDesord[i] = arrayDesord[menor];
        arrayDesord[menor] = temp;
        trocas++;
    }
}

void contagemMenores(tipoArray *arrayDesord, int tamArray){
    tipoArray *d = NULL, *e =NULL;
    int i, j;

    d = (tipoArray*) malloc(tamArray*sizeof(tipoArray));///Array auxiliar das posições
    if(d == NULL) return;
    e = (tipoArray*) malloc(tamArray*sizeof(tipoArray));///Array auxiliar
    if(e == NULL) return;

    for(i=0;i<tamArray;i++)///Popula com zero todos os elementos do array auxiliar de posição
        d[i] = 0;
    for(i=1;i<tamArray;i++)
        for(j=i-1;j>=0;j--){
            comparacoes++;
            if(arrayDesord[i] < arrayDesord[j])
                d[j]+=1;
            else
                d[i]+=1;
        }
    for(i=0;i<tamArray;i++){
        trocas++;
        e[d[i]] = arrayDesord[i];
    }
    for(i=0;i<tamArray;i++)///Preenche arrayDesord de forma ordenada
        arrayDesord[i] = e[i];

    free(d);
    free(e);

    return;
}
