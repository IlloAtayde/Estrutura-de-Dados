/**     Instituto Federal de Educa��o, Ci�ncia e Tecnologia
                       Campus - Jo�o Pessoa
        Curso Superior Tecnol�gico em Redes de Computadores

                        Estruturas de Dados

                Professores Crishane e Daniel Cardoso

           Aluno Illo Atayde Macedo Duarte - Mat 20161380041

   PROJETO II - Conversor de Express�es na forma infixa para posfixa

Arquivo destinado aos prot�tipos das fun��es de manipula��o das pilhas
e defini��es.                                                           */

typedef struct ch{
    char chPPT;
    int chTipo;//operando chTipo = 0, operador chTipo =1
    int chPrior;
    struct ch *proxNo;
}tNo;

typedef tNo* ptrTNo;

typedef struct fl{
    float flPPT;
    struct fl *proxNoFl;
}tNoFl;

typedef tNoFl* ptrTNoFl;

int empilha(ptrTNo *pilha,char chPush,int chT,int chP);///Push

int desempilha(ptrTNo *pilha, char *chPop);///Pop

int vazia(ptrTNo pilha);

int cheia(ptrTNo pilha);

char topo(ptrTNo pilha);

void exibe(ptrTNo pilha);

int empilhaFl(ptrTNoFl *pilha,float flPush);///Push float

int desempilhaFl(ptrTNoFl *pilha, float *flPop);///Pop float
