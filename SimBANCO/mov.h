/*  Instituto Federal de Educa��o, Ci�ncia e Tecnologia
                Campus - Jo�o Pessoa
    Curso Superior Tecnol�gico em Redes de Computadores

                    Estruturas de Dados

    Professores Alex Sandro e Daniel Cardoso

    Aluno Illo Atayde Macedo Duarte - Mat 20161380041

                    PROJETO I - SimBANCO
Arquivo destinado aos prot�tipos das fun��es que manipulam a estrutura movimento*/



typedef enum {false,true} boolean;

typedef struct stMov{
    float valMovimento;
    char descMovimento[10];
    struct stMov *proxMovimento;
}tStMov;

typedef tStMov* movimento;

boolean insMovimento(movimento *lstMov,const char* desMov,float valMov);//Insere um movimento na lista

boolean remMovimentos(movimento *lstMov);//Remove todos os movimentos de uma lista

