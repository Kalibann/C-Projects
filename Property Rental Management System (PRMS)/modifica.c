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

void altera_cadastro(int tratam_error) {
    system("cls");
       FILE *deleta;
    int escolha;
    char reg[6], nome[30], nome_i[20], reg_i[6], loc_i[35];
    char dirnome[50] = "Locatario/";
    char dirreg[50] = "Regist_Locatar/";
    char dirreg_i[50] = "Regist_Imoveis/";
    char dirnome_i[50] = "Imovel/";
    char dirloc_i[50] = "LocacaoImovel/";

    printf(" ++=========== ALTERAR  CADASTRO ================++\n");
    printf(" ||                                              ||\n");
    printf(" ||    Você deseja alterar o cadastro:           ||\n");
    printf(" ||                                              ||\n");
    printf(" ||  -> 1 - Usando nome do locatário.            ||\n");
    printf(" ||  -> 2 - Usando código de registro.           ||\n");
    printf(" ||                                              ||\n");
    printf(" ||    Ou                                        ||\n");
    printf(" ||                                              ||\n");
    printf(" ||  -> 3 - Voltar ao menu.                      ||\n");
    printf(" ||                                              ||\n");
    printf(" ++==============================================++\n");

    if(tratam_error != 0){
        printf(" ||                                              ||\n");
        printf(" ||     Por favor pressione algo válido!         ||\n");
        printf(" ||                                              ||\n");
        printf(" ++==============================================++\n");
        }

    escolha = getch();
    if(escolha == '1'){
        printf("\n\n  > Digite o nome do locatário: ");
        scanf(" %[^\n]s", &nome);

        strcat(dirnome, nome);
        strcat(dirnome, ".txt");
        deleta = fopen(dirnome, "r");

        fgets(reg, 6, deleta);
        fclose(deleta);
        strcat(dirreg, reg);
        strcat(dirreg, ".txt");

        strcpy(loc_i, nome);
        strcat(loc_i, " ");
        strcat(loc_i, reg);

        strcat(dirloc_i, loc_i);
        strcat(dirloc_i, ".txt");

        deleta = fopen(dirloc_i, "r");
        fgets(reg_i, 6, deleta);
        fclose(deleta);

        strcat(dirreg_i, reg_i);
        strcat(dirreg_i, ".txt");

        deleta = fopen(dirreg_i, "r");
        fgets(nome_i, 20, deleta);
        fclose(deleta);
        strcat(dirnome_i, nome_i);
        strcat(dirnome_i, ".txt");

        remove(dirnome);
        remove(dirreg);
        remove(dirloc_i);
        remove(dirnome_i);
        remove(dirreg_i);

        cadastro_locacao_inicio();

    }

    else if(escolha == '2'){
        printf("\n\n  > Digite o registro do locatário: ");
        scanf(" %s", &reg);

        strcat(dirreg, reg);
            strcat(dirreg, ".txt");
            deleta = fopen(dirreg, "r");

            fgets(nome, 30, deleta);
        fclose(deleta);
        strcat(dirnome, nome);
        strcat(dirnome, ".txt");

        strcpy(loc_i, nome);
    strcat(loc_i, " ");
    strcat(loc_i, reg);

    strcat(dirloc_i, loc_i);
    strcat(dirloc_i, ".txt");

    deleta = fopen(dirloc_i, "r");
    fgets(reg_i, 6, deleta);
        fclose(deleta);

        strcat(dirreg_i, reg_i);
        strcat(dirreg_i, ".txt");

        deleta = fopen(dirreg_i, "r");
        fgets(nome_i, 20, deleta);
        fclose(deleta);
        strcat(dirnome_i, nome_i);
        strcat(dirnome_i, ".txt");

        remove(dirnome);
    remove(dirreg);
    remove(dirloc_i);
    remove(dirnome_i);
    remove(dirreg_i);

    cadastro_locacao_inicio();
    }

    else if(escolha == '3'){menu_principal(0);}
    else altera_cadastro(1);

}
