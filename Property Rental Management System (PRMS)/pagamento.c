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

void relatorio_pagamentos(int tratam_error) {
    system("cls");
    char escolha = NULL;
    printf(" ++========= RELATORIO DE PAGAMENTO =============++\n");
    printf(" ||                                              ||\n");
    printf(" ||  -> Pressione 1 para ver o status de         ||\n");
    printf(" ||      pagamento do imovel via nome.           ||\n");
    printf(" ||                                              ||\n");
    printf(" ||  -> Pressione 2 para ver o status de         ||\n");
    printf(" ||      pagamento do imovel via registro.       ||\n");
    printf(" ||                                              ||\n");
    printf(" ||  -> Pressione 3 para voltar ao menu.         ||\n");
    printf(" ||                                              ||\n");
    printf(" ++==============================================++\n");

    if(tratam_error != 0){
        printf(" ||                                              ||\n");
        printf(" ||     Por favor pressione algo válido!         ||\n");
        printf(" ||                                              ||\n");
        printf(" ++==============================================++\n");
        }

    escolha = getch();
    if          (escolha == '1'){ status_via_nome();}
    else if(escolha == '2'){ status_via_registro();}
    else if(escolha == '3'){ menu_principal(0);}
    else  relatorio_pagamentos(1);
}

void status_via_nome(){
    FILE * cam;
    char cam_imv[30] = {"Imovel/"};
    char nome[20];
    char pago;

        printf("\n\n   > Insira o nome do imóvel : ");
            scanf(" %[^\n]s", nome);
    strcat(cam_imv, nome);
    strcat(cam_imv, ".txt");

    cam = fopen(cam_imv, "r");
        fseek(cam, -1, SEEK_END);
        fscanf(cam, "%c", &pago);
    fclose(cam);

    if(pago == 'S'){printf("\n  > O Imóvel já esta quitado.\n\n");}
    if(pago == 'N'){printf("\n  > O Imóvel não esta quitado.\n\n");}

    system("pause");
    menu_principal(0);
}

void status_via_registro(){
    FILE * cam;
    char reg[6];
    char reg_imv[24] = {"Regist_Imoveis/"};
    char cam_imv[30] = {"Imovel/"};
    char nome[20];
    char pago;

    printf("\n\n   > Insira o código de registro do imóvel : ");
            scanf(" %s", &reg);
    strcat(reg_imv, reg);
    strcat(reg_imv, ".txt");

    cam = fopen(reg_imv, "r");
    fscanf(cam, "%[^\n]s", &nome);
    fclose(cam);

    strcat(cam_imv, nome);
    strcat(cam_imv, ".txt");

    cam = fopen(cam_imv, "r");
        fseek(cam, -1, SEEK_END);
        fscanf(cam, "%c", &pago);
    fclose(cam);

    if(pago == 'S'){printf("\n  > O Imóvel já esta quitado.\n\n");}
    if(pago == 'N'){printf("\n  > O Imóvel não esta quitado.\n\n");}

    system("pause");
    menu_principal(0);
}
