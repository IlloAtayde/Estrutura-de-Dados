typedef int tipoArray;

void geraArray(int tamArray, tipoArray **arrayOrdCres, tipoArray **arrayOrdDecres);///Fun��o gera dois arrays din�micos, crescente e decrescente, de tamanho especificado e retorna por refer�ncia dois ponteiros para os mesmos

void geraArrayDesord(int tamArray, tipoArray **arrayDesord);///Fun��o gera um array din�mico desordenado e de elementos n�o repetidos, de tamanho especificado e retorna por refer�ncia um ponteiro para o mesmo

void imprimirArray(int tamArray, const tipoArray *arrayPrint);///Fun��o respons�vel por exibir os elementos do array na tela

void copiaArray(int tamArray, const tipoArray *arrayOriginal, tipoArray* *arrayCopia);///Efetua a c�pia do array passado
