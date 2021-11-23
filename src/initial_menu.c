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
    printf("\t 3 - Gerar arquivo de texto com informacoes dos pacientes no grupo de risco\n");
    printf("\t 4 - Mandar informações para o Ministerio da saude\n");
    printf("\t 5 - Cadastrar um novo usuario no sistema\n");
    printf("\t 6 - Sair da aplicacao\n\n\n");
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
            printf("opcao = 2\n");
            break;
        }
        if (opcao == 3){
            printf("opcao = 3\n");
            break;
        }
        if (opcao == 4){
            printf("opcao = 4\n");
            break;
        }
        if (opcao == 5){
            printf("opcao = 5\n");
            break;
        }
        if (opcao == 6){
            break;
        }
        else{
            printf("Voce escolheu uma opcao invalida!\n");
        }
    }while(opcao != 1,2,3,4,5,6);

}
