void mostra_locacao() {
    setlocale(LC_ALL, "Portuguese"); // permite usar acentos e cedilhas; será usado bastante durante o programa

    int opc_busca, opc_busca2;
    char reg[6], nome[30], nome_i[20], reg_i[6], loc_i[35], buffer[35];
    char dirnome[50] = "Locatario/";
    char dirreg[50] = "Regist_Locatar/";
    char dirreg_i[50] = "Regist_Imoveis/";
    char dirnome_i[50] = "Imovel/";
    char dirloc_i[50] = "LocacaoImovel/";

    FILE *busca;
	
	system("cls");
	
    do{
        printf("=====|Escolha uma opcao valida|=====\n\n");
        printf("1- Busca com base no imovel        =\n");
        printf("2- Busca base no locatario         =\n");
        printf("3- Mostra todos os cadastros       =\n");
        printf("4- Voltar ao menu de busca         =\n");
		printf("\n=====|x-x-x-x-x-x-x-x-x-x-x-x-|=====\n");
        printf("> ");
        scanf(" %d", &opc_busca);
    }
    while(opc_busca <1 || opc_busca >4);

    if(opc_busca == 1){

        while(true){

            do{
			printf("\n========|Selecione uma opcao valida|========\n\n");
            printf("1- Buscar por numero de registro do imovel =\n");
            printf("2- Buscar pelo nome do imovel              =\n");
            printf("3- Voltar ao menu                          =\n");
			printf("\n========|x-x-x-x-x-x-x-x-x-x-x-x-x-|========\n");
            printf(" > ");
            scanf("%d", &opc_busca2);
            }while(opc_busca2 < 1 || opc_busca2 > 3);

            if(opc_busca2 == 1){
				printf("----------------------------------------\n");
                printf(" > Digite um registro para buscar: ");
                scanf(" %[^\n]s", reg_i);
                strcat(dirreg_i, reg_i);
                strcat(dirreg_i, ".txt");
                busca = fopen(dirreg_i, "r");
                if(busca == NULL){  printf(" > ERRO: Esse registro nao existe! Tente novamente...\n\n"); mostra_locacao();}
                else    break;

            }
            if(opc_busca2 == 2){
				printf("----------------------------------------\n");
                printf(" > Digite o nome do imovel para buscar: ");
                scanf(" %[^\n]s", nome_i);
                strcat(dirnome_i, nome_i);
                strcat(dirnome_i, ".txt");
                busca = fopen(dirnome_i, "r");
                if(busca == NULL){  printf(" > ERRO: Esse imovel nao existe! Tente novamente...\n\n"); mostra_locacao();}
                else    break;
            }
            if(opc_busca2 == 3){
                system("cls");
                mostra_locacao();
            }
        }

        if(opc_busca2 == 1){
            fgets(nome_i, 30, busca);
            fclose(busca);
            strcat(dirnome_i, nome_i);
            strcat(dirnome_i, ".txt");
        }
        else{
            fgets(reg_i, 6, busca);
            fclose(busca);
            strcat(dirreg_i, reg_i);
            strcat(dirreg_i, ".txt");
        }

        busca = fopen(dirreg_i, "r");
        if(busca == NULL){
                printf(" > ERRO: Problema inesperado ao tentar mostrar os dados! Tente novamente...\n\n");
                mostra_locacao();
            }
        else{
            for(int k = 0; k<2;k++){
                    fgets(loc_i, 35, busca);
                    printf("\n%s", loc_i);
            }
            strcat(dirloc_i, loc_i);
            strcat(dirloc_i, ".txt");
            printf("\n\nOPA: %s\n\n", dirloc_i);

            busca = fopen(dirloc_i, "r");
            if(busca == NULL){
                printf(" > ERRO: Problema inesperado ao tentar mostrar os dados! Tente novamente...\n\n");
                mostra_locacao();
            }
            else{
                system("cls");
                char p[2];
                int z, k;

                for(k=0;k<22;k++){
                    fgets(buffer, 30, busca);
                    if(k==0){   printf("|======|Informacoes Imovel|======\n\n");     printf("|Reg.Imovel: ");}
                    if(k==1)    printf("|Nome Imovel: ");
                    if(k==2)    printf("|Valor Imovel: ");
                    if(k==3)    printf("|Situação de Pagamento [(S)-Em dia|(N)-Pendente]: ");
                    if(k==4)    printf("\n\n======|Informacoes Locatario|======\n\n");
                    if(k==4)    printf("|Reg.Locatario: ");
                    if(k==5)    printf("|Nome Locatario: ");
                    if(k==6)    printf("|Genero: ");
                    if(k==7)    printf("|CPF: ");
                    if(k==8)    printf("|Tipo Telefone [0-Fixo|1-Celular]: ");
                    if(k==9)    printf("|Telefone: ");
                    if(k==10)    printf("|Pais: ");
                    if(k==11)    printf("|Estado: ");
                    if(k==12)    printf("|Cidade: ");
                    if(k==13)    printf("|Bairro: ");
                    if(k==14)    printf("|Logradouro: ");
                    if(k==15)    printf("|Numero: ");
                    if(k==16)    printf("|CEP: ");
                    if(k==17)    printf("|Existencia de Fiador [0-Não|1-Sim]: ");
                    if(k==17){   p[0] = buffer[0]; p[1] = '\0'; z=atoi(p);}
                    if(z == 1){
                        if(k==18)    printf("\n\n======|Outras Informacoes|======\n\n");
                        if(k==18)    printf("|Nome Fiador: ");
                        if(k==19)    printf("|CPF Fiador: ");
                        if(k==20)    printf("|Tipo Telefone Fiador [0-Fixo|1-Celular]: ");
                        if(k==21)    printf("|Telefone Fiador: ");
                    }
                    if(z == 0){
                        if(k==18)    printf("\n\n======|Outras Informacoes|======\n\n");
                        if(k==18)    printf("|Tipo de Calcao [0-Cheque|1-Dinheiro|2-Cartao]: ");
                        if(k==19)    printf("|Valor Calcao: ");
                        if(k==20)    break;
                    }
                    printf("%s", buffer);
                }
                fclose(busca);
            }
        }
    }

    if(opc_busca == 2){
        while(true){

            do{
			printf("\n========|Selecione uma opcao valida|========\n\n");
            printf("1- Buscar por numero de registro do locatario =\n");
            printf("2- Buscar pelo nome do locatario              =\n");
            printf("3- Voltar ao menu de busca                    =\n");
			printf("\n========|x-x-x-x-x-x-x-x-x-x-x-x-x-|========\n");
            printf(" > ");
            scanf("%d", &opc_busca2);
            }while(opc_busca2 < 1 || opc_busca2 > 3);

            if(opc_busca2 == 1){
                printf("\n > Digite um registro para buscar: ");
                scanf(" %[^\n]s", reg);
                strcat(dirreg, reg);
                strcat(dirreg, ".txt");
                busca = fopen(dirreg, "r");
                if(busca == NULL){  printf(" > ERRO: Esse registro nao existe! Tente novamente...\n\n"); mostra_locacao();}
                else    break;

            }
            if(opc_busca2 == 2){
                printf("\n > Digite o nome do locatario para buscar: ");
                scanf(" %[^\n]s", nome);
                strcat(dirnome, nome);
                strcat(dirnome, ".txt");
                busca = fopen(dirnome, "r");
                if(busca == NULL){  printf(" > ERRO: Esse cadastro nao existe! Tente novamente...\n\n"); mostra_locacao();}
                else    break;
            }
            else {
                system("cls");
                mostra_locacao();
            }
        }

        if(opc_busca2 == 1){
            fgets(nome, 30, busca);
            fclose(busca);
            strcat(dirnome, nome);
            strcat(dirnome, ".txt");
        }
        else{
            fgets(reg, 6, busca);
            fclose(busca);
            strcat(dirreg, reg);
            strcat(dirreg, ".txt");
        }

        strcpy(loc_i, nome);
        strcat(loc_i, " ");
        strcat(loc_i, reg);

        strcat(dirloc_i, loc_i);
        strcat(dirloc_i, ".txt");

        busca = fopen(dirloc_i, "r");
        if(busca == NULL){
            printf(" > ERRO: Problema inesperado ao tentar mostrar os dados! Tente novamente...\n\n");
            mostra_locacao();
        }
        else{

            system("cls");
            char p[2];
            int z,k;

            for(k=0;k<22;k++){
                fgets(buffer, 30, busca);
                if(k==0){   printf("|======|Informacoes Imovel|======\n\n");     printf("|Reg.Imovel: ");}
                if(k==1)    printf("|Nome Imovel: ");
                if(k==2)    printf("|Valor Imovel: ");
                if(k==3)    printf("|Situação de Pagamento [(S)-Em dia|(N)-Pendente]: ");
                if(k==4)    printf("\n\n======|Informacoes Locatario|======\n\n");
                if(k==4)    printf("|Reg.Locatario: ");
                if(k==5)    printf("|Nome Locatario: ");
                if(k==6)    printf("|Genero: ");
                if(k==7)    printf("|CPF: ");
                if(k==8)    printf("|Tipo Telefone [0-Fixo|1-Celular]: ");
                if(k==9)    printf("|Telefone: ");
                if(k==10)    printf("|Pais: ");
                if(k==11)    printf("|Estado: ");
                if(k==12)    printf("|Cidade: ");
                if(k==13)    printf("|Bairro: ");
                if(k==14)    printf("|Logradouro: ");
                if(k==15)    printf("|Numero: ");
                if(k==16)    printf("|CEP: ");
                if(k==17)    printf("|Existencia de Fiador [0-Não|1-Sim]: ");
                if(k==17){   p[0] = buffer[0]; p[1] = '\0'; z=atoi(p);}
                if(z == 1){
                    if(k==18)    printf("\n\n======|Outras Informacoes|======\n\n");
                    if(k==18)    printf("|Nome Fiador: ");
                    if(k==19)    printf("|CPF Fiador: ");
                    if(k==20)    printf("|Tipo Telefone Fiador [0-Fixo|1-Celular]: ");
                    if(k==21)    printf("|Telefone Fiador: ");
                }
                if(z == 0){
                    if(k==18)    printf("\n\n======|Outras Informacoes|======\n\n");
                    if(k==18)    printf("|Tipo de Calcao [0-Cheque|1-Dinheiro|2-Cartao]: ");
                    if(k==19)    printf("|Valor Calcao: ");
                    if(k==20)    break;
                }
                printf("%s", buffer);
            }
            fclose(busca);
        }

    }
    if(opc_busca == 3){
        system("cls");
        printf("|============================|CADASTROS|============================|\n\n");
        int x, i, k=0;
        char nome[30], reg[6], nome_i[20], reg_i[6];
        FILE *dados;
        DIR *dir;
        struct dirent *lsdir;

        dir = opendir("LocacaoImovel\\");

        // Imprime todos os arquivos de um diretório específico
        while ( ( lsdir = readdir(dir) ) != NULL )
        {
            char d[35];

            if(k>1){

                x=strlen(lsdir->d_name);

                reg[0] = lsdir->d_name[x-9];
                reg[1] = lsdir->d_name[x-8];
                reg[2] = lsdir->d_name[x-7];
                reg[3] = lsdir->d_name[x-6];
                reg[4] = lsdir->d_name[x-5];
                reg[5] = '\0';

                strcpy(d, "LocacaoImovel/");
                strcat(d, lsdir->d_name);

                dados=fopen(d, "r");

                fgets(reg_i, 6, dados);
                rewind(dados);
                for(i=0;i<2;i++){
                    fgets(nome_i, 30, dados);
                }
                rewind(dados);
                for(i=0;i<5;i++){
                    fgets(nome, 30, dados);
                }

                fclose(dados);
                    printf("|Nome: %s", nome);
                    printf("|Reg.Locatario: %s\n", reg);
                    printf("|Imovel: %s", nome_i);
                    printf("|Reg.Imovel: %s\n\n", reg_i);
                }
            k++;
        }

        closedir(dir);
    }
    if(opc_busca == 4){
        system("cls");
        menu_principal(1);
    }
    printf("\n\nPressione qualquer tecla para voltar ao menu de busca...\n");
    printf("> ");
    getch();
    system("cls");
    mostra_locacao();
}
