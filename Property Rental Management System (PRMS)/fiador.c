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

void coleta_info_fiado(fiador *fiado){
    setlocale(LC_ALL, "Portuguese"); // permite usar acentos e cedilhas; será usado bastante durante o programa

    int i = 1;
	printf("\n--------------------------------------------");
    printf("\n  > Insira o nome do fiador: ");
        scanf(" %[^\n]s", fiado->nome);
	printf("--------------------------------------------");
    printf("\n  > Insira o CPF [Use somente numeros]: ");
        scanf(" %s", &fiado->cpf);
	printf("--------------------------------------------");
    while(i){
    printf("\n  > Insira o tipo de telefone, 0 para fixo e 1 para celular: ");
        scanf(" %d", &fiado->tipo_telefone);
        if(fiado->tipo_telefone == 0) i = 0;
        if(fiado->tipo_telefone == 1) i = 0;
		printf("--------------------------------------------");
    }
    printf("\n  > Insira o Telefone [Use somente numeros]: ");
        scanf(" %s", &fiado->telefone);
	printf("--------------------------------------------\n");
}

void coleta_info_sem_fiado(nao_fiador *no_fiado){
    int i = 1;
    setlocale(LC_ALL, "Portuguese"); // permite usar acentos e cedilhas; será usado bastante durante o programa
    while(i){
    printf("\n  > Qual o tipo de calcao?");
    printf("\n   > 0 para Cheque");
    printf("\n   > 1 para Dinheiro");
    printf("\n   > 2 para Cartao");
    printf("\n\n   > : ");
        scanf(" %d", &no_fiado->tipo_calcao);
        if(no_fiado->tipo_calcao == 0) i = 0;
        if(no_fiado->tipo_calcao == 1) i = 0;
        if(no_fiado->tipo_calcao == 2) i = 0;
		printf("--------------------------------------------");
    }

    printf("\n  > Insira o valor do calcao: R$");
    scanf(" %f", &no_fiado->valor_calcao);
}
