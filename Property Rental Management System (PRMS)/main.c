/*
 ===================================================================================
 Name         : Property Rental Management System (PRMS)
 Author       : Lucas Elias de Andrade Cruvinel, Ramon Soares Mendes Meneses Leite
 Registration : 201902914, 201902921
 Version      : 0.49
 E-mail:      : lucrilhasbr@gmail.com, ramnsores1000@gmail.com
 Description  : System focused on property rental management
 University   : Universidade Federal de Goiás - Catalão GO
 Objective    : Final work of APC2 / LAB2
 ===================================================================================
 */
 
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

//Codigo Modularizado:
#include "busca.c"
#include "cadastro.c"
#include "cadastro_imovel.c"
#include "cadastro_locatario.c"
#include "exclui.c"
#include "fiador.c"
#include "menu.c"
#include "modifica.c"
#include "pagamento.c"
#include "structs.h"

//Declaração de Funções:

FILE *abre_arq_loc(char nome[], int opc); //faz abertura do arquivo
FILE *verifica_abertura_loc(FILE *cadastro, char nome[], int opc); //verifica abertura do arquivo

//Structs

void main() {

    setlocale(LC_ALL, "Portuguese"); // permite usar acentos e cedilhas; será usado bastante durante o programa
    criapastas();
    menu_principal(0);
    }

void criapastas(){
    struct stat st = {0};
    if (stat("Imovel", &st) == -1)                  { mkdir("Imovel"); }
    if (stat("Locatario", &st) == -1)            { mkdir("Locatario"); }
    if (stat("LocacaoImovel", &st) == -1) { mkdir("LocacaoImovel"); }
    if (stat("Regist_Imoveis", &st) == -1) { mkdir("Regist_Imoveis"); }
    if (stat("Regist_Locatar", &st) == -1) { mkdir("Regist_Locatar"); }
}
