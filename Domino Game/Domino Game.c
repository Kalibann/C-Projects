/*
 =====================================================================================
 Name         : Simple Domino in C
 Author       : João Pedro Portilho Silva, Lucas Elias de Andrade Cruvinel,
			  Ramon Soares Mendes de Meneses Leite
 E-mail:      : jppsil14@gmail.com; lucrilhasbr@hotmail.com; ramnsores1000@gmail.com
 University   : Universidade Federal de Goiás - Catalão GO
 Objective    : Final work of APC1 / LAB1
 =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <locale.h>

//Structs

struct perfil_jogador
{
    char nomes[4][50];
    int outroai[4]; // Auxiliar para resolver erro
    int arm[200];
};

//Variaveis globais:

char *pecas_jogo[30] =
    {{"Vazio"},{"[0|0]"}, {"[0|1]"}, {"[0|2]"}, {"[0|3]"},
    {"[0|4]"}, {"[0|5]"}, {"[0|6]"}, {"[1|1]"},
    {"[1|2]"}, {"[1|3]"}, {"[1|4]"}, {"[1|5]"},
    {"[1|6]"}, {"[2|2]"}, {"[2|3]"}, {"[2|4]"},
    {"[2|5]"}, {"[2|6]"}, {"[3|3]"}, {"[3|4]"},
    {"[3|5]"}, {"[3|6]"}, {"[4|4]"}, {"[4|5]"},
    {"[4|6]"}, {"[5|5]"}, {"[5|6]"}, {"[6|6]"}, {"Vazio"}};

char *inverte[30] =
    {{"Vazio"},{"[0|0]"}, {"[1|0]"}, {"[2|0]"}, {"[3|0]"},
    {"[4|0]"}, {"[5|0]"}, {"[6|0]"}, {"[1|1]"},
    {"[2|1]"}, {"[3|1]"}, {"[4|1]"}, {"[5|1]"},
    {"[6|1]"}, {"[2|2]"}, {"[3|2]"}, {"[4|2]"},
    {"[5|2]"}, {"[6|2]"}, {"[3|3]"}, {"[4|3]"},
    {"[5|3]"}, {"[6|3]"}, {"[4|4]"}, {"[5|4]"},
    {"[6|4]"}, {"[5|5]"}, {"[6|5]"}, {"[6|6]"}, {"Vazio"}};

int peca_chave = 0, cont1 = 0;
int temp = 1;

//Funcoes:
void menu(); //Função q mostra o menu
void regras(); //Função q mostra as regras
void adeus(); //Função q mostra mensagem final
bool Existe(int valores[], int tam, int valor); //Função auxiliar do GeraAleatorios (nao randomizar a mesma peça)
void GeraAleatorios(int numeros[], int quantNumeros, int Limite); //Função para randomizar pecas
void quatro_jogadores(); // Função para jogar em 4 jogadores


int main() //Função principal
{
    menu();
    return 0;
}

//__________________________________________________________________________________________________________________________//

void menu(){
    int auxiliar = 1;
    int nummenu;
    setlocale(LC_ALL, "Portuguese");
    system("cls");
    system("color 06");
    printf("\n********************************************************************************************************");
    printf("\n*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*");
    printf("\n*@@           @@@@@@@@         @@@@@@@ @@@@@@@@@ @@@@@             @@@@   @@@@@@@@@ @@@@@@         @@@@*");
    printf("\n*@@  @@@@@@@@  @@@@@@  @@@@@@@  @@@@@ @ @@@@@@@ @ @@@@@@@@@   @@@@@@@@@ @@ @@@@@@@@ @@@@@  @@@@@@@  @@@*");
    printf("\n*@@  @@@@@@@@@  @@@@ @@@@@@@@@@@ @@@@ @@ @@@@@ @@ @@@@@@@@@   @@@@@@@@@ @@@ @@@@@@@ @@@@ @@@@@@@@@@@ @@*");
    printf("\n*@@  @@@@@@@@@  @@@@ @@@@@@@@@@@ @@@@ @@@ @@@ @@@ @@@@@@@@@   @@@@@@@@@ @@@@ @@@@@@ @@@@ @@@@@@@@@@@ @@*");
    printf("\n*@@  @@@@@@@@@  @@@@ @@@@@@@@@@@ @@@@ @@@@   @@@@ @@@@@@@@@   @@@@@@@@@ @@@@@ @@@@@ @@@@ @@@@@@@@@@@ @@*");
    printf("\n*@@  @@@@@@@@@  @@@@ @@@@@@@@@@@ @@@@ @@@@@ @@@@@ @@@@@@@@@   @@@@@@@@@ @@@@@@ @@@@ @@@@ @@@@@@@@@@@ @@*");
    printf("\n*@@  @@@@@@@@@  @@@@ @@@@@@@@@@@ @@@@ @@@@@@@@@@@ @@@@@@@@@   @@@@@@@@@ @@@@@@@ @@@ @@@@ @@@@@@@@@@@ @@*");
    printf("\n*@@  @@@@@@@@@  @@@@ @@@@@@@@@@@ @@@@ @@@@@@@@@@@ @@@@@@@@@   @@@@@@@@@ @@@@@@@@ @@ @@@@ @@@@@@@@@@@ @@*");
    printf("\n*@@  @@@@@@@@  @@@@@@  @@@@@@@  @@@@@ @@@@@@@@@@@ @@@@@@@@@   @@@@@@@@@ @@@@@@@@@ @ @@@@@  @@@@@@@  @@@*");
    printf("\n*@@           @@@@@@@@         @@@@@@ @@@@@@@@@@@ @@@@             @@@@ @@@@@@@@@@  @@@@@@         @@@@*");
    printf("\n*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*");
    printf("\n********************************************************************************************************");
    printf("\n*                                                   *                                                  *");
    printf("\n*  Menu:                                            * Desenvolvedores deste Programa:                  *");
    printf("\n*    >Pressione 1 para jogar.                       *  -> João Pedro Portilho                          *");
    printf("\n*    >Pressione 2 para aprender a jogar.            *  -> Lucas A. Cruvinel                            *");
    printf("\n*    >Pressione 3 para fechar o jogo.               *  -> Ramon Soares                                 *");
    printf("\n*                                                   *                                                  *");
    printf("\n********************************************************************************************************");

    while(auxiliar){
        nummenu = getch();
        nummenu = nummenu - 48;
        if(nummenu == 1){quatro_jogadores();}
        else if(nummenu == 2){regras();}
        else if(nummenu == 3){adeus();}
        else printf("\n********************************************************************************************************\n*                                 Por favor pressione uma tecla valida!                                *\n********************************************************************************************************");}
 }

//__________________________________________________________________________________________________________________________//

 void regras(){
    int numreg;
    int auxiliar = 1;
    system("cls");
    setlocale(LC_ALL, "Portuguese");
    system("color FC");
    printf("\n********************************************************************************************************");
    printf("\n*                                                                                                      *");
    printf("\n*                                              COMO JOGAR:                                             *");
    printf("\n*      ->O jogo começa com uma pessoa colocando uma peça na mesa.                                      *");
    printf("\n*      ->O jogador seguinte deve entao jogar outra peça.                                               *");
    printf("\n*      ->Esta segunda peça deve ter um número que seja igual a um dos numeros da peça anterior.        *");
    printf("\n*      ->E assim o jogo se segue.                                                                      *");
    printf("\n*      ->Caso um jogador não tenha uma peça que possa ser usada.                                       *");
    printf("\n*      ->Ele deve passar sua vez para o proximo jogador.                                               *");
    printf("\n*      ->O primeiro jogador a ficar sem nenhuma peça GANHA                                             *");
    printf("\n*      ->E todos os outros são PERDEDORES                                                              *");
    printf("\n*                                                                                                      *");
    printf("\n********************************************************************************************************");
    printf("\n*                                                                                                      *");
    printf("\n*                                  Pressione 1 para voltar ao menu.                                    *");
    printf("\n*                                  Pressione 2 para fechar o jogo.                                     *");
    printf("\n*                                                                                                      *");
    printf("\n********************************************************************************************************");
    while(auxiliar){
        numreg = getch();
        numreg = numreg - 48;
        if(numreg == 1){menu();}
        else if(numreg == 2){adeus();}
        else printf("\n********************************************************************************************************\n*                                 Por favor pressione uma tecla valida!                                *\n********************************************************************************************************");
        }
}

//__________________________________________________________________________________________________________________________//

void adeus(){
    system("cls");
    system("color FD");
    printf("\n********************************************************************************************************");
    printf("\n********************************************************************************************************");
    printf("\n**                                                                                                    **");
    printf("\n**         Segundo Lavoisier, na natureza nada se cria, nada se perde, tudo se transforma.            **");
    printf("\n**         E agora mais do que nunca isso se torna verdade.                                           **");
    printf("\n**         Pois a felicidade de poder te servir agora se torna saudade de saber que você vai embora.  **");
    printf("\n**         Obrigado por tudo e volte sempre.                                                          **");
    printf("\n**                                                                                                    **");
    printf("\n********************************************************************************************************");
    printf("\n********************************************************************************************************");
    exit(0);
    }

//__________________________________________________________________________________________________________________________//

bool Existe(int valores[], int tam, int valor){
    for(int i = 0;i < tam; i++){
        if(valores[i]==valor || valor == 0)
            return true;}

    return false;
}

//__________________________________________________________________________________________________________________________//

void GeraAleatorios(int numeros[], int quantNumeros, int Limite){
    srand(time(NULL));
    int v;
    for(int i = 0; i<quantNumeros;i++){
            v = rand() % Limite;
        while(Existe(numeros,i,v))
            v = rand() % Limite;

        numeros[i] = v;
    }
}

//__________________________________________________________________________________________________________________________//

void quatro_jogadores()
{
    //Função para jogar em 4 jogadores

    struct perfil_jogador jogador;
    jogador.arm[0] = 27;

    system("cls");
    *pecas_jogo = malloc(6*sizeof(char));
    int contador, pontuacao, qtd_turnos = 0; //contadores
    int inventario[5][7];
    int aux_inventario[28], aux_peca, aux_66 = 0; //auxiliadores
    int peca_mesa = 1; // variaveis de peças
    int i, j, k=0, terminar_jogo = 0; // utilidades


    bool turno = false, fim_de_jogo = true, aux_x = true;; // booleanos para parada e execução

    char mesa[50][6] = {0};

    for(contador = 1; contador < 5; contador++)
    {
        printf("=======================================================");
        printf("\nSeja muito bem-vindo, Jogador %d! Diga-me seu apelido: \n", contador);
        printf("Meu apelido é -> ");
        scanf("%s", jogador.nomes[contador]);
    }
    system("cls");

    // Sistemas de Turnos

    GeraAleatorios(aux_inventario, 28, 29);//chamada da função para randomizar as peças

    for (i=0;i<5;i++){
         for (j=0;j<7;j++){
                if(i==0)
                    inventario[i][j] = 29;
                else{
                    inventario[i][j] = aux_inventario[k];
                    k++;}
         }
    }

    while(fim_de_jogo == true)
    {
        for(int cont1 = 1; cont1 < 5; cont1++)
        {
//Estrutura inicial

            system("cls");
            printf("                    | Turno do: %s | Nº Turno: %d \n", jogador.nomes[cont1], qtd_turnos+1);
            printf("\n                    Mesa do jogo:\n");
            printf("________________________________________________________________________________________________________________________\n\n");
            printf("%s", mesa[1]);
            printf("%s", mesa[2]);
            printf("%s", mesa[3]);
            printf("%s", mesa[4]);
            printf("%s", mesa[5]);
            printf("%s", mesa[6]);
            printf("%s", mesa[7]);
            printf("%s", mesa[8]);
            printf("%s", mesa[8]);
            printf("%s", mesa[9]);
            printf("%s", mesa[10]);
            printf("%s", mesa[11]);
            printf("%s", mesa[12]);
            printf("%s", mesa[13]);
            printf("%s", mesa[14]);
            printf("%s", mesa[15]);
            printf("%s", mesa[16]);
            printf("%s", mesa[17]);
            printf("%s", mesa[18]);
            printf("%s", mesa[19]);
            printf("%s", mesa[20]);
            printf("%s", mesa[21]);
            printf("%s", mesa[22]);
            printf("%s", mesa[23]);
            printf("%s", mesa[24]);
            printf("%s", mesa[25]);
            printf("%s", mesa[26]);
            printf("%s", mesa[27]);
            printf("%s", mesa[28]);
            //--
            printf("\n________________________________________________________________________________________________________________________\n\n");
            printf("\n                    Meu inventario:\n\n");
            printf("                    {0. %s}, {1. %s}, {2. %s}, {3. %s}, {4. %s}, {5. %s}, {6. %s}", pecas_jogo[inventario[cont1][0]], pecas_jogo[inventario[cont1][1]], pecas_jogo[inventario[cont1][2]], pecas_jogo[inventario[cont1][3]], pecas_jogo[inventario[cont1][4]], pecas_jogo[inventario[cont1][5]], pecas_jogo[inventario[cont1][6]]);
            printf("\n\n                    OBS: Para pular seu turno, digite 7; ");
            printf("\n                    OBS: Para colocar uma peça invertida, digite 8 e em seguida escolha a peça; ");
            printf("\n                    Qual peca deseja colocar?\n                    > ");

            while(aux_x == true){
                printf("\n                    Se saiu com a peca [6|6], digite 1 e coloque-a, se não digite 0: \n                    > ");
                scanf("%d", &aux_66);
                if(aux_66 == 0){
                    cont1++;
                    system("cls");
                    printf("                    | Turno do: %s | N Turno: %d \n", jogador.nomes[cont1], qtd_turnos+1);
                    printf("\n                    Mesa do jogo:\n");
                    printf("________________________________________________________________________________________________________________________\n\n");
                    printf("%s", mesa[1]);
                    printf("%s", mesa[2]);
                    printf("%s", mesa[3]);
                    printf("%s", mesa[4]);
                    printf("%s", mesa[5]);
                    printf("%s", mesa[6]);
                    printf("%s", mesa[7]);
                    printf("%s", mesa[8]);
                    printf("%s", mesa[8]);
                    printf("%s", mesa[9]);
                    printf("%s", mesa[10]);
                    printf("%s", mesa[11]);
                    printf("%s", mesa[12]);
                    printf("%s", mesa[13]);
                    printf("%s", mesa[14]);
                    printf("%s", mesa[15]);
                    printf("%s", mesa[16]);
                    printf("%s", mesa[17]);
                    printf("%s", mesa[18]);
                    printf("%s", mesa[19]);
                    printf("%s", mesa[20]);
                    printf("%s", mesa[21]);
                    printf("%s", mesa[22]);
                    printf("%s", mesa[23]);
                    printf("%s", mesa[24]);
                    printf("%s", mesa[25]);
                    printf("%s", mesa[26]);
                    printf("%s", mesa[27]);
                    printf("%s", mesa[28]);
                    //--
                    printf("\n________________________________________________________________________________________________________________________\n\n");
                    printf("\n                    Meu inventario:\n\n");
                    printf("                    {0. %s}, {1. %s}, {2. %s}, {3. %s}, {4. %s}, {5. %s}, {6. %s}", pecas_jogo[inventario[cont1][0]], pecas_jogo[inventario[cont1][1]], pecas_jogo[inventario[cont1][2]], pecas_jogo[inventario[cont1][3]], pecas_jogo[inventario[cont1][4]], pecas_jogo[inventario[cont1][5]], pecas_jogo[inventario[cont1][6]]);
                    printf("\n\n                    OBS: Para pular seu turno, digite 7; ");
                    printf("\n                    OBS: Para colocar uma peca invertida, digite 8 e em seguida escolha a peca; ");
                    printf("\n                    Qual peca deseja colocar?\n                    > ");
                }
                else
                    if(aux_66 == 1){
                        aux_x = false;
                        printf("                    > ");}
            }

//Estrutura de leitura das escolhas do jogador e seus subgrupos com condições

            scanf("%d", &peca_chave);

            //Condição de existência

            while(inventario[cont1][peca_chave] == 29 || peca_chave >= 9 || peca_chave < 0)
            {
              printf("\n                    Slot inválido! No slot escolhido, nao há peça alguma. Por favor, insira outro número. \n                    > ");
              scanf("%d", &peca_chave);
            }
            if (peca_mesa == 1){
                while(inventario[cont1][peca_chave] != 28){
                    printf("                    Jogue a peça [6|6]! > ");
                    scanf("%d", &peca_chave);
                }
            }
//___________________________________________________________________________________________________

    //Condição para inverter a peça

        if(peca_chave == 8){
                printf("\n                    Escolha uma peca para inverter:  ");
                scanf("%d", &aux_peca);
                while(inventario[cont1][aux_peca] == 29 || peca_chave >= 9 || peca_chave < 0){
                    printf("\n                    Slot inválido! No slot escolhido, nao há peça alguma. Por favor, insira outro número. \n                    > ");
                    scanf("%d", &aux_peca);}
                strcpy(mesa[peca_mesa], inverte[inventario[cont1][aux_peca]]);
                jogador.arm[temp] = inventario[cont1][aux_peca];
                temp++;
                inventario[cont1][aux_peca] = inventario[0][0];
        }

    //Condição para passar a vez

        else
            if(peca_chave == 7){ cont1++;
                turno = true;}

    //Condição de possibilidade de escolha de uma determinada peça


        else
            if(peca_chave >= 0 && peca_chave < 9){

            if(jogador.arm[temp-1] == 1){
                while(inventario[cont1][peca_chave] != 2 && inventario[cont1][peca_chave] != 3 &&
                      inventario[cont1][peca_chave] != 4 && inventario[cont1][peca_chave] != 5 &&
                      inventario[cont1][peca_chave] != 6 && inventario[cont1][peca_chave] != 7){
                        printf("\n                    Aqui não companheiro, vai roubar pra lá! Digite outra peça: > ");
                        scanf("%d", &peca_chave);
                            if(peca_chave == 7 || peca_chave ==8)
                                break;}}
            if(jogador.arm[temp-1] == 2){
                while(inventario[cont1][peca_chave] != 1 && inventario[cont1][peca_chave] != 3 &&
                      inventario[cont1][peca_chave] != 4 && inventario[cont1][peca_chave] != 5 &&
                      inventario[cont1][peca_chave] != 6 && inventario[cont1][peca_chave] != 7 &&
					  inventario[cont1][peca_chave] != 8 && inventario[cont1][peca_chave] != 9 &&
                      inventario[cont1][peca_chave] != 10 && inventario[cont1][peca_chave] != 11 &&
                      inventario[cont1][peca_chave] != 12 && inventario[cont1][peca_chave] != 13){
                        printf("\n                    Aqui não companheiro, vai roubar pra lá! Digite outra peça: > ");
                        scanf("%d", &peca_chave);
                            if(peca_chave == 7 || peca_chave ==8)
                                break;}}
            if(jogador.arm[temp-1] == 3){
                while(inventario[cont1][peca_chave] != 1 && inventario[cont1][peca_chave] != 2 &&
                      inventario[cont1][peca_chave] != 4 && inventario[cont1][peca_chave] != 5 &&
                      inventario[cont1][peca_chave] != 6 && inventario[cont1][peca_chave] != 7 &&
					  inventario[cont1][peca_chave] != 9 && inventario[cont1][peca_chave] != 14 &&
                      inventario[cont1][peca_chave] != 15 && inventario[cont1][peca_chave] != 16 &&
                      inventario[cont1][peca_chave] != 17 && inventario[cont1][peca_chave] != 18){
                        printf("\n                    Aqui não companheiro, vai roubar pra lá! Digite outra peça: > ");
                        scanf("%d", &peca_chave);
                            if(peca_chave == 7 || peca_chave ==8)
                                break;}}
            if(jogador.arm[temp-1] == 4){
                while(inventario[cont1][peca_chave] != 1 && inventario[cont1][peca_chave] != 2 &&
                      inventario[cont1][peca_chave] != 3 && inventario[cont1][peca_chave] != 5 &&
                      inventario[cont1][peca_chave] != 6 && inventario[cont1][peca_chave] != 7 &&
					  inventario[cont1][peca_chave] != 10 && inventario[cont1][peca_chave] != 15 &&
                      inventario[cont1][peca_chave] != 19 && inventario[cont1][peca_chave] != 20 &&
                      inventario[cont1][peca_chave] != 21 && inventario[cont1][peca_chave] != 22){
                        printf("\n                    Aqui não companheiro, vai roubar pra lá! Digite outra peça: > ");
                        scanf("%d", &peca_chave);
                            if(peca_chave == 7 || peca_chave ==8)
                                break;}}
            if(jogador.arm[temp-1] == 5){
                while(inventario[cont1][peca_chave] != 1 && inventario[cont1][peca_chave] != 2 &&
                      inventario[cont1][peca_chave] != 3 && inventario[cont1][peca_chave] != 4 &&
                      inventario[cont1][peca_chave] != 6 && inventario[cont1][peca_chave] != 7 &&
					  inventario[cont1][peca_chave] != 11 && inventario[cont1][peca_chave] != 16 &&
                      inventario[cont1][peca_chave] != 20 && inventario[cont1][peca_chave] != 23 &&
                      inventario[cont1][peca_chave] != 24 && inventario[cont1][peca_chave] != 25){
                        printf("\n                    Aqui não companheiro, vai roubar pra lá! Digite outra peça: > ");
                        scanf("%d", &peca_chave);
                            if(peca_chave == 7 || peca_chave ==8)
                                break;}}
            if(jogador.arm[temp-1] == 6){
                while(inventario[cont1][peca_chave] != 1 && inventario[cont1][peca_chave] != 2 &&
                      inventario[cont1][peca_chave] != 3 && inventario[cont1][peca_chave] != 4 &&
                      inventario[cont1][peca_chave] != 5 && inventario[cont1][peca_chave] != 7 &&
					  inventario[cont1][peca_chave] != 12 && inventario[cont1][peca_chave] != 17 &&
                      inventario[cont1][peca_chave] != 21 && inventario[cont1][peca_chave] != 24 &&
                      inventario[cont1][peca_chave] != 26 && inventario[cont1][peca_chave] != 27){
                        printf("\n                    Aqui não companheiro, vai roubar pra lá! Digite outra peça: > ");
                        scanf("%d", &peca_chave);
                            if(peca_chave == 7 || peca_chave ==8)
                                break;}}
			if(jogador.arm[temp-1] == 7){
                while(inventario[cont1][peca_chave] != 1 && inventario[cont1][peca_chave] != 2 &&
                      inventario[cont1][peca_chave] != 3 && inventario[cont1][peca_chave] != 4 &&
                      inventario[cont1][peca_chave] != 5 && inventario[cont1][peca_chave] != 6 &&
					  inventario[cont1][peca_chave] != 13 && inventario[cont1][peca_chave] != 18 &&
                      inventario[cont1][peca_chave] != 22 && inventario[cont1][peca_chave] != 25 &&
                      inventario[cont1][peca_chave] != 27 && inventario[cont1][peca_chave] != 28){
                        printf("\n                    Aqui não companheiro, vai roubar pra lá! Digite outra peça: > ");
                        scanf("%d", &peca_chave);
                            if(peca_chave == 7 || peca_chave ==8)
                                break;}}
			if(jogador.arm[temp-1] == 8){
                while(inventario[cont1][peca_chave] != 2 && inventario[cont1][peca_chave] != 9 &&
                      inventario[cont1][peca_chave] != 10 && inventario[cont1][peca_chave] != 11 &&
                      inventario[cont1][peca_chave] != 12 && inventario[cont1][peca_chave] != 13){
                        printf("\n                    Aqui não companheiro, vai roubar pra lá! Digite outra peça: > ");
                        scanf("%d", &peca_chave);
                            if(peca_chave == 7 || peca_chave ==8)
                                break;}}
			if(jogador.arm[temp-1] == 9){
                while(inventario[cont1][peca_chave] != 2 && inventario[cont1][peca_chave] != 3 &&
                      inventario[cont1][peca_chave] != 8 && inventario[cont1][peca_chave] != 10 &&
                      inventario[cont1][peca_chave] != 11 && inventario[cont1][peca_chave] != 12 &&
					  inventario[cont1][peca_chave] != 13 && inventario[cont1][peca_chave] != 14 &&
                      inventario[cont1][peca_chave] != 15 && inventario[cont1][peca_chave] != 16 &&
                      inventario[cont1][peca_chave] != 17 && inventario[cont1][peca_chave] != 18){
                        printf("\n                    Aqui não companheiro, vai roubar pra lá! Digite outra peça: > ");
                        scanf("%d", &peca_chave);
                            if(peca_chave == 7 || peca_chave ==8)
                                break;}}
			if(jogador.arm[temp-1] == 10){
                while(inventario[cont1][peca_chave] != 2 && inventario[cont1][peca_chave] != 4 &&
                      inventario[cont1][peca_chave] != 8 && inventario[cont1][peca_chave] != 9 &&
                      inventario[cont1][peca_chave] != 11 && inventario[cont1][peca_chave] != 12 &&
					  inventario[cont1][peca_chave] != 13 && inventario[cont1][peca_chave] != 15 &&
                      inventario[cont1][peca_chave] != 19 && inventario[cont1][peca_chave] != 20 &&
                      inventario[cont1][peca_chave] != 21 && inventario[cont1][peca_chave] != 22){
                        printf("\n                    Aqui não companheiro, vai roubar pra lá! Digite outra peça: > ");
                        scanf("%d", &peca_chave);
                            if(peca_chave == 7 || peca_chave ==8)
                                break;}}
			if(jogador.arm[temp-1] == 11){
                while(inventario[cont1][peca_chave] != 2 && inventario[cont1][peca_chave] != 5 &&
                      inventario[cont1][peca_chave] != 8 && inventario[cont1][peca_chave] != 9 &&
                      inventario[cont1][peca_chave] != 10 && inventario[cont1][peca_chave] != 12 &&
					  inventario[cont1][peca_chave] != 13 && inventario[cont1][peca_chave] != 16 &&
                      inventario[cont1][peca_chave] != 20 && inventario[cont1][peca_chave] != 23 &&
                      inventario[cont1][peca_chave] != 24 && inventario[cont1][peca_chave] != 25){
                        printf("\n                    Aqui não companheiro, vai roubar pra lá! Digite outra peça: > ");
                        scanf("%d", &peca_chave);
                            if(peca_chave == 7 || peca_chave ==8)
                                break;}}
			if(jogador.arm[temp-1] == 12){
                while(inventario[cont1][peca_chave] != 2 && inventario[cont1][peca_chave] != 6 &&
                      inventario[cont1][peca_chave] != 8 && inventario[cont1][peca_chave] != 9 &&
                      inventario[cont1][peca_chave] != 10 && inventario[cont1][peca_chave] != 11 &&
					  inventario[cont1][peca_chave] != 13 && inventario[cont1][peca_chave] != 17 &&
                      inventario[cont1][peca_chave] != 21 && inventario[cont1][peca_chave] != 24 &&
                      inventario[cont1][peca_chave] != 26 && inventario[cont1][peca_chave] != 27){
                        printf("\n                    Aqui não companheiro, vai roubar pra lá! Digite outra peça: > ");
                        scanf("%d", &peca_chave);
                            if(peca_chave == 7 || peca_chave ==8)
                                break;}}
			if(jogador.arm[temp-1] == 13){
                while(inventario[cont1][peca_chave] != 2 && inventario[cont1][peca_chave] != 7 &&
                      inventario[cont1][peca_chave] != 8 && inventario[cont1][peca_chave] != 9 &&
                      inventario[cont1][peca_chave] != 10 && inventario[cont1][peca_chave] != 11 &&
					  inventario[cont1][peca_chave] != 12 && inventario[cont1][peca_chave] != 18 &&
                      inventario[cont1][peca_chave] != 22 && inventario[cont1][peca_chave] != 25 &&
                      inventario[cont1][peca_chave] != 27 && inventario[cont1][peca_chave] != 28){
                        printf("\n                    Aqui não companheiro, vai roubar pra lá! Digite outra peça: > ");
                        scanf("%d", &peca_chave);
                            if(peca_chave == 7 || peca_chave ==8)
                                break;}}
			if(jogador.arm[temp-1] == 14){
                while(inventario[cont1][peca_chave] != 3 && inventario[cont1][peca_chave] != 9 &&
                      inventario[cont1][peca_chave] != 15 && inventario[cont1][peca_chave] != 16 &&
                      inventario[cont1][peca_chave] != 17 && inventario[cont1][peca_chave] != 18){
                        printf("\n                    Aqui não companheiro, vai roubar pra lá! Digite outra peça: > ");
                        scanf("%d", &peca_chave);
                            if(peca_chave == 7 || peca_chave ==8)
                                break;}}
			if(jogador.arm[temp-1] == 15){
                while(inventario[cont1][peca_chave] != 3 && inventario[cont1][peca_chave] != 4 &&
                      inventario[cont1][peca_chave] != 9 && inventario[cont1][peca_chave] != 10 &&
                      inventario[cont1][peca_chave] != 14 && inventario[cont1][peca_chave] != 16 &&
					  inventario[cont1][peca_chave] != 17 && inventario[cont1][peca_chave] != 18 &&
                      inventario[cont1][peca_chave] != 19 && inventario[cont1][peca_chave] != 20 &&
                      inventario[cont1][peca_chave] != 21 && inventario[cont1][peca_chave] != 22){
                        printf("\n                    Aqui não companheiro, vai roubar pra lá! Digite outra peça: > ");
                        scanf("%d", &peca_chave);
                            if(peca_chave == 7 || peca_chave ==8)
                                break;}}
			if(jogador.arm[temp-1] == 16){
                while(inventario[cont1][peca_chave] != 3 && inventario[cont1][peca_chave] != 5 &&
                      inventario[cont1][peca_chave] != 9 && inventario[cont1][peca_chave] != 11 &&
                      inventario[cont1][peca_chave] != 14 && inventario[cont1][peca_chave] != 15 &&
					  inventario[cont1][peca_chave] != 17 && inventario[cont1][peca_chave] != 18 &&
                      inventario[cont1][peca_chave] != 20 && inventario[cont1][peca_chave] != 23 &&
                      inventario[cont1][peca_chave] != 24 && inventario[cont1][peca_chave] != 25){
                        printf("\n                    Aqui não companheiro, vai roubar pra lá! Digite outra peça: > ");
                        scanf("%d", &peca_chave);
                            if(peca_chave == 7 || peca_chave ==8)
                                break;}}
			if(jogador.arm[temp-1] == 17){
                while(inventario[cont1][peca_chave] != 3 && inventario[cont1][peca_chave] != 6 &&
                      inventario[cont1][peca_chave] != 9 && inventario[cont1][peca_chave] != 12 &&
                      inventario[cont1][peca_chave] != 14 && inventario[cont1][peca_chave] != 15 &&
					  inventario[cont1][peca_chave] != 16 && inventario[cont1][peca_chave] != 18 &&
                      inventario[cont1][peca_chave] != 21 && inventario[cont1][peca_chave] != 24 &&
                      inventario[cont1][peca_chave] != 26 && inventario[cont1][peca_chave] != 27){
                        printf("\n                    Aqui não companheiro, vai roubar pra lá! Digite outra peça: > ");
                        scanf("%d", &peca_chave);
                            if(peca_chave == 7 || peca_chave ==8)
                                break;}}
			if(jogador.arm[temp-1] == 18){
                while(inventario[cont1][peca_chave] != 3 && inventario[cont1][peca_chave] != 7 &&
                      inventario[cont1][peca_chave] != 9 && inventario[cont1][peca_chave] != 26 &&
                      inventario[cont1][peca_chave] != 13 && inventario[cont1][peca_chave] != 14 &&
					  inventario[cont1][peca_chave] != 15 && inventario[cont1][peca_chave] != 16 &&
                      inventario[cont1][peca_chave] != 17 && inventario[cont1][peca_chave] != 22 &&
                      inventario[cont1][peca_chave] != 25 && inventario[cont1][peca_chave] != 27){
                        printf("\n                    Aqui não companheiro, vai roubar pra lá! Digite outra peça: > ");
                        scanf("%d", &peca_chave);
                            if(peca_chave == 7 || peca_chave ==8)
                                break;}}
			if(jogador.arm[temp-1] == 19){
                while(inventario[cont1][peca_chave] != 4 && inventario[cont1][peca_chave] != 10 &&
                      inventario[cont1][peca_chave] != 15 && inventario[cont1][peca_chave] != 20 &&
                      inventario[cont1][peca_chave] != 21 && inventario[cont1][peca_chave] != 22){
                        printf("\n                    Aqui não companheiro, vai roubar pra lá! Digite outra peça: > ");
                        scanf("%d", &peca_chave);
                            if(peca_chave == 7 || peca_chave ==8)
                                break;}}
			if(jogador.arm[temp-1] == 20){
                while(inventario[cont1][peca_chave] != 4 && inventario[cont1][peca_chave] != 5 &&
                      inventario[cont1][peca_chave] != 10 && inventario[cont1][peca_chave] != 11 &&
                      inventario[cont1][peca_chave] != 15 && inventario[cont1][peca_chave] != 16 &&
					  inventario[cont1][peca_chave] != 19 && inventario[cont1][peca_chave] != 21 &&
                      inventario[cont1][peca_chave] != 22 && inventario[cont1][peca_chave] != 23 &&
                      inventario[cont1][peca_chave] != 24 && inventario[cont1][peca_chave] != 25){
                        printf("\n                    Aqui não companheiro, vai roubar pra lá! Digite outra peça: > ");
                        scanf("%d", &peca_chave);
                            if(peca_chave == 7 || peca_chave ==8)
                                break;}}
			if(jogador.arm[temp-1] == 21){
                while(inventario[cont1][peca_chave] != 4 && inventario[cont1][peca_chave] != 6 &&
                      inventario[cont1][peca_chave] != 10 && inventario[cont1][peca_chave] != 12 &&
                      inventario[cont1][peca_chave] != 15 && inventario[cont1][peca_chave] != 17 &&
					  inventario[cont1][peca_chave] != 19 && inventario[cont1][peca_chave] != 20 &&
                      inventario[cont1][peca_chave] != 22 && inventario[cont1][peca_chave] != 24 &&
                      inventario[cont1][peca_chave] != 26 && inventario[cont1][peca_chave] != 27){
                        printf("\n                    Aqui não companheiro, vai roubar pra lá! Digite outra peça: > ");
                        scanf("%d", &peca_chave);
                            if(peca_chave == 7 || peca_chave ==8)
                                break;}}
			if(jogador.arm[temp-1] == 22){
                while(inventario[cont1][peca_chave] != 4 && inventario[cont1][peca_chave] != 7 &&
                      inventario[cont1][peca_chave] != 10 && inventario[cont1][peca_chave] != 13 &&
                      inventario[cont1][peca_chave] != 15 && inventario[cont1][peca_chave] != 18 &&
					  inventario[cont1][peca_chave] != 19 && inventario[cont1][peca_chave] != 20 &&
                      inventario[cont1][peca_chave] != 21 && inventario[cont1][peca_chave] != 25 &&
                      inventario[cont1][peca_chave] != 27 && inventario[cont1][peca_chave] != 28){
                        printf("\n                    Aqui não companheiro, vai roubar pra lá! Digite outra peça: > ");
                        scanf("%d", &peca_chave);
                            if(peca_chave == 7 || peca_chave ==8)
                                break;}}
			if(jogador.arm[temp-1] == 23){
                while(inventario[cont1][peca_chave] != 5 && inventario[cont1][peca_chave] != 11 &&
                      inventario[cont1][peca_chave] != 16 && inventario[cont1][peca_chave] != 20 &&
                      inventario[cont1][peca_chave] != 24 && inventario[cont1][peca_chave] != 25){
                        printf("\n                    Aqui não companheiro, vai roubar pra lá! Digite outra peça: > ");
                        scanf("%d", &peca_chave);
                            if(peca_chave == 7 || peca_chave ==8)
                                break;}}
			if(jogador.arm[temp-1] == 24){
                while(inventario[cont1][peca_chave] != 5 && inventario[cont1][peca_chave] != 6 &&
                      inventario[cont1][peca_chave] != 11 && inventario[cont1][peca_chave] != 12 &&
                      inventario[cont1][peca_chave] != 16 && inventario[cont1][peca_chave] != 17 &&
					  inventario[cont1][peca_chave] != 21 && inventario[cont1][peca_chave] != 23 &&
                      inventario[cont1][peca_chave] != 25 && inventario[cont1][peca_chave] != 26 &&
                      inventario[cont1][peca_chave] != 27 && inventario[cont1][peca_chave] != 20){
                        printf("\n                    Aqui não companheiro, vai roubar pra lá! Digite outra peça: > ");
                        scanf("%d", &peca_chave);
                            if(peca_chave == 7 || peca_chave ==8)
                                break;}}
			if(jogador.arm[temp-1] == 25){
                while(inventario[cont1][peca_chave] != 5 && inventario[cont1][peca_chave] != 7 &&
                      inventario[cont1][peca_chave] != 11 && inventario[cont1][peca_chave] != 13 &&
                      inventario[cont1][peca_chave] != 16 && inventario[cont1][peca_chave] != 18 &&
					  inventario[cont1][peca_chave] != 20 && inventario[cont1][peca_chave] != 22 &&
                      inventario[cont1][peca_chave] != 23 && inventario[cont1][peca_chave] != 24 &&
                      inventario[cont1][peca_chave] != 27 && inventario[cont1][peca_chave] != 28){
                        printf("\n                    Aqui não companheiro, vai roubar pra lá! Digite outra peça: > ");
                        scanf("%d", &peca_chave);
                            if(peca_chave == 7 || peca_chave ==8)
                                break;}}
			if(jogador.arm[temp-1] == 26){
                while(inventario[cont1][peca_chave] != 6 && inventario[cont1][peca_chave] != 12 &&
                      inventario[cont1][peca_chave] != 17 && inventario[cont1][peca_chave] != 21 &&
                      inventario[cont1][peca_chave] != 24 && inventario[cont1][peca_chave] != 27){
                        printf("\n                    Aqui não companheiro, vai roubar pra lá! Digite outra peça: > ");
                        scanf("%d", &peca_chave);
                            if(peca_chave == 7 || peca_chave ==8)
                                break;}}
			if(jogador.arm[temp-1] == 27){
                while(inventario[cont1][peca_chave] != 6 && inventario[cont1][peca_chave] != 7 &&
                      inventario[cont1][peca_chave] != 12 && inventario[cont1][peca_chave] != 13 &&
                      inventario[cont1][peca_chave] != 17 && inventario[cont1][peca_chave] != 18 &&
					  inventario[cont1][peca_chave] != 21 && inventario[cont1][peca_chave] != 22 &&
                      inventario[cont1][peca_chave] != 24 && inventario[cont1][peca_chave] != 25 &&
                      inventario[cont1][peca_chave] != 26 && inventario[cont1][peca_chave] != 28){
                        printf("\n                    Aqui não companheiro, vai roubar pra lá! Digite outra peça: > ");
                        scanf("%d", &peca_chave);
                            if(peca_chave == 7 || peca_chave ==8)
                                break;}}
			if(jogador.arm[temp-1] == 28){
                while(inventario[cont1][peca_chave] != 6 && inventario[cont1][peca_chave] != 13 &&
                      inventario[cont1][peca_chave] != 18 && inventario[cont1][peca_chave] != 22 &&
                      inventario[cont1][peca_chave] != 25 && inventario[cont1][peca_chave] != 27){
                        printf("\n                    Aqui não companheiro, vai roubar pra lá! Digite outra peça: > ");
                        scanf("%d", &peca_chave);
                            if(peca_chave == 7 || peca_chave ==8)
                                break;}}


                if(peca_chave == 8){
                    printf("\n                    Escolha uma peca para inverter:  ");
                    scanf("%d", &aux_peca);
                    while(inventario[cont1][aux_peca] == 29 || peca_chave > 8 || peca_chave < 0){
                        printf("\n                    Slot inválido! No slot escolhido, nao há peça alguma. Por favor, insira outro número. \n                    > ");
                        scanf("%d", &aux_peca);}
                    strcpy(mesa[peca_mesa], inverte[inventario[cont1][peca_chave]]);
                    jogador.arm[temp] = inventario[cont1][peca_chave];
                    temp++;
                    inventario[cont1][peca_chave] = inventario[0][0];
                }

                else
                    if(peca_chave == 7){ cont1++;
                    turno = true;}

                else{
                    strcpy(mesa[peca_mesa], pecas_jogo[inventario[cont1][peca_chave]]);
                    jogador.arm[temp] = inventario[cont1][peca_chave];
                    temp++;
                    inventario[cont1][peca_chave] = inventario[0][0];
                    }
        }

//___________________________________________________________________________________________________


            if(turno == false){
                peca_mesa++; }//Mudar posição da mesa

            //Mudar turno se o jogador passar a vez (auxiliar)

            if (turno == true){
                cont1--;
                turno = false;}

//Estrutura para terminar o jogo se o jogador conseguir colocar todas as peças na mesa

            for(i=0;i<7;i++){
                if(inventario[cont1][i] == 29){
                    terminar_jogo++;}
            }

            if(terminar_jogo == 7){
                fim_de_jogo = false;
                parabains(jogador.nomes[cont1]);}
            else{
                terminar_jogo = 0;}

        }

        qtd_turnos++; //Passar de turno
    }
}
//__________________________________________________________________________________________________________________________//

void parabains(char pessoa[]){
    int numreg;
    int auxiliar = 1;
    system("cls");
    setlocale(LC_ALL, "Portuguese");
    system("color B1");
    printf("\n********************************************************************************************************");
    printf("\n*                                                                                                      *");
    printf("\n*                                              PARABAINS                                               *");
    printf("\n*                                            VOCÊ GANHOU!!!!\n                                           *");
    printf("\n*      \"Não acho que quem ganhar ou quem perder, nem quem ganhar nem perder,                           *");
    printf("\n*       vai ganhar ou perder. Vai todo mundo perder.\"                       -Dilma Rousseff            *");
    printf("\n*                                                                                                      *");
    printf("\n*      Dominó pode parecer um jogo de sorte,                                                           *");
    printf("\n*      Mas é um jogo que apenas o mais inteligente ganha,                                              *");
    printf("\n*      E por meio dessa conquista, você se provou;                                                     *");
    printf("\n*      Você É o mais INTELIGENTE e o mais PIK@ CARALH$.                                                *");
    printf("\n*                                                                                                      *");
    printf("\n********************************************************************************************************");
    printf("\n                   Jogador Vencedor: %s", pessoa);
    printf("\n********************************************************************************************************");
    printf("\n*                                                                                                      *");
    printf("\n*                                  Pressione 1 para voltar ao menu.                                    *");
    printf("\n*                                  Pressione 2 para fechar o jogo.                                     *");
    printf("\n*                                                                                                      *");
    printf("\n********************************************************************************************************");
    while(auxiliar){
        numreg = getch();
        numreg = numreg - 48;
        if(numreg == 1){menu();}
        else if(numreg == 2){adeus();}
        else printf("\n********************************************************************************************************\n*                                 Por favor pressione uma tecla valida!                                *\n********************************************************************************************************");
        }
}
//__________________________________________________________________________________________________________________________//
