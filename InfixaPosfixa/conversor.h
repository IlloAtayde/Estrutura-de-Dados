/**     Instituto Federal de Educação, Ciência e Tecnologia
                       Campus - João Pessoa
        Curso Superior Tecnológico em Redes de Computadores

                        Estruturas de Dados

                Professores Crishane e Daniel Cardoso

           Aluno Illo Atayde Macedo Duarte - Mat 20161380041

   PROJETO II - Conversor de Expressões na forma infixa para posfixa

 Arquivo destinado aos protótipos das funções principais e definições    */


#define operando 0
#define operador 1
#define NAO_MOSTRAR 0
#define MOSTRAR 1

int expressaoInfixaValida(const char *expressao);

char* obterOperandos(const char *expressao);

char* converteInfixaParaPosfixa(const char *expressao, int mostraExecucao);

float executaExpressao(const char *expressao, const char *operandos, float *valores);
