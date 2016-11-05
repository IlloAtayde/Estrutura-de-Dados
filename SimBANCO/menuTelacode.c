/*  Instituto Federal de Educação, Ciência e Tecnologia
                Campus - João Pessoa
    Curso Superior Tecnológico em Redes de Computadores

                    Estruturas de Dados

    Professores Alex Sandro e Daniel Cardoso

    Aluno Illo Atayde Macedo Duarte - Mat 20161380041

                    PROJETO I - SimBANCO
            Arquivo destinado às funções de tela e menu  */


#include <stdio.h>
#include <stdlib.h>
#include<conio2.h>
#include"cliente.h"

void escTela(void){//Escreve o menu na tela

    fflush(stdin);
    textcolor(YELLOW);
    printf("SimBANCO");
    textcolor(WHITE);
    putchar('\n');
    putchar('\n');
    printf("(1)Incluir novo cliente:\n");
    putchar('\n');
    printf("(2)Alterar nome do cliente:\n");
    putchar('\n');
    printf("(3)Excluir um cliente:\n");
    putchar('\n');
    printf("(4)Exibir dados de um cliente:\n");
    putchar('\n');
    printf("(5)Exibir todos os clientes:\n");
    putchar('\n');
    printf("(6)Incluir um novo movimento ao cliente:\n");
    putchar('\n');
    printf("(7)Exibir o extrato de um cliente:\n");
    putchar('\n');
    printf("(8)Remover todos os registros:\n");
    putchar('\n');
    printf("(9)Sair!\n");
    putchar('\n');
    printf("(10)Cadastro automatico!\n");
    putchar('\n');
    putchar('\n');
    printf("DIGITE UMA OPCAO VALIDA: ");
    return;
}

char nome[20], descricao[10];
int numConta, inutil;
float dinheiro;
cliente lstCliente;

void opMenu_01(void){//Incluir novo cliente

    system("cls");
    printf("Digite o nome do cliente: ");
    scanf("%s",nome);
    putchar('\n');
    if(insCliente(&lstCliente,nome))
        printf("Cliente cadastrado com sucesso!\n");
    putchar('\n');
    system("pause");
    system("cls");
    return;
}

void opMenu_02(void){//Alterar nome do cliente

    system("cls");
    printf("Digite o numero da conta do cliente: ");
    scanf("%d",&numConta);
    putchar('\n');
    if(!(buscaCliente(&lstCliente,numConta,&inutil))){
        printf("Cliente nao cadastrado!\n");
        putchar('\n');
        system("pause");
        system("cls");
        return;
    }
    putchar('\n');
    exibeCliente(lstCliente,numConta);
    putchar('\n');
    printf("Digite o novo nome para o cliente: ");
    scanf("%s",nome);
    putchar('\n');
    if(altNomeCliente(&lstCliente,numConta,nome))
        printf("Nome alterado com sucesso!\n");
    putchar('\n');
    exibeCliente(lstCliente,numConta);
    putchar('\n');
    system("pause");
    system("cls");
    return;
}

void opMenu_03(void){//Excluir um cliente

    system("cls");
    printf("Digite o numero da conta do cliente: ");
    scanf("%d",&numConta);
    putchar('\n');
    exibeCliente(lstCliente,numConta);
    putchar('\n');
    if(!(remCliente(&lstCliente,numConta))){
        putchar('\n');
        printf("Falha na exclusao!\n");
        putchar('\n');
        system("pause");
        system("cls");
        return;
    }
    putchar('\n');
    printf("Cliente removido com sucesso!\n");
    putchar('\n');
    exibeTdClientes(lstCliente);
    putchar('\n');
    system("pause");
    system("cls");
    return;
}

void opMenu_04(void){//Exibir dados de um cliente

    system("cls");
    printf("Digite o numero da conta do cliente: ");
    scanf("%d",&numConta);
    putchar('\n');
    exibeCliente(lstCliente,numConta);
    putchar('\n');
    system("pause");
    system("cls");
    return;
}

void opMenu_05(void){//Exibir todos os clientes

    system("cls");
    exibeTdClientes(lstCliente);
    putchar('\n');
    system("pause");
    system("cls");
    return;
}

void opMenu_06(void){//Incluir um novo movimento ao cliente

    system("cls");
    printf("Digite o numero da conta do cliente: ");
    scanf("%d",&numConta);
    putchar('\n');
    if(!(buscaCliente(&lstCliente,numConta,&inutil))){
        printf("Cliente nao cadastrado!\n");
        putchar('\n');
        system("pause");
        system("cls");
        return;
    }
    putchar('\n');
    exibeCliente(lstCliente,numConta);
    putchar('\n');
    printf("Digite a descricao da movimentacao: ");
    scanf("%s",descricao);
    putchar('\n');
    printf("Digite o valor da movimentacao: ");
    scanf("%f",&dinheiro);
    putchar('\n');
    if(!(insMovCli(&lstCliente,numConta,descricao,dinheiro))){
        printf("Cliente nao cadastrado!\n");
        putchar('\n');
        system("pause");
        system("cls");
        return;
    }
    printf("Movimentacao realizada com sucesso!\n");
    putchar('\n');
    exibeCliente(lstCliente,numConta);
    putchar('\n');
    system("pause");
    system("cls");
    return;
}

void opMenu_07(void){//Exibir o extrato de um cliente

    system("cls");
    printf("Digite o numero da conta do cliente: ");
    scanf("%d",&numConta);
    system("cls");
    extratoCliente(&lstCliente,numConta);
    putchar('\n');
    system("pause");
    system("cls");
    return;
}

void opMenu_08(void){//Remover todos os registros

    system("cls");
    printf("REMOVENDO TODOS OS CLIENTES...\n");
    putchar('\n');
    if(remTdClientes(&lstCliente))
        printf("Clientes removidos com sucesso!\n");
    else
        printf("Nenhum cliente cadastrado!\n");
    putchar('\n');
    system("pause");
    system("cls");
    return;
}

void opMenu_09(void){//Sair!

    system("cls");
    printf("SAINDO DO SimBanco!...\n");
    putchar('\n');
    if(remTdClientes(&lstCliente))
    printf("Clientes removidos com sucesso!\n");
    return;
}

void opMenu_10(void){//Inserir clientes e movimentos automaticamente!

    system("cls");
    //Dez clientes automáticos
    insCliente(&lstCliente,"Loba");
    insCliente(&lstCliente,"Latifa");
    insCliente(&lstCliente,"Garnizeh");
    insCliente(&lstCliente,"Ranzinza");
    insCliente(&lstCliente,"Maria");
    insCliente(&lstCliente,"Joao");
    insCliente(&lstCliente,"Severino");
    insCliente(&lstCliente,"Virgilio");
    insCliente(&lstCliente,"Rebeca");
    insCliente(&lstCliente,"Jaqueline");
    //Inserções de cinco movimentações em cliente Loba
    insMovCli(&lstCliente,1,"Deposito",20.00);
    insMovCli(&lstCliente,1,"Transf.",-45.00);
    insMovCli(&lstCliente,1,"Pagamento",-73.00);
    insMovCli(&lstCliente,1,"Saque",-62.00);
    insMovCli(&lstCliente,1,"Deposito",350.00);
    //Inserções de cinco movimentações em cliente Latifa
    insMovCli(&lstCliente,2,"Deposito",20.00);
    insMovCli(&lstCliente,2,"Transf.",-45.00);
    insMovCli(&lstCliente,2,"Pagamento",-73.00);
    insMovCli(&lstCliente,2,"Saque",-62.00);
    insMovCli(&lstCliente,2,"Deposito",350.00);
    //Inserções de cinco movimentações em cliente Garnizeh
    insMovCli(&lstCliente,3,"Pagamento",-73.00);
    insMovCli(&lstCliente,3,"Saque",-62.00);
    insMovCli(&lstCliente,3,"Deposito",350.00);
    //Inserções de cinco movimentações em cliente Ranzinza
    insMovCli(&lstCliente,4,"Transf.",-45.00);
    insMovCli(&lstCliente,4,"Pagamento",-73.00);
    insMovCli(&lstCliente,4,"Saque",-62.00);
    insMovCli(&lstCliente,4,"Deposito",350.00);
    insMovCli(&lstCliente,4,"Pagamento",-73.00);
    insMovCli(&lstCliente,4,"Saque",-62.00);
    //Inserções de cinco movimentações em cliente Maria
    insMovCli(&lstCliente,5,"Transf.",-45.00);
    insMovCli(&lstCliente,5,"Pagamento",-73.00);
    insMovCli(&lstCliente,5,"Saque",-62.00);
    insMovCli(&lstCliente,5,"Deposito",350.00);
    insMovCli(&lstCliente,5,"Transf.",-1573.00);
    insMovCli(&lstCliente,5,"Saque",-62.00);
    if(insMovCli(&lstCliente,5,"Deposito",350.00))
        printf("Insercao automatica finalizada com sucesso!\n");
    putchar('\n');
    system("pause");
    system("cls");
    return;
}
