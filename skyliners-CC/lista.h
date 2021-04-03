typedef struct elemento Elemento;
typedef Elemento * Lista;

Lista * criarLista ();

// adiciona no inicio da lista
int adicionarLista (Lista *, Peca);

// retira o elemento que possua o tipo igual ao passado por parâmetro.
int retirar (Lista *, int);

/* analisa se na lista existe peça do tipo passado por parâmetro 
e retorna a posição da primeira desse tipo (e 0 se não existir) */
int acessar (Lista *, int);

int quantidadePeca (Lista * , int );