//Bibliotecas utilizadas:

#include <dirent.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "structs.h"

void menu_principal(int tratam_error) {
    char escolha = NULL;
    system("cls"); // Limpa a tela do terminal, funciona apenas em windows; será usado bastante durante o programa.



    printf(" ++================== MENU ======================++\n");
    printf(" ||                                              ||\n");
    printf(" || -> Pressione 1 para Cadastrar Locação        ||\n");
    printf(" || -> Pressione 2 para Buscar Locação           ||\n");
    printf(" || -> Pressione 3 para Ver status de Pagamento  ||\n");
    printf(" || -> Pressione 4 para Alterar Cadastro         ||\n");
    printf(" || -> Pressione 5 para Excluir Cadastro         ||\n");
    printf(" || -> Pressione 6 para Sair do Sistema          ||\n");
    printf(" ||                                              ||\n");
    printf(" ++==============================================++\n");

    if(tratam_error != 0){
        printf(" ||                                              ||\n");
        printf(" ||     Por favor pressione algo válido!         ||\n");
        printf(" ||                                              ||\n");
        printf(" ++==============================================++\n");
        }

    escolha = getch();

    if           (escolha == '1'){ cadastro_locacao_inicio();}
    else if (escolha == '2'){ mostra_locacao();}
    else if (escolha == '3'){ relatorio_pagamentos(0);}
    else if (escolha == '4'){ altera_cadastro(0);}
    else if (escolha == '5'){ exclui_cadastro();}
    else if (escolha == '6'){ sair();}
    else menu_principal(1);
};

void sair() {
    system("cls");
    printf("  > Encerrando o programa");
    Sleep(500); printf("."); Sleep(500); printf("."); Sleep(500); printf(".");

    system("cls");
    printf(" \n++===========================================++\n");
    printf(" ||                                           ||\n");
    printf(" ||             FIM DO PROGRAMA               ||\n");
    printf(" ||                                           ||\n");
    printf(" ++===========================================++\n");

    exit(0);
};
