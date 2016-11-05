/*  Instituto Federal de Educação, Ciência e Tecnologia
                Campus - João Pessoa
    Curso Superior Tecnológico em Redes de Computadores

                    Estruturas de Dados

    Professores Alex Sandro e Daniel Cardoso

    Aluno Illo Atayde Macedo Duarte - Mat 20161380041

                    PROJETO I - SimBANCO
  Arquivo destinado às funções que manipulam os clientes  */


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio2.h>
#include"cliente.h"

void iniCliente(cliente *lstcli){//Inicializa cliente
    *lstcli = NULL;
}

boolean insCliente(cliente *lstCli,const char* nomeCli){//Insere um cliente na lista
    cliente aux;
    cliente novo;

    aux = *lstCli;

    if ((novo = (tStCliente*) malloc(sizeof(tStCliente))) == NULL)
        return false;

    novo->saldo = 0.00; //inicializa saldo
    novo->movCliente = NULL;//inicializa movimentações
    strcpy(novo->nomeCliente,nomeCli);//faz a inserção do nome

    if (aux == NULL){//valido somente para o primeiro cliente
        novo->idCliente = 1;//id para o primeiro cliente
        novo->proxCliente = NULL;//seta o proximo cliente para NULL
        *lstCli = novo;//aponta a lista pra novo
        return true;
    }

    novo->idCliente = (aux->idCliente)+1;// auto incremento para os proximos clientes da lista
    novo->proxCliente = aux;//comportamento de pilha - novo elemento sempre se conectará ao ultimo que entrou na lista
    *lstCli = novo;//aponta a lista pra novo
    return true;
}

boolean insMovCli(cliente *lstCli,int idCli,const char* desMov, float valMov){//Insere um movimento em dado cliente

    cliente auxCli;
    int posCli;

    auxCli = buscaCliente(lstCli,idCli,&posCli);//faz uma busca na lista cliente para retornar o ponteiro que aponta pra cliente especificado

    if(auxCli == NULL)
        return false;
    auxCli->saldo += valMov;//atualiza o valor do saldo
    return insMovimento(&auxCli->movCliente,desMov,valMov);//faz a inserção do movimento
}

void extratoCliente(cliente *lstCli,int idCli){//Exibe o extrato de um dado cliente

    cliente auxCli;
    movimento auxMov;
    int posCli;

    if(!(auxCli = buscaCliente(lstCli,idCli,&posCli))){
        printf("Cliente nao cadastrado!\n");
        return;
    }

    auxMov = auxCli->movCliente;
    if(auxMov == NULL){
        printf("Nenhum movimento registrado!\n");
        return;
    }
    printf("EXTRATO CLIENTE\n");
    putchar('\n');
    printf("%s conta: %d\n",auxCli->nomeCliente,auxCli->idCliente);
    while(auxMov != NULL){
        printf("%-10s",auxMov->descMovimento);
        auxMov->valMovimento >= 0.00 ? textcolor(LIGHTBLUE):textcolor(LIGHTRED);
        printf("%10.2f\n",auxMov->valMovimento);
        textcolor(WHITE);
        auxMov = auxMov->proxMovimento;
    }
    putchar('\n');
    printf("%-10s","Total");
    auxCli->saldo >= 0 ? textcolor(LIGHTBLUE):textcolor(LIGHTRED);
    printf("%10.2f\n",auxCli->saldo);
    textcolor(WHITE);
    return;
}

boolean altNomeCliente(cliente *lstCli, int idCli, const char* nomeCli){//Atera o nome de um dado cliente
    cliente auxCli;
    int posicao;

    if(!(auxCli = buscaCliente(lstCli,idCli,&posicao))) //*lstCli; - faz a busca do cliente verificando se existe e já atribui o endereço do mesmo
        return false;
/*

    while((aux->proxCliente != NULL) && (aux->idCliente != idCli))
        aux = aux->proxCliente;

    if (aux->idCliente != idCli)
        return false;
*/
    strcpy(auxCli->nomeCliente,nomeCli);// efetua a alteração do nome
    return true;
}

tStCliente* buscaCliente(cliente *lstCli, int idCli, int *posCli){//Efetua a busca de um dado cliente
	cliente auxCli;
    int posicao = 1;

	auxCli = *lstCli;

	if(auxCli == NULL)
		return NULL;

	while(auxCli != NULL){
		if(auxCli->idCliente == idCli){
            *posCli = posicao;
            return auxCli;
        }
		posicao++;
		auxCli = auxCli->proxCliente;
	}

	return NULL;
}

void exibeCliente(cliente lstCli, int idCli){//Exibe informações de um dado cliente
    cliente aux;
    char nomeTemp[20];
    float saldoTemp;

    aux = lstCli;

    if(aux == NULL){
        printf("Nao ha clientes cadastrados.\n");
        return;
    }

    while((aux->proxCliente != NULL) && (aux->idCliente != idCli))
        aux = aux->proxCliente;

    if(aux->idCliente != idCli){
        printf("Cliente nao cadastrado.\n");
        return;
    }

    saldoTemp = aux->saldo;
    strcpy(nomeTemp,aux->nomeCliente);
    printf("%s, conta numero:%d, saldo:R$ ",nomeTemp, idCli);
    aux->saldo >= 0 ? textcolor(LIGHTBLUE):textcolor(LIGHTRED);
    printf("%10.2f\n", saldoTemp);
    textcolor(WHITE);
    putchar('\n');
    return;
}//textcolor(BLUE);

void exibeTdClientes(cliente lstCli){//Exibe todos os clientes da lista
    cliente aux;

    aux = lstCli;

    if(aux == NULL){
        printf("Nenhum cliente cadastrado!\n");
        putchar('\n');
        return;
    }
    printf("CLIENTES CADASTRADOS:\n");
    putchar('\n');
    while(aux != NULL){
        printf("%-10s, conta: %02d, saldo: R$ ",aux->nomeCliente,aux->idCliente);
        aux->saldo >= 0.00 ? textcolor(LIGHTBLUE) : textcolor(LIGHTRED);
        printf("%10.2f\n",aux->saldo);
        textcolor(WHITE);
        aux = aux->proxCliente;
    }
    return;
}

boolean remCliente(cliente *lstCli, int idCli){//Revove um cliente específico da lista
	cliente auxCli, auxCliAnt;
	//movimento auxMov;
    int posCli,contador = 1;

	if(!(auxCli = buscaCliente(lstCli,idCli,&posCli)))
		return false;

	if(auxCli->saldo != 0){
        auxCli->saldo > 0 ? printf("Efetue um saque de R$ %10.2f\n",auxCli->saldo):printf("Efetue um deposito de R$ %10.2f\n",auxCli->saldo * (-1));
        return false;
	}
	//if((auxMov = auxCli->movCliente))
    remMovimentos(&auxCli->movCliente);

    auxCli = *lstCli;

	while((contador <= posCli - 1) && (auxCli != NULL)){
        auxCliAnt = auxCli;
        auxCli = auxCli->proxCliente;
        contador++;
	}
	if(auxCli == NULL)
        return false;
    if(posCli == 1)
        *lstCli = auxCli->proxCliente;
    else
        auxCliAnt->proxCliente = auxCli->proxCliente;
    free(auxCli);
    return true;
}

boolean remTdClientes(cliente *lstCli){//Remove todos os clientes da lista
    cliente auxCli;

    if(!(auxCli = *lstCli))

    //if(auxCli == NULL)
        return false;
    while(auxCli != NULL){
		remMovimentos(&auxCli->movCliente);
		//auxCli->saldo = 0.00;
        *lstCli = auxCli->proxCliente;
        free(auxCli);
        auxCli = *lstCli;
    }
    return true;
}
