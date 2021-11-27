#include <stdio.h>
#include <stdlib.h>

void show_info(void)
{
    FILE *pont_arq;
    char c;

    system("cls");
    pont_arq = fopen("dbs/db.txt","r");
    if (pont_arq == NULL)
    {
        printf("Erro ao tentar abrir o arquivo!");
        initialize_menu();
    }
    printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("Lista de pacientes cadastrados\n");
    printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    do
    {
        c = fgetc(pont_arq);
        printf("%c", c);
    }while (c != EOF);

    printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
    printf("O que deseja fazer agora?\n\n");
    printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
    printf("1 - Voltar ao menu\n");
    printf("2 - Sair da aplicacao\n");

    int opcao_2 = 0;
    do{

        fflush(stdin);
        printf("Escolha sua opcao: ");
        scanf("%d", &opcao_2);

        if (opcao_2 == 1){
            fclose(pont_arq);
            initialize_menu();
        }
        else{
            break;
        }

    }while(opcao_2 != 1);

}

void send_info(){
    FILE *pont_arq, *copy_arq;
    char filename[40], c;
    system("cls");


    do{
        fflush(stdin);
        printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
        printf("Insira o nome do arquivo para ser exportado(inclua \".txt\" no final: ");
        scanf("%[^\n]s", &filename);
    }while(filename == NULL);


    pont_arq = fopen("dbs/db_2.txt","r");
    copy_arq = fopen(filename, "w");

    c = fgetc(pont_arq);
    while (c != EOF)
    {
        fputc(c, copy_arq);
        c = fgetc(pont_arq);
    }
    printf("\nContents copied to %s\n", filename);

    fclose(pont_arq);
    fclose(copy_arq);



    printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
    printf("O que deseja fazer agora?\n\n");
    printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
    printf("1 - Voltar ao menu\n");
    printf("2 - Sair da aplicacao\n");
    int opcao_3 = 0;
    do{

        fflush(stdin);
        printf("Escolha sua opcao: ");
        scanf("%d", &opcao_3);

        if (opcao_3 == 1){
            fclose(pont_arq);
            initialize_menu();
        }
        else{
            break;
        }

    }while(opcao_3 != 1);
    fclose(pont_arq);
    fclose(copy_arq);
}






































