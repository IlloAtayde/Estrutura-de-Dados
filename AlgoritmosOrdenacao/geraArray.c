#include <stdlib.h>
#include <stdio.h>
#include "geraArray.h"

void geraArray(int tamArray, tipoArray **arrayOrdCres, tipoArray **arrayOrdDecres){
    int i=0, j=0;
    tipoArray *a = NULL, *b = NULL;

    a = (tipoArray*) malloc(tamArray*sizeof(tipoArray));
    if(a == NULL) return;
    b = (tipoArray*) malloc(tamArray*sizeof(tipoArray));
    if(b == NULL) return;

    for(i=0; i<tamArray; i++)///Popula Array crescente
        a[i] = i;
    for(i=tamArray-1; i>=0; i--){///Popula Array decrescente
        b[j] = i;
        j++;
    }

    *arrayOrdCres = a;
    *arrayOrdDecres = b;

    return;
}

void geraArrayDesord(int tamArray, tipoArray **arrayDesord){

    int i=0, j=0, numRand;
    tipoArray *c = NULL;

    c = (tipoArray*) malloc(tamArray*sizeof(tipoArray));
    if(c == NULL) return;

    do {///Popula Array desordenando e garante que não haverá nenhum número repetido
       numRand = rand()%tamArray;
       if(i==0){
        c[i++]=numRand;
        continue;
       }
       for(j=0; j<i; j++){
        if(c[j]!=numRand)
            continue;
        numRand = rand()%tamArray;
        j = -1;
       }
        c[i++]=numRand;
        gotoxy(1,7);
        printf("Gerando numeros aleatorios....%0.2f%%\n",((float)i/(float)tamArray)*100);
       }while(i<tamArray);

    *arrayDesord = c;
    return;
}

void imprimirArray(int tamArray, const tipoArray *arrayPrint){

    int i = 0;

    if(tamArray > 24){///Se o tamanho do Array for maior que 24 imprime somente os dez primeiros e o dez últimos elementos
        putchar('\n');
        for(i=0; i<5; i++)
            printf("%d ",arrayPrint[i]);
        printf(".. ");
        for(i=tamArray-5;i<tamArray;i++)
            printf("%d ",arrayPrint[i]);
        putchar('\n');
        return;
    }
    putchar('\n');///Caso contrário imprime todos os elementos
    for(i=0; i<tamArray; i++)
        printf("%d ",arrayPrint[i]);
    putchar('\n');
    return;
}

void copiaArray(int tamArray, const tipoArray *arrayOriginal, tipoArray* *arrayCopia){

    int i;
    tipoArray *cpArray = NULL;

    cpArray = (tipoArray*) malloc(tamArray*sizeof(tipoArray));
    if(cpArray == NULL) return;

    for(i=0;i<tamArray;i++)
        cpArray[i] = arrayOriginal[i];

    *arrayCopia = cpArray;

    return;
}
