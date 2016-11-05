/*  Instituto Federal de Educa��o, Ci�ncia e Tecnologia
                Campus - Jo�o Pessoa
    Curso Superior Tecnol�gico em Redes de Computadores

                    Estruturas de Dados

    Professores Alex Sandro e Daniel Cardoso

    Aluno Illo Atayde Macedo Duarte - Mat 20161380041

                    PROJETO I - SimBANCO
Arquivo destinado aos prot�tipos das fun��es que manipulam a estrutura cliente*/


#include"mov.h"

typedef struct stCliente{
    int idCliente;
    char nomeCliente[20];
    float saldo;    //talvez tenha que ser removida
    tStMov *movCliente;
    struct stCliente *proxCliente;
}tStCliente;

typedef tStCliente* cliente;

void iniCliente(cliente *lstCli);
//Fun��o respons�vel pela inicializa��o da lista cliente
boolean insCliente(cliente *lstCli,const char* nomeCli);
//Fun��o respons�vel por inserir um cliente na lista
boolean altNomeCliente(cliente *lstCli, int idCli, const char* nomeCli);
//Fun��o respons�vel pela altera��o do nome de um cliente da lista
tStCliente* buscaCliente(cliente *lstCli, int idCli, int *posCli);
//Fun��o respons�vel pela busca de um cliente da lista
boolean insMovCli(cliente *lstCli,int idCli,const char* desMov, float valMov);
//Fun��o respons�vel pela inser��o de um movimento para um cliente da lista
void extratoCliente(cliente *lstCli,int idCli);
//Fun��o respons�vel pela exibi��o de todas as movimenta��es de um cliente da lista
void exibeCliente(cliente lstCli, int idCli);
//Fun��o respons�vel por exibir um cliente da lista
void exibeTdClientes(cliente lstCli);
//Fun��o respons�vel por exibir todos os clientes da lista
boolean remCliente(cliente *lstCli, int idCli);
//Fun��o respons�vel por remover um cliente da lista
boolean remTdClientes(cliente *lstCli);
//Fun��o respons�vel por remover todos os clientes da lista
