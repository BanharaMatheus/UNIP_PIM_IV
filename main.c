#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    /*
    Para fazer o sistema de cadastro, criar uma função que retorne uma lista ou
    alguma outra coisa e substituir ali no while do admin/admin
    */


    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n");
    printf("Sistema para cadastro de pacientes diagnosticados com COVID-19\n\n");
    /*printf("+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+\n\n");*/
    printf("Faca seu login\n\n");
    printf("-----------------------------------------------------------------------------------------------------------------------\n\n");

    char username[90];
    char passwd[90];
    char username_cp[90] = "admin";
    char passwd_cp[90] = "admin";
    int login_key = 0;

    while(!login_key){
        printf("User: ");
        scanf("%s", &username);
        printf("Password: ");
        scanf("%s", &passwd);

        if (strcmp(username, username_cp) == 0 && strcmp(passwd, passwd_cp) == 0){
            printf("LOGIN ACEITO");
            login_key = 1;
        }
        else
            printf("\nUsuario ou senha incorretos!\n\n");
            printf("Favor tentar novamente\n\n");
    }


    initialize_menu();

    return 0;
}
