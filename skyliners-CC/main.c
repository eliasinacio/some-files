#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include "pilha.h"
#include "lista.h"
#include "jogo.h"

int main () {
  Matriz cidade = criarMatriz();

  // criando os jogadores
  Jogador * player1, * player2, * player3, * player4;
  player1 = (Jogador*)malloc(sizeof(Jogador));
  player2 = (Jogador*)malloc(sizeof(Jogador));
  player3 = (Jogador*)malloc(sizeof(Jogador));
  player4 = (Jogador*)malloc(sizeof(Jogador));
  
  // enchendo as listas com as peças
  prepararJogador(player1); 
  prepararJogador(player2);
  prepararJogador(player3);
  prepararJogador(player4);

  system("cls");
  printf("\n              ##### SKYLINERS ##### \n\n");
  printf(" Olá, jogadores. Atentem para as regras: \n\n");
  printf(" -> O jogo inicia pelo jogador da vista Sul. \n");
  printf(" -> Todos começam com 12 andares, 2 telhados e 1 parque. \n");
  printf(" -> Não podem ser jogadas peças nas posições marcadas com [*] \n\n");
  printf(" O jogo inicia com 6 andares colocados aleatoriamente ao redor do parque cetral. \n\n");
  
  int fim = 0;

  // coloca o parque e as 6 peças aleatórias em volta
  inicioAleatorio(cidade);

  while (1) {
    // fiz essa relação while e for, para ajudar na hora de encerrar a partida de forma justa
    for (int i=1; i<5; i++) {
      mostrarMatriz(cidade);

      Jogador * playerDaRodada;

      // verifica qual o jogador da rodada
      printf("\n Vez do jogador com vista ");
      if (i == 1) {
        printf("sul. \n\n");
        playerDaRodada = player1;
      } else if (i == 2) {
        printf("oeste. \n\n");
        playerDaRodada = player2;
      } else if (i == 3) {
        printf("norte. \n\n");
        playerDaRodada = player3;
      } else if (i == 4) {
        printf("leste. \n\n");
        playerDaRodada = player4;
      }

      printf("Digite: \n");
      printf(" [0] para mostrar vista.\n");
      printf(" [1] para jogar andar (tem %d). \n" , quantidadePeca(playerDaRodada->pecas, 1));
      printf(" [2] para jogar telhado (tem %d). \n", quantidadePeca(playerDaRodada->pecas, 2));
      printf(" [3] para jogar parque (tem %d) \n", quantidadePeca(playerDaRodada->pecas, 3));
      printf(">> ");
      int opt = -1;

      // recebendo a opção e validando
      while (1) {
        scanf("%d", &opt);
        while (getchar() != '\n');
        
        if (opt <= 3 && opt >= 1) {
          if (quantidadePeca(playerDaRodada->pecas, opt) < 1) {
            printf("você não possui mais peças desse tipo.\n Digite outra: ");
          } else break; 
        }
        else if (opt != 0) printf("Erro. Digite novamente: ");
        else break;
      }
       
      // vista
      if (opt == 0) {
        // essa função de mostrar vista retorna os pontos, pra aproveitar toda a varredura feita nessa função 
        // (já que pra contar os pontos teria todo um processo de analizar a matriz de novo dependendo da vista)
        int pontos = vistaePontos(cidade, i, 1);
        printf("Pontos: %d", pontos);

        getchar();
      } 
      
      // jogada 
      else {
        printf("\nDigite a posição: ");

        while (1) {
          char position[2];
          int col = -1, lin = -1;

          scanf("%s", position);

          if (isdigit(position[1]) == 0) {
            printf("Inválido. Digite novamente: ");
          } else {
            if (position[0] == 'a' || position[0] == 'A') col = 0;
            if (position[0] == 'b' || position[0] == 'B') col = 1;
            if (position[0] == 'c' || position[0] == 'C') col = 2;
            if (position[0] == 'd' || position[0] == 'D') col = 3;
            if (position[0] == 'e' || position[0] == 'E') col = 4;
            if (position[1] == '1') lin = 0;
            if (position[1] == '2') lin = 1;
            if (position[1] == '3') lin = 2;
            if (position[1] == '4') lin = 3;
            if (position[1] == '5') lin = 4;

            // se não entrar em nenhum desses ifs alguma coisa tá errada
            if (col == -1 || lin == -1) {
              printf("Inválido. Digite novamente: ");
            }
            else {
              int deuCerto = jogada(playerDaRodada->pecas, opt, cidade[lin][col]);
              if (deuCerto == 1) break;
              else (printf("Jogada inválida. Tente novamente: "));
            }
          }
        }  
      }

      // quando a quantidade de peças do tipo 1 (andar) acabar, marca essa como a ultima rodada
      if (quantidadePeca(playerDaRodada->pecas, 1) == 0) {
        fim = 1;
      }

      system("cls");
    }
    // o while vai ser encerrado se o ultimo for for a ultima rodada  
    if (fim == 1) break;
  }

  // atualizando os pontos 

  player1->pontos = vistaePontos(cidade, 1, 0);
  player2->pontos = vistaePontos(cidade, 2, 0);
  player3->pontos = vistaePontos(cidade, 3, 0);
  player4->pontos = vistaePontos(cidade, 4, 0);

  // conferindo o vencedor 
  int vencedor = 0, ptsVencedor = 0;

  if (player1->pontos > ptsVencedor) {
    vencedor = 1; 
    ptsVencedor = player1->pontos;
  }
  if (player2->pontos > ptsVencedor) {
    vencedor = 2; 
    ptsVencedor = player2->pontos;
  }
  if (player3->pontos > ptsVencedor) {
    vencedor = 3; 
    ptsVencedor = player3->pontos;
  }
    
  if (player4->pontos > ptsVencedor) {
    vencedor = 4; 
    ptsVencedor = player4->pontos;
  }

  printf("\n\n   ===== FIM DA PARTIDA =====\n\n");

  mostrarMatriz(cidade);
  
  printf("\n");
  printf("   O vencedor é o jogador com vista ");
  if (vencedor == 1) printf("SUL");
  if (vencedor == 2) printf("OESTE");
  if (vencedor == 3) printf("NORTE");
  if (vencedor == 4) printf("LESTE");

  printf("\n");
  printf("Esta é a sua vista: \n");
  vistaePontos(cidade, vencedor, 1);
  printf("Pontos do Vencedor: %d\n", ptsVencedor);

  return 0;
}
