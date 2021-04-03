// Lista vai ser usada para as peças nas mãos dos jogadores
// O elemento é o mesmo da Pilha.

#include <stdlib.h>
#include <stdio.h>
#include "pilha.h"
#include "lista.h"

struct elemento {
  Peca dados;
  struct elemento * prox;
};

Lista * criarLista () {
  Lista * li;
  li = (Lista*)malloc(sizeof(Lista));
  if (li != NULL) {
    *li = NULL;
  }
  return li;
}

// adiciona no inicio da lista
int adicionarLista (Lista * li, Peca pe) {
  if (li == NULL) return 0;
  else {
    Elemento * novo;
    novo = (Elemento*)malloc(sizeof(Elemento));
    if (novo == NULL) return 0; 

    novo->dados = pe;
    novo->prox = *li;
    *li = novo;

    return 1;
  }
}

// retira o elemento que possua o tipo igual ao passado por parâmetro.
int retirar (Lista * li, int tipo) { 
  if (li == NULL) return 0;
  if (*li == NULL) return 0;
  else {
    Elemento * aux = *li;
    if (aux->dados.tipo == tipo) { // se o primeiro for uma peça desejada retira logo
      *li = aux->prox;
      free(aux);
    } else {
      Elemento * aux2;
      while (aux != NULL) {
        if (aux->prox->dados.tipo == tipo) {
          aux2 = aux->prox; // salvando o elemento a ser deletado;
          aux->prox = aux2->prox;
          free(aux2);
          return 1;
        }
        aux = aux->prox;
      }
    }
  }
}

/* analisa se na lista existe peça do tipo passado por parâmetro 
e retorna a posição da primeira desse tipo (e 0 se não existir) */
int acessar (Lista * li, int tipo) {
  if (li == NULL || *li == NULL) {
    return 0;
  }
  if (tipo >= 1 && tipo <= 3) {
    Elemento * aux = *li;
    int cont = 0; 
    
    while (aux != NULL) {
      cont++;
      if (aux->dados.tipo == tipo) {
        return cont;
      }
      aux = aux->prox;
    }
  }
  else return 0;
}

// analisa a quantidade de peças/elementos do tipo passado por parâmetro
int quantidadePeca (Lista * li, int tipo) {
  if (li == NULL || *li == NULL) {
    return 0;
  }
  if (tipo >= 1 && tipo <= 3) {
    Elemento * aux = *li;
    int cont = 0; 
    
    while (aux != NULL) {
      if (aux->dados.tipo == tipo) {
        cont++;
      }
      aux = aux->prox;
    }
    return cont;
  }
  else return 0;
}