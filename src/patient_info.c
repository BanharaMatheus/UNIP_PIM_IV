#include <stdio.h>

void patient_informations(){
    FILE *pont_arq;
    pont_arq = fopen("db.txt", "a");

    struct ficha_paciente{
        char nome[80], rua[80], cpf_patient[30], bairro[30], cidade[20], estado[20], email[20], comorbidade[40], telefone[20], numero_casa[20], cep[20];
        double dd_nascimento, mm_nascimento, aa_nascimento, dd_diagnostico, mm_diagnostico, aa_diagnostico;
    };
    struct ficha_paciente paciente;

    char data_nascimento[10], data_diagnostico[10];

    system("cls");

    printf("Informacoes necessarias sobre o paciente diagnosticado com COVID-19 \n\n\n");


    printf("Nome do paciente: ");
    fflush(stdin);
    scanf("%[^\n]s", paciente.nome);
    printf("CPF (somente numeros): ");
    fflush(stdin);
    scanf("%[^\n]s", &paciente.cpf_patient);
    printf("Telefone (somente numeros): ");
    fflush(stdin);
    scanf("%[^\n]s", &paciente.telefone);
    printf("Rua: ");
    fflush(stdin);
    scanf("%[^\n]s", &paciente.rua);
    printf("Numero da casa: ");
    fflush(stdin);
    scanf("%[^\n]s", &paciente.numero_casa);
    printf("Bairro: ");
    fflush(stdin);
    scanf("%[^\n]s", &paciente.bairro);
    printf("Cidade: ");
    fflush(stdin);
    scanf("%[^\n]s", &paciente.cidade);
    printf("Estado: ");
    fflush(stdin);
    scanf("%[^\n]s", &paciente.estado);
    printf("CEP (somente numeros): ");
    fflush(stdin);
    scanf("%[^\n]s", &paciente.cep);
    printf("Data de nascimento (formato DD/MM/AAAA): ");
    fflush(stdin);
    scanf("%d/%d/%d", &paciente.dd_nascimento, &paciente.mm_nascimento, &paciente.aa_nascimento);
    fflush(stdin);
    printf("Data do diagnostico (formato DD/MM/AAAA): ");
    fflush(stdin);
    scanf("%d/%d/%d", &paciente.dd_diagnostico, &paciente.mm_diagnostico, &paciente.aa_diagnostico);
    fflush(stdin);
    printf("Email do paciente: ");
    scanf("%[^\n]s", &paciente.email);
    printf("Comorbidade(se nao houver apenas \"N\"): ");
    fflush(stdin);
    scanf("%[^\n]s", &paciente.comorbidade);
    fprintf(pont_arq, "%s, %s, %s, %s, %s, %s, %s, %s, %s, %s\n", paciente.nome, paciente.cpf_patient, paciente.telefone, paciente.rua, paciente.numero_casa, paciente.bairro, paciente.cidade, paciente.estado, paciente.cep, paciente.email);


    /*
    Falta concagtenar as datas pra printar no arquivo, ai acabo aquela task

    Depois entra o tratamento de dados

    sprintf(data_nascimento, "%lf", paciente.dd_diagnostico, &paciente.mm_diagnostico, &paciente.aa_diagnostico);
    fprintf(pont_arq, "%s \n", paciente.dd_diagnostico);
    */






    printf("------------------------------------------------------------------------------------------------------------------------\n\n");
    printf("Paciente cadastrado com sucesso!\n\n");
    printf("Oque deseja fazer agora?\n\n");
    printf("------------------------------------------------------------------------------------------------------------------------\n\n");
    printf("1 - Voltar ao menu\n");
    printf("2 - Cadastrar outro paciente\n");
    printf("3 - Sair da aplicacao\n\n");

    int opcao = 0;
    do{

        fflush(stdin);
        printf("Escolha sua opcao: ");
        scanf("%d", &opcao);

        if (opcao == 1){
            initialize_menu();
            break;
        }
        if (opcao == 2){
            patient_informations();
            break;
        }
        if (opcao == 3){
            printf("opcao = 3\n");
            break;
        }
        else{
            printf("Voce escolheu uma opcao invalida!\n");
        }

    }while(opcao != 1,2,3);
    fclose(pont_arq);



}

