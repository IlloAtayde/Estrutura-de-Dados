/**            Instituto Federal de Educa��o, Ci�ncia e Tecnologia
                               Campus - Jo�o Pessoa
               Curso Superior Tecnol�gico em Redes de Computadores

                                Estruturas de Dados

                      Professores Crishane e Daniel Cardoso

                Aluno Illo Atayde Macedo Duarte - Mat 20161380041

        PROJETO II - Conversor de Express�es na forma infixa para posfixa

Arquivo destinado �s fun��es de verifica��o, convers�o, obten��o de operandos e execu��o */


#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include"conversor.h"
#include"pilha.h"
#include"auxBibli.h"

/**typedef struct ch{
    char chPPT;
    int chTipo;//operando chTipo = 0, operador chTipo =1
    int chPrior;
    struct ch *proxCh;
}tCh;

typedef tCh* ptrTCh;*/

int expressaoInfixaValida(const char *expressao){
    char chTeste;
    int pos = 0, contParentesis = 0, chT, chP = -1;
    ptrTNo pilhaTemp = NULL;

    if(strlen(expressao) <= 2)///Verifica se a express�o digitada tem menos de dois caracteres
        return 0;
    //strupr(expressao);
    while(expressao[pos] != '\0'){///Verifica��o caracter a caracter
        chTeste = expressao[pos];

        if((pos==0)&&((chTeste==')')||(ehOperador(chTeste))))///N�o permite que a express�o comece com {')','+','-','*','/','^'}
            return 0;
        if(chTeste == '('){///Incrementa contParentesis quando for encontrado um '('
            contParentesis++;
            pos++;
            continue;
        }else
           if(chTeste == ')'){///Decrementa contParentesis quando for encontrado um ')'
               contParentesis--;
               pos++;
               continue;
           }else
              if(ehOperando(chTeste)||ehOpeNum(chTeste))///Testa se � operando, ou seja, Letras ou n�meros
                chT = operando;
              else
                if(ehOperador(chTeste))///Testa se � operador, ou seja, operadores matem�ticos
                  chT = operador;
                else return 0;///Se n�o pertencer a nenhum dos caracteres citados acima retorna 0, ou seja, express�o inv�lida
        if(!(vazia(pilhaTemp)))
            if(pilhaTemp->chTipo == chT)///Evita que operadores, e ou, operandos sejam digitados juntos
                return 0;
        empilha(&pilhaTemp,chTeste,chT,chP);
        pos++;

    }
    if(contParentesis != 0)///Se, ao final, a quantidade de caracteres do tipo par�ntesis n�o estiver aos pares, express�o inv�lida
        return 0;
    if(pilhaTemp->chTipo == operador)
        return 0;///Isto evita, mesmo se digitada entre par�ntesis, que uma express�o com um operador na �ltima posi��o seja processada
    while(pilhaTemp != NULL){///Garante que, mesmo se digitado entre par�ntesis, o primeiro caracter  n�o seja um operador
        if(pilhaTemp->proxNo == NULL)
            if(pilhaTemp->chTipo == operador){
                desempilha(&pilhaTemp,&chTeste);
                return 0;
            }
        desempilha(&pilhaTemp,&chTeste);
    }
    return 1;
}/// Final fun��o: expressaoInfixaValida

char* obterOperandos(const char *expressao){
    char chTeste, chPopTemp[27], chTemp, *chRetorno = NULL;
    int pos = 0, chT = 0, chP = 0;
    ptrTNo pilhaTemp = NULL;
    chPopTemp[0] = '\0';

    while(expressao[pos] != '\0'){///Empilhando s� operandos
        chTeste = expressao[pos];
        if(!(ehOperando(chTeste))){
            pos++;
            continue;
        }
        empilha(&pilhaTemp,chTeste,chT,chP);
        pos++;
    }pos = 0;

    while(!vazia(pilhaTemp)){///Montando uma string com operandos obtidos, sem duplicatas
        desempilha(&pilhaTemp,&chTemp);
        if(strchr(chPopTemp,chTemp))
            continue;
        chPopTemp[pos] = chTemp;
        chPopTemp[++pos] = '\0';
    }pos = 0;

    if(!(chRetorno = (char*)malloc(strlen(chPopTemp)*sizeof(char)))){
        printf("Falha na alocacao dinamica!\n");
        return NULL;
    }
    ordCresArray(chPopTemp);
    strcpy(chRetorno,chPopTemp);
    return chRetorno;
}/// Final fun��o: obterOperandos

char* converteInfixaParaPosfixa(const char *expressao, int mostraExecucao){
    char chPop, chTemp, *chRetorno = NULL;
    int pos = 0, cont = 0, chP = 0, chT = 0, i = 0, exCont = 1;
    ptrTNo pilhaTemp = NULL;

    while(expressao[pos]!= '\0'){
        chTemp = expressao[pos];

        if(ehOperando(chTemp) || ehOperador(chTemp) || ehOpeNum(chTemp)){///Conta quantos caracteres ser�o necess�rios para armazenar a express�o convertida
            cont++;
            pos++;
            continue;
        }pos++;
    }pos = 0;

    if(!(chRetorno = (char*) malloc((cont+1)*sizeof(char)))){
        printf("Problema na alocacao dinamica\n");
        return NULL;
    }

    while(expressao[pos]!='\0'){///Come�o do while...
        chTemp = expressao[pos];

        if(ehOperando(chTemp) || ehOpeNum(chTemp)){///Se for operando j� armazena na string chRetorno
            chRetorno[i++] = chTemp;
            chRetorno[i] = '\0';
            pos++;
            if(mostraExecucao == MOSTRAR){
                printf("[%2d]:",exCont++);
                printf("Encontrado: %-12c",chTemp);
                printf("; Saida -> %s\n",chRetorno);
                putchar('\n');
            }
            continue;
        }

        if(chTemp == '('){///Se for abre par�nteses, seta prioridade e empilha
            chP = 1;
            pos++;
            empilha(&pilhaTemp,chTemp,chT,chP);
            if(mostraExecucao == MOSTRAR){
                printf("[%2d]:",exCont++);
                printf("Encontrado: %c -> empilha; ",chTemp);
                printf("Pilha (topo): ");
                putchar('[');
                printf("%c",pilhaTemp->chPPT);
                putchar(']');
                putchar('\n');
                putchar('\n');
            }
            continue;
           }

        if(chTemp == ')'){///Se for fecha par�nsteses, desempilha at� encontrar o abre par�nteses correspondente. Armazenando em chRetorno
            if(mostraExecucao == MOSTRAR){
                printf("[%2d]:",exCont++);
                printf("Encontrado: %-4c\n\n",chTemp);
            }
            desempilha(&pilhaTemp,&chPop);
            while(chPop != '('){
                //desempilha(&pilhaTemp,&chPop);
                chRetorno[i++] = chPop;
                chRetorno[i] = '\0';
                if(mostraExecucao == MOSTRAR){
                printf("[%2d]:",exCont++);
                printf("desempilha: %-3c -> Saida",chPop);
                printf("; Saida -> %s\n",chRetorno);
                putchar('\n');
                }
                desempilha(&pilhaTemp,&chPop);
            }
            if(mostraExecucao == MOSTRAR){
                printf("[%2d]:",exCont++);
                printf("desempilha: %-3c\n\n",chPop);
            }//desempilha(&pilhaTemp,&chPop);
            pos++;
            continue;
        }

        switch(chTemp){
        case '+':
        case '-':
            chP = 2;
            if((!vazia(pilhaTemp)) && (pilhaTemp->chPrior >= chP)){///Caso seja '+' ou '-'
                desempilha(&pilhaTemp,&chPop);
                chRetorno[i++] = chPop;
                chRetorno[i] = '\0';
                 if(mostraExecucao == MOSTRAR){
                    printf("[%2d]:",exCont++);
                    printf("Encontrado: %-4c\n\n",chTemp);
                    printf("[%2d]:",exCont++);
                    printf("desempilha: %-3c -> Saida",chPop);
                    printf("; Saida -> %s\n\n",chRetorno);
                    //putchar('\n');
                }
            }
            empilha(&pilhaTemp,chTemp,chT,chP);
                if(mostraExecucao == MOSTRAR){
                    printf("[%2d]:",exCont++);
                    printf("Empilha %c encontrado -> ",chTemp);
                    printf("; Pilha (topo): ");
                    putchar('[');
                    printf("%c",pilhaTemp->chPPT);
                    putchar(']');
                    putchar('\n');
                    putchar('\n');
            }

            break;
        case '*':
        case '/':
            chP = 3;
            if((!vazia(pilhaTemp)) && (pilhaTemp->chPrior >= chP)){///Caso seja '*' ou '/'
                desempilha(&pilhaTemp,&chPop);
                chRetorno[i++] = chPop;
                chRetorno[i] = '\0';
                if(mostraExecucao == MOSTRAR){
                    printf("[%2d]:",exCont++);
                    printf("Encontrado: %-4c\n\n",chTemp);
                    printf("[%2d]:",exCont++);
                    printf("desempilha: %-3c -> Saida",chPop);
                    printf("; Saida -> %s\n\n",chRetorno);
                    //putchar('\n');
                }
            }
            empilha(&pilhaTemp,chTemp,chT,chP);
                if(mostraExecucao == MOSTRAR){
                    printf("[%2d]:",exCont++);
                    printf("Empilha %c encontrado -> ",chTemp);
                    printf("; Pilha (topo): ");
                    putchar('[');
                    printf("%c",pilhaTemp->chPPT);
                    putchar(']');
                    putchar('\n');
                    putchar('\n');
            }

            break;
        case '^':
            chP = 4;
            if((!vazia(pilhaTemp)) && (pilhaTemp->chPrior >= chP)){///Caso seja '^'
                desempilha(&pilhaTemp,&chPop);
                chRetorno[i++] = chPop;
                chRetorno[i] = '\0';
                if(mostraExecucao == MOSTRAR){
                    printf("[%2d]:",exCont++);
                    printf("Encontrado: %-4c\n\n",chTemp);
                    printf("[%2d]:",exCont++);
                    printf("desempilha: %-3c -> Saida",chPop);
                    printf("; Saida -> %s\n\n",chRetorno);
                    //putchar('\n');
                }
            }
            empilha(&pilhaTemp,chTemp,chT,chP);
                if(mostraExecucao == MOSTRAR){
                    printf("[%2d]:",exCont++);
                    printf("Empilha %c encontrado -> ",chTemp);
                    printf("; Pilha (topo): ");
                    putchar('[');
                    printf("%c",pilhaTemp->chPPT);
                    putchar(']');
                    putchar('\n');
                    putchar('\n');
            }

            break;
        }pos++;///Fim switch
    }///...fim do while
    if(mostraExecucao == MOSTRAR){
        putchar('\n');
        printf("Esvaziando a pilha...\n\n");
    }
    while(!vazia(pilhaTemp)){///Ao final, desempilha todos os operadores que restarem na pilha
        desempilha(&pilhaTemp,&chPop);
        chRetorno[i++] = chPop;
        chRetorno[i] = '\0';
        if(mostraExecucao == MOSTRAR){
        printf("desempilha %c -> Saida",chPop);
        printf("; Saida -> %s\n",chRetorno);
        putchar('\n');
        }
    }
    return chRetorno;
}/// Final fun��o: converteInfixaParaPosfixa

float executaExpressao(const char *expressao, const char *operandos, float *valores){
    char chTemp;
    float val1, val2, sub, flRetorno, flTemp;
    ptrTNoFl pilhaTempFl = NULL;
    int pos = 0;

    while(expressao[pos] != '\0'){///While in�cio...
        chTemp = expressao[pos];

        switch(chTemp){///Caso operador seja...
        case '+':
            desempilhaFl(&pilhaTempFl,&val2);
            desempilhaFl(&pilhaTempFl,&val1);
            sub = (val1 + val2);
            empilhaFl(&pilhaTempFl,sub);
            break;
        case '-':
            desempilhaFl(&pilhaTempFl,&val2);
            desempilhaFl(&pilhaTempFl,&val1);
            sub = (val1 - val2);
            empilhaFl(&pilhaTempFl,sub);
            break;
        case '*':
            desempilhaFl(&pilhaTempFl,&val2);
            desempilhaFl(&pilhaTempFl,&val1);
            sub = (val1 * val2);
            empilhaFl(&pilhaTempFl,sub);
            break;
        case '/':
            desempilhaFl(&pilhaTempFl,&val2);
            if(val2 == 0){///N�o permite divis�o por ZERO
                printf("ERRO! DIVISAO POR ZERO!\n");
                return 0;
            }
            desempilhaFl(&pilhaTempFl,&val1);
            sub = (val1 / val2);
            empilhaFl(&pilhaTempFl,sub);
            break;
        case '^':
            desempilhaFl(&pilhaTempFl,&val2);
            desempilhaFl(&pilhaTempFl,&val1);
            sub = pow(val1,val2);
            empilhaFl(&pilhaTempFl,sub);
            break;
        default:
            flTemp = obterValor(chTemp,operandos,valores);///Caso padr�o: obter valor do operando
            empilhaFl(&pilhaTempFl,flTemp);
        }pos++;///Fim do switch
    }///...While fim
    desempilhaFl(&pilhaTempFl,&flRetorno);
    return flRetorno;

}/// Final fun��o: executaExpressao
