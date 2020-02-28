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


void cria_codg_reg_imv(char *codg, char nome[]){
    srand(time(NULL));
    FILE *imv;
    char reg_imv[24] = {"Regist_Imoveis/"};
    int i, aux;

    for(i=0;i<6;i++){ codg[i] = NULL;}
    for(i=0;i<5;i++){
        aux = rand()%58;
        if(aux>=0 && aux<=10){ aux += 47;}
        if(aux>10 && aux<=20){ aux += 37;}
        if(aux>20 && aux<=30){ aux += 27;}
        if(aux>30 && aux<=40){ aux += 17;}
        if(aux>40 && aux<=50){ aux += 7;}
        if(aux>=47 && aux<= 57){ codg[i] = aux;}
    }

    strcat(reg_imv, codg);
    strcat(reg_imv, ".txt");

    imv = fopen(reg_imv, "r");
    if(imv == NULL) {
        imv = fopen(reg_imv, "w");
        if(imv == NULL){printf("\n  >  >  Erro ao tentar executar o cadastro!  <  <\n  >  > Por favor reinicie o programa!  <  <\n"); Sleep(500); sair();}
        fprintf(imv, "%s\n", nome);
        fclose(imv);
        }
    else cria_codg_reg_imv(codg, nome);
}

void coleta_info_imovel(dados_imovel *imovel){
    int i = 1;
    printf("\n======|Insira as Informações do Imóvel|======\n");
	printf("--------------------------------------------");
    printf("\n > Nome do Imóvel: ");
        scanf(" %[^\n]s", imovel->nome_imovel);
	printf("--------------------------------------------\n");
    printf(" > Valor do Imóvel em R$: ");
        scanf("%f", &imovel->valor_imovel);
	printf("--------------------------------------------\n");
    while(i){
    printf(" > O imóvel está quitado? [S/N] : ");
        scanf(" %c", &imovel->pago);
        if          (imovel->pago == 'S'){ i = 0;}
        else if(imovel->pago == 'N'){ i = 0;}
        else if(imovel->pago == 's'){ i = 0; imovel->pago = 'S';}
        else if(imovel->pago == 'n'){ i = 0; imovel->pago = 'N';}
		printf("--------------------------------------------");
    }
        cria_codg_reg_imv(&imovel->cod_registro, imovel->nome_imovel);
    printf("\n > O Código de Registro do Imóvel é : %s", imovel->cod_registro);
	printf("\n--------------------------------------------\n");
        //cria_arq_imv(imovel.cod_registro, imovel.nome_imovel, imovel.valor_imovel);
        system("pause");
}
