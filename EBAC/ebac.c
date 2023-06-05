#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int cadastroUsuario(){

    char cpf[50];
   // char nome[50];

    printf ("Cadastro de Usuário EBAC!\n");
    printf ("Digite o CPF a ser cadastrado:");
    scanf ("%s", &cpf);

    return 0;
}
int consultarUsuario(){

    return 0;
}
int deletarUsuario(){

    return 0;
}

int main (){
    setlocale(LC_ALL, "portuguese");

    int menu = 0;
    int escolha = 0;

    for (; menu == 0;){
        printf ("\t\t## BEM VINDO ##\n");
        printf ("Sistema de cadastro de anunos e fucionario.\n\n");
        printf ("\t1 - Cadastro usuário\n");
        printf ("\t2 - Consultar usuário\n");
        printf ("\t3 - Deletar usuário\n\n");
        printf ("Por favor escolha uma opção: ");
        scanf ("%d", &escolha);

        switch (escolha){
            case 1:
            cadastroUsuario();
            break;
            case 2:
            consultarUsuario();
            break;
            case 3:
            deletarUsuario();
            break;
        }
    }

    return 0;
}