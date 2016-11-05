/** Instituto Federal de Educação, Ciência e Tecnologia
                Campus - João Pessoa
    Curso Superior Tecnológico em Redes de Computadores

                    Estruturas de Dados

            Professores Crishane e Daniel Cardoso

    Aluno Illo Atayde Macedo Duarte - Mat 20161380041

PROJETO II - Conversor de Expressões na forma infixa para posfixa
            Arquivo destinado à função principal                    */


#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>
#include<conio.h>
#include<conio2.h>
#include"conversor.h"
#include"auxBibli.h"

int main()
{
    char expressao[30], *operandos = NULL, *chPosfixa = NULL, chTemp, chS_N = '\0';
    float valores[30], flResultado;
    int pos = 0, exibeConversao = -1;
    do{
        system("cls");
        textcolor(YELLOW);
        printf("---------------CONVERTE INFIXA -> POSFIXA---------------\n\n\n");
        textcolor(WHITE);
        printf("Digite uma expressao!\n\n");
        scanf("%s",expressao);
        fflush(stdin);
        strupr(expressao);
        while(exibeConversao == -1){
            printf("Deseja ver passo a passo(s/n)?");
            scanf("%c",&chS_N);
            putchar('\n');
            putchar('\n');
            //chS_N = toupper(chS_N);
            switch(chS_N){
            case 's':
            case 'S':
                exibeConversao = MOSTRAR;
                break;
            case 'n':
            case 'N':
                exibeConversao = NAO_MOSTRAR;
                break;
            }fflush(stdin);
        }
        if(!(expressaoInfixaValida(expressao)))
            printf("Expressao invalida!\n\n");
            else{
                chPosfixa = converteInfixaParaPosfixa(expressao,exibeConversao);
                exibeConversao = -1;
                operandos = obterOperandos(expressao);
                printf("Expressao convertida com sucesso! %s\n\n",chPosfixa);

                while(operandos[pos] != '\0'){///Obtendo valores para os operandos
                    chTemp = operandos[pos];
                    printf("Digite um valor para %c:",chTemp);
                    scanf("%f",&valores[pos++]);
                }pos = 0;
                flResultado = executaExpressao(chPosfixa,operandos,valores);
                printf("Resultado da expressao %s eh: %f\n\n",expressao,flResultado);
            }
        printf("Digite ESC para sair ou qualquer tecla para continuar...\n\n\n\n");
        fflush(stdin);
    }while(getch() != 27);
    return 0;
}
