/**     Instituto Federal de Educa��o, Ci�ncia e Tecnologia
                       Campus - Jo�o Pessoa
        Curso Superior Tecnol�gico em Redes de Computadores

                        Estruturas de Dados

                Professores Crishane e Daniel Cardoso

           Aluno Illo Atayde Macedo Duarte - Mat 20161380041

   PROJETO II - Conversor de Express�es na forma infixa para posfixa

 Arquivo destinado aos prot�tipos das fun��es auxiliares e defini��es    */

typedef char variavel;

///Fun��o que organiza, em ordem crescente, os elementos de um array passado por refer�ncia
void ordCresArray(variavel *arreyDesord);

///Fun��o localiza o valor do operando dentro de um array de valores
float obterValor(char chTeste,const char *operandos, float *valores);

///Fun��o para verifica se � operando
int ehOperando(char chTeste);

///Fun��o para verifica se � operando num�rico
int ehOpeNum(char chTeste);

///Fun��o para verifica se � operador
int ehOperador(char chTeste);
