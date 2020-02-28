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

void cadastro_locacao_inicio() {
    dados_imovel info_imv;
    dados_locatario info_loc;
        system("cls");
    coleta_info_imovel(&info_imv);
        system("cls");
    coleta_info_locacao(&info_loc);
    if(info_loc.existencia_fiador == 0){
        nao_fiador info_sem_fiado;
        coleta_info_sem_fiado(&info_sem_fiado);
        gravacao_sem_fiado(info_imv, info_loc, info_sem_fiado);
        menu_principal(0);
    }
    if(info_loc.existencia_fiador == 1){
        fiador info_fiado;
        coleta_info_fiado(&info_fiado);
        gravacao_fiado(info_imv, info_loc, info_fiado);
        menu_principal(0);
    }
}

void gravacao_sem_fiado(dados_imovel imovel, dados_locatario pessoa, nao_fiador nfiado){
    FILE *imv;
    FILE *locat;
    FILE *tudo;
	FILE *regimv;
    char cam_imv[30] = {"Imovel/"};
    char cam_locat[30] = {"Locatario/"};
    char cam_locimov[40] = {"LocacaoImovel/"};
	char cam_reg_imv[40] = {"Regist_Imoveis/"};

    strcat(cam_imv, imovel.nome_imovel);
    strcat(cam_imv, ".txt");
    strcat(cam_locat, pessoa.nome);
    strcat(cam_locat, ".txt");
    strcat(cam_locimov, pessoa.nome);
    strcat(cam_locimov, " ");
    strcat(cam_locimov, pessoa.cod_registro);;
    strcat(cam_locimov, ".txt");
	strcat(cam_reg_imv, imovel.cod_registro);
	strcat(cam_reg_imv, ".txt");

    imv = fopen(cam_imv, "w");
        if(imv == NULL){ printf("\n  >  >  Erro ao tentar executar o cadastro!  <  <\n  >  > Por favor reinicie o programa!  <  <\n"); sair();}
    locat = fopen(cam_locat, "w");
        if(locat == NULL){ printf("\n  >  >  Erro ao tentar executar o cadastro!  <  <\n  >  > Por favor reinicie o programa!  <  <\n"); sair();}
    tudo = fopen(cam_locimov, "w");
        if(tudo == NULL){ printf("\n  >  >  Erro ao tentar executar o cadastro!  <  <\n  >  > Por favor reinicie o programa!  <  <\n"); sair();}
	regimv = fopen(cam_reg_imv, "a");
        if(regimv == NULL){ printf("\n  >  >  Erro ao tentar executar o cadastro!  <  <\n  >  > Por favor reinicie o programa!  <  <\n"); sair();}

        fprintf(imv, "%s\n", imovel.cod_registro);
        fprintf(imv, "%s\n", imovel.nome_imovel);
        fprintf(imv, "%.2f\n", imovel.valor_imovel);
        fprintf(imv, "%c", imovel.pago);

        fprintf(tudo, "%s\n", imovel.cod_registro);
        fprintf(tudo, "%s\n", imovel.nome_imovel);
        fprintf(tudo, "%.2f\n", imovel.valor_imovel);
        fprintf(tudo, "%c\n", imovel.pago);

        fprintf(locat, "%s\n", pessoa.cod_registro);
        fprintf(locat, "%s\n", pessoa.nome);
        fprintf(locat, "%c\n", pessoa.genero);
        fprintf(locat, "%s\n", pessoa.cpf);
        fprintf(locat, "%d\n", pessoa.tipo_telefone);
        fprintf(locat, "%s\n", pessoa.telefone);
        fprintf(locat, "%s\n", pessoa.endereco.pais);
        fprintf(locat, "%s\n", pessoa.endereco.estado);
        fprintf(locat, "%s\n", pessoa.endereco.cidade);
        fprintf(locat, "%s\n", pessoa.endereco.bairro);
        fprintf(locat, "%s\n", pessoa.endereco.logradouro);
        fprintf(locat, "%d\n", pessoa.endereco.numero);
        fprintf(locat, "%ld\n", pessoa.endereco.cep);
        fprintf(locat, "%d", pessoa.existencia_fiador);

		fprintf(regimv,"%s %s", pessoa.nome, pessoa.cod_registro);

        fprintf(tudo, "%s\n", pessoa.cod_registro);
        fprintf(tudo, "%s\n", pessoa.nome);
        fprintf(tudo, "%c\n", pessoa.genero);
        fprintf(tudo, "%s\n", pessoa.cpf);
        fprintf(tudo, "%d\n", pessoa.tipo_telefone);
        fprintf(tudo, "%s\n", pessoa.telefone);
        fprintf(tudo, "%s\n", pessoa.endereco.pais);
        fprintf(tudo, "%s\n", pessoa.endereco.estado);
        fprintf(tudo, "%s\n", pessoa.endereco.cidade);
        fprintf(tudo, "%s\n", pessoa.endereco.bairro);
        fprintf(tudo, "%s\n", pessoa.endereco.logradouro);
        fprintf(tudo, "%d\n", pessoa.endereco.numero);
        fprintf(tudo, "%ld\n", pessoa.endereco.cep);
        fprintf(tudo, "%d\n", pessoa.existencia_fiador);

        fprintf(tudo, "%d\n", nfiado.tipo_calcao);
        fprintf(tudo, "%.2f", nfiado.valor_calcao);

	fclose(regimv);
    fclose(imv);
    fclose(locat);
    fclose(tudo);

    printf("\n\nCadastro concluido com sucesso! Retornando ao menu");
    Sleep(1000);
    printf(".");
    Sleep(1000);
    printf(".");
    Sleep(1000);
    printf(".");
    menu_principal(0);
}

void gravacao_fiado(dados_imovel imovel, dados_locatario pessoa, fiador fiado){
    FILE *regimv;
    FILE *imv;
    FILE *locat;
    FILE *tudo;
    char cam_imv[30] = {"Imovel/"};
    char cam_locat[30] = {"Locatario/"};
    char cam_locimov[40] = {"LocacaoImovel/"};
	char cam_reg_imv[40] = {"Regist_Imoveis/"};

    strcat(cam_imv, imovel.nome_imovel);
    strcat(cam_imv, ".txt");
    strcat(cam_locat, pessoa.nome);
    strcat(cam_locat, ".txt");
    strcat(cam_locimov, pessoa.nome);
    strcat(cam_locimov, " ");
    strcat(cam_locimov, pessoa.cod_registro);;
    strcat(cam_locimov, ".txt");

    imv = fopen(cam_imv, "w");
        if(imv == NULL){ printf("\n  >  >  Erro ao tentar executar o cadastro!  <  <\n  >  > Por favor reinicie o programa!  <  <\n"); sair();}
    locat = fopen(cam_locat, "w");
        if(locat == NULL){ printf("\n  >  >  Erro ao tentar executar o cadastro!  <  <\n  >  > Por favor reinicie o programa!  <  <\n"); sair();}
    tudo = fopen(cam_locimov, "w");
        if(tudo == NULL){ printf("\n  >  >  Erro ao tentar executar o cadastro!  <  <\n  >  > Por favor reinicie o programa!  <  <\n"); sair();}
	regimv = fopen(cam_reg_imv, "a");
        if(regimv == NULL){ printf("\n  >  >  Erro ao tentar executar o cadastro!  <  <\n  >  > Por favor reinicie o programa!  <  <\n"); sair();}

        fprintf(imv, "%s\n", imovel.cod_registro);
        fprintf(imv, "%s\n", imovel.nome_imovel);
        fprintf(imv, "%.2f\n", imovel.valor_imovel);
        fprintf(imv, "%c", imovel.pago);

        fprintf(tudo, "%s\n", imovel.cod_registro);
        fprintf(tudo, "%s\n", imovel.nome_imovel);
        fprintf(tudo, "%.2f\n", imovel.valor_imovel);

        fprintf(locat, "%s\n", pessoa.cod_registro);
        fprintf(locat, "%s\n", pessoa.nome);
        fprintf(locat, "%c\n", pessoa.genero);
        fprintf(locat, "%s\n", pessoa.cpf);
        fprintf(locat, "%d\n", pessoa.tipo_telefone);
        fprintf(locat, "%s\n", pessoa.telefone);
        fprintf(locat, "%s\n", pessoa.endereco.pais);
        fprintf(locat, "%s\n", pessoa.endereco.estado);
        fprintf(locat, "%s\n", pessoa.endereco.cidade);
        fprintf(locat, "%s\n", pessoa.endereco.bairro);
        fprintf(locat, "%s\n", pessoa.endereco.logradouro);
        fprintf(locat, "%d\n", pessoa.endereco.numero);
        fprintf(locat, "%ld\n", pessoa.endereco.cep);
        fprintf(locat, "%d", pessoa.existencia_fiador);

        fprintf(tudo, "%s\n", pessoa.cod_registro);
        fprintf(tudo, "%s\n", pessoa.nome);
        fprintf(tudo, "%c\n", pessoa.genero);
        fprintf(tudo, "%s\n", pessoa.cpf);
        fprintf(tudo, "%d\n", pessoa.tipo_telefone);
        fprintf(tudo, "%s\n", pessoa.telefone);
        fprintf(tudo, "%s\n", pessoa.endereco.pais);
        fprintf(tudo, "%s\n", pessoa.endereco.estado);
        fprintf(tudo, "%s\n", pessoa.endereco.cidade);
        fprintf(tudo, "%s\n", pessoa.endereco.bairro);
        fprintf(tudo, "%s\n", pessoa.endereco.logradouro);
        fprintf(tudo, "%d\n", pessoa.endereco.numero);
        fprintf(tudo, "%ld\n", pessoa.endereco.cep);
        fprintf(tudo, "%d\n", pessoa.existencia_fiador);

        fprintf(tudo, "%s\n", fiado.nome);
        fprintf(tudo, "%s\n", fiado.cpf);
        fprintf(tudo, "%d\n", fiado.tipo_telefone);
        fprintf(tudo, "%s", fiado.telefone);

	fclose(regimv);
    fclose(imv);
    fclose(locat);
    fclose(tudo);

    printf("\n\nCadastro concluido com sucesso! Retornando ao menu");
    Sleep(1000);
    printf(".");
    Sleep(1000);
    printf(".");
    Sleep(1000);
    printf(".");
    menu_principal(0);
}
