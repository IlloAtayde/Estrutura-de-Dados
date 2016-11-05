/*  Instituto Federal de Educação, Ciência e Tecnologia
                Campus - João Pessoa
    Curso Superior Tecnológico em Redes de Computadores

                    Estruturas de Dados

    Professores Alex Sandro e Daniel Cardoso

    Aluno Illo Atayde Macedo Duarte - Mat 20161380041

                    PROJETO I - SimBANCO
            Arquivo destinado à função principal        */


#include <stdio.h>
#include <stdlib.h>
#include<conio2.h>
#include"cliente.h"
#include"menuTela.h"

int main(){

int opMenu;

    do{
        escTela();//Escreve o menu na tela
        scanf("%d",&opMenu);

        switch(opMenu){
        case 1:
            opMenu_01();//Incluir novo cliente
            break;
        case 2:
            opMenu_02();//Alterar nome do cliente
            break;
        case 3:
            opMenu_03();//Excluir um cliente
            break;
        case 4:
            opMenu_04();//Exibir dados de um cliente
            break;
        case 5:
            opMenu_05();//Exibir todos os clientes
            break;
        case 6:
            opMenu_06();//Incluir um novo movimento ao cliente
            break;
        case 7:
            opMenu_07();//Exibir o extrato de um cliente
            break;
        case 8:
            opMenu_08();//Remover todos os registros
            break;
        case 9:
            opMenu_09();//Sair!
            break;
        case 10:
            opMenu_10();//Inserir clientes e movimentos automaticamente!
            break;
        default:
            system("cls");
            printf("OPCAO INVALIDA!\n");
            putchar('\n');
            system("pause");
            system("cls");
        }
    }while(opMenu!= 9);
    return false;
}
