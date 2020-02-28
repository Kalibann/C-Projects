void exclui_cadastro() {
    system("cls");
    int opc_ex;
    char reg[6], nome[30], nome_i[30], reg_i[6], loc_i[35];
    char dirnome[50] = "Locatario/";
    char dirreg[50] = "Regist_Locatar/";
    char dirreg_i[50] = "Regist_Imoveis/";
    char dirnome_i[50] = "Imovel/";
    char dirloc_i[50] = "LocacaoImovel/";

    FILE *deleta;

    while(true){
        opc_ex = 0;

        do{
        printf("==============|Selecione uma opcao|==============\n");
        printf("1- Excluir por numero de registro do locatario  =\n");
        printf("2- Excluir pelo nome do locatario               =\n");
        printf("3- Voltar ao menu principal                     =\n");
        printf("==============|x-x-x-x-x-x-x-x-x-x|==============\n");
        printf("> ");
        scanf(" %d", &opc_ex);
        }while(opc_ex <1 || opc_ex >3);

        if(opc_ex == 1){
			printf("-------------------------------------------------------\n");    
            printf(" > Digite um registro para deletar: ");
            scanf("%s", reg);
            strcat(dirreg, reg);
            strcat(dirreg, ".txt");
            deleta = fopen(dirreg, "r");
            if(deleta == NULL){  printf(" > ERRO: Esse registro nao existe! Tente novamente...\n\n"); exclui_cadastro();}
            else    break;

        }
        if(opc_ex == 2){
			printf("-------------------------------------------------------\n");          
            printf(" > Digite o nome do locatario para deletar o cadastro: ");
            scanf(" %[^\n]s", nome);
            strcat(dirnome, nome);
            strcat(dirnome, ".txt");
            deleta = fopen(dirnome, "r");
            if(deleta == NULL){  printf(" > ERRO: Esse cadastro nao existe! Tente novamente...\n\n"); exclui_cadastro();}
            else    break;
        }
        if(opc_ex == 3){
            system("cls");
            menu_principal();
        }
    }

    if(opc_ex == 1){
        fgets(nome, 30, deleta);
        fclose(deleta);
        strcat(dirnome, nome);
        strcat(dirnome, ".txt");
    }
    if(opc_ex == 2){
        fgets(reg, 6, deleta);
        fclose(deleta);
        strcat(dirreg, reg);
        strcat(dirreg, ".txt");
    }

    strcpy(loc_i, nome);
    strcat(loc_i, " ");
    strcat(loc_i, reg);

    strcat(dirloc_i, loc_i);
    strcat(dirloc_i, ".txt");

    deleta = fopen(dirloc_i, "r");
    if(deleta == NULL){
        printf(" > ERRO: Problema inesperado ao tentar excluir arquivo! Tente novamente...\n\n");
        exclui_cadastro();
    }
    else{
        fgets(reg_i, 6, deleta);
        fclose(deleta);

        strcat(dirreg_i, reg_i);
        strcat(dirreg_i, ".txt");
        deleta = fopen(dirreg_i, "r");
        fgets(nome_i, 30, deleta);
        fclose(deleta);
        strcat(dirnome_i, nome_i);
        strcat(dirnome_i, ".txt");
    }
	
	/*
    printf("%s\n", nome);
    printf("%s\n", nome_i);
    printf("%s\n", loc_i);
    printf("%s\n", reg);
    printf("%s\n", reg_i);
    printf("%s\n", dirnome);
    printf("%s\n", dirnome_i);
    printf("%s\n", dirloc_i);
    printf("%s\n", dirreg);
    printf("%s\n", dirreg_i);
	*/
	
    remove(dirnome);
    remove(dirreg);
    remove(dirloc_i);
    remove(dirnome_i);
    remove(dirreg_i);
	
	printf("----------------------------------------------------\n");    
    printf(" > Cadastro deletado! Voltando ao menu");
    Sleep(1000);
    printf(".");
    Sleep(1000);
    printf(".");
    Sleep(1000);
    printf(".");
    system("clear");
    menu_principal();
}