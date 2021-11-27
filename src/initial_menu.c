#include <stdio.h>
#include <stdlib.h>


void initialize_menu(){
    int opcao = 0;

    system("cls");


    printf("------------------------------------------------------------------------------------------------------------------------\n\n");
    printf("Seja bem vindo(a)!\n\n");
    printf("------------------------------------------------------------------------------------------------------------------------\n\n");
    printf("Sistema de cadastro de pacientes com COVID-19\n\n");
    printf("________________________________________________________________________________________________________________________\n\n\n");
    printf("\t 1 - Cadastrar paciente com COVID-19\n");
    printf("\t 2 - Exibir dados de pacientes ja cadastrados\n");
    printf("\t 3 - Mandar informacoes para o Ministerio da saude\n");
    printf("\t 4 - Limpar bancos de dados\n");
    printf("\t 5 - Sair da aplicacao\n\n\n");
    printf("------------------------------------------------------------------------------------------------------------------------\n\n");
    do{
        fflush(stdin);
        printf("Escolha sua opcao: ");
        scanf("%d", &opcao);
        if (opcao == 1){
            patient_informations();
            break;
        }
        if (opcao == 2){
            show_info();
            break;
        }
        if (opcao == 3){
            send_info();
            break;
        }
        if (opcao == 4){
            clean_dbs();
            break;
        }
        if (opcao == 5){
            break;
        }
        else{
            printf("Voce escolheu uma opcao invalida!\n");
        }
    }while(opcao != 1,2,3,4);

}
