/** Instituto Federal de Educação, Ciência e Tecnologia
                Campus - João Pessoa
    Curso Superior Tecnológico em Redes de Computadores

                    Estruturas de Dados

            Professores Crishane e Daniel Cardoso

    Aluno Illo Atayde Macedo Duarte - Mat 20161380041

PROJETO II - Conversor de Expressões na forma infixa para posfixa
            Arquivo destinado às função auxiliares                    */

#include<string.h>
#include<stdio.h>
#include"auxBibli.h"

void ordCresArray(variavel *arrayDesord){///Função organiza em ordem alfabética, no mesmo array do recebimento
    variavel varAux;
    int i = 0, j = 0, tam;
    tam = strlen(arrayDesord);

    for (i=0; i < tam-1; i++){
        varAux = arrayDesord[j];
        for (j=0; j < tam-1; j++){
            if(varAux > arrayDesord[j+1]){
                arrayDesord[j] = arrayDesord[j+1];
                arrayDesord[j+1] = varAux;
            }else varAux = arrayDesord[j+1];
        }j = 0;
    }
    return ;
}

float obterValor(char chTeste,const char *operandos, float *valores){///Função obtem o valor numérico de um operando, passados em uma lista de valores
    int pos = 0;
    float flRetorno;

    if(ehOpeNum(chTeste)){
        flRetorno = (float)(chTeste - 48);
        ///printf("%f\n",flRetorno);
    }else while(operandos[pos] != '\0'){
            if(chTeste == operandos[pos])
            flRetorno = valores[pos];
            pos++;
          }
    return flRetorno;
}

int ehOperando(char chTeste){///Função verifica se o caracter passado é operando, ou seja, letras
    char chOperandos[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    if(strchr(chOperandos,chTeste))
        return 1;
    return 0;
}

int ehOpeNum(char chTeste){///Função verifica se o caracter passado é operando numérico, ou seja, letras
    char chOpeNum[] = "0123456789";

    if(strchr(chOpeNum,chTeste))
        return 1;
    return 0;
}

int ehOperador(char chTeste){///Fução verifica se o caracter passsado é operador matemático
    char chOperadores[] = "+-*/^";

    if(strchr(chOperadores,chTeste))
        return 1;
    return 0;
}
