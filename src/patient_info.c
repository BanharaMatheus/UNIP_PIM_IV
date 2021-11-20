#include <stdio.h>


int patient_informations(){
    char patient_name[80];
    int cpf;

    system("cls");

    printf("Informacoes necessarias sobre o paciente diagnosticado com COVID-19 \n\n\n");

    printf("Nome do paciente: ");

    fflush(stdin);
    scanf("%[^\n]s", &patient_name);

    printf("CPF: ");
    fflush(stdin);
    scanf("%[^\n]s", &cpf);
    return 0;
}

