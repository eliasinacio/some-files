#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "pilha.h"
#include "lista.h"
#include "jogo.h"

// cria a lista de peças dos jogadores e preenche com as peças e suas quantidades corretas
int prepararJogador (Jogador * player) {
  player->pecas = criarLista();
  
  Peca andar, telhado, parque;
  andar.tipo = 1;
  telhado.tipo = 2;
  parque.tipo = 3;
  for (int i=0; i<12; i++) {
    adicionarLista(player->pecas, andar);
  }

  for (int i=0; i<2; i++) {
    adicionarLista(player->pecas, telhado);
  }

  adicionarLista(player->pecas, parque);
  

  return 1;
}

// Analizar se a jogada é possível
int jogada (Lista * jogador, int tipo, Pilha * predio) {
  // erro de peças sobre tetos ou parques
  if (topoPilha(predio) == 2 || topoPilha(predio) == 3) {
    printf(" -> Peças não podem ser jogadas sobre telhados ou parques.\n");
    return 0;
  } 

  // erro de parques sobre telhados ou andares
  if (tipo == 3 && tamanhoPilha(predio) != 0) {
    printf(" -> Parques não podem ser jogados sobre qualquer outra peça.\n");
    return 0;
  }

  // erro tetos sobre chão
  if (tipo == 2 && tamanhoPilha(predio) == 0) {
    printf(" -> Tetos só podem ser jogados sobre andares.\n");
    return 0;
  }

  else {
    Peca jogada;
    jogada.tipo = tipo;
    adicionarPilha(predio, jogada);
    retirar(jogador, tipo);
    return 1;
  }
}

// Retorna o tipo da peça superior na pilha (prédio)  
int topoPilha (Pilha * predio) {
  Peca pe, * pPe;
  pPe = &pe;
  acessarPilha(predio, pPe);
  return pe.tipo;
}



// cria a cidade: matriz de pilhas.
Matriz criarMatriz () {
  Pilha *** matriz;
  matriz = (Pilha***)malloc(5 * sizeof(Pilha**));
  for (int i=0; i<5; i++) {
    matriz[i] = (Pilha**)malloc(5 * sizeof(Pilha*));
  }

  for (int i=0; i<5; i++) {
    for (int j=0; j<5; j++) {
      matriz[i][j] = criarPilha();
    }
  }

  return matriz;
}

int mostrarMatriz (Matriz cidade) {
  // os printfs vão ser bem estranhos mas de certa forma sempre esse tipo de coisa vai parecer gambiarra kk 
  /* mas basicamente ao mostrar, o código vai verificar quando há prédios "travados" ou parques, ou quando o numero é maior ou menor
  para enquadrar na formatação, e prevê com os switchs onde pôr as coordenadas... */
  printf("\n");
  for (int i=0; i<5; i++) {
    printf("           ");
    if (i == 2) printf("+----+----+----+----+----+             ↓\n");
    else if (i == 3) printf("+----+----+----+----+----+             ↑\n");
    else printf("+----+----+----+----+----+\n");
    
    printf("           ");

    for (int j=0; j<5; j++) {
      printf("|");
      printf(" "); 
      if (tamanhoPilha(cidade[i][j]) <= 9) printf(" "); // ajuda na formatação, verifica se tem um ou dois dígitos no número
      printf("%d", tamanhoPilha(cidade[i][j]));

      if (topoPilha(cidade[i][j]) == 2 || topoPilha(cidade[i][j]) == 3) printf("*"); // se o predio está com telhado ou parque
      else printf(" ");
    }

    printf("|");
    
    switch (i) {
    case 0:
      printf(" 1\n");
      break;
    case 1:
      printf(" 2         Norte\n");
      break;
    case 2:
      printf(" 3   Oeste →   ← Leste \n");
      break;
    case 3:
      printf(" 4          Sul\n");
      break;
    case 4:
      printf(" 5\n");
      break;
    default:
      break;
    }
  }
  printf("           +----+----+----+----+----+\n");
  printf("             A     B    C    D    E  \n");
}

int inicioAleatorio (Matriz cidade) {
  // adicionando o parque no centro
  Peca parque; parque.tipo = 3;
  adicionarPilha(cidade[2][2], parque);

  // adicionando as 6 peças aleatoriamente ao redor do centro
  Peca andar; andar.tipo = 1;
  
  srand(time(NULL));
  
  for (int i=0; i < 6; i++) {
    // gerando valores aleatórios na faixa de 0 a 8 (não conta o 8), tem 8 lugares possiveis ao redor do parque
    int num = rand() % 8; 

    switch (num) {
    case 0:
      adicionarPilha(cidade[1][1], andar); 
      break;
    case 1:
      adicionarPilha(cidade[1][2], andar); 
      break;
    case 2:
      adicionarPilha(cidade[1][3], andar); 
      break;
    case 3:
      adicionarPilha(cidade[2][1], andar); 
      break;
    case 4:
      adicionarPilha(cidade[2][3], andar); 
      break;
    case 5:
      adicionarPilha(cidade[3][1], andar); 
      break;
    case 6:
      adicionarPilha(cidade[3][2], andar); 
      break;
    case 7:
      adicionarPilha(cidade[3][3], andar); 
      break;
    
    default:
      break;
    }
  }
}

// função de vista, e de atualização dos pontos.
// se o ultimo parametro for 0 apenas retorna a pontuação do jogador. Se for 1, mostra sua vista
int vistaePontos(Matriz cidade, int jogador, int mostrar) {
  int matriz[5][5];
  int pontos = 0; // aproveitando que essa função percorre a cidade trocentas vezes, ela retorna os pontos também
  // essa matriz vai receber as alturas, mas o foco mesmo é converter, independente da vista, para uma matriz sempre voltada para o mesmo lado
  // a função absolute eu criei pra ajudar a fazer operações mais simples com módulo dos números
  // o código se baseia em criar um "mapa" visual com 0 onde não deve ser mostrado nada e de 1 a 5, dependendo da posição do predio, mais a frente ou mais atrás 

  switch (jogador) {
    // caso 1, é a vista do sul
    case 1: {
      for (int c=0; c<5; c++) {
        for (int l=4; l!=-1; l--) {
          matriz[l][c] = tamanhoPilha(cidade[l][c]);
        }
      }
      
      break;
    }

    case 2: {
      // vista oeste
      for (int l=0; l<5; l++) {
        for (int c=0; c<5; c++) {
          matriz[absolute(c-4)][l] = tamanhoPilha(cidade[l][c]);
        }
      }
      
      break;
    }

    case 3: {
      // vista norte
      for (int c=0; c<5; c++) {
        for (int l=0; l<5; l++) {
          matriz[absolute(l-4)][absolute(c-4)] = tamanhoPilha(cidade[l][c]);
        }
      }

      break;
    }

    case 4: {
      // vista leste
      for (int l=4; l!=-1; l--) {
        for (int c=4; c!=-1; c--) {
          matriz[c][absolute(l-4)] = tamanhoPilha(cidade[l][c]);
        }
      }
      break;
    }

    default: 
      break;
  }

  // a partir deste ponto independente do lado da vista, o código usa a matriz criada com os pontos de altura dos prédios
  
  // aqui eu crio uma matriz com 5 colunas e a qntdd de linhas será o máximo de altura do maior prédio
  // depois ela vai ser preenchida de forma que repita o mesmo "tipo de andar" dependendo da altura do prédio
  // por padrão ela vai estar com 0 em todas as posições
  int max = maiorDaCidade(cidade);
  int visao[max][5];
  for (int i=0; i<max+1; i++) {
    for (int j=0; j<5; j++) {
      visao[i][j] = 0;
    }
  }
  
  for (int c=0; c<5; c++) {
    // o código vai percorrer a matriz de coluna em coluna, e dependendo do valor ali, vai repetir na matriz maior
    int rep = 0; // repetições/altura , vai indicar quantas vezes o tipo de andar(no caso pra diferenciar a largura) vai ser colocada
    int dis = 0;  // "distância"/largura, indica a largura do andar, dependendo do quão distante está na vista
    int cont = 0; // este contador vai ser usado para não perder a posição em que foi repetido o ultimo andar
    

    // esse for representa as linhas da matriz
    for (int l=0; l<5; l++) {
      // se o valor na matriz for zero ele é ignorado, pois não apareceria na vista de forma alguma
      if (matriz[l][c] != 0) {
        rep = matriz[l][c]; // como na matriz vista
        dis = l; int x = 1;
        
        // agora vai preencher a matriz visao repetindo os valores onde serão realmente visiveis
        for (int i=cont; i<rep; i++) {
          // esse cont sempre é salvo quando quando as repetições acabam, para no próximo ciclo começar daí
          if (rep == 0) {
            cont = i;
            break;
          }
          visao[i][c] = absolute(dis-5);
        }
      }
    }
  }
  
  // contando os pontos
  for (int c=0; c<5; c++) {
    int aux;
    for (int l=max; l!=-1; l--) {
      if (visao[l][c] != 0 && visao[l][c] != aux) {
        pontos++;
      }
      aux = visao[l][c];
    }
  }

  if (mostrar == 1) {
    // mostrando, dependendo do valor na matriz de inteiros vai mostrar uma largura diferente
    for (int l=max; l!=-1; l--) {
      for (int c=0; c<5; c++) {
        if (visao[l][c] == 0) printf("             ");
        if (visao[l][c] == 5) printf("      Ħ      ");
        if (visao[l][c] == 4) printf("     ĦĦĦ     ");
        if (visao[l][c] == 3) printf("    ĦĦĦĦĦ    ");
        if (visao[l][c] == 2) printf("   ĦĦĦĦĦĦĦ   ");
        if (visao[l][c] == 1) printf("  ĦĦĦĦĦĦĦĦĦ  ");
      }
      printf("\n");
    }

    printf("\n");
  }

  return pontos;
}


// retorna o valor absoluto do passado por parâmetro
int absolute (int valor) {
  if (valor < 0) return valor*(-1); 
  return valor;
}

// retorna o valor da altura do maior predio (pilha) da cidade (matriz)
int maiorDaCidade (Matriz cidade) {
  int maior = 0;
  for (int c=0; c<5; c++) {
    for (int l=4; l!=-1; l--) {
      if (tamanhoPilha(cidade[l][c]) > maior) maior = tamanhoPilha(cidade[l][c]); 
    }
  }
  return maior;
}