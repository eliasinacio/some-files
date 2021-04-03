struct peca {
/* 1: andar, 
  2: telhado, 
  3: parque */
  int tipo;
};

typedef struct peca Peca;
typedef struct elemento Elemento;
typedef Elemento * Pilha;

// criação normal, aloca e retorna o ponteiro
Pilha * criarPilha ();

// Adiciona uma peça no topo da pilha
int adicionarPilha (Pilha *, Peca);

// Coloca na peça passada por parâmetro, os dados da peça superior na pilha;
int acessarPilha (Pilha *, Peca *);

// Retorna o número de peças na pilha
int tamanhoPilha (Pilha *);

// Esvazia a pinha
int limparPilha (Pilha *);