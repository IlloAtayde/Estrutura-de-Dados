/*  Instituto Federal de Educação, Ciência e Tecnologia
                Campus - João Pessoa
    Curso Superior Tecnológico em Redes de Computadores

                    Estruturas de Dados

    Professores Alex Sandro e Daniel Cardoso

    Aluno Illo Atayde Macedo Duarte - Mat 20161380041

                    PROJETO I - SimBANCO
    Arquivo destinado às funções que manipulam os movimentos  */




#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"mov.h"

//Função responsável por inserção de um registro de determinado cliente na lista movimentos
boolean insMovimento(movimento *lstMov,const char* desMov,float valMov){
    movimento aux;
    movimento novo;

    aux = *lstMov;

    if ((novo = (tStMov*) malloc(sizeof(tStMov))) == NULL)
        return false;
    //novo->saldo = 0.00; //talvez tenha que ser removida
    novo->valMovimento = valMov;
    strcpy(novo->descMovimento,desMov);

    if (aux == NULL){
        //novo->idCliente = 1;
        novo->proxMovimento = NULL;
        *lstMov = novo;
        return true;
    }
    //novo->idCliente = (aux->idCliente)+1;
    novo->proxMovimento = aux;
    *lstMov = novo;
    return true;
}

//Função responsável por remoção de todos os registros de um cliente especifico na lista movimentos
boolean remMovimentos(movimento *lstMov){
    movimento auxMov;//, auxMovTemp;

    do{
        if(!(auxMov = *lstMov))
        //if(auxMov == NULL)
            return false;
        //auxMovTemp = auxMov->proxMovimento;
        //*lstMov = auxMovTemp;
        *lstMov = auxMov->proxMovimento;
        free(auxMov);
    }while(*lstMov != NULL);//(auxMovTemp != NULL);
    return true;
}

