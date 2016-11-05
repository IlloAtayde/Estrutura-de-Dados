typedef int tipoArray;

void geraArray(int tamArray, tipoArray **arrayOrdCres, tipoArray **arrayOrdDecres);///Função gera dois arrays dinâmicos, crescente e decrescente, de tamanho especificado e retorna por referência dois ponteiros para os mesmos

void geraArrayDesord(int tamArray, tipoArray **arrayDesord);///Função gera um array dinâmico desordenado e de elementos não repetidos, de tamanho especificado e retorna por referência um ponteiro para o mesmo

void imprimirArray(int tamArray, const tipoArray *arrayPrint);///Função responsável por exibir os elementos do array na tela

void copiaArray(int tamArray, const tipoArray *arrayOriginal, tipoArray* *arrayCopia);///Efetua a cópia do array passado
