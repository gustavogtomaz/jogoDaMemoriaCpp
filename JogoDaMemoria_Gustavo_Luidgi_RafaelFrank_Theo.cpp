#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main() {
  setlocale(LC_ALL, "portuguese");
  /*
  MN=matriz normal
  MT=matriz transposta
  MC=matriz c coluna trocada
  ML=matriz com linha trocada
  MENU=0, pra ir pro case 0
  MA=pra guardar o n gerado aleatoriamente
  matrizVerso=matriz do verso das carta
  matrizUsada=matriz usada
  jaAberta=para n abrir cartas ja abertas
  paresacertados=quantidade de pares acertados
  lp, cp= linha/coluna primeira carta
  ls, cs= linha/coluna segunda carta
  */

  int menu = 0, mn[4][4] = {6,1,7,2,5,3,8,4,3,5,6,2,4,8,1,7},
      mt[4][4], ml[4][4], mc[4][4], ma, matrizUsada[4][4], matrizVerso[4][4],
      lp, cp, ls, cs, qj=0, jaAberta = 0, paresacertados = 0;


  // declarando matriz verso
  for (int l = 0; l < 4; l = l + 1) {
    for (int c = 0; c < 4; c = c + 1) {
      matrizVerso[c][l] = 0;
    }
  }
  // fazendo matriz transposta
  for (int l = 0; l < 4; l = l + 1) {
    for (int c = 0; c < 4; c = c + 1) {
      mt[c][l] = mn[l][c];
    }
  }
  // declarando matriz linha trocada
  for (int l = 0; l < 4; l = l + 1) {
    for (int c = 0; c < 4; c = c + 1) {
      ml[l][c] = mn[l][c];
      if (l == 2) {
        ml[3][c] = mn[2][c];
      }
      if (l == 3) {
        ml[2][c] = mn[3][c];
      }
    }
  }
  // declarando coluna trocada
  for (int l = 0; l < 4; l = l + 1) {
    for (int c = 0; c < 4; c = c + 1) {
      mc[l][c] = mn[l][c];
      if (c == 2) {
        mc[l][3] = mn[l][3];
      }
      if (c == 3) {
        mc[l][2] = mn[l][2];
      }
    }
  }
  // estrutura d repeti�ao pq quebrou no case(break) se n ia seguir em lista
  do {
    switch (menu) {
    case 0:
           cout<< "INSTRU��ES: No jogo digite linha, coluna(linha, enter, coluna) para "
              "escolher as cartas que voc� vai virar;\nQuando as cartas nao "
              "estiverem reveladas o numero 0 vai aparecer\n\n\n"
           << "Digite:\n"
           << "1-Jogar\n"
           << "2-Cr�ditos\n"
           << "3-Sair\n";
      cin >> menu;
      //Para caso seja digitado um n maior ou menor do que os usados
      if (menu > 3 || menu < 1) {
        menu = -1;
      }
      break;

    case 1:
      srand(time(NULL));
      ma = rand() % 4 + 1;
      //  Jogo em si
      cout << "matriz usada: " << ma << "\n";
      //Switch case da variavel q guarda o n aleatorio para "escolher" a matriz
      switch (ma) {
        // Normal 1
      case 1:
        for (int l = 0; l < 4; l = l + 1) {
          for (int c = 0; c < 4; c = c + 1) {
            matrizUsada[l][c] = mn[l][c];
          }
        }
        break;
        // Transposta 2
      case 2:
        for (int l = 0; l < 4; l = l + 1) {
          for (int c = 0; c < 4; c = c + 1) {
            matrizUsada[l][c] = mt[l][c];
          }
        }
        break;
        // Linha trocada 3
      case 3:
        for (int l = 0; l < 4; l = l + 1) {
          for (int c = 0; c < 4; c = c + 1) {
            matrizUsada[l][c] = ml[l][c];
          }
        }
        break;
        // Coluna trocada 4
      case 4:
        for (int l = 0; l < 4; l = l + 1) {
          for (int c = 0; c < 4; c = c + 1) {
            matrizUsada[l][c] = mc[l][c];
          }
        }
        break;
      }
      //Jogadas, estrutura de repeti�ao para evitar jogadas erradas
      while (qj < 24 && paresacertados < 8) {
        cout << "Digite linha e coluna da sua 1 carta\n";
        cin >> lp >> cp;
        if (matrizVerso[lp][cp] == 0) {
          matrizVerso[lp][cp] = matrizUsada[lp][cp];
        } else {
          while (jaAberta < 1 || lp > 3 || cp > 3) {
            cout << "Digite linha e coluna da sua 1 carta novamente\n";
            cin >> lp >> cp;
            if (matrizVerso[lp][cp] == 0) {
              matrizVerso[lp][cp] = matrizUsada[lp][cp];
              jaAberta = 1;
            }
          }
        }
        jaAberta = 0;
        cout << "Digite linha e coluna da sua 2 carta\n";
        cin >> ls >> cs;
        if (matrizVerso[ls][cs] == 0) {
          matrizVerso[ls][cs] = matrizUsada[ls][cs];
        } else {
          while (jaAberta < 1 || ls > 3 || cs > 3) {
            cout << "Digite linha e coluna da sua 2 carta novamente\n";
            cin >> ls >> cs;
            if (matrizVerso[ls][cs] == 0) {
              matrizVerso[ls][cs] = matrizUsada[ls][cs];
              jaAberta = 1;
            }
          }
        }
        if (menu==1){system("cls");}
        //Cout da matriz com as cartas viradas
        for (int l = 0; l < 4; l = l + 1) {
          for (int c = 0; c < 4; c = c + 1) {
            cout << matrizVerso[l][c] << " ";
          }
          cout << "\n";
        }
        cout << "\n";
        //Checagem da igualdade
        if (matrizUsada[lp][cp] != matrizUsada[ls][cs]) {
          matrizVerso[lp][cp] = 0;
          matrizVerso[ls][cs] = 0;
          cout << "JOGADA NOK\n";
        } else if (matrizUsada[lp][cp] == matrizUsada[ls][cs]) {
          paresacertados = paresacertados + 1;
          cout << "JOGADA OK\n";
        }
        //Checagem de vitoria ou derrota
        qj = qj + 1;
        if (paresacertados == 8) {
          cout << "parabens voce venceu!!\n";
           system("pause");
             system("cls");
          qj=0;
          menu=0;
        paresacertados=0;
          break;
        }
        if (qj == 24) {
          cout << "GAME OVER\n";
            system("pause");
             system("cls");
           qj=0;
          menu=0;
          paresacertados=0;
          break;
        }
      }
      break;

    case 2:
     system("cls");
     cout<<"Cr�ditos:\n Luidgi Poffo, Gustavo Garcia, Theo Lopes, "
              "Rafael Frank\n\n\n";
      menu = 0;
      break;

    default:
      cout << "essa opcao e invalida\n";
      menu = 0;
      break;
    }
    if (menu==1){system("cls");}
  } while (menu < 3);

  return 0;
}
