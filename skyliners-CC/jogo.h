// criei um struct pro jogador pra salvar a pontuação dele tambem

struct jogador {
  Lista * pecas;
  int pontos;
};

typedef Pilha *** Matriz;
typedef struct jogador Jogador;


// relacionadas aos jogadores 

int prepararJogador (Jogador*);

// listas e pilhas

int jogada (Lista * , int , Pilha *);
int analizarJogada (Lista *, int, Pilha *);
int topoPilha (Pilha * );


// relacionadas a matriz/cidade

Matriz criarMatriz ();
int mostrarMatriz (Matriz);
int inicioAleatorio (Matriz); 
int vistaePontos (Matriz, int, int);


// outras auxiliares

int absolute (int );
int maiorDaCidade (Matriz);