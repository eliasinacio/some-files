// AS PILHAS SERÃO OS PRÉDIOS 

#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

struct elemento {
  Peca dados;
  struct elemento * prox;
};

// criação normal, aloca e retorna o ponteiro
Pilha * criarPilha () {
  Pilha * pi;
  pi = (Pilha*)malloc(sizeof(Pilha));
  if (pi != NULL) {
    *pi = NULL;
  }
  return pi;;
}

int adicionarPilha (Pilha * pi, Peca peca) {
  if (pi == NULL) return 0;
  
  else {
    Elemento * novo;
    novo = (Elemento*)malloc(sizeof(Elemento));
    if (novo == NULL) return 0;

    novo->dados.tipo = peca.tipo;
    novo->prox = *pi;
    *pi=novo;
    return 1;
  }
}

// remove o superior na pilha
int removerPilha (Pilha * pi) {
  if (pi == NULL) return 0;
  else if (*pi == NULL) return 0;
  else {
    Elemento * aux = *pi;
    *pi = aux->prox;
    free(aux);
    return 1;
  }
}

int acessarPilha (Pilha * pi, Peca * p) {
  if (pi == NULL) return 0;
  else if (*pi == NULL) return 0;
  else {
    Elemento * aux = *pi;
    p->tipo = aux->dados.tipo;
    return 1;
  }
}

// retorna o número de elementos da pilha
int tamanhoPilha (Pilha * pi) {
  if (pi == NULL) return 0;
  else if (*pi == NULL) return 0;
  else {
    Elemento * aux = *pi;
    int cont = 1;

    while (aux->prox != NULL) {
      cont++;
      aux = aux->prox;
    }
    return cont;
  }
}

int limparPilha (Pilha * pi) {
  if (pi != NULL) {
    Elemento * aux;

    while (*pi != NULL) {
      aux = *pi;
      *pi = aux->prox;
      free(aux);
    }
    return 1;
  }
}

int vaziaPilha (Pilha * pi) {
  if (pi == NULL) return 1;
  else if (*pi == NULL) return 1;
  else return 0;
}