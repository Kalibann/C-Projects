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

void cria_codg_reg_locat(char *codg, char nome[]){
    srand(time(NULL));
    FILE *imv;
    char reg_imv[24] = {"Regist_Locatar/"};;
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
        fprintf(imv, "%s", nome);
        fclose(imv);
        }
    else cria_codg_reg_locat(&codg, nome);
}

void coleta_info_locacao(dados_locatario *pessoa){
    int i;
    char aux;

    printf("\n======|Insira as Informações do Locatário|======: \n");
	printf("--------------------------------------------");
    printf("\n  > Insira o nome do locatário: ");
       scanf(" %[^\n]s", pessoa->nome);
    i = 1;
	printf("--------------------------------------------");
    while(i){
    printf("\n  > Insira o gênero do locatário, M ou F: ");
        scanf(" %c", &pessoa->genero);
        if          (pessoa->genero == 'M'){ i = 0;}
        else if(pessoa->genero == 'F'){ i = 0;}
        else if(pessoa->genero == 'm'){ i = 0; pessoa->genero = 'M';}
        else if(pessoa->genero == 'f'){ i = 0; pessoa->genero = 'F';}
		printf("--------------------------------------------");
        }
    i = 1;
    while(i){
    printf("\n  > Insira o Tipo de Telefone [0- Fixo| 1- Celular]: ");
        scanf(" %d", &pessoa->tipo_telefone);
        if(pessoa->tipo_telefone == 0) i = 0;
        if(pessoa->tipo_telefone == 1) i = 0;
		printf("--------------------------------------------");
    }

    printf("\n  > Insira o Telefone [Use somente números]: ");
        scanf(" %s", &pessoa->telefone);
		printf("--------------------------------------------");
    printf("\n  > Insira o CPF [Use somente números]: ");
        scanf(" %s", &pessoa->cpf);
		printf("--------------------------------------------");
    printf("\n\n======|Informe o Endereço do Locatário|======\n\n");
	printf("--------------------------------------------");
    printf("\n  > Insira o País: ");
        scanf(" %[^\n]s", &pessoa->endereco.pais);
		printf("--------------------------------------------");
    printf("\n  > Insira o Estado: ");
        scanf(" %[^\n]s", &pessoa->endereco.estado);
		printf("--------------------------------------------");
    printf("\n  > Insira o Cidade: ");
        scanf(" %[^\n]s", pessoa->endereco.cidade);
		printf("--------------------------------------------");
    printf("\n  > Insira o Bairro: ");
        scanf(" %[^\n]s", &pessoa->endereco.bairro);
		printf("--------------------------------------------");
    printf("\n  > Insira o Logradouro: ");
        scanf(" %[^\n]s", &pessoa->endereco.logradouro);
		printf("--------------------------------------------");
    printf("\n  > Insira o Número: ");
        scanf(" %ld", &pessoa->endereco.numero);
		printf("--------------------------------------------");
    printf("\n  > Insira o CEP [Use somente números]: ");
        scanf(" %ld", &pessoa->endereco.cep);
		printf("--------------------------------------------");
    cria_codg_reg_locat(&pessoa->cod_registro, pessoa->nome);

    printf("\n\n  > >  Código do Locatário : %s  < <\n\n", pessoa->cod_registro);
    system("pause");
    i = 1;
	printf("--------------------------------------------");
    while(i){
    system("cls");
    printf("\n   Informações do Fiador :");
    printf("\n\n  > Existe um fiador? [0-Não|1-Sim]: ");
        scanf(" %d", &pessoa->existencia_fiador);
        if(pessoa->existencia_fiador == 0) i = 0;
        if(pessoa->existencia_fiador == 1) i = 0;
	printf("--------------------------------------------");
    }

}
