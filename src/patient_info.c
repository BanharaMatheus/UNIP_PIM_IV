#include <stdio.h>
#include <time.h>
#include <stdbool.h>

void patient_informations(){
    FILE *pont_arq;
    pont_arq = fopen("dbs/db.txt", "a");

    FILE *pont_arq_2;
    pont_arq_2 = fopen("dbs/db_2.txt", "a");

    struct ficha_paciente{
        char nome[99], rua[99], cpf_patient[99], bairro[99], cidade[99], estado[99], email[99], comorbidade[999], telefone[99], numero_casa[99], cep[99];
        int dd_nascimento, mm_nascimento, aa_nascimento, dd_diagnostico, mm_diagnostico, aa_diagnostico, idade, key_comorb;
    };
    struct ficha_paciente paciente;

    char data_nascimento[10], data_diagnostico[10];
    int dia, mes, ano;
    struct tm *local;
    time_t t;
    t = time(NULL);
    local=localtime(&t);

    dia=local->tm_mday;
    mes=local->tm_mon+1;
    ano=local->tm_year+1900;

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
    printf("CEP (somente numeros): ");
    fflush(stdin);
    scanf("%[^\n]s", &paciente.cep);
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
    fflush(stdin);
    printf("Comorbidade(Se houver separe com espacos/se nao houver apenas ENTER): ");
    if (scanf("%[^\n]s", &paciente.comorbidade) == '\0'){
        paciente.key_comorb = 0;
    }else{paciente.key_comorb = 1;}
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

    if(paciente.key_comorb == 1){
        if(paciente.aa_nascimento < (ano-64)){
            if(paciente.mm_nascimento < mes){
                paciente.idade = ano - paciente.aa_nascimento;
                fprintf(pont_arq_2, "%s, %s, %s, %s, %d\n", paciente.nome, paciente.cep, paciente.rua, paciente.numero_casa, paciente.idade);
            }
            if(paciente.mm_nascimento == mes){
                if(paciente.dd_nascimento <= dia){
                    paciente.idade = ano - paciente.aa_nascimento;
                    fprintf(pont_arq_2, "%s, %s, %s, %s, %d\n", paciente.nome, paciente.cep, paciente.rua, paciente.numero_casa, paciente.idade);
                }
            }
        paciente.idade = ano - paciente.aa_nascimento;
        }
    }

    fprintf(pont_arq, "%s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %d/%d/%d, %d/%d/%d %s\n", paciente.nome, paciente.cpf_patient, paciente.telefone, paciente.rua, paciente.numero_casa,
            paciente.bairro, paciente.cidade, paciente.estado, paciente.cep, paciente.email, paciente.dd_nascimento, paciente.mm_nascimento, paciente.aa_nascimento,
            paciente.dd_diagnostico, paciente.mm_diagnostico, paciente.aa_diagnostico, paciente.comorbidade);


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
            fclose(pont_arq);
            fclose(pont_arq_2);
            initialize_menu();
            break;
        }
        if (opcao == 2){
            fclose(pont_arq);
            fclose(pont_arq_2);
            patient_informations();
            break;
        }
        if (opcao == 3){
            fclose(pont_arq);
            fclose(pont_arq_2);
            break;
        }
        else{
            printf("Voce escolheu uma opcao invalida!\n");
        }

    }while(opcao != 1,2,3);



}


void clean_dbs(){
    system("cls");
    printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
    printf("Isso ira limpar todos os dados cadastrados no sistema\n\n");
    printf("Tem certeza que deseja fazer isso?\n\n");
    printf("1 - SIM\n\n");
    printf("2 - NAO\n\n");
    printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
    printf("Caso escolha 1, os DBs serao resetados e voce retornara ao menu\n");
    int opcao_4 = 0;
    do{

        fflush(stdin);
        printf("Escolha sua opcao: ");
        scanf("%d", &opcao_4);

        if (opcao_4 == 1){
            remove("dbs/db.txt");
            remove("dbs/db_2.txt");
            initialize_menu();
        }
        else{
            initialize_menu();
            break;
        }

    }while(opcao_4 != 1);
}
