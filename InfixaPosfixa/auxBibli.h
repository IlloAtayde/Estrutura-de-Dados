/**     Instituto Federal de Educação, Ciência e Tecnologia
                       Campus - João Pessoa
        Curso Superior Tecnológico em Redes de Computadores

                        Estruturas de Dados

                Professores Crishane e Daniel Cardoso

           Aluno Illo Atayde Macedo Duarte - Mat 20161380041

   PROJETO II - Conversor de Expressões na forma infixa para posfixa

 Arquivo destinado aos protótipos das funções auxiliares e definições    */

typedef char variavel;

///Função que organiza, em ordem crescente, os elementos de um array passado por referência
void ordCresArray(variavel *arreyDesord);

///Função localiza o valor do operando dentro de um array de valores
float obterValor(char chTeste,const char *operandos, float *valores);

///Função para verifica se é operando
int ehOperando(char chTeste);

///Função para verifica se é operando numérico
int ehOpeNum(char chTeste);

///Função para verifica se é operador
int ehOperador(char chTeste);
