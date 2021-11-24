#include <stdio.h>
#include <time.h>

void patient_informations(){
    FILE *pont_arq;
    pont_arq = fopen("db.txt", "a");

    FILE *pont_arq_2;
    pont_arq_2 = fopen("db_2.txt", "a");

    struct ficha_paciente{
        char nome[80], rua[80], cpf_patient[30], bairro[30], cidade[20], estado[20], email[20], comorbidade[40], telefone[20], numero_casa[20], cep[20];
        int dd_nascimento, mm_nascimento, aa_nascimento, dd_diagnostico, mm_diagnostico, aa_diagnostico, idade;
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
    scanf("%s", &paciente.comorbidade);


    if(paciente.comorbidade != "N"){
        printf("Possui alguma comorbidade");
        if(paciente.aa_nascimento < (ano-64)){
            if(paciente.mm_nascimento == mes){
                if(paciente.dd_nascimento == dia){
                    fprintf(pont_arq_2, "%s, %s, %s, %s, %d\n", paciente.nome, paciente.cep, paciente.rua, paciente.numero_casa, paciente.idade);
                }
            }
        }
    }
    else{
        printf("Não possui nenhuma comorbidade");
    }


    fprintf(pont_arq, "%s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %d/%d/%d, %d/%d/%d\n", paciente.nome, paciente.cpf_patient, paciente.telefone, paciente.rua, paciente.numero_casa,
            paciente.bairro, paciente.cidade, paciente.estado, paciente.cep, paciente.email, paciente.dd_nascimento, paciente.mm_nascimento, paciente.aa_nascimento, paciente.dd_diagnostico, paciente.mm_diagnostico, paciente.aa_diagnostico);






    /*
    printf("%d\n" , paciente.dd_nascimento);
    printf("%d\n" , paciente.mm_nascimento);
    printf("%d\n" , paciente.aa_nascimento);
    printf("%d\n" , paciente.dd_diagnostico);
    printf("%d\n" , paciente.mm_diagnostico);
    printf("%d\n" , paciente.aa_diagnostico);
    printf("Comorbidade: %s", paciente.comorbidade);

    fprintf(pont_arq, "%d/%d/%d, %d/%d/%d\n", paciente.dd_nascimento, paciente.mm_nascimento, paciente.aa_nascimento, paciente.dd_diagnostico, paciente.mm_diagnostico, paciente.aa_diagnostico);
    */

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

