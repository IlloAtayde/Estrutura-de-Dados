typedef struct noArvore{
    int dado;
    struct noArvore *noEsq;
    struct noArvore *noDir;
}tNoArvore;

typedef tNoArvore* ptr_tNoArvore;

int inicializaRaiz(ptr_tNoArvore *arvore, int valor);

ptr_tNoArvore buscaNo(ptr_tNoArvore arvore, int valBusca);

int insereEsquerda(ptr_tNoArvore *arvore,int valor, int valRaiz);

int insereDireita(ptr_tNoArvore *arvore, int valor, int valRaiz);

void exibePreOrdem(ptr_tNoArvore arvore);

void exibeInOrdem(ptr_tNoArvore arvore);

void exibePosOrdem(ptr_tNoArvore arvore);
