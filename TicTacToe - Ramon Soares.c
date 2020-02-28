/*
 ============================================================================
 Name         : Simple Tic-Tac-Toe
 Author       : Ramon Soares Mendes Meneses Leite
 Version      : 1.00
 E-mail:      : ramnsores1000@gmail.com
 University   : Universidade Federal de Goiás - Catalão GO
 Objective    : Just for fun
 ============================================================================
 */

//Bibliotecas utilizadas:

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <windows.h>

//Funções:

void reset_mesa(char m[3][3]); //inicializa e limpa a mesa
void mostra_mesa(char m[3][3]); //imprime a mesa atual
void jogador1(char m[3][3]); //função para operar escolhas do jogador
void jogador2(char m[3][3]); //função para operar escolhas do jogador 2 (caso multiplayer)
void jogador_pc_facil(char m[3][3]); //função para operar o pc no modo facil
void jogador_pc_medio(char m[3][3]); //função para operar o pc no modo medio
void jogador_pc_dificil(char m[3][3]); //função para operar o pc no modo dificil
void regras(); //função para mostrar regras
void sair (); //função para sair do jogo
char vencedor(char m[3][3]); //função para verificar vencedor
void gotoxy(int x, int y); //função auxiliar para tela final do jogo (permite o posicionamento do cursor em qualquer posição da tela)
void tela_final(char v, int modo); // tela final do jogo (ping-pong com string)

int main() {

    //Inicialização das variáveis da main
    setlocale(LC_ALL,"Portuguese");
    int opc = 0, modo = 0, j=0, escolha, par_impar;
    char m[3][3], venc, username[30], pcname[30], username2[30];

    //menu
    printf("      x=============================x\n");
    printf("      o                             o\n");
    printf("      x      # JOGO DA VELHA #      x\n");
    printf("      o                             o\n");
    printf("      x=============================x\n\n");

    printf("  >>>     Escolha um modo    <<<  \n\n");
    printf("  >>>  1 - Jogar contra CPU  <<<  \n");
    printf("  >>>  2 - Multiplayer       <<<  \n");
    printf("  >>>  3 - Regras            <<<  \n");
    printf("  >>>  4 - Sair              <<<  \n\n");

    //Modo do jogo
    while (modo != 1 && modo != 2 && modo != 3 && modo != 4) {
        printf("  > ");
        scanf("%d", &modo);
    }

    if(modo == 1) {
        system("cls");
        printf("  >>> Escolha a dificuldade <<<  \n\n");
        printf("  >>> 1 - Fácil   <<<  \n");
        printf("  >>> 2 - Médio   <<<  \n");
        printf("  >>> 3 - Difícil <<<  \n\n");

        //Opção de dificuldade
        while (opc != 1 && opc != 2 && opc != 3) {
            printf("  > ");
            scanf("%d", &opc);
        }
        system("cls");
        printf(" >>>>> Digite o nome do Jogador 1: ");
        scanf(" %[^\n]s", username);
        printf(" >>>>> Digite um nome para o Computador: ");
        scanf(" %[^\n]s", pcname);
    } else if (modo == 2) {
        system("cls");
        printf(" >>>>> Digite o nome do Jogador 1: ");
        scanf(" %[^\n]s", username);
        printf(" >>>>> Digite o nome do Jogador 2: ");
        scanf(" %[^\n]s", username2);
    } else if (modo == 3) {
        regras();
    } else if (modo == 4) {
        sair();
    }

    //impar ou par para ver quem começa
    do {
        printf(" >>>>> (Jogador 1) - Par (0) ou Ímpar (1) para começar > ");
        scanf("%d", &escolha);
    } while(escolha != 1 && escolha != 0);

    printf(" >>>>> Sorteando");
    Sleep(500);
    printf(".");
    Sleep(500);
    printf(".");
    Sleep(500);
    printf(".");

    srand(time(NULL)); //randomizar 0 ou 1
    par_impar = rand()%2;
    reset_mesa(m);

    do {
        mostra_mesa(m);
        if(escolha==par_impar) {
            if(j==0) {
                printf("\n\n >>>>> O número sorteado foi %d, então o %s começa!", par_impar, username);
            }
            printf("\n\n\n   Sua vez %s!\n", username);
            jogador1(m);
        } else {
            if(modo == 1) {
                if(j==0) {
                    printf("\n\n >>>>> O número sorteado foi %d, então o %s começa!", par_impar, pcname);
                    Sleep(2000);
                }
                printf("\n\n\n   Vez do %s... ", pcname);
                if (opc == 1) {
                    jogador_pc_facil(m);

                } else if (opc == 2) {
                    jogador_pc_medio(m);

                } else if (opc == 3) {
                    jogador_pc_dificil(m);
                }
            } else if(modo == 2) {
                if(j==0) {
                    printf("\n\n >>>>> O número sorteado foi %d, então o %s começa!", par_impar, username2);
                    Sleep(2000);
                }
                printf("\n\n\n   Sua vez %s!\n", username2);
                jogador2(m);
            }
        }
        j++;
        par_impar= !par_impar; // troca a variavel de 0 para 1 e vice-versa
        venc = vencedor(m); //venc recebe valor relacionado ao vencedor
    } while(j<9 && venc == ' ');

    mostra_mesa(m);
    tela_final(venc, modo);//acaba jogo com tela final

    return 0;
}

void reset_mesa(char m[3][3]) {
    int i, j;

    for(i=0; i<3; i++) {
        for(j=0; j<3; j++) {
            m[i][j]='0';
        }
    }
    mostra_mesa(m);
    printf("\n\n >>>>> Mesa inicializada!");
    Sleep(2500);

    for(i=0; i<3; i++) {
        for(j=0; j<3; j++) {
            m[i][j]=' ';
        }
    }
}

void mostra_mesa(char m[3][3]) {
    int i;

    system("cls");

    printf("\n   V   0   1   2 \n");
    for(i=0; i<3; i++) {
        printf("\n   %d   %c | %c | %c ", i, m[i][0], m[i][1], m[i][2]);
        if (i<2)
            printf("\n      ---+---+---");
    }
}

void jogador1(char m[3][3]) {
    int L, C;

    do {
        printf("   Digite uma posição válida > ");
        scanf("%d %d", &L, &C);
    } while(L<0 || L>2 || C<0 || C>2 || m[L][C]!=' ');

    m[L][C] ='X';
}

void jogador2(char m[3][3]) {
    int L, C;

    do {
        printf("   Digite uma posição válida > ");
        scanf("%d %d", &L, &C);
    } while(L<0 || L>2 || C<0 || C>2 || m[L][C]!=' ');

    m[L][C] ='O';

}

void jogador_pc_facil(char m[3][3]) {
    int Linha, Coluna;

    //Condições nivel facil
    //Condições aleatórias
    do {
        Linha = rand()%3;
        Coluna = rand()%3;
    } while(m[Linha][Coluna]!= ' ');

    m[Linha][Coluna]='O';
    Sleep(750);
}

void jogador_pc_medio(char m[3][3]) {

    int Linha, Coluna;

    //Condições nível medio
    if (m[0][0] == 'O' && m[0][1] == 'O' && m[0][2] == ' ') {
        Linha = 0;
        Coluna = 2;
    } else if(m[0][0] == 'O' && m[0][2] == 'O' && m[0][1] == ' ') {
        Linha = 0;
        Coluna = 1;
    } else if(m[0][1] == 'O' && m[0][2] == 'O' && m[0][0] == ' ') {
        Linha = 0;
        Coluna = 0;
    } else if(m[0][0] == 'O' && m[1][0] == 'O' && m[2][0] == ' ') {
        Linha = 2;
        Coluna = 0;
    } else if(m[0][0] == 'O' && m[2][0] == 'O' && m[1][0] == ' ') {
        Linha = 1;
        Coluna = 0;
    } else if(m[0][1] == 'O' && m[1][1] == 'O' && m[2][1] == ' ') {
        Linha = 2;
        Coluna = 1;
    } else if(m[0][1] == 'O' && m[2][1] == 'O' && m[1][1] == ' ') {
        Linha = 1;
        Coluna = 1;
    } else if(m[0][2] == 'O' && m[1][2] == 'O' && m[2][2] == ' ') {
        Linha = 2;
        Coluna = 2;
    } else if(m[0][2] == 'O' && m[2][2] == 'O' && m[1][2] == ' ') {
        Linha = 1;
        Coluna = 2;
    } else if(m[0][0] == 'O' && m[1][1] == 'O' && m[2][2] == ' ') {
        Linha = 2;
        Coluna = 2;
    } else if(m[0][0] == 'O' && m[2][2] == 'O' && m[1][1] == ' ') {
        Linha = 1;
        Coluna = 1;
    }

    else if(m[1][0] == 'O' && m[1][1] == 'O' && m[1][2] == ' ') {
        Linha = 1;
        Coluna = 2;
    } else if(m[1][0] == 'O' && m[1][2] == 'O' && m[1][1] == ' ') {
        Linha = 1;
        Coluna = 1;
    } else if(m[1][1] == 'O' && m[1][2] == 'O' && m[1][0] == ' ') {
        Linha = 1;
        Coluna = 0;
    } else if(m[1][1] == 'O' && m[0][2] == 'O' && m[2][0] == ' ') {
        Linha = 2;
        Coluna = 0;
    } else if(m[1][0] == 'O' && m[2][0] == 'O' && m[0][0] == ' ') {
        Linha = 0;
        Coluna = 0;
    } else if(m[1][1] == 'O' && m[2][1] == 'O' && m[0][1] == ' ') {
        Linha = 0;
        Coluna = 1;
    } else if(m[1][2] == 'O' && m[2][2] == 'O' && m[0][2] == ' ') {
        Linha = 0;
        Coluna = 2;
    } else if(m[1][1] == 'O' && m[2][2] == 'O' && m[0][0] == ' ') {
        Linha = 0;
        Coluna = 0;
    }

    else if(m[2][0] == 'O' && m[2][1] == 'O' && m[2][2] == ' ') {
        Linha = 2;
        Coluna = 2;
    } else if(m[2][0] == 'O' && m[2][2] == 'O' && m[2][1] == ' ') {
        Linha = 2;
        Coluna = 1;
    } else if(m[2][1] == 'O' && m[2][2] == 'O' && m[2][0] == ' ') {
        Linha = 2;
        Coluna = 0;
    } else if(m[2][0] == 'O' && m[1][1] == 'O' && m[0][2] == ' ') {
        Linha = 0;
        Coluna = 2;
    } else if(m[2][0] == 'O' && m[0][2] == 'O' && m[1][1] == ' ') {
        Linha = 1;
        Coluna = 1;
    }

    //Condições aleatórias
    else {
        do {
            Linha = rand()%3;
            Coluna = rand()%3;
        } while(m[Linha][Coluna]!=' ');
    }

    m[Linha][Coluna]='O';
    Sleep(750);
}

void jogador_pc_dificil(char m[3][3]) {
    int Linha, Coluna;

    //Condições nivel dificil
    //Condições ofensivas
    if (m[0][0] == 'O' && m[0][1] == 'O' && m[0][2] == ' ') {
        Linha = 0;
        Coluna = 2;
    } else if(m[0][0] == 'O' && m[0][2] == 'O' && m[0][1] == ' ') {
        Linha = 0;
        Coluna = 1;
    } else if(m[0][1] == 'O' && m[0][2] == 'O' && m[0][0] == ' ') {
        Linha = 0;
        Coluna = 0;
    } else if(m[0][0] == 'O' && m[1][0] == 'O' && m[2][0] == ' ') {
        Linha = 2;
        Coluna = 0;
    } else if(m[0][0] == 'O' && m[2][0] == 'O' && m[1][0] == ' ') {
        Linha = 1;
        Coluna = 0;
    } else if(m[0][1] == 'O' && m[1][1] == 'O' && m[2][1] == ' ') {
        Linha = 2;
        Coluna = 1;
    } else if(m[0][1] == 'O' && m[2][1] == 'O' && m[1][1] == ' ') {
        Linha = 1;
        Coluna = 1;
    } else if(m[0][2] == 'O' && m[1][2] == 'O' && m[2][2] == ' ') {
        Linha = 2;
        Coluna = 2;
    } else if(m[0][2] == 'O' && m[2][2] == 'O' && m[1][2] == ' ') {
        Linha = 1;
        Coluna = 2;
    } else if(m[0][0] == 'O' && m[1][1] == 'O' && m[2][2] == ' ') {
        Linha = 2;
        Coluna = 2;
    } else if(m[0][0] == 'O' && m[2][2] == 'O' && m[1][1] == ' ') {
        Linha = 1;
        Coluna = 1;
    }

    else if(m[1][0] == 'O' && m[1][1] == 'O' && m[1][2] == ' ') {
        Linha = 1;
        Coluna = 2;
    } else if(m[1][0] == 'O' && m[1][2] == 'O' && m[1][1] == ' ') {
        Linha = 1;
        Coluna = 1;
    } else if(m[1][1] == 'O' && m[1][2] == 'O' && m[1][0] == ' ') {
        Linha = 1;
        Coluna = 0;
    } else if(m[1][1] == 'O' && m[0][2] == 'O' && m[2][0] == ' ') {
        Linha = 2;
        Coluna = 0;
    } else if(m[1][0] == 'O' && m[2][0] == 'O' && m[0][0] == ' ') {
        Linha = 0;
        Coluna = 0;
    } else if(m[1][1] == 'O' && m[2][1] == 'O' && m[0][1] == ' ') {
        Linha = 0;
        Coluna = 1;
    } else if(m[1][2] == 'O' && m[2][2] == 'O' && m[0][2] == ' ') {
        Linha = 0;
        Coluna = 2;
    } else if(m[1][1] == 'O' && m[2][2] == 'O' && m[0][0] == ' ') {
        Linha = 0;
        Coluna = 0;
    }

    else if(m[2][0] == 'O' && m[2][1] == 'O' && m[2][2] == ' ') {
        Linha = 2;
        Coluna = 2;
    } else if(m[2][0] == 'O' && m[2][2] == 'O' && m[2][1] == ' ') {
        Linha = 2;
        Coluna = 1;
    } else if(m[2][1] == 'O' && m[2][2] == 'O' && m[2][0] == ' ') {
        Linha = 2;
        Coluna = 0;
    } else if(m[2][0] == 'O' && m[1][1] == 'O' && m[0][2] == ' ') {
        Linha = 0;
        Coluna = 2;
    } else if(m[2][0] == 'O' && m[0][2] == 'O' && m[1][1] == ' ') {
        Linha = 1;
        Coluna = 1;
    }


    //Condições Defensivas
    else if(m[0][0] == 'X' && m[0][1] == 'X' && m[0][2] == ' ') {
        Linha = 0;
        Coluna = 2;
    } else if(m[0][0] == 'X' && m[0][2] == 'X' && m[0][1] == ' ') {
        Linha = 0;
        Coluna = 1;
    } else if(m[0][1] == 'X' && m[0][2] == 'X' && m[0][0] == ' ') {
        Linha = 0;
        Coluna = 0;
    } else if(m[0][0] == 'X' && m[1][0] == 'X' && m[2][0] == ' ') {
        Linha = 2;
        Coluna = 0;
    } else if(m[0][0] == 'X' && m[2][0] == 'X' && m[1][0] == ' ') {
        Linha = 1;
        Coluna = 0;
    } else if(m[0][1] == 'X' && m[1][1] == 'X' && m[2][1] == ' ') {
        Linha = 2;
        Coluna = 1;
    } else if(m[0][1] == 'X' && m[2][1] == 'X' && m[1][1] == ' ') {
        Linha = 1;
        Coluna = 1;
    } else if(m[0][2] == 'X' && m[1][2] == 'X' && m[2][2] == ' ') {
        Linha = 2;
        Coluna = 2;
    } else if(m[0][2] == 'X' && m[2][2] == 'X' && m[1][2] == ' ') {
        Linha = 1;
        Coluna = 2;
    } else if(m[0][0] == 'X' && m[1][1] == 'X' && m[2][2] == ' ') {
        Linha = 2;
        Coluna = 2;
    } else if(m[0][0] == 'X' && m[2][2] == 'X' && m[1][1] == ' ') {
        Linha = 1;
        Coluna = 1;
    }

    else if(m[1][0] == 'X' && m[1][1] == 'X' && m[1][2] == ' ') {
        Linha = 1;
        Coluna = 2;
    } else if(m[1][0] == 'X' && m[1][2] == 'X' && m[1][1] == ' ') {
        Linha = 1;
        Coluna = 1;
    } else if(m[1][1] == 'X' && m[1][2] == 'X' && m[1][0] == ' ') {
        Linha = 1;
        Coluna = 0;
    } else if(m[1][0] == 'X' && m[2][0] == 'X' && m[0][0] == ' ') {
        Linha = 0;
        Coluna = 0;
    } else if(m[1][1] == 'X' && m[2][1] == 'X' && m[0][1] == ' ') {
        Linha = 0;
        Coluna = 1;
    } else if(m[1][2] == 'X' && m[2][2] == 'X' && m[0][2] == ' ') {
        Linha = 0;
        Coluna = 2;
    } else if(m[1][1] == 'X' && m[2][2] == 'X' && m[0][0] == ' ') {
        Linha = 0;
        Coluna = 0;
    } else if(m[1][1] == 'X' && m[0][2] == 'X' && m[2][0] == ' ') {
        Linha = 2;
        Coluna = 0;
    }

    else if(m[2][0] == 'X' && m[2][1] == 'X' && m[2][2] == ' ') {
        Linha = 2;
        Coluna = 2;
    } else if(m[2][0] == 'X' && m[2][2] == 'X' && m[2][1] == ' ') {
        Linha = 2;
        Coluna = 1;
    } else if(m[2][1] == 'X' && m[2][2] == 'X' && m[2][0] == ' ') {
        Linha = 2;
        Coluna = 0;
    } else if(m[2][0] == 'X' && m[1][1] == 'X' && m[0][2] == ' ') {
        Linha = 0;
        Coluna = 2;
    } else if(m[2][0] == 'X' && m[0][2] == 'X' && m[1][1] == ' ') {
        Linha = 1;
        Coluna = 1;
    }

    //Condições aleatórias
    else {
        do {
            Linha = rand()%3;
            Coluna = rand()%3;
        } while(m[Linha][Coluna]!=' ');
    }

    m[Linha][Coluna]='O';
    Sleep(750);
}

void regras() {
    int saida = NULL;
    system("cls");
    printf("\n > Objetivo: Ser o primeiro a fazer uma sequencia de tres simbolos iguais, seja em uma linha, coluna ou diagonal.\n\n");
    printf(" > Um jogador joga com o círculo ( O ) e outro com os xis ( X );\n");
    printf(" > Cada  jogador, na sua vez, coloca a peça numa lacuna que esteja vazia;\n");
    printf(" > Quando um jogador conquista o objetivo, é o vencedor;\n");
    printf(" > Quando há empate costuma-se dizer que o jogo 'deu velha'.\n\n");
    printf(" > Aperte qualquer tecla para sair... ");
    saida = getch();
    if (saida != NULL) {
        system("cls");
        main();
    }
}
void sair () {
    printf("\n  > Espero nos vermos em breve! Volte sempre!\n");
    exit(0);
}

char vencedor(char m[3][3]) {
    int i;

    for(i=0; i<3; i++) {
        if(m[i][0]==m[i][1] && m[i][1] == m[i][2] && m[i][0]!=' ')
            return m[i][0];
        if(m[0][i]==m[1][i] && m[1][i] == m[2][i] && m[0][i]!=' ')
            return m[0][i];
    }

    if(m[0][0]==m[1][1] && m[1][1]== m[2][2] && m[0][0]!=' ')
        return m[0][0];
    if(m[0][2]==m[1][1] && m[1][1]== m[2][0] && m[0][2]!=' ')
        return m[0][2];

    return ' ';
}

void gotoxy(int x, int y) {
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD) {
        x-1,y-1
    });
}

void tela_final(char v, int modo) {

    system("cls");
    int x=1, y=1, dx=1, dy=1, i, saida = NULL;
    while( ! kbhit() == TRUE) {
        gotoxy(x,y);
        switch(v) {
        case 'X':
            if(modo == 1)
                printf("Parabéns, você ganhou!");
            else
                printf("Parabéns Jogador 1, você ganhou!");
            Sleep(100);
            break;
        case 'O':
            if(modo == 1)
                printf("Você Perdeu!");
            else
                printf("Parabéns Jogador 2, você ganhou!");
            Sleep(100);
            break;
        case ' ':
            printf("Velha!");
            Sleep(100);
            break;
        }
        for(i=0; i<40000000; i++); //causa uma pausa
        gotoxy(x,y);
        putchar(' ');
        x += dx;
        y += dy;
        if( x==1 || x==80)
            dx = -dx;
        if( y==1 || y==24)
            dy = -dy;
        system("cls");
    }
    saida = getch();
    if (saida != NULL) {
        system("cls");
        main();
    }
}
