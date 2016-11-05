/*  Instituto Federal de Educação, Ciência e Tecnologia
                Campus - João Pessoa
    Curso Superior Tecnológico em Redes de Computadores

                    Estruturas de Dados

    Professores Alex Sandro e Daniel Cardoso

    Aluno Illo Atayde Macedo Duarte - Mat 20161380041

                    PROJETO I - SimBANCO
Arquivo destinado aos protótipos das funções que manipulam a estrutura cliente*/


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
//Função responsável pela inicialização da lista cliente
boolean insCliente(cliente *lstCli,const char* nomeCli);
//Função responsável por inserir um cliente na lista
boolean altNomeCliente(cliente *lstCli, int idCli, const char* nomeCli);
//Função responsável pela alteração do nome de um cliente da lista
tStCliente* buscaCliente(cliente *lstCli, int idCli, int *posCli);
//Função responsável pela busca de um cliente da lista
boolean insMovCli(cliente *lstCli,int idCli,const char* desMov, float valMov);
//Função responsável pela inserção de um movimento para um cliente da lista
void extratoCliente(cliente *lstCli,int idCli);
//Função responsável pela exibição de todas as movimentações de um cliente da lista
void exibeCliente(cliente lstCli, int idCli);
//Função responsável por exibir um cliente da lista
void exibeTdClientes(cliente lstCli);
//Função responsável por exibir todos os clientes da lista
boolean remCliente(cliente *lstCli, int idCli);
//Função responsável por remover um cliente da lista
boolean remTdClientes(cliente *lstCli);
//Função responsável por remover todos os clientes da lista
